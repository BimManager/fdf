/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:45:48 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 10:35:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_cvecnorm(t_matrix *vec)
{
	t_matrix	*ret;
	double		mag;

	ret = ft_cvecnew((vec->tab)[0][0], (vec->tab)[1][0],
		(vec->tab)[2][0], (vec->tab)[3][0]);
	mag = ft_cvecmag(ret);
	if (mag)
	{
		(ret->tab)[0][0] /= mag;
		(ret->tab)[1][0] /= mag;
		(ret->tab)[2][0] /= mag;
	}
	return (ret);
}
