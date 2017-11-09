         /**
 @file
 life.c
 
 @name 
 bach.life
 
 @realname 
 bach.life
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject

 @status
 hidden

 @digest 
 life elements of an llll
 
 @description
 lifes the element of an llll in sublists, according to a regular size pattern.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 life, wrap, pattern, sublist
 
 @seealso
 bach.trans, bach.lace, bach.delace, bach.mdelace
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _life
{
	struct llllobj_object 	n_ob;
	int		*n_world[2];
	int		n_xsize;
	int		n_ysize;
	long	n_thisworld;
} t_life;

typedef enum _life_states {
	DEAD, LIVE
} t_life_states;

t_life_states state[1 << 9];


void life_assist(t_life *x, void *b, long m, long a, char *s);

t_life *life_new(t_symbol *s, short ac, t_atom *av);
void life_free(t_life *x);

void life_bang(t_life *x);
void life_int(t_life *x, t_atom_long v);
void life_float(t_life *x, double v);
void life_anything(t_life *x, t_symbol *msg, long ac, t_atom *av);
void life_step(int *this_world, int *new_world);
void life_ezstep(int *this_world, int *new_world, int x_size, int y_size);

t_class *life_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.life", (method)life_new, (method)life_free, (short)sizeof(t_life), 0L, A_GIMME, 0);
	
	// @method llll @digest life the elements of the llll
	// @description
	// The elements of the input llll are sequentially lifeed into sublists 
	// according to a regular pattern of sublist sizes, with optional overlapping.
	class_addmethod(c, (method)life_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)life_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)life_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)life_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Returns the lifeing of the most recently received llll.
	class_addmethod(c, (method)life_bang,		"bang",			0);
	
	class_addmethod(c, (method)life_assist,	"assist",		A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	life_class = c;
	
	
	int bitmap, xx, yy;
	for (bitmap = 0; bitmap < 1<<9; bitmap++) {
		for(xx = yy = 0; yy < 9; yy++)
			if(bitmap & 1<<yy)
				xx += 1;
		if(bitmap & 020) {
			if(xx == 2 || xx == 3)
				state[bitmap] = LIVE;
			else
				state[bitmap] = DEAD;
		} else {
			if(xx == 3)
				state[bitmap] = LIVE;
			else
				state[bitmap] = DEAD;
		}
	}
	
	dev_post("bach.life compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void life_bang(t_life *x)
{	
	int *this_world = x->n_world[x->n_thisworld];
	int *new_world = x->n_world[1 - x->n_thisworld];
	//life_step(this_world, new_world);
	life_ezstep(this_world, new_world, x->n_xsize, x->n_ysize);
	int *this_new_world = new_world;
	t_llll *out_ll = llll_get();
	/*
	long this_row = 1;
	long this_col = 1;
	for (this_this_world = this_world; *this_this_world; this_this_world++) {
		if (*this_this_world > 0) {
			if (*this_this_world < this_row) {
				object_bug((t_object *) x, "Unsorted rows");
				break;
			}
			if (row_ll)
				llll_appendllll(out_ll, row_ll, 0, WHITENULL_llll);
			for ( ; this_row < *this_this_world; this_row++) {
				llll_appendllll(out_ll, llll_get(), 0, WHITENULL_llll);
				this_col = 1;
			}
			row_ll = llll_get();
		} else {
			if (-*this_this_world < this_col) {
				object_bug((t_object *) x, "Unsorted cols");
				break;
			}
			for ( ; this_col < -*this_this_world; this_col++) {
				llll_appendlong(row_ll, 0, 0, WHITENULL_llll);
			}
			llll_appendlong(row_ll, 1, 0, WHITENULL_llll);
		}
	}
	if (row_ll)
		llll_appendllll(out_ll, row_ll, 0, WHITENULL_llll);
	 */
	
	long row_count;
	
	for (row_count = 0; row_count < x->n_ysize; row_count++) {
		t_llll *row_ll = llll_get();
		long col_count;
		for (col_count = 0; col_count < x->n_xsize; col_count++) {
			llll_appendlong(row_ll, *this_new_world++, 0, WHITENULL_llll);
		}
		llll_appendllll(out_ll, row_ll, 0, WHITENULL_llll);
	}
	
	x->n_thisworld = 1 - x->n_thisworld;
	 
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out_ll);
	llll_free(out_ll);
}

void life_int(t_life *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	life_anything(x, _sym_int, 1, &outatom);
}

void life_float(t_life *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	life_anything(x, _sym_float, 1, &outatom);
}

