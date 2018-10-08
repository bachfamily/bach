/**
 @file
 constraints.c
 
 @name
 bach.constraints
 
 @realname
 bach.constraints
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Solve constraints satisfaction problems
 
 @description
 Solves constraints satisfaction problems.
 The rules for the evaluation of each constraint must be provided in the object's lambda loop, each associated to a unique arbitrary name.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 constraint satisfaction problem, rule, domain, lambda loop, solve, constraint
 
 @seealso
 bach.comb, bach.perm, bach.cartesianprod, God Solve the Queens
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

#define CONSTRAINTS_VARWISE_BLOCK_SIZE    16
#define POS_OUTPUT_INTERVAL 0
#define CONSTRAINTS_POINTS_POOL_SIZE 100000 // * 88
#define CONSTRAINTS_POINTMAP_SLOTS    100003 // * 8
                                             //#define CONSTRAINTS_POINTS_POOL_SIZE 100
                                             //#define CONSTRAINTS_POINTMAP_SLOTS    103

#ifdef CONFIGURATION_Development
//#define CONSTRAINTS_DEBUG
#endif

#ifdef CONSTRAINTS_DEBUG
#define CONSTRAINTS_dev_post(...) post(__VA_ARGS__)
#define CONSTRAINTS_dev_cpost(...) post(__VA_ARGS__)
#define CONSTRAINTS_dev_object_post(...) object_post(__VA_ARGS__)
#define CONSTRAINTS_dev_object_warn(...) object_warn(__VA_ARGS__)
#define CONSTRAINTS_dev_llll_print(ll, cl, e, md, fn) llll_print(ll, cl, e, md, fn)
#else
#define CONSTRAINTS_dev_post(...) ((void) 0)
#define CONSTRAINTS_dev_cpost(...) ((void) 0)
#define CONSTRAINTS_dev_object_post(...) ((void) 0)
#define CONSTRAINTS_dev_object_warn(...) ((void) 0)
#define CONSTRAINTS_dev_llll_print(ll, cl, e, md, fn) ((void) 0)
#endif

typedef struct _constraints_rvs
{
    long                    r_result;
    t_bool                    r_accepted;
    t_llll                  *r_getdomains;
    t_llll                  *r_setdomains;
} t_constraints_rvs;

typedef struct _constraints
{
    struct llllobj_object     n_ob;
    void                    *n_proxy[3];
    long                    n_in;
    long                    n_nsolutions;
    long                    n_random;
    long                    n_nc; // node consistency
    long                    n_ac; // arc consistency
    long                    n_sortdomains;
    long                    n_sortconstraints;
    long                    n_stop;
    long                    n_maxtime;
    long                    n_maxsteps;
    long                    n_parallel;
    long                    n_more;
    long                    n_weak;
    long                    n_greedy;
    long                    n_picky;
    long                    n_scoredetails;
    t_atom                    n_maxscore;
    t_atom                    n_minscore;
    t_atom                  n_goalscore;
    long                    n_provisionals;
    t_systhread                n_thread;
    t_bach_atomic_lock        n_inuse;
    t_qelem                    n_pos_qelem;
    t_qelem                    n_score_qelem;
    t_qelem                    n_provisionals_qelem;
    t_qelem                 n_detailed_score_qelem;
    double                    n_normalized_position;
    long                    n_score;
    t_llll                    *n_provisionals_ll;
    t_llll                  *n_detailed_score_ll;
    t_systhread_mutex        n_provisionals_mutex;
    t_systhread_mutex        n_detailed_score_mutex;
    t_bach_atomic_lock      n_domain_lock;
    t_constraints_rvs       n_rvs;
} t_constraints;



typedef enum {
    V_GOOD = 0,
    V_INVALID,
    V_EMPTY
} e_llll_constraints_validity;

typedef struct _constraint {
    t_symbol    *c_name; // only contains a reference
    long        c_nvars;
    long        *c_vars;
    long        c_maxvar;
    long        c_outputvars;
    long        c_low;
    long        c_required;
} t_constraint;


typedef struct _domainvalues {
    long d_size;
    t_hatom *d_hatoms;
    long d_step; // the variable which changed the domain
} t_domainvalues;


typedef struct _domain {
    t_domainvalues  *d_values;
    t_domainvalues  *d_currentvalues;
    t_llll          **d_lls;
    t_llll          **d_currentll;
    long            d_var;
} t_domain;



typedef struct {
    t_hatom *s_hatom;
    long    s_score;
} t_scored_hatom;

typedef struct {
    long            s_size;
    t_scored_hatom  *s_scored_hatoms;
} t_scored_purged_domain;

typedef struct _pointllelem {
    long                *p_point;
    struct _pointllelem    *p_prev;
    struct _pointllelem    *p_next;
    struct _pointllelem **p_bucket;
} t_pointllelem;

typedef struct _mapllelem {
    t_pointllelem        *m_pointllelem;
    struct _mapllelem    *m_prev;
    struct _mapllelem    *m_next;
} t_mapllelem;

typedef struct _pointmap {
    t_pointllelem    **p_bucket;
    t_mapllelem        *p_mapll_head;
    t_mapllelem        *p_mapll_tail;
    t_pointllelem    **p_ptelempool;
    t_pointllelem    **p_ptelempool_next_free;
    t_mapllelem        **p_mapelempool;
    t_mapllelem        **p_mapelempool_next_free;
    long            **p_points_pool;
    long            **p_points_pool_next_free;
    long            p_nvars;
    long            p_stored_points;
    long            p_own_my_points;
} t_pointmap;

typedef struct _score_and_good {
    long    score;
    t_bool  good;
} t_score_and_good;

void constraints_assist(t_constraints *x, void *b, long m, long a, char *s);
void constraints_inletinfo(t_constraints *x, void *b, long a, char *t);

t_constraints *constraints_new(t_symbol *s, short ac, t_atom *av);
void constraints_free(t_constraints *x);

void constraints_bang(t_constraints *x);
void constraints_int(t_constraints *x, t_atom_long v);
void constraints_float(t_constraints *x, double v);
void constraints_anything(t_constraints *x, t_symbol *msg, long ac, t_atom *av);
void constraints_stop(t_constraints *x);

t_max_err constraints_setattr_minscore(t_constraints *x, void *attr, long ac, t_atom *av);
t_max_err constraints_setattr_maxscore(t_constraints *x, void *attr, long ac, t_atom *av);
t_max_err constraints_setattr_goalscore(t_constraints *x, void *attr, long ac, t_atom *av);



long constraints_func(t_constraints *x, t_llll *what, t_bool *accepted, long def_accept = 0, long def_result = 0);
void constraints_outpos(t_constraints *x, long current_var, long double tree_size_inv, long nvars, long *positions, long double *pos_weights);
void constraints_outscore(t_constraints *x, long score);
void constraints_out_detailed_score(t_constraints *x, long score, t_constraint *constraints, t_score_and_good *score_constraintwise);
void constraints_outprovisionals(t_constraints *x, t_hatom **provisionals);
void constraints_outprovisionals_scored(t_constraints *x, t_scored_hatom **provisionals);
void constraints_outprovisionals_remapped(t_constraints *x, t_hatom **provisionals, long nvars, long *o2r);

void constraints_output_tree(t_constraints *x, t_symbol *msg, long ac, t_atom *av);


void constraints_calculate_tree_size(long nvars, t_domain *domains,
                                     long double *domain_positional_multipliers, long double *tree_size, long double *tree_size_inv);

void constraints_fill_domain(t_llll *this_domain_ll, t_domain *this_domains,
                             long step = 0, t_bool reverse_domains = false, t_bool randomize_domains = false);

void constraints_fill_spd(t_domainvalues *values, t_scored_purged_domain *this_scored_purged_domains);

void constraints_fill_arrays(t_constraints *x, const t_llll *domains_ll, const t_llll *constraints_ll,
                             long *nvars, t_domain **domains,
                             long *nconstraints, t_constraint **constraints,
                             const t_bool force_required = false, const t_bool reverse_domains = false, const t_bool randomize_domains = false);

void constraints_free_domains(t_domain *domains);
void constraints_free_constraints(t_constraint *constraints);
void constraints_free_constraints_varwise(t_constraint ***constraints_varwise);
void constraints_free_garbage(t_llll *garbage);

t_constraint ***constraints_varwise_init(t_constraints *x, t_constraint *constraints, long nconstraints, long nvars);

void constraints_assign_maxvar(t_constraint *constraints);


void constraints_output(t_constraints *x, t_llll *solutions, t_max_err err);
t_max_err constraints_backtrack_wrapped(t_constraints *x, t_llll *data, t_llll *res);
t_max_err constraints_weak_wrapped(t_constraints *x, t_llll *data, t_llll *res);
t_max_err constraints_hungry_wrapped(t_constraints *x, t_llll *data, t_llll *res);

void constraints_getdomains(t_constraints *x, t_llll *getdomains, t_domain *domains, long nvars);
void constraints_getdomains_remapped(t_constraints *x, t_llll *getdomains, t_domain *domains, long nvars, long *o2r);

t_llll *constraints_simple_backtrack(t_constraints *x, const t_llll *domains_ll, const t_llll *constraints_ll, const t_llll *more_ll);
t_llll *constraints_weak(t_constraints *x, t_llll *domains_ll, t_llll *constraints_ll);
t_llll *constraints_hungry(t_constraints *x, t_llll *domains_ll, t_llll *constraints_ll);

void constraints_pos_qelem_do(t_constraints *x);
void constraints_score_qelem_do(t_constraints *x);
void constraints_score_detailed_qelem_do(t_constraints *x);
void constraints_provisionals_qelem_do(t_constraints *x);

void constraints_move_to_next_solution(t_hatom ***this_current, t_hatom **under_exam, long *this_var, long **this_positions);
e_llll_constraints_validity constraints_check_domains(t_llll *domains);
e_llll_constraints_validity constraints_check_domains_allow_empty(t_constraints *x, const t_llll *domains);
long constraints_check_constraints(t_constraints *x, const t_llll *constraints, long nvars);
e_llll_constraints_validity constraints_node_consistency(t_constraints *x, t_domain *domains, long *nconstraints, t_constraint *constraints);

long sort_constraints_testfn(void *dummy, t_llllelem *a, t_llllelem *b);
long sort_domains_testfn(void *dummy, t_llllelem *a, t_llllelem *b);
void shuffle_ptr_array(void **arr, long size);
void shuffle_hatom_array(t_hatom *arr, long size);
void shuffle_long_array(long *arr, long size);
int sort_domains_cb(t_domain *a, t_domain *b);
int sort_constraints_cb(t_constraint *a, t_constraint *b);
int sort_constraint_ptrs_cb(t_constraint **a, t_constraint **b);
int sort_scored_hatoms_cb(t_scored_hatom *a, t_scored_hatom *b);

t_pointmap *pointmap_new(long nvars);
t_uint64 pointmap_insert(t_pointmap *x, long *point);
long pointmap_check_for_existence(t_pointmap *x, long *point);
long *pointmap_get_point(t_pointmap *x);
void pointmap_free(t_pointmap *x);
unsigned long point_hash(long *point, long nvars);

long constraints_evaluate(t_constraints *x, t_hatom **tuple, t_constraint *this_constraint, t_bool *accepted);
long constraints_evaluate_with_remap(t_constraints *x, t_hatom **tuple, t_constraint *this_constraint, long *var_remap_r2o);

void object_warn_point(t_constraints *x, long nvars, long *point);

void constraints_post_int_tuple(long *tuple);
void constraints_post_hatom_tuple(t_hatom **tuple);

void post_constraints(t_constraint *c);
void post_domains(t_domain *d);
void post_score_constraintwise(t_constraint *c, t_score_and_good *s);

t_class *constraints_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.constraints", (method)constraints_new, (method)constraints_free, (short)sizeof(t_constraints), 0L, A_GIMME, 0);
    
    // @method llll @digest Function depends on inlet
    // @description
    // An llll in the first inlet sets the problem domains and starts the search.
    // Each sublist of the domains llll is the domain for one variable of the problem. <br />
    // An llll in the second inlet sets the associations between constraints and domains.
    // Each sublist of the associations llll represents one constraint as follows:
    // the first element of the sublist is the constraint name, which should be matched by a corresponding branch of the lambda loop;
    // then one or more sublists follow, each containing the indices of the variables to which the given constraint applies
    // (technically we are defining as many constraints as sublists);
    // finally, one or more optional keywords can be specified: <m>low</m>, <m>vars</m>, <m>required</m>.
    // If the <m>low</m> keyword is present, the constraint is considered a low-priority one:
    // even if the solver is allowed changing the order of evaluation of the constraints
    // (which in general is strongly suggested for efficiency reasons),
    // low-priority constraints are always evaluated last.
    // This can be useful in some exotic cases in which high-priority constraints set the evaluation criteria for low-priority ones.
    // If the <m>vars</m> keyword is present,
    // an llll containing the <m>vars</m> symbol followed by the indices of the concerned variables is output immediately before evaluating the constraint.
    // This can be useful when the same constraint name applies to different variable sets,
    // and the actual variable numbers define the evaluation rules.
    // If the <m>required</m> keyword is present, the heuristic and hungry engines knows that the evaluation of this constraint
    // can yield a <m>reject</m> result (see below), causing the proposed solution to be immediately discarded.
    // It is advisable, although not mandatory, adding the <m>required</m> keyword to such constraints, as it will allow some specific search optimizations. <br />
    // A single-element llll in the third inlet is treated as the return value from the lambda loop: <br />
    // <o>bach.constraints</o> outputs from its lambda outlet combinations of values (partial labels, in techical jargon) to be evaluated,
    // each with respect to one specific constraint.
    // Each partial label is preceded by the name of the relevant constraint, so that the partial label itself can be routed to the appropriate part of the patch.
    // The result of the evaluation is expected in the third inlet.
    // It must be 0 or 1 (respectively "reject" or "accept") for the deterministic solver.
    // For the heuristic and hungry solvers, all the results (which have to be integers) for one solution will be summed together to concour to the solution's score.
    // If the <m>reject</m> keyword is received by the heuristic solver the proposed solution being currently evaluated is immediately rejected. <br />
    // Moreover, if the <m>provisionals</m> attribute is set for the strong and hungry solvers, each time a partial solution is found
    // (that is, each time all the variables evaluated so far have a set consistent assignments)
    // it is output from the third outlet, preceded by the keyword <m>provisional</m>.
    // In response to it, a <m>getdomains</m> or <m>setdomains</m> message can be sent to the lambda inlet. <br />
    // The <m>getdomains</m> message, followed by a one or more variable indices, will cause the current domains corresponding to said indices
    // to be output as sublists of an llll preceded by the <m>domains</m> keyword. At this point, a <m>setdomains</m> message can be sent to the lambda inlet. <br />
    // The <m>setdomains</m> message allows to change "on the fly" the domain of one or more variable yet to be assigned.
    // It is composed of the <m>setdomains</m> keyword, followed by one or more sublists, each of which is composed of an optional domain index (defaulting to 1 if not present),
    // and one or more sublists each containing a domain to substitute the current one. The first sublist will replace the domain for the specified index,
    // or the first domain if not specified; the second sublist will replace the domain for the following domain index; and so on.
    // For example, the llll <m>setdomains ((a b c) (d e f))</m> will cause the first domain to be set to <m>a b c</m>, and the second to be set to <m>d e f</m>;
    // the llll <m>setdomains (10 (g h i) (j k l))</m> will cause the tenth domain to be set to <m>g h i</m>, and the eleventh to be set to <m>j k l</m>;
    // the llll <m>setdomains (4 (m n)) (8 (o p) (q))</m> will cause the fourth domain to be set to <m>m n</m>, the eighth to be set to <m>o p</m>,
    // and the ninth to be set to <m>q</m>. This is not equivalent to assigning the variable, as its consistency with the problem rules has still to be checked.<br />
    // Only domains of variables which have not been assigned yet will actually be replaced:
    // if a domain is specified for an already assigned variable, it will be ignored.
    // A history of all the domains assignment for a variable is maintained internally,
    // so as to be able to retrieve a previously assigned domain in case of backtracking.
    // Notice that the <m>setdomains</m> message can sent only once for each provisional output from the third outlet,
    // in response to either the <m>provisional</m> or the <m>domains</m> message.
    // The latter case is useful for the typical case of progressively filtering out elements of a domain.<br />
    // As a final note, if the <m>provisionals</m> attribute is set, immediately after the <m>provisional</m> message is output from the lambda outlet,
    // and the optional <m>getdomains</m> and <m>setdomains</m> are received,
    // the current partial solution is output from the leftmost outlet as well, preceded by the <m>provisional</m> keyword.
    // This allows viewing or processing otherwise said partial solution in the main or scheduler thread,
    // even if the <m>parallel</m> attribute is on. <br />
    // As a final note, the <m>provisionals</m> attribute for the heuristic solver has a different result:
    // as the heuristic solver is not chronological, it does not output partial assignments,
    // but rather global assignments that can still be improved.
    // For the same reason, this does not happen through the lambda outlet, as it would not make sense to change the domains "on the fly",
    // but only through the first outlet, with the syntax described above.
    class_addmethod(c, (method)constraints_anything,    "anything",        A_GIMME,    0);
    
    // @method int @digest Lambda inlet
    // @description
    // <o>bach.constraints</o> outputs from its lambda outlet combinations of values (partial labels, in techical jargon) to be evaluated,
    // each with respect to one specific constraint.
    // Each partial label is preceded by the name of the relevant constraint, so that the partial label itself can be routed to the appropriate part of the patch.
    // The result of the evaluation is expected in the third inlet.
    // The deterministic solver will consider a 0 or 1 respectively as "reject" or "accept".
    // The heuristic solver will sum together all the values received for one solution, thus determining the solution's score.
    // If no value is re-injected in the lambda inlet, the result of the evaluation will be considered to be 0 by the heuristic and hungry solvers,
    // and 1 by the strong solver: this means that, in any case, the proposed assignation will be accepted.
    // Notice that the <m>reject</m> keyword (see description of <m>anything</m>) is also accepted in place of a 0 by the strong solver.
    class_addmethod(c, (method)constraints_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)constraints_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)constraints_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Perform last operation
    // @description
    // In first inlet: return the solution for the most recently received domains and constraints. <br />
    // @copy BACH_DOC_BANG_LAMBDA_CAVEAT
    class_addmethod(c, (method)constraints_bang,        "bang",            0);
    
    // @method stop @digest Stop search
    // @description A <m>stop</m> message will cause the search to stop immediately.
    class_addmethod(c, (method)constraints_stop,        "stop",            0);
    
    class_addmethod(c, (method)constraints_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)constraints_inletinfo,    "inletinfo",    A_CANT,        0);
    
    CLASS_ATTR_LONG(c, "solutions",    0,    t_constraints, n_nsolutions);
    CLASS_ATTR_LABEL(c, "solutions", 0, "Number of Solutions");
    CLASS_ATTR_FILTER_MIN(c, "solutions", 0);
    CLASS_ATTR_BASIC(c, "solutions", 0);
    // @description Strong solver only: number of solutions to find.
    // When set to 0, all the solutions are found.
    
    CLASS_ATTR_LONG(c, "weak",    0,    t_constraints, n_weak);
    CLASS_ATTR_LABEL(c, "weak", 0, "Use Heuristic Search Engine");
    CLASS_ATTR_FILTER_MIN(c, "weak", 0);
    CLASS_ATTR_BASIC(c, "weak", 0);
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "weak", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "engine",    0,    t_constraints, n_weak);
    CLASS_ATTR_FILTER_MIN(c, "engine", 0);
    CLASS_ATTR_BASIC(c, "engine", 0);
    CLASS_ATTR_FILTER_CLIP(c, "engine", 0, 2);
    CLASS_ATTR_STYLE_LABEL(c, "engine", 0, "enumindex", "Engine");
    CLASS_ATTR_ENUMINDEX(c,"engine", 0, "Strong Heuristic Hungry");
    // @description The <m>engine</m> attribute allows choosing which search engine will be used. <br />
    // The strong engine, based upon a chronological backtracking algorithm,
    // will look for solutions satisfying all the constraints of the problem.
    // The fact that the engine is chronological is crucial:
    // as variables are assigned one after another,
    // it is possible to view their assignment and possibly change the domains of those yet to be assigned. <br />
    // The heuristic engine, based upon a hill-climbing algorithm,
    // will look for solutions achieving maximal score, the score being defined as the sum of the evaluation results for every constraint.
    // Notice that "maximal score" doesn't necessarily mean "maximum score":
    // the heuristic solver will try to find what it considers a good solution for the problem,
    // but in most cases this might not be the best possible solution.
    // The usefulness of the heuristic solver lies in the fact
    // that in many occasions finding the best possible solution would require an enormous amount of time,
    // whereas a reasonably good solution can be found quickly.
    // It also happens that a "best possible solution" cannot actually be defined,
    // but quality scores for different features of the solution can.
    // On the other hand, by appropriately setting the <m>minscore</m> and <m>maxscore</m> attributes,
    // the heuristic engine can be employed for solving deterministic problems:
    // this can indeed be a very efficient approach for large problems. <br />
    // The hungry engine adopts a somewhat hybrid approach:
    // it builds chronologically a solution, but accepts scores in response to evaluations.
    // Namely, it sorts the constraints so as to be able to process and assign the lowest-indexed variables first.
    // Then, it evaluates the first constraint for every possible combination of assignments to the variables it concerns,
    // and chooses the highest-scored assignment. After that, it repeats the process for the second constraint, and so on.
    // As assignment can be rejected, it is possible that a constraint can not be satisfied by any possible assignment of its variables,
    // because of the values taken by previously assigned variables are not compatible with it.
    // In this case, the solver backtracks and picks the second-best solution for the previously assigned constraint.
    // This can happen recursively, picking decreasingly well-scored assignments for the previous constraint,
    // and going back to previously evaluated constraints, until an acceptable solution is found, or no solution is proved to exist.
    // As such, it is a deterministic solver, which can be useful for large optimization problems
    // in which each variable assigned is directly influenced mostly or solely by recent ones.
    CLASS_ATTR_LONG(c, "greedy",    0,    t_constraints, n_greedy);
    CLASS_ATTR_LABEL(c, "greedy", 0, "Greedy");
    CLASS_ATTR_FILTER_MIN(c, "greedy", 0);
    CLASS_ATTR_BASIC(c, "greedy", 0);
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "greedy", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "picky",    0,    t_constraints, n_picky);
    CLASS_ATTR_LABEL(c, "picky", 0, "Picky");
    CLASS_ATTR_FILTER_MIN(c, "picky", 0);
    CLASS_ATTR_BASIC(c, "picky", 0);
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "picky", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_ATOM(c, "minscore",    0,    t_constraints, n_minscore);
    CLASS_ATTR_LABEL(c, "minscore", 0, "Minimum Score");
    CLASS_ATTR_FILTER_MIN(c, "minscore", 0);
    CLASS_ATTR_ACCESSORS(c, "minscore", (method)NULL, (method)constraints_setattr_minscore);
    // @description Heuristic solver only: minimum required score.
    // Only solutions whose score is greater or equal will be returned.
    // The value of the attribute can be any integer, or <m>&lt;none&gt;</m> (default). <br />
    // N.B.: if no time limit is set and solutions with sufficient score are rare or non existing,
    // <o>bach.constraints</o> can be stuck in an infinite loop.
    
    CLASS_ATTR_ATOM(c, "maxscore",    0,    t_constraints, n_maxscore);
    CLASS_ATTR_LABEL(c, "maxscore", 0, "Maximum Score");
    CLASS_ATTR_FILTER_MIN(c, "maxscore", 0);
    CLASS_ATTR_ACCESSORS(c, "maxscore", (method)NULL, (method)constraints_setattr_maxscore);
    // @description Heuristic solver only:
    // when a solution whose score is greater or equal is found, it is output and no better solution is searched for.
    // The value of the attribute can be any integer, or <m>&lt;none&gt;</m> (default). <br />
    
    CLASS_ATTR_ATOM(c, "goalscore",    0,    t_constraints, n_goalscore);
    CLASS_ATTR_LABEL(c, "goalscore", 0, "Goal Score");
    CLASS_ATTR_FILTER_MIN(c, "goalscore", 0);
    CLASS_ATTR_ACCESSORS(c, "goalscore", (method)NULL, (method)constraints_setattr_goalscore);
    // @description Heuristic solver only:
    // as long as this score is not met, new solutions will be searched for within maxtime.
    // Nonetheless, solution with a lower score will still be considered acceptable, and therefore returned.
    // The value of the attribute can be any integer, or <m>&lt;none&gt;</m> (default). <br />
    // N.B.: if no time limit is set and solutions with sufficient score are rare or non existing,
    // <o>bach.constraints</o> can be stuck in an infinite loop.
    
    CLASS_ATTR_LONG(c, "provisionals",    0,    t_constraints, n_provisionals);
    CLASS_ATTR_FILTER_CLIP(c, "provisionals", 0, 2);
    CLASS_ATTR_STYLE_LABEL(c, "provisionals", 0, "enumindex", "Output Provisional Solutions");
    CLASS_ATTR_ENUMINDEX(c, "provisionals", 0, "No Better Equal");
    // @description Heuristic solver: <br />
    // When set to 0, no provisional solutions are output during the search. <br />
    // When set to 1, only provisional solutions that improve the score are output. <br />
    // When set to 2, provisional solution with the same score as the previous ones are output. <br />
    // Strong and hungry solvers: <br />
    // Partial solutions are output from the third and first outlets when set to 1 or 2.
    
    CLASS_ATTR_LONG(c, "random",    0,    t_constraints, n_random);
    CLASS_ATTR_LABEL(c, "random", 0, "Random");
    CLASS_ATTR_FILTER_CLIP(c, "random", 0, 1);
    CLASS_ATTR_STYLE(c, "random", 0, "onoff");
    CLASS_ATTR_BASIC(c, "random", 0);
    // @description Deterministic and hungry solvers only:
    // when set to 1 the domains are randomized.
    
    CLASS_ATTR_LONG(c, "more",    0,    t_constraints, n_more);
    CLASS_ATTR_LABEL(c, "more", 0, "Output more llll");
    CLASS_ATTR_FILTER_CLIP(c, "more", 0, 1);
    CLASS_ATTR_STYLE(c, "more", 0, "onoff");
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "more", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "nodeconsistency",    0,    t_constraints, n_nc);
    CLASS_ATTR_LABEL(c, "nodeconsistency", 0, "Node Consistency");
    CLASS_ATTR_FILTER_CLIP(c, "nodeconsistency", 0, 1);
    CLASS_ATTR_STYLE(c, "nodeconsistency", 0, "onoff");
    // @description Strong and hungry solvers: when set to 1 (as by default),
    // node consistency is enforced before starting the backtracking search.
    // This means that constraints affecting single variables are processed first,
    // so as to reduce the domain sizes and optimize the search process.
    // No provisionals are output during the node consistency enforcement,
    // and for this reason it may be necessary to set the attribute to 0 in some situations, if the <m>provisionals</m> attribute is on.
    
    
    CLASS_ATTR_LONG(c, "sortdomains",    0,    t_constraints, n_sortdomains);
    CLASS_ATTR_LABEL(c, "sortdomains", 0, "Sort Domains");
    CLASS_ATTR_FILTER_CLIP(c, "sortdomains", 0, 1);
    CLASS_ATTR_STYLE(c, "sortdomains", 0, "onoff");
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "sortdomains", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "scoredetails",    0,    t_constraints, n_scoredetails);
    CLASS_ATTR_LABEL(c, "scoredetails", 0, "Output Score Details");
    CLASS_ATTR_FILTER_CLIP(c, "scoredetails", 0, 1);
    CLASS_ATTR_STYLE(c, "scoredetails", 0, "onoff");
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "scoredetails", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "sortconstraints",    0,    t_constraints, n_sortconstraints);
    CLASS_ATTR_LABEL(c, "sortconstraints", 0, "Sort Constraints");
    CLASS_ATTR_FILTER_CLIP(c, "sortconstraints", 0, 1);
    CLASS_ATTR_STYLE(c, "sortconstraints", 0, "onoff");
    CLASS_ATTR_INVISIBLE(c, "sortconstraints", 0);
    // @description Strong and hungry solvers:
    // When set to 1 (as by default), the constraints might not be evaluated in the order they are provided by the user,
    // but according to a different ordering allowing the search to be performed more efficiently.
    // If the <m>provisionals</m> attribute is on, this may interfere with the dynamic reassignment of domains.
    // For this reason, it is generally advisable to set the attribute to 0 if the domains will be reassigned during the search.
    
    CLASS_ATTR_LONG(c, "maxtime",    0,    t_constraints, n_maxtime);
    CLASS_ATTR_LABEL(c, "maxtime", 0, "Maximum Running Time");
    CLASS_ATTR_FILTER_MIN(c, "maxtime", 0);
    CLASS_ATTR_BASIC(c, "maxtime", 0);
    // @description Stops the search after the specified time (in ms).
    // The default is 60000; when set to 0 no time limit is defined.
    
    CLASS_ATTR_LONG(c, "maxsteps",    0,    t_constraints, n_maxsteps);
    CLASS_ATTR_LABEL(c, "maxsteps", 0, "Maximum Number of Steps Without Improvement");
    CLASS_ATTR_FILTER_MIN(c, "maxsteps", 0);
    CLASS_ATTR_BASIC(c, "maxsteps", 0);
#ifndef CONFIGURATION_Development
    CLASS_ATTR_INVISIBLE(c, "maxsteps", 0);
#endif
    // @exclude bach.constraints
    
    CLASS_ATTR_LONG(c, "parallel",    0,    t_constraints, n_parallel);
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    CLASS_ATTR_FILTER_CLIP(c, "parallel", 0, 1);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    // @description When set to 1, the search is performed in a separate thread.
    // This means that the normal Max operation is not interrupted.
    // The <m>parallel</m> attribute is highly experimental and can lead to serious problems,
    // including data corruption and crashes.
    // In general, it is essential that the lambda loop is not modified and the patch is not saved or closed
    // as long as the search is going on. Such operations are more than likely to crash Max.
    
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    
    class_register(CLASS_BOX, c);
    constraints_class = c;
    
    CONSTRAINTS_dev_post("bach.constraints compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


t_max_err constraints_setattr_minscore(t_constraints *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
            x->n_minscore = *av;
        else
            atom_setsym(&x->n_minscore, gensym("<none>"));
    } else
        atom_setsym(&x->n_minscore, gensym("<none>"));
    
    x->n_ob.l_rebuild = 1;
    return MAX_ERR_NONE;
}

t_max_err constraints_setattr_maxscore(t_constraints *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
            x->n_maxscore = *av;
        else
            atom_setsym(&x->n_maxscore, gensym("<none>"));
    } else
        atom_setsym(&x->n_maxscore, gensym("<none>"));
    
    x->n_ob.l_rebuild = 1;
    return MAX_ERR_NONE;
}

t_max_err constraints_setattr_goalscore(t_constraints *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
            x->n_goalscore = *av;
        else
            atom_setsym(&x->n_goalscore, gensym("<none>"));
    } else
        atom_setsym(&x->n_goalscore, gensym("<none>"));
    
    x->n_ob.l_rebuild = 1;
    return MAX_ERR_NONE;
}


void constraints_stop(t_constraints *x)
{
    x->n_stop = 1;
}

void constraints_bang(t_constraints *x)
{
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        constraints_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void constraints_int(t_constraints *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    constraints_anything(x, _sym_int, 1, &outatom);
}

void constraints_float(t_constraints *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    constraints_anything(x, _sym_float, 1, &outatom);
}

void constraints_anything(t_constraints *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *domains = NULL, *in_ll = NULL, *constraints = NULL, *more = NULL, *solutions;
    long inlet = proxy_getinlet((t_object *) x);
    x->n_rvs.r_result = 0;
    
    switch (inlet) {
        case 0:
            if (bach_atomic_trylock(&x->n_inuse)) {
                object_error((t_object *) x, "Already running");
                return;
            }
            if (msg != _sym_bang) {
                in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                if (!in_ll)
                    return;
                if (in_ll->l_size == 0) {
                    object_error((t_object *) x, "Needs at least one domain");
                    return;
                }
                if (hatom_getsym(&in_ll->l_head->l_hatom) == gensym("more")) {
                    more = in_ll;
                } else {
                    domains = in_ll;
                    llll_retain(domains);
                    llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, domains, 0);
                    constraints = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
                }
            } else {
                domains = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
                constraints = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
            }
            x->n_stop = 0;
            if (!x->n_parallel) {
                switch (x->n_weak) {
                    case 0:
                        solutions = constraints_simple_backtrack(x, domains, constraints, more);
                        break;
                    case 1:
                        solutions = constraints_weak(x, domains, constraints);
                        break;
                    case 2:
                        solutions = constraints_hungry(x, domains, constraints);
                        break;
                }
                constraints_output(x, solutions, 0); // this will retain solutions
                llll_free(solutions);
                llll_release(domains);
                llll_release(constraints);
                llll_release(more);
            } else {
                t_llll *data = llll_get();
                llll_appendobj(data, domains, 0, WHITENULL_llll);
                llll_appendobj(data, constraints, 0, WHITENULL_llll);
                llll_appendobj(data, more, 0, WHITENULL_llll);
                switch (x->n_weak) {
                    case 0:
                        bach_thread_start((t_object *) x, LLLL_OBJ_VANILLA, data, 0, (thread_task_fn) constraints_backtrack_wrapped, (thread_end_fn) constraints_output, &x->n_thread);
                        break;
                    case 1:
                        bach_thread_start((t_object *) x, LLLL_OBJ_VANILLA, data, 0, (thread_task_fn) constraints_weak_wrapped, (thread_end_fn) constraints_output, &x->n_thread);
                        break;
                    case 2:
                        bach_thread_start((t_object *) x, LLLL_OBJ_VANILLA, data, 0, (thread_task_fn) constraints_hungry_wrapped, (thread_end_fn) constraints_output, &x->n_thread);
                        break;
                }
            }
            break;
        case 1:
            x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
            break;
        case 2:
            if (msg == LLLL_NATIVE_MSG) {
                t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                if (lambda_llll) {
                    if (lambda_llll->l_size) { // if there's an llll then parse it
                        t_hatom *lambda_hatom = &lambda_llll->l_head->l_hatom;
                        if (lambda_hatom->h_type != H_SYM) {
                            x->n_rvs.r_result = hatom_getlong(lambda_hatom);
                            x->n_rvs.r_accepted = true;
                        } else if (lambda_hatom->h_w.w_sym == _llllobj_sym_setdomains) {
                            llll_retain(lambda_llll);
                            bach_atomic_lock(&x->n_domain_lock);
                            llll_free(x->n_rvs.r_setdomains);
                            x->n_rvs.r_setdomains = lambda_llll;
                            bach_atomic_unlock(&x->n_domain_lock);
                        } else if (lambda_hatom->h_w.w_sym == _llllobj_sym_getdomains) {
                            llll_retain(lambda_llll);
                            bach_atomic_lock(&x->n_domain_lock);
                            llll_free(x->n_rvs.r_getdomains);
                            x->n_rvs.r_getdomains = lambda_llll;
                            bach_atomic_unlock(&x->n_domain_lock);
                        } else { // any other symbol stands for "reject"
                            x->n_rvs.r_result = 0;
                            x->n_rvs.r_accepted = false;
                        }
                    } else { // if it's just null consider it as reject
                        x->n_rvs.r_result = 0;
                        x->n_rvs.r_accepted = false;
                    }
                    llll_free(lambda_llll);
                } else { // a badly formed llll is considered as reject
                    x->n_rvs.r_result = 0;
                    x->n_rvs.r_accepted = false;
                }
            } else {
                if (msg == _sym_int || msg == _sym_float || msg == _sym_list) {
                    x->n_rvs.r_result = ac ? atom_getlong(av) : 0;
                    x->n_rvs.r_accepted = true;
                } else if (msg == _llllobj_sym_setdomains) {
                    x->n_rvs.r_setdomains = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                } else if (msg == _llllobj_sym_getdomains) {
                    x->n_rvs.r_getdomains = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                } else {
                    x->n_rvs.r_result = 0;
                    x->n_rvs.r_accepted = false;
                }
            }
            break;
    }
}

void constraints_output(t_constraints *x, t_llll *solutions, t_max_err err)
{
    x->n_thread = NULL;
    bach_atomic_unlock(&x->n_inuse);
    if (solutions && err == MAX_ERR_NONE) {
        llll_retain(solutions);
        llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, solutions, 0);
        x->n_ob.l_rebuild = 0;
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
    }
}

long constraints_func(t_constraints *x, t_llll *what, t_bool *accepted, long def_accept, long def_result)
{
    x->n_rvs.r_accepted = def_accept;
    x->n_rvs.r_result = def_result;
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, what);
    *accepted = x->n_rvs.r_accepted;
    return x->n_rvs.r_result;
}

void constraints_outpos(t_constraints *x, long current_var, long double tree_size_inv, long nvars, long *positions, long double *pos_weights)
{
    long i;
    long double pos_in_tree;
    if (tree_size_inv != 0) {
        if (current_var > 0) {
            pos_in_tree = 1;
            for (i = 1; i <= current_var; i++) {
                pos_in_tree += positions[i] * pos_weights[i];
            }
            pos_in_tree *= tree_size_inv;
        } else
            pos_in_tree = 1;
    } else {
        pos_in_tree = 0;
    }
    if (!x->n_thread) {
        llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, pos_in_tree);
    } else {
        x->n_normalized_position = pos_in_tree;
        qelem_set(x->n_pos_qelem);
    }
}

void constraints_outscore(t_constraints *x, long score)
{
    if (!x->n_thread)
        llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, score);
    else {
        x->n_score = score;
        qelem_set(x->n_score_qelem);
    }
}

void constraints_out_detailed_score(t_constraints *x, long score, t_constraint *constraints, t_score_and_good *score_constraintwise)
{
    t_llll *scorell = llll_get();
    //llll_appendlong(scorell, score);
    long idx;
    t_constraint *this_constraints;
    for (this_constraints = constraints + 1, idx = 1;
         this_constraints->c_name;
         this_constraints++, idx++) {
        t_llllelem *scorell_elem;
        for (scorell_elem = scorell->l_head; scorell_elem; scorell_elem = scorell_elem->l_next) {
            t_llll *subll = hatom_getllll(&scorell_elem->l_hatom);
            if (hatom_getsym(&subll->l_head->l_hatom) == this_constraints->c_name) {
                subll->l_tail->l_hatom.h_w.w_long += score_constraintwise[idx].score;
                break;
            }
        }
        if (!scorell_elem) {
            t_llll *subll = llll_get();
            llll_appendsym(subll, this_constraints->c_name);
            llll_appendlong(subll, score_constraintwise[idx].score);
            llll_appendllll(scorell, subll);
        }
    }
    
    llll_prependlong(scorell, score);
    if (!x->n_thread) {
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, scorell);
        llll_free(scorell);
    } else {
        x->n_score = score;
        qelem_set(x->n_score_qelem);
    }
}

void constraints_outprovisionals_remapped(t_constraints *x, t_hatom **provisionals, long nvars, long *o2r)
{
    long var;
    t_llll *prov_ll = llll_get();
    llll_appendsym(prov_ll, gensym("provisional"));
    for (var = 1; var <= nvars; var++) {
        t_hatom *this_provisional = provisionals[o2r[var]];
        if (this_provisional)
            llll_appendhatom_clone(prov_ll, provisionals[o2r[var]], 0, WHITENULL_llll);
        else
            llll_appendllll(prov_ll, llll_get());
    }
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, prov_ll);
    if (!x->n_thread) {
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, prov_ll);
        llll_free(prov_ll);
    } else {
        systhread_mutex_lock(x->n_provisionals_mutex);
        if (x->n_provisionals_ll)
            llll_free(x->n_provisionals_ll);
        x->n_provisionals_ll = prov_ll;
        systhread_mutex_unlock(x->n_provisionals_mutex);
        qelem_set(x->n_provisionals_qelem);
    }
}

void constraints_outprovisionals(t_constraints *x, t_hatom **provisionals)
{
    t_hatom **this_provisionals;
    t_llll *prov_ll = llll_get();
    llll_appendsym(prov_ll, gensym("provisional"));
    for (this_provisionals = provisionals + 1; *this_provisionals; this_provisionals++)
        llll_appendhatom_clone(prov_ll, *this_provisionals, 0, WHITENULL_llll);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, prov_ll);
    if (!x->n_thread) {
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, prov_ll);
        llll_free(prov_ll);
    } else {
        systhread_mutex_lock(x->n_provisionals_mutex);
        if (x->n_provisionals_ll)
            llll_free(x->n_provisionals_ll);
        x->n_provisionals_ll = prov_ll;
        systhread_mutex_unlock(x->n_provisionals_mutex);
        qelem_set(x->n_provisionals_qelem);
    }
}

void constraints_outprovisionals_scored(t_constraints *x, t_scored_hatom **provisionals)
{
    t_scored_hatom **this_provisionals;
    t_llll *prov_ll = llll_get();
    llll_appendsym(prov_ll, gensym("provisional"));
    for (this_provisionals = provisionals + 1; *this_provisionals; this_provisionals++)
        llll_appendhatom_clone(prov_ll, (*this_provisionals)->s_hatom, 0, WHITENULL_llll);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, prov_ll);
    if (!x->n_thread) {
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, prov_ll);
        llll_free(prov_ll);
    } else {
        systhread_mutex_lock(x->n_provisionals_mutex);
        if (x->n_provisionals_ll)
            llll_free(x->n_provisionals_ll);
        x->n_provisionals_ll = prov_ll;
        systhread_mutex_unlock(x->n_provisionals_mutex);
        qelem_set(x->n_provisionals_qelem);
    }
}

void constraints_provisionals_qelem_do(t_constraints *x)
{
    t_llll *out_ll;
    systhread_mutex_lock(x->n_provisionals_mutex);
    out_ll = x->n_provisionals_ll;
    x->n_provisionals_ll = NULL;
    systhread_mutex_unlock(x->n_provisionals_mutex);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out_ll);
    llll_free(out_ll);
}

void constraints_detailed_score_qelem_do(t_constraints *x)
{
    t_llll *out_ll;
    systhread_mutex_lock(x->n_detailed_score_mutex);
    out_ll = x->n_detailed_score_ll;
    x->n_detailed_score_ll = NULL;
    systhread_mutex_unlock(x->n_detailed_score_mutex);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, out_ll);
    llll_free(out_ll);
}

void constraints_pos_qelem_do(t_constraints *x)
{
    llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, x->n_normalized_position);
}

void constraints_score_qelem_do(t_constraints *x)
{
    llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, x->n_score);
}

void constraints_assist(t_constraints *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        switch (a) {
            case 0:    sprintf(s, "llll: Domains");        break; // @in 0 @type llll @digest Domains
            case 1: sprintf(s, "llll: Associations");    break; // @in 1 @type llll @digest Associations
            case 2: sprintf(s, "Lambda Inlet");            break; // @in 2 @type int/llll @digest Lambda inlet: validity or score
                                                                  // @description @copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
                                                                  // If the strong solver is active, the expected value is 0 (or <m>reject</m>) or 1 (or no return value),
                                                                  // meaning respectively that a given partial label violates one or more constraints, or is acceptable. <br />
                                                                  // If the heuristic or hungry solver is active, the expected value is any integer, to be added to the score of the solution being currently examined,
                                                                  // or the <m>reject</m> symbol, meaning that the solution is not acceptable.
                                                                  // If no return value is provided, it will be considered a score of 1 by strong solver,
                                                                  // a score of 0 by the heuristic and hungry solver. <br />
                                                                  // If the strong or hungry solver is active and the <m>provisionals</m> attribute is on,
                                                                  // the <m>getdomains</m> and <m>setdomains</m> message can be sent to the lambda inlet
                                                                  // in response to the <m>provisional</m> message from the lambda outlet,
                                                                  // and the <m>setdomains</m> message can be sent in response to the <m>domains</m> message.
                                                                  // @copy BACH_DOC_LAMBDA_GENERAL_WARNING
        }
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        switch (a) {
            case 0:    sprintf(s, "llll (%s): Solutions", type);            break; // @out 0 @type llll @digest Found solutions
                                                                                   // @description Solutions are output as an llll whose sublists contain one solution each.
            case 1:    sprintf(s, "float/int: Advancement");    break; // @out 1 @type int/float @digest Search advancement
                                                                       // @description With the deterministic search engine, the middle outlet returns the current search position in the problem tree, expressed in percentage.
                                                                       // With the heuristic and hungry search engines, it returns the current achieved score. In both cases, the value is updated "live" during the search.
            case 2:    sprintf(s, "llll (%s): Lambda Outlet", type);    break; // @out 2 @type llll @digest Lambda outlet
                                                                               // @description @copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
                                                                               // In this case, assignments of values to one or more variables of the problem are output from the lambda outlet,
                                                                               // each preceded by the name of the relative constraint
                                                                               // according to the constraint definitions received in the second inlet. <br />
                                                                               // Immediately before any proposed assignment, the special keyword <m>vars</m> can be output if requested,
                                                                               // followed by the indices of the variables associated to the next proposed assignment. <br />
                                                                               // After the evaluation value for an assignment has been returned,
                                                                               // the <m>provisional</m> message can be output, followed by a partial solution.
                                                                               // After that, if requested through the <m>getdomains</m> message,
                                                                               // the <m>domains</m> message can be output, followed by the current values taken by one or more domains. <br />
                                                                               // For more details, please refer to the description of the <m>llll</m> method. <br />
                                                                               // @copy BACH_DOC_LAMBDA_GENERAL_WARNING
        }
    }
}

void constraints_inletinfo(t_constraints *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void constraints_free(t_constraints *x)
{
    long i;
    if (x->n_thread) {
        unsigned int rv;
        x->n_stop = 1;
        systhread_join(x->n_thread, &rv);
        CONSTRAINTS_dev_post("thread exited with return value %u");
    }
    for (i = 2; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    systhread_mutex_free_debug(x->n_provisionals_mutex);
    
    qelem_free_debug(x->n_pos_qelem);
    qelem_free_debug(x->n_score_qelem);
    qelem_free_debug(x->n_provisionals_qelem);
    
    llll_free(x->n_rvs.r_setdomains);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_constraints *constraints_new(t_symbol *s, short ac, t_atom *av)
{
    t_constraints *x = NULL;
    long i;
    t_max_err err = 0;
    
    if ((x = (t_constraints *) object_alloc_debug(constraints_class))) {
        x->n_nsolutions = 1;
        x->n_nc = 1;
        x->n_ac = 1;
        x->n_sortdomains = 1;
        x->n_sortconstraints = 1;
        x->n_maxtime = 60000;
        atom_setsym(&x->n_minscore, gensym("<none>"));
        atom_setsym(&x->n_maxscore, gensym("<none>"));
        atom_setsym(&x->n_goalscore, gensym("<none>"));
        attr_args_process(x, ac, av);
        x->n_pos_qelem = qelem_new_debug(x, (method) constraints_pos_qelem_do);
        x->n_score_qelem = qelem_new_debug(x, (method) constraints_score_qelem_do);
        x->n_detailed_score_qelem = qelem_new_debug(x, (method) constraints_detailed_score_qelem_do);
        x->n_provisionals_qelem = qelem_new_debug(x, (method) constraints_provisionals_qelem_do);
        
        systhread_mutex_new_debug(&x->n_provisionals_mutex, 0);
        llllobj_obj_setup((t_llllobj_object *) x, 2, "444");
        for (i = 2; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}


// domains are in the form (el1 el2 ...) (el1 el2 ...) ...
// constraints are in the form (constraint1_id (var1 var2 ...)) (constraint2_id (var1 var2 ...))
//
// we achieve node consistency by separatedly testing all the unary constraints,
// and immediately removing from the domains all the values that don't satisfy them
// after that, we don't need to evaluate the unary constraints anymore!
// domains and constraints are 1-based arrays (which means their 0-th element is ignored)
// domains has an empty terminator(we require that at least its d_size field is set to 0)
// constraints has an empty terminator (we require that at least its c_name field is set to NULL)
// *nconstraints is the actual number of valid constraints (independent of the allocated size of constraints)
e_llll_constraints_validity constraints_node_consistency(t_constraints *x, t_domain *domains, long *nconstraints, t_constraint *constraints)
{
    t_constraint *this_constraints;
    long stripped_constraints = 0; // that is, how many unary constraints we have found
    for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++) {
        if (this_constraints->c_nvars == 1 && this_constraints->c_required) { // if it's a unary constraint and can be optimized
            long var = this_constraints->c_vars[1]; // it has one only variable
            t_domain *this_domains = domains + var; // this is the variable's domain
            t_domainvalues *values = this_domains->d_currentvalues;
            t_hatom *this_hatom;
            //long tot_vals = values->d_size; // total number of values in the variable's domain
            long stripped_vals = 0; // how many did we strip away, because they didn't satisfy this unary constraint?
            t_symbol *name_sym = this_constraints->c_name;
            for (this_hatom = values->d_hatoms + 1; this_hatom->h_type != H_NOTHING; this_hatom++) { // for every value in this domain
                t_llll *test_llll = llll_get();
                t_bool dummy_accepted;
                llll_appendsym(test_llll, name_sym, 0, WHITENULL_llll); // let's start building an llll to send out for test - its first element is the name of our unary constraint
                llll_appendhatom_clone(test_llll, this_hatom, 0, WHITENULL_llll); // append it to the test llll
                if (this_constraints->c_outputvars) { // should we output the variable index?
                    t_llll *vars_llll = llll_get();    // then let's prepare a llll with the variable
                    llll_appendlong(vars_llll, var, 0, WHITENULL_llll); // let's put in vars_llll the variable intex
                    llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
                    //                    (testfn)(data, vars_llll);
                    constraints_func(x, vars_llll, &dummy_accepted);
                    llll_free(vars_llll);
                }
                //                if (!((testfn)(data, test_llll))) { // if the constraint is not satisfied
                if (!(constraints_func(x, test_llll, &dummy_accepted, 1))) { // if the constraint is not satisfied
                    this_hatom->h_type = H_NULL; // we shall erase this value later
                    stripped_vals++;
                }
                llll_free(test_llll); // we don't need the hatom we tested anymore in the test llll
            }
            
            //if (stripped_vals == tot_vals)
            //    return V_GOOD;
            
            if (stripped_vals != 0) { // if at least one value has been removed, it's time to make some cleanup!
                if (stripped_vals != values->d_size) {
                    
                    t_hatom *write, *read;
                    write = read = values->d_hatoms + 1;
                    while (read->h_type != H_NOTHING) { // *read will always point to something non-NULL, unless it's the array terminator
                        if (write->h_type == H_NULL) { // if *write must be erased
                            while (read->h_type == H_NULL) // if there is a WHITENULL to write into, there must be a non-WHITENULL to read from: let's find it!
                                read++;
                            *write = *read;
                            if (read->h_type == H_NOTHING)
                                break;
                            read->h_type = H_NULL; // now *read must be erased!
                        }
                        read++;
                        write++;
                    }
                    write->h_type = H_NOTHING; // let's set the array terminator to the element following the last valid element of the array
                    values->d_size -= stripped_vals;
                } else {
                    values->d_hatoms[1].h_type = H_NOTHING;
                    values->d_size = 0;
                }
            }
            stripped_constraints++;
        }
    }
    
    if (stripped_constraints != 0) { // cleanup, like before. we get rid of unary constraints, using the c_name field as a terminator
        t_constraint *read, *write;
        write = read = constraints + 1;
        while (read->c_name) {
            if (write->c_nvars == 1) {
                while (read->c_nvars == 1) {
                    bach_freeptr(read->c_vars);
                    read++;
                }
                *write = *read;
                if (!read->c_name)
                    break;
                read->c_nvars = 1;
            }
            read++;
            write++;
        }
        write->c_name = NULL;
        *nconstraints -= stripped_constraints;
    }
    return V_GOOD;
}

t_max_err constraints_backtrack_wrapped(t_constraints *x, t_llll *data, t_llll *res)
{
    t_llll *domains_ll = (t_llll *) hatom_getobj(&data->l_head->l_hatom);
    t_llll *constraints_ll = (t_llll *) hatom_getobj(&data->l_head->l_next->l_hatom);
    t_llll *more_ll = (t_llll *) hatom_getobj(&data->l_tail->l_hatom);
    t_llll *sln = constraints_simple_backtrack(x, domains_ll, constraints_ll, more_ll);
    llll_release(domains_ll);
    llll_release(constraints_ll);
    llll_release(more_ll);
    if (sln) {
        llll_clone_upon(sln, res);
        llll_free(sln);
        return MAX_ERR_NONE;
    } else
        return MAX_ERR_GENERIC;
}

t_max_err constraints_weak_wrapped(t_constraints *x, t_llll *data, t_llll *res)
{
    t_llll *domains_ll = (t_llll *) hatom_getobj(&data->l_head->l_hatom);
    t_llll *constraints_ll = (t_llll *) hatom_getobj(&data->l_head->l_next->l_hatom);
    t_llll *sln = constraints_weak(x, domains_ll, constraints_ll);
    llll_release(domains_ll);
    llll_release(constraints_ll);
    if (sln) {
        llll_clone_upon(sln, res);
        llll_free(sln);
        return MAX_ERR_NONE;
    } else
        return MAX_ERR_GENERIC;
}

t_max_err constraints_hungry_wrapped(t_constraints *x, t_llll *data, t_llll *res)
{
    t_llll *domains_ll = (t_llll *) hatom_getobj(&data->l_head->l_hatom);
    t_llll *constraints_ll = (t_llll *) hatom_getobj(&data->l_head->l_next->l_hatom);
    t_llll *sln = constraints_hungry(x, domains_ll, constraints_ll);
    llll_release(domains_ll);
    llll_release(constraints_ll);
    if (sln) {
        llll_clone_upon(sln, res);
        llll_free(sln);
        return MAX_ERR_NONE;
    } else
        return MAX_ERR_GENERIC;
}

/*
 STRUCTURE OF THE TREE llll:
 
 <nvars> <nconstraints>
 
 (
 (<domain[1].d_size> <.d_var>
 (<.d_hatom[1]> .<d_hatom[2]> …)
 )
 (<domain[2]…>
 (…)
 )
 )
 
 (
 (
 (<constraints_varwise[1][1].c_name> <.c_nvars> <.c_maxvar> <.c_outputvars> <.c_low>
 (<.c_vars[1]> <.c_vars[2]> …)
 )
 (<constraints_varwise[1][2]…>
 (…)
 )
 )
 (<constraints_varwise[2][1]…>
 (…)
 )
 )
 
 (<var_remap_o2r[1]> <var_remap_o2r[2]> …)
 
 (<var_remap_r2o[1]> …)
 
 (<positions[1]> …)
 */




