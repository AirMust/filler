/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:10:38 by slynell           #+#    #+#             */
/*   Updated: 2020/07/26 13:48:50 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_push_exit(char *str, t_ps *ps)
{
	if (*str)
	{
		ft_putstr(str);
	}
	ft_push_free(ps);
	return (0);
}

void	ft_push_free(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps);
	ps = NULL;
}

int		ft_push_check3(t_ps *ps)
{
	int i;
	int s;

	i = -1;
	s = 0;
	while (++i < ps->a_len - 1)
		if (ps->a[i + 1] < ps->a[i])
			s++;
	if (ps->a[0] < ps->a[i])
		s++;
	return (s > 1 ? 0 : 1);
}

t_ps	*ft_push_init(int length)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps) * 1);
	if (length != -1)
	{
		ps->a = (int *)malloc(sizeof(int) * (length + 100));
		ps->b = (int *)malloc(sizeof(int) * (length + 100));
	}
	else
	{
		ps->a = (int *)malloc(sizeof(int) * (1));
		ps->b = (int *)malloc(sizeof(int) * (1));
	}
	ps->a_len = 0;
	ps->b_len = 0;
	ps->count = 0;
	ps->option = 0;
	return (ps);
}
