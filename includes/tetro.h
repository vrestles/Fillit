/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:44:12 by rtroll            #+#    #+#             */
/*   Updated: 2018/12/11 23:04:21 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRO_H
# define TETRO_H
# include "point.h"

typedef	struct			s_tetro
{
	struct s_point		point[4];
	char				letter;
}						t_tetro;

#endif