// --- NON DESTRUCTIVE
t_llll *constraints_simple_backtrack(t_constraints *x, const t_llll *domains_ll, const t_llll *constraints_ll, const t_llll *more_ll)
{
    t_constraint ***constraints_varwise = NULL, *constraints = NULL, *this_constraints;
    long *positions = NULL;
    long double *domain_positional_multipliers = NULL, tree_size, tree_size_inv = 0;
    long nvars;
    long nconstraints;
    long var, this_var = 0;
    t_hatom **current = NULL, **this_current; // contains the current values;
    long *var_remap_o2r, *var_remap_r2o; // o = original, r = reordered
    long good, found = 0;
    t_llll *test_llll, *sln_llll;
    t_llll *vars_llll;
    t_llll *garbage = NULL;
    t_hatom *under_exam; // points to a t_hatom* in the domain of the currently investigated variable
    t_domain *domains = NULL, *this_domains;
    unsigned long stms, maxtime, next_pos_output_time;
    long nresults = x->n_nsolutions;
    t_bool provisionals = x->n_provisionals;
    t_bool sortdomains = x->n_sortdomains && !provisionals;
    
    stms = systime_ms();
    maxtime = x->n_maxtime > 0 ? stms + x->n_maxtime : 0;
    next_pos_output_time = stms + POS_OUTPUT_INTERVAL;
    
#ifdef CONSTRAINTS_SIMPLE_BACKTRACK_ENABLE_MORE
    if (more_ll) {
        t_llllelem *more_ll_elem = more_ll->l_head;
        nvars = hatom_getlong(&(more_ll_elem = more_ll_elem->l_next)->l_hatom); // first is "more"
        nconstraints = hatom_getlong(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        domains = (t_domain *) bach_newptrclear((nvars + 2) * sizeof(t_domain));
        
        t_llll *more_domains_ll = hatom_getllll(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        t_llllelem *more_domains_elem;
        this_domains = domains + 1;
        for (more_domains_elem = more_domains_ll->l_head;
             more_domains_elem;
             more_domains_elem = more_domains_elem->l_next, this_domains++) {
            t_llllelem *this_domain_elem;
            long domain_size = this_domains->d_size = hatom_getlong(&(this_domain_elem = hatom_getllll(&more_domains_elem->l_hatom)->l_head)->l_hatom);
            this_domains->d_var = hatom_getlong(&(this_domain_elem = this_domain_elem->l_next)->l_hatom);
            this_domains->d_hatoms = (t_hatom *) bach_newptrclear((domain_size + 2) * sizeof(t_hatom));
            t_llll *hatoms_ll = hatom_getllll(&(this_domain_elem = this_domain_elem->l_next)->l_hatom);
            t_llllelem *hatoms_elem;
            t_hatom *this_hatoms;
            for (hatoms_elem = hatoms_ll->l_head, this_hatoms = this_domains->d_hatoms + 1; hatoms_elem; hatoms_elem = hatoms_elem->l_next, this_hatoms++) {
                *this_hatoms = hatoms_elem->l_hatom;
            }
        }
        
        constraints_varwise = (t_constraint ***) bach_newptrclear((nvars + 2) * sizeof(t_constraint **));
        constraints = (t_constraint *) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint));
        
        t_llll *more_constraints_varwise_ll = hatom_getllll(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        t_llllelem *more_constraints_varwise_elem;
        t_constraint *this_constraint = constraints + 1;
        
        for (more_constraints_varwise_elem = more_constraints_varwise_ll->l_head, this_constraints_varwise = constraints_varwise + 1;
             more_constraints_varwise_elem;
             more_constraints_varwise_elem = more_constraints_varwise_elem->l_next, this_constraints_varwise++) {
            
            t_llll *this_constraints_varwise_ll = hatom_getllll(&more_constraints_varwise_elem->l_hatom);
            t_llllelem *this_constraints_varwise_elem;
            t_constraint **this_this_constraints_varwise;
            *this_constraints_varwise = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint **));
            
            for (this_constraints_varwise_elem = this_constraints_varwise_ll->l_head, this_this_constraints_varwise = *this_constraints_varwise + 1;
                 this_constraints_varwise_elem;
                 this_constraints_varwise_elem = this_constraints_varwise_elem->l_next, this_this_constraints_varwise++) {
                
                t_llll *this_constraint_ll = hatom_getllll(&this_constraints_varwise_elem->l_hatom);
                t_llllelem *this_constraint_elem;
                this_constraint->c_name = &(this_constraint_elem = this_constraint_ll->l_head)->l_hatom;
                this_constraint->c_nvars = hatom_getlong(&(this_constraint_elem = this_constraint_elem->l_next)->l_hatom);
                this_constraint->c_maxvar = hatom_getlong(&(this_constraint_elem = this_constraint_elem->l_next)->l_hatom);
                this_constraint->c_outputvars = hatom_getlong(&(this_constraint_elem = this_constraint_elem->l_next)->l_hatom);
                this_constraint->c_low = hatom_getlong(&(this_constraint_elem = this_constraint_elem->l_next)->l_hatom);
                this_constraint->c_vars = (long *) bach_newptrclear((this_constraint->c_nvars + 2) * sizeof(long));
                
                t_llll *constraint_vars_ll = hatom_getllll(&(this_constraint_elem = this_constraint_elem->l_next)->l_hatom);
                t_llllelem *constraint_vars_elem;
                long *this_vars;
                
                for (constraint_vars_elem = constraint_vars_ll->l_head, this_vars = this_constraint->c_vars + 1;
                     constraint_vars_elem;
                     constraint_vars_elem = constraint_vars_elem->l_next, this_vars++) {
                    *this_vars = hatom_getlong(&constraint_vars_elem->l_hatom);
                }
                
                *this_this_constraints_varwise = this_constraint;
                this_constraint++;
            }
        }
        
        var_remap_r2o = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
        var_remap_o2r = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
        positions = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
        
        long *this_var_remap_r2o, *this_var_remap_o2r;
        
        t_llll *more_r2o_ll = hatom_getllll(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        t_llll *more_o2r_ll = hatom_getllll(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        t_llll *more_positions_ll = hatom_getllll(&(more_ll_elem = more_ll_elem->l_next)->l_hatom);
        
        t_llllelem *more_r2o_elem, *more_o2r_elem, *more_positions_elem;
        
        this_current = current = (t_hatom **) bach_newptrclear((nvars + 2) * sizeof(t_hatom *));
        
        for (more_r2o_elem = more_r2o_ll->l_head, more_o2r_elem = more_o2r_ll->l_head, more_positions_elem = more_positions_ll->l_head,
             this_var_remap_r2o = var_remap_r2o + 1, this_var_remap_o2r = var_remap_o2r + 1, this_positions = positions + 1,
             this_domains = domains + 1;
             more_r2o_elem;
             more_r2o_elem = more_r2o_elem->l_next, more_o2r_elem = more_o2r_elem->l_next, more_positions_elem = more_positions_elem->l_next,
             this_var_remap_r2o++, this_var_remap_o2r++, this_positions++,
             this_domains++) {
            
            *this_var_remap_o2r = hatom_getlong(&more_o2r_elem->l_hatom);
            *this_var_remap_r2o = hatom_getlong(&more_r2o_elem->l_hatom);
            *this_positions = hatom_getlong(&more_positions_elem->l_hatom);
            *this_current++;
            *this_current = this_domains->d_hatoms + *this_positions + 1;
        }
        this_positions = positions + nvars;
        this_var = nvars + 1;
        
        constraints_move_to_next_solution(&this_current, &under_exam, &this_var, &this_positions);
        
    } else
#endif // CONSTRAINTS_SIMPLE_BACKTRACK_ENABLE_MORE
        
    {
        // first we should check the correctness of the incoming data
        switch (constraints_check_domains_allow_empty(x, domains_ll)) {
            case V_INVALID:
                return NULL;
                break;
            case V_EMPTY:
                return llll_get();
                break;
            default:
                break;
        }
        
        constraints_fill_arrays(x, domains_ll, constraints_ll, &nvars, &domains, &nconstraints, &constraints, 1, 0, x->n_random);
        if (nvars < 1 || nconstraints < 1) {
            return NULL;
        }
        
        CONSTRAINTS_dev_post("---- BEFORE NC ---- ");
        
        // here we can achieve node consistency
        // that is, we run through the constraints
        // whenever an unary constraint is met, we test all its domain, get rid of the bad elements and get rid of the constraint
        // if all the elements of the domain are discarded, the problem has no solution.
        
        post_constraints(constraints);
        post_domains(domains);
        
        if (x->n_nc) {
            if (constraints_node_consistency(x, domains, &nconstraints, constraints) != V_GOOD) {
                constraints_free_domains(domains);
                constraints_free_constraints(constraints);
                return llll_get();
            }
        }
        
        CONSTRAINTS_dev_post("---- AFTER NC ---- ");
        
        post_constraints(constraints);
        post_domains(domains);
        
        // here we can sort domains from smaller to larger
        // and keep a map of the resorted variables numbers vs original variable numbers
        
        //    CONSTRAINTS_dev_llll_print(domains, data, gensym("domains with nc"), 0, 6, NULL);
        //    CONSTRAINTS_dev_llll_print(constraints, data, gensym("constraints with nc"), 0, 6, NULL);
        
        // we waste the element 0 of the arrays, but we keep everything 1-based!
        var_remap_o2r = (long *) bach_newptrclear((nvars + 1) * sizeof(long));
        var_remap_r2o = (long *) bach_newptrclear((nvars + 1) * sizeof(long));
        
        // domains can be sorted from smaller to larger
        // this should improve efficiency
        if (sortdomains) {
            qsort(domains + 1, nvars, sizeof(t_domain), (qsort_fn) sort_domains_cb);
            
            // for every domain, build a map of how the domains are remapped - so that we can restore the old indexing when needed */
            
            for (this_domains = domains + 1, var = 1; this_domains->d_var; this_domains++, var++) {
                long original = this_domains->d_var;
                var_remap_o2r[original] = var;
                var_remap_r2o[var] = original;
            }
            
            for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++) {
                long *this_var_ptr;
                for (this_var_ptr = this_constraints->c_vars + 1; *this_var_ptr > 0; this_var_ptr++) {
                    *this_var_ptr = var_remap_o2r[*this_var_ptr];
                }
            }
            
        } else {
            // if we don't sort the domains, we build trivial maps
            for (var = 1; var <= nvars; var++) {
                var_remap_o2r[var] = var; // original to resorted
                var_remap_r2o[var] = var; // resorted to original
            }
        }
        
        if (domains[1].d_currentvalues->d_size == 0) {
            sln_llll = llll_get();
            goto constraints_simple_backtrack_exit;
        }
        
        // here we can sort the constraints from looser to tighter
        
        if (x->n_sortconstraints)
            qsort(constraints + 1, nconstraints, sizeof(t_constraint), (qsort_fn) sort_constraints_cb);
        
        // here we could achieve arc consistency or whatever
        
        constraints_assign_maxvar(constraints);
        constraints_varwise = constraints_varwise_init(x, constraints, nconstraints, nvars);
        
        // now, every i-th item of constraints_varwise contains a llll containing all the constraints concerning the i-th variable
        
        positions = (long *) bach_newptrclear((nvars + 1) * sizeof(long));
        
        // we can start to backtrack now!
        current = (t_hatom **) bach_newptrclear((nvars + 2) * sizeof(t_hatom *));
        this_current = current;
        under_exam = domains[1].d_currentvalues->d_hatoms;
        *this_current = under_exam;
        this_var = 1;
        positions[1] = 1;
        current[1] = domains[1].d_currentvalues->d_hatoms + 1;
    }
    
    sln_llll = llll_get();
    garbage = llll_get();
    
    domain_positional_multipliers = (long double *) bach_newptrclear((nvars + 1) * sizeof(long double));
    
    constraints_calculate_tree_size(nvars, domains, domain_positional_multipliers, &tree_size, &tree_size_inv);
    
    // this cycle runs once for each solution to find
    while (this_var != 0 && this_var <= nvars) {
        // this cycle runs once for every variable to assign
        while (1) {
            t_constraint ***this_constraints_varwise = constraints_varwise + this_var;
            t_constraint **this_this_constraints_varwise;
            good = true;
            
            // let's run through the constraints associated to this variable (could be none of course!)
            for (this_this_constraints_varwise = *this_constraints_varwise + 1; good && *this_this_constraints_varwise; this_this_constraints_varwise++) {
                t_constraint *this_constraint = *this_this_constraints_varwise;
                long *this_constraint_var;
                t_bool dummy_accepted;
                
                // let's prepare the llll to send out
                test_llll = llll_get();
                llll_appendsym(test_llll, this_constraint->c_name, 0, WHITENULL_llll);
                // if we have to send out the variables as well
                if (this_constraint->c_outputvars) {
                    // then let's prepare a llll with the variables
                    vars_llll = llll_get();
                    // let's run through the variables associated to this constraint
                    for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                        // let's put in vars_llll this variable index
                        llll_appendlong(vars_llll, var_remap_r2o[*this_constraint_var], 0, WHITENULL_llll);
                        // let's copy in test_llll the hatom provisionally assigned to this variable
                        llll_appendhatom_clone(test_llll, current[*this_constraint_var], 0, WHITENULL_llll);
                    }
                    // let's send out the variables
                    llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
                    constraints_func(x, vars_llll, &dummy_accepted);
                    llll_free(vars_llll);
                } else {
                    for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                        llll_appendhatom_clone(test_llll, current[*this_constraint_var], 0, WHITENULL_llll);
                    }
                }
                good = (constraints_func(x, test_llll, &dummy_accepted, 1, 1) != 0);
                llll_free(test_llll);
            }
            
            stms = systime_ms();
            
            if (stms >= next_pos_output_time) {
                next_pos_output_time += POS_OUTPUT_INTERVAL;
                constraints_outpos(x, this_var, tree_size_inv, nvars, positions, domain_positional_multipliers);
            }
            
            if (good) {    // if it's good so far
                if (provisionals) {
                    t_llll *getdomains = NULL;
                    t_llll *setdomains = NULL;
                    bach_atomic_lock(&x->n_domain_lock);
                    llll_free(x->n_rvs.r_getdomains);
                    llll_free(x->n_rvs.r_setdomains);
                    x->n_rvs.r_getdomains = NULL;
                    x->n_rvs.r_setdomains = NULL;
                    bach_atomic_unlock(&x->n_domain_lock);
                    /*     if (x->n_sortdomains)
                     constraints_outprovisionals_remapped(x, current, nvars, var_remap_o2r);
                     else */
                    constraints_outprovisionals(x, current);
                    
                    bach_atomic_lock(&x->n_domain_lock);
                    if (x->n_rvs.r_getdomains) {
                        getdomains = llll_clone(x->n_rvs.r_getdomains);
                    }
                    bach_atomic_unlock(&x->n_domain_lock);
                    
                    if (getdomains) {
                        constraints_getdomains_remapped(x, getdomains, domains, nvars, var_remap_o2r);
                        llll_free(getdomains);
                    }
                    
                    bach_atomic_lock(&x->n_domain_lock);
                    if (x->n_rvs.r_setdomains) {
                        setdomains = llll_clone(x->n_rvs.r_setdomains);
                    }
                    bach_atomic_unlock(&x->n_domain_lock);
                    if (setdomains) {
                        t_llllelem *elem;
                        for (elem = setdomains->l_head->l_next; elem; elem = elem->l_next) {
                            t_llll *one_setdomains = hatom_getllll(&elem->l_hatom);
                            if (one_setdomains) {
                                t_llllelem *one_setdomains_elem = one_setdomains->l_head;
                                long type = hatom_gettype(&one_setdomains_elem->l_hatom);
                                long domain_idx = 1;
                                if (type == H_LONG || type == H_RAT || type == H_DOUBLE) { // do we have a starting value first?
                                    domain_idx = hatom_getlong(&one_setdomains_elem->l_hatom);
                                    one_setdomains_elem = one_setdomains_elem->l_next;
                                }
                                if (domain_idx <= 0)
                                    domain_idx = 1;
                                for ( ; one_setdomains_elem; one_setdomains_elem = one_setdomains_elem->l_next, domain_idx++) {
                                    if (domain_idx <= nvars) {
                                        long domain_remapped_idx = var_remap_o2r[domain_idx];
                                        t_llll *domain_ll = hatom_getllll(&one_setdomains_elem->l_hatom);
                                        if (domain_ll && !current[domain_remapped_idx]) {
                                            if (tree_size != 0) {
                                                tree_size /= domains[domain_remapped_idx].d_currentvalues->d_size;
                                                constraints_fill_domain(domain_ll, domains + domain_remapped_idx, this_var, false, x->n_random);
                                                tree_size *= domains[domain_remapped_idx].d_currentvalues->d_size;
                                                if (tree_size != 0) {
                                                    long var;
                                                    for (var = domain_remapped_idx - 1; var > 0; var--) {
                                                        domain_positional_multipliers[var] = domain_positional_multipliers[var + 1] * domains[var + 1].d_currentvalues->d_size;
                                                    }
                                                    tree_size_inv = 1. / tree_size;
                                                } else {
                                                    for (var = domain_remapped_idx - 1; var > 0; var--) {
                                                        domain_positional_multipliers[var] = 0;
                                                    }
                                                    tree_size_inv = 0;
                                                }
                                            } else {
                                                constraints_fill_domain(domain_ll, domains + domain_remapped_idx, this_var, false, x->n_random);
                                                constraints_calculate_tree_size(nvars, domains, domain_positional_multipliers, &tree_size, &tree_size_inv);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        llll_appendobj(garbage, setdomains);
                    }
                }
                this_var++; // pick a value for the next variable
            } else { // if the result was not good
                while (this_var > 0 && (domains[this_var].d_currentvalues->d_hatoms + positions[this_var] + 1)->h_type == H_NOTHING) { // if there are no more values at this level, backtrack!
                    current[this_var] = NULL;
                    positions[this_var] = 0;
                    this_var--;
                }
                if (this_var > 0) {
                    t_domain *scanned_domain;
                    t_bool downgraded = false;
                    for (scanned_domain = domains + 1; scanned_domain->d_var; scanned_domain++) {
                        while (scanned_domain->d_currentvalues->d_step >= this_var) {
                            CONSTRAINTS_dev_post("- restoring domain %ld", scanned_domain->d_var);
                            scanned_domain->d_currentvalues--;
                            scanned_domain->d_currentll--;
                            downgraded = true;
                        }
                        
                    }
                    if (downgraded) {
                        constraints_calculate_tree_size(nvars, domains, domain_positional_multipliers, &tree_size, &tree_size_inv);
                    }
                }
            }
            if (x->n_stop || (maxtime && stms > maxtime))
                goto constraints_simple_backtrack_exit;
            if (this_var > 0 && this_var <= nvars) {
                // this must be checked for the case in which noteconsistency is on, and the domain of the next variable has been set to empty.
                // if that domain is only constrained by unary constraints, then its validity won't be assessed in the main evaluation loop
                // so we have to detect it here and stop the computation
                if (domains[this_var].d_currentvalues->d_size == 0) {
                    this_var = 0;
                    break;
                }
                positions[this_var]++;
                current[this_var] = domains[this_var].d_currentvalues->d_hatoms + positions[this_var];
            } else
                break;
        }
        
        if (this_var > nvars) { // if all the labels have been committed
            t_llll *this_sln = llll_get();
            for (var = 1; var <= nvars; var++) {
                llll_appendhatom_clone(this_sln, current[var_remap_o2r[var]], 0, WHITENULL_llll);
            }
            llll_appendllll(sln_llll, this_sln, 0, WHITENULL_llll);
            found++;
            if (nresults < 1 || found < nresults) { // if there is more to see, see it!
                                                    //constraints_move_to_next_solution(&this_current, &under_exam, &this_var, &this_positions);
                this_var = nvars;
                while (this_var > 0 && (domains[this_var].d_currentvalues->d_hatoms + positions[this_var] + 1)->h_type == H_NOTHING) { // if there are no more variables at this level, backtrack!
                    current[this_var] = NULL;
                    positions[this_var] = 0;
                    this_var--;
                }
                if (this_var > 0) {
                    t_domain *scanned_domain;
                    t_bool downgraded = false;
                    for (scanned_domain = domains + 1; scanned_domain->d_var; scanned_domain++) {
                        while (scanned_domain->d_currentvalues->d_step > this_var) {
                            CONSTRAINTS_dev_post("- restoring domain %ld", scanned_domain->d_var);
                            scanned_domain->d_currentvalues--;
                            scanned_domain->d_currentll--;
                            downgraded = true;
                        }
                    }
                    if (downgraded) {
                        constraints_calculate_tree_size(nvars, domains, domain_positional_multipliers, &tree_size, &tree_size_inv);
                    }
                    positions[this_var]++;
                    current[this_var] = domains[this_var].d_currentvalues->d_hatoms + positions[this_var];
                }
                
            }
#ifdef CONSTRAINTS_SIMPLE_BACKTRACK_ENABLE_MORE
            else if (x->n_more) {
                t_llll *more_out = llll_get();
                llll_appendsym(more_out, gensym("tree"), 0, WHITENULL_llll);
                llll_appendsym(more_out, gensym("more"), 0, WHITENULL_llll);
                llll_appendlong(more_out, nvars, 0, WHITENULL_llll);
                llll_appendlong(more_out, nconstraints, 0, WHITENULL_llll);
                
                t_llll *domains_more = llll_get();
                t_domain *this_domains;
                for (this_domains = domains + 1; this_domains->d_size; this_domains++) {
                    t_llll *this_domains_more = llll_get();
                    llll_appendlong(this_domains_more, this_domains->d_size, 0, WHITENULL_llll);
                    llll_appendlong(this_domains_more, this_domains->d_var, 0, WHITENULL_llll);
                    t_llll *hatoms_more = llll_get();
                    t_hatom *this_hatoms;
                    for (this_hatoms = this_domains->d_hatoms + 1; this_hatoms->h_type == H_NOTHING; this_hatoms++) {
                        llll_appendhatom_clone(hatoms_more, this_hatoms, 0, WHITENULL_llll);
                    }
                    llll_appendllll(this_domains_more, hatoms_more, 0, WHITENULL_llll);
                    llll_appendllll(domains_more, this_domains_more, 0, WHITENULL_llll);
                }
                llll_appendllll(more_out, domains_more, 0, WHITENULL_llll);
                
                t_llll *constraints_varwise_more = llll_get();
                t_constraint ***this_constraints_varwise;
                for (this_constraints_varwise = constraints_varwise + 1; *this_constraints_varwise; this_constraints_varwise++) {
                    t_llll *this_constraints_varwise_more = llll_get();
                    t_constraint **this_this_constraints_varwise;
                    for (this_this_constraints_varwise = *this_constraints_varwise + 1; *this_this_constraints_varwise; this_this_constraints_varwise++) {
                        t_llll *constraint_more = llll_get();
                        t_constraint *this_constraint = *this_this_constraints_varwise;
                        llll_appendhatom_clone(constraint_more, this_constraint->c_name, 0, WHITENULL_llll);
                        llll_appendlong(constraint_more, this_constraint->c_nvars, 0, WHITENULL_llll);
                        llll_appendlong(constraint_more, this_constraint->c_maxvar, 0, WHITENULL_llll);
                        llll_appendlong(constraint_more, this_constraint->c_outputvars, 0, WHITENULL_llll);
                        llll_appendlong(constraint_more, this_constraint->c_low, 0, WHITENULL_llll);
                        
                        t_llll *constraint_vars_more = llll_get();
                        long *this_constraint_var;
                        for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                            llll_appendlong(constraint_vars_more, *this_constraint_var, 0, WHITENULL_llll);
                        }
                        llll_appendllll(constraint_more, constraint_vars_more, 0, WHITENULL_llll);
                        llll_appendllll(this_constraints_varwise_more, constraint_more, 0, WHITENULL_llll);
                    }
                    llll_appendllll(constraints_varwise_more, this_constraints_varwise_more, 0, WHITENULL_llll);
                }
                llll_appendllll(more_out, constraints_varwise_more, 0, WHITENULL_llll);
                
                t_llll *var_remap_o2r_more = llll_get();
                t_llll *var_remap_r2o_more = llll_get();
                t_llll *positions_more = llll_get();
                for (var = 1; var <= nvars; var++) {
                    llll_appendlong(var_remap_o2r_more, var_remap_r2o[var], 0, WHITENULL_llll);
                    llll_appendlong(var_remap_r2o_more, var_remap_o2r[var], 0, WHITENULL_llll);
                    llll_appendlong(positions_more, positions[var], 0, WHITENULL_llll);
                }
                llll_appendllll(more_out, var_remap_o2r_more, 0, WHITENULL_llll);
                llll_appendllll(more_out, var_remap_r2o_more, 0, WHITENULL_llll);
                llll_appendllll(more_out, positions_more, 0, WHITENULL_llll);
                
                t_atom more_out_atom;
                atom_setobj(&more_out_atom, more_out);
                
                if (x->n_thread) {
                    defer((t_object *) x, (method) constraints_output_tree, NULL, 1, &more_out_atom); // more_out will be destroyed in here
                } else {
                    constraints_output_tree(x, NULL, 1, &more_out_atom);
                }
            }
            
#endif // CONSTRAINTS_SIMPLE_BACKTRACK_ENABLE_MORE
        }
    }
    
constraints_simple_backtrack_exit:
    if (this_var > nvars)
        this_var = nvars;
    if (positions) {
        constraints_outpos(x, this_var, tree_size_inv, nvars, positions, domain_positional_multipliers);
        bach_freeptr(positions);
    }
    
    constraints_free_constraints_varwise(constraints_varwise);
    constraints_free_domains(domains);
    constraints_free_constraints(constraints);
    constraints_free_garbage(garbage);
    
    bach_freeptr(current);
    bach_freeptr(var_remap_o2r);
    bach_freeptr(var_remap_r2o);
    bach_freeptr(domain_positional_multipliers);
    return sln_llll;
}


// --- NON DESTRUCTIVE
t_llll *constraints_weak(t_constraints *x, t_llll *domains_ll, t_llll *constraints_ll)
{
    t_constraint ***constraints_varwise, ***this_constraints_varwise;
    t_constraint *constraints, *this_constraints;
    long nvars;
    long nconstraints;
    long var, this_var;
    long found = 0;
    t_domain *domains, *this_domains;
    unsigned long stms, maxtime, next_pos_output_time;
    long **unconcerned_constraints_idxs = NULL, **this_unconcerned_constraints_idxs;
    long *starting_point_for_backtracking = NULL;
    long *var_array = NULL;
    long **domain_steps_array = NULL, **this_domain_steps_array, *domain_steps_pos;
    long winner_var = 0;
    long best_point_winner_var = 0;
    long greedy = x->n_greedy;
    long picky = x->n_picky;
    long scoredetails = x->n_scoredetails;
    long maxsteps = x->n_maxsteps;
    long maxscore, minscore, goalscore;
    t_bool has_maxscore, has_minscore, has_goalscore;
    long provisionals = x->n_provisionals;
    t_uint64 problem_size;
    
    if (atom_gettype(&x->n_minscore) == A_SYM) {
        has_minscore = false;
        minscore = 0;
    } else {
        has_minscore = true;
        minscore = atom_getlong(&x->n_minscore);
    }
    
    if (atom_gettype(&x->n_maxscore) == A_SYM) {
        has_maxscore = false;
        maxscore = 0;
    } else {
        has_maxscore = true;
        maxscore = atom_getlong(&x->n_maxscore);
    }
    
    if (atom_gettype(&x->n_goalscore) == A_SYM) {
        has_goalscore = false;
        goalscore = 0;
    } else {
        has_goalscore = true;
        goalscore = atom_getlong(&x->n_goalscore);
    }
    
    stms = systime_ms();
    maxtime = x->n_maxtime > 0 ? stms + x->n_maxtime : 0;
    next_pos_output_time = stms + POS_OUTPUT_INTERVAL;
    
    // first we should check for the correctness of the incoming data
    switch (constraints_check_domains(domains_ll)) {
        case V_INVALID:
            return NULL;
            break;
        case V_EMPTY:
            return llll_get();
            break;
        default:
            break;
    }
    
    constraints_fill_arrays(x, domains_ll, constraints_ll, &nvars, &domains, &nconstraints, &constraints);
    
    if (nvars < 1 || nconstraints < 1)
        return NULL;
    
    // compute the size of the problem
    problem_size = 1;
    for (this_domains = domains + 1; this_domains->d_var && problem_size <= CONSTRAINTS_POINTMAP_SLOTS; this_domains++)
        problem_size *= this_domains->d_currentvalues->d_size;
    
    CONSTRAINTS_dev_post("problem size = %llu", problem_size);
    
    
    // here we can sort the constraints from looser to tighter
    
    if (x->n_sortconstraints)
        qsort(constraints + 1, nconstraints, sizeof(t_constraint), (qsort_fn) sort_constraints_cb);
    
    // here we could achieve arc consistency or whatever
    
    constraints_assign_maxvar(constraints);
    constraints_varwise = constraints_varwise_init(x, constraints, nconstraints, nvars);
    
    // here we can achieve node consistency
    // that is, we run through the constraints
    // whenever an unary constraint is met, we test all its domain, get rid of the bad elements and get rid of the constraint
    // if all the elements of the domain are discarded, the problem has no solution.
    /*
     if (x->n_nc) {
     if (constraints_node_consistency(x, domains, &nconstraints, constraints) != V_GOOD) {
     for (this_domains = domains + 1; this_domains->d_size; this_domains++)
     bach_freeptr(this_domains->d_hatoms);
     bach_freeptr(domains);
     for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++)
     bach_freeptr(this_constraints->c_vars);
     bach_freeptr(constraints);
     return llll_get();
     }
     }
     */
    
    
    // here we can achieve arc consistency or whatever
    /*
     if (ac) {
     if (llll_ac3(domains, constraints, testfn, data) != V_GOOD) {
     llll_free(domains);
     llll_free(constraints);
     return llll_get();
     }
     }
     */
    
    
    t_pointmap *centers_pointmap = pointmap_new(nvars);
    t_pointmap *peripheric_pointmap = pointmap_new(nvars);
    t_llll *sln_llll = llll_get();
    
    var_array = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    long idx;
    for (idx = 1; idx <= nvars; idx++)
        var_array[idx] = idx;
    
    domain_steps_array = (long **) bach_newptrclear((nvars + 2) * sizeof(long *));
    domain_steps_pos = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    
    // look for a random combination
    long *center_point = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    //long *best_point = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    //long *center_point = pointmap_get_point(centers_pointmap);
    long *overall_best_point = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    
    t_hatom **current_tuple = (t_hatom **) bach_newptrclear((nvars + 2) * sizeof (t_hatom *));
    
    t_hatom **center_tuple = (t_hatom **) bach_newptrclear((nvars + 2) * sizeof(t_hatom *));
    long used, score;
    t_score_and_good *score_constraintwise = (t_score_and_good *) bach_newptrclear((nconstraints + 2) * sizeof(t_score_and_good));
    t_score_and_good *best_score_constraintwise = (t_score_and_good *) bach_newptrclear((nconstraints + 2) * sizeof(t_score_and_good));
    t_score_and_good *current_score_constraintwise = (t_score_and_good *) bach_newptrclear((nconstraints + 2) * sizeof(t_score_and_good));
    starting_point_for_backtracking = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
    long result, center_is_good = 0;
    long best_score, overall_best_score = LONG_MIN;
    long *current_point = NULL;
    long found_a_good_one = 0;
    t_uint64 numpoints_center, numpoints_peripheric = 0;
    t_bool accepted = false;
    score = -1;
    do {
        used = 0;
        //score = -1;
        result = 0;
        long trys = 0;
        
        do {
            // generate a random center_point we didn't meet yet
            CONSTRAINTS_dev_object_warn((t_object *) x, "----- TOSSING DICE -----");
            
            do {
                for (this_var = 1; this_var <= nvars; this_var++) {
                    long max_dice = domains[this_var].d_currentvalues->d_size;
                    CONSTRAINTS_dev_object_warn((t_object *) x, " --- die #%ld from 1 to %ld", this_var, max_dice);
                    long idx = (rand() % max_dice) + 1;
                    center_point[this_var] = idx;
                }
                used = pointmap_check_for_existence(centers_pointmap, center_point);
                stms = systime_ms();
                if (x->n_stop || (maxtime && stms > maxtime))
                    goto constraints_weak_exit;
                trys++;
                //CONSTRAINTS_dev_object_warn((t_object *) x, " trying with:");
                //constraints_post_int_tuple(center_point);
            } while (used);
            
            CONSTRAINTS_dev_object_post((t_object *) x, " -- the center point is:");
            constraints_post_int_tuple(center_point);
#ifdef CONSTRAINTS_DEBUG
            {
                long i;
                for (i = 1; i <= nvars; i++) {
                    center_tuple[i] = &domains[i].d_currentvalues->d_hatoms[center_point[i]];
                }
                CONSTRAINTS_dev_post(" corresponding to tuple:");
                constraints_post_hatom_tuple(center_tuple);
            }
#endif
            CONSTRAINTS_dev_object_post((t_object *) x, " -- starting backtracking phase");
            
            for (this_domain_steps_array = domain_steps_array + 1, idx = 1;
                 idx <= nvars;
                 this_domain_steps_array++, idx++) {
                long this_domain_size = domains[idx].d_currentvalues->d_size;
                *this_domain_steps_array = (long *) bach_newptrclear((this_domain_size + 2) * sizeof(long));
                long j;
                for (j = 1; j <= this_domain_size; j++)
                    (*this_domain_steps_array)[j] = j;
                shuffle_long_array(*this_domain_steps_array, this_domain_size);
                long start = (*this_domain_steps_array)[1];
                for (j = 1; j < this_domain_size; j++) {
                    (*this_domain_steps_array)[j] = (*this_domain_steps_array)[j+1] - (*this_domain_steps_array)[j];
                    CONSTRAINTS_dev_object_post((t_object *) x, " ---- step #%ld = %ld", j, (*this_domain_steps_array)[j]);
                }
                (*this_domain_steps_array)[j] = start - (*this_domain_steps_array)[j];
                CONSTRAINTS_dev_object_post((t_object *) x, " ---- step #%ld = %ld", j, (*this_domain_steps_array)[j]);
                domain_steps_pos[idx] = 1;
            }
            
            
            
            
            
            bach_copyptr(center_point + 1, starting_point_for_backtracking + 1, nvars * sizeof(long));
            
            this_var = 1;
            
            while (this_var > 0 && this_var <= nvars) {
                CONSTRAINTS_dev_object_post((t_object *) x, " -- this_var = %ld", this_var);
                
                
                // this cycle runs once for every variable to assign
                while (1) {
                    t_constraint ***this_constraints_varwise = constraints_varwise + this_var;
                    t_constraint **this_this_constraints_varwise;
                    t_bool good = true;
                    
                    // let's run through the constraints associated to this variable (could be none of course!)
                    for (this_this_constraints_varwise = *this_constraints_varwise + 1;
                         good && *this_this_constraints_varwise && (*this_this_constraints_varwise)->c_required;
                         this_this_constraints_varwise++) {
                        t_constraint *this_constraint = *this_this_constraints_varwise;
                        CONSTRAINTS_dev_object_post((t_object *) x, " --- this_constraint->c_name = %s", this_constraint->c_name->s_name);
                        
                        long *this_constraint_var;
                        t_bool dummy_accepted;
                        
                        // let's prepare the llll to send out
                        t_llll *test_llll = llll_get();
                        llll_appendsym(test_llll, this_constraint->c_name, 0, WHITENULL_llll);
                        // if we have to send out the variables as well
                        if (this_constraint->c_outputvars) {
                            // then let's prepare a llll with the variables
                            t_llll *vars_llll = llll_get();
                            // let's run through the variables associated to this constraint
                            for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                                CONSTRAINTS_dev_object_post((t_object *) x, " ---- this_constraint_var = %ld", *this_constraint_var);
                                // let's put in vars_llll this variable index
                                llll_appendlong(vars_llll, *this_constraint_var, 0, WHITENULL_llll);
                                // let's copy in test_llll the hatom provisionally assigned to this variable
                                llll_appendhatom_clone(test_llll,
                                                       &domains[*this_constraint_var].d_currentvalues->d_hatoms[center_point[*this_constraint_var]],
                                                       0,
                                                       WHITENULL_llll);
                            }
                            // let's send out the variables
                            llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
                            constraints_func(x, vars_llll, &dummy_accepted);
                            llll_free(vars_llll);
                        } else {
                            for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                                CONSTRAINTS_dev_object_post((t_object *) x, " ---- this_constraint_var = %ld", *this_constraint_var);
                                
                                llll_appendhatom_clone(test_llll,
                                                       &domains[*this_constraint_var].d_currentvalues->d_hatoms[center_point[*this_constraint_var]],
                                                       0,
                                                       WHITENULL_llll);
                            }
                        }
                        constraints_func(x, test_llll, &good, 1, 0);
                        llll_free(test_llll);
                    }
                    
                    stms = systime_ms();
                    
                    /*                   if (stms >= next_pos_output_time) {
                     next_pos_output_time += POS_OUTPUT_INTERVAL;
                     constraints_outpos(x, this_var, tree_size_inv, nvars, positions, domain_positional_multipliers);
                     } */
                    CONSTRAINTS_dev_object_post((t_object *) x, " -- good = %d", good);
                    
                    if (good) {    // if it's good so far
                        this_var++; // pick a value for the next variable
                        CONSTRAINTS_dev_object_post((t_object *) x, " -- this_var = %ld", this_var);
                    } else { // if the result was not good
                        while (this_var > 0 &&
                               (domain_steps_pos[this_var] == domains[this_var].d_currentvalues->d_size)) { // if there are no more values at this level, backtrack!
                            center_point[this_var] = starting_point_for_backtracking[this_var];
                            domain_steps_pos[this_var] = 1;
                            this_var--;
                            CONSTRAINTS_dev_object_post((t_object *) x, " --- just backtracked: this_var = %d", this_var);
                        }
                        if (this_var > 0) {
                            CONSTRAINTS_dev_object_post((t_object *) x, " -- advancing variable %ld:", this_var);
                            CONSTRAINTS_dev_object_post((t_object *) x, " --- domain_steps_pos[this_var] = %ld", domain_steps_pos[this_var]);
                            CONSTRAINTS_dev_object_post((t_object *) x, " --- domain_steps_array[this_var][domain_steps_pos[this_var]] = %ld", domain_steps_array[this_var][domain_steps_pos[this_var]]);
                            CONSTRAINTS_dev_object_post((t_object *) x, " --- center_point was:");
                            constraints_post_int_tuple(center_point);
#ifdef CONSTRAINTS_DEBUG
                            {
                                long i;
                                for (i = 1; i <= nvars; i++) {
                                    center_tuple[i] = &domains[i].d_currentvalues->d_hatoms[center_point[i]];
                                }
                                CONSTRAINTS_dev_post(" corresponding to tuple:");
                                constraints_post_hatom_tuple(center_tuple);
                            }
#endif
                            
                            center_point[this_var] += domain_steps_array[this_var][domain_steps_pos[this_var]];
                            if (center_point[this_var] > domains[this_var].d_currentvalues->d_size)
                                center_point[this_var] -= domains[this_var].d_currentvalues->d_size;
                            else if (center_point[this_var] < 1)
                                center_point[this_var] += domains[this_var].d_currentvalues->d_size;
                            domain_steps_pos[this_var]++;
                            CONSTRAINTS_dev_object_post((t_object *) x, " --- now the center point is:");
                            constraints_post_int_tuple(center_point);
                            
#ifdef CONSTRAINTS_DEBUG
                            {
                                long i;
                                for (i = 1; i <= nvars; i++) {
                                    center_tuple[i] = &domains[i].d_currentvalues->d_hatoms[center_point[i]];
                                }
                                CONSTRAINTS_dev_post(" corresponding to tuple:");
                                constraints_post_hatom_tuple(center_tuple);
                            }
#endif
                        }
                    }
                    if (x->n_stop || (maxtime && stms > maxtime)) {
                        goto constraints_weak_exit;
                    }
                    if (this_var == 0 || this_var > nvars) {
                        CONSTRAINTS_dev_object_post((t_object *) x, " --- breaking out");
                        break;
                    }
                }
                
                if (this_var > nvars) { // if all the labels have been committed
                    if (pointmap_check_for_existence(centers_pointmap, center_point)) {
                        CONSTRAINTS_dev_object_post((t_object *) x, " --- this center point point is taken; looking for another one");
                        this_var = 0;
                        CONSTRAINTS_dev_object_post((t_object *) x, " --- this_var = %d", this_var);
                    }
                }
            }
        } while (this_var == 0);
        
        
        
        
        
        
        
        
        
        
        // we rearrange the constraints variable-wise
        // for each variable, from 1 to domains->l_size, we see which constraints are concerned by it
        // that is, which ones we should re-evaluate when that var's value changes
        // this means that one constraint can appear several times in different constraints_varwise
        // N.B.: this rearrangement is different from the one happening in constraints_simple_backtrack
        
        // this is an array of arrays of t_constraint pointers
        // each of its elements will contain an array of pointers to all the constraints with a given maxvar
        
        //constraints_varwise = (t_constraint ***) bach_newptrclear((nvars + 2) * sizeof(t_constraint **));
        
        // moreover, for each variable we keep a register of which constraints don't affect it
        unconcerned_constraints_idxs = (long **) bach_newptrclear((nvars + 2) * sizeof(long *));
        
        // as usual, let's start from the [1]st position in the array
        this_constraints_varwise = constraints_varwise + 1;
        this_unconcerned_constraints_idxs = unconcerned_constraints_idxs + 1;
        
        
        // here we associate variables and constraints
        
        
        if (1) { // was: if (x->n_sortconstraints) { // here we sort the constraints
                 // let's examine one var after another
            for (var = 1; var <= nvars; var++, this_constraints_varwise++, this_unconcerned_constraints_idxs++) {
                // let's allocate space for this variable's constraints - that is, the [1]st element of the constraints array
                //*this_constraints_varwise = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint *)); // we waste some memory but make things easier!
                *this_unconcerned_constraints_idxs = (long *) bach_newptrclear((nconstraints + 2) * sizeof(long)); // as above
                t_constraint **this_this_constraints_varwise = *this_constraints_varwise + 1;
                long *this_this_unconcerned_constraints_idxs = *this_unconcerned_constraints_idxs + 1;
                long this_var_constraints = 0;
                long idx;
                
                // now let's run through the constraints, one after another
                //CONSTRAINTS_dev_post("working on variable %ld", var);
                long *this_var_ptr;
                for (this_constraints = constraints + 1, idx = 1; this_constraints->c_name; this_constraints++, idx++) {
                    long found = 0;
                    for (this_var_ptr = this_constraints->c_vars + 1; !found && *this_var_ptr; this_var_ptr++)
                        found = (*this_var_ptr == var);
                    
                    if (found) {
                        *this_this_constraints_varwise = this_constraints;
                        this_this_constraints_varwise++;
                        this_var_constraints ++;
                    } else {
                        *(this_this_unconcerned_constraints_idxs++) = idx;
                        //CONSTRAINTS_dev_post(" - constraint %ld is unconcerned", idx);
                    }
                    
                }
                //CONSTRAINTS_dev_post(" -- this_var_constraints: %ld", this_var_constraints);
                
#ifdef CONSTRAINTS_DEBUG____
                for (this_this_constraints_varwise = *this_constraints_varwise + 1, idx = 1;
                     *this_this_constraints_varwise;
                     this_this_constraints_varwise++, idx++) {
                    CONSTRAINTS_dev_post(" --- %ld: %s", idx, (*this_this_constraints_varwise)->c_name->s_name);
                }
#endif
                
                *this_this_constraints_varwise = NULL;
                qsort((*this_constraints_varwise) + 1, this_var_constraints, sizeof(t_constraint *), (qsort_fn) sort_constraint_ptrs_cb);
                
#ifdef CONSTRAINTS_DEBUG_____
                CONSTRAINTS_dev_post(" -- constraints for variable %ld have been rearranged", var);
                for (this_this_constraints_varwise = *this_constraints_varwise + 1, idx = 1;
                     *this_this_constraints_varwise;
                     this_this_constraints_varwise++, idx++) {
                    CONSTRAINTS_dev_post(" --- %ld: %s", idx, (*this_this_constraints_varwise)->c_name->s_name);
                }
#endif
                
            }
            *this_constraints_varwise = NULL;
        } else { // UNUSED FOR NOW
            this_constraints = constraints + 1;
            for (var = 1; var <= nvars; var++, this_constraints_varwise++) {
                // let's allocate space for this variable's constraints - that is, the [var]st element of the constraints array
                *this_constraints_varwise = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint *)); // we waste some memory but make things easier!
                t_constraint **this_this_constraints_varwise = *this_constraints_varwise + 1;
                long this_var_constraints = 0;
                
                // now let's run through the constraints, one after another
                long *this_var_ptr;
                for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++) {
                    long found = 0;
                    for (this_var_ptr = this_constraints->c_vars + 1; !found && *this_var_ptr; this_var_ptr++)
                        found = (*this_var_ptr == var);
                    
                    if (found) {
                        *this_this_constraints_varwise = this_constraints;
                        this_this_constraints_varwise++;
                        this_var_constraints ++;
                    }
                }
                
                *this_this_constraints_varwise = NULL;
            }
            *this_constraints_varwise = NULL;
        }
        
        
        
        
        
        
        
        //CONSTRAINTS_dev_object_warn((t_object *) x, " tried %ld times", trys);
        //current_point = pointmap_get_point(centers_pointmap);
        //bach_copyptr(center_point, current_point, (nvars + 2) * sizeof(long));
        long *center_point_copy = pointmap_get_point(centers_pointmap);
        bach_copyptr(center_point + 1, center_point_copy + 1, nvars * sizeof(long));
        numpoints_center = pointmap_insert(centers_pointmap, center_point_copy);
        
        CONSTRAINTS_dev_object_warn((t_object *) x, "----- THE CENTER POINT IS:");
        constraints_post_int_tuple(center_point);
        
        
        //object_warn_point(x, nvars, center_point);
        
        score = 0;
        // then run through all the constraints, to calculate this combination's score
        
        long idx;
        center_is_good = 1;
        
        for (this_var = 1; this_var <= nvars; this_var++) {
            center_tuple[this_var] = &domains[this_var].d_currentvalues->d_hatoms[center_point[this_var]];
        }
        CONSTRAINTS_dev_post(" corresponding to tuple:");
        constraints_post_hatom_tuple(center_tuple);
        
        for (idx = 1, this_constraints = constraints + 1; /*good && */this_constraints->c_name; idx++, this_constraints++) {
            // we have to run through all the constraints, because this evaluation will form the basis of the further ones
            score += result = constraints_evaluate(x, center_tuple, this_constraints, &accepted);
            score_constraintwise[idx].score = result;
            score_constraintwise[idx].good = accepted;
            center_is_good &= accepted;
            
            post_score_constraintwise(this_constraints, score_constraintwise + idx);
            
        }
        
        CONSTRAINTS_dev_post(" was it good? %ld", center_is_good);
        
        if (center_is_good && (score > overall_best_score || (provisionals == 2 && score == overall_best_score))) { // which means that a better solution has been found
            CONSTRAINTS_dev_object_warn((t_object *) x, " found a good one at first try!", score, center_is_good, found_a_good_one);
            overall_best_score = score;
            if (!scoredetails)
                constraints_outscore(x, score);
            else
                constraints_out_detailed_score(x, score, constraints, score_constraintwise);
            bach_copyptr(center_point + 1, overall_best_point + 1, nvars * sizeof(long));
            if (provisionals && (!has_maxscore || score + provisionals - 1 < maxscore))
                constraints_outprovisionals(x, center_tuple);
        }
        found_a_good_one |= center_is_good;
        
        /*
         if (good)
         post(" which is already good!");
         else
         post(" which is not good yet");
         */
        
        //object_warn((t_object *) x, "- score = %ld", score);
        
        // all the points visited so far have been marked
        
        // now run through all the possible tuples
        
        best_score = score;
        
        //post(" indeed: score = %ld, best_score = %ld, good = %ld", score, best_score, good);
        
        //bach_copyptr(center_point, best_point, (nvars + 2) * sizeof(long));
        bach_copyptr(score_constraintwise, best_score_constraintwise, (nconstraints + 2) * sizeof(t_score_and_good));
        
        current_point = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
        
        long steps = 0;
        
        do {
            CONSTRAINTS_dev_post("--- search the neighbours of center_point:");
            constraints_post_int_tuple(center_point);
            CONSTRAINTS_dev_post(" corresponding to center_tuple:");
            constraints_post_hatom_tuple(center_tuple);
            winner_var = 0;
            bach_copyptr(center_tuple, current_tuple, (nvars + 2) * sizeof(t_hatom *));
            bach_copyptr(center_point + 1, current_point + 1, nvars * sizeof(long));
            long found_a_good_one_with_this_center = center_is_good;
            
            //shuffle_long_array(var_array + 1, nvars);
            long vararray_idx;
            
            for (vararray_idx = 1, this_domains = domains + 1;
                 vararray_idx <= nvars && !(greedy && found) && !(x->n_stop || (maxtime && stms > maxtime)) && (!has_maxscore || best_score < maxscore);
                 this_domains++, vararray_idx++) {
                long var = var_array[vararray_idx];
                long current_score;
                
                // if we have a winner var, this means that a previous run has already be done
                // in this run, all the coordinates of the new center center_point have remained unchanged, except for the winner_var-th coordinate
                // this means that all the points along the winner_var-th coordinate have already been tested
                // all this of course is only true if we're not greedy
                if (var == winner_var && !greedy)
                    continue;
                CONSTRAINTS_dev_post("working on var %ld, at vararray_idx %d", var, vararray_idx);
                long size = this_domains->d_currentvalues->d_size;
                t_constraint ***this_constraints_varwise = constraints_varwise + var;
                t_constraint **this_this_constraints_varwise;
                bach_copyptr(score_constraintwise, current_score_constraintwise, (nconstraints + 2) * sizeof(t_score_and_good));
                current_score = score;
                result = 0;
                long idx;
                long orig_point_coord = center_point[var];
                long all_others_are_good = 1;
                if (!center_is_good) {
                    
                    long *this_this_unconcerned_constraints_idxs;
                    for (this_this_unconcerned_constraints_idxs = unconcerned_constraints_idxs[var] + 1; all_others_are_good && *this_this_unconcerned_constraints_idxs; this_this_unconcerned_constraints_idxs++) {
                        CONSTRAINTS_dev_post(" score_constraintswise for constraint #%ld: %s on variables %ld %ld: good = %ld",
                                             *this_this_unconcerned_constraints_idxs,
                                             constraints[*this_this_unconcerned_constraints_idxs].c_name->s_name,
                                             constraints[*this_this_unconcerned_constraints_idxs].c_vars[1], constraints[*this_this_unconcerned_constraints_idxs].c_vars[2],
                                             score_constraintwise[*this_this_unconcerned_constraints_idxs].good);
                        all_others_are_good &= score_constraintwise[*this_this_unconcerned_constraints_idxs].good;
                    }
                    
                }
                CONSTRAINTS_dev_post("good = %ld", center_is_good);
                CONSTRAINTS_dev_post("all_others_are_good = %ld", all_others_are_good);
                
                for (idx = 1;
                     idx <= size &&
                     !(greedy && found) &&
                     !(x->n_stop || (maxtime && stms > maxtime)) &&
                     (!has_maxscore || best_score < maxscore) &&
                     (maxsteps == 0 || steps <= maxsteps);
                     idx++) {
                    if (idx == orig_point_coord)
                        continue;
                    current_point[var] = idx;
                    
                    if (!pointmap_check_for_existence(peripheric_pointmap, current_point) && !pointmap_check_for_existence(centers_pointmap, current_point)) {
                        long current_is_good;
                        long *current_point_copy = pointmap_get_point(peripheric_pointmap);
                        bach_copyptr(current_point + 1, current_point_copy + 1, nvars * sizeof(long));
                        numpoints_peripheric = pointmap_insert(peripheric_pointmap, current_point_copy);
                        current_tuple[var] = &this_domains->d_currentvalues->d_hatoms[idx];
                        current_is_good = 1;
                        CONSTRAINTS_dev_post("working on current_point:");
                        constraints_post_int_tuple(current_point);
                        CONSTRAINTS_dev_post(" - corresponding to current_tuple:");
                        constraints_post_hatom_tuple(current_tuple);
                        for (this_this_constraints_varwise = *this_constraints_varwise + 1;
                             (!found_a_good_one_with_this_center || current_is_good) && *this_this_constraints_varwise;
                             this_this_constraints_varwise++) {
                            long constraint_idx = *this_this_constraints_varwise - constraints;
                            result = constraints_evaluate(x, current_tuple, *this_this_constraints_varwise, &accepted);
                            //if (accepted)
                            current_score = current_score - current_score_constraintwise[constraint_idx].score + result;
                            current_score_constraintwise[constraint_idx].score = result;
                            current_score_constraintwise[constraint_idx].good = accepted;
                            current_is_good &= accepted;
                        }
                        CONSTRAINTS_dev_post(" is this one good? current_is_good = %ld", current_is_good);
                        CONSTRAINTS_dev_post(" is the center good? center_is_good = %ld", center_is_good);
                        CONSTRAINTS_dev_post(" do we have a good one? found_a_good_one = %ld", found_a_good_one);
                        CONSTRAINTS_dev_post(" have we found a good one with this center? found_a_good_one_with_this_center = %ld", found_a_good_one_with_this_center);
                        CONSTRAINTS_dev_post(" and its score is current_score = %ld", current_score);
                        
                        //object_warn((t_object *) x, "- current_score = %ld", current_score);
                        
                        if ((!found_a_good_one_with_this_center && current_is_good) ||
                            (!found_a_good_one_with_this_center && !current_is_good && current_score >= best_score + picky) ||
                            (found_a_good_one_with_this_center && current_is_good && all_others_are_good && current_score >= best_score + picky)) {
                            
                            //object_warn((t_object *) x, "found a neighbour which is the best so far");
                            //bach_copyptr(current_point, best_point, (nvars + 2) * sizeof(long));
                            CONSTRAINTS_dev_post(" - this was an improvement!");
                            
                            if (winner_var) { // if a previous best center_point was found, we need to clean it up
                                              //best_point[winner_var] = center_point[winner_var];
                                for (this_this_constraints_varwise = constraints_varwise[winner_var] + 1; *this_this_constraints_varwise; this_this_constraints_varwise++) {
                                    long constraint_idx = *this_this_constraints_varwise - constraints;
                                    best_score_constraintwise[constraint_idx] = current_score_constraintwise[constraint_idx];
                                }
                            }
                            //best_point[var] = idx;
                            winner_var = var;
                            CONSTRAINTS_dev_post("winner_var = %ld", winner_var);
                            best_point_winner_var = current_point[winner_var];
                            best_score = current_score;
                            for (this_this_constraints_varwise = *this_constraints_varwise + 1; *this_this_constraints_varwise; this_this_constraints_varwise++) {
                                long constraint_idx = *this_this_constraints_varwise - constraints;
                                best_score_constraintwise[constraint_idx] = current_score_constraintwise[constraint_idx];
                                CONSTRAINTS_dev_post(" best_score_constraintwise[%ld].good = %ld", constraint_idx, best_score_constraintwise[constraint_idx].good);
                            }
                            //winner_var = var;
                            
                            if (current_is_good && all_others_are_good) {
                                CONSTRAINTS_dev_post("THIS IS A GOOD ONE!");
                                found_a_good_one_with_this_center = 1;
                            }
                        }
                        //current_point = (long *) bach_newptrclear((nvars + 2) * sizeof(long));
                        bach_copyptr(center_point + 1, current_point + 1, nvars * sizeof(long));
                        stms = systime_ms();
                    } else {
                        //CONSTRAINTS_dev_object_warn((t_object *) x, " - already visited");
                    }
                }
                
                // restore tuple
                current_tuple[var] = center_tuple[var];
                current_point[var] = center_point[var];
            }
            
            if (winner_var) { // which means that a better solution than the center has been found
                steps++;
                CONSTRAINTS_dev_post("steps = %ld", steps);
                
                center_point[winner_var] = best_point_winner_var;
                //bach_copyptr(best_point, center_point, (nvars + 2) * sizeof(long));
                bach_copyptr(best_score_constraintwise, score_constraintwise, (nconstraints + 2) * sizeof(t_score_and_good));
                /*                if (!good) { // if it was good before, it can't be bad now
                 good = 1;
                 for (this_constraints = constraints + 1, idx = 1; good && this_constraints->c_name; this_constraints++, idx++)
                 good &= score_constraintwise[idx] >= 0;
                 }*/
                score = best_score;
                CONSTRAINTS_dev_object_warn((t_object *) x, "best_score = %ld, good = %ld, found_a_good_one = %ld", score, center_is_good, found_a_good_one);
                //                char buf[2048];
                //                *buf = 0;
                for (var = 1; var <= nvars; var++) {
                    center_tuple[var] = &domains[var].d_currentvalues->d_hatoms[center_point[var]];
                    //                    snprintf_zero(buf, 2048, "%s %ld", buf, center_point[var]);
                }
                //                post("tuple: %s", buf);
                
                if (score > overall_best_score || (provisionals == 2 && score == overall_best_score)) {
                    //CONSTRAINTS_dev_object_warn((t_object *) x, "  > overall_best_score", score);
                    steps = 0;
                    CONSTRAINTS_dev_post("--- RESETTING STEPS");
                    
                    if (found_a_good_one_with_this_center) {
                        //CONSTRAINTS_dev_object_warn((t_object *) x, "  outputting score");
                        overall_best_score = score;
                        if (!scoredetails)
                            constraints_outscore(x, score);
                        else
                            constraints_out_detailed_score(x, score, constraints, score_constraintwise);
                        bach_copyptr(center_point + 1, overall_best_point + 1, nvars * sizeof(long));
                        CONSTRAINTS_dev_post("--- WE HAVE A NEW center_point: ");
                        constraints_post_int_tuple(center_point);
                        if (provisionals && (!has_maxscore || score + provisionals - 1 < maxscore)) {
                            CONSTRAINTS_dev_object_warn((t_object *) x, "  outputting a provisional");
                            constraints_outprovisionals(x, center_tuple);
                        }
                        center_is_good = 1;
                    } else {
                        ;
                    }
                    
                    
                }
                found_a_good_one |= center_is_good;
            }
            stms = systime_ms();
        } while (winner_var &&
                 !x->n_stop &&
                 !(maxtime && stms > maxtime) &&
                 (!has_maxscore || score < maxscore) && (maxsteps == 0 || steps <= maxsteps));
        
        
