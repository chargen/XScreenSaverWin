/* -*- Mode: C; tab-width: 4 -*- */
/* sproingiewrap.c - sproingies wrapper */

#if 0
static const char sccsid[] = "@(#)sproingiewrap.c	4.07 97/11/24 xlockmore";
#endif

/*-
 * sproingiewrap.c - Copyright 1996 Sproingie Technologies Incorporated.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and that
 * both that copyright notice and this permission notice appear in
 * supporting documentation.
 *
 * This file is provided AS IS with no warranties of any kind.  The author
 * shall have no liability with respect to the infringement of copyrights,
 * trade secrets or any patents by this file or any part thereof.  In no
 * event will the author be liable for any lost revenue or profits or
 * other special, indirect and consequential damages.
 *
 *    Programming:  Ed Mackey, http://www.netaxs.com/~emackey/
 *                  Gordon Wrigley, gdw33@student.canterbury.ac.nz
 *                  Sergio Guti�rrez "Sergut", sergut@gmail.com
 *    Sproingie 3D objects modeled by:  Al Mackey, al@iam.com
 *       (using MetaNURBS in NewTek's Lightwave 3D v5).
 *
 * Revision History:
 * 01-Sep-06: Make the sproingies select a new direction after each hop
 *              (6 frames); if they fall towards the edge, they explode.
 *              (TODO: let them fall for a time before they explode or
 *               disappear) [sergut]
 * 13-Dec-02: Changed triangle normals into vertex normals to give a smooth
 *              apperance and moved the sproingies from Display Lists to
 *              Vertex Arrays, still need to do this for the TopsSides.
 *              [gordon]
 * 26-Apr-97: Added glPointSize() calls around explosions, plus other fixes.
 * 28-Mar-97: Added size support.
 * 22-Mar-97: Updated to use glX interface instead of xmesa one.
 *              Also, support for multiscreens added.
 * 20-Mar-97: Updated for xlockmore v4.02alpha7 and higher, using
 *              xlockmore's built-in Mesa/OpenGL support instead of
 *              my own.  Submitted for inclusion in xlockmore.
 * 09-Dec-96: Written.
 */

#define DELAY 30000
# define DEFAULTS	"*delay:		30000   \n"			\
					"*count:		8       \n"			\
					"*size:			0       \n"			\
					"*showFPS:      False   \n"			\
					"*fpsTop:       True    \n"			\
					"*wireframe:	False	\n"

#define refresh_sproingies NULL
#define sproingies_handle_event NULL

#if 0
	#ifdef STANDALONE
	# include "xlockmore.h"				/* from the xscreensaver distribution */
	#else  /* !STANDALONE */
	# include "xlock.h"					/* from the xlockmore distribution */
	#endif /* !STANDALONE */
#endif

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#include "win32.h"

//#ifdef USE_GL

#define DEF_SMART_SPROINGIES "True" /* Smart sproingies do not fall down the edge */

#include "sproingies.h"

#undef countof
#define countof(x) (sizeof((x))/sizeof((*x)))

#if 0
	static XrmOptionDescRec opts[] = {
	    {"-fall",     ".smartSproingies",  XrmoptionNoArg,  "False"},
	    {"-no-fall",  ".smartSproingies",  XrmoptionNoArg,  "True"},
	};
#endif

static int smrt_spr = True;

#if 0
	static argtype vars[] = {
	    {&smrt_spr,  "smartSproingies",  "Boolean",  DEF_SMART_SPROINGIES,  t_Bool},
	};

	ENTRYPOINT ModeSpecOpt sproingies_opts =
	{countof(opts), opts, countof(vars), vars, NULL};

	#ifdef USE_MODULES
	ModStruct   sproingies_description =
	{"sproingies", "init_sproingies", "draw_sproingies", "release_sproingies",
	 "refresh_sproingies", "init_sproingies", NULL, &sproingies_opts,
	 1000, 5, 0, 400, 4, 1.0, "",
	 "Shows Sproingies!  Nontoxic.  Safe for pets and small children", 0, NULL};
	#endif
#endif

#define MINSIZE 32

#include <time.h>

void        NextSproingie(int screen);
void        NextSproingieDisplay(int screen,int pause);
void        DisplaySproingies(int screen,int pause);
void        ReshapeSproingies(int w, int h);
void        CleanupSproingies(int screen);
void        InitSproingies(int wfmode, int grnd, int mspr, int smrtspr,
						   int screen, int numscreens, int mono);

