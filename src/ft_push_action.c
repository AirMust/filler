/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:07:20 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 14:29:07 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_push_pb(t_ps *ps)
{
	if ((*ps).a_len > 0)
	{
		ft_push_insert(ps->a[0], 'b', ps);
		ft_push_remove('a', ps);
	}
	ft_push_print("p", 'b', ps);
}

void	ft_push_r(t_ps *ps, char flag)
{
	int	x;
	int	*array;
	int	length;

	ft_push_restruct(ps, &array, &length, flag);
	x = array[0];
	ft_push_remove(flag, ps);
	ft_push_restruct(ps, &array, &length, flag);
	array[length] = x;
	length += 1;
	ft_push_construct(&ps, array, length, flag);
	ft_push_print("r", flag, ps);
}

void	ft_push_rr(t_ps *ps, char flag)
{
	int	x;
	int	*array;
	int	length;

	ft_push_restruct(ps, &array, &length, flag);
	length = length - 1;
	ft_push_construct(&ps, array, length, flag);
	x = array[length];
	ft_push_insert(x, flag, ps);
	ft_push_print("rr", flag, ps);
}

void	ft_push_s(t_ps *ps, char flag)
{
	int	x;
	int	*array;
	int	length;

	ft_push_restruct(ps, &array, &length, flag);
	if (length > 1)
	{
		x = array[0];
		array[0] = array[1];
		array[1] = x;
	}
	ft_push_construct(&ps, array, length, flag);
	ft_push_print("s", flag, ps);
}

void	ft_push_pa(t_ps *ps)
{
	if ((*ps).b_len > 0)
	{
		ft_push_insert(ps->b[0], 'a', ps);
		ft_push_remove('b', ps);
	}
	ft_push_print("p", 'a', ps);
}
