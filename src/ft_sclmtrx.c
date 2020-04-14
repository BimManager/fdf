/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclmtrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:59:53 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/08 12:00:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_sclmtrx(double x, double y, double z)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 4);
	(ret->tab)[0][0] = x;
	(ret->tab)[1][1] = y;
	(ret->tab)[2][2] = z;
	(ret->tab)[3][3] = 1;
	return (ret);
}
