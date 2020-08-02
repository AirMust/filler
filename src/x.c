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
			if (tf->token[i][j] == '*')
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
	while (++i < end_row + 1)
	{

		temp_token[i - st_row] = ft_strdup(ft_strsub(tf->token[i], st_col, end_col - st_col + 1));
	}
	temp_token[i - st_row] = 0;
	ft_free_matrix_char(&(tf->token), tf->token_row);
	tf->token = temp_token;
	tf->token_row = end_row - st_row + 1;
	tf->token_col = end_col - st_col + 1;
}


int algorithm_step_2(t_filler *tf, int y, int x)
{
	int i;
	int j;
	int perec;

	i = -1;
	perec = 0;
	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
		{
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->iam ||
										   tf->map[y + i][x + j] == tf->iam + 32))
				perec++;
			if (tf->token[i][j] == '*' && (tf->map[y + i][x + j] == tf->he ||
										   tf->map[y + i][x + j] == tf->he + 32))
				return (0);
		}
	}
	if (perec == 1)
		return (1);
	return (0);
}

int algorithm_step_1(t_filler *tf, int row, int col)
{
	int i;
	int j;

	i = -1;
	while (++i < tf->token_row)
	{
		j = -1;
		while (++j < tf->token_col)
		{
			if (tf->token[i][j] == '*' && row - i >= 0 &&
				row + (tf->token_row - i - 1) < tf->map_row && col - j >= 0 &&
				col + (tf->token_col - j - 1) < tf->map_col)
			{
				if (algorithm_step_2(tf, row - i, col - j) == 1)
				{
					tf->radius = 100;
					tf->row = row - i;
					tf->col = col - j;
					return (1);
				}
			}
		}
	}
	return (0);
}

void filler_algorithm(t_filler *tf)
{
	int i;
	int j;
	int flag;

	flag = 0;
	flag += tf->row >= tf->map_row / 2 ? 2 : 0;
	flag += tf->col >= tf->map_col / 2 ? 1 : 0;
	i = flag < 2 ? tf->map_row - 1 : 0;
	while (flag < 2 ? i >= 0 : i < tf->map_row)
	{
		j = flag % 2 == 0 ? tf->map_col - 1 : 0;
		while (flag % 2 == 0 ? j >= 0 : j < tf->map_col)
		{

			if (algorithm_step_1(tf, i, j) == 1)
				return;
			j = j + (flag % 2 == 0 ? -1 : 1);
		}
		i = i + (flag < 2 ? -1 : 1);
	}
}
