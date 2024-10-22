/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/22 07:57:13 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1920
# define HEIGHT 1080

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
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;
	t_map		*map;
	char		*input_map;
	char		*ceiling_str;
	char		*floor_str;
	char		*no_str;
	char		*so_str;
	char		*we_str;
	char		*ea_str;
	uint32_t	c_hex;
	uint32_t	f_hex;
}	t_data;

// Init
int			init_window(t_data *data);
t_data		*malloc_struct(char *map);
void		init_struct(t_data *data);
void		check_file(t_data *data);

// Utils
void		error_exit(char *str);
void		check_extension(t_data *data);
int			is_whitespace(char c);
char		*free_array(char **strlist);

int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_randomize(void *param);
void		*ft_draw_rect(mlx_t *mlx, uint32_t width,
				uint32_t height, uint32_t color);

uint32_t	hexconvert(char *str);

void		malloc_or_open_failed(t_data *data, int num);
void		free_all(t_data *data, int exit_code);
#endif