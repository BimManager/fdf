/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veccrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 09:53:50 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:47:18 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_veccrs(t_matrix *v1, t_matrix *v2, int kill)
{
	t_matrix	*ret;
	int			r;

	r = v1->rows;
	ret = ft_mtrxnew(r, 1);
	(ret->tab)[0][0] = (v1->tab)[1][0] * (v2->tab)[2][0] -
		(v1->tab)[2][0] * (v2->tab)[1][0];
	(ret->tab)[1][0] = (v1->tab)[2][0] * (v2->tab)[0][0] -
		(v1->tab)[0][0] * (v2->tab)[2][0];
	(ret->tab)[2][0] = (v1->tab)[0][0] * (v2->tab)[1][0] -
		(v1->tab)[1][0] * (v2->tab)[0][0];
	if (kill)
	{
		ft_mtrxdel(&v1);
		ft_mtrxdel(&v2);
	}
	return (ret);
}
