/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:30 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		free_and_return(void *allocated, int ret)
{
	free(allocated);
	return (ret);
}

void	free_entire_map(void *mem)
{
	int		i;
	char	**str;

	str = (char **)mem;
	i = 0;
	while (str[i])
	{
		ft_bzero(str[i], ft_strlen(str[i]));
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int		free_entire_parsing(t_game *game)
{
	int	index;

	index = 0;
	free_entire_map(game->map->map);
	free(game->map->tex.no_tex);
	free(game->map->tex.so_tex);
	free(game->map->tex.we_tex);
	free(game->map->tex.ea_tex);
	free(game->map->tex.sp_tex);
	free(game->map->tex.li_tex);
	free(game->map->tex.do_tex);
	free(game->map->tex.co_tex);
	free(game->map->tex.lu_tex);
	free(game->map->tex.m_enter_tex);
	free(game->map->tex.m_g_o_tex);
	free(game->map->tex.logo_tex);
	free(game->map->tex.m_n_tex);
	while (index < 10)
		free(game->map->tex.nbrs[index++]);
	free(game->map->tex.nbrs);
	init_tex(game);
	return (1);
}
