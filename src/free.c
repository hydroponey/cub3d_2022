/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 01:30:26 by asimoes           #+#    #+#             */
/*   Updated: 2022/01/02 05:17:14 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line/get_next_line.h"

void	free_paths(t_conf *conf)
{
	if (conf->no_path != NULL)
		free(conf->no_path);
	if (conf->so_path != NULL)
		free(conf->so_path);
	if (conf->ea_path != NULL)
		free(conf->ea_path);
	if (conf->we_path != NULL)
		free(conf->we_path);
}

void	free_textures(t_conf *conf)
{
	if (conf->no.img != NULL)
		mlx_destroy_image(conf->mlx, conf->no.img);
	if (conf->so.img != NULL)
		mlx_destroy_image(conf->mlx, conf->so.img);
	if (conf->ea.img != NULL)
		mlx_destroy_image(conf->mlx, conf->ea.img);
	if (conf->we.img != NULL)
		mlx_destroy_image(conf->mlx, conf->we.img);
	if (conf->img != NULL)
		mlx_destroy_image(conf->mlx, conf->img);
}

void	ft_freetab(char **tab, short origin)
{
	char	**start;

	start = tab;
	while (*tab)
		free(*tab++);
	if (origin)
		free(start);
}

void	free_gnl(char *line, int fd)
{
	int	ret;

	free(line);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
	close(fd);
}
