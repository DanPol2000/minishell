/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:06 by chorse            #+#    #+#             */
/*   Updated: 2022/06/13 17:39:59 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}


int main(int ac, char **av, char **env)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	env_check(data, env);
	printf("AC = %d\n", ac);
	printf("AV %s\n", av[1]);
}

void env_check(t_data *data, char **env)
{
	int d = 0;
	int i = -1;
	int t = 0;
	t_env *env_list;
	char *value;
	char *key;
	while (env[t])
	{
		d = 0; 
		i = 0;
		env_list = malloc(sizeof(t_env));
		data->env_save = env_list;
		while (env[0][d] != '=')
			d++;
		key = malloc(sizeof(char) * d);
		d = 0;
		while (env[t][d] != '=')
			key[i++] = env[t][d++];
		key[i] = '\0';
		value = malloc(sizeof(char) * (ft_strlen(env[t]) - d) + 1);
		i = 0;
		while (env[t][d++])
			value[i++] = env[t][d++];
		value[i] = '\0';
		env_list->key = key;
		env_list->value = value;
		printf("KEY = %s\n", env_list->key);
		printf("Value = %s\n", env_list->value);
		t++;
	}
}