/**
    @file    bach_graphics.h
    @brief    Common tools for painting and writing.
    
    by Daniele Ghisi
*/

#ifndef _BACH_GRAPHICS_H_
#define _BACH_GRAPHICS_H_

#include "bach.h"

//#ifdef USE_GPC_LIBRARY
//#include "gpc.h"
//#endif

//#define BACH_MAX7_STYLES_COMPATIBILITY  // uncomment it if you want Max7-styles support - but this will BREAK compatibility with Max6!!!

#ifdef BACH_MAX
#include "jgraphics.h"
/**    Declaration of type for the unicode character, for cross-platform compatibility        @ingroup datatypes    */
typedef unsigned short unicodeChar;
#endif

#ifdef BACH_JUCE
#include "bach_jucewrapper.h"
#include "juce_paint_wrappers.h"
/**    Declaration of type for the unicode character, for cross-platform compatibility        @ingroup datatypes    */
typedef juce_wchar unicodeChar;
#endif


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif




// (PRIVATE) Some convenience threshold constants
#define CONST_EPSILON1 0.05 
#define CONST_EPSILON2 0.15 
#define CONST_EPSILON3 0.0005 
#define CONST_EPSILON4 0.0005 
#define CONST_EPSILON5 0.01 
#define CONST_EPSILON_DOUBLE_EQ 0.0001    ///< Used in ms_to_unscaled_xposition() to handle the equality of doubles
#define CONST_EPSILON_ALIGNMENTS 0.01    ///< Threshold used in functions determining the position of points with respect to points/figures 

#ifndef PIOVERTWO
/** The pi/2 constant.                @ingroup math    */
#define PIOVERTWO    1.57079632679489661923
#endif

// Convenience constants combining the #t_jgraphics_text_justification constants
#ifdef BACH_MAX
#define JGRAPHICS_TEXT_JUSTIFICATION_BOTTOMLEFT        (JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM |    JGRAPHICS_TEXT_JUSTIFICATION_LEFT) 
#define JGRAPHICS_TEXT_JUSTIFICATION_BOTTOMRIGHT    (JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM |    JGRAPHICS_TEXT_JUSTIFICATION_RIGHT) 
#define JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT        (JGRAPHICS_TEXT_JUSTIFICATION_TOP |        JGRAPHICS_TEXT_JUSTIFICATION_LEFT) 
#define JGRAPHICS_TEXT_JUSTIFICATION_TOPRIGHT        (JGRAPHICS_TEXT_JUSTIFICATION_TOP |        JGRAPHICS_TEXT_JUSTIFICATION_RIGHT) 
#endif

typedef struct _jhsla {
    double hue;                ///< Hue component in the range [0.0, 2*pi]
    double saturation;        ///< Saturation component in the range [0.0, 1.0]
    double lightness;        ///< Lightness component in the range [0.0, 1.0]
    double alpha;            ///< Alpha (transparency) component in the range [0.0, 1.0]
} t_jhsla;


/** A polygon.    @ingroup geometry */
typedef struct _polygon
{
    long num_vertices;
    t_pt *vertices;
} t_polygon;


/** A bezier closed spline.    @ingroup geometry */
typedef struct _bezier_cs
{
    long num_segments;
    t_pt *vertices;
    t_pt *ctrl_pt_1;
    t_pt *ctrl_pt_2;
} t_beziercs;



// internal only
typedef struct _bach_casting_ray
{
    t_pt c; // starting point for the ray (center of innermost polygon)

    double alpha; // angle
    //... and cw and ccw extensions
    double alpha_cw;
    double alpha_ccw;
    
    t_pt p; // point outside the polygon, end of the ray
    //... and cw and ccw extensions
    t_pt p_cw;
    t_pt p_ccw;

    
    // intersection with outermost polygon
    t_pt q;
    long idx_q;
    //... and cw and ccw extensions
    t_pt q_cw;
    long idx_q_cw;
    t_pt q_ccw;
    long idx_q_ccw;
    
    
    // intersection with innermost polygon
    t_pt r;
    long idx_r;
    //... and cw and ccw extensions
    t_pt r_cw;
    long idx_r_cw;
    t_pt r_ccw;
    long idx_r_ccw;
    
    
    // distance between intersection
    double dist;
} t_bach_casting_ray;







//// POLYGON STUFF

void polygon_free(t_polygon *p);
t_polygon *polygon_build(long num_points, t_pt *points);


t_pt polygon_get_barycenter(t_polygon *poly);
char polygon_get_orientation(t_polygon *poly);
char triangle_get_orientation(t_pt t1, t_pt t2, t_pt t3);


/**    Determine if a point lies inside a generic polygon
    @ingroup        geometry
    @param    pt        The point
    @param    poly    The polygon
    @return            1 if pt is inside the polygon, 0 otherwise
 */ 
char is_pt_in_polygon(t_pt pt, t_polygon *poly);

/*t_polygon polygon_offset_smart(t_polygon poly, double amount, long unwanted_pts_size, t_pt *unwanted_pts);

// mode == 1: extrusion must stay WITHIN container
// mode == 2: extrusion must stay OUTSIDE container
// mode == 0: no constraint
void polygon_offset_smart_inplace(t_polygon **poly, double amount, long unwanted_pts_size, t_pt *unwanted_pts, 
                                   char mode, t_polygon *container, char algo_intersect, long wanted_pts_size, t_pt *wanted_pts);
*/
t_polygon *get_convex_hull(long num_points, t_pt *points);
t_polygon *get_bounding_box(long num_points, t_pt *points, t_pt pad);
double pt_polygon_distance(t_pt pt, t_polygon *poly);

// lexicographical order
double pt_pt_cmp(t_pt pt1, t_pt pt2);


//// BEZIER CLOSED SPLINES STUFF
t_beziercs *beziercs_build(long num_segments, t_pt *vertices, t_pt *cp1, t_pt *cp2);
void beziercs_free(t_beziercs *p);
void paint_beziercs(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_beziercs *bezier);
t_beziercs *polygon_to_bezier_closed_spline(t_polygon *poly);
t_beziercs *get_venn_enclosure(long num_pts_in, t_pt *pts_in, long num_pts_out, t_pt *pts_out, t_jgraphics *g);


// MATH UTILITIES FOR PAINTING

/**    Evaluate the position of a moving point on a bezier curve with 2 control points (3rd order).
    @ingroup    geometry
    @param    x0                The x of the curve start point 
    @param    y0                The y of the curve start point
     @param    x1                The x of the first control point 
    @param    y1                The y of the first control point
    @param    x2                The x of the second control point
     @param    y2                The y of the second control point
    @param    x3                The x of the curve end point 
    @param    y3                The y of the curve end point
    @param    t                The "time"-point in which the position will be evaluated (the curve is parametrated by 0<=t<=1, 0 being the beginning, 1 being the end) 
     @param    x_res            Will be filled with the x of the evaluated point 
    @param    y_res            Will be filled with the y of the evaluated point 
 */
void compute_bezier_point(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double t, double *x_res, double *y_res);


