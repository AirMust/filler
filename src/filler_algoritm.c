/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2020/08/03 01:00:02 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int algorithm_step_2(t_filler *tf, int y, int x)
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
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->iam ||
										   tf->map[y + i][x + j] == tf->iam + 32))
				perec++;
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->he ||
										   tf->map[y + i][x + j] == tf->he + 32))
				return (0);
		}
	}
	if (perec == 1)
		return (1);
	return (0);
}

int algorithm_step_1(t_filler *tf, int row, int col)
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
				if (algorithm_step_2(tf, row - i, col - j) == 1)
				{
					tf->radius = 100;
					tf->row = row - i;
					tf->col = col - j;
					return (1);
				}
			}
		}
	}
	return (0);
}

void filler_algorithm(t_filler *tf)
{
	int i;
	int j;
	int flag;

	flag = 0;
	flag += tf->row >= tf->map_row / 2 ? 2 : 0;
	flag += tf->col >= tf->map_col / 2 ? 1 : 0;
	i = flag < 2 ? tf->map_row - 1 : 0;
	while (flag < 2 ? i >= 0 : i < tf->map_row)
	{
		j = flag % 2 == 0 ? tf->map_col - 1 : 0;
		while (flag % 2 == 0 ? j >= 0 : j < tf->map_col)
		{

			if (algorithm_step_1(tf, i, j) == 1)
				return;
			j = j + (flag % 2 == 0 ? -1 : 1);
		}
		i = i + (flag < 2 ? -1 : 1);
	}
}

static int algo_dist(t_filler *tf, int row, int col)
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
				// printf("\n%d %d %d %d %d\n", ABS(i - row), ABS(j - col), i, j, min_dist);

			}
		}
	}
	return (min_dist);
}

static int	calc_sum(t_filler *tf, int y, int x)
{
	int	j;
	int	i;
	int	sum;
	int	player_counter;

	sum = 0;
	player_counter = 0;
	j = -1;
	while (++j < tf->token_row)
	{
		i = -1;
		while (++i < tf->token_col)
			if (tf->token[j][i] == '*')
			{
				if ((y + j) < 0 || (y + j) >= tf->map_row
					|| (x + i) < 0 || (x + i) >= tf->map_col
					|| tf->heat[y + j][x + i] == -2)
					return (-1);
				if (tf->heat[y + j][x + i] == -1)
					player_counter++;
				sum += tf->heat[y + j][x + i];
			}
	}
	return ((player_counter == 1) ? sum : -1);
}

void		calc_coords(t_filler *tf)
{
	int	j;
	int	i;
	int	sum;
	int	min_sum;

	min_sum = INT_MAX;
	j = -(tf->map_row);
	while (j < tf->map_row + tf->token_row)
	{
		i = -(tf->map_col);
		while (i < tf->map_col + tf->token_col)
		{
			sum = calc_sum(tf, j, i);
			if (sum != -1 && sum < min_sum)
			{
				tf->row = j;
				tf->col = i;
				min_sum = sum;
				tf->radius = 10;
			}
			i++;
		}
		j++;
	}
}


void algorithm2(t_filler *tf)
{
	int i;
	int j;
	// int flag;

	i = -1;
	while (++i < tf->map_row)
	{
		j = -1;
		while (++j < tf->map_col)
		{
			if (tf->map[i][j] == tf->iam || tf->map[i][j] == tf->iam + 32)
				tf->heat[i][j] = -1;
			else if (tf->map[i][j] == tf->he || tf->map[i][j] == tf->he + 32)
				tf->heat[i][j] = -2;
			else if (tf->map[i][j] == '.')
				tf->heat[i][j] = algo_dist(tf, i, j);
		}
	}
	calc_coords(tf);
	// printf("%d %d\n", tf->row, tf->col);
}
