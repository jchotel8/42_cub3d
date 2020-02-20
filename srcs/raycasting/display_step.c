/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:31:17 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		put_image_screen(t_game *game, t_image *image, t_vector pos, float k)
{
	put_image_to_image(game->image, image, vec(pos.x - (float)image->w * k / 2,
			pos.y - (float)image->h * k / 2), k);
	return (1);
}

void	display_step(t_game *game)
{
	if (game->step == STEP_START)
	{
		display_rec_deg(game, form(vec(0, 0), vec(game->dim.x, game->dim.y),
				0x04003F), 0, 0x872984);
		put_image_screen(game, game->map->tex.logo_tex, vec(game->dim.x / 2,
			game->dim.y / 2), 0.4f * (float)game->dim.x / (float)game->dim.y);
		put_image_screen(game, game->map->tex.m_enter_tex, vec(game->dim.x / 2,
			90.0f * (float)game->dim.y / 100.0f), (1.2f) * (float)game->dim.x
				/ (float)game->dim.y);
		put_image_screen(game, game->map->tex.m_n_tex, vec(game->dim.x / 2,
				29 * (float)game->dim.y / 30), (0.5f) * (float)game->dim.x
				/ (float)game->dim.y);
	}
	else if (game->step == STEP_END)
	{
		display_rec_deg(game, form(vec(0, 0), vec(game->dim.x, game->dim.y),
				0x872984), 0, 0x04003F);
		put_image_screen(game, game->map->tex.m_g_o_tex, vec(game->dim.x / 2,
		(float)game->dim.y / 2), (5.0f) * (float)game->dim.x /
		(float)game->dim.y);
		put_image_screen(game, game->map->tex.m_n_tex, vec(game->dim.x / 2,
				29 * (float)game->dim.y / 30), (0.5f) * (float)game->dim.x /
				(float)game->dim.y);
	}
}