// (PRIVATE) get a bach-standard choice for the two internal bezier control points for the cubic bezier curve in the convex hull given by x_start y_start x_end y_end, with the slope given by slope (0 = linear). BEWARE: ONLY WORKS FOR POSITIVE SLOPES
void get_bezier_control_points(double x_start, double y_start, double x_end, double y_end, double slope, double *ctrl_1_x, double *ctrl_1_y, double *ctrl_2_x, double *ctrl_2_y, double *left_derivative, double *right_derivative);
// (PRIVATE) get the middle refinement point to split a curve display into 2 bezier curves
void get_middle_refinement_point_for_curve(double x1, double y1, double x2, double y2, double *middle_x, double *middle_y, double *middle_derivative, double slope);


/** Fill an array of #t_unicodeChar with some data.
    @ingroup    math
    @param        a        Pointer to the first element of the array
    @param        count    Number of #t_unicodeChar arguments (to be placed after this <count> argument) with which the array will be filled
    @remark                Be sure that the array has the correct size to be filled with <count> arguments. 
 */
void fill_unicodeChar_array(unicodeChar *a, long count,...);



// GEOMETRY UTILITIES 

/**    Determine if three points are aligned
    @ingroup    geometry
    @param    x0        The x of the first point  
    @param    y0        The y of the first point
    @param    x1        The x of the second point  
    @param    y1        The y of the second point
    @param    x2        The x of the third point  
    @param    y2        The y of the third point
    @return            1 if points are aligned, 0 otherwise
    @remark            The threshold for alignment is the static constant #CONST_EPSILON_ALIGNMENTS.
 */
char are_pts_aligned(double x0, double y0, double x1, double y1, double x2, double y2);


/**    Determine if a point lies on a segment
    @ingroup    geometry
    @param    ptx        The x of the point    
    @param    pty        The y of the point
    @param    x1        The x of the head of the segment  
    @param    y1        The y of the head of the segment
    @param    x2        The x of the tail of the segment
    @param    y2        The y of the tail of the segment
    @return            1 if (ptx, pty) is on the segment determined by (x1, y1) and (x2, y2), 0 otherwise
    @remark            The threshold for alignment is the static constant #CONST_EPSILON_ALIGNMENTS.
    @see            are_pts_aligned()
 */
char is_pt_in_segment(double ptx, double pty, double x1, double y1, double x2, double y2);


/**    Determine if a point lies inside a generic triangle
    @ingroup    geometry
    @param    ptx        The x of the point    
    @param    pty        The y of the point
    @param    x1        The x of the first vertex of the triangle  
    @param    y1        The y of the first vertex of the triangle
    @param    x2        The x of the second vertex of the triangle
    @param    y2        The y of the second vertex of the triangle
    @param    x3        The x of the third vertex of the triangle
    @param    y3        The y of the third vertex of the triangle
    @return            1 if (ptx, pty) is inside the triangle determined by (x1, y1), (x2, y2) and (x3, y3), 0 otherwise
    @remark            The threshold for alignment is the static constant #CONST_EPSILON_ALIGNMENTS.
 */
char is_pt_in_triangle(double ptx, double pty, double x1, double y1, double x2, double y2, double x3, double y3);


/**    Determine if a point lies inside a rectangle
    @ingroup    geometry
    @param    pt        The point
    @param    rect    The rectangle
    @return            1 if pt is inside the rectangle
 */
char is_pt_in_rectangle(t_pt pt, t_rect rect);


/**    Determine if a point lies inside a rectangle, with a tolerance pad
    @ingroup    geometry
    @param    pt        The point
    @param    rect    The rectangle
    @param    tolerance    The tolerance pad (the same for each side of the rectangle)
    @return            1 if pt is inside the rectangle, within the given tolerance
 */
char is_pt_in_rectangle_tolerance(t_pt pt, t_rect rect, double tolerance);


/**    Determine if a point lies inside a generic quadrilater
    @ingroup    geometry
     @param    ptx        The x of the point    
    @param    pty        The y of the point
    @param    x1        The x of the first vertex of the quadrilater  
    @param    y1        The y of the first vertex of the quadrilater
     @param    x2        The x of the second vertex of the quadrilater
     @param    y2        The y of the second vertex of the quadrilater
    @param    x3        The x of the third vertex of the quadrilater
    @param    y3        The y of the third vertex of the quadrilater
    @param    x4        The x of the fourth vertex of the quadrilater
    @param    y4        The y of the fourth vertex of the quadrilater
    @return            1 if (ptx, pty) is inside the quadrilater determined by (x1, y1), (x2, y2), (x3, y3) and (x4, y4), 0 otherwise
    @remark            The threshold for alignment is the static constant #CONST_EPSILON_ALIGNMENTS.
 */
