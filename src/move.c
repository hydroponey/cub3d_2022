/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 04:54:04 by asimoes           #+#    #+#             */
/*   Updated: 2022/01/02 12:26:16 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int	move_forward(t_conf *conf)
{
	int	temp;
	int	change;

	change = 0;
	if (conf->key_w)
	{
		temp = (int)(conf->posx + conf->dirx * conf->move_speed);
		printf("temp = %d\n", temp);
		printf("map_width = %d\nmap_height = %d\n", conf->map_width, conf->map_height);
		if (conf->map[temp][(int)conf->posy] == 0)
		{
			conf->posx += conf->dirx * conf->move_speed;
			change = 1;
		}
		temp = (int)(conf->posy + conf->diry * conf->move_speed + 0.1);
		if (conf->map[(int)conf->posx][temp] == 0)
		{
			conf->posy += conf->diry * conf->move_speed;
			change = 1;
		}
	}
	return (change);
}

int	move_backwards(t_conf *conf)
{
	int	temp;
	int	change;

	change = 0;
	if (conf->key_s)
	{
		temp = (int)(conf->posx - conf->dirx * conf->move_speed - 0.1);
		if (conf->map[temp][(int)conf->posy] == 0)
		{
			conf->posx -= conf->dirx * conf->move_speed;
			change = 1;
		}
		temp = (int)(conf->posy - conf->diry * conf->move_speed - 0.1);
		if (conf->map[(int)conf->posx][temp] == 0)
		{
			conf->posy -= conf->diry * conf->move_speed;
			change = 1;
		}
	}
	return (change);
}

int	move_left(t_conf *conf)
{
	int	temp;
	int	change;

	change = 0;
	if (conf->key_a)
	{
		temp = (int)(conf->posx - conf->diry * conf->move_speed);
		if (conf->map[temp][(int)conf->posy] == 0)
		{
			conf->posx -= conf->diry * conf->move_speed;
			change = 1;
		}
		temp = (int)(conf->posy + conf->dirx * conf->move_speed);
		if (conf->map[(int)conf->posx][temp] == 0)
		{
			conf->posy += conf->dirx * conf->move_speed;
			change = 1;
		}
	}
	return (change);
}

int	move_right(t_conf *conf)
{
	int	temp;
	int	change;

	change = 0;
	if (conf->key_d)
	{
		temp = (int)(conf->posx + conf->diry * conf->move_speed);
		if (conf->map[temp][(int)conf->posy] == 0)
		{
			conf->posx += conf->diry * conf->move_speed;
			change = 1;
		}
		temp = (int)(conf->posy - conf->dirx * conf->move_speed);
		if (conf->map[(int)conf->posx][temp] == 0)
		{
			conf->posy -= conf->dirx * conf->move_speed;
			change = 1;
		}
	}
	return (change);
}
