/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxtrsp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:44:36 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/04 16:58:56 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxtrsp(t_matrix *mat)
{
	t_matrix	*ret;
	int			i;
	int			j;

	ret = ft_mtrxnew(mat->cols, mat->rows);
	i = mat->rows;
	while (i--)
	{
		j = mat->cols;
		while (j--)
			(ret->tab)[j][i] = (mat->tab)[i][j];
	}
	return (ret);
}
