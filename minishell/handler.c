/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:15:13 by chorse            #+#    #+#             */
/*   Updated: 2022/06/20 14:07:54 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void handler(t_data *data)
{
	while (data->args)
	{
		printf("Args = %s\n", data->args->value);
		data->args = data->args->next;
	}
}