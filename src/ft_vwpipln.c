/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vwpipln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:29:27 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 11:36:11 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_maxmin(t_imgdata *imgdt, t_matrix *vec)
{
	double	w;

	w = (vec->tab)[3][0];
	if (w)
	{
		imgdt->xmin = imgdt->xmin > (vec->tab)[0][0] / w
			? (vec->tab)[0][0] / w : imgdt->xmin;
		imgdt->ymin = imgdt->ymin > (vec->tab)[1][0] / w
			? (vec->tab)[1][0] / w : imgdt->ymin;
		imgdt->xmax = imgdt->xmax < (vec->tab)[0][0] / w
			? (vec->tab)[0][0] / w : imgdt->xmax;
		imgdt->ymax = imgdt->ymax < (vec->tab)[1][0] / w
			? (vec->tab)[1][0] / w : imgdt->ymax;
	}
}

static void	resetmaxmin(t_imgdata *imgdt)
{
	imgdt->xmin = 0;
	imgdt->ymin = 0;
	imgdt->xmax = 0;
	imgdt->ymax = 0;
}

void		ft_vwpipln(t_imgdata *imgdt)
{
	t_list	*it;
	double	z;

	ft_queuecp(&imgdt->mapped, imgdt->points, imgdt->cache);
	it = ft_queuepeek(imgdt->mapped);
	resetmaxmin(imgdt);
	while (it)
	{
		if (it->content_size)
		{
			z = (((t_matrix *)it->content)->tab)[2][0];
			ft_vecprj((t_matrix **)&it->content, imgdt->cache->prjmtrx);
			ft_vecmap((t_matrix **)&it->content, imgdt->cache->mapmtrx);
			ft_maxmin(imgdt, it->content);
			(((t_matrix *)(it->content))->tab)[2][0] = z;
		}
		it = it->next;
	}
	it = ft_queuepeek(imgdt->mapped);
	while (it)
	{
		if (it->content_size)
			ft_dcxform((t_matrix **)&it->content, imgdt);
		it = it->next;
	}
}
