/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 12:49:19 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/28 16:17:02 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	to_d(t_whole *whole)
{
	// if (whole->map->tiles[(int)(whole->y)][(int)(whole->x)].symbol == '1')
	// 	return ;
	whole->img_ea->instances[0].x += (int)whole->pdy;
	whole->img_ea->instances[0].y -= (int)whole->pdx;
	whole->x -= whole->pdy;
	whole->y -= whole->pdx;
	//whole->img_ea->instances[0].x += 20;
	//whole->x += 0.25;
	// printf("whole->y is %f\n", whole->y);
	// printf("whole->x is %f\n", whole->x);
	// if (whole->map->tiles[(int)(whole->y)][(int)(whole->x + 1)].symbol == '1')
	// 	return ;
	// whole->moves++;
	// whole->x += 0.25;
	// whole->img_ea->instances[0].x += 20;
	// if (!whole->flag)
	// {
	// 	whole->x = whole->x + 1;
	// 	whole->flag = 1;
	// }

	// whole->pa = whole->pa + 0.1;
	// if (whole->pa > (2 * PI))
	// 	whole->pa = whole->pa - (2 * PI);
	//printf("whole->pa is %f\n", whole->pa);
	// whole->pdx = cos(whole->pa) * 5;
	// whole->pdy = sin(whole->pa) * 5;
	//whole->x = whole->x + whole->pdx;
	// printf("whole->x is %f\n", whole->x);
	// printf("whole->x is %d\n", (int)(whole->x));
	// printf("whole->y is %f\n", whole->y);
	// printf("player pdx is (%f)\n", whole->pdx);
	// printf("player pdy is (%f)\n", whole->pdy);
}

void	to_a(t_whole *whole)
{
	// float	tempx;
	// float	tempy;

	// tempx = whole->x - whole->pdy;
	// tempy = whole->y - whole->pdx;
	// if (whole->map->tiles[(int)(tempy)][(int)(tempx)].symbol == '1')
	// 	return ;
	whole->img_ea->instances[0].x -= (int)whole->pdy;
	whole->img_ea->instances[0].y += (int)whole->pdx;
	whole->x -= whole->pdy;
	whole->y -= whole->pdx;
	//whole->img_ea->instances[0].x -= 20;
	//whole->x -= 0.25;
	// printf("whole->y is %f\n", whole->y);
	// printf("whole->x is %f\n", whole->x);
	// if (whole->map->tiles[(int)whole->y][(int)(whole->x - 0.25)].symbol == '1')
	// 	return ;
	// whole->moves++;
	// whole->img_ea->instances[0].x -= 20;
	// whole->x -= 0.25;
	// if (!whole->flag)
	// {
	// 	whole->x = whole->x - 1;
	// 	whole->flag = 1;
	// }
	// whole->pa = whole->pa - 0.1;
	// if (whole->pa < 0)
	// 	whole->pa = whole->pa + (2 * PI);
	// whole->pdx = cos(whole->pa) * 5;
	// whole->pdy = sin(whole->pa) * 5;

	
	//whole->x = whole->x - whole->pdx;
	//printf("whole->x is %f\n", whole->x);
}

void	to_w(t_whole *whole)
{

	// if (whole->map->tiles[(int)(whole->y)][(int)whole->x].symbol == '1')
	// 	return ;
	whole->img_ea->instances[0].x += (int)whole->pdx;
	whole->img_ea->instances[0].y += (int)whole->pdy;
	whole->x += whole->pdx;
	whole->y += whole->pdy;
	printf("whole->x is %f\n", whole->x);
	printf("whole->y is %f\n", whole->y);
	// printf("whole->y is %f\n", whole->y);
	// printf("whole->x is %f\n", whole->x);

	// float new_x;
	// float new_y;
	// if (!whole->flag)
	// {
	// 	whole->y = whole->y + 1;
	// 	whole->flag = 1;
	// }
	// new_x = whole->x + whole->pdx;
	// new_y = whole->y + whole->pdy;

	// whole->x = new_x;
	// whole->y = new_y;
	// printf("whole->x is %f\n", whole->x);
	// printf("whole->y is %f\n", whole->y);
}

