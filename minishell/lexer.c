/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:17:22 by chorse            #+#    #+#             */
/*   Updated: 2022/06/24 18:34:31 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void parser(t_data *data)
{
	t_args *args;
	char *s;
	char *env;
	
	args = NULL;
	lexer(data, &args);
	// printf_token_list(args);
	// handler(args);
	s = what_env(args);
	env = getenv(s);
	printf("ENV = %s\n", env);
}

char  *what_env(t_args *args)
{
	t_args *tmp;
	int i = 0;
	int y = 0;
	char *env;
	
	env = malloc(100);
	tmp = args;
	while (tmp)
	{
		i = 0;
		while (i < ft_strlen(tmp->value))
		{
			if (tmp->value[i] == '$')
			{
				i++;
				while (tmp->value[i])
				{
					env[y] = tmp->value[i];
					y++;
					i++;
				}
				return env;
			}
			i++;	
		}
		tmp = tmp->next;
	}
	env[i] = '\0';
	return env;
}

void	printf_token_list(t_args *token_list)
{
	t_args	*tmp_token;
	
	tmp_token = token_list;
	printf("\n\n%p\n", token_list);
	printf("TOKEN_LIST:\n\n");
	while (tmp_token)
	{
		printf("%s|", tmp_token->value);
		tmp_token = tmp_token->next;
	}
}

void lexer(t_data *data, t_args **args)
{
	int smb = 0;
	char *tmp;
	int len = 0;

	len = ft_strlen(data->line);
	// args = malloc(10000);
	while (data->line[smb])
	{
		tmp = malloc(sizeof(char) * (len + 1));
		int i = 0;
		if (is_space(data->line[smb]))
		{
			while (is_space(data->line[smb]))
				smb++;
		}
		if (data->line[smb])
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
		smb++;
		tmp[i] = '\0';
		printf("STR = %s\n", tmp);
		ft_create_lst(tmp, args);
		// printf("%s\n", data->args->value);
		free(tmp);
	}
}
