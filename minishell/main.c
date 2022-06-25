/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:06 by chorse            #+#    #+#             */
/*   Updated: 2022/06/25 15:16:30 by chorse           ###   ########.fr       */
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

int main()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->line = readline("\e[1;32mbash$ \e[0;37m");
	add_history(data->line);
	parser(data);
	return (0);
}
