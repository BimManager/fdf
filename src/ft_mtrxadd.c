/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:17:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/03 16:29:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxadd(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*ret;
	size_t		r;
	size_t		c;

	if (m1->rows != m2->rows || m1->cols != m2->cols)
		return (NULL);
	ret = ft_mtrxnew(m1->rows, m1->cols);
	r = -1;
	while (++r < m1->rows)
	{
		c = -1;
		while (++c < m1->cols)
			(ret->tab)[r][c] = (m1->tab)[r][c] + (m2->tab)[r][c];
	}
	return (ret);
}
