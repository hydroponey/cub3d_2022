/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:15 by asimoes           #+#    #+#             */
/*   Updated: 2022/01/02 05:32:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_conf *conf)
{
	conf->mlx = mlx_init();
	if (conf->mlx == NULL)
		exit_error("mlx_init failed", conf);
	conf->resx = RESO_X;
	conf->resy = RESO_Y;
	conf->move_speed = MOVE_SPEED * (conf->resx * conf->resy) / (800 * 600);
	conf->rot_speed = ROT_SPEED * (conf->resx * conf->resy) / (800 * 600);
	load_textures(conf);
	get_textures_addr(conf);
	create_image(conf);
}