char is_pt_in_quadrilater(double ptx, double pty, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


/**    Determine if a point lies in the semiplane ABOVE a segment
    @ingroup    geometry
    @param    ptx        The x of the point    
    @param    pty        The y of the point
    @param    x1        The x of the head of the segment  
    @param    y1        The y of the head of the segment
    @param    x2        The x of the tail of the segment
    @param    y2        The y of the tail of the segment
    @return            1 if (ptx, pty) is in the upper semimplane with respect to the segment determined by (x1, y1) and (x2, y2)
 */
char is_pt_above_segment(double ptx, double pty, double x1, double y1, double x2, double y2); // detect if a point is inside a semiplane


/**    Find the distance between a point and a line in the plane.
    @ingroup    geometry
     @param    ptx        The x of the point  
    @param    pty        The y of the point
    @param    x1        The x of a point of the line  
    @param    y1        The y of a point of the line
    @param    x2        The x of another (different) point of the line
    @param    y2        The y of this latter
    @return            The distance between (ptx, pty) and the line determined by (x1, y1) and (x2, y2)
 */
double pt_line_distance(double ptx, double pty, double x1, double y1, double x2, double y2);


/**    Find the distance between a point and the intersection of the vertical line containing the point and a given line.
    (For short: the "vertical" distance between the point and the line, i.e. the distance "calculated" on the line drawn 
    vertically from the point to the line)
    @ingroup    geometry
    @remark            This is a actually not a distance, but a signed difference of Y values, positive when is pty is 
                    greater than the vertical intersection point Y, negative otherwise
    @param    ptx        The x of the point  
    @param    pty        The y of the point
    @param    x1        The x of a point of the line  
    @param    y1        The y of a point of the line
    @param    x2        The x of another (different) point of the line
    @param    y2        The y of this latter
    @return            The distance between (ptx, pty) and the point of the line, determined by (x1, y1) and (x2, y2), which has as x ptx.
                    If the point is above the line, this distance will be positive, otherwise negative. If the point is on the line, the 
                    distance will be null (which is also the case if the line is purely vertical).
 */
double pt_line_distance_vertical(double ptx, double pty, double x1, double y1, double x2, double y2);

/**    Find the distance between a point and a line segment (not the whole infinite line!)
    @ingroup    geometry
    @remark            This is different from pt_line_distance, since it is only referred to the segment between the two extreme points
    @param    ptx        The x of the point
    @param    pty        The y of the point
    @param    x1        The x of the starting point of the segment
    @param    y1        The y of the starting point of the segment
    @param    x2        The x of the ending point of the segment
    @param    y2        The y of the ending point of the segment
    @return            The distance between (ptx, pty) and the segment.
 */
double pt_segment_distance(t_pt pt, t_pt v, t_pt w);


/**    Tell if a point lies on a line segment.
    @ingroup    geometry
    @param    point_x            The x of the point to consider
    @param    point_y            The y of the point to consider
    @param    start_x            The x of the starting point of the line
    @param    start_y            The y of the starting point of the line
    @param    end_x            The x of the ending point of the line
    @param    end_x            The y of the ending point of the line
    @param    line_width        The line width of the curve (you might want to increase it to account for toleration factors)
    @return            1 if the point lies on the segment, 0 otherwise.
 */
int is_pt_in_line_shape(double point_x, double point_y, double start_x, double start_y, double end_x, double end_y, double line_width);


/**    Compute dot product of two-dimensional vectors.
    @ingroup    geometry
    @param    p            The first vector
    @param    q            The second vector
    @return            The "dot" (internal) product of the two vectors
 */
double pt_pt_dot(t_pt p, t_pt q);


/**    Tell if a point lies on a bezier curve.
    @ingroup                geometry
    @param    point_x            The x of the point to consider
    @param    point_y            The y of the point to consider
    @param    start_x            The x of the starting point of the curve
    @param    start_y            The y of the starting point of the curve
    @param    end_x            The x of the ending point of the curve
    @param    end_x            The y of the ending point of the curve
    @param    slope            The slope of the curve (-1 to 1, 0 being linear)
    @param    line_width        The line width of the curve (you might want to increase it to account for toleration factors)
    @return                    1 if the point lies on the curve, 0 otherwise.
 */
int is_pt_in_curve_shape(double point_x, double point_y, double start_x, double start_y, double end_x, double end_y, double slope, double line_width);


/**    Tell if a line and a rectangle intersect (i.e. if there is a collision).
    The line is identified by two (different) points lying on it.
    @ingroup                geometry
    @param    line_x1            The x of the first point on the line.
    @param    line_y1            The y of the first point on the line.
    @param    line_x2            The x of the second point on the line.
    @param    line_y2            The y of the second point on the line.
    @param    rect_x1            The x of the rectangle top-left corner.
    @param    rect_y1            The y of the rectangle top-left corner
    @param    rect_width        The width of the rectangle.
    @param    rect_height        The height of the rectangle.
    @param    detect_full_line_collision    If 0, the algorithm only takes into account the collision between the rectangle and the segment identified by the two points,
                                        and not the collision with the parts of the line before and after the two points. If non-zero, the full line is taken into account.
    @return                    1 if the there is collision, 0 otherwise.
 */
char line_rectangle_collision(double line_x1, double line_y1, double line_x2, double line_y2, double rect_x1, double rect_y1, double rect_width, double rect_height, char detect_full_line_collision);


/**    Tell if two rectangles intersect (i.e. if there is a collision).
    @ingroup                geometry
    @param    rect1_x1        The x of the first rectangle top-left corner.
    @param    rect1_y1        The y of the first rectangle top-left corner
    @param    rect1_width        The width of the first rectangle.
    @param    rect1_height    The height of the first rectangle.
    @param    rect2_x1        The x of the second rectangle top-left corner.
    @param    rect2_y1        The y of the second rectangle top-left corner
    @param    rect2_width        The width of the second rectangle.
    @param    rect2_height    The height of the second rectangle.
    @return                    1 if the there is collision, 0 otherwise.
 */
char rectangle_rectangle_collision(double rect1_x1, double rect1_y1, double rect1_width, double rect1_height, double rect2_x1, double rect2_y1, double rect2_width, double rect2_height);


// PAINTING AND WRITING WRAPPERS


/**    Paint a line.
    @ingroup        paint
    @param    g        The graphic context  
    @param    color    The color
    @param    x1        The x of the start point
    @param    y1        The y of the start point
    @param    x2        The x of the end point
     @param    y2        The y of the end point
    @param    width    The width of the line
 */
void paint_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width);


/**    Fast non antialiasing/rotating version of paint_line()
     @ingroup        paint
    @param    g        The graphic context  
    @param    color    The color
    @param    x1        The x of the start point
    @param    y1        The y of the start point
    @param    x2        The x of the end point
    @param    y2        The y of the end point
    @param    width    The width of the line
 */
void paint_line_fast(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width);


/**    Paint a filled rectangle (with no border, only filling content)
     @ingroup        paint
     @param    g        The graphic context  
     @param    color    The color
    @param    x1        The x of the top-left corner
     @param    y1        The y of the top-left-corner
    @param    width    The width of the rectangle
    @param    height    The height of the rectangle
 */
void paint_filledrectangle(t_jgraphics* g, t_jrgba fillcolor, double x1, double y1, double width, double height);


/**    Paint a rounded filled rectangle (with no border, only filling content)
     @ingroup        paint
     @param    g        The graphic context  
     @param    color    The color
    @param    x1        The x of the top-left corner
     @param    y1        The y of the top-left-corner
    @param    width    The width of the rectangle
    @param    height    The height of the rectangle
    @param    ovalwidth    The radius of the horizontal rounding
    @param    ovalheight    The radius of the vertical rounding
 */
void paint_filledrectangle_rounded(t_jgraphics* g, t_jrgba fillcolor, double x1, double y1, double width, double height, double ovalwidth, double ovalheight);


/**    Paint a vertically striped rectangle (with no border, only filling content)
     @ingroup        paint
     @param    g        The graphic context  
     @param    bgcolor    The color of the background
     @param    stripecolor    The color of the superposed stripes
    @param    x1        The x of the top-left corner
     @param    y1        The y of the top-left-corner
    @param    width    The width of the rectangle
    @param    height    The height of the rectangle
    @param    stripe_width    The width of each stripe
    @param    nonstripe_width    The width of each non-striped space
 */
void paint_stripedrectangle(t_jgraphics* g, t_jrgba bgcolor, t_jrgba stripecolor, double x1, double y1, double width, double height, double stripe_width, double nonstripe_width);


/**    Fast non-antialiased version of paint_filledrectangle()
     @ingroup        paint
     @param    g        The graphic context  
     @param    color    The color
    @param    x1        The x of the top-left corner
     @param    y1        The y of the top-left-corner
    @param    width    The width of the rectangle
    @param    height    The height of the rectangle
 */
void paint_filledrectangle_fast(t_jgraphics* g, t_jrgba fill_color, double x1, double y1, double width, double height);


/**    Paint a rectangle (only outline, no filling content)
    @ingroup            paint
    @param    g            The graphic context  
     @param    bordercolor    The border color
     @param    x1            The x of the top-left corner
    @param    y1            The y of the top-left-corner
    @param    width        The width of the rectangle
    @param    height        The height of the rectangle
    @param    linewidth    The width of the line of the border
*/
void paint_strokenrectangle(t_jgraphics* g, t_jrgba bordercolor, double x1, double y1, double width, double height, double linewidth);


/**    Fast non-antialiased version of paint_strokenrectangle()
    @ingroup            paint
    @param    g            The graphic context  
     @param    bordercolor    The border color
     @param    x1            The x of the top-left corner
    @param    y1            The y of the top-left-corner
    @param    width        The width of the rectangle
    @param    height        The height of the rectangle
    @param    linewidth    The width of the line of the border
*/
void paint_strokenrectangle_fast(t_jgraphics* g, t_jrgba bordercolor, double x1, double y1, double width, double height, double linewidth);