#ifdef CONSTRAINTS_DEBUG
        if (steps == maxsteps) {
            CONSTRAINTS_dev_post("--- steps REACHED maxsteps - about to toss again");
            
        }
#endif
        
        CONSTRAINTS_dev_post("center_numpoints = %llu, peripheric_numpoints = %llu", numpoints_center, numpoints_peripheric);
    } while (numpoints_peripheric < problem_size - 1 && (!center_is_good || (has_minscore && score < minscore) || (has_goalscore && score < goalscore)) && !x->n_stop && !(maxtime && stms > maxtime));
    
constraints_weak_exit:
    CONSTRAINTS_dev_object_post((t_object *) x, "---- overall_best_score : %ld over %ld constraints", overall_best_score, nconstraints);
    if (found_a_good_one && (!has_minscore || overall_best_score >= minscore)) {
        t_llll *this_sln = llll_get();
        if (!scoredetails)
            constraints_outscore(x, overall_best_score);
        else
            constraints_out_detailed_score(x, overall_best_score, constraints, best_score_constraintwise);
        for (var = 1; var <= nvars; var++)
            llll_appendhatom_clone(this_sln, &domains[var].d_currentvalues->d_hatoms[overall_best_point[var]], 0, WHITENULL_llll);
        llll_appendllll(sln_llll, this_sln, 0, WHITENULL_llll);
    }
    
    for (this_constraints_varwise = constraints_varwise + 1; *this_constraints_varwise; this_constraints_varwise ++)
        bach_freeptr(*this_constraints_varwise);
    bach_freeptr(constraints_varwise);
    
    if (unconcerned_constraints_idxs) {
        for (this_unconcerned_constraints_idxs = unconcerned_constraints_idxs + 1; *this_unconcerned_constraints_idxs; this_unconcerned_constraints_idxs++)
            bach_freeptr(*this_unconcerned_constraints_idxs);
        bach_freeptr(unconcerned_constraints_idxs);
    }
    
    if (domain_steps_array) {
        long **this_domain_shuffle_array;
        for (this_domain_shuffle_array = domain_steps_array + 1; *this_domain_shuffle_array; this_domain_shuffle_array++)
            bach_freeptr(*this_domain_shuffle_array);
        bach_freeptr(domain_steps_array);
    }
    
    constraints_free_domains(domains);
    constraints_free_constraints(constraints);
    bach_freeptr(var_array);
    bach_freeptr(center_tuple);
    bach_freeptr(current_tuple);
    
    
    bach_freeptr(score_constraintwise);
    bach_freeptr(best_score_constraintwise);
    bach_freeptr(current_score_constraintwise);
    
    bach_freeptr(starting_point_for_backtracking);
    
    bach_freeptr(center_point);
    //bach_freeptr(best_point);
    bach_freeptr(overall_best_point);
    bach_freeptr(current_point);
    pointmap_free(centers_pointmap);
    pointmap_free(peripheric_pointmap);
    return sln_llll;
}