typedef struct {
	GLfloat     view_rotx, view_roty, view_rotz;
	GLint       gear1, gear2, gear3;
	GLfloat     angle;
	GLuint      limit;
	GLuint      count;
	//GLXContext *glx_context;
	HGLRC hglrc;
	int         mono;
	HWND window;
} sproingiesstruct;

static sproingiesstruct *sproingies = NULL;


ENTRYPOINT void
init_sproingies (ModeInfo * mi)
{
	HWND window = MI_WINDOW(mi);
	int         screen = MI_SCREEN(mi);

	int         count = MI_COUNT(mi);
	int         size = MI_SIZE(mi);

	sproingiesstruct *sp;
	int         wfmode = 0, grnd = 0, mspr, w, h;

	if (sproingies == NULL) {
		if ((sproingies = (sproingiesstruct *) calloc(MI_NUM_SCREENS(mi),
					 sizeof (sproingiesstruct))) == NULL)
			return;
	}
	sp = &sproingies[screen];

	sp->mono = (MI_IS_MONO(mi) ? 1 : 0);
	sp->window = window;
	if ((sp->hglrc = init_GL(mi)) != NULL) {

		if (MI_IS_WIREFRAME(mi))
			wfmode = 1;

		if (grnd > 2)
			grnd = 2;

		mspr = count;
		if (mspr > 100)
			mspr = 100;

		/* wireframe, ground, maxsproingies */
		InitSproingies(wfmode, grnd, mspr, smrt_spr, MI_SCREEN(mi), MI_NUM_SCREENS(mi), sp->mono);

		/* Viewport is specified size if size >= MINSIZE && size < screensize */
		if (size == 0) {
			w = MI_WIDTH(mi);
			h = MI_HEIGHT(mi);
		} else if (size < MINSIZE) {
			w = MINSIZE;
			h = MINSIZE;
		} else {
			w = (size > MI_WIDTH(mi)) ? MI_WIDTH(mi) : size;
			h = (size > MI_HEIGHT(mi)) ? MI_HEIGHT(mi) : size;
		}

		glViewport((MI_WIDTH(mi) - w) / 2, (MI_HEIGHT(mi) - h) / 2, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 0.1, 2000.0);	/* was 200000.0 */
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		DisplaySproingies(MI_SCREEN(mi),mi->pause);

	} else {
		MI_CLEARWINDOW(mi);
	}
}

/* ARGSUSED */
ENTRYPOINT void
draw_sproingies (ModeInfo * mi)
{
	sproingiesstruct *sp = &sproingies[MI_SCREEN(mi)];
	HDC display = MI_DISPLAY(mi);
	HWND window = MI_WINDOW(mi);

	if (!sp->hglrc)
		return;

	glDrawBuffer(GL_BACK);
	wglMakeCurrent(display, sp->hglrc);

    glPushMatrix();
    //glRotatef(current_device_rotation(), 0, 0, 1);
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
	NextSproingieDisplay(MI_SCREEN(mi),mi->pause);	/* It will swap. */
    glPopMatrix();

    if (mi->fps_p) do_fps (mi);
    glFinish();
    SwapBuffers(MI_DISPLAY(mi));
}

#if 0
	#ifndef STANDALONE
	ENTRYPOINT void
	refresh_sproingies(ModeInfo * mi)
	{
		/* No need to do anything here... The whole screen is updated
		 * every frame anyway.  Otherwise this would be just like
		 * draw_sproingies, above, but replace NextSproingieDisplay(...)
		 * with DisplaySproingies(...).
		 */
	}
	#endif /* !STANDALONE */
#endif

ENTRYPOINT void
reshape_sproingies (ModeInfo *mi, int w, int h)
{
  ReshapeSproingies(w, h);
}


ENTRYPOINT void
release_sproingies (ModeInfo * mi)
{
	if (sproingies != NULL) {
		int         screen;

		for (screen = 0; screen < MI_NUM_SCREENS(mi); screen++) {
			sproingiesstruct *sp = &sproingies[screen];

			if (sp->hglrc) {

				wglMakeCurrent(MI_DISPLAY(mi), sp->hglrc);
				CleanupSproingies(MI_SCREEN(mi));
			}
		}

		(void) free((void *) sproingies);
		sproingies = NULL;
	}
	FreeAllGL(mi);
}

XSCREENSAVER_MODULE ("Sproingies", sproingies)

//#endif /* USE_GL */

/* End of sproingiewrap.c */