/**    Paint a rectangle (both outline, and filling content)
    @ingroup                paint
    @param    g                The graphic context  
    @param    border_color    The border color
    @param    fill_color        The interior color
    @param    x1                The x of the top-left corner
    @param    y1                The y of the top-left-corner
    @param    width            The width of the rectangle
    @param    height            The height of the rectangle
    @param    border_width    The width of the line of the border
    @see    paint_filledrectangle()
    @see    paint_strokenrectangle()
 */
void paint_rectangle(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width);


/**    Paint a rectangle with rounded corners (both outline, and filling content)
    @ingroup                paint
    @param    g                The graphic context  
     @param    border_color    The border color
    @param    fill_color        The interior color
    @param    x1                The x of the top-left corner
    @param    y1                The y of the top-left-corner
    @param    width            The width of the rectangle
    @param    height            The height of the rectangle
    @param    border_width    The width of the line of the border
    @param    oval_width        The width of the oval used for the round corners
    @param    oval_height        The height of the oval used for the round corners
    @see    paint_rectangle()
 */
void paint_rectangle_rounded(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width, double ovalwidth, double ovalheight);


/**    Paint a rhomboid (as the ones used for breakpoints in bach UI objects)
    @ingroup            paint
    @param    g            The graphic context 
    @param    bordercolor    The border color
    @param    fillcolor    The filling color
    @param    bpt_x        The x of the center of the rhomboid
    @param    bpt_y        The y of the center of the rhomboid
    @param    semiwidth    Half of the horizontal width of the rhomboid
    @param    semiheight    Half of the vertical height of the rhomboid
    @param    linewidth    The width of the line of the border
 */
void paint_rhomboid(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double bpt_x, double bpt_y, double semiwidth, double semiheight, double linewidth);


/**    Paint a generic triangle
    @ingroup            paint
    @param    g            The graphic context 
    @param    bordercolor    The border color
    @param    fillcolor    The filling color
    @param    x1            The x of the first vertex of the triangle  
    @param    y1            The    y of the first vertex of the triangle
    @param    x2            The x of the second vertex of the triangle
    @param    y2            The y of the second vertex of the triangle
    @param    x3            The x of the third vertex of the triangle
    @param    y3            The y of the third vertex of the triangle
    @param    linewidth    The width of the line of the border
 */
void paint_triangle(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x1, double y1, double x2, double y2, double x3, double y3, double linewidth);


/**    Paint a generic quadrilater
    @ingroup            paint
    @param    g            The graphic context 
    @param    bordercolor    The border color
    @param    fillcolor    The filling color
    @param    x1            The x of the first vertex of the quadrilater  
    @param    y1            The    y of the first vertex of the quadrilater
     @param    x2            The x of the second vertex of the quadrilater
     @param    y2            The y of the second vertex of the quadrilater
    @param    x3            The x of the third vertex of the quadrilater
    @param    y3            The y of the third vertex of the quadrilater
    @param    x4            The x of the fourth vertex of the quadrilater
    @param    y4            The y of the fourth vertex of the quadrilater
    @param    linewidth    The width of the line of the border
 */
void paint_quadrilater(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double linewidth);



/**    Paint a filled circle (with no stroken circumference, only filled)
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The filling color
    @param    x            The x of the center  
    @param    y            The y of the center
    @param    radius        The radius of the circle
 */
void paint_circle_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radius);


/**    Paint a circumference (not filled, only border)
     @ingroup            paint
     @param    g            The graphic context 
    @param    color        The line color
    @param    x            The x of the center  
     @param    y            The y of the center
    @param    radius        The radius of the circle
    @param    linewidth    The width of the line
 */
void paint_circle_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radius, double linewidth);


/**    Paint a circle (both circumference and filled content)
    @ingroup            paint
    @param    g            The graphic context 
    @param    bordercolor    The color of the border
    @param    fillcolor    The color of the interior
    @param    x            The x of the center  
    @param    y            The y of the center
    @param    radius        The radius of the circle
    @param    linewidth    The width of the line
 */
void paint_circle(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x, double y, double radius, double linewidth);


/**    Paint an arc of a circumference (border only)
     @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x            The x of the center  
    @param    y            The y of the center
    @param    radius        The radius of the circle
    @param    linewidth    The width of the line
    @param    start_angle    The starting angle of the arc in radians. Zero radians is center right (positive x axis).
    @param    end_angle    The ending angle of the arc in radians. Zero radians is center right (positive x axis).
 */
void paint_arc_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radius, double linewidth, double start_angle, double end_angle);


/**    Paint a filled ellipse (with no stroken circumference, only filled)
     @ingroup            paint
     @param    g            The graphic context 
     @param    color        The filling color
     @param    x            The x of the center  
     @param    y            The y of the center
     @param    radiusx        The horizontal radius
    @param    radiusy        The vertical radius
 */
void paint_ellipse_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy);


/**    Paint an ellipse, but only border (no filling)
    @ingroup            paint
    @param    g            The graphic context 
     @param    color        The ellipse color
    @param    x            The x of the center  
    @param    y            The y of the center
     @param    radiusx        The horizontal radius
    @param    radiusy        The vertical radius
    @param    linewidth    The width of the line
 */
void paint_ellipse_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy, double linewidth);


/**    Paint a vertical dashed line
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
     @param    x            The horizontal coordinate of the line  
    @param    y1            The starting y
    @param    y2            The ending y
    @param    width        The width of the line
    @param    dash_length    The length of the single dash (also the length of each single space between dashes)
 */
void paint_dashed_y_line(t_jgraphics* g, t_jrgba color, double x, double y1, double y2, double width, double dash_length);


/**    Paint an horizontal dashed line
    @ingroup            paint
     @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The starting x
    @param    x2            The ending x
    @param    y            The vertical coordinate of the line  
    @param    width        The width of the line
    @param    dash_length    The length of the single dash (also the length of each single space between dashes)
 */
void paint_dashed_x_line(t_jgraphics* g, t_jrgba color, double x1, double x2, double y, double width, double dash_length);


/**    Paint a dashed line
     @ingroup            paint
     @param    g            The graphic context 
     @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
     @param    width        The width of the line
    @param    dash_length    The length of the single dash (also the length of each single space between dashes)
 */
void paint_dashed_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width, double dash_length);


/**    Paint a bezier curve.
    @ingroup            paint
    @param    g            The graphic context
    @param    color        The line color
    @param    start_x            The x of the starting point
    @param    start_y            The y of the starting point
    @param  control_point1_x    The x of the first control point
    @param  control_point1_y    The y of the first control point
    @param  control_point2_x    The x of the second control point
    @param  control_point2_y    The y of the second control point
    @param    end_x            The x of the ending point
    @param    end_y            The y of the ending point
    @param    width        The width of the line
 */
void paint_bezier_curve(t_jgraphics* g, t_jrgba color, double start_x, double start_y, double control_point1_x, double control_point1_y, double control_point2_x, double control_point2_y, double end_x, double end_y, double width);


