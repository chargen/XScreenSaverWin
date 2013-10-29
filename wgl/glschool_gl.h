/* glschool_gl.h, Copyright (c) 2005-2006 David C. Lambert <dcl@panix.com>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 */
#ifndef __GLSCHOOL_GL_H__
#define __GLSCHOOL_GL_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#if 0
	#ifdef HAVE_COCOA
	# include "jwxyz.h"
	# ifndef HAVE_JWZGLES
	#  include <OpenGL/glu.h>
	# endif
	#else
	# include <X11/Xlib.h>
	# include <GL/gl.h>
	# include <GL/glu.h>
	#endif

	#ifdef HAVE_JWZGLES
	# include "jwzgles.h"
	#endif /* HAVE_JWZGLES */
#endif

#include "glschool_alg.h"

extern void glschool_initFog(void);
extern void glschool_initGLEnv(Bool);
extern void glschool_initLights(void);
extern void glschool_reshape(int, int);
extern void glschool_drawGoal(double *, GLuint);
extern void glschool_getColorVect(XColor *, int, double *);
extern int glschool_drawBoundingBox(BBox *, Bool);
extern int glschool_createBBoxList(BBox *, GLuint *, int);
extern void glschool_createDrawLists(BBox *, GLuint *, GLuint *, GLuint *, int *, int *, Bool);
extern void glschool_drawSchool(XColor *, School *, GLuint, GLuint, GLuint, int, Bool, Bool, 
                       int, int, unsigned long *);

#endif /* __GLSCHOOL_GL_H__ */
