/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:22:06 by slynell           #+#    #+#             */
/*   Updated: 2020/07/31 15:37:33 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/header/libft.h"

typedef struct		s_filler
{
	int		col;
	int		row;
	int		tmp_row;
	int		tmp_col;
	char	**map;
	char	**token;
	char	player;
	char	opponent;
	int		map_row;
	int		map_col;
	int		token_row;
	int		token_col;
	int		radius;
}					t_filler;

/*
** Push swap basic function
*/
