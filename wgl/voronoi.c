/* voronoi, Copyright (c) 2007, 2008 Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */

#define DELAY 20000
#define DEFAULTS        "*delay:        20000              \n" \
                        "*showFPS:      False              \n" \


# define refresh_voronoi 0
# define release_voronoi 0
#undef countof
#define countof(x) (sizeof((x))/sizeof((*x)))

#define BELLRAND(n) ((frand((n)) + frand((n)) + frand((n))) / 3)

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

#include "win32.h"


//#include "xlockmore.h"
#include <ctype.h>

//#ifdef USE_GL /* whole file */

#define DEF_POINTS      "25"
#define DEF_POINT_SIZE  "9"
#define DEF_POINT_SPEED "1.0"
#define DEF_POINT_DELAY "0.05"
#define DEF_ZOOM_SPEED  "1.0"
#define DEF_ZOOM_DELAY  "15"

typedef struct node {
  GLfloat x, y;
  GLfloat dx, dy;
  GLfloat ddx, ddy;
  struct node *next;
  GLfloat color[4], color2[4];
  int rot;
} node;

typedef struct {
  //GLXContext *glx_context;
  HGLRC hglrc;
  node *nodes;
  int nnodes;
  node *dragging;
  int ncolors;
  XColor *colors;

  enum { MODE_WAITING, MODE_ADDING, MODE_ZOOMING } mode;
  int adding;
  double last_time;

  GLfloat zooming;         /* 1.0 starting zoom, 0.0 no longer zooming. */
  GLfloat zoom_toward[2];

} voronoi_configuration;

static voronoi_configuration *vps = NULL;

/* command line arguments */
static int npoints = 25;
static GLfloat point_size = 9.0f, point_speed = 1.0f, point_delay = 0.05f;
static GLfloat zoom_speed = 1.0f, zoom_delay = 15.0f;

#if 0
	static XrmOptionDescRec opts[] = {
	  { "-points",       ".points",      XrmoptionSepArg, 0 },
	  { "-point-size",   ".pointSize",   XrmoptionSepArg, 0 },
	  { "-point-speed",  ".pointSpeed",  XrmoptionSepArg, 0 },
	  { "-point-delay",  ".pointDelay",  XrmoptionSepArg, 0 },
	  { "-zoom-speed",   ".zoomSpeed",   XrmoptionSepArg, 0 },
	  { "-zoom-delay",   ".zoomDelay",   XrmoptionSepArg, 0 },
	};

	static argtype vars[] = {
	  {&npoints,      "points",      "Points",      DEF_POINTS,       t_Int},
	  {&point_size,   "pointSize",   "PointSize",   DEF_POINT_SIZE,   t_Float},
	  {&point_speed,  "pointSpeed",  "PointSpeed",  DEF_POINT_SPEED,  t_Float},
	  {&point_delay,  "pointDelay",  "PointDelay",  DEF_POINT_DELAY,  t_Float},
	  {&zoom_speed,   "zoomSpeed",   "ZoomSpeed",   DEF_ZOOM_SPEED,   t_Float},
	  {&zoom_delay,   "zoomDelay",   "ZoomDelay",   DEF_ZOOM_DELAY,   t_Float},
	};

	ENTRYPOINT ModeSpecOpt voronoi_opts =
	  {countof(opts), opts, countof(vars), vars, NULL};
#endif

/* Returns the current time in seconds as a double.
 */
static double
double_time (void)
{
#if 0
  struct timeval now;
# ifdef GETTIMEOFDAY_TWO_ARGS
  struct timezone tzp;
  gettimeofday(&now, &tzp);
# else
  gettimeofday(&now);
# endif

  return (now.tv_sec + ((double) now.tv_usec * 0.000001));
#endif
	return GetTickCount() / 1000.0;
}


static node *
add_node (voronoi_configuration *vp, GLfloat x, GLfloat y)
{
  node *nn = (node *) calloc (1, sizeof (*nn));
  int i;
  nn->x = x;
  nn->y = y;

  i = random() % vp->ncolors;
  nn->color[0] = vp->colors[i].red   / 65536.0f;
  nn->color[1] = vp->colors[i].green / 65536.0f;
  nn->color[2] = vp->colors[i].blue  / 65536.0f;
  nn->color[3] = 1.0f;

  nn->color2[0] = nn->color[0] * 0.7f;
  nn->color2[1] = nn->color[1] * 0.7f;
  nn->color2[2] = nn->color[2] * 0.7f;
  nn->color2[3] = 1.0f;

  nn->ddx = (float)(frand (0.000001 * point_speed) * (random() & 1 ? 1 : -1));
  nn->ddy = (float)(frand (0.000001 * point_speed) * (random() & 1 ? 1 : -1));

  nn->rot = (random() % 360) * (random() & 1 ? 1 : -1);

  nn->next = vp->nodes;
  vp->nodes = nn;
  vp->nnodes++;
  return nn;
}


