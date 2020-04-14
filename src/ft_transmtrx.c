/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmtrx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:52:53 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/08 11:53:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_transmtrx(double x, double y, double z)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 4);
	(ret->tab)[0][0] = 1;
	(ret->tab)[1][1] = 1;
	(ret->tab)[2][2] = 1;
	(ret->tab)[3][3] = 1;
	(ret->tab)[0][3] = x;
	(ret->tab)[1][3] = y;
	(ret->tab)[2][3] = z;
	return (ret);
}
