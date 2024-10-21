/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 09:07:17 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/21 13:18:38 by adakheel      ########   odam.nl         */
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
	int				empty_file;
	int				all_zeros;
	int				access_all_zeros;
	int				map_lines;
	int				number_of_line_before_map;
	int				column;
	int				x;
	int				y;
	char			*given_map;
	t_map			*map;
	t_map_list		*list_clue;
}					t_whole;



void	allocate_m_map(t_whole *whole, int i, int old_fd);
void	check_file_cub(t_whole *whole, int i, int fd, char *line);
void	malloc_or_open_failed(t_whole *whole, int num);


void	ft_free_map_list_exit(t_whole *whole, char *str);
void	ft_free_map_exit(t_whole *whole, char *str);
void	just_exit(char *str);

void	read_line_until_end(int fd);
void	ft_free_map_from_n(t_map *map, int line);
void	free_all(t_whole *whole, int exit_code);
void	print_error(t_whole *whole, char *str);
void	print_error_with_line(t_whole *whole, char *text, char *line);
int		is_white_space(char c);
int		check_is_already_saved(t_whole *whole, char *line, int i);
int		check_edges(t_whole *whole);
int		check_next_char(t_whole *whole, int y, int x, int direction);

int		is_player_reach_everywhere(t_whole *whole);
void	call_check_map_and_check_result(t_whole *whole, int i);



#endif