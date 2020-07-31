/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2020/07/31 03:15:07 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void city_block(t_bord *data)
{
	int i;
	int j;
	int len;

	i = -1;
	j = -1;
	while (data->map[++i])
	{
		while (data->map[i][++j])
		{
			if (data->map[i][j] == data->enemy || data->map[i][j] == data->enemy - 32)
			{
				len = distance_block(data, &i, &j);
				if (len < data->dist)
				{
					data->dist = len;
					data->y = data->tmp_y;
					data->x = data->tmp_x;
				}
			}
		}
		j = -1;
	}
}

// int help_check(t_bord *data, int column, int row)
// {
// 	if (row < data->px)
// 	{
// 		while (data->token[column][row])
// 		{
// 			if (data->token[column][row] == '*')
// 				return (0);
// 			row++;
// 		}
// 	}
// 	return (1);
// }

// int check_enemy(t_bord *data, int i, int j, int column)
// {
// 	int row;

// 	row = -1;
// 	data->c = 0;
// 	while (data->token[++column] && ((i + column) < data->map_y))
// 	{
// 		while (data->token[column][++row] && ((j + row) < data->map_x))
// 		{
// 			if (data->token[column][row] == '*' &&
// 				((data->map[i + column][j + row] == data->enemy || data->map[i + column][j + row] == data->enemy - 32)))
// 				return (0);
// 			if (data->token[column][row] == '*' &&
// 				(data->map[i + column][j + row] == data->player || data->map[i + column][j + row] == data->player - 32))
// 				data->c++;
// 		}
// 		if (help_check(data, column, row) == 0)
// 			return (0);
// 		row = -1;
// 	}
// 	if (column < data->py)
// 		return (0);
// 	if (data->c == 1)
// 		return (1);
// 	return (0);
// }

// void fit_token(t_bord *data, int *i, int *j)
// {
// 	int row;
// 	int colum;

// 	row = -1;
// 	colum = -1;
// 	while (data->token[++colum])
// 	{
// 		while (data->token[colum][++row])
// 		{
// 			if (data->token[colum][row] == '*' &&
// 				(data->map[*i][*j] == data->player))
// 			{
// 				if (*i - colum >= 0 && *j - row >= 0)
// 				{
// 					if (check_enemy(data, (*i - colum), (*j - row), -1))
// 					{
// 						data->tmp_y = *i - colum;
// 						data->tmp_x = *j - row;
// 						city_block(data);
// 					}
// 				}
// 			}
// 		}
// 		row = -1;
// 	}
// }

int temp_2(t_bord *data, int y, int x)
{
	int i;
	int j;
	int perec;

	i = -1;
	perec = 0;
	while (data->token[++i])
	{
		j = -1;
		while (data->token[i][++j])
		{
			if (data->token[i][j] == '*' && (data->map[y + i][x + j] == data->player || data->map[y + i][x + j] == data->player - 32))
				perec++;
			if (data->token[i][j] == '*' && (data->map[y + i][x + j] == data->enemy || data->map[y + i][x + j] == data->enemy - 32))
				return (0);
		}
	}
	if (perec == 1)
		return (1);
	return (0);
}
void temp_1(t_bord *data, int y, int x)
{
	int i;
	int j;

	i = -1;
	while (data->token[++i])
	{
		j = -1;
		while (data->token[i][++j])
		{
			if (data->token[i][j] == '*' && y - i >= 0 &&
				y + (data->py - i - 1) < data->map_y && x - j >= 0 &&
				x + (data->px - j - 1) < data->map_x)
			{
				if (temp_2(data, y - i, x - j) == 1)
				{
					data->tmp_y = y - i;
					data->tmp_x = x - j;
					city_block(data);
				}
			}
		}
	}
}

void filler_algoritm(t_bord *data)
{
	int i;
	int j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == data->player || data->map[i][j] == data->player - 32)
				temp_1(data, i, j);
		}
	}
	ft_printf("%i %i\n", data->y, data->x);
	data->dist = 10000;
}
// fit_token(data, &i, &j);
