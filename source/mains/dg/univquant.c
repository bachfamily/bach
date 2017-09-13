#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "llllobj.h"
#include "ext_strings.h"
#include "llll_commons_ext.h"

typedef enum _univquant_var_types {
	k_UNIVQUANT_TYPE_INCORRECT = 0,			///< Wrongly defined variable
	k_UNIVQUANT_TYPE_LONG_RANGE = 1,		///< Variable is defined by a range of long numbers
	k_UNIVQUANT_TYPE_EXPLICIT_DOMAIN = 2	///< Variable is defined by explicit domain
} e_univquant_var_types;



// single variable
typedef struct _univquant_var
{
	t_symbol				*name;
	e_univquant_var_types	type;
		
	// if type == 0:
	long		domain_min;
	long		domain_max;
	
	// if type == 1:
	t_llll		*explicit_domain;
} t_univquant_var;


typedef struct _univquant
{
	struct llllobj_object 	n_ob;
	
	void					*m_proxy;	// proxy
	long					m_in;   
} t_univquant;


void univquant_assist(t_univquant *x, void *b, long m, long a, char *s);
void univquant_inletinfo(t_univquant *x, void *b, long a, char *t);

t_univquant *univquant_new(t_symbol *s, short ac, t_atom *av);
void univquant_free(t_univquant *x);

void univquant_bang(t_univquant *x);
void univquant_int(t_univquant *x, long num);
void univquant_float(t_univquant *x, double num);
void univquant_anything(t_univquant *x, t_symbol *msg, long ac, t_atom *av);

t_class *univquant_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}	
	
	c = class_new("bach.univquant", (method)univquant_new, (method)univquant_free, (short)sizeof(t_univquant), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)univquant_anything,					"anything",				A_GIMME,	0);
	
	class_addmethod(c, (method)univquant_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)univquant_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)univquant_anything,					"list",					A_GIMME,	0);
	class_addmethod(c, (method)univquant_bang,						"bang",		0);
	
	class_addmethod(c, (method)univquant_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)univquant_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
//	llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	univquant_class = c;
	
	dev_post("bach.univquant compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void univquant_bang(t_univquant *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void univquant_int(t_univquant *x, long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	univquant_anything(x, _llllobj_sym_list, 1, argv);
}

void univquant_float(t_univquant *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	univquant_anything(x, _llllobj_sym_list, 1, argv);
}

t_univquant_var get_default_univquant_var(){
	t_univquant_var res;
	res.name = _llllobj_sym_empty_symbol;
	res.type = k_UNIVQUANT_TYPE_INCORRECT;
	res.domain_min = res.domain_max = 0;
	res.explicit_domain = NULL;
	return res;
}

char is_char_variable_name_delimiter(char ch)
{
	if (ch != ' ' && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ')' && ch != '(' && ch != '&' && ch != '|' && ch != '^'
		&& ch != '[' && ch != ']' && ch != '{' && ch != '}' && ch != '%' && ch != '!' && ch != '?')       
		return 0;
	return 1;
}

char is_found_substring_entire_symbol(char *str, char *substr, long len_substr){
	long len_str = strlen(str);
	long substr_start_idx = (substr - str)/sizeof(char);
	char next_char_ok = false, prev_char_ok = false;
	
	// analyzing next char
	long next_char_idx = substr_start_idx + len_substr;
	long prev_char_idx = substr_start_idx - 1;
	next_char_ok = ((next_char_idx >= len_str) || is_char_variable_name_delimiter(str[next_char_idx]));
	prev_char_ok = ((prev_char_idx < 0) || is_char_variable_name_delimiter(str[prev_char_idx]));
	return (next_char_ok && prev_char_ok);
}


