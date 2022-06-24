/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:06 by chorse            #+#    #+#             */
/*   Updated: 2022/06/24 13:55:59 by chorse           ###   ########.fr       */
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
	(void )env;
	// env_check(data, env);
	data->line = readline("\e[1;32mbash$ \e[0;37m");
	add_history(data->line);
	printf("AC = %d\n", ac);
	printf("AC = %s\n", av[1]);
	parser(data);
	return (0);
}
