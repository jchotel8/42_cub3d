/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:36 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		fill_temp_map(t_map *map, char *line, char **temp)
{
	if (!((*temp) = ft_strnew(ft_strlen(map->map[0]) + ft_strlen(line) + 1)))
		return (0);
	(*temp) = ft_strncat((*temp), map->map[0], ft_strlen(map->map[0]));
	(*temp) = ft_strncat((*temp), "\n", 1);
	(*temp) = ft_strncat((*temp), line, ft_strlen(line));
	free_entire_map(map->map);
	if (!(map->map = malloc(sizeof(char *) * 2)))
		return (0);
	map->map[0] = ft_strdup(*temp);
	map->map[1] = NULL;
	free((*temp));
	return (1);
}

int		get_map(t_game *game, char *line, int *map_end)
{
	char	*temp;

	temp = NULL;
	if (!remove_spaces(&line))
		return (0);
	if (ft_stronly("1", line) && game->map->map)
		*map_end = 1;
	if (game->map->map == NULL)
	{
		if (!(game->map->map = malloc(sizeof(char *) * 2)))
			return (0);
		game->map->map[0] = ft_strdup(line);
		game->map->map[1] = NULL;
		return (1);
	}
	if (!(fill_temp_map((t_map *)game->map, line, &temp)))
		return (0);
	return (1);
}

int		fill_the_map(t_game *game, char *line, int *tc, int *map_end)
{
	if (!ft_strncmp(line, "R ", 2))
		return (get_resolution(game, line));
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "S ", 2) || !ft_strncmp(line, "LU ", 3)
		|| !ft_strncmp(line, "LI ", 3) || !ft_strncmp(line, "CO ", 3)
		|| !ft_strncmp(line, "DO ", 3))
		return (get_texture(game, line, tc));
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "F ", 2))
		return (get_color(game, line, line[0]));
	else if (ft_strlen(line) > 0 && line[0] == '1')
		return (get_map(game, line, map_end));
	else
		return (game->map->map && (*map_end) == 0 ? 0 : 1);
}

int		read_map(t_game *game, int fd)
{
	char	*line;
	int		continue_read;
	int		tc;
	int		map_end;

	continue_read = 1;
	tc = 0;
	map_end = 0;
	if (!load_nbrs(game))
		return (0);
	game->map->map = NULL;
	while (get_next_line(fd, &line))
	{
		continue_read = fill_the_map(game, line, &tc, &map_end);
		free(line);
		if (!continue_read)
			return (0);
	}
	fill_the_map(game, line, &tc, &map_end);
	free(line);
	close(fd);
	if (tc < 5)
		return (0);
	return (1);
}

int		parse_map(t_game *game, char *map_name)
{
	int		fd;
	char	*tmp;

	if (ft_strlen(map_name) < 4 && ft_strcmp(map_name + ft_strlen(map_name) - 4,
			".cub") != 0)
		return (0);
	if (!load_default_textures(game) || (fd = open(map_name, O_RDONLY)) == -1)
		return (0);
	game->map->floor_color = -1;
	game->map->sky_color = -1;
	if (!read_map(game, fd) || !game->map->map)
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(game->map->map[0]))))
		fnq(free_entire_map, (void *)game->map->map, EXIT_FAILURE,
				MSG_MAP_ERROR);
	ft_strcpy(tmp, game->map->map[0]);
	free_entire_map(game->map->map);
	if (!(game->map->map = ft_split(tmp, "\n")))
		fnq(free, (void *)tmp, EXIT_FAILURE, MSG_MAP_ERROR);
	free(tmp);
	if (!valid_map(game) || !is_structure_full(game))
		return (0);
	game->p.vision = game->dim.y / 2;
	game->angle = 17.0 * game->dim.x / (game->dim.y);
	return (1);
}
