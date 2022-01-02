/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:41:09 by asimoes           #+#    #+#             */
/*   Updated: 2022/01/02 09:36:35 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "cub3d.h"

void	set_params_headers(char **params)
{
	params[0] = "NO ";
	params[1] = "SO ";
	params[2] = "WE ";
	params[3] = "EA ";
	params[4] = "F ";
	params[5] = "C ";
}

void	error_double_param(int param, char *line, t_conf *conf)
{
	free_gnl(line, conf->fd);
	if (param == PARAM_C)
		exit_error("Multiple ceil color lines in configuration file", conf);
	if (param == PARAM_EA)
		exit_error("Multiple east texture lines in configuration file", conf);
	if (param == PARAM_F)
		exit_error("Multiple floor color lines in configuration file", conf);
	if (param == PARAM_NO)
		exit_error("Multiple north texture lines in configuration file", conf);
	if (param == PARAM_SO)
		exit_error("Multiple south texture lines in configuration file", conf);
	if (param == PARAM_WE)
		exit_error("Multiple west texture lines in configuration file", conf);
}

void	check_param(int param, char *value, t_conf *conf)
{
	if (param == PARAM_C)
		parse_c(value, conf);
	if (param == PARAM_EA)
		parse_ea(value, conf);
	if (param == PARAM_F)
		parse_f(value, conf);
	if (param == PARAM_NO)
		parse_no(value, conf);
	if (param == PARAM_SO)
		parse_so(value, conf);
	if (param == PARAM_WE)
		parse_we(value, conf);
}

int	is_param(char **params, char *line, int *check, t_conf *conf)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(params[i], line, ft_strlen(params[i])) == 0)
		{
			if (check[i] != 0)
				error_double_param(i, line, conf);
			check_param(i, line, conf);
			check[i] = 1;
			return (1);
		}
		i++;
	}
	if (ft_strlen(line) > 0)
	{
		free_gnl(line, conf->fd);
		exit_error("Unknown parameter or no value.", conf);
	}
	return (0);
}

int	check_params(char **params, t_conf *conf)
{
	int		ret;
	char	*line;
	char	*trimmed;
	int		double_check[6];
	int		params_read;

	params_read = 0;
	ft_bzero(double_check, sizeof(int) * 6);
	ret = get_next_line(conf->fd, &line);
	while (ret >= 0)
	{
		trimmed = trim_helper(line, " \t", conf);
		free(line);
		map_check(trimmed, conf);
		params_read += is_param(params, trimmed, double_check, conf);
		free(trimmed);
		if (params_read == 6 || ret == 0)
			break ;
		ret = get_next_line(conf->fd, &line);
	}
	if (params_read != 6)
		return (1);
	return (0);
}
