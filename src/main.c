/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:29:43 by lcharvol          #+#    #+#             */
/*   Updated: 2020/08/01 14:49:51 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

// void get_real_piece_size(t_piece *p)
// {
// 	int i;
// 	int i2;

// 	i = -1;
// 	p->start_x = p->size_x;
// 	p->start_y = p->size_y;
// 	while (++i < p->size_y)
// 	{
// 		i2 = -1;
// 		while (++i2 < p->size_x)
// 			if (p->piece[i][i2] == '*')
// 			{
// 				if (i2 < p->start_x)
// 					p->start_x = i2;
// 				if (i2 > p->end_x)
// 					p->end_x = i2;
// 				if (i < p->start_y)
// 					p->start_y = i;
// 				if (i > p->end_y)
// 					p->end_y = i;
// 			}
// 	}
// 	p->real_size_x = (p->end_x - p->start_x) + 1;
// 	p->real_size_y = (p->end_y - p->start_y) + 1;
// }

// void get_piece(t_piece *p)
// {
// 	int i;
// 	char *line;

// 	i = 0;
// 	if (p->piece != NULL)
// 		free(p->piece);
// 	p->piece = (char **)malloc(sizeof(char *) * (p->size_y + 1));
// 	while (i < p->size_y)
// 	{
// 		get_next_line(0, &line);
// 		p->piece[i] = (char *)malloc(sizeof(char *) * (p->size_x + 1));
// 		p->piece[i] = ft_strcpy(p->piece[i], (const char *)line);
// 		i++;
// 		ft_strdel(&line);
// 	}
// 	get_real_piece_size(p);
// }

// void get_piece_size(char *line, t_piece *p)
// {
// 	int i;
// 	int tmp;

// 	i = 0;
// 	p->size_x = 0;
// 	p->size_y = 0;
// 	while (line[i])
// 	{
// 		tmp = 0;
// 		while (is_number(line[i]) == 0 && line[i])
// 		{
// 			tmp += line[i] - 48;
// 			if (is_number(line[i + 1]) == 0)
// 				tmp *= 10;
// 			i++;
// 		}
// 		if (p->size_y == 0)
// 			p->size_y = tmp;
// 		else if (p->size_x == 0)
// 			p->size_x = tmp;
// 		i++;
// 	}
// 	ft_strdel(&line);
// 	get_piece(p);
// }

// void get_id_player(t_filler *current)
// {
// 	char *line;

// 	get_next_line(0, &line);
// 	if (ft_strncmp(line, "$$$", 2) == 0 && current->player == 0)
// 	{
// 		if (ft_strstr(line, "p2"))
// 		{
// 			current->player = 'X';
// 			current->opponent = 'O';
// 		}
// 		if (ft_strstr(line, "p1"))
// 		{
// 			current->player = 'O';
// 			current->opponent = 'X';
// 		}
// 	}
// 	ft_strdel(&line);
// }
// void			get_player(t_map *map)
// {
// 	char		*line;

// 	get_next_line(0, &line);
// 	if (ft_strncmp(line, "$$$", 2) == 0 && map->player == 0)
// 	{
// 		if (ft_strstr(line, "p2"))
// 			map->player = 2;
// 		if (ft_strstr(line, "p1"))
// 			map->player = 1;
// 		wich_player(map);
// 	}
// 	ft_strdel(&line);
// }

// void get_map(t_map *map)
// {
// 	int i;
// 	char *line;

// 	i = -1;
// 	ft_get_next_line(0, &line);
// 	ft_strdel(&line);
// 	map->map = (char **)malloc(sizeof(char *) * (map->map_size_y + 1));
// 	while (++i <= (map->map_size_y - 1))
// 	{
// 		ft_get_next_line(0, &line);
// 		map->map[i] = ft_strdup((const char *)(&line[4]));
// 		ft_strdel(&line);
// 	}
// }

void read_object_value(t_filler *tf, int flag)
{
	int i;
	char *line;
	char **temp_map;
	int temp_count_row;

	temp_count_row = (flag == 0 ? tf->map_row : tf->token_row);
	temp_map = (flag == 0 ? tf->map : tf->token);

	i = -1;
	IF_TRUE(flag == 0, get_next_line(0, &line));
	IF_TRUE(flag == 0, ft_strdel(&line));
	temp_map = (char **)malloc(sizeof(char *) * (temp_count_row + 1));
	while (++i < temp_count_row)
	{
		get_next_line(0, &line);
		temp_map[i] = ft_strdup((const char *)(&line[flag == 0 ? 4 : 0]));
		ft_strdel(&line);
	}
	IF_TRUE(flag == 0, tf->map = temp_map);
	IF_TRUE(flag == 1, tf->token = temp_map);
}

void read_object_size(char *line, t_filler *tf, int flag)
{
	char **actor;

	actor = ft_strsplit(line, ' ');
	if (flag == 0)
	{
		tf->map_row = ft_atoi(actor[1]);
		tf->map_col = ft_atoi(actor[2]);
	}
	else if (flag == 1)
	{
		tf->token_row = ft_atoi(actor[1]);
		tf->token_col = ft_atoi(actor[2]);
	}
	ft_strsplitfree(&actor);
}

void correction_token(t_filler *tf)
{
	int end_row;
	int end_col;
	int st_row;
	int st_col;
	int i;
	int j;
	char **temp_token;

	st_row = tf->token_row;
	st_col = tf->token_col;
	end_row = 0;
	end_col = 0;
	i = -1;
	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
		{
			if(tf->token[i][j] == '*')
			{
				IF_TRUE(i < st_row, st_row = i);
				IF_TRUE(j < st_col, st_col = j);
				IF_TRUE(i > end_row, end_row = i);
				IF_TRUE(j > end_col, end_col = j);
			}
		}
	}
	temp_token = (char **)malloc(sizeof(char *) * (end_row - st_row + 2));
	i = st_row - 1;
	while(++i < end_row + 1)
	{
		temp_token[i] = ft_strdup(ft_strsub(tf->token[i], st_col, end_col - st_col + 1));
	}
	ft_free_matrix_char(&(tf->token), tf->token_row);
	tf->token = temp_token;
	tf->token_row = end_row - st_row + 1;
	tf->token_col = end_col - st_col + 1;
	// printf("%d %d\n", tf->token_row, tf->token_col);
	// i = -1;
	// while(++i < tf->token_row)
	// 	printf("%s\n", tf->token[i]);

}

void read_object(char *line, t_filler *tf, int flag)
{
	read_object_size(line, tf, flag);
	read_object_value(tf, flag);
	IF_TRUE(flag == 1, correction_token(tf));
}

void read_user(t_filler *tf)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && tf->player == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			tf->player = 'X';
			tf->opponent = 'O';
		}
		if (ft_strstr(line, "p1"))
		{
			tf->player = 'O';
			tf->opponent = 'X';
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
	tf->tmp_col = 0;
	tf->tmp_row = 0;
	tf->map = NULL;
	tf->token = NULL;
	tf->map_col = 0;
	tf->map_row = 0;
	tf->token_col = 0;
	tf->token_row = 0;
	tf->radius = 100500;
	tf->player = 0;
	tf->opponent = 0;
	return (tf);
}

int main(void)
{
	t_filler *tf;
	int i;

	tf = create_filler();

	i = 0;
	read_user(tf);
		// read_filler(tf);

	while (i++ < 1)
	{
		read_filler(tf);

		filler_algoritm(tf);
	}
	// ft_printf("%d %d \n", tf->map_row, tf->map_col);
	// ft_printf("%d %d \n", tf->token_row, tf->token_col);

	ft_free_matrix_char(&(tf->map), tf->map_row);
	ft_free_matrix_char(&(tf->token), tf->token_row);
	free(tf);
	return (0);
}
