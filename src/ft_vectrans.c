/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectrans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:02:02 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 15:04:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vectrans(t_imgdata *imgdt, double x, double y)
{
	t_list		*it;
	t_matrix	*trans;

	it = ft_queuepeek(imgdt->mapped);
	trans = imgdt->cache->transmtrx;
	(trans->tab)[0][3] = x;
	(trans->tab)[1][3] = y;
	ft_vecxform(it, trans);
}
