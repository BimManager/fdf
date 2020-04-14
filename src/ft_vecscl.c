/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecscl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:11:59 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 14:05:44 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vecscl(t_imgdata *imgdt, double x, double y)
{
	t_list		*it;
	t_matrix	*scl;

	it = ft_queuepeek(imgdt->mapped);
	scl = imgdt->cache->sclmtrx;
	(scl->tab)[0][0] = x;
	(scl->tab)[1][1] = y;
	ft_vecxform(it, scl);
}
