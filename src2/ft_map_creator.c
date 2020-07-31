/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:33:17 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/05 15:33:19 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char		**ft_map_creator(int y, int x)
{
	int		i;
	char	**data;

	i = 0;
	if (!(data = (char**)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (i != y)
	{
		data[i] = ft_strnew(x);
		i++;
	}
	data[i] = NULL;
	return (data);
}
