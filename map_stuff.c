/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:59:52 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/15 22:00:04 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "./libft/libft.h"
#include "list_t.h"

static int	ft_draw_tetro(char **map, t_tetro *tet, int *t, t_point *p)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		map[tet->point[k].i + t[0]][tet->point[k].j + t[1]] = tet->letter;
		p[k].i = tet->point[k].i + t[0];
		p[k].j = tet->point[k].j + t[1];
		k++;
	}
	return (1);
}

static int	ft_suitable_for_map(t_tetro *tetro, int size, int i, int j)
{
	int		max_i;
	int		max_j;
	int		k;

	if (tetro == NULL)
		return (0);
	max_i = tetro->point[0].i;
	max_j = tetro->point[0].j;
	k = 1;
	while (k < 4)
	{
		if (tetro->point[k].i + i > max_i)
			max_i = tetro->point[k].i + i;
		if (tetro->point[k].j + j > max_j)
			max_j = tetro->point[k].j + j;
		k++;
	}
	if (max_j >= size || max_i >= size)
		return (1);
	return (0);
}

int			ft_place(t_tetro *t, char **map, int size, t_point *prev)
{
	int		tab[2];
	int		k;
	int		count;

	tab[0] = -1;
	count = 0;
	while (++tab[0] < size)
	{
		tab[1] = -1;
		while (++tab[1] < size)
		{
			k = -1;
			while (++k < 4)
			{
				if (ft_suitable_for_map(t, size, tab[0], tab[1]))
					break ;
				if (map[t->point[k].i + tab[0]][t->point[k].j + tab[1]] == '.')
					count++;
			}
			if (count == 4)
				return (ft_draw_tetro(map, t, tab, prev));
			count = 0;
		}
	}
	return (0);
}

static int	ft_count_points(char **map, t_tetro *t, t_point *p, int *i)
{
	int		k;
	int		count;

	k = 0;
	count = 0;
	while (k < 4)
	{
		if (ft_suitable_for_map(t, i[2], i[0], i[1]))
			break ;
		if (map[t->point[k].i + i[0]][t->point[k].j + i[1]] == '.'
	&& ((t->point[k].i + i[0]) != p[k].i || (t->point[k].j + i[1]) != p[k].j))
			count++;
		k++;
	}
	return (count);
}

int			ft_move(t_tetro *t, char **map, int size, t_point *p)
{
	int		i[3];
	int		k;
	int		count;

	k = -1;
	i[2] = size;
	while (++k < 4)
		map[p[k].i][p[k].j] = '.';
	i[0] = p[0].i - 1;
	count = 0;
	while (++i[0] < size)
	{
		i[1] = p[0].j - 1 - t->point[0].j;
		while (++i[1] < size)
		{
			count = ft_count_points(map, t, p, i);
			if (count == 4)
				return (ft_draw_tetro(map, t, i, p));
			count = 0;
		}
		p[0].j = 0;
	}
	return (0);
}
