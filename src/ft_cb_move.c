/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:29:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 14:56:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mvleft(t_windata *windt)
{
	ft_vectrans(windt->img_data, -1, 0);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	mvright(t_windata *windt)
{
	ft_vectrans(windt->img_data, 1, 0);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	mvup(t_windata *windt)
{
	ft_vectrans(windt->img_data, 0, -1);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	mvdown(t_windata *windt)
{
	ft_vectrans(windt->img_data, 0, 1);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	zrot(t_windata *windt)
{
	static double	gamma;

	gamma += M_PI / 4;
	ft_mtrxdel(&windt->img_data->cache->rotzmtrx);
	windt->img_data->cache->rotzmtrx = ft_rotz_mtrx(gamma);
	ft_vwpipln(windt->img_data);
	ft_imgplot(windt, windt->img_data->mapped);
}
