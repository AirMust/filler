/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:56:26 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/25 13:56:27 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include "./libft/libft.h"

typedef struct		s_bord
{
	int		y;
	int		x;
	int		tmp_y;
	int		tmp_x;
	char	**map;
	char	**token;
	char	player;
	char	enemy;
	int		map_y;
	int		map_x;
	int		py;
	int		px;
	int		dist;
	int		c;
}					t_bord;

int					filler(char *line);
char				**ft_map_creator(int y, int x);
int					distance_block(t_bord *data, int *i, int *j);
void				filler_algoritm(t_bord *data);
void				token_size(char *token, t_bord *data);
void				board_size(char *mapsize, t_bord *data);
void				whoami(char *line, t_bord *data);
#endif
