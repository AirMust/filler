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
