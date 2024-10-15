/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/15 11:10:59 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 512
# define HEIGHT 512

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_data;

// Init
int			init_data(t_data *data);

// Utils
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_randomize(void *param);

#endif