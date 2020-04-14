/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_decviewpoint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:31:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 14:31:44 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xdec(t_windata *windt)
{
	chng(windt, 0, -1);
}

void	ydec(t_windata *windt)
{
	chng(windt, 1, -1);
}

void	zdec(t_windata *windt)
{
	chng(windt, 2, -1);
}