static int
cone (void)
{
  int i;
  int faces = 64;
  GLfloat step = (float)(M_PI * 2 / faces);
  GLfloat th = 0.0f;
  GLfloat x = 1.0f;
  GLfloat y = 0.0f;

  glBegin(GL_TRIANGLE_FAN);
  glVertex3f (0, 0, 1);
  for (i = 0; i < faces; i++)
    {
      glVertex3f (x, y, 0);
      th += step;
      x = COSF(th);
      y = SINF(th);
    }
  glVertex3f (1, 0, 0);
  glEnd();
  return faces;
}


static void
move_points (voronoi_configuration *vp)
{
  node *nn;
  for (nn = vp->nodes; nn; nn = nn->next)
    {
      if (nn == vp->dragging) continue;
      nn->x  += nn->dx;
      nn->y  += nn->dy;

      if (vp->mode == MODE_WAITING)
        {
          nn->dx += nn->ddx;
          nn->dy += nn->ddy;
        }
    }
}


static void
prune_points (voronoi_configuration *vp)
{
  node *nn;
  node *prev = 0;
  int lim = 5;

  for (nn = vp->nodes; nn; prev = nn, nn = (nn ? nn->next : 0))
    if (nn->x < -lim || nn->x > lim ||
        nn->y < -lim || nn->y > lim)
      {
        if (prev)
          prev->next = nn->next;
        else
          vp->nodes = nn->next;
        free (nn);
        vp->nnodes--;
        nn = prev;
     }
}


static void
zoom_points (voronoi_configuration *vp)
{
  node *nn;

  GLfloat tick = SINF(vp->zooming * M_PI);
  GLfloat scale = (float)(1 + (tick * 0.02 * zoom_speed));

  vp->zooming -= (float)(0.01 * zoom_speed);
  if (vp->zooming < 0) vp->zooming = 0;

  if (vp->zooming <= 0) return;

  if (scale < 1) scale = 1;

  for (nn = vp->nodes; nn; nn = nn->next)
    {
      GLfloat x = nn->x - vp->zoom_toward[0];
      GLfloat y = nn->y - vp->zoom_toward[1];
      x *= scale;
      y *= scale;
      nn->x = x + vp->zoom_toward[0];
      nn->y = y + vp->zoom_toward[1];
    }
}



static void
draw_cells (ModeInfo *mi)
{
  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];
  node *nn;
  int lim = 5;

  for (nn = vp->nodes; nn; nn = nn->next)
    {
      if (nn->x < -lim || nn->x > lim ||
          nn->y < -lim || nn->y > lim)
        continue;

      glPushMatrix();
      glTranslatef (nn->x, nn->y, 0);
      glScalef ((float)(lim*2), (float)(lim*2), (float)1);
      glColor4fv (nn->color);
      mi->polygon_count += cone ();
      glPopMatrix();
    }

  glClear (GL_DEPTH_BUFFER_BIT);

  if (point_size <= 0)
    ;
  else if (point_size < 3)
    {
      glPointSize (point_size);
      for (nn = vp->nodes; nn; nn = nn->next)
        {
          glBegin (GL_POINTS);
          glColor4fv (nn->color2);
          glVertex2f (nn->x, nn->y);
          glEnd();
          mi->polygon_count++;
        }
    }
  else
    {
      for (nn = vp->nodes; nn; nn = nn->next)
        {
          int w = MI_WIDTH (mi);
          int h = MI_HEIGHT (mi);
          int s = (int)point_size;
          int i;

          glColor4fv (nn->color2);
          glPushMatrix();
          glTranslatef (nn->x, nn->y, 0);
          glScalef ((float)(1.0 / w * s), (float)(1.0 / h * s), (float)1);

          glLineWidth (point_size / 10);
          nn->rot += (nn->rot < 0 ? -1 : 1);
          glRotatef((float)nn->rot, 0.0f, 0.0f, 1.0f);

          glRotatef (180, 0, 0, 1);
          for (i = 0; i < 5; i++)
            {
              glBegin (GL_TRIANGLES);
              glVertex2f (0.0f, 1.0f);
              glVertex2f (-0.2f, 0.0f);
              glVertex2f ( 0.2f, 0.0f);
              glEnd ();
              glRotatef (360.0f/5.0f, 0.0f, 0.0f, 1.0f);
              mi->polygon_count++;
            }
          glPopMatrix();
        }
    }
}


/* Window management, etc
 */