long substitute_var_in_expressions_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_SYM){
		t_symbol *var_name = *((t_symbol **) ((void **)data)[0]);
		t_hatom *var_value = *((t_hatom **) ((void **)data)[1]);
		long var_index = *((long *) ((void **)data)[2]);
		if (hatom_getsym(a) == var_name) {
			if (hatom_gettype(var_value) == H_LLLL){
				t_llll *ll = llll_clone(hatom_getllll(var_value));
				llll_free(hatom_change_to_llll(a, ll));
			} else {
				*a = *var_value;
			}
		} else {
			// search for substring
			char *str = hatom_getsym(a)->s_name;
			long len_str = strlen(str);
			long len_var_name = strlen(var_name->s_name);
			
			long num_found = 0; 
			char *substr = str;
			while (substr){ 
				substr = strstr(substr, var_name->s_name);
				if (substr) {
					num_found++;
					substr += len_var_name * sizeof(char);
				}
			}
			
			t_llll *temp = llll_get();
			llll_appendhatom_clone(temp, var_value, 0, WHITENULL_llll);
			char *var_value_str = NULL;
			llll_to_text_buf(temp, &var_value_str, 0, BACH_DEFAULT_MAXDECIMALS, 0, NULL);
			llll_free(temp);
			
			char *newstr;
			char PARENTHESIZE = false;
			long delta = 0;
			long len_var_value_str = strlen(var_value_str);
			long len_newstr = MAX(len_str + 1, len_str + 1 + num_found*(len_var_value_str + PARENTHESIZE*2 - len_var_name));
			newstr = (char *)bach_newptr(len_newstr * sizeof(char));
			strncpy_zero(newstr, str, len_str + 1);
			if (num_found > 0) {
				substr = str;
				while (substr) {
					substr = strstr(substr, var_name->s_name);
					if (substr && is_found_substring_entire_symbol(str, substr, len_var_name)) {
						long idx = (substr-str)/sizeof(char);
						
						if (PARENTHESIZE) {
							newstr[idx] = '(';
							strncpy(newstr+idx+1, var_value_str, len_str);
							newstr[idx+len_var_value_str+1] = ')';
						} else {
							strncpy(newstr+idx, var_value_str, len_str);
						}
						strncpy_zero(&newstr[idx+len_var_value_str+PARENTHESIZE*2+delta], &str[idx+len_var_name], len_newstr-(idx+len_var_value_str+PARENTHESIZE*2+delta));
						delta += (len_var_value_str + PARENTHESIZE*2 - len_var_name);
					}
					if (substr)
						substr += len_var_name * sizeof(char);
				}
			}
			
			hatom_setsym(a, gensym(newstr));
			bach_freeptr(var_value_str);
			bach_freeptr(newstr);
		}
	}
	return 0;
}


// destructive!
void substitute_var_in_expressions(t_llll *ll, t_symbol *var_name, t_hatom *var_value, long var_index)
{
	void *data[3];
	data[0] = &var_name;
	data[1] = &var_value;
	data[2] = &var_index;
	llll_funall(ll, (fun_fn) substitute_var_in_expressions_fn, data, 0, 0, FUNALL_ONLY_PROCESS_ATOMS);
}


long parse_with_lexpr_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_SYM){
		t_atom av;
		atom_setsym(&av, hatom_getsym(a));
		t_lexpr	*n_lexpr = lexpr_new(NULL, 1, &av);
		if (n_lexpr) {
			t_hatom *res;
			t_hatom vars[LEXPR_MAX_VARS]; // dummy: no vars.
			res = lexpr_eval(n_lexpr, vars);
			*a = *res;
			bach_freeptr(res);
		}
		lexpr_free(n_lexpr);
	}
	return 0;
}



void parse_universal_quantifiers_for_single_llll(t_llll *this_llll, long num_vars, t_univquant_var *vars, t_symbol **quantified_vars)
{
	t_llllelem *elem;
	if (this_llll->l_tail) {
		elem = this_llll->l_tail->l_prev;
		while (elem){
			t_llllelem *prev_el = elem->l_prev;
			if (hatom_gettype(&elem->l_hatom) == H_SYM){
				long i, found_idx = -1;
				for (i = 0; i < num_vars; i++) {
					if (hatom_getsym(&elem->l_hatom) == quantified_vars[i]) {
						found_idx = i;
						break;
					}
				}
				
				if (found_idx >= 0) {
					t_llll *wrapped = llll_wrap_element_range(elem, this_llll->l_tail);
					t_llll *copy = llll_clone(wrapped); // copy to be repeated for each element in the domain
					llll_destroyelem(wrapped->l_owner);
					llll_destroyelem(copy->l_head); // destroy quantifier
					if (vars[i].type == k_UNIVQUANT_TYPE_LONG_RANGE) {
						long j;
						for (j = vars[i].domain_min; j <= vars[i].domain_max; j++) {
							t_llll *modified_copy = llll_clone(copy);
							t_hatom h;
							hatom_setlong(&h, j);
							substitute_var_in_expressions(modified_copy, vars[i].name, &h, i);
							llll_chain(this_llll, modified_copy);
						}
					} else if (vars[i].type == k_UNIVQUANT_TYPE_EXPLICIT_DOMAIN) {
						t_llllelem *domainel;
						for (domainel = vars[i].explicit_domain->l_head; domainel; domainel = domainel->l_next) {
							t_llll *modified_copy = llll_clone(copy);
							substitute_var_in_expressions(modified_copy, vars[i].name, &domainel->l_hatom, i);
							llll_chain(this_llll, modified_copy);
						}
					}
					llll_free(copy);
				}
			}
			elem = prev_el;
		}
	}
}