void life_anything(t_life *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!ll)
		return;
	if (ll->l_size == 0 || ll->l_depth != 2) {
		llll_free(ll);
		return;
	}
	
	t_llllelem *row_el, *col_el; 
	long row_count;
	int *this_this_world = x->n_world[x->n_thisworld];
	int *this_new_world = x->n_world[1-x->n_thisworld];
	
	/*
	for (row_el = ll->l_tail, row_count = ll->l_size; row_el; row_el = row_el->l_prev, row_count--) {
		if (hatom_gettype(&row_el->l_hatom) != H_LLLL) {
			object_error((t_object *) x, "Bad matrix");
		}
		long new_row = 1;
		t_llll *row_ll = hatom_getllll(&row_el->l_hatom);
		long col_count;
		for (col_el = row_ll->l_tail, col_count = row_ll->l_size; col_el; col_el = col_el->l_prev, col_count--) {
			long col_val = hatom_getlong(&col_el->l_hatom);
			if (col_val) {
				if (new_row) {
					*(this_this_world++) = row_count;
					new_row = 0;
				}
				*(this_this_world++) = -col_count;
			}
		}
	}
	*this_this_world = 0;
	 */
	for (row_el = ll->l_head, row_count = 0; row_el && row_count < x->n_ysize; row_el = row_el->l_next, row_count++) {
		long col_count;
		t_llll *row_ll = hatom_getllll(&row_el->l_hatom);
		for (col_el = row_ll->l_head, col_count = 0; col_el && col_count < x->n_xsize; col_el = col_el->l_next, col_count++) {
			*this_this_world++ = hatom_getlong(&col_el->l_hatom);
			*this_new_world++ = 0;
		}
		for ( ; col_count < x->n_xsize; col_count++) {
			*this_this_world++ = 0;
			*this_new_world++ = 0;
		}
	}
	
	for ( ; row_count < x->n_ysize; row_count++) {
		long col_count;
		for (col_count = 0 ; col_count < x->n_xsize; col_count++) {
			*this_this_world++ = 0;
			*this_new_world++ = 0;
		}	
	}
	llll_release(ll);
	life_bang(x);
}


void life_assist(t_life *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to process
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
		// @out 0 @type llll @digest Processed llll
	}
}

void life_free(t_life *x)
{
	bach_freeptr(x->n_world[0]);
	bach_freeptr(x->n_world[1]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_life *life_new(t_symbol *s, short ac, t_atom *av)
{
	t_life *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_life *) object_alloc_debug(life_class))) {
		// @arg 0 @name count @type list @optional 1 @digest Count
		// @description Initial value for the <m>count</m> attribute.

		x->n_world[0] = (int *) bach_newptr(1000000 * sizeof(int));
		x->n_world[1] = (int *) bach_newptr(1000000 * sizeof(int));
		x->n_thisworld = 0;

		x->n_xsize = 50;
		x->n_ysize = 50;
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	}
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}




/*!
 * \file life.c
 *
 * \brief An implementation of the Game of Life
 *
 * The Life universe is represented by an array containing the co-ordinates
 * of the live cells, organized as a sequence of rows. Each row is a Y value
 * followed by a sequence of X values. X and Y are distinguished from each
 * other by their sign. The array is terminated by a Y value of 0.
 *
 * Y values have the same sign as the terminator, so they are positive and X
 * values are negative. Y values are all greater than the terminator, so they
 * decrease in order to make the terminator sort last. X values are all less
 * than Y values, so they increase in order to make the Y value following the
 * line sort after the line.
 *
 * $Copyright: (C) 2003 Tony Finch <dot@dotat.at> $
 *
 * $dotat: things/life.c,v 1.7 2003/12/04 17:06:27 fanf2 Exp $
 */

/*!
 * \brief Compute the next generation of the Game of Life.
 * \param this The current state of the known universe.
 * \param new Where to put the replacement universe.
 * \note \c new must have three times the space used by \c this.
 */
