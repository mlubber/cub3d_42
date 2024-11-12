/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 13:26:14 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/12 14:49:53 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	to_hex_digit(int value)
{
	if (value < 10)
		return ('0' + value);
	else
		return ('A' + (value - 10));
}

static uint32_t	hex_char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (0);
}

static uint32_t	hex_str_to_uint32(const char *hexStr)
{
	uint32_t	result;
	int			i;
	uint32_t	cur_hex_val;

	result = 0;
	i = 0;
	if (hexStr[0] == '0' && (hexStr[1] == 'x' || hexStr[1] == 'X'))
	{
		i = 2;
	}
	while (hexStr[i] != '\0')
	{
		cur_hex_val = hex_char_to_value(hexStr[i]);
		result = result * 16;
		result = result + cur_hex_val;
		i++;
	}
	return (result);
}

static void	rgb_to_hex(int r, int g, int b, char hex[11])
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	hex[0] = '0';
	hex[1] = 'x';
	hex[2] = to_hex_digit(r / 16);
	hex[3] = to_hex_digit(r % 16);
	hex[4] = to_hex_digit(g / 16);
	hex[5] = to_hex_digit(g % 16);
	hex[6] = to_hex_digit(b / 16);
	hex[7] = to_hex_digit(b % 16);
	hex[8] = 'F';
	hex[9] = 'F';
	hex[10] = '\0';
}

uint32_t	hexconvert(char *str)
{
	char		**rgb;
	int			r;
	int			g;
	int			b;
	char		hex[11];

	rgb = ft_split(str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	rgb_to_hex(r, g, b, hex);
	return (hex_str_to_uint32(hex));
}
