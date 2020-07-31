/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:46:39 by slynell           #+#    #+#             */
/*   Updated: 2020/07/26 13:53:28 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_push_read_int(t_ps *ps, char *str)
{
	int k;

	if (ft_strequ(str, "-v") == 0 && ft_strequ(str, "-c") == 0)
	{
		if (ft_check_integer(str) == 0)
			return (1);
		k = -1;
		while (++k < ps->a_len)
			if (ps->a[k] == ft_atoi(str))
				return (1);
		ps->a[ps->a_len++] = ft_atoi(str);
	}
	return (0);
}

int		ft_push_read(t_ps *ps, char **av, int ac)
{
	int		i;
	int		j;
	char	**actor;

	j = 0;
	while (ac > 1 && av[++j])
	{
		actor = ft_strsplit(av[j], ' ');
		i = -1;
		while (actor[++i])
		{
			ps->option += ft_strequ(actor[i], "-v") ? 1 : 0;
			ps->option += ft_strequ(actor[i], "-c") ? 2 : 0;
			ps->b[ps->a_len] = 0;
			if (ft_push_read_int(ps, actor[i]))
				return (1);
		}
		ft_strsplitfree(&actor);
	}
	return (0);
}

int		ft_push_read_count_int(t_ps *ps, char *str)
{
	if (ft_strequ(str, "-v") == 0 && ft_strequ(str, "-c") == 0)
	{
		if (ft_check_integer(str) == 0)
			return (1);
		ps->a_len++;
	}
	return (0);
}

int		ft_push_read_count(t_ps *ps, char **av, int ac)
{
	int		i;
	int		j;
	char	**actor;

	j = 0;
	while (ac > 1 && av[++j])
	{
		actor = ft_strsplit(av[j], ' ');
		i = -1;
		while (actor[++i])
		{
			if (ft_push_read_count_int(ps, actor[i]))
				return (1);
		}
		ft_strsplitfree(&actor);
	}
	return (0);
}
