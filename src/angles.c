#include "../include/main.h"

/**
 * deg - A function to convert a given value of either Gradients
 * or Radians to Degrees.
 *
 * @val: Value in Gradients or Radians
 * @format: 'g' for Gradient or 'r' for Radians
 * Return: Value in Degrees else -1
 */
double deg(float val, char format)
{
	if (format == 'g')
		val *= 0.9;
	else if (format == 'r')
		val = val * 180 / PI;
	else
		return (-1);

	return (val);
}

/**
 * grd - A function to convert a given value of either Degrees
 * or Radians to Gradients.
 *
 * @val: Value in Degrees or Radians
 * @format: 'd' for Degrees or 'r' for Radians
 * Return: Value in Gradients else -1
 */
double grd(float val, char format)
{
	if (format == 'd')
		val /= 0.9;
	else if (format == 'r')
		val = val * 200 / PI;
	else
		return (-1);

	return (val);
}

/**
 * rad - A function to convert a given value of either Degrees
 * or Gradients to Radians.
 *
 * @val: Value in Degrees or Gradients
 * @format: 'd' for Degrees or 'g' for Gradients
 * Return: Value in Radians else -1
 */
double rad(float val, char format)
{
	if (format == 'd')
		val = val * PI / 180;
	else if (format == 'g')
		val = val * PI / 200;
	else
		return (-1);

	return (val);
}
