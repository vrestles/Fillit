/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:37:17 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/14 20:30:29 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "tetro.h"
#include <fcntl.h>
#include "./libft/libft.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_list_t	*tet;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}
	tet = ft_get_tetro(fd);
	if (tet == NULL)
		return (0);
	ft_solver(tet);
	ft_ldel(&tet);
	return (0);
}
