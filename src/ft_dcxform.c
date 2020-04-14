/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcxform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:23:24 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 16:58:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_matrix	*ft_cvec4x4rvec3x3(t_matrix *vec)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(1, 3);
	(ret->tab)[0][0] = (vec->tab)[0][0];
	(ret->tab)[0][1] = (vec->tab)[1][0];
	(ret->tab)[0][2] = (vec->tab)[3][0];
	return (ret);
}

void			ft_dcxform(t_matrix **vec, t_imgdata *imgdt)
{
	t_matrix	*dc;
	t_matrix	*res;
	t_matrix	*tmp;
	int			w;

	dc = ft_mtrxnew(3, 3);
	(dc->tab)[0][0] = (WIN_WIDTH - 2 * OFFSET) / (imgdt->xmax - imgdt->xmin);
	(dc->tab)[1][1] = (WIN_HEIGHT - 2 * OFFSET) / (imgdt->ymax - imgdt->ymin);
	(dc->tab)[2][0] = (imgdt->xmax * OFFSET - imgdt->xmin
		* (WIN_WIDTH - OFFSET)) / (imgdt->xmax - imgdt->xmin);
	(dc->tab)[2][1] = (imgdt->ymax * OFFSET - imgdt->ymin
		* (WIN_HEIGHT - OFFSET)) / (imgdt->ymax - imgdt->ymin);
	tmp = ft_cvec4x4rvec3x3(*vec);
	res = ft_mtrxmul(tmp, dc);
	ft_mtrxdel(&dc);
	ft_mtrxdel(&tmp);
	w = ((*vec)->tab)[3][0];
	((*vec)->tab)[0][0] = w ? (res->tab)[0][0] / w : -(res->tab)[0][0];
	((*vec)->tab)[1][0] = w ? (res->tab)[0][1] / w : -(res->tab)[0][1];
	ft_mtrxdel(&res);
}
