/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:17:22 by chorse            #+#    #+#             */
/*   Updated: 2022/06/20 14:16:43 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void lexer(t_data *data)
{
	int smb = 0;
	char *tmp;
	t_args *args;
	int len = 0;

	len = ft_strlen(data->line);
	args = malloc(1000);
	while (data->line[smb])
	{
		tmp = malloc(sizeof(char) * len);
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
		ft_create_lst(tmp, args);
		data->args = args;
		printf("%s\n", args->value);
		free(tmp);
	}
}
