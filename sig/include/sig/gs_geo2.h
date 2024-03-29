/*=======================================================================
   Copyright (c) 2018-2019 Marcelo Kallmann.
   This software is distributed under the Apache License, Version 2.0.
   All copies must contain the full copyright notice licence.txt located
   at the base folder of the distribution. 
  =======================================================================*/

/** \file gs_geo2.h 
 * 2d geometric primitives */

# ifndef GS_GEO2_H
# define GS_GEO2_H

# define GS_CCW(ax,ay,bx,by,cx,cy) (((ax-cx)*(by-cy))-((ay-cy)*(bx-cx)))
# define GS_CCWD(ax,ay,bx,by,cx,cy) (GS_CCW(double(ax),double(ay),double(bx),double(by),double(cx),double(cy)))

/*! Returns true if segments (p1,p2) and (p3,p4) intersect in one point, and false otherwise. */
bool gs_segments_intersect ( double p1x, double p1y, double p2x, double p2y,
							 double p3x, double p3y, double p4x, double p4y );

/*! Returns true if segments (p1,p2) and (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, q will be the intersection point. */
bool gs_segments_intersect ( double p1x, double p1y, double p2x, double p2y,
							 double p3x, double p3y, double p4x, double p4y,
							 double& qx, double &qy );

/*! Returns true if segments (p1,p2) and (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, q will be the intersection point and t will give (1-t)p1+(t)p2=q. */
bool gs_segments_intersect ( double p1x, double p1y, double p2x, double p2y,
							 double p3x, double p3y, double p4x, double p4y,
							 double& qx, double &qy, double& t );

/*! Returns true if segments (p1,p2) and (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, t will define the intersection point with (1-t)p1+(t)p2. */
bool gs_segments_intersect ( double p1x, double p1y, double p2x, double p2y,
							 double p3x, double p3y, double p4x, double p4y, double& t );

/*! Returns true if lines (p1,p2) and (p3,p4) intersect in one point, and false otherwise. */
bool gs_lines_intersect ( double p1x, double p1y, double p2x, double p2y,
						  double p3x, double p3y, double p4x, double p4y );

/*! Returns true if lines (p1,p2) and (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, q will be the intersection point. */
bool gs_lines_intersect ( double p1x, double p1y, double p2x, double p2y,
						  double p3x, double p3y, double p4x, double p4y,
						  double& qx, double &qy );

/*! Returns true if lines (p1,p2) and (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, q will be the intersection point and t will give (1-t)p1+(t)p2=q. */
bool gs_lines_intersect ( double p1x, double p1y, double p2x, double p2y,
						  double p3x, double p3y, double p4x, double p4y,
						  double& qx, double &qy, double& t );

/*! Returns true if segment (p1,p2) and line (p3,p4) intersect in one point, and false otherwise. 
	In case of intersection, q will be the intersection point. */
bool gs_segment_line_intersect ( double p1x, double p1y, double p2x, double p2y,
								 double p3x, double p3y, double p4x, double p4y,
								 double& qx, double &qy );

/*! Orthogonal projection of p in the line (p1,p2). The projected point becomes q. */
void gs_line_projection ( double p1x, double p1y, double p2x, double p2y,
						  double px, double py, double& qx, double& qy );

/*! Line projection also returning the parametric location t of the projected point. */
void gs_line_projection ( double p1x, double p1y, double p2x, double p2y,
						  double px, double py, double& qx, double& qy, double& t );

/*! Line projection only returning the parametric location t of the projected point. */
void gs_line_projection ( double p1x, double p1y, double p2x, double p2y,
						  double px, double py, double& t );

/*! Returns >0 if the orthogonal projection of p is inside (within epsilon distance)
	the segment (p1,p2), and 0 otherwise.
	In any case, the projected point on the line (p1,p2) is returned in q.
	If >0 is the result, the following code is returned:
	1: if point q is close to p1 within epsilon and outside (p1,p2),
	2: if q is close to p2 within epsilon and outside (p1,p2),
	3: if q is inside (or in the boundary of) (p1,p2). */
int gs_segment_projection ( double p1x, double p1y, double p2x, double p2y,
							double px, double py, double& qx, double& qy, double epsilon );

/*! Returns in q the closest point in segment (p1,p2) to p.
	Parametric location t : q=p1(1-t)+p2(t) is returned. */
double gs_project_to_segment ( double p1x, double p1y, double p2x, double p2y, 
							   double px, double py, double& qx, double& qy );

/*! Returns the distance between p1 and p2 */
double gs_dist ( double p1x, double p1y, double p2x, double p2y );

/*! Returns the square of the distance between p1 and p2 */
double gs_dist2 ( double p1x, double p1y, double p2x, double p2y );

/*! Assumes p is in segment p1,p2 and returns t such that p = (1-t)p1 + t p2 */
double gs_param ( double p1x, double p1y, double p2x, double p2y, double px, double py );

/*! Returns the angle in radians between the two vectors. The vectors may not be normalized */
double gs_angle ( double v1x, double v1y, double v2x, double v2y );

/*! Set the vector to have the new length, and return the old lenght. */
double gs_len ( double& vx, double& vy, double len );

/*! Returns the angle in radians between the two vectors, which are assumed to be normalized */
double gs_anglen ( double v1x, double v1y, double v2x, double v2y );