// --- NON DESTRUCTIVE
t_llll *constraints_hungry(t_constraints *x, t_llll *domains_ll, t_llll *constraints_ll)
{
    t_constraint ***constraints_varwise, *constraints;
    long nvars;
    long nconstraints;
    long var, this_var;
    t_llll *test_llll, *sln_llll;
    t_llll *vars_llll;
    t_domain *domains;
    t_scored_purged_domain *scored_purged_domains = NULL;
    unsigned long stms, maxtime;
    long provisionals = x->n_provisionals;
    t_llll *garbage = NULL;
    long score;
    
    stms = systime_ms();
    maxtime = x->n_maxtime > 0 ? stms + x->n_maxtime : 0;
    
    // first we should check for the correctness of the incoming data
    switch (constraints_check_domains_allow_empty(x, domains_ll)) {
        case V_INVALID:
            return NULL;
            break;
        case V_EMPTY:
            return llll_get();
            break;
        default:
            break;
    }
    
    // the domains are reversed, so that in case of equal scores the first element is chosen
    constraints_fill_arrays(x, domains_ll, constraints_ll, &nvars, &domains, &nconstraints, &constraints, 0, 1, x->n_random);
    if (nvars < 1 || nconstraints < 1)
        return NULL;
    
    if (x->n_nc) {
        if (constraints_node_consistency(x, domains, &nconstraints, constraints) != V_GOOD) {
            constraints_free_domains(domains);
            constraints_free_constraints(constraints);
            return llll_get();
        }
    }
    
    // we define maxvar
    constraints_assign_maxvar(constraints);
    
    // here we can sort the constraints from looser to tighter
    if (x->n_sortconstraints)
        qsort(constraints + 1, nconstraints, sizeof(t_constraint), (qsort_fn) sort_constraints_cb);
    
    constraints_varwise = constraints_varwise_init(x, constraints, nconstraints, nvars);
    this_var = 1;
    score = 0;
    sln_llll = llll_get();
    garbage = llll_get();
    
    scored_purged_domains = (t_scored_purged_domain *) bach_newptrclear((nvars + 2) * sizeof(t_scored_purged_domain));
    t_scored_hatom **current_scored = (t_scored_hatom **) bach_newptrclear((nvars + 2) * sizeof(t_scored_hatom *));
    
    while (this_var != 0 && this_var <= nvars) {
        CONSTRAINTS_dev_post("working on variable %ld", this_var);
        t_constraint ***this_constraints_varwise = constraints_varwise + this_var;
        t_constraint **this_this_constraints_varwise;
        t_scored_purged_domain *this_scored_purged_domain = &scored_purged_domains[this_var];
        long pd_size = this_scored_purged_domain->s_size;
        if (pd_size == 0) {
            constraints_fill_spd(domains[this_var].d_currentvalues, this_scored_purged_domain);
            pd_size = this_scored_purged_domain->s_size;
        }
        
        for (this_this_constraints_varwise = *this_constraints_varwise + 1; pd_size > 0 && *this_this_constraints_varwise; this_this_constraints_varwise++) {
            
            t_constraint *this_constraint = *this_this_constraints_varwise;
            long *this_constraint_var;
            // let's prepare the llll to send out
            
            // if we have to send out the variables as well
            if (this_constraint->c_outputvars) {
                // then let's prepare a llll with the variables
                vars_llll = llll_get();
                // let's run through the variables associated to this constraint
                for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                    // let's put in vars_llll this variable index
                    llll_appendlong(vars_llll, *this_constraint_var, 0, WHITENULL_llll);
                }
                // let's send out the variables
                llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
                t_bool dummy_accepted;
                constraints_func(x, vars_llll, &dummy_accepted);
                llll_free(vars_llll);
            }
            
            
            t_llll *test_llll_base = llll_get();
            llll_appendsym(test_llll_base, this_constraint->c_name, 0, WHITENULL_llll);
            
            // we build the part of test_llll that doesn't change
            // that is, the part that is only composed by previously assigned (and thus lower-indexed) variables
            t_hatom *changing_hatom;
            for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
                if (*this_constraint_var != this_var)
                    llll_appendhatom_clone(test_llll_base, current_scored[*this_constraint_var]->s_hatom, 0, WHITENULL_llll);
                else
                    changing_hatom = &llll_appendlong(test_llll_base, 0)->l_hatom; // a placeholder
            }
            
            // and now we start running through the domain of this_var
            long item;
            for (item = pd_size; item >= 1; item--) {
                t_scored_hatom *this_scored_hatom = &this_scored_purged_domain->s_scored_hatoms[item];
                t_bool accepted;
                hatom_change_to_hatom_clone_and_free(changing_hatom, this_scored_hatom->s_hatom);
                test_llll = llll_clone(test_llll_base);
                this_scored_hatom->s_score += constraints_func(x, test_llll, &accepted, 1, 0);
                llll_free(test_llll);
                if (!accepted) {
                    t_scored_hatom swap = *this_scored_hatom;
                    *this_scored_hatom = this_scored_purged_domain->s_scored_hatoms[pd_size];
                    this_scored_purged_domain->s_scored_hatoms[pd_size] = swap;
                    pd_size--;
                }
            }
            
            llll_free(test_llll_base);
        }
        
        CONSTRAINTS_dev_post(" - we have %ld values left in the domain", pd_size);
        
        if (pd_size != 0) {
            qsort(this_scored_purged_domain->s_scored_hatoms + 1, pd_size, sizeof(t_scored_hatom), (qsort_fn) sort_scored_hatoms_cb); // should be replaced with a stable sort
            this_scored_purged_domain->s_size = pd_size;
            current_scored[this_var] = &this_scored_purged_domain->s_scored_hatoms[pd_size];
            score += current_scored[this_var]->s_score;
            constraints_outscore(x, score);
            this_var++;
        } else {
            do {
                CONSTRAINTS_dev_post("- invalidating variable %ld", this_var);
                this_scored_purged_domain->s_size = 0;
                current_scored[this_var] = NULL;
                this_var--;
                this_scored_purged_domain--;
                if (this_var > 0)
                    score -= current_scored[this_var]->s_score;
            } while (this_var > 0 && this_scored_purged_domain->s_size <= 1);
            CONSTRAINTS_dev_post("- restarting from variable %ld", this_var);
            
            if (this_var > 0) {
                t_domain *scanned_domain;
                for (scanned_domain = domains + 1; scanned_domain->d_var; scanned_domain++) {
                    while (scanned_domain->d_currentvalues->d_step > this_var) {
                        CONSTRAINTS_dev_post("- downgrading variable %ld", scanned_domain->d_var);
                        scanned_domain->d_currentvalues--;
                        scanned_domain->d_currentll--;
                    }
                }
                this_scored_purged_domain->s_size--;
                current_scored[this_var] = &this_scored_purged_domain->s_scored_hatoms[this_scored_purged_domain->s_size];
                score += current_scored[this_var]->s_score;
                this_var++;
            }
        }
        
        if (this_var > 0 && this_var <= nvars) {
            if (provisionals) {
                t_llll *getdomains = NULL;
                t_llll *setdomains = NULL;
                bach_atomic_lock(&x->n_domain_lock);
                llll_free(x->n_rvs.r_getdomains);
                llll_free(x->n_rvs.r_setdomains);
                x->n_rvs.r_getdomains = NULL;
                x->n_rvs.r_setdomains = NULL;
                bach_atomic_unlock(&x->n_domain_lock);
                constraints_outprovisionals_scored(x, current_scored);
                
                bach_atomic_lock(&x->n_domain_lock);
                if (x->n_rvs.r_getdomains) {
                    getdomains = llll_clone(x->n_rvs.r_getdomains);
                }
                bach_atomic_unlock(&x->n_domain_lock);
                
                if (getdomains) {
                    constraints_getdomains(x, getdomains, domains, nvars);
                    llll_free(getdomains);
                }
                
                bach_atomic_lock(&x->n_domain_lock);
                if (x->n_rvs.r_setdomains) {
                    setdomains = llll_clone(x->n_rvs.r_setdomains);
                }
                bach_atomic_unlock(&x->n_domain_lock);
                if (setdomains) {
                    t_llllelem *elem;
                    for (elem = setdomains->l_head->l_next; elem; elem = elem->l_next) {
                        t_llll *one_setdomains = hatom_getllll(&elem->l_hatom);
                        if (one_setdomains) {
                            t_llllelem *one_setdomains_elem = one_setdomains->l_head;
                            long type = hatom_gettype(&one_setdomains_elem->l_hatom);
                            long domain_idx = 1;
                            if (type == H_LONG || type == H_RAT || type == H_DOUBLE) { // do we have a starting value first?
                                domain_idx = hatom_getlong(&one_setdomains_elem->l_hatom);
                                one_setdomains_elem = one_setdomains_elem->l_next;
                            }
                            if (domain_idx <= 0)
                                domain_idx = 1;
                            for ( ; one_setdomains_elem; one_setdomains_elem = one_setdomains_elem->l_next, domain_idx++) {
                                t_llll *domain_ll = hatom_getllll(&one_setdomains_elem->l_hatom);
                                if (domain_ll && domain_idx <= nvars && !current_scored[domain_idx]) {
                                    constraints_fill_domain(domain_ll, domains + domain_idx, this_var, true, x->n_random);
                                    scored_purged_domains[domain_idx].s_size = 0; // invalidated!
                                }
                            }
                        }
                    }
                    llll_appendobj(garbage, setdomains);
                }
            }
            
            stms = systime_ms();
            if (x->n_stop || (maxtime && stms > maxtime)) {
                goto constraints_hungry_exit;
            }
            
        }
    }
    
    if (this_var > nvars) {
        t_llll *this_sln = llll_get();
        for (var = 1; var <= nvars; var++) {
            llll_appendhatom_clone(this_sln, current_scored[var]->s_hatom, 0, WHITENULL_llll);
        }
        llll_appendllll(sln_llll, this_sln, 0, WHITENULL_llll);
    }
    
    
