/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:15:13 by chorse            #+#    #+#             */
/*   Updated: 2022/06/24 17:33:15 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void handler(t_args *args)
{
	t_args	*tmp;

	tmp = args;
	while (tmp)
	{
		printf("%s|", tmp->value);
		tmp = tmp->next;
	}
}