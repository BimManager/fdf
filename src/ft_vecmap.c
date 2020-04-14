/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:47:00 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 13:28:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vecmap(t_matrix **cvec, t_matrix *mapmtrx)
{
	t_matrix	*rv;
	t_matrix	*res;

	rv = ft_mtrxtrsp(*cvec);
	res = ft_mtrxmul(rv, mapmtrx);
	ft_mtrxdel(&rv);
	((*cvec)->tab)[0][0] = (res->tab)[0][0];
	((*cvec)->tab)[1][0] = (res->tab)[0][1];
	((*cvec)->tab)[3][0] = (res->tab)[0][2];
	ft_mtrxdel(&res);
}