void	to_s(t_whole *whole)
{
	// if (whole->map->tiles[(int)(whole->y)][(int)whole->x].symbol == '1')
	// 	return ;
	whole->img_ea->instances[0].x -= (int)whole->pdx;
	whole->img_ea->instances[0].y -= (int)whole->pdy;
	whole->x -= whole->pdx;
	whole->y -= whole->pdy;
	printf("whole->x is %f\n", whole->x);
	printf("whole->y is %f\n", whole->y);
	// printf("whole->y is %f\n", whole->y);
	// printf("whole->x is %f\n", whole->x);
	// float new_x;
	// float new_y;
	// if (!whole->flag)
	// {
	// 	whole->y = whole->y - 1;
	// 	whole->flag = 1;
	// }
	// new_x = whole->x - whole->pdx;
	// new_y = whole->y - whole->pdy;

	// whole->y = new_y;
	// whole->x = new_x;
	// printf("whole->x is %f\n", whole->x);
	// printf("whole->y is %f\n", whole->y);
}

void	breken_angle(t_whole *whole, int rechting)
{
	if (rechting > 0)
	{
		whole->pa = whole->pa + 0.1;
		if (whole->pa > (2 * PI))
			whole->pa = whole->pa - (2 * PI);
	}
	else
	{
		whole->pa = whole->pa - 0.1;
		if (whole->pa < 0)
			whole->pa = whole->pa + (2 * PI);
	}
	//printf("whole->pa is %f\n", whole->pa);
	whole->pdx = cos(whole->pa) * 5;
	whole->pdy = sin(whole->pa) * 5;
	//printf("whole->pdx is %f\n", whole->pdx);
	//printf("whole->pdy is %f\n", whole->pdy);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_whole		*whole;

	whole = param;
	// if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	// 	close_w(whole);
	printf("whole->x is %f\n", whole->x);
	printf("whole->y is %f\n", whole->y);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT))
		to_d(whole);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT))
		to_a(whole);
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT))
		to_w(whole);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT))
		to_s(whole);
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT))
		breken_angle(whole, -1);
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) || \
		(keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT))
		breken_angle(whole, 1);
}












// void	to_right(t_whole *whole)
// {
// 	int	len;

// 	if (whole->map->tiles[whole->y][whole->x + 1].symbol == '1')
// 		return ;
// 	whole->x += 1;
// 	whole->img_p->instances[0].x += 80;
// 	if (whole->map->tiles[whole->y][whole->x].symbol == 'E' || whole \
// 	->map->tiles[whole->y][whole->x].symbol == 'C')
// }

// void	to_left(t_whole *whole)
// {
// 	int	len;

// 	if (whole->map->tiles[whole->y][whole->x - 1].symbol == '1')
// 		return ;
// 	whole->img_p->instances[0].x -= 80;
// 	whole->x -= 1;
// 	if (whole->map->tiles[whole->y][whole->x].symbol == 'E' || whole \
// 	->map->tiles[whole->y][whole->x].symbol == 'C')
// }

// void	to_up(t_whole *whole)
// {
// 	int	len;

// 	if (whole->map->tiles[whole->y - 1][whole->x].symbol == '1')
// 		return ;
// 	whole->img_p->instances[0].y -= 80;
// 	whole->y -= 1;
// 	if (whole->map->tiles[whole->y][whole->x].symbol == 'E' || whole \
// 	->map->tiles[whole->y][whole->x].symbol == 'C')
// }

// void	to_down(t_whole *whole)
// {
// 	int	len;

// 	if (whole->map->tiles[whole->y + 1][whole->x].symbol == '1')
// 		return ;
// 	whole->img_p->instances[0].y += 80;
// 	whole->y += 1;
// 	if (whole->map->tiles[whole->y][whole->x].symbol == 'E' || whole \
// 	->map->tiles[whole->y][whole->x].symbol == 'C')
// }

// void	my_key_hook(mlx_key_data_t keydata, void *param)
// {
// 	t_whole		*whole;

// 	whole = param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		close_w(whole);
// 	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) || (\
// 	keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
// 		to_right(whole);
// 	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) || (\
// 	keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS))
// 		to_left(whole);
// 	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) || (\
// 	keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS))
// 		to_up(whole);
// 	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS) || (\
// 	keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS))
// 		to_down(whole);
// }