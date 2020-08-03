/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:22:06 by slynell           #+#    #+#             */
/*   Updated: 2020/08/03 01:30:33 by air_must         ###   ########.fr       */
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
	char	**map;
	char	**token;
	char	iam;
	char	he;
	int		map_row;
	int		map_col;
	int		token_row;
	int		token_col;
	int		radius;
	int		**heat;
}					t_filler;

/*
** Read Filler function
*/
void read_object(char *line, t_filler *tf, int flag);

/*
** Algorithm Filler function
*/
void filler_algorithm(t_filler *tf);

#endif