/*! Returns the minimum distance between p and segment (p1,p2) */
double gs_point_segment_dist ( double px, double py, 
							   double p1x, double p1y, double p2x, double p2y );

/*! Returns the square of the minimum distance between p and segment (p1,p2). */
double gs_point_segment_dist2 ( double px, double py,
								double p1x, double p1y, double p2x, double p2y );

/*! Same parameters as the previous function, but also returning parameter t,
	which will contain the parametric location of the closest point in the line
	passing by {p1,p2}, such that if t is in (0,1), the point is inside the segment,
	if t<=0 the closest point of the segment is p1, and if t>=1 it is p2. */
double gs_point_segment_dist2 ( double px, double py,
								double p1x, double p1y, double p2x, double p2y, double& t );

/*! Same parameters as the previous function, but also returning in q the projection point
	of point p in the line passing by {p1,p2} (not the segment). */
double gs_point_segment_dist2 ( double px, double py,
								double p1x, double p1y, double p2x, double p2y, 
								double& t, double& qx, double& qy );

/*! Returns the minimum distance between segment (p1,p2) and segment (p3,p4) */
double gs_segment_segment_dist ( double p1x, double p1y, double p2x, double p2y,
								 double p3x, double p3y, double p4x, double p4y );

/*! Returns the square of the minimum distance between segment (p1,p2) and segment (p3,p4) */
double gs_segment_segment_dist2 ( double p1x, double p1y, double p2x, double p2y,
								  double p3x, double p3y, double p4x, double p4y );

/*! Returns the minimum distance between p and line (p1,p2) */
double gs_point_line_dist ( double px, double py, double p1x, double p1y, double p2x, double p2y );

/*! Returns true if the distance between p1 and p2 is smaller (or equal) than epsilon */
bool gs_next ( double p1x, double p1y, double p2x, double p2y, double epsilon );

/*! Again checks the distance between p1 and p2, but now the square of epsilon is given */
bool gs_next2 ( double p1x, double p1y, double p2x, double p2y, double epsilon2 );

/*! Returns >0 if the three points are in counter-clockwise order, <0 if
	the order is clockwise and 0 if points are collinear. */
double gs_ccw ( double p1x, double p1y, double p2x, double p2y, double p3x, double p3y );

/*! Returns true if p is in the segment (p1,p2), within precision epsilon, and false
	otherwise. More precisely, true is returned if dist(p,(p1,p2))<=epsilon. */
bool gs_in_segment ( double p1x, double p1y, double p2x, double p2y,
					 double px, double py, double epsilon );

/*! Returns true if p is in the segment (p1,p2), within precision epsilon, and false
	otherwise. More precisely, true is returned if dist(p,(p1,p2))<=epsilon.
	Parameter dist2 always returns the square of that distance, and parameter t
	is always returned as the interpolation factor: p1(1-t)+p2(t)=proj(p,(p1,p2)). */
bool gs_in_segment ( double p1x, double p1y, double p2x, double p2y, double px, double py,
					 double epsilon, double& dist2, double& t );

/*! Returns true if p is inside (or in the border) of triangle (p1,p2,p3), otherwise false
	is returned. The test is based on 3 CCW>=0 tests and no epsilons are used. */
bool gs_in_triangle ( double p1x, double p1y, double p2x, double p2y, double p3x, double p3y,
					  double px, double py );

/*! Returns true if p is strictly inside of triangle (p1,p2,p3), otherwise false
	is returned. The test is based on 3 CCW>0 tests and no epsilons are used. */
bool gs_in_triangle_interior ( double p1x, double p1y, double p2x, double p2y, double p3x, double p3y,
							   double px, double py );

/*! Given point p=(px,py) and circle c=(cx,cy,r), returns the two tangent points 
    t1=(t1x,t1y) and t2=(t2x,t2y) passing trough p. The returned points will be such
    that: (p,c,t1) has CCW orientation and (p,c,t2) CW orientation.
    The scalar returned by the function is dist(p,t); -1 is returned in case of error. */
double gs_tangent ( double px, double py, double cx, double cy, double r, 
					double& t1x, double& t1y, double& t2x, double& t2y );

/*! Given circles c1=(c1x,c1y,r1) and c2=(c2x,c2y,r2) returns the two external tangent
    segments t12=(t1x,t1y;t2x,t2y) and t34=(t3x,t3y;t4x,t4y) such that:
    - t1 and t3 are tangents points on c1, and t2 and t4 on c2;
    - (c1,t1,c2) has CCW orientation and (c1,t3,c2) has CW orientation.
    The scalar returned by the function is the length of t12 and t34; -1 will be returned
    if the tangents could not be computed (for ex: if one circle contains the other). */
double gs_external_tangents ( double c1x, double c1y, double r1, double c2x, double c2y, double r2, 
							  double& t1x, double& t1y, double& t2x, double& t2y,
							  double& t3x, double& t3y, double& t4x, double& t4y );

/*! This function behaves exactly as gs_external_tangents() however it returns the
    internal tangents (not the external ones). */
double gs_internal_tangents ( double c1x, double c1y, double r1, double c2x, double c2y, double r2, 
							  double& t1x, double& t1y, double& t2x, double& t2y,
							  double& t3x, double& t3y, double& t4x, double& t4y );

//============================== end of file ===============================

# endif // GS_GEO2_H