constraints_hungry_exit:
    if (this_var > nvars)
        this_var = nvars;
    
    constraints_free_constraints_varwise(constraints_varwise);
    constraints_free_domains(domains);
    constraints_free_constraints(constraints);
    constraints_free_garbage(garbage);
    
    for (var = 1; var <= nvars; var++) {
        bach_freeptr(scored_purged_domains[var].s_scored_hatoms);
    }
    bach_freeptr(scored_purged_domains);
    bach_freeptr(current_scored);
    return sln_llll;
}

t_bool constraints_perform_backtracking(long *this_var, t_domain *domains, t_hatom **current, long *positions)
{
    t_bool downgraded = false;
    while (*this_var > 0 && (domains[*this_var].d_currentvalues->d_hatoms + positions[*this_var] + 1)->h_type == H_NOTHING) { // if there are no more variables at this level, backtrack!
        current[*this_var] = NULL;
        positions[*this_var] = 0;
        (*this_var)--;
    }
    if (*this_var > 0) {
        t_domain *scanned_domain;
        for (scanned_domain = domains + 1; scanned_domain->d_var; scanned_domain++) {
            while (scanned_domain->d_currentvalues->d_step > *this_var) {
                CONSTRAINTS_dev_post("- downgrading variable %ld", scanned_domain->d_var);
                scanned_domain->d_currentvalues--;
                scanned_domain->d_currentll--;
                downgraded = true;
            }
            
        }
    }
    return downgraded;
}

