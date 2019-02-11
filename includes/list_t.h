/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_t.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:45:22 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/11 23:34:20 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_T_H
# define LIST_T_H
# include "tetro.h"

typedef	struct			s_list_t
{
	struct s_tetro		*tetro;
	struct s_list_t		*next;
}						t_list_t;

#endif
