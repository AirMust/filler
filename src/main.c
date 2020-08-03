/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:29:43 by lcharvol          #+#    #+#             */
/*   Updated: 2020/08/03 01:49:59 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void read_user(t_filler *tf)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && tf->iam == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			tf->iam = 'X';
			tf->he = 'O';
		}
		if (ft_strstr(line, "p1"))
		{
			tf->iam = 'O';
			tf->he = 'X';
		}
	}
	ft_strdel(&line);
}

void read_filler(t_filler *tf)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			read_object(line, tf, 0);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			read_object(line, tf, 1);
			ft_strdel(&line);
			return;
		}
		else
			ft_strdel(&line);
	}
}

t_filler *create_filler()
{
	t_filler *tf;

	tf = (t_filler *)malloc(sizeof(t_filler));
	tf->col = 0;
	tf->row = 0;
	tf->map = NULL;
	tf->token = NULL;
	tf->map_col = 0;
	tf->map_row = 0;
	tf->token_col = 0;
	tf->token_row = 0;
	tf->heat = NULL;
	tf->radius = 11;
	tf->iam = 0;
	tf->he = 0;
	return (tf);
}

int main(void)
{
	t_filler *tf;

	tf = create_filler();
	read_user(tf);
	while (1)
	{
		read_filler(tf);
		tf->radius = 11;
		filler_algorithm(tf);
		ft_free_matrix_char(&(tf->map), tf->map_row);
		ft_free_matrix_int(&(tf->heat), tf->map_row);
		ft_free_matrix_char(&(tf->token), tf->token_row);
		if (tf->radius == 11)
		{
			ft_printf("0 0\n");
			break;
		}
		ft_printf("%d %d\n", tf->row, tf->col);
	}
	free(tf);
	return (0);
}
