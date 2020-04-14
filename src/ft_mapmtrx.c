/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapmtrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:48:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 13:47:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mapmtrx(t_matrix *xdir, t_matrix *ydir, t_matrix *origin)
{
	t_matrix	*k;
	t_matrix	*tk;
	t_matrix	*ktk;
	t_matrix	*iktk;

	k = ft_mtrxnew(3, 4);
	ft_rvmtrxn(k, xdir, 0);
	ft_rvmtrxn(k, ydir, 1);
	ft_rvmtrxn(k, origin, 2);
	tk = ft_mtrxtrsp(k);
	ktk = ft_mtrxmul(k, tk);
	ft_mtrxdel(&k);
	iktk = ft_mtrxinv3x3(ktk);
	ft_mtrxdel(&ktk);
	k = ft_mtrxmul(tk, iktk);
	ft_mtrxdel(&tk);
	ft_mtrxdel(&iktk);
	return (k);
}
