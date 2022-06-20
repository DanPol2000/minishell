/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:14:30 by chorse            #+#    #+#             */
/*   Updated: 2022/06/19 15:19:21 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}


int	ft_lstsize(t_args *lst)
{
	t_args	*s;
	int		i;

	i = 0;
	s = lst;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void ft_create_lst(char *tmp, t_args *args)
{
	t_args	*new;

	new = ft_lstnew(tmp);
	args = new;
	args->next = NULL;
	if (ft_lstsize(args) > 1)
	{
		ft_lstadd_back(args, new);
		args->next = NULL;
	}
}

t_args	*ft_lstnew(void *value)
{
	t_args	*new = NULL;

	new = malloc(sizeof(t_args));
	if (new)
	{
		new->value = value;
		new->next = NULL;
	}
	return (new);
}

t_args	*ft_lstlast(t_args *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_args *lst, t_args *new)
{
	t_args	*tmp;

	if (lst != NULL && lst != NULL)
	{
		tmp = ft_lstlast(lst);
		tmp->next = new;
	}
	else 
		lst = new;
}

int is_space(char c)
{
	if (c == ' ' || c == '	' || c == '\t' || \
		c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}
