/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:43 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_int_len(unsigned int nb)
{
	unsigned int	index;

	index = 0;
	while (nb >= 10)
	{
		nb /= 10;
		index++;
	}
	return (index + 1);
}

int		is_structure_full(t_game *game)
{
	if (!game->map)
		return (0);
	if (!game->dim.x || !game->map->sky_color ||
		!game->map->floor_color || !game->map->tex.ea_tex ||
		!game->map->tex.no_tex || !game->map->tex.so_tex ||
		!game->map->tex.we_tex || !game->dim.y || game->map->floor_color == -1
		|| game->map->sky_color == -1)
		return (0);
	return (1);
}

char	*to_next_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c && *(str + 1))
			return (str + 1);
		str++;
	}
	return (NULL);
}

char	*get_val(char *line, char *key)
{
	char	*tmp;

	if (!key || !line)
		return (0);
	if ((tmp = ft_strnstr(line, key, ft_strlen(key))))
	{
		line = line + ft_strlen(key);
		while (*line == ' ')
			line++;
		return (line);
	}
	return (NULL);
}

int		get_resolution(t_game *game, char *line)
{
	char	*tmp;

	if (game->level > 0)
		return (1);
	if (!(tmp = get_val(line, "R ")))
		return (0);
	if (!(game->dim.x = ft_atoi(tmp)))
		return (0);
	tmp += get_int_len(game->dim.x);
	if (!(game->dim.y = ft_atoi(tmp)))
		return (0);
	if (game->dim.y >= MAX_HEIGHT)
		game->dim.y = MAX_HEIGHT;
	if (game->dim.x >= MAX_WIDTH)
		game->dim.x = MAX_WIDTH;
	if (game->dim.y <= MIN_HEIGHT)
		game->dim.y = MIN_HEIGHT;
	if (game->dim.x <= MIN_WIDTH)
		game->dim.x = MIN_WIDTH;
	return (1);
}
