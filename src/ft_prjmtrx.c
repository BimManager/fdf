/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prjmtrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:45:35 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/08 11:46:25 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_prjmtrx(t_matrix *v, t_matrix *n)
{
	t_matrix	*tmp;
	t_matrix	*tn_m;
	t_matrix	*unit;
	int			dot;

	tn_m = ft_mtrxtrsp(n);
	tmp = ft_mtrxmul(tn_m, v);
	ft_mtrxdel(&tn_m);
	dot = ft_vecdot(n, v);
	unit = ft_mtrxunit(4);
	ft_mtrxsclr(unit, dot);
	tn_m = ft_mtrxsub(tmp, unit);
	ft_mtrxdel(&tmp);
	ft_mtrxdel(&unit);
	return (tn_m);
}
