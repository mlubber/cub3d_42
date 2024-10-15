
#include "../../include/cub3d.h"

void	malloc_failed(t_whole *whole)
{
	printf("Error, malloc failed");
	// free everything 
	//exit 
	free(whole);
	exit(1);
}

void	print_error(t_whole *whole, char *text, char *line)
{
	char	*to_print;

	to_print = NULL;
	if (!line)
		to_print = text;
	else
	{
		to_print = ft_strjoin(text, line);
		if (!to_print && errno == 12)
			malloc_failed(whole);
	}
	printf("%s", to_print);
	free(to_print);
}

int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}


int	save_line_in_whole(char **which, char *line, int i)
{
	int	newi;

	while (line[i] && is_white_space(line[i]))
		i++;
	newi = i;
	while (line[newi] && !is_white_space(line[newi]) && line[newi] != '\n')
		newi++;
	*which = ft_substr(line, i, newi - i);
	return (0);
}


int	check_scenario(t_whole *whole, char *line, int fd)
{
	int	i;

	if (whole->cub_color_C && whole->cub_color_F && whole->cub_t_EA && \
		whole->cub_t_NO && whole->cub_t_SO && whole->cub_t_WE)
	{
		i = 1;
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			i++;
		}
		whole->map_lines = i;
		printf("lines are equal to (%d)\n", whole->map_lines);
		allocate_m_map(whole);
	}
	else
	{
		print_error(whole, "Error, line is not matched with any of elements : ", line);
		return (1);
	}
	return (0);
}

int	check_is_already_saved(t_whole *whole, char *line, int i)
{
	char	*sub;

	sub = ft_substr(line, 0, 3);
	if (!ft_strncmp(sub, "NO ", 3))
	{
		free(sub);
		if (whole->cub_t_NO == NULL)
			return (save_line_in_whole(&whole->cub_t_NO, line, i + 2));
		return (2);
	}
	if (!ft_strncmp(sub, "SO ", 3))
	{
		free(sub);
		if (whole->cub_t_SO == NULL)
			return (save_line_in_whole(&whole->cub_t_SO, line, i + 2));
		return (2);
	}
	if (!ft_strncmp(sub, "WE ", 3))
	{
		free(sub);
		if (whole->cub_t_WE == NULL)
			return (save_line_in_whole(&whole->cub_t_WE, line, i + 2));
		return (2);
	}
	if (!ft_strncmp(sub, "EA ", 3))
	{
		free(sub);
		if (whole->cub_t_EA == NULL)
			return (save_line_in_whole(&whole->cub_t_EA, line, i + 2));
		return (2);
	}
	if (sub)
		free(sub);
	sub = ft_substr(line, 0, 2);
	if (!ft_strncmp(sub, "F ", 2))
	{
		free(sub);
		if (whole->cub_color_F == NULL)
			return (save_line_in_whole(&whole->cub_color_F, line, i + 2));
		return (2);
	}
	if (!ft_strncmp(sub, "C ", 2))
	{
		free(sub);
		if (whole->cub_color_C == NULL)
			return (save_line_in_whole(&whole->cub_color_C, line, i + 2));
		return (2);
	}
	free(sub);
	return (1);
}


int check_file_cub(t_whole *whole)
{
	char	*line;
	int		fd;
	int		i;
	int		result;

	line = NULL;
	whole->number_of_line_before_map = -1;
	fd = open(whole->given_map, O_RDONLY);
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		whole->number_of_line_before_map++;
		while (line[i] && is_white_space(line[i]) && line[i] != '\n')
			i++;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
			{
				result = check_is_already_saved(whole, &line[i], i);
				if (result == 1)
				{
					print_error(whole, "Error, the key of line is not matched with any of elements : ", line);
					return (1);
					// its have tp free everything also
				}
				else if (result == 2)
				{
					print_error(whole, "Error, this key of line is duplicate!: ", line);
					return (1);
				}
				break ;
			}
			else
			{
				printf("number of lines before map (%d)\n", whole->number_of_line_before_map);
				if (check_scenario(whole, line, fd))
					return (1);
			}
			break ;
		}
		free(line);
	}
	close(fd);
	printf("NO is (%s)\n", whole->cub_t_NO);
	return (0);
}


// int	check_is_already_saved2(t_whole *whole, char *line, int i)
// {
// 	if ((line[i] == 'E' && line[i + 1] == 'A'))
// 	{
// 		if (whole->cub_t_EA == NULL)
// 			return (save_line_in_whole(&whole->cub_t_EA, line, i + 2));
// 		return (1);
// 	}
// 	if (line[i] == 'F')
// 	{
// 		if (whole->cub_color_F == NULL)
// 			return (save_line_in_whole(&whole->cub_color_F, line, i + 1));
// 		return (1);
// 	}
// 	if (line[i] == 'C')
// 	{
// 		if (whole->cub_color_C == NULL)
// 			return (save_line_in_whole(&whole->cub_color_C, line, i + 1));
// 		return (1);
// 	}
// 	return (2);
// }

// int	check_is_already_saved(t_whole *whole, char *line, int i)
// {
// 	if ((line[i] == 'N' && line[i + 1] == 'O'))
// 	{
// 		if (whole->cub_t_NO == NULL)
// 			return (save_line_in_whole(&whole->cub_t_NO, line, i + 2));
// 		return (1);
// 	}
// 	if ((line[i] == 'S' && line[i + 1] == 'O'))
// 	{
// 		if (whole->cub_t_SO == NULL)
// 			return (save_line_in_whole(&whole->cub_t_SO, line, i + 2));
// 		return (1);
// 	}
// 	if ((line[i] == 'W' && line[i + 1] == 'E'))
// 	{
// 		if (whole->cub_t_WE == NULL)
// 			return (save_line_in_whole(&whole->cub_t_WE, line, i + 2));
// 		return (1);
// 	}
// 	else
// 		return (check_is_already_saved2(whole, line, i));
// 	return (0);
// }

// int check_file_cub(t_whole *whole)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;
// 	int		result;

// 	line = NULL;
// 	whole->number_of_line_before_map = -1;
// 	fd = open(whole->given_map, O_RDONLY);
// 	while (1)
// 	{
// 		i = 0;
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		whole->number_of_line_before_map++;
// 		while (line[i] && is_white_space(line[i]) && line[i] != '\n')
// 			i++;
// 		while (line[i] && line[i] != '\n')
// 		{
// 			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
// 			{
// 				result = check_is_already_saved(whole, &line[i], i);
// 				if (result == 1)
// 				{
// 					print_error(whole, "Error, this key of line is duplicate!: ", line);
// 					return (1);
// 					// its have tp free everything also
// 				}
// 				else if (result == 2)
// 				{
// 					print_error(whole, "Error, the key of line is not matched with any of elements : ", line);
// 					return (1);
// 				}
// 				break ;
// 			}
// 			else
// 			{
// 				printf("number of lines before map (%d)\n", whole->number_of_line_before_map);
// 				if (check_scenario(whole, line, fd))
// 					return (1);
// 			}
// 			break ;
// 		}
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }