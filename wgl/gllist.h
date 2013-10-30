#ifndef __GLLIST_H__
#define __GLLIST_H__

#if 0
	#ifdef HAVE_CONFIG_H
	# include "config.h"
	#endif /* HAVE_CONFIG_H */
#endif

#include <stdlib.h>

#if 0
	#ifndef HAVE_COCOA
	# include <GL/gl.h>
	#endif

	#ifdef HAVE_JWZGLES
	# include "jwzgles.h"
	#endif /* HAVE_JWZGLES */
#endif

#include <windows.h>
#include <GL/gl.h>

struct gllist{
	GLenum format;
	GLenum primitive;
	int points;
	const void *data;
	struct gllist *next;
};

void renderList(const struct gllist *list, int wire_p);

#endif
