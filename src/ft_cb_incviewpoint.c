/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_incviewpoint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:30:57 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 14:30:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	chng(t_windata *windt, int col, int val)
{
	t_imgdata	*imgdt;
	t_cache		*cache;

	imgdt = windt->img_data;
	cache = imgdt->cache;
	(cache->viewpoint->tab)[0][col] += val;
	ft_mtrxdel(&cache->prjmtrx);
	cache->prjmtrx = ft_prjmtrx(cache->viewpoint, cache->normal);
	ft_vwpipln(imgdt);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	xinc(t_windata *windt)
{
	chng(windt, 0, 1);
}

void	yinc(t_windata *windt)
{
	chng(windt, 1, 1);
}

void	zinc(t_windata *windt)
{
	chng(windt, 2, 1);
}
