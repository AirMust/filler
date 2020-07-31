/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:42:03 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 14:46:22 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_push_print_meta(t_ps *ps)
{
	if (ps->option == 1 || ps->option == 3)
	{
		ft_putstr("\nArray 'A': ");
		ft_array_print((*ps).a, ps->a_len);
		ft_putstr("\nArray 'B': ");
		ft_array_print((*ps).b, ps->b_len);
		ft_putstr("\nCount 'A': ");
		ft_putnbr_fd(ps->a_len, 1);
		ft_putstr("\nCount 'B': ");
		ft_putnbr_fd(ps->b_len, 1);
	}
}

void	ft_push_print(char *str, char flag, t_ps *ps)
{
	if (ps->option == 100)
		return ;
	if (ps->option == 1 || ps->option == 3)
	{
		IF_TRUE(ps->option == 3, ft_putstr("\033[32m"));
		ft_putstr("\n\n# Step: ");
		ft_putnbr_fd(ps->count + 1, 1);
		IF_TRUE(ps->option == 3, ft_putstr("\033[36m"));
		ft_putstr("\nOperation: ");
	}
	ft_putstr(str);
	ft_putchar(flag);
	ft_putstr(ps->option == 1 || ps->option == 3 ? "" : "\n");
	IF_TRUE(ps->option == 3, ft_putstr("\033[0m"));
	ft_push_print_meta(ps);
	ps->count += 1;
}
