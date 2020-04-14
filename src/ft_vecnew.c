/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:22:17 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 14:22:25 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_cvecnew(double x, double y, double z, double w)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 1);
	(ret->tab)[0][0] = x;
	(ret->tab)[1][0] = y;
	(ret->tab)[2][0] = z;
	(ret->tab)[3][0] = w;
	return (ret);
}

t_matrix	*ft_rvecnew(double x, double y, double z, double w)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(1, 4);
	(ret->tab)[0][0] = x;
	(ret->tab)[0][1] = y;
	(ret->tab)[0][2] = z;
	(ret->tab)[0][3] = w;
	return (ret);
}
