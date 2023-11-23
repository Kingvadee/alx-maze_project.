#include "../include/main.h"

/**
 * rgba_color_add - A function to add 2 structs of type ColorRGBA together
 *
 * @color1: The 1st struct
 * @color2: The 2nd struct
 * Return: The sum struct of type ColorRGBA
 */
ColorRGBA rgba_color_add(ColorRGBA color1, ColorRGBA color2)
{
	ColorRGBA color;

	color.red = abs(color1.red + color2.red) % 255;
	color.green = abs(color1.green + color2.green) % 255;
	color.blue = abs(color1.blue + color2.blue) % 255;
	color.alpha = handle_mod1(color1.alpha + color2.alpha);
	return (color);
}

/**
 * rgba_color_sub - A function to subtract 2 structs of type ColorRGBA
 *
 * @color1: The 1st struct
 * @color2: The 2nd struct
 * Return: The difference struct of type ColorRGBA
 */
ColorRGBA rgba_color_sub(ColorRGBA color1, ColorRGBA color2)
{
	ColorRGBA color;

	color.red = abs(color1.red - color2.red) % 255;
	color.green = abs(color1.green - color2.green) % 255;
	color.blue = abs(color1.blue - color2.blue) % 255;
	color.alpha = handle_mod1(color1.alpha - color2.alpha);
	return (color);
}

/**
 * rgba_color_mul - A function to multiply 2 structs of type ColorRGBA together
 *
 * @color1: The 1st struct
 * @color2: The 2nd struct
 * Return: The product struct of type ColorRGBA
 */
ColorRGBA rgba_color_mul(ColorRGBA color1, ColorRGBA color2)
{
	ColorRGBA color;

	color.red = abs(color1.red * color2.red) % 255;
	color.green = abs(color1.green * color2.green) % 255;
	color.blue = abs(color1.blue * color2.blue) % 255;
	color.alpha = handle_mod1(color1.alpha * color2.alpha);
	return (color);
}

/**
 * rgba_color_div - A function to divide 2 structs of type ColorRGBA
 *
 * @color1: The 1st struct
 * @color2: The 2nd struct
 * Return: The quotient struct of type ColorRGBA
 */
ColorRGBA rgba_color_div(ColorRGBA color1, ColorRGBA color2)
{
	ColorRGBA color;

	color.red = abs(color1.red / color2.red) % 255;
	color.green = abs(color1.green / color2.green) % 255;
	color.blue = abs(color1.blue / color2.blue) % 255;
	color.alpha = handle_mod1(color1.alpha / color2.alpha);
	return (color);
}

/**
 * rgba_color_comp - A function to compare 2 structs of type ColorRGBA
 *
 * @color1: The 1st struct
 * @color2: The 2nd struct
 * Return: 1 if they are equal else -1
 */
int rgba_color_comp(ColorRGBA color1, ColorRGBA color2)
{
	if (!(color1.red == color2.red))
		return (-1);
	if (!(color1.green == color2.green))
		return (-1);
	if (!(color1.blue == color2.blue))
		return (-1);
	if (!(color1.alpha == color2.alpha))
		return (-1);
	return (1);
}
