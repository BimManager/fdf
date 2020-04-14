/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxncv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:11:14 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:11:37 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxncv(t_matrix *m, int c)
{
	t_matrix	*ret;
	int			r;

	ret = ft_mtrxnew(m->rows, 1);
	r = m->rows;
	while (r--)
		(ret->tab)[r][0] = (m->tab)[r][c];
	return (ret);
}
