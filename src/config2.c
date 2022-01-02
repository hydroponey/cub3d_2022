/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:51:28 by asimoes           #+#    #+#             */
/*   Updated: 2022/01/02 05:12:33 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_config(char *filename, t_conf *conf)
{
	int		err;
	char	*params[6];

	set_params_headers(params);
	conf->fd = open(filename, O_RDONLY);
	if (conf->fd == -1)
		exit_error("Failed to open map file", conf);
	err = check_params(params, conf);
	if (err != 0)
	{
		close(conf->fd);
		exit_error("Missing required parameters in cub file", conf);
	}
	parse_map(conf->fd, conf);
	close(conf->fd);
}

void	check_args(int argc, char *argv[], t_conf *conf)
{
	char	check[2];

	if (argc != 2)
		exit_error("Wrong number of arguments", conf);
	if (ft_strlen(argv[1]) < 5)
		exit_error("Invalid map file name", conf);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		exit_error("Invalid map file name", conf);
	conf->fd = open(argv[1], O_RDONLY);
	if (conf->fd == -1)
		exit_error("Failed to open map file", conf);
	if (read(conf->fd, check, 2) == -1)
	{
		close(conf->fd);
		exit_error("Invalid map file", conf);
	}
	close(conf->fd);
}
