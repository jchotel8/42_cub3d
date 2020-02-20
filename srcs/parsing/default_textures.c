/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:26 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_default_textures(t_game *game)
{
	if (!(load_tex(game, &game->map->tex.lu_tex, LU_DEFAULT_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.do_tex, DO_DEFAULT_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.li_tex, LI_DEFAULT_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.co_tex, CO_DEFAULT_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.m_enter_tex, M_ENTER_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.m_g_o_tex, M_GAME_OVER_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.m_n_tex, M_NAME_TEX)))
		return (0);
	if (!(load_tex(game, &game->map->tex.logo_tex, M_LOGO_TEX)))
		return (0);
	return (1);
}