t_llll *parse_universal_quantifiers(t_object *x, t_llll *ll, long num_vars, t_univquant_var *vars)
{
	long i;
	
	if (num_vars >= 10){
		object_error(x, "Too many variables!");
		return llll_clone(ll);
	}
	
	// building quantified_vars symbol (e.g. Vx, Vy, ...)
	t_symbol **quantified_vars;
	quantified_vars = (t_symbol **)bach_newptr(num_vars * sizeof(t_symbol *));
	for (i = 0; i < num_vars; i++) {
		char this_quantifiedsym[100];
		long this_len_name = strlen(vars[i].name->s_name);
		if (this_len_name >= 99)
			object_warn(x, "Warning: variable name is too long");
		snprintf_zero(this_quantifiedsym, 100, "V%s", vars[i].name->s_name);
		quantified_vars[i] = gensym(this_quantifiedsym);
	}
	
	t_llll *ll_cloned = llll_clone(ll); // we work on a copy, since we'll destroy and change things
	t_llll *scanned_ll = llll_scan(ll_cloned, true);
	t_llllelem *scannedelem;

	llll_flatten(scanned_ll, 1, 0);
	for (scannedelem = scanned_ll->l_tail; scannedelem; scannedelem = scannedelem->l_prev){
		if (hatom_gettype(&scannedelem->l_hatom) == H_OBJ) {
			t_llllelem *elem = (t_llllelem *)hatom_getobj(&scannedelem->l_hatom);
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				parse_universal_quantifiers_for_single_llll(hatom_getllll(&elem->l_hatom), num_vars, vars, quantified_vars);
			}
		}
	}
	// whole list
	parse_universal_quantifiers_for_single_llll(ll_cloned, num_vars, vars, quantified_vars);
	
	// then parsing with lexpr all math functions
	llll_funall(ll_cloned, (fun_fn) parse_with_lexpr_fn, NULL, 0, 0, FUNALL_ONLY_PROCESS_ATOMS);
	
	return ll_cloned;
	bach_freeptr(quantified_vars);
}


void univquant_anything(t_univquant *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);

	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 1);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}
	
	// do calculations
	if (inlet == 0) {
		t_llll *expression = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		t_llll *variable_domains = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
		
		long num_vars = variable_domains->l_size;
		if (num_vars > 0) {
			t_llllelem *varel;
			long i;
			t_univquant_var *vars;
			vars = (t_univquant_var *)bach_newptr(num_vars * sizeof(t_univquant_var));

			for (i = 0; i < num_vars; i++)
				vars[i] = get_default_univquant_var();

			// parse domains
			for (varel = variable_domains->l_head, i = 0; varel && i < num_vars; i++, varel = varel->l_next) {
				if (hatom_gettype(&varel->l_hatom) == H_LLLL) {
					t_llll *thisvar_ll = hatom_getllll(&varel->l_hatom);
					if (thisvar_ll && thisvar_ll->l_size >= 2 && hatom_gettype(&thisvar_ll->l_head->l_hatom) == H_SYM) {
						vars[i].name = hatom_getsym(&thisvar_ll->l_head->l_hatom);
						if (hatom_gettype(&thisvar_ll->l_head->l_next->l_hatom) == H_LLLL) {
							t_llll *domainrange = hatom_getllll(&thisvar_ll->l_head->l_next->l_hatom);
							vars[i].type = k_UNIVQUANT_TYPE_LONG_RANGE;
							if (domainrange->l_size >= 2) {
								if (is_hatom_number(&domainrange->l_head->l_hatom) && is_hatom_number(&domainrange->l_head->l_next->l_hatom)){
									vars[i].domain_min = hatom_getlong(&domainrange->l_head->l_hatom);
									vars[i].domain_max = hatom_getlong(&domainrange->l_head->l_next->l_hatom);
								}
							}
						} else {
							vars[i].type = k_UNIVQUANT_TYPE_EXPLICIT_DOMAIN;
							vars[i].explicit_domain = llll_clone(thisvar_ll);
							llll_behead(vars[i].explicit_domain);
						}
					}
				} 
			}
			
			
			// calculate
			t_llll *out_ll = parse_universal_quantifiers((t_object *)x, expression, num_vars, vars);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, out_ll, 0);

			// free univquant vars
			for (i = 0; i < num_vars; i++)
				if (vars[i].explicit_domain) 
					llll_free(vars[i].explicit_domain);
			bach_freeptr(vars);

			x->n_ob.l_rebuild = 0;
			univquant_bang(x);
		}
		
		llll_release(expression);
		llll_release(variable_domains);
	}
}


void univquant_assist(t_univquant *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) 
			sprintf(s, "llll: Expression");
		else
			sprintf(s, "llll: Variable Domains");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Quantified Expression", type);
	}
}

void univquant_inletinfo(t_univquant *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void univquant_free(t_univquant *x)
{	
	object_free_debug(x->m_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_univquant *univquant_new(t_symbol *s, short ac, t_atom *av)
{
	t_univquant *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if (x = (t_univquant *) object_alloc_debug(univquant_class)) {
	
		attr_args_process(x, ac, av);
		err = llllobj_obj_setup((t_llllobj_object *) x, 2, "4");
		x->m_proxy = proxy_new_debug((t_object *) x, 1, &x->m_in);
		if (err) {
			error("Cannot find bach.llll: bach.univquant can't be instatiated.");
			object_free_debug(x);
			return NULL;
		}
	} else 
		object_post((t_object *) x, "wrong argument!");
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

