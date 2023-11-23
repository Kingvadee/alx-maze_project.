#ifndef _APPLIED_MATH_H_
#define _APPLIED_MATH_H_

#include <math.h>

/* PI = 3.14159265358979323846 */
#define PI M_PI

/* CONVERSION OF ANGLES */
double deg(float val, char format);
double grd(float val, char format);
double rad(float val, char format);
float handle_mod1(float target);

#endif /* _APPLIED_MATH_H_ */