void life_stepzzz(int *this_world, int *new_world)
{
	unsigned bitmap;
	int *next, *prev;
	int x, y;
	
	prev = next = this_world;
	bitmap = 0;
	*new_world = 0;
	for(;;) {
		/* did we write an X co-ordinate? */
		if(*new_world < 0)
			new_world++;
		if (prev == next) {
			/* start a new group of rows */
			if(*next == 0) {
				*new_world = 0;
				return;
			}
			y = *next++ + 1;
		} else {
			/* move to next row and work out which ones to scan */
			if(*prev == y--)
				prev++;
			if(*this_world == y)
				this_world++;
			if(*next == y-1)
				next++;
		}
		/* write new row co-ordinate */
		*new_world = y;
		for(;;) {
			/* skip to the leftmost cell */
			x = *prev;
			if(x > *this_world)
				x = *this_world;
			if(x > *next)
				x = *next;
			/* end of line? */
			if(x >= 0)
				break;
			for(;;) {
				/* add a column to the bitmap */
				if(*prev == x) {
					bitmap |= 0100;
					prev++;
				}
				if(*this_world == x) {
					bitmap |= 0200;
					this_world++;
				}
				if(*next == x) {
					bitmap |= 0400;
					next++;
				}
				/* what does this bitmap indicate? */
				if(state[bitmap] == LIVE)
					*++new_world = x - 1;
				else if(bitmap == 000)
					break;
				/* move right */
				bitmap >>= 3;
				x += 1;
			}
		}
	}
}







/*!
 * \file life.c
 *
 * \brief An implementation of the Game of Life
 *
 * $Copyright: (C) 2003 Tony Finch <dot@dotat.at> $
 *
 * $dotat: things/life.c,v 1.3 2003/12/04 16:25:38 fanf2 Exp $
 */

/*!
 * \brief Compute the next generation of the Game of Life.
 *
 * \param old The current state of the known universe.
 * \param new Where to put the replacement universe.
 *
 * Each array contains the co-ordinates of the live cells, organized as a
 * sequence of rows, each row being a Y co-ordinate followed by a sequence of
 * X co-ordinates. X and Y co-ordinates are distinguished from each other by
 * their sign. The array is terminated by a Y co-ordinate of 0.
 *
 * Y co-ordinates have the same sign as the terminator, which means they are
 * positive, and X co-ordinates are negative. Y co-ordinates are all greater
 * than the terminator, so they are in decreasing order so that the terminator
 * sorts last. X co-ordinates are all less than Y co-ordinates, so they are in
 * increasing order so that the Y co-ordinate that terminates each line sorts
 * at the end of the line.
 */
void
life_stepqqq(int *this_world, int *new_world)
{
	unsigned bitmap;
	int *next, *prev;
	int x, y;
	
	prev = next = this_world;
	bitmap = 0;
	*new_world = 0;
	for(;;) {
		/* only increment new if we wrote an X co-ordinate */
		if(*new_world < 0)
			new_world++;
		if(this_world != next)
		/* try and catch up with the next line */
			y = *this_world++;
		else if(prev != this_world)
		/* try to get the previous row to catch up */
			y = *prev++ - 1;
		else if(*next != 0)
		/* all caught up so push the next one forward */
			y = *next++ + 1;
		else {
			*new_world = 0;
			return;
		}
		/* drag other lines with us if they are adjacent */
		if(y == *prev - 1)
			prev++;
		if(y == *next + 1)
			next++;
		/* write new row co-ordinate */
		*new_world = y;
		for(;;) {
			/* skip to the leftmost cell */
			x = *this_world;
			if(x > *next)
				x = *next;
			if(x > *prev)
				x = *prev;
			if(x >= 0)
				break;
			for(;;) {
				/* add a column to the bitmap */
				if(*next == x) {
					bitmap |= 0100;
					next++;
				}
				if(*this_world == x) {
					bitmap |= 0200;
					this_world++;
				}
				if(*prev == x) {
					bitmap |= 0400;
					prev++;
				}
				/* what does this bitmap indicate? */
				if(state[bitmap] == LIVE)
					*++new_world = x - 1;
				else if(bitmap == 000)
					break;
				/* move right */
				bitmap >>= 3;
				x += 1;
			}
		}
	}
}

/* EOF life.c */



void life_ezstep(int *this_world, int *new_world, int x_size, int y_size)
{
	int x, y;
	for (y = 1; y < y_size - 1; y++) {
		for (x = 1; x < x_size - 1; x++) {
			int nx, ny;
			int count = 0;
			for (ny = y - 1; ny <= y + 1 && count < 4; ny++) {
				for (nx = x - 1; nx <= x + 1 && count < 4; nx++) {
					if (nx == x && ny == y)
						continue;
					count += *(this_world + nx * y_size + ny);
				}
			}
			if (*(this_world + x * y_size + y) == 0) {
				*(new_world + x * y_size + y) = count == 3;
			} else {
				*(new_world + x * y_size + y) = count == 2 || count == 3;
			}
		}
	}
}





/* EOF life.c */