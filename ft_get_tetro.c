/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:43:45 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/15 22:09:16 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "tetro.h"
#include "libft/libft.h"
#include <stdio.h>

static int		ft_check_char(char *str)
{
	while (*str != '\0')
	{
		if (*str != '.' && *str != '#')
			return (1);
		str++;
	}
	return (0);
}

static int		ft_error(char *str, int i, int bias)
{
	if ((i >= 0 && i < 4) && (ft_strlen(str) != 4 || ft_check_char(str) == 1))
		return (1);
	if (bias > 25 || (i == 4 && str[0] != '\0'))
		return (1);
	return (0);
}

static t_list_t	*ft_delete_list(t_list_t *list)
{
	ft_putendl("error");
	ft_ldel(&list);
	return (NULL);
}

static void		ft_free_tmp(char **tmp, int *i)
{
	int			j;

	j = 0;
	while (j < 5)
	{
		ft_strdel(tmp);
		tmp++;
		j++;
	}
	*i = 0;
}

t_list_t		*ft_get_tetro(int fd)
{
	int			i;
	int			bias;
	char		*tmp[5];
	t_tetro		*ptr;
	t_list_t	*list;

	list = NULL;
	i = 0;
	bias = 0;
	while (get_next_line(fd, &tmp[i]))
	{
		if (ft_error(tmp[i], i, bias))
			return (ft_delete_list(list));
		if (i % 3 == 0 && i > 0)
		{
			if ((ptr = ft_make_tetro(tmp, bias++)) == NULL)
				return (ft_delete_list(list));
			ft_ladd(&list, ptr);
		}
		if (++i == 5)
			ft_free_tmp(tmp, &i);
	}
	if (i != 4)
		return (ft_delete_list(list));
	return (list);
}
