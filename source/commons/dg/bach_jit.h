/**
	@file	bach_jit.h
	@brief	Common tools for painting to Jitter matrices.
	
	by Daniele Ghisi
*/

#ifndef _BACH_JIT_H_
#define _BACH_JIT_H_

#include "notation.h"
#include "jit.common.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

typedef void (*bach_paint_ext_fn)(t_object *x, t_object *view, t_jgraphics *g, t_rect rect);


void bach_paint_to_jitter_matrix(t_object *x, t_symbol *matrix_name, long width, long height, bach_paint_ext_fn obj_paint_ext);



#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _BACH_JIT_H_
