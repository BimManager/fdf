/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_prj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:27:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 11:41:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_chgclr(t_imgdata *imgdt)
{
	ft_mtrxdel(&imgdt->cache->rotzmtrx);
	ft_mtrxdel(&imgdt->cache->transmtrx);
	ft_mtrxdel(&imgdt->cache->sclmtrx);
	imgdt->cache->rotzmtrx = ft_rotz_mtrx(0);
	imgdt->cache->transmtrx = ft_transmtrx(0, 0, 0);
	imgdt->cache->sclmtrx = ft_sclmtrx(1, 1, 1);
}

static void	prjhelp(t_windata *windt, t_matrix *viewpoint, t_matrix *normal)
{
	t_cache	*cache;

	ft_chgclr(windt->img_data);
	cache = windt->img_data->cache;
	ft_mtrxdel(&cache->prjmtrx);
	ft_mtrxdel(&cache->viewpoint);
	ft_mtrxdel(&cache->normal);
	cache->viewpoint = viewpoint;
	cache->normal = normal;
	cache->prjmtrx = ft_prjmtrx(cache->viewpoint, cache->normal);
}

void		prj0(t_windata *windt)
{
	t_imgdata	*imgdt;

	imgdt = windt->img_data;
	ft_mtrxdel(&imgdt->x_dir);
	ft_mtrxdel(&imgdt->y_dir);
	ft_mtrxdel(&imgdt->cache->mapmtrx);
	imgdt->x_dir = ft_rvecnew(1, 0, 0, 0);
	imgdt->y_dir = ft_rvecnew(1, 1, 0, 0);
	imgdt->cache->mapmtrx = ft_mapmtrx(imgdt->x_dir,
		imgdt->y_dir, imgdt->origin);
	prjhelp(windt, ft_rvecnew(1, 1, 1, 0), ft_rvecnew(0, 0, 1, 0));
	ft_vwpipln(imgdt);
	ft_imgplot(windt, imgdt->mapped);
}

void		prj1(t_windata *windt)
{
	t_imgdata	*imgdt;

	imgdt = windt->img_data;
	ft_mtrxdel(&imgdt->x_dir);
	ft_mtrxdel(&imgdt->y_dir);
	ft_mtrxdel(&imgdt->cache->mapmtrx);
	imgdt->x_dir = ft_rvecnew(1, 0, 0, 0);
	imgdt->y_dir = ft_rvecnew(0, 1, 0, 0);
	imgdt->cache->mapmtrx = ft_mapmtrx(imgdt->x_dir,
		imgdt->y_dir, imgdt->origin);
	prjhelp(windt, ft_rvecnew(1, 1, 1, 0), ft_rvecnew(0, 0, 1, 0));
	ft_vwpipln(imgdt);
	ft_imgplot(windt, imgdt->mapped);
}

void		prj2(t_windata *windt)
{
	t_imgdata	*imgdt;

	imgdt = windt->img_data;
	ft_mtrxdel(&imgdt->x_dir);
	ft_mtrxdel(&imgdt->y_dir);
	ft_mtrxdel(&imgdt->cache->mapmtrx);
	imgdt->x_dir = ft_rvecnew(1, 0, 0, 0);
	imgdt->y_dir = ft_rvecnew(0, 1, 0, 0);
	imgdt->cache->mapmtrx = ft_mapmtrx(imgdt->x_dir,
		imgdt->y_dir, imgdt->origin);
	prjhelp(windt, ft_rvecnew(0, 0, 1, 0), ft_rvecnew(0, 0, 1, 0));
	ft_vwpipln(windt->img_data);
	ft_imgplot(windt, windt->img_data->mapped);
}
