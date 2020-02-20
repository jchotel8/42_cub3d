/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:51 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:26:00 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			set_wall(t_ray *ray, t_vector x, t_vector y)
{
	ray->wall = (ray->pos.x == x.x && ray->pos.y == x.y && ray->cos > 0 ?
			1 : 4);
	ray->wall = (ray->pos.x == x.x && ray->pos.y == x.y && ray->cos < 0 ?
			3 : ray->wall);
	ray->wall = (ray->pos.x == y.x && ray->pos.y == y.y && ray->sin > 0 ?
			2 : ray->wall);
	return (ray->wall);
}

int			set_doors(t_ray *ray, char c)
{
	if (c == 'D' && ray->wall % 2 != 0)
		ray->wall = 5;
	else if (c == 'D')
		ray->wall = 6;
	if (c == 'U' && ray->wall % 2 != 0)
		ray->wall = 7;
	else if (c == 'U')
		ray->wall = 8;
	else
		return (0);
	return (1);
}

t_vector	next_block(t_vector res, t_vector p)
{
	t_vector hit;

	hit.x = res.x - (p.x > res.x && res.x == (int)res.x ? 0.0001 : 0);
	hit.y = res.y - (p.y > res.y && res.y == (int)res.y ? 0.0001 : 0);
	return (hit);
}

t_vector	next_inter(t_vector p, t_vector vec, t_ray *ray)
{
	float		c;
	t_vector	x;
	t_vector	y;

	c = vec.y + ray->tan * vec.x;
	x.x = (int)vec.x + (vec.x == (int)vec.x && ray->cos < 0 ? -1 : 0)
			+ (ray->cos > 0 ? 1 : 0);
	x.y = -ray->tan * (float)x.x + c;
	y.y = (int)vec.y + (vec.y == (int)vec.y && ray->sin > 0 ? -1 : 0)
			+ (ray->sin > 0 ? 0 : 1);
	y.x = (y.y - c) / -ray->tan;
	ray->pos = (sq_dist(p, y) > sq_dist(p, x) ? x : y);
	ray->wall = set_wall(ray, x, y);
	return (ray->pos);
}

t_vector	next_hit(t_game *game, t_ray *ray)
{
	t_vector	hit;
	int			number;
	char		c;

	number = 0;
	ray->sp_num = 0;
	ray->pos = next_inter(game->p.pos, game->p.pos, ray);
	hit = next_block(ray->pos, game->p.pos);
	c = game->map->map[(int)hit.y][(int)hit.x];
	while (!(ray->pos.x == 0 && ray->pos.y == 0)
		&& c && (!ft_strchr("DUH1", c)))
	{
		if (++number > 1000)
			quit(EXIT_FAILURE, MSG_RENDERING_ERROR_429);
		if (ft_strchr("2LC", c) && ray->sp_num < 9)
			ray->sprites[++ray->sp_num] = set_sprite(hit, &ray->wall, game);
		ray->pos = next_inter(game->p.pos, ray->pos, ray);
		hit = next_block(ray->pos, game->p.pos);
		c = game->map->map[(int)hit.y][(int)hit.x];
		set_doors(ray, c);
	}
	return (ray->pos);
}
