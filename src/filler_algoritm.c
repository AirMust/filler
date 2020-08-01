/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2020/08/01 14:55:12 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int			distance_block(t_filler *tf, int *i, int *j)
{
	int		tem_y;
	int		tem_x;

	tem_y = 0;
	tem_x = 0;
	tem_y = *i - tf->tmp_row;
	if (tem_y < 0)
		tem_y *= -1;
	tem_x = *j - tf->tmp_col;
	if (tem_x < 0)
		tem_x *= -1;
	return (tem_x + tem_y);
}


void city_block(t_filler *tf)
{
	int i;
	int j;
	int len;

	i = -1;
	while (++i < tf->map_row)
	{
		j = -1;
		while (++j < tf->map_col)
		{
			if (tf->map[i][j] == tf->opponent || tf->map[i][j] == tf->opponent + 32)
			{
				len = distance_block(tf, &i, &j);
				if (len < tf->radius)
				{
					tf->radius = len;
					tf->row = tf->tmp_row;
					tf->col = tf->tmp_col;
				}
			}
		}
	}
}

int temp_2(t_filler *tf, int y, int x)
{
	int i;
	int j;
	int perec;

	i = -1;
	perec = 0;
	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
		{
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->player || tf->map[y + i][x + j] == tf->player + 32))
				perec++;
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->opponent || tf->map[y + i][x + j] == tf->opponent + 32))
				return (0);
		}
	}
	if (perec == 1)
		return (1);
	return (0);
}
void temp_1(t_filler *tf, int row, int col)
{
	int i;
	int j;

	i = -1;

	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
		{
			if (tf->token[i][j] == '*' && row - i >= 0 &&
				row + (tf->token_row - i - 1) < tf->map_row && col - j >= 0 &&
				col + (tf->token_col - j - 1) < tf->map_col)
			{
				// printf("%d %d %d %d\n", row, i, col, j);
				if (temp_2(tf, row - i, col - j) == 1)
				{
					tf->tmp_row = row - i;
					tf->tmp_col = col - j;
					city_block(tf);
				}
			}
		}
	}
}

void filler_algoritm(t_filler *tf)
{
	int i;
	int j;

	i = -1;
	while (++i < tf->map_row)
	{
		j = -1;
		while (++j < tf->map_col)
		{
			if (tf->map[i][j] == tf->player || tf->map[i][j] == tf->player + 32)
				temp_1(tf, i, j);
				// printf("%d %d", i, j);
		}
	}
	ft_printf("%i %i\n", tf->row, tf->col);
	tf->radius = 10000;
}
// fit_token(tf, &i, &j);
