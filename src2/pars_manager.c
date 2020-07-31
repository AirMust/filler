/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:31:46 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/05 15:31:52 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void		token_size(char *token, t_bord *data)
{
	data->py = (int)ft_atoi(&token[6]);
	token = &token[6];
	while (ft_isdigit(*token) && token)
		token++;
	while (ft_isspace(*token) && token)
		token++;
	data->px = (int)ft_atoi(token);
	data->token = ft_map_creator(data->py, data->px);
}

void		board_size(char *mapsize, t_bord *data)
{
	data->map_y = (int)ft_atoi(&mapsize[8]);
	mapsize = &mapsize[8];
	while (ft_isdigit(*mapsize) && mapsize)
		mapsize++;
	while (ft_isspace(*mapsize) && mapsize)
		mapsize++;
	data->map_x = (int)ft_atoi(mapsize);
	data->map = ft_map_creator(data->map_y, data->map_x);
}

void		whoami(char *line, t_bord *data)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, "dgonor"))
	{
		data->player = 'O';
		data->enemy = 'X';
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, "dgonor"))
	{
		data->player = 'X';
		data->enemy = 'O';
	}
}
