/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:06 by chorse            #+#    #+#             */
/*   Updated: 2022/06/27 16:51:47 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int g_ask;
int	g_exit_status;

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
	t_args *args;

	// printf("%d\n", )
	data = malloc(sizeof(t_data));
	args = NULL;
	data->flag = 0;
	signal(SIGINT, func_ex);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (data->line && data->line[0] != '\0')
		{	
			data->line = readline("\e[1;32mbash$ \e[0;37m");
			add_history(data->line);
			signal(SIGINT, func_ex);
			signal(SIGQUIT, SIG_IGN);
			parser(data, args);
		}
		else if (data->line == NULL)
		{
			write(1, "\33[2K\rminishell$ exit\n", 22);
			exit(0);
		}
		free(data->line);
		data->line = NULL;
		free_lst(args);
	}
	return (0);
}

// void func_ex(int sig)
// {
// 	g_exit_status += sig;
// 	if (sig == 2)
// 	{
// 		g_exit_status = 130;
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	if (sig == SIGQUIT)
// 	{
// 		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
// 		exit (1);
// 	}
// }

void parser(t_data *data, t_args *args)
{
	char *s;
	char *env;
	
	lexer(data, &args);
	// printf_token_list(args);
	// check_first(data, args);
	s = what_env(args);
	if (s[0] == '?')
	{	printf("%d\n", g_ask);
		return ;
	}
	if (g_ask == 1)
		return ;
	g_ask = 0;
	env = getenv(s);
	if (env != NULL)
		printf("%s\n", env);
	else
	{
		g_ask = 0;
		check_tokens(args);
		handler(args);
	}
}
