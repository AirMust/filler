/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_filler_support.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:29:43 by lcharvol          #+#    #+#             */
/*   Updated: 2020/08/03 01:29:31 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void read_object_value(t_filler *tf, int flag)
{
	int i;
	char *line;
	char **temp_map;
	int temp_count_row;

	temp_count_row = (flag == 0 ? tf->map_row : tf->token_row);
	temp_map = (flag == 0 ? tf->map : tf->token);

	i = -1;
	IF_TRUE(flag == 0, get_next_line(0, &line));
	IF_TRUE(flag == 0, ft_strdel(&line));
	temp_map = (char **)malloc(sizeof(char *) * (temp_count_row + 1));
	while (++i < temp_count_row)
	{
		get_next_line(0, &line);
		temp_map[i] = ft_strdup((const char *)(&line[flag == 0 ? 4 : 0]));
		ft_strdel(&line);
	}
	temp_map[i] = 0;
	IF_TRUE(flag == 0, tf->map = temp_map);
	IF_TRUE(flag == 1, tf->token = temp_map);
}

void create_grid(t_filler *tf)
{
	int i;

	tf->heat = (int **)malloc(sizeof(int *) * (tf->map_row + 1));
	i = -1;
	while (++i < tf->map_row)
		tf->heat[i] = (int *)malloc(sizeof(int) * (tf->map_col + 1));
	tf->heat[i] = 0;
}

void read_object_size(char *line, t_filler *tf, int flag)
{
	char **actor;

	actor = ft_strsplit(line, ' ');
	if (flag == 0)
	{
		tf->map_row = ft_atoi(actor[1]);
		tf->map_col = ft_atoi(actor[2]);
	}
	else if (flag == 1)
	{
		tf->token_row = ft_atoi(actor[1]);
		tf->token_col = ft_atoi(actor[2]);
	}
	ft_strsplitfree(&actor);
}

void read_object(char *line, t_filler *tf, int flag)
{
	read_object_size(line, tf, flag);
	read_object_value(tf, flag);
	IF_TRUE(flag == 0, create_grid(tf));
}
