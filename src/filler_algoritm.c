/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2020/08/03 01:27:15 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"


static int fill_heat(t_filler *tf, int row, int col)
{
	int j;
	int i;
	int dist;
	int min_dist;

	min_dist = INT_MAX;
	i = -1;
	while (++i < tf->map_row)
	{
		j = -1;
		while (++j < tf->map_col)
		{
			if (tf->map[i][j] == tf->he || tf->map[i][j] == tf->he + 32)
			{

				dist = ABS(i - row) + ABS(j - col);
				if (dist < min_dist)
					min_dist = dist;

			}
		}
	}
	return (min_dist);
}

static int	calc_heat(t_filler *tf, int row, int col)
{
	int	j;
	int	i;
	int	sum_heat;
	int	overlap;

	sum_heat = 0;
	overlap = 0;
	i = -1;
	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
			if (tf->token[i][j] == '*')
			{
				if ((row + i) < 0 || (row + i) >= tf->map_row
					|| (col + j) < 0 || (col + j) >= tf->map_col
					|| tf->heat[row + i][col + j] == -2)
					return (-1);
				if (tf->heat[row + i][col + j] == -1)
					overlap++;
				sum_heat += tf->heat[row + i][col + j];
			}
	}
	return ((overlap == 1) ? sum_heat : -1);
}

void		processing_heat(t_filler *tf)
{
	int	row;
	int	col;
	int	sum_heat;
	int	sum_heat_min;

	sum_heat_min = INT_MAX;
	row = -(tf->map_row) - 1;
	while (++row < tf->map_row + tf->token_row)
	{
		col = -(tf->map_col) - 1;
		while (++col < tf->map_col + tf->token_col)
		{
			sum_heat = calc_heat(tf, row, col);
			if (sum_heat != -1 && sum_heat < sum_heat_min)
			{
				tf->row = row;
				tf->col = col;
				sum_heat_min = sum_heat;
				tf->radius = 0;
			}
		}
	}
}


void filler_algorithm(t_filler *tf)
{
	int row;
	int col;

	row = -1;
	while (++row < tf->map_row)
	{
		col = -1;
		while (++col < tf->map_col)
		{
			if (tf->map[row][col] == tf->iam || tf->map[row][col] == tf->iam + 32)
				tf->heat[row][col] = -1;
			else if (tf->map[row][col] == tf->he || tf->map[row][col] == tf->he + 32)
				tf->heat[row][col] = -2;
			else if (tf->map[row][col] == '.')
				tf->heat[row][col] = fill_heat(tf, row, col);
		}
	}
	processing_heat(tf);
}
