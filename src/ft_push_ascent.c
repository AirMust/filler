/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ascent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:08:39 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 14:29:08 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_push_ascent(t_ps *ps, char flag, int max, int current)
{
	int	i;
	int	*array;
	int	length;

	ft_push_restruct(ps, &array, &length, flag);
	i = -1;
	if (max == 1)
	{
		while (++i < length)
			if (array[i] == (flag == 'b' ? ft_array_max(array, length) :
			ft_array_min(array, length)))
			{
				ft_push_iterate(ps, i, flag, length);
				break ;
			}
	}
	else
		while (++i < length - 1)
			if (flag == 'b' ? current < array[i] && current > array[i + 1] :
			current < array[i + 1] && current > array[i])
			{
				ft_push_iterate(ps, i + 1, flag, length);
				break ;
			}
}

void	ft_push_iterate(t_ps *ps, int count_step, char flag, int length)
{
	if (2 * count_step < length)
	{
		while (count_step-- > 0)
			ft_push_r(ps, flag);
	}
	else
	{
		count_step = length - 1 - count_step;
		while (count_step-- >= 0)
			ft_push_rr(ps, flag);
	}
	return ;
}

void	ft_push_prev_ascent(t_ps *ps, char flag)
{
	if (flag == 'a')
	{
		if (ps->b[0] < ft_array_min(ps->a, ps->a_len) ||
		ps->b[0] > ft_array_max(ps->a, ps->a_len))
			ft_push_ascent(ps, 'a', 1, ps->b[0]);
		else
			ft_push_ascent(ps, 'a', 0, ps->b[0]);
		ft_push_pa(ps);
	}
	if (flag == 'b')
	{
		if (ps->a[0] < ft_array_min(ps->b, ps->b_len) ||
		ps->a[0] > ft_array_max(ps->b, ps->b_len))
			ft_push_ascent(ps, 'b', 1, ps->a[0]);
		else
			ft_push_ascent(ps, 'b', 0, ps->a[0]);
		ft_push_pb(ps);
	}
}
