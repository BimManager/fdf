/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecmag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 09:56:57 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 12:15:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_rvecmag(t_matrix *vec)
{
	double	ret;

	ret = (vec->tab)[0][0] * (vec->tab)[0][0]
		+ (vec->tab)[0][1] * (vec->tab)[0][1]
		+ (vec->tab)[0][2] * (vec->tab)[0][2];
	ret = sqrt(ret);
	return (ret);
}

double	ft_cvecmag(t_matrix *vec)
{
	double	ret;

	ret = (vec->tab)[0][0] * (vec->tab)[0][0]
		+ (vec->tab)[1][0] * (vec->tab)[1][0]
		+ (vec->tab)[2][0] * (vec->tab)[2][0];
	ret = sqrt(ret);
	return (ret);
}
