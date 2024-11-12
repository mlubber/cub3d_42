/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/11/12 11:26:28 by mlubbers      ########   odam.nl         */
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
	bool	horizontal;
	bool	vertical;
}	t_ray;

typedef struct s_whole
{
	mlx_t			*mlx;
	mlx_image_t		*ray_image;
	mlx_image_t		*image;
	mlx_image_t		*line;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*ceiling;
	mlx_image_t		*ground;
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
	mlx_image_t		*square;
	mlx_texture_t	*texture;
	char			*cub_t_no;
	char			*cub_t_so;
	char			*cub_t_we;
	char			*cub_t_ea;
	char			*cub_color_f;
	char			*cub_color_c;
	uint32_t		c_hex;
	uint32_t		g_hex;
	int				empty_file;
	int				all_zeros;
	int				access_all_zeros;
	int				rows;
	int				number_of_line_before_map;
	int				column;
	double			player_x;
	double			player_y;
	double			player_x_start;
	double			player_y_start;
	int				width;
	int				height;
	char			player_dir;
	double			pa;
	double			pdx;
	double			pdy;
	bool			moved;
	int 			k;
	int				l;
	int				xo;
	int				yo;
	char			*given_map;
	t_map			*map;
	t_ray			*ray;
}					t_whole;

void		allocate_m_map(t_whole *whole, int i, char *line_to_free);
void		check_file(t_whole *whole, int i, int fd, char *line);

void		read_line_until_end(int fd);
void		ft_free_map_from_n(t_map *map, int line);
void		free_all(t_whole *whole, int exit_code);
void		print_error(t_whole *whole, char *str);
void		print_error_with_line(t_whole *whole, char *text, char *line);
int			is_white_space(char c);
int			check_is_already_saved(t_whole *whole, char *line, int i);
int			check_edges(t_whole *whole);
int			check_next_char(t_whole *whole, int y, int x, int direction);

void		call_check_map_and_result(t_whole *whole, int i, char *line);

void		print_map(t_whole *whole);
int			check_scenario(t_whole *whole, char *line, int fd);
int			process_element(t_whole *whole, char *line, int i, int fd);

int			hexconvert(t_whole *whole, int i, int r, int g);
char		*free_array(char **strlist);
int			check_split(char **split);

void		check_textures(t_whole *whole, char c);

// Init
int			init_window(t_whole *whole);

// Utils
void		put_player(void *param);
void		*ft_draw_rect(mlx_t *mlx, uint32_t width, uint32_t height,
				uint32_t color);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// Execute

void		ft_hook(void *param);
void		raycasting(t_whole *whole);
void		draw_ray(t_whole *whole, int i);

double		calculate_distance(double ax, double ay, double bx, double by);
void		change_degrees(t_whole *whole);
void		set_ray_to_draw(t_whole *whole);

#endif