/**    Paint a 3rd-order bezier curve, without leaving control to the user of the two internal control points.
    These points are "automatically" obtained via the function get_bezier_control_points(), so the user just have to care about
    the starting and the ending point of the curve, and its slope.
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
     @param    y2            The y of the ending point  
    @param    slope        The slope of the curve (Max-like parameter: 0 = linear, -1 = "extremely logarithmic", 1 = "extremely exponential", as in the [curve~] object) 
    @param    width        The width of the line
 */
void paint_simple_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width);


/**    Paint a curve as the union of two 3rd-order bezier curves,    without leaving control to the user of the internal control points.
    These points are "automatically" obtained via the function get_bezier_control_points(), so the user just have to care about
    the starting and the ending point of the curve, and its slope. The algorithm changes then a control points, so that the first derivative is 
    always preserved in the junction of the two bezier curves. This is the function used in drawing slopes in bach UI object: indeed, splitting
    the curve into two bezier curves gives a much better quality of result for slopes near -1 or near 1 (the split point depends on the slope also).
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
    @param    slope        The slope of the curve (Max-like parameter: 0 = linear, -1 = "extremely logarithmic", 1 = "extremely exponential", as in the [curve~] object) 
    @param    width        The width of the line
 */
void paint_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width);


/**    Paint a curve, as for paint_curve() function, but also returns the full control points of the two bezier polygons determining the two parts of the curve.
    @ingroup            paint
    @param    g            The graphic context. If NULL, the function will run and possibly retrieve all the values, without painting anything
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
    @param    slope        The slope of the curve (Max-like parameter: 0 = linear, -1 = "extremely logarithmic", 1 = "extremely exponential", as in the [curve~] object) 
    @param    width        The width of the line
    @param    ctrl1        Pointer which will be filled with the first control point of the first bezier curve
    @param    ctrl2        Pointer which will be filled with the second control point of the first bezier curve
    @param    middle_pt    Pointer which will be filled with the middle point (the intersection point between the two parts of the curve)
    @param    ctrl3        Pointer which will be filled with the first control point of the second bezier curve
    @param    ctrl4        Pointer which will be filled with the second control point of the second bezier curve
 */
void paint_curve_and_get_bezier_control_points(t_jgraphics* g, t_jrgba color, t_pt start, t_pt end, double slope, double width, 
                                               t_pt *ctrl1, t_pt *ctrl2, t_pt *middle_pt, t_pt *ctrl3, t_pt *ctrl4);


/**    Subdivide a (cubic) bezier curve with De Casteljau's algorithm
    @ingroup            paint
    @param p0        Starting point of original curve
    @param p1        First control point of original curve
    @param p2        Second control point of original curve
    @param p3        Ending point of original curve
    @param q0        Pointer which will be filled with the starting point of the left subdivision curve
    @param q1        Pointer which will be filled with the first control point of the left subdivision curve
    @param q2        Pointer which will be filled with the second control point of the left subdivision curve
    @param q3        Pointer which will be filled with the ending point of the left subdivision curve
    @param r0        Pointer which will be filled with the starting point of the right subdivision curve
    @param r1        Pointer which will be filled with the first control point of the right subdivision curve
    @param r2        Pointer which will be filled with the second control point of the right subdivision curve
    @param r3        Pointer which will be filled with the ending point of the right subdivision curve
    @param t        The parameter for subdivision point (between 0. and 1.)
 */
void subdivide_bezier(t_pt p0, t_pt p1, t_pt p2, t_pt p3, t_pt *q0, t_pt *q1, t_pt *q2, t_pt *q3, t_pt *r0, t_pt *r1, t_pt *r2, t_pt *r3, double t);


/**    Obtain the middle subdivision points for a cubic Bezier curve
    @ingroup            paint
    @param p0        Starting point of original curve
    @param p1        First control point of original curve
    @param p2        Second control point of original curve
    @param p3        Ending point of original curve
    @param t        The parameter for subdivision point (between 0. and 1.)
    @param order    The (diadic) recursion order of the algorithm (1 = split the curve into 2 curves, 2 = split the curve into 4 curves, and so on).
                    Must be at least 1.
    @param subd_pts    Array of subdivision points, already allocated with at least 2^order - 1 elements, which will be filled with the middle subdivision points. 
    @return            0 if no error were found, 1 if some error was detected.
    @see            get_single_bezier_subdivision_point()
 */
char get_bezier_subdivision_points(t_pt p0, t_pt p1, t_pt p2, t_pt p3, double t, long order, t_pt *subd_pts);


/**    Obtain one middle subdivision point for a cubic Bezier curve
    @ingroup        paint
    @param p0        Starting point of original curve
    @param p1        First control point of original curve
    @param p2        Second control point of original curve
    @param p3        Ending point of original curve
    @param t        The parameter for subdivision point (between 0. and 1.)
    @return            The middle subdivision point
    @remark            This function corresponds to get_bezier_subdivision_points() with order = 1.
    @see            get_bezier_subdivision_points()
 */
t_pt get_single_bezier_subdivision_point(t_pt p0, t_pt p1, t_pt p2, t_pt p3, double t);


                                                 
/**    Paint a slur like the one used to gather tuplets (if slur and NOT bracket is chosen, of course). Actually, this is just a 3-rd order bezier curve,
    whose control points coincide.
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    xm            The x of the (coinciding) control points
    @param    ym            The y of the (coinciding) control points
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
    @param    width        The width of the line
 */
void paint_tuplet_slur(t_jgraphics* g, t_jrgba color, double x1, double y1, double xm, double ym, double x2, double y2, double width);


/**    Paint a line (like paint_line()), starting with a given line width and ending with another line width.
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
    @param    width_start    The starting line width
    @param    width_end    The ending line width
    @see                paint_line()
 */
void paint_doublewidth_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width_start, double width_end);


/**    Paint a curve (like paint_curve(), union of two 3rd-order bezier curves), starting with a given line width and ending with another line width.
    @ingroup            paint
    @param    g            The graphic context 
    @param    color        The line color
    @param    x1            The x of the starting point
    @param    y1            The y of the starting point
    @param    x2            The x of the ending point  
    @param    y2            The y of the ending point  
    @param    slope        The slope of the curve (see paint_curve()) 
    @param    width        The width of the line
    @see                paint_curve()
 */
void paint_doublewidth_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width_start, double width_end);


/**    Paint a line (like paint_line()), whose color changes as a gradient from a starting color to an ending color.
     @ingroup                        paint
    @param    g                        The graphic context 
    @param    color_start                The starting line color
    @param    color_end                The ending line color
    @param    x1                        The x of the starting point
    @param    y1                        The y of the starting point
    @param    x2                        The x of the ending point  
    @param    y2                        The y of the ending point  
     @param    width                    The line width
    @param    num_steps                Number of discretization steps from the beginning to the end, to paint the color gradient 
                                    (= number of actually painted differently coloured small lines) 
    @param    colors_from_spectrum    If this is 1, the <color_start> and <color_end> are ignored, and the colors are built from the standard bach colourspectrum 
                                    (red to blue), starting from the following velocity parameters <vel1>, <vel2>, <max_velocity>. This mean that the starting 
                                    color will be double_to_color(vel1, 0, max_velocity), the ending color will be double_to_color(vel2, 0, max_velocity), and
                                    every intermediate color will NOT be the interpolation of the first and last color, but the interpolated parameter will 
                                    actually be the velocity (from <vel1> to <vel2>) and for every interpolated velocity v, the corresponding color will be 
                                    calculated with double_to_color(v, 0, max_velocity).
                                    If this is 0, the intermediate colors will be interpolated from <color_start> to <color_end>, via color_interp(), and 
                                    the following velocities parameter <vel1>, <vel2> and <max_velocity> will be ignored.
    @param    vel1                    The starting velocity (used only if <colors_from_spectrum> = 1)
    @param    vel2                    The ending velocity (used only if <colors_from_spectrum> = 1)
    @param    max_velocity            The maximum admitted velocity (used only if <colors_from_spectrum> = 1), usually #CONST_MAX_VELOCITY
    @see                            paint_line()
 */
