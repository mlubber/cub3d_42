/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/12 14:48:17 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TILE 64
# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265359
# define P2 1.57079632679
# define P3	4.71238898038
# define DR 0.0174533
# define SPEED 5

# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
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

typedef struct s_ray
{
	double	h_tan;
	double	v_tan;
	double	h_ry;
	double	h_rx;
	double	v_ry;
	double	v_rx;
	double	h_yo;
	double	h_xo;
	double	v_yo;
	double	v_xo;
	double	h_dist;
	double	v_dist;
	double	ra;
	double	ry;
	double	rx;
	double	r_dist;
	bool	horizonal;
	bool	vertical;
}	t_ray;

typedef struct s_whole
{
	mlx_t			*mlx;
	mlx_image_t		*ray_image;
	mlx_image_t		*image;
	mlx_image_t		*ceiling;
	mlx_image_t		*ground;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*which_texture;
	uint32_t		color;
	uint32_t		c_hex;
	uint32_t		g_hex;
	double			scale;
	double			player_x;
	double			player_y;
	double			pa;
	double			pdx;
	double			pdy;
	char			player_dir;
	char			*cub_t_no;
	char			*cub_t_so;
	char			*cub_t_we;
	char			*cub_t_ea;
	char			*cub_color_f;
	char			*cub_color_c;
	char			*given_map;
	int				wall_height;
	int				empty_file;
	int				rows;
	int				number_of_line_before_map;
	int				column;
	int				width;
	int				height;
	bool			moved;
	int				xo;
	int				yo;
	t_map			*map;
	t_ray			*ray;
}					t_whole;

// Execution

void		draw_texture(t_whole *whole, int start_x);

void		ft_hook(void *param);

void		raycasting(t_whole *whole);

void		set_ray_to_draw(t_whole *whole);
void		change_degrees(t_whole *whole);
double		calculate_distance(double ax, double ay, double bx, double by);

// Init

int			init_window(t_whole *whole);
int			error_close_window(t_whole *whole);

// Parsing

void		check_name_extension(t_whole *whole);
void		check_file(t_whole *whole, int i, int fd, char *line);

int			check_scenario(t_whole *whole, char *line, int fd);

int			hexconvert(t_whole *whole, int i, int r, int g);

void		allocate_m_map(t_whole *whole, int i, char *line_to_free);

void		call_check_map_and_result(t_whole *whole, int i, char *line);

int			check_next_char(t_whole *whole, int y, int x, int direction);
int			check_edges(t_whole *whole);

int			process_element(t_whole *whole, char *line, int i, int fd);
int			is_white_space(char c);

// Utils

void		free_all(t_whole *whole, int exit_code);
void		print_error_with_line(t_whole *whole, char *text, char *line);

void		print_error(t_whole *whole, char *str);
int			check_split(char **split);
void		free_array(char **strlist);
void		read_line_until_end(int fd);
void		ft_free_map_from_n(t_map *map, int line);

#endif