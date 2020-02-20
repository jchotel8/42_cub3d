/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:31:34 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_player	init_player(void)
{
	t_player	player;

	player.rot_speed = 5;
	player.speed = 0.4;
	player.health = 100;
	player.size = 1;
	player.coins = 0;
	player.vision = 0;
	return (player);
}

void		reinit_player(t_game *game)
{
	game->p.pos = game->map->spawn;
	game->p.yaw = game->map->spawn_yaw;
	game->p.vision = game->dim.y / 2;
	game->p.health = 100;
	game->p.coins = 0;
}

int			init_ray(t_ray *ray, float teta)
{
	ray->alpha = (teta / 360.0) * (float)(2 * M_PI);
	ray->cos = cos(ray->alpha);
	ray->sin = sin(ray->alpha);
	ray->tan = tan(ray->alpha);
	clear_sprites(ray->sprites, 9);
	return (1);
}

t_game		*init_game(int nb_level, char **av)
{
	t_game	*game;

	if (!(game = malloc(sizeof(struct s_game))))
		return (NULL);
	if (!(game->map = malloc(sizeof(struct s_map))))
		return (NULL);
	init_tex(game);
	game->p = init_player();
	game->level = 0;
	game->total_level = 0;
	game->dim.y = 0;
	game->dim.x = 0;
	game->step = STEP_START;
	game->disable_map = 0;
	game->disable_bonus = 0;
	game->save_first_image = 0;
	return (game);
}
