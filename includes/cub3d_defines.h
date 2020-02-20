/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:32:00 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:24:01 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H
# define MIN_WIDTH							500
# define MIN_HEIGHT							500
# define MAX_WIDTH							2560
# define MAX_HEIGHT							1400
# define NORTH								90
# define EAST								0
# define WEST								180
# define SOUTH								270
# define MAX_ROT_SPEED						90
# define HP									20
# define STEP_START							0
# define STEP_PLAYING						1
# define STEP_END							2
# define MAP_SIZE							200
# define PLAYER_COLOR						0xA896FF
# define WALL_COLOR							0x474347
# define VOID_COLOR							0xFFFFFF
# define AIM_HEIGHT							25
# define AIM_WIDTH							2
# define AIM_CIRCLE_THICK					2
# define AIM_CIRCLE_COLOR					0xDC4A44
# define AIM_CIRCLE_SIZE					9
# define AIM_COLOR							0xFFFFFF
# define BONUS_OPACITY						100
# define MAX_LEVEL							10
# define LU_DEFAULT_TEX		"textures/jesus.XPM"
# define DO_DEFAULT_TEX		"textures/tropical.XPM"
# define LI_DEFAULT_TEX		"textures/mini_heart.xpm"
# define CO_DEFAULT_TEX		"textures/planet_rose.XPM"
# define M_ENTER_TEX		"textures/menus/click_enter_menu.xpm"
# define M_GAME_OVER_TEX	"textures/menus/game_over_menu.xpm"
# define M_NAME_TEX			"textures/menus/name_menu.xpm"
# define M_LOGO_TEX			"textures/menus/logo.xpm"
# define MAP_ONLY							"LDHCUFBWENS0123"
# define POS_ONLY							"WENS"
# define GAME_NAME							"cub3d"
# define ARGUMENT_SAVE						"-save"
# define ARGUMENT_SAVE_2					"--save"
# define ARGUMENT_DISABLE_BONUS				"--disable-bonus"
# define ARGUMENT_DISABLE_MAP				"--disable-map"
# define MSG_ARGUMENTS_ERROR				"Wrong arguments."
# define MSG_MAP_ERROR						"Map error."
# define MSG_MAPNAME_ERROR					"Invalid map name."
# define MSG_RENDERING_ERROR				"Rendering error."
# define MSG_RENDERING_ERROR_428			"Rendering error. (ERROR_CODE 428)"
# define MSG_RENDERING_ERROR_429			"Rendering error. (ERROR_CODE 429)"
# define MSG_TOO_FEW_ARGUMENTS	"Too few arguments.\nUsage: ./cub3d <valid map>"
# define MSG_CANNOT_ALLOCATE_GAME_ERROR		"Cannot allocate global game."
# define MSG_CANNOT_ALLOCATE_MAP_ERROR		"Cannot allocate map."
# define MSG_CANNOT_ALLOCATE_IMAGE_ERROR	"Cannot allocate image."
# define MSG_CANNOT_ALLOCATE_PLAYER_ERROR	"Cannot allocate player."
# define MSG_CANNOT_INIT_MLX_ERROR			"Cannot init MLX."
# define MSG_CANNOT_INIT_MLX_WINDOW_ERROR	"Cannot init MLX's window."
#endif
