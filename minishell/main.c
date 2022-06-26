/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:06 by chorse            #+#    #+#             */
/*   Updated: 2022/06/26 16:52:39 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static int g_ask;

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main()
{
	t_data *data;

	printf("%d\n", g_ask);
	data = malloc(sizeof(t_data));
	data->line = readline("\e[1;32mbash$ \e[0;37m");
	add_history(data->line);
	parser(data);
	return (0);
}

void parser(t_data *data)
{
	t_args *args;
	char *s;
	char *env;
	
	args = NULL;
	lexer(data, &args);
	// printf_token_list(args);
	s = what_env(args);
	if (s[0] == '?')
	{	printf("%d\n", g_ask);
		return ;
	}
	env = getenv(s);
	if (env != NULL)
		printf("%s\n", env);
	else
	{
		check_tokens(args);
		handler(args);
	}
}

void lexer(t_data *data, t_args **args)
{
	int smb = 0;
	char *tmp;
	int len = 0;
	

	len = ft_strlen(data->line);
	while (data->line[smb])
	{
		tmp = malloc(sizeof(char) * (len + 1));
		int i = 0;
		int key = 0;
		if (is_space(data->line[smb])) //skip space
		{
			while (is_space(data->line[smb]))
				smb++;
		}
		if (data->line[smb] && !is_space(data->line[smb])) //check general symbols
		{
			if (data->line[smb] != '"' && data->line[smb] != 39)  
			{
							
				while (data->line[smb] && !is_space(data->line[smb]))
				{
					if (ft_strlen(tmp) < 1)
					{
						tmp[i] = data->line[smb];
						i++;
						smb++;
					}
					else
					{
						tmp[i] = data->line[smb];
						smb++;
						i++;
					}
				}
			}
			if (data->line[smb] == 39 && !is_space(data->line[smb])) //check single_quote
			{
				smb++;
				key = 1;
				if (data->line[smb] == '\0')
				{
						write(1, "\33[2K\rLack of second quote\n", 26);
						g_ask = 1;
						printf("G = %d\n", g_ask);
						break ;
				}
				while (data->line[smb] && data->line[smb] != 39)
				{
					
					if (data->line[smb+1] == '\0')
					{
						write(1, "\33[2K\rLack of second quote\n", 26);
						g_ask = 1;
						printf("G = %d\n", g_ask);
						break ;
					}
					else
					{
						tmp[i] = data->line[smb];
						smb++;
						i++;
					}
				}
				
				smb++;
			}
			if (data->line[smb] == '"' && !is_space(data->line[smb])) //check double_quote
			{
				smb++;
				key = 2;
				if (data->line[smb] == '\0')
				{
						write(1, "\33[2K\rLack of second quote\n", 26);
						g_ask = 1;
						printf("G = %d\n", g_ask);
						break ;
				}
				while (data->line[smb] && data->line[smb] != '"')
				{
					if (data->line[smb+1] == '\0')
					{
						write(1, "\33[2K\rLack of second quote\n", 26);
						g_ask = 1;
						printf("G = %d\n", g_ask);
						break ;
					}
					else
					{
						tmp[i] = data->line[smb];
						smb++;
						i++;
					}
				}
				smb++;
			}
		}
		smb++;
		tmp[i] = '\0';
		// printf("STR = %s\n", tmp);
		ft_create_lst(tmp, args, key);
		free(tmp);
	}
}
