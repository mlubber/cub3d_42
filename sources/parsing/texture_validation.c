/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_validation.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: adakheel <adakheel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/24 10:25:59 by adakheel      #+#    #+#                 */
/*   Updated: 2024/10/28 08:03:40 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	expand_tilde(t_whole *whole, char **path, char **envp, int i)
{
	char	*home;
	char	*expand;

	while (envp && envp[i])
	{
		if (!ft_strncmp("HOME=", envp[i], 5))
			break ;
		i++;
	}
	home = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	if (!home)
		print_error(whole, "malloc");
	expand = ft_strjoin(home, *path + 1);
	if (!expand)
	{
		free(home);
		print_error(whole, "malloc");
	}
	free(*path);
	free(home);
	*path = expand;
}

void	make_sub(t_whole *whole, char **path)
{
	char	*new;

	new = ft_substr(*path, 1, ft_strlen(*path));
	if (!new)
		print_error(whole, "malloc");
	free(*path);
	*path = new;
}

void	check_first_char_path(t_whole *whole, char **envp)
{
	if (whole->cub_t_ea[0] == '.')
		make_sub(whole, &whole->cub_t_ea);
	if (whole->cub_t_so[0] == '.')
		make_sub(whole, &whole->cub_t_so);
	if (whole->cub_t_no[0] == '.')
		make_sub(whole, &whole->cub_t_no);
	if (whole->cub_t_we[0] == '.')
		make_sub(whole, &whole->cub_t_we);
	if (whole->cub_t_ea[0] == '~')
		expand_tilde(whole, &whole->cub_t_ea, envp, 0);
	if (whole->cub_t_so[0] == '~')
		expand_tilde(whole, &whole->cub_t_so, envp, 0);
	if (whole->cub_t_no[0] == '~')
		expand_tilde(whole, &whole->cub_t_no, envp, 0);
	if (whole->cub_t_we[0] == '~')
		expand_tilde(whole, &whole->cub_t_we, envp, 0);		
}

void	check_texture_path(t_whole *whole, char **envp)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	check_first_char_path(whole, envp);
	fd1 = open(whole->cub_t_ea, O_RDONLY);
	fd2 = open(whole->cub_t_no, O_RDONLY);
	fd3 = open(whole->cub_t_so, O_RDONLY);
	fd4 = open(whole->cub_t_we, O_RDONLY);

	printf("texture is (%s)\n", whole->cub_t_ea);
	printf("texture is (%s)\n", whole->cub_t_no);
	printf("texture is (%s)\n", whole->cub_t_so);
	printf("texture is (%s)\n", whole->cub_t_we);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		print_error(whole, "open texture");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}