ENTRYPOINT void
reshape_voronoi (ModeInfo *mi, int width, int height)
{
/*  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];*/

  glViewport (0, 0, (GLint) width, (GLint) height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho (0, 1, 1, 0, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClear(GL_COLOR_BUFFER_BIT);
}


static node *
find_node (ModeInfo *mi, GLfloat x, GLfloat y)
{
  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];
  int ps = (int)(point_size < 5 ? 5 : point_size);
  GLfloat hysteresis = (float)((1.0 / MI_WIDTH (mi)) * ps);
  node *nn;
  for (nn = vp->nodes; nn; nn = nn->next)
    if (nn->x > x - hysteresis && nn->x < x + hysteresis &&
        nn->y > y - hysteresis && nn->y < y + hysteresis)
      return nn;
  return 0;
}

#if 0
	ENTRYPOINT Bool
	voronoi_handle_event (ModeInfo *mi, XEvent *event)
	{
	  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];

	  if (event->xany.type == ButtonPress)
		{
		  GLfloat x = (GLfloat) event->xbutton.x / MI_WIDTH (mi);
		  GLfloat y = (GLfloat) event->xbutton.y / MI_HEIGHT (mi);
		  node *nn = find_node (mi, x, y);
		  if (!nn)
			nn = add_node (vp, x, y);
		  vp->dragging = nn;

		  return True;
		}
	  else if (event->xany.type == ButtonRelease && vp->dragging)
		{
		  vp->dragging = 0;
		  return True;
		}
	  else if (event->xany.type == MotionNotify && vp->dragging)
		{
		  vp->dragging->x = (GLfloat) event->xmotion.x / MI_WIDTH (mi);
		  vp->dragging->y = (GLfloat) event->xmotion.y / MI_HEIGHT (mi);
		  return True;
		}

	  return False;
	}
#endif

static void
state_change (ModeInfo *mi)
{
  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];
  double now = double_time();

  if (vp->dragging)
    {
      vp->last_time = now;
      vp->adding = 0;
      vp->zooming = 0;
      return;
    }

  switch (vp->mode)
    {
    case MODE_WAITING:
      if (vp->last_time + zoom_delay <= now)
        {
          node *tn = vp->nodes;
          vp->zoom_toward[0] = (float)(tn ? tn->x : 0.5);
          vp->zoom_toward[1] = (float)(tn ? tn->y : 0.5);

          vp->mode = MODE_ZOOMING;
          vp->zooming = 1;

          vp->last_time = now;
        }
      break;

    case MODE_ADDING:
      if (vp->last_time + point_delay <= now)
        {
          add_node (vp, 
                    (float)(BELLRAND(0.5) + 0.25), 
                    (float)(BELLRAND(0.5) + 0.25));
          vp->last_time = now;
          vp->adding--;
          if (vp->adding <= 0)
            {
              vp->adding = 0;
              vp->mode = MODE_WAITING;
              vp->last_time = now;
            }
        }
      break;

    case MODE_ZOOMING:
      {
        zoom_points (vp);
        if (vp->zooming <= 0)
          {
            vp->mode = MODE_ADDING;
            vp->adding = npoints;
            vp->last_time = now;
          }
      }
      break;

    default:
      abort();
    }
}

const char *progname = "Voronoi";

ENTRYPOINT void 
init_voronoi (ModeInfo *mi)
{
  voronoi_configuration *vp;

  if (!vps) {
    vps = (voronoi_configuration *)
      calloc (MI_NUM_SCREENS(mi), sizeof (voronoi_configuration));
    if (!vps) {
      fprintf(stderr, "%s: out of memory\n", progname);
      exit(1);
    }
  }

  vp = &vps[MI_SCREEN(mi)];

  vp->hglrc = init_GL(mi);

  if (point_size < 0) point_size = 10;

  vp->ncolors = 128;
  vp->colors = (XColor *) calloc (vp->ncolors, sizeof(XColor));
  make_smooth_colormap (0, 0, 0,
                        vp->colors, &vp->ncolors,
                        False, False, False);

  reshape_voronoi (mi, MI_WIDTH(mi), MI_HEIGHT(mi));

  vp->mode = MODE_ADDING;
  vp->adding = npoints * 2;
  vp->last_time = 0;
}


ENTRYPOINT void
draw_voronoi (ModeInfo *mi)
{
  voronoi_configuration *vp = &vps[MI_SCREEN(mi)];
  HDC dpy = MI_DISPLAY(mi);
  HWND window = MI_WINDOW(mi);

  if (!vp->hglrc)
    return;

  wglMakeCurrent(MI_DISPLAY(mi), vp->hglrc);

  glShadeModel(GL_FLAT);
  glEnable(GL_POINT_SMOOTH);
/*  glEnable(GL_LINE_SMOOTH);*/
/*  glEnable(GL_POLYGON_SMOOTH);*/

  glEnable (GL_DEPTH_TEST);
  glDepthFunc (GL_LEQUAL);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  mi->polygon_count = 0;
  draw_cells (mi);
  move_points (vp);
  prune_points (vp);
  state_change (mi);

  if (mi->fps_p) do_fps (mi);
  glFinish();

  SwapBuffers(dpy);
}

XSCREENSAVER_MODULE ("Voronoi", voronoi)

//#endif /* USE_GL */
