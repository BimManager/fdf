/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxmul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:30:29 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/27 12:24:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxmul(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*ret;
	size_t		r;
	size_t		c;
	size_t		t;

	if (m1->cols != m2->rows)
		return (NULL);
	ret = ft_mtrxnew(m1->rows, m2->cols);
	r = -1;
	while (++r < ret->rows)
	{
		c = -1;
		while (++c < ret->cols)
		{
			t = -1;
			while (++t < m1->cols)
				(ret->tab)[r][c] += (m1->tab)[r][t] * (m2->tab)[t][c];
		}
	}
	return (ret);
}
