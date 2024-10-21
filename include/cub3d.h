/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 07:01:53 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 512
# define HEIGHT 512

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/include/libft.h"
# include "../libraries/libft/include/get_next_line.h"

typedef struct s_tile
{
	char	symbol;
}	t_tile;

typedef struct s_map
{
	t_tile	**tiles;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	char		*input_map;
}	t_data;

// Init
int			init_data(t_data *data);
t_data		*init_struct(char *map);
void		check_file(t_data *data);

// Utils
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_randomize(void *param);
void		error_exit(char *str);
void		check_extension(t_data *data);
int			is_whitespace(char c);

#endif