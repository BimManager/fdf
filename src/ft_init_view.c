/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:06:31 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 15:45:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** origin (x, y, z, 1)
** w = 1 (always)
*/

t_view	*ft_init_view(t_imgdata *imgdt)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	ft_bzero(view, sizeof(t_view));
	view->viewpoint = ft_rvecnew(imgdt->xymax, imgdt->xymax, imgdt->zmax, 0);
	view->plane_normal = ft_rvecnew(0, 0, 1, 0);
	view->origin = ft_rvecnew(0, 0, 0, 1);
	view->x_dir = ft_rvecnew(1, 0, 0, 0);
	view->y_dir = ft_rvecnew(1, 1, 0, 0);
	return (view);
}
