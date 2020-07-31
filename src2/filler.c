/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:37:56 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/25 13:37:58 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void		step_order(t_bord *data)
{
	data->dist = 10000;
	data->px = 0;
	data->py = 0;
	data->map_x = 0;
	data->map_y = 0;
	data->token = NULL;
	data->x = 0;
	data->y = 0;
	data->tmp_x = 0;
	data->tmp_y = 0;
	data->player = 0;
	data->enemy = 0;
	data->map = NULL;
}

static void		ft_help_pars(char *line, t_bord *data, int *i, int *marker)
{
	if (ft_strstr(line, "Piece"))
		token_size(line, data);
	if (data->token && *marker == -1)
	{
		ft_strcpy(data->token[*i += 1], line);
		if (*i == data->py - 1)
		{
			*i = -1;
			*marker = 0;
			filler_algoritm(data);
			ft_memdel_arlen((void**)data->token);
		}
	}
	if (*marker > 1)
		*marker -= 1;
	if (*marker < -1)
		*marker += 1;
}

static void		ft_pars_bord(char *line, t_bord *data, int *i, int *marker)
{
	if (!data->player)
		whoami(line, data);
	if (!data->map_y && !data->map_x)
		if (ft_strstr(line, "Plateau"))
			board_size(line, data);
	if (ft_strstr(line, "Plateau"))
		*marker = 3;
	if (*marker == 1 && data->map)
	{
		ft_strcpy(data->map[*i += 1], line + 4);
		if (*i == data->map_y - 1)
		{
			*i = -1;
			*marker = -3;
		}
	}
	ft_help_pars(line, data, i, marker);
}

int				filler(char *line)
{
	t_bord	data;
	int		index;
	int		marker;

	index = -1;
	marker = 0;
	step_order(&data);
	while (get_next_line(0, &line) > 0)
	{
		ft_pars_bord(line, &data, &index, &marker);
		ft_strdel(&line);
	}
	ft_memdel_arlen((void**)data.map);
	return (0);
}

int				main(void)
{
	char *line;

	line = NULL;
	filler(line);
	return (0);
}
