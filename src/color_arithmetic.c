#include "../include/main.h"

/**
 * handle_mod1 - Function to handle modulo operations by 1
 *
 * @target: The target of the modulo operation
 * Return: Float value of the operation
 */
float handle_mod1(float target)
{
	if (target >= 1.0)
		return (target - (fabs(target)));
	else if (target <= -1.0)
		return (target + (fabs(target)) + 1);
	else
		return (target);
}

/**
 * rgba_add - A function to add given values to the RGB and A of color
 *
 * @color: The struct of the target color
 * @n: An integer to be added to the Red, Green, and Blue values of color
 * @a: A float value to be added to the Alpha value of color
 */
void rgba_add(ColorRGBA *color, int n, float a)
{
	color->red = abs(color->red + n) % 255;
	color->green = abs(color->green + n) % 255;
	color->blue = abs(color->blue + n) % 255;
	color->alpha = color->alpha + a;
	color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_sub - A function to subtract given values from the RGB and A of color
 *
 * @color: The struct of the target color
 * @n: An integer to be subtracted from the RGB values of color
 * @a: A float value to be subtracted from the Alpha value of color
 */
void rgba_sub(ColorRGBA *color, int n, float a)
{
	color->red = abs(color->red - n) % 255;
	color->green = abs(color->green - n) % 255;
	color->blue = abs(color->blue - n) % 255;
	color->alpha = color->alpha - a;
	color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_mul - A function to multiply RGB and A by given values
 *
 * @color: The struct of the target color
 * @n: An integer to multiply with the Red, Green, and Blue values of color
 * @a: A float value to multiply with the Alpha value of color
 */
void rgba_mul(ColorRGBA *color, int n, float a)
{
	color->red = abs(color->red * n) % 255;
	color->green = abs(color->green * n) % 255;
	color->blue = abs(color->blue * n) % 255;
	color->alpha = color->alpha * a;
	color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_div - A function to divide RGB and A by given values
 *
 * @color: The struct of the target color
 * @n: An integer to divide the Red, Green, and Blue values of color with
 * @a: A float value to divide the Alpha value of color with
 */
void rgba_div(ColorRGBA *color, int n, float a)
{
	color->red = abs(color->red / n) % 255;
	color->green = abs(color->green / n) % 255;
	color->blue = abs(color->blue / n) % 255;
	color->alpha = color->alpha / a;
	color->alpha = handle_mod1(color->alpha);
}
