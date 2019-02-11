/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:25:12 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/14 21:14:41 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_t.h"
#include <stdlib.h>

t_list_t	*ft_lnew(t_tetro *content)
{
	t_list_t	*ptr;

	ptr = (t_list_t*)malloc(sizeof(t_list_t));
	if (ptr == NULL)
		return (NULL);
	ptr->next = NULL;
	ptr->tetro = content;
	return (ptr);
}

void		ft_ladd(t_list_t **alst, t_tetro *content)
{
	t_list_t	*tmp;

	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = ft_lnew(content);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lnew(content);
}

void		ft_ldel(t_list_t **alst)
{
	t_list_t	*tmp;
	t_list_t	*next;

	if (*alst == NULL)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->tetro);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
