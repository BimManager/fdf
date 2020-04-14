/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cachenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:44:29 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 10:34:32 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cache	*ft_cachenew(t_imgdata *imgdt)
{
	t_cache	*ret;

	ret = malloc(sizeof(t_cache));
	ret->viewpoint = ft_rvecnew(1, 1, 1, 0);
	ret->normal = ft_rvecnew(0, 0, 1, 0);
	ret->prjmtrx = ft_prjmtrx(ret->viewpoint, ret->normal);
	ret->mapmtrx = ft_mapmtrx(imgdt->x_dir, imgdt->y_dir, imgdt->origin);
	ret->rotzmtrx = ft_rotz_mtrx(0);
	ret->transmtrx = ft_transmtrx(0, 0, 0);
	ret->sclmtrx = ft_sclmtrx(1, 1, 1);
	return (ret);
}
