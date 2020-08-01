/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2020/08/01 14:46:35 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int			distance_block(t_filler *data, int *i, int *j)
{
	int		tem_y;
	int		tem_x;

	tem_y = 0;
	tem_x = 0;
	tem_y = *i - data->tmp_row;
	if (tem_y < 0)
		tem_y *= -1;
	tem_x = *j - data->tmp_col;
	if (tem_x < 0)
		tem_x *= -1;
	return (tem_x + tem_y);
}


void city_block(t_filler *data)
{
	int i;
	int j;
	int len;

	i = -1;
	while (++i < data->map_row)
	{
		j = -1;
		while (++j < data->map_col)
		{
			if (data->map[i][j] == data->opponent || data->map[i][j] == data->opponent + 32)
			{
				len = distance_block(data, &i, &j);
				if (len < data->radius)
				{
					data->radius = len;
					data->row = data->tmp_row;
					data->col = data->tmp_col;
				}
			}
		}
	}
}

// int help_check(t_filler *data, int column, int row)
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

// int check_opponent(t_filler *data, int i, int j, int column)
// {
// 	int row;

// 	row = -1;
// 	data->c = 0;
// 	while (data->token[++column] && ((i + column) < data->map_y))
// 	{
// 		while (data->token[column][++row] && ((j + row) < data->map_x))
// 		{
// 			if (data->token[column][row] == '*' &&
// 				((data->map[i + column][j + row] == data->opponent || data->map[i + column][j + row] == data->opponent + 32)))
// 				return (0);
// 			if (data->token[column][row] == '*' &&
// 				(data->map[i + column][j + row] == data->player || data->map[i + column][j + row] == data->player + 32))
// 				data->c++;
// 		}
// 		if (help_check(data, column, row) == 0)
// 			return (0);
// 		row = -1;
// 	}
// 	if (column < data->token_row)
// 		return (0);
// 	if (data->c == 1)
// 		return (1);
// 	return (0);
// }

// void fit_token(t_filler *data, int *i, int *j)
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
// 					if (check_opponent(data, (*i - colum), (*j - row), -1))
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

int temp_2(t_filler *data, int y, int x)
{
	int i;
	int j;
	int perec;

	i = -1;
	perec = 0;
	while (++i < data->token_row)
	{
		j = -1;
		while (++j < data->token_col)
		{
			if (data->token[i][j] == '*' && (data->map[y + i][x + j] == data->player || data->map[y + i][x + j] == data->player + 32))
				perec++;
			if (data->token[i][j] == '*' && (data->map[y + i][x + j] == data->opponent || data->map[y + i][x + j] == data->opponent + 32))
				return (0);
		}
	}
	if (perec == 1)
		return (1);
	return (0);
}
void temp_1(t_filler *data, int row, int col)
{
	int i;
	int j;

	i = -1;

	while (++i < data->token_row)
	{
		j = -1;
		while (++j < data->token_col)
		{
			if (data->token[i][j] == '*' && row - i >= 0 &&
				row + (data->token_row - i - 1) < data->map_row && col - j >= 0 &&
				col + (data->token_col - j - 1) < data->map_col)
			{
				// printf("%d %d %d %d\n", row, i, col, j);
				if (temp_2(data, row - i, col - j) == 1)
				{
					data->tmp_row = row - i;
					data->tmp_col = col - j;
					city_block(data);
				}
			}
		}
	}
}

void filler_algoritm(t_filler *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->map_row)
	{
		j = -1;
		while (++j < data->map_col)
		{
			if (data->map[i][j] == data->player || data->map[i][j] == data->player + 32)
				temp_1(data, i, j);
				// printf("%d %d", i, j);
		}
	}
	ft_printf("%i %i\n", data->row, data->col);
	data->radius = 10000;
}
// fit_token(data, &i, &j);