void paint_colorgradient_line(t_jgraphics* g, t_jrgba color_start, t_jrgba color_end, double x1, double y1, double x2, double y2, double width, long num_steps, char colors_from_spectrum, double vel1, double vel2, double max_velocity);


/**    Paint a curve (like paint_curve(), union of two 3rd-order bezier curves), whose color changes as a gradient from a starting color to an ending color.
    IMPORTANT: This function doesn't really work properly, and for the moment it only paints the two bezier curves, the first one having as color the 
    starting color, and the second one having as color the ending color.
    In order to improve this function, one would need some algorithms to refine each bezier curve into <num_steps>/2 smaller beziers, and to assign
    a different color to each small curve.
    @ingroup                        paint
    @param    g                        The graphic context 
    @param    color_start                The starting line color
    @param    color_end                The ending line color
    @param    x1                        The x of the starting point
    @param    y1                        The y of the starting point
    @param    x2                        The x of the ending point  
    @param    y2                        The y of the ending point  
    @param    width                    The line width
    @param    num_steps                (IGNORED) Number of discretization steps from the beginning to the end, to paint the color gradient 
    @param    colors_from_spectrum    If this is 1, the <color_start> and <color_end> are ignored, and the colors are built from the standard bach colourspectrum.
                                    See paint_colorgradient_line() for more information.
    @param    vel1                    The starting velocity (used only if <colors_from_spectrum> = 1)
    @param    vel2                    The ending velocity (used only if <colors_from_spectrum> = 1)
    @param    max_velocity            The maximum admitted velocity (used only if <colors_from_spectrum> = 1), usually #CONST_MAX_VELOCITY
    @see                            paint_colorgradient_line()
    @see                            paint_curve()
 */
void paint_colorgradient_curve(t_jgraphics* g, t_jrgba color_start, t_jrgba color_end, double x1, double y1, double x2, double y2, double slope, double width, long num_steps, char are_color_from_spectrum, double vel1, double vel2, double max_velocity);


/**    Paint a line with an arrow at the end.
    @ingroup                paint
    @param    g                The graphic context  
    @param    color            The color
    @param    x1                The x of the start point
     @param    y1                The y of the start point
    @param    x2                The x of the end point
    @param    y2                The y of the end point
    @param    width            The width of the line
    @param    arrow_height    The height of the arrow
    @param    arrow_width        The width of the base of the arrow
 */
void paint_arrow(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width, double arrow_height, double arrow_width);



void paint_hairpin(t_jgraphics* g, t_jrgba color, long cresc_or_dim, double xstart, double xend, double middley, double semiaperture, double width, double dash_lenght, double start_aperture_normalized);
void paint_polygon(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_polygon *poly);
void paint_beziercs(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_beziercs *bezier);



/**    Paint a play head.
    @ingroup                    paint
    @param    g                    The graphic context
    @param    color                The color of the playhead
    @param    playhead_x            The x position (pixel) for the playhead
    @param    playhead_y1            The starting y (pixel) of the playhead
    @param    playhead_y2            The ending y (pixel) of the playhead
    @param    width                The width of the playhead line
    @param    tip_size            The size of the upper and lower part of the playhead 
    @param    r_ob                The notation object
 */ 
void paint_playhead_line(t_jgraphics* g, t_jrgba color, double playhead_x, double playhead_y1, double playhead_y2, double width, double tip_size);




// COLOR UTILITIES 

/**    Builds a #t_jrgba color structure starting from separate rgba components 
     @ingroup    colors
     @param    r    The value of the red component (0 to 1)
    @param    g    The value of the green component (0 to 1)
    @param    b    The value of the blue component (0 to 1)
     @param    a    The value of the alpha component (0 = transparent to 1 = opaque)
    @return        The #t_jrgba structure corresponding to the desired color
 */ 
t_jrgba build_jrgba(double r, double g, double b, double a);


/**    Sets the rgba fields of a color in a #t_jrgba structure.
    @ingroup        colors
    @param    col        The color, as a #t_jrgba structure, in which the rgba fields need to be set.
    @param    r        The value of the red component (0 to 1)
    @param    g        The value of the green component (0 to 1)
    @param    b        The value of the blue component (0 to 1)
    @param    a        The value of the alpha component (0 = transparent to 1 = opaque)
 */ 
void set_jrgba(t_jrgba *col, double r, double g, double b, double a);


/**    Convert RGBA to HSLA color encoding.
    @ingroup        colors
    @param    color    The color in RGBA encoding
    @return            The color in HSLA encoding
 */ 
t_jhsla rgba_to_hsla(t_jrgba color);


/**    Convert HSLA to RGBA color encoding.
    @ingroup        colors
    @param    color    The color in HSLA encoding
    @return            The color in RGBA encoding
 */ 
t_jrgba hsla_to_rgba(t_jhsla color);


/**    Force all the rgba components to lie between 0 and 1 (in case they don't).
    @ingroup        colors
    @param    col        The color
 */ 
void assure_color_goodness(t_jrgba *color);


/**    Change the luminosity of a color, not strictly, only by multiplying rgb components by a given factor.
    @ingroup            colors
    @param    color        The starting color
    @param    factor        The factor for changing luminosity (>1: brighter, <1: darken)
    @return                The new color
*/ 
t_jrgba change_luminosity(t_jrgba color, double factor);


/**    Change the luminosity of a color, not strictly, only by adding to rgb components a given quantity.
    @ingroup            colors
     @param    color        The starting color
     @param    add            The quantity to add to rgb components (>0: brighter, <0: darken)
     @return                The new color
 */ 
t_jrgba add_luminosity(t_jrgba color, double add);


/**    Change the alpha component of a color
    @ingroup            colors
    @param    color        The starting color
    @param    new_alpha    The new alpha
    @return                The new color (having as alpha the new alpha)
 */ 
t_jrgba change_alpha(t_jrgba color, double new_alpha);


/**    Blend two colors via their alpha channel
    @ingroup            colors
    @param    color1        The first color
    @param    color2        The second color
    @return                The blended color
 */ 
t_jrgba color_alphablend(t_jrgba color1, t_jrgba color2);


/**    Get the grey color having rgb components equal to a given parameter (and alpha = 1) 
    @ingroup            colors
     @param    param        The value of r, g and b components (they'll be the same)
    @return                The grey color
 */ 
t_jrgba get_grey(double param);


/**    Get a grey color which is readable over a given background color.
    @ingroup            colors
    @param    color        The background color
    @param    grey_offset    The initial offset, conceived as the grey rgb components to be written on a white background (e.g. 0.2 means that on a white background will be used get_grey(0.2))
    @return                If the background color lightness is > 0.5, it returns get_grey(grey_offset), otherwise 1 - get_grey(grey_offset).
 */ 