void constraints_calculate_tree_size(long nvars, t_domain *domains,
                                     long double *domain_positional_multipliers, long double *tree_size, long double *tree_size_inv)
{
    long var;
    *tree_size = domain_positional_multipliers[nvars] = 1;
    for (var = nvars - 1; var > 0; var--)
        domain_positional_multipliers[var] = (*tree_size *= domains[var + 1].d_currentvalues->d_size);
    *tree_size *= domains[1].d_currentvalues->d_size; // we don't care for the positional value of the last digit, but we need to calculate the tree size anyway
    if (*tree_size != 0)
        *tree_size_inv = 1. / *tree_size;
    else
        *tree_size_inv = 0;
}

void constraints_getdomains(t_constraints *x, t_llll *getdomains, t_domain *domains, long nvars)
{
    long var;
    t_llll *outdomains = llll_get();
    llll_appendsym(outdomains, gensym("domains"));
    if (getdomains->l_size == 1) {
        for (var = 1; var <= nvars; var++) {
            t_llll *this_domain_ll = llll_clone(*domains[var].d_currentll);
            llll_appendllll(outdomains, this_domain_ll);
        }
    } else {
        t_llllelem *elem;
        for (elem = getdomains->l_head->l_next; elem; elem = elem->l_next) {
            long var = hatom_getlong(&elem->l_hatom);
            if (var >= 1 && var <= nvars) {
                t_llll *this_domain_ll = llll_clone(*domains[var].d_currentll);
                llll_appendllll(outdomains, this_domain_ll);
            } else {
                llll_appendllll(outdomains, llll_get());
            }
        }
    }
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, outdomains);
    llll_free(outdomains);
}


