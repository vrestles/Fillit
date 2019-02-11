/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:12:04 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/14 21:57:47 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetro.h"
#include <stdlib.h>

static void		ft_remove_bias(t_tetro *ptr)
{
	int		num;
	int		min_i;
	int		min_j;

	min_i = ptr->point[0].i;
	min_j = ptr->point[0].j;
	num = 1;
	while (num < 4)
	{
		if (ptr->point[num].i < min_i)
			min_i = ptr->point[0].i;
		if (ptr->point[num].j < min_j)
			min_j = ptr->point[num].j;
		num++;
	}
	num = 0;
	while (num < 4)
	{
		ptr->point[num].i -= min_i;
		ptr->point[num].j -= min_j;
		num++;
	}
}

static int		ft_valid_tetro(t_tetro *ptr)
{
	int		res;
	int		num;
	int		oth;

	res = 0;
	num = 0;
	while (num < 4)
	{
		oth = 0;
		while (oth < 4)
		{
			if (ptr->point[num].i == ptr->point[oth].i && \
					(ptr->point[num].j - ptr->point[oth].j == -1 || \
					ptr->point[num].j - ptr->point[oth].j == 1))
				res++;
			if (ptr->point[num].j == ptr->point[oth].j && \
					(ptr->point[num].i - ptr->point[oth].i == -1 || \
					ptr->point[num].i - ptr->point[oth].i == 1))
				res++;
			oth++;
		}
		num++;
	}
	return ((res < 6) ? 1 : 0);
}

static t_tetro	*ft_delete_tetro(t_tetro *ptr)
{
	free(ptr);
	return (NULL);
}

t_tetro			*ft_make_tetro(char **tab, int bias)
{
	int		j;
	int		i;
	int		num;
	t_tetro	*ptr;

	num = 0;
	ptr = (t_tetro*)malloc(sizeof(t_tetro));
	ptr->letter = 'A' + bias;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tab[i][j] == '#')
			{
				if (num == 4)
					return (ft_delete_tetro(ptr));
				ptr->point[num].i = i;
				ptr->point[num++].j = j;
			}
	}
	ft_remove_bias(ptr);
	if (ft_valid_tetro(ptr))
		return (ft_delete_tetro(ptr));
	return (ptr);
}
