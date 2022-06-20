/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:59:05 by chorse            #+#    #+#             */
/*   Updated: 2022/06/20 14:06:08 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_args
{
	char			*value;
	struct s_args	*next;
}	t_args;

typedef struct s_data
{
	char	*line;
	t_args	*args;
	t_env	*env_save;
}	t_data;

void	env_check(t_data *data, char **env);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	lexer(t_data *data);
int		is_space(char c);
void	ft_create_lst(char *tmp, t_args *args);
void	ft_lstadd_back(t_args *lst, t_args *new);
t_args	*ft_lstlast(t_args *lst);
t_args	*ft_lstnew(void *value);
int		ft_lstsize(t_args *lst);
void	handler(t_data *data);
#endif