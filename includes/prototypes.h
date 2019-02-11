/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:56:19 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/14 22:38:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "list_t.h"

t_tetro		*ft_make_tetro(char **tab, int bias);
t_list_t	*ft_get_tetro(int fd);
t_list_t	*ft_lnew(t_tetro *content);
void		ft_ladd(t_list_t **alst, t_tetro *content);
void		ft_ldel(t_list_t **alst);
void		ft_solver(t_list_t *list);
int			ft_move(t_tetro *tetro, char **map, int size, t_point *prev);
int			ft_place(t_tetro *tetro, char **map, int size, t_point *prev);

#endif