void constraints_getdomains_remapped(t_constraints *x, t_llll *getdomains, t_domain *domains, long nvars, long *o2r)
{
    long var;
    t_llll *outdomains = llll_get();
    llll_appendsym(outdomains, gensym("domains"));
    if (getdomains->l_size == 1) {
        for (var = 1; var <= nvars; var++) {
            t_llll *this_domain_ll = llll_clone(*domains[o2r[var]].d_currentll);
            llll_appendllll(outdomains, this_domain_ll);
        }
    } else {
        t_llllelem *elem;
        for (elem = getdomains->l_head->l_next; elem; elem = elem->l_next) {
            long var = hatom_getlong(&elem->l_hatom);
            if (var >= 1 && var <= nvars) {
                t_llll *this_domain_ll = llll_clone(*domains[o2r[var]].d_currentll);
                llll_appendllll(outdomains, this_domain_ll);
            } else {
                llll_appendllll(outdomains, llll_get());
            }
        }
    }
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, outdomains);
    llll_free(outdomains);
}

void constraints_fill_spd(t_domainvalues *values, t_scored_purged_domain *this_scored_purged_domains)
{
    long size = values->d_size;
    if (size > this_scored_purged_domains->s_size || !this_scored_purged_domains->s_scored_hatoms) {
        this_scored_purged_domains->s_scored_hatoms = (t_scored_hatom *) bach_resizeptrclear(this_scored_purged_domains->s_scored_hatoms, (size + 2) * sizeof(t_scored_hatom));
    }
    this_scored_purged_domains->s_size = size;
    long item;
    t_scored_hatom *this_scored_hatom;
    for (item = 1, this_scored_hatom = this_scored_purged_domains->s_scored_hatoms + 1; item <= size; item++, this_scored_hatom++) {
        this_scored_hatom->s_hatom = &values->d_hatoms[item];
        this_scored_hatom->s_score = 0;
    }
    this_scored_hatom->s_hatom = NULL;
    this_scored_hatom->s_score = 0;
}

void constraints_fill_arrays(t_constraints *x, const t_llll *domains_ll, const t_llll *constraints_ll,
                             long *nvars, t_domain **domains,
                             long *nconstraints, t_constraint **constraints,
                             const t_bool force_required, const t_bool reverse_domains, const t_bool randomize_domains)
{
    t_constraint *this_constraints;
    t_llllelem *this_constraint_elem;
    
    *nvars = domains_ll->l_size;
    if (*nvars == 0) {
        object_error((t_object *) x, "Problem has no variables");
        return;
    }
    *nconstraints = constraints_check_constraints(x, constraints_ll, *nvars);
    if (*nconstraints < 1)
        return;
    
    *constraints = (t_constraint *) bach_newptrclear((*nconstraints + 2) * sizeof(t_constraint));
    
    // we count everything from 1 in here!
    this_constraints = *constraints + 1;
    
    // fill the constraints array
    // the list of variables for each constraint is terminated by 0
    for (this_constraint_elem = constraints_ll->l_head; this_constraint_elem; this_constraint_elem = this_constraint_elem->l_next) {
        t_llll *this_constraint_ll = hatom_getllll(&this_constraint_elem->l_hatom);
        t_llllelem *this_constraint_ll_head = this_constraint_ll->l_head;
        t_llllelem *this_option_elem;
        t_symbol *this_option_sym;
        long outputvars = 0, low = 0, required = 0;
        for (this_option_elem = this_constraint_ll->l_tail; (this_option_sym = hatom_getsym(&this_option_elem->l_hatom)) != NULL; this_option_elem = this_option_elem->l_prev) {
            outputvars |= (this_option_sym == _llllobj_sym_vars);
            low |= (this_option_sym == gensym("low"));
            required |= (this_option_sym == gensym("required"));
        }
        if (force_required)
            required = 1;
        
        t_llllelem *this_varlist_elem;
        for (this_varlist_elem = this_constraint_ll_head->l_next; this_varlist_elem && hatom_gettype(&this_varlist_elem->l_hatom) == H_LLLL; this_varlist_elem = this_varlist_elem->l_next, this_constraints++) {
            this_constraints->c_name = hatom_getsym(&this_constraint_ll_head->l_hatom);
            t_llll *varlist_ll = hatom_getllll(&this_varlist_elem->l_hatom);
            this_constraints->c_nvars = varlist_ll->l_size;
            this_constraints->c_vars = (long *) bach_newptrclear((this_constraints->c_nvars + 2) * sizeof(long));
            long *this_var = this_constraints->c_vars + 1;
            t_llllelem *this_var_elem;
            for (this_var_elem = varlist_ll->l_head; this_var_elem; this_var_elem = this_var_elem->l_next, this_var++)
                *this_var = hatom_getlong(&this_var_elem->l_hatom);
            *this_var = 0;
            this_constraints->c_outputvars = outputvars;
            this_constraints->c_low = low;
            this_constraints->c_required = required;
        }
    }
    this_constraints->c_name = NULL;
    
    
    *domains = (t_domain *) bach_newptrclear((*nvars + 2) * sizeof(t_domain));
    
    // fill the domains array
    
    t_domain *this_domain;
    t_llllelem *this_domain_elem;
    long var;
    for (this_domain_elem = domains_ll->l_head, this_domain = *domains + 1, var = 1;
         this_domain_elem;
         this_domain_elem = this_domain_elem->l_next, this_domain++, var++) {
        this_domain->d_currentvalues = this_domain->d_values = (t_domainvalues *) bach_newptrclear((*nvars + 2) * sizeof(t_domainvalues));
        this_domain->d_currentll = this_domain->d_lls = (t_llll **) bach_newptrclear((*nvars + 2) * sizeof(t_llll *));
        this_domain->d_var = var;
        constraints_fill_domain(hatom_getllll(&this_domain_elem->l_hatom), this_domain, 0, reverse_domains, randomize_domains);
    }
}


void constraints_fill_domain(t_llll *this_domain_ll, t_domain *this_domain, long step, t_bool reverse_domains, t_bool randomize_domains)
{
    t_domainvalues *newvalues = ++(this_domain->d_currentvalues);
    long prevsize = newvalues->d_size;
    long newsize = this_domain_ll->l_size;
    
    if (prevsize < newsize || !newvalues->d_hatoms) { // new_size might be 0, but if no allocation has been done, do it anyway!
        newvalues->d_hatoms = (t_hatom *) bach_resizeptrclear(newvalues->d_hatoms, (newsize + 2) * sizeof(t_hatom));
    }
    newvalues->d_size = newsize;
    
    t_hatom *this_hatom;
    long increment;
    if (!reverse_domains) {
        this_hatom = newvalues->d_hatoms + 1;
        increment = 1;
    } else {
        this_hatom = newvalues->d_hatoms + newsize;
        increment = -1;
    }
    
    t_llllelem *this_domain_elem;
    for (this_domain_elem = this_domain_ll->l_head; this_domain_elem; this_domain_elem = this_domain_elem->l_next, this_hatom += increment)
        *this_hatom = this_domain_elem->l_hatom;
    (newvalues->d_hatoms + newsize + 1)->h_type = H_NOTHING;
    
    if (randomize_domains) {
        shuffle_hatom_array(newvalues->d_hatoms + 1, newsize);
    }
    
    newvalues->d_step = step;
    *(++(this_domain->d_currentll)) = this_domain_ll;
}

void constraints_free_domains(t_domain *domains)
{
    t_domain *this_domains;
    if (domains) {
        for (this_domains = domains + 1; this_domains->d_var; this_domains++) {
            t_domainvalues *this_values;
            for (this_values = this_domains->d_values + 1; this_values->d_hatoms; this_values++)
                bach_freeptr(this_values->d_hatoms);
            bach_freeptr(this_domains->d_values);
            bach_freeptr(this_domains->d_lls);
        }
        bach_freeptr(domains);
    }
}

void constraints_free_constraints(t_constraint *constraints)
{
    t_constraint *this_constraints;
    if (constraints) {
        for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++)
            bach_freeptr(this_constraints->c_vars);
        bach_freeptr(constraints);
    }
}

void constraints_free_garbage(t_llll *garbage)
{
    t_llllelem *garbage_elem;
    if (garbage) {
        for (garbage_elem = garbage->l_head; garbage_elem; garbage_elem = garbage_elem->l_next) {
            llll_free((t_llll *) hatom_getobj(&garbage_elem->l_hatom));
        }
        llll_free(garbage);
    }
}

void constraints_output_tree(t_constraints *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *tree = (t_llll *) atom_getobj(av);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, tree);
    llll_free(tree);
}

void constraints_move_to_next_solution(t_hatom ***this_current, t_hatom **under_exam, long *this_var, long **this_positions)
{
    //long new_position;
    (*this_var)--;
    *under_exam = *((*this_current)--);
    
    while (*under_exam && *under_exam + 1 == NULL) {
        *((*this_positions)--) = 0;
        (*this_var)--;
        *under_exam = *((*this_current)--);
    }
    
    // look for the last variable whose domain has not been explored completely
    // that is, if *under_exam means that what we've popped is actually a variable (if it's NULL, it means that we've reached the top of the stack)
    // and if **(under_exam + 1) means that there is another value to explore in its domain
    if (*under_exam) {
        (*under_exam)++; // go there
        *(++(*this_current)) = *under_exam;
        (**this_positions)++;
    }
}


// domains are in the form (el1 el2 ...) (el1 el2 ...) ...
// so we simply check for each element being an llll
e_llll_constraints_validity constraints_check_domains(t_llll *domains)
{
    t_llllelem *elem;
    if (domains->l_size == 0)
        return V_EMPTY;
    for (elem = domains->l_head; elem; elem = elem->l_next) {
        if (elem->l_hatom.h_type != H_LLLL)
            return V_INVALID;
        if (elem->l_hatom.h_w.w_llll->l_size == 0)
            return V_EMPTY;
    }
    return V_GOOD;
}

e_llll_constraints_validity constraints_check_domains_allow_empty(t_constraints *x, const t_llll *domains)
{
    t_llllelem *elem;
    if (domains->l_size == 0)
        return V_EMPTY;
    for (elem = domains->l_head; elem; elem = elem->l_next) {
        if (elem->l_hatom.h_type != H_LLLL) {
            object_error((t_object *) x, "Badly formed domains llll");
            return V_INVALID;
        }
    }
    if (hatom_getllll(&domains->l_head->l_hatom)->l_size == 0)
        return V_EMPTY;
    return V_GOOD;
}

// constraints are in the form (constraint1_id (var1 var2 ...) (var1 var2 ...) ... [vars] [after]) (constraint2_id (var1 var2 ...) (var1 var2 ...) ... [vars] [low])
// so we need to check for each element being an llll of length > 1
// and each element after the 1st being an llll of depth 1, except for the optional vars keywords
// and each element of it being an integer 1 < n <= nvars
long constraints_check_constraints(t_constraints *x, const t_llll *constraints, long nvars)
{
    t_llllelem *elem;
    t_llll *constraint_llll;
    t_llllelem *var;
    long count = 0;
    for (elem = constraints->l_head; elem; elem = elem->l_next) {
        t_llllelem *in_elem;
        if (elem->l_hatom.h_type != H_LLLL || (constraint_llll = elem->l_hatom.h_w.w_llll)->l_size < 2) {
            object_error((t_object *) x, "Badly formed constraints llll");
            return 0;
        }
        t_hatom *name = &constraint_llll->l_head->l_hatom;
        char *nametxt = NULL;
        long type = hatom_gettype(name);
        hatom_to_text_buf(name, &nametxt);
        if (type != H_LONG && type != H_SYM) {
            object_warn((t_object *) x, "Suspicious name for constraint %ld: %s", count + 1, nametxt);
        }
        for (in_elem = constraint_llll->l_head->l_next; in_elem && hatom_gettype(&in_elem->l_hatom) == H_LLLL; in_elem = in_elem->l_next) {
            t_llll *varlist_llll = hatom_getllll(&in_elem->l_hatom);
            if (varlist_llll->l_depth != 1 || varlist_llll->l_size < 1) {
                object_error((t_object *) x, "Badly formed variables list for constraint %s", nametxt);
                bach_freeptr(nametxt);
                return 0;
            }
            for (var = varlist_llll->l_head; var; var = var->l_next) {
                long idx;
                if (var->l_hatom.h_type != H_LONG) {
                    object_error((t_object *) x, "Constraint %s: all variable indices must be integers", nametxt);
                    bach_freeptr(nametxt);
                    return 0;
                }
                idx = var->l_hatom.h_w.w_long;
                if (idx < 1 || idx > nvars) {
                    object_error((t_object *) x, "Constraint %s: variable index %ld out of range", nametxt, idx);
                    bach_freeptr(nametxt);
                    return 0;
                }
            }
            count++;
        }
        for ( ; in_elem; in_elem = in_elem->l_next) {
            t_symbol *sym = hatom_getsym(&in_elem->l_hatom);
            if (sym != _llllobj_sym_vars && sym != gensym("low") && sym != gensym("required")) {
                char *spectxt = NULL;
                hatom_to_text_buf(&in_elem->l_hatom, &spectxt);
                object_error((t_object *) x, "Constraint %s: unknown specifier %s", nametxt, spectxt);
                bach_freeptr(spectxt);
                return 0;
            }
        }
        bach_freeptr(nametxt);
    }
    if (count == 0)
        object_error((t_object *) x, "Problem has no constraints");
    return count;
}


void constraints_free_constraints_varwise(t_constraint ***constraints_varwise)
{
    t_constraint ***this_constraints_varwise;
    if (constraints_varwise) {
        for (this_constraints_varwise = constraints_varwise + 1; *this_constraints_varwise; this_constraints_varwise ++)
            bach_freeptr(*this_constraints_varwise);
        bach_freeptr(constraints_varwise);
    }
}


t_constraint ***constraints_varwise_init(t_constraints *x, t_constraint *constraints, long nconstraints, long nvars)
{
    // we rearrange the constraints variable-wise
    // for each variable, from 1 to domains->l_size, we see which constraints are concerned by it
    // actually, we will see which constraints have that var as their highest-order variable
    // that is, which ones we should re-evaluate when that var's value changes
    
    // this is an array of arrays of t_constraint pointers
    // each of its elements will contain an array of pointers to all the constraints with a given maxvar
    t_constraint ***constraints_varwise = (t_constraint ***) bach_newptrclear((nvars + 2) * sizeof(t_constraint **));
    t_constraint ***last_constraints_varwise = (t_constraint ***) bach_newptrclear((nvars + 2) * sizeof(t_constraint **));
    
    long var;
    for (var = 1; var <= nvars; var++) {
        constraints_varwise[var] = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint *)); // we waste some memory but make things easier
        last_constraints_varwise[var] = constraints_varwise[var] + 1;
    }
    
    t_constraint *this_constraint;
    for (this_constraint = constraints + 1; this_constraint->c_name; this_constraint++) {
        long maxvar = this_constraint->c_maxvar;
        *(last_constraints_varwise[maxvar]++) = this_constraint;
    }
    
    bach_freeptr(last_constraints_varwise);
    
    return constraints_varwise;
    
    /*
     if (x->n_sortconstraints) {
     // let's examine one var after another
     long var;
     for (var = 1; var <= nvars; var++, this_constraints_varwise++) {
     // let's allocate space for this variable's constraints - that is, the [1]st element of the constraints array
     *this_constraints_varwise = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint *)); // we waste some memory but make things easier!
     t_constraint **this_this_constraints_varwise = *this_constraints_varwise + 1;
     long this_var_constraints = 0;
     
     // now let's run through the constraints, one after another
     t_constraint *this_constraints;
     for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++) {
     if (this_constraints->c_maxvar == var) {
     *this_this_constraints_varwise = this_constraints;
     this_this_constraints_varwise++;
     this_var_constraints ++;
     }
     }
     *this_this_constraints_varwise = NULL;
     qsort((*this_constraints_varwise) + 1, this_var_constraints, sizeof(t_constraint *), (qsort_fn) sort_constraints_with_attributes_by_ptr_cb);
     }
     *this_constraints_varwise = NULL;
     } else {
     t_constraint *this_constraints;
     long var;
     this_constraints = constraints + 1;
     for (var = 1; var <= nvars; var++, this_constraints_varwise++) {
     // let's allocate space for this variable's constraints - that is, the [1]st element of the constraints array
     *this_constraints_varwise = (t_constraint **) bach_newptrclear((nconstraints + 2) * sizeof(t_constraint *)); // we waste some memory but make things easier!
     t_constraint **this_this_constraints_varwise = *this_constraints_varwise + 1;
     while (this_constraints->c_name && this_constraints->c_maxvar <= var) {
     *this_this_constraints_varwise = this_constraints;
     this_this_constraints_varwise++;
     this_constraints++;
     }
     *this_this_constraints_varwise = NULL;
     }
     *this_constraints_varwise = NULL;
     }
     return constraints_varwise;
     */
}


void constraints_assign_maxvar(t_constraint *constraints)
{
    t_constraint *this_constraints;
    for (this_constraints = constraints + 1; this_constraints->c_name; this_constraints++) {
        long *this_var;
        long maxvar = 1;
        for (this_var = this_constraints->c_vars + 1; *this_var > 0; this_var++) {
            if (*this_var > maxvar)
                maxvar = *this_var;
            if (*this_var > this_constraints->c_maxvar)
                this_constraints->c_maxvar = *this_var;
        }
    }
}






long sort_constraints_testfn(void *dummy, t_llllelem *a, t_llllelem *b)
{
    return a->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_llll->l_size <= b->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_llll->l_size;
}

long sort_domains_testfn(void *dummy, t_llllelem *a, t_llllelem *b)
{
    return a->l_hatom.h_w.w_llll->l_size <= b->l_hatom.h_w.w_llll->l_size;
}



// qsort return value:
// < 0 if a must come first
// > 0 if b must come first

int sort_domains_cb(t_domain *a, t_domain *b)
{
    long asize = a->d_currentvalues->d_size;
    long bsize = b->d_currentvalues->d_size;
    if (asize == 0)
        return 1;
    else if (bsize == 0)
        return -1;
    else
        return a->d_currentvalues->d_size - b->d_currentvalues->d_size;
}

int sort_constraints_cb(t_constraint *a, t_constraint *b)
{
    long required = b->c_required - a->c_required;
    if (required != 0)
        return required;
    return a->c_nvars - b->c_nvars;
}

int sort_constraint_ptrs_cb(t_constraint **a, t_constraint **b)
{
    long required = (*b)->c_required - (*a)->c_required;
    if (required != 0)
        return required;
    long lowness = (*a)->c_low - (*b)->c_low;
    if (lowness != 0)
        return lowness;
    return (*a)->c_nvars - (*b)->c_nvars;
}

int sort_scored_hatoms_cb(t_scored_hatom *a, t_scored_hatom *b)
{
    return a->s_score - b->s_score;
}

void shuffle_ptr_array(void **arr, long size)
{
    long i;
    for (i = size; i > 1; i--) {
        long idx = rand() % i; // not the best random number ever, but it's fairly ok ;)
        void *temp = arr[idx];
        arr[idx] = arr[i-1];
        arr[i-1] = temp;
    }
}

void shuffle_hatom_array(t_hatom *arr, long size)
{
    long i;
    for (i = size; i > 1; i--) {
        long idx = rand() % i; // not the best random number ever, but it's fairly ok ;)
        t_hatom temp = arr[idx];
        arr[idx] = arr[i-1];
        arr[i-1] = temp;
    }
}

void shuffle_long_array(long *arr, long size)
{
    long i;
    for (i = size; i > 1; i--) {
        long idx = rand() % i; // not the best random number ever, but it's fairly ok ;)
        long temp = arr[idx];
        arr[idx] = arr[i-1];
        arr[i-1] = temp;
    }
}

t_pointmap *pointmap_new(long nvars)
{
    long i;
    //t_pointmap *x = (t_pointmap *) bach_newptrclear(CONSTRAINTS_POINTMAP_SLOTS * sizeof(t_pointmap));
    t_pointmap *x = (t_pointmap *) bach_newptrclear(sizeof(t_pointmap));
    x->p_bucket = (t_pointllelem **) bach_newptrclear(CONSTRAINTS_POINTMAP_SLOTS * sizeof(t_pointllelem *)); // 8
    
    x->p_ptelempool = (t_pointllelem **) bach_newptr((CONSTRAINTS_POINTS_POOL_SIZE + 1) * sizeof(t_pointllelem *)); // 8
    x->p_ptelempool[CONSTRAINTS_POINTS_POOL_SIZE] = NULL;
    x->p_ptelempool_next_free = x->p_ptelempool + CONSTRAINTS_POINTS_POOL_SIZE - 1;
    for (i = 0; i < CONSTRAINTS_POINTS_POOL_SIZE; i++)
        x->p_ptelempool[i] = (t_pointllelem *) bach_newptrclear(sizeof(t_pointllelem)); // 32
    
    x->p_mapelempool = (t_mapllelem **) bach_newptr((CONSTRAINTS_POINTS_POOL_SIZE + 1) * sizeof(t_mapllelem *)); // 8
    x->p_mapelempool[CONSTRAINTS_POINTS_POOL_SIZE] = NULL;
    x->p_mapelempool_next_free = x->p_mapelempool + CONSTRAINTS_POINTS_POOL_SIZE - 1;
    for (i = 0; i < CONSTRAINTS_POINTS_POOL_SIZE; i++)
        x->p_mapelempool[i] = (t_mapllelem *) bach_newptrclear(sizeof(t_mapllelem)); // 24
    
    x->p_points_pool = (long **) bach_newptr((CONSTRAINTS_POINTS_POOL_SIZE + 1) * sizeof(long *)); // 8
    x->p_points_pool[CONSTRAINTS_POINTS_POOL_SIZE] = NULL;
    x->p_points_pool_next_free = x->p_points_pool + CONSTRAINTS_POINTS_POOL_SIZE - 1;
    for (i = 0; i < CONSTRAINTS_POINTS_POOL_SIZE; i++) {
        x->p_points_pool[i] = (long *) bach_newptrclear((nvars + 2) * sizeof(long)); // 8
                                                                                     //*x->p_points_pool[i] = 123456789;
    }
    
    x->p_nvars = nvars;
    
    return x;
}

t_uint64 pointmap_insert(t_pointmap *x, long *point)
{
    t_pointllelem *ptelem = *(x->p_ptelempool_next_free--);
    ptelem->p_point = point;
    ptelem->p_next = NULL;
    
    t_mapllelem *mapllelem = *(x->p_mapelempool_next_free--);
    mapllelem->m_pointllelem = ptelem;
    mapllelem->m_next = NULL;
    
    x->p_stored_points++;
    
    // insert it in the hash table
    unsigned long key = point_hash(point, x->p_nvars) % CONSTRAINTS_POINTMAP_SLOTS;
    t_pointllelem **bucket = x->p_bucket + key;
    ptelem->p_bucket = bucket;
    t_pointllelem *prev = *bucket;
    if (!prev) {
        ptelem->p_prev = NULL;
        *bucket = ptelem;
    } else {
        while (prev->p_next)
            prev = prev->p_next;
        ptelem->p_prev = prev;
        prev->p_next = ptelem;
    }
    
    // append it to the linked list
    if (!x->p_mapll_head) {
        x->p_mapll_head = x->p_mapll_tail = mapllelem;
        mapllelem->m_prev = NULL;
    } else {
        x->p_mapll_tail->m_next = mapllelem;
        mapllelem->m_prev = x->p_mapll_tail;
        x->p_mapll_tail = mapllelem;
    }
    // no need to set m_next, it is already NULL
    // (either because it has never been used, or because it has been set to NULL when the same mapllelem has been removed before)
    
#ifdef CONFIGURATION_Development
    if (x->p_mapelempool_next_free < x->p_mapelempool)
        bach_breakpoint(0);
    
    if (x->p_ptelempool_next_free < x->p_ptelempool)
        bach_breakpoint(0);
#endif
    
    // do we need to remove one point?
    if (x->p_ptelempool_next_free == x->p_ptelempool) {
        t_mapllelem *oldest_in_ll = x->p_mapll_head;
        x->p_mapll_head = oldest_in_ll->m_next;
        x->p_mapll_head->m_prev = NULL;
        oldest_in_ll->m_next = NULL;
        t_pointllelem *oldest_in_ht = oldest_in_ll->m_pointllelem;
        prev = oldest_in_ht->p_prev;
        t_pointllelem *next = oldest_in_ht->p_next;
        if (prev)
            prev->p_next = next;
        else
            *(oldest_in_ht->p_bucket) = next;
        if (next)
            next->p_prev = prev;
        
        *(++x->p_points_pool_next_free) = oldest_in_ht->p_point;
        *(++x->p_ptelempool_next_free) = oldest_in_ht;
        *(++x->p_mapelempool_next_free) = oldest_in_ll;
        x->p_stored_points--;
    }
    return x->p_stored_points;
}

long pointmap_check_for_existence(t_pointmap *x, long *point)
{
    unsigned long key = point_hash(point, x->p_nvars) % CONSTRAINTS_POINTMAP_SLOTS;
    t_pointllelem *elem = x->p_bucket[key];
    size_t size = (x->p_nvars + 1) * sizeof(long);
    while (elem && memcmp(point, elem->p_point, size) != 0)
        elem = elem->p_next;
    return elem != NULL;
}

long *pointmap_get_point(t_pointmap *x)
{
    return *(x->p_points_pool_next_free--);
}

void pointmap_free(t_pointmap *x)
{
    t_mapllelem *elem, *nextelem;
    long count;
    for (elem = x->p_mapll_head, count = 0; elem; elem = nextelem, count++) {
        bach_freeptr(elem->m_pointllelem->p_point);
        bach_freeptr(elem->m_pointllelem);
        nextelem = elem->m_next;
        bach_freeptr(elem);
    }
    
    bach_freeptr(x->p_bucket);
    
    t_pointllelem **ptllelem;
    for (ptllelem = x->p_ptelempool; ptllelem <= x->p_ptelempool_next_free; ptllelem++)
        bach_freeptr(*ptllelem);
    bach_freeptr(x->p_ptelempool);
    
    t_mapllelem **mapllelem;
    for (mapllelem = x->p_mapelempool; mapllelem <= x->p_mapelempool_next_free; mapllelem++)
        bach_freeptr(*mapllelem);
    bach_freeptr(x->p_mapelempool);
    
    long **point;
    for (point = x->p_points_pool; point <= x->p_points_pool_next_free; point++)
        bach_freeptr(*point);
    bach_freeptr(x->p_points_pool);
    
    bach_freeptr(x);
}

unsigned long point_hash(long *point, long nvars)
{
    unsigned long hash = 5381;
    long i = 0;
    
    for (i = 1; i <= nvars; point++, i++)
        hash = ((hash << 5) + hash) + (*point);
    return hash;
}


long constraints_evaluate(t_constraints *x, t_hatom **tuple, t_constraint *this_constraint, t_bool *accepted)
{
    long *this_constraint_var;
    long result;
    // let's prepare the llll to send out
    t_llll *test_llll = llll_get();
    llll_appendsym(test_llll, this_constraint->c_name, 0, WHITENULL_llll);
    // if we have to send out the variables as well
    if (this_constraint->c_outputvars) {
        // then let's prepare a llll with the variables
        t_llll *vars_llll = llll_get();
        // let's run through the variables associated to this constraint
        for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
            // let's put in vars_llll this variable intex
            llll_appendlong(vars_llll, *this_constraint_var, 0, WHITENULL_llll);
            // let's copy in test_llll the hatom provisionally assigned to this variable
            llll_appendhatom_clone(test_llll, tuple[*this_constraint_var], 0, WHITENULL_llll);
        }
        // let's send out the variables
        llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
        constraints_func(x, vars_llll, accepted);
        llll_free(vars_llll);
    } else {
        // let's run through the constraints associated to this variable
        for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
            llll_appendhatom_clone(test_llll, tuple[*this_constraint_var], 0, WHITENULL_llll);
        }
    }
    result = constraints_func(x, test_llll, accepted, 1, 0);
    llll_free(test_llll);
    return result;
}

long constraints_evaluate_with_remap(t_constraints *x, t_hatom **tuple, t_constraint *this_constraint, t_bool *accepted, long *var_remap_r2o)
{
    long *this_constraint_var;
    long result;
    // let's prepare the llll to send out
    t_llll *test_llll = llll_get();
    llll_appendsym(test_llll, this_constraint->c_name, 0, WHITENULL_llll);
    // if we have to send out the variables as well
    if (this_constraint->c_outputvars) {
        // then let's prepare a llll with the variables
        t_llll *vars_llll = llll_get();
        // let's run through the variables associated to this constraint
        for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
            // let's put in vars_llll this variable intex
            llll_appendlong(vars_llll, var_remap_r2o[*this_constraint_var], 0, WHITENULL_llll);
            // let's copy in test_llll the hatom provisionally assigned to this variable
            llll_appendhatom_clone(test_llll, tuple[*this_constraint_var], 0, WHITENULL_llll);
        }
        // let's send out the variables
        llll_prependsym(vars_llll, _llllobj_sym_vars, 0, WHITENULL_llll);
        constraints_func(x, vars_llll, accepted);
        llll_free(vars_llll);
    } else {
        // let's run through the constraints associated to this variable
        for (this_constraint_var = this_constraint->c_vars + 1; *this_constraint_var != 0; this_constraint_var++) {
            llll_appendhatom_clone(test_llll, tuple[*this_constraint_var], 0, WHITENULL_llll);
        }
    }
    result = constraints_func(x, test_llll, accepted, 1, 0);
    llll_free(test_llll);
    return result;
}


void object_warn_point(t_constraints *x, long nvars, long *point)
{
#ifdef CONSTRAINTS_DEBUG
    char txt[2048];
    long i;
    *txt = 0;
    for (i = 1; i <= nvars; i++)
        snprintf_zero(txt, 2048, "%s %ld", txt, point[i]);
    object_warn((t_object *) x, txt);
#endif
}


void constraints_post_int_tuple(long *tuple)
{
#ifdef CONSTRAINTS_DEBUG
    char buf[2048];
    *buf = 0;
    for (tuple++; *tuple != 0; tuple ++)
        snprintf_zero(buf, 2048, " %s %ld", buf, *tuple);
    post("%s", buf);
#endif
}

void constraints_post_hatom_tuple(t_hatom **tuple)
{
#ifdef CONSTRAINTS_DEBUG
    t_llll *templl = llll_get();
    int i;
    for (i = 1; tuple[i] != NULL; i++) {
        llll_appendhatom_clone(templl, tuple[i], 0, WHITENULL_llll);
    }
    llll_print(templl);
    llll_free(templl);
#endif
}



void post_one_constraint(t_constraint *thisC)
{
#ifdef CONSTRAINTS_DEBUG
    post("constraint name: %s", thisC->c_name->s_name);
    post("nvars: %ld", thisC->c_nvars);
    long idx;
    for (idx = 1; thisC->c_vars[idx]; idx++) {
        post(" - var %ld: %ld", idx, thisC->c_vars[idx]);
    }
#endif
}

void post_constraints(t_constraint *c)
{
#ifdef CONSTRAINTS_DEBUG
    t_constraint *thisC;
    for (thisC = c + 1; thisC->c_name; thisC++) {
        post_one_constraint(thisC);
    }
    post("------------------------");
#endif
}

void post_domains(t_domain *d)
{
#ifdef CONSTRAINTS_DEBUG
    long didx;
    for (didx = 1; d[didx].d_var; didx++) {
        post("domain %ld", didx);
        long vidx;
        t_domainvalues *v = d[didx].d_currentvalues;
        post("size of currentvalues: %ld", v->d_size);
        for (vidx = 1; v->d_hatoms[vidx].h_type != H_NOTHING; vidx++) {
            post(" - currentvalues %ld: %ld", vidx, hatom_getlong(v->d_hatoms + vidx));
        }
    }
    post("------------------------");
#endif
}

void post_score_constraintwise(t_constraint *c, t_score_and_good *s)
{
#ifdef CONSTRAINTS_DEBUG
    post("------score_constraintwise for the following constraint:");
    post_one_constraint(c);
    post("-------is it good? %ld", s->good);
    post("-------and its score is %ld", s->score);
    post("---------");
#endif
}
