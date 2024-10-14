/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/14 10:17:35 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <memory.h>
# include <inttypes.h>
# include <stdarg.h>
# include <sys/time.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/include/libft.h"
# include "../libraries/libft/include/get_next_line.h"

typedef struct s_tile
{
	char	symbol;
}			t_tile;

typedef struct s_map
{
	t_tile	**tiles;
}			t_map;

typedef struct s_map_list
{
	int				x;
	int				y;
	int				instance;
	struct s_map_list	*next;
}			t_map_list;

typedef struct s_connect
{
	char			*cub_t_NO;
	char			*cub_t_SO;
	char			*cub_t_WE;
	char			*cub_t_EA;
	char			*cub_color_F;
	char			*cub_color_C;
	int				p;
	int				e;
	int				line;
	int				map_lines;
	int				number_of_line_before_map;
	int				column;
	int				access_coins;
	int				access_exit;
	int				x;
	int				y;
	int				total_coins;
	int				collected;
	int				moves;
	char			*given_map;
	mlx_t			*mlx;
	mlx_texture_t	*my_t_p;
	mlx_texture_t	*my_t_p_01;
	mlx_texture_t	*my_t_p_02;
	mlx_texture_t	*my_t_e;
	mlx_texture_t	*my_t_b;
	mlx_texture_t	*my_t_w;
	mlx_texture_t	*my_t_c;
	mlx_image_t		*img_p;
	mlx_image_t		*img_p_01;
	mlx_image_t		*img_p_02;
	mlx_image_t		*img_e;
	mlx_image_t		*img_b;
	mlx_image_t		*img_w;
	mlx_image_t		*img_c;
	mlx_image_t		*img_str;
	t_map			*map;
	t_map_list			*list_clue;
}					t_whole;



void	allocate_m_map(t_whole *whole);
int		check_file_cub(t_whole *whole);
void	ft_free_map_list_exit(t_whole *whole, char *str);
void	ft_free_map_exit(t_whole *whole, char *str);
void	ft_free_exit(t_whole *whole, char *str);



#endif