t_jrgba get_grey_to_write_over_color(t_jrgba color, double grey_offset);


/**    Check if a given color is ok to write a text over a given other color. If this is not the case, corrects the initial color to a color assuring the correct readability
    @ingroup            colors
    @param    color        Pointer to the color to be checked for the text
    @param    color_to_write_on    Color of the background on which we have to write
 */ 
void correct_color_to_write_over_color(t_jrgba *color, t_jrgba color_to_write_on);


/**    Get a color as interpolation between two colors
    @ingroup            colors
     @param    color1        The first color
    @param    color2        The second color
    @param    parameter    The interpolation parameter (0 = first color, 1 = second color)
    @return                The interpolated color
 */ 
t_jrgba color_interp(t_jrgba color1, t_jrgba color2, double parameter);


/**    Convert a long number into a color, where the conversion table is a default bach conversion.
    (Use this function if you want to keep the 'compatibility' with standard bach colors, should they change in future)
    @ingroup            colors
     @param    value        The long value
    @return                The related color
 */ 
t_jrgba long_to_color(long value);


/**    Convert a double precision floating number into a color taken from a color spectrum.
    When <value> = <min>, the colour will be red = build_jrgba(1, 0, 0, 1), when <value> = <max> the colour will be either violet = build_jrgba(1, 0, 1, 1) in case
    <loop> is set to 0, or the starting red again, in case <loop> is set to true. When value is between min and max, colour will range inside the colourspectrum.
    Color are uniform linear interpolation (depending of the <value> position between <min> and <max>)
    build_jrgba(1, 0, 0, 1) -> build_jrgba(1, 1, 0, 1) -> build_jrgba(0, 1, 0, 1) -> build_jrgba(0, 1, 1, 1) -> build_jrgba(0, 0, 1, 1) -> build_jrgba(1, 0, 1, 1) 
    and ONLY in case <loop> is set to 1 this gets back to -> build_jrgba(1, 0, 0, 1).
    The cycle corresponds to: red -> yellow -> green -> light blue -> blue -> violed and ONLY in case <loop> = 1, this gets back to -> red.
     @ingroup            colors
     @param    value        The double precision value
     @param    min            The minimum value (corresponding to red = build_jrgba(1, 0, 0, 1))
    @param    max            The maximum value (corresponding either to the same red, after a complete loop red->green->blue->red, if <loop> = 1, or to violet = build_jrgba(1, 0, 1, 1), if <loop> = 0)
    @param    loop        Set to 0 if the ending point of the spectrum (when <val> = <max>) is violet = build_jrgba(1, 0, 1, 1); set to 1 if it spectrum goes back to red = build_jrgba(1, 0, 0, 1)
    @return                The color related to <value>
    @see                color_to_double()
 */ 
t_jrgba double_to_color(double value, double min, double max, char loop);


/**    Changes a color depending on a velocity, applying the velocity color scale.
    @ingroup            colors
    @param    color       Pointer to the color
    @param    velocity    The velocity
 */
void apply_velocity_colorscale(t_jrgba *color, double velocity);


/**    Changes a color depending on a velocity, applying the velocity color scale.
 @ingroup            colors
 @param    color       Pointer to the color
 @param    velocity    The velocity
 */
void apply_velocity_colorspectrum(t_jrgba *color, double velocity);


/**    Changes a color depending on a velocity, applying the velocity alpha scale.
    @ingroup            colors
    @param    color       Pointer to the color
    @param    velocity    The velocity
 */
void apply_velocity_alphascale(t_jrgba *color, double velocity);



/**    Convert a colour into a double. The color is first 01-normalized with get_01normalized_color() in order for it to surely have at least a 0 rgb component and
    a 1 rgb component; after this, we are sure that it lies in the spectrum given as output by double_to_color(). This function performs the inverse mapping 
    with respect to the double_to_color() function (so refer to it for more information about colour paths), and returns <min> when colour is red, and 
    <max> when colour is either violet (if <loop> is 0) or red again (if <loop> is 1).
    The cycle red -> yellow -> green -> light blue -> blue -> violed (and ONLY in case <loop> = 1) -> red, is linearly mapped to <min> -> <max>, and the 
    corresponding value is returned.
    @ingroup            colors
    @param    color        The color
    @param    min            The minimum value (corresponding to red = build_jrgba(1, 0, 0, 1))
    @param    max            The maximum value (corresponding either to the same red, after a complete loop red->green->blue->red, if <loop> = 1, or to violet = build_jrgba(1, 0, 1, 1), if <loop> = 0)
    @param    loop        Set to 0 if the ending point of the spectrum is violet; set to 1 if it spectrum goes back to red.
    @return                The value related to <color>
    @see                double_to_color()
 */ 
double color_to_double(t_jrgba color, double min, double max, char loop);


/**    Get the lightness value of a color, intended as the L component of a HSL representation. More precisely, L = (max(R,G,B) + min(R,G,B))/2.
    This value is then balanced via the alpha A value, and the lightness returned is L + (1 - A) * (1 - L).
    @ingroup            colors
    @param    color        The color
     @return                The lightness as (max(R,G,B) + min(R,G,B))/2  + (1 - A) * (1 - (max(R,G,B) + min(R,G,B))/2)
 */
double get_lightness(t_jrgba color);


/**    Perform a 1-normalization of a color: the color rgb components are linearly stretched in order for the biggest one to reach the value of 1.
    The result is a color surely having a 1 rgb component.
    @ingroup            colors
    @param    color        The original color
    @return                The corresponding color, surely having a 1 component.
    @see                get_0normalized_color()
 */
t_jrgba get_1normalized_color(t_jrgba color);


/**    Perform a 0-normalization of a color: the color rgb components are linearly stretched in order for the biggest one to stay fixed, and the smallest one
    to be reach the value of 0. The result is a color surely having a 0 rgb component.
    @ingroup            colors
    @param    color        The original color
    @return                The corresponding color, surely having a 0 component.
    @see                get_1normalized_color()
 */
t_jrgba get_0normalized_color(t_jrgba color);


/**    Perform a 1-normalization, followed by a 0-normalization of a color. The result is a color surely having a 0 rgb component and a 1 rgb component.
    Thus only 1 of the rgb component can lie in the middle of the [0, 1] interval.
    @ingroup            colors
    @param    color        The original color
    @return                The corresponding color, surely having a 0 component and a 1 component.
    @see                get_1normalized_color()
    @see                get_0normalized_color()
    @remark                This is a quick wrapper of get_1normalized_color() and get_0normalized_color()
 */
t_jrgba get_01normalized_color(t_jrgba color);


/**    Translate a color into its 0-1 normalized horizontal and vertical coordinates for a color picker. This is used to paint the color picker in #k_SLOT_TYPE_COLOR slots
    @ingroup            colors
    @param    color        The color
    @param    x_coord        Will be filled with the horizontal coordinate (0 to 1)
    @param    y_coord        Will be filled with the vertical coordinate (0 to 1)
    @return                1 if the color was black (and thus the <x_coord> has been filled with a default 0), 0 otherwise.
    @see                xy_coordinates_to_color()
 */
char get_color_xy_coordinates(t_jrgba color, double *x_coord, double *y_coord); // returns 0 if color is NOT black, 1 if colour is black (and thus x_coord is by convention 0)


/**    Translate the 0-1 normalized horizontal and vertical coordinates into a color, for a color picker. This is used to paint the color picker in #k_SLOT_TYPE_COLOR slots
    @ingroup                        colors
     @param    x_coord                    The horizontal coordinate (0 to 1)
    @param    y_coord                    The vertical coordinate (0 to 1)
    @param    toprightcornercolor        The color at the top-right corner of the color picker. At the left-right corner we consider to have the white, at the bottom the black.
    @return                            The color corresponding to the coordinates.
    @see                            get_color_xy_coordinates()
    @remark                            The output color alpha is the <toprightcornercolor> alpha.
 */
t_jrgba xy_coordinates_to_color(double x_coord, double y_coord, t_jrgba toprightcornercolor);


/**    Tell if two colors are the same (up to a certain threshold) 
    @ingroup        paint
    @param    color1    The first color
    @param    color2    The second color
    @param    epsilon    The threshold allowed
    @return            1 if all fields of the colors lie within a threshold of #epsilon (and so, roughly speaking, if #epsilon is small, the two colors coincide); 0 otherwise.
 */ 
char are_colors_equal(t_jrgba color1, t_jrgba color2, double epsilon);


/**    Build a #t_rect rectangle structure from the top-left corner, width and height 
    @ingroup        paint
    @param    x        The x of the top-left corner
    @param    y        The y of the top-left corner
    @param    width    The width of the rectangle
    @param    heigh    The height of the rectangle
    @return            The #t_rect structure
 */ 
t_rect build_rect(double x, double y, double width, double height);


/**    Build a #t_pt structure from the x and y values 
    @ingroup        paint
    @param    x        The x coordinate
    @param    y        The y coordinate
    @return            The #t_pt structure
 */ 
t_pt build_pt(double x, double y);


/**    Get the distance between two points 
    @ingroup        geometry
    @param    pt1        The first point
    @param    pt2    The second point
    @return            The distance between the two points
 */ 
double pt_pt_distance(t_pt pt1, t_pt pt2);


/**    Get the squared distance between two points 
    @ingroup        geometry
    @param    pt1        The first point
    @param    pt2    The second point
    @return            The distance between the two points
 */ 
double pt_pt_distance_squared(t_pt pt1, t_pt pt2);


/**    Get the norm of a point (as a vector), i.e. the distance of such point from the (0, 0) point
    @ingroup        geometry
    @param    pt        The point
    @return            The norm of the point
 */ 
double pt_norm(t_pt pt);


/**    Sum of two vectors (as #t_pt, component-wise)
    @ingroup        geometry
    @param    pt1        The first point
    @param    pt2        The second point
    @return            The sum component-wise
 */ 
t_pt pt_pt_sum(t_pt pt1, t_pt pt2);


/**    Difference of two vectors (as #t_pt, component-wise)
    @ingroup        geometry
     @param    pt1        The first vector
    @param    pt2        The second vector
    @return            The difference component-wise
 */ 
t_pt pt_pt_diff(t_pt pt1, t_pt pt2);


/**    Scalar product of two vectors (as #t_pt)
    @ingroup        geometry
    @param    pt1        The first vector
    @param    pt2        The second vector
    @return            The scalar product
 */
double pt_pt_scalarprod(t_pt pt1, t_pt pt2);


/**    Product of a vector (as #t_pt) and scalar, component-wise)
    @ingroup        geometry
    @param    point    The point
    @param    scalar    The scalar factor
    @return            The product of the vector and the scalar, component-wise
 */ 
t_pt pt_number_prod(t_pt point, double scalar);




// TEXT WRITING & typographical

#ifdef BACH_MAX

/**    Tell if a given font is installed in the system
    @ingroup                text_writing
    @param    font            The font name as symbol
    @return                    1 if the font is installed, 0 otherwise
*/
char is_font_installed(t_symbol *font);


/**    Write a given text in a graphic context.
    @ingroup                text_writing
    @param    g                The graphic context
    @param    jf                The font for writing
    @param    textcolor        The text color
    @param    text            The text as a string
    @param    x1                The x of the top-left corner of the text box
    @param    y1                The y of the top-left corner of the text box
    @param    width            The width of the text box in pixels
    @param    height            The height of the text box in pixels
    @param    justification    A combination of t_jgraphics_text_justification to specify the justification
    @param    single_line        Set this to 1 if you want the text to be displayed in a single line (also if the width is not enough to display it all),
                            set this to 0 if you allow the text to be wrapped in more than one line.
    @param    use_ellipsis    Set this to 1 if you want to use the "..." ellipsis when a word can't be completed because the box is too narrow 
                            (this is only accounted for if <single_line> = 1) 
 */ 
void write_text(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double width, double height, int justification, char single_line, char use_ellipsis);


/**    Convenience wrapper for writing left-aligned single-lined non-ellipsed text.
    @ingroup                text_writing
    @param    g                The graphic context
     @param    jf                The font for writing
     @param    textcolor        The text color
     @param    text            The text as a string
    @param    x1                The x of the top-left corner of the text box
    @param    y1                The y of the top-left corner of the text box
    @param    max_width        A maximale width of the text box in pixels (for safety, this can be more than the needed width)
    @param    max_height        A maximale height of the text box in pixels (for safety, this can be more than the needed height) 
    @see                    write_text()
 */ 
void write_text_simple(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height);


/**    Write a given text in a graphic context, but in vertical.
    @ingroup                text_writing
    @param    g                The graphic context
    @param    jf                The font for writing
    @param    textcolor        The text color
    @param    text            The text as a string
    @param    x1                The x of the top-left corner of the text box
    @param    y1                The y of the top-left corner of the text box
    @param    width            The width of the text box in pixels
    @param    height            The height of the text box in pixels
    @param    justification    A combination of t_jgraphics_text_justification to specify the justification
    @param    line_spacing    A factor for the line spacing (1. = default)
 */ 
void write_text_in_vertical(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double boxwidth, double boxheight, int justification, double line_spacing);




// private
void write_long_if_there_is_space(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, long num, char *unit, double x1, double y1, double width, double height, int justification);
void write_double_account_for_fixed_width(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, double num, char *unit, double x1, double y1, double width, double height, 
                                          int justification, long max_num_digits);

void paint_rect(t_jgraphics* g, t_rect *rect, t_jrgba *border_color, t_jrgba *fill_color, double border_width, double corner_roundness);
void paint_background(t_object *x, t_jgraphics *g, t_rect *rect, t_jrgba *fill_color, double corner_roundness);
void paint_border(t_object *x, t_jgraphics *g, t_rect *rect, t_jrgba *border_color, double border_size, double corner_roundness);



#endif

#ifdef BACH_JUCE
void write_text_simple(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height, const Justification& justificationFlags = Justification::topLeft);
void write_text(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height, const Justification& justificationFlags = Justification::topLeft, char single_line, char use_ellipsis);
char *charset_unicodetoutf8_debug(unicodeChar *uni, long len, long *outlen);
#endif




#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _BACH_GRAPHICS_H_
