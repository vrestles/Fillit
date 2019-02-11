/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:04:40 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/14 23:43:15 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "./libft/libft.h"
#include "list_t.h"
#include <stdlib.h>

static char		**ft_alloc_map(int size)
{
	char	**ptr;
	int		i;

	ptr = (char**)malloc(sizeof(char**) * size + 1);
	i = 0;
	while (i < size)
	{
		ptr[i] = ft_strnew(size);
		(void)ft_memset((void*)ptr[i], '.', size);
		i++;
	}
	ptr[size] = NULL;
	return (ptr);
}

static void		ft_del_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(map);
		map++;
		i++;
	}
}

static void		ft_print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(map[i]);
		i++;
	}
}

static int		ft_solve(t_list_t *list, char **map, int size)
{
	t_point	prev[4];

	if (list == NULL)
		return (1);
	if (ft_place(list->tetro, map, size, prev))
	{
		if (ft_solve(list->next, map, size))
			return (1);
	}
	else
		return (0);
	while (ft_move(list->tetro, map, size, prev))
		if (ft_solve(list->next, map, size))
			return (1);
	return (0);
}

void			ft_solver(t_list_t *list)
{
	char	**map;
	int		size;

	size = 2;
	map = ft_alloc_map(size);
	while (ft_solve(list, map, size) == 0)
	{
		ft_del_map(map, size);
		map = ft_alloc_map(++size);
	}
	ft_print_map(map, size);
	ft_del_map(map, size);
}
