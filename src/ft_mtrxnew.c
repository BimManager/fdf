/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 10:26:19 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/27 11:57:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxnew(size_t rows, size_t cols)
{
	t_matrix	*ret;

	ret = ft_memalloc(sizeof(t_matrix));
	ret->rows = rows;
	ret->cols = cols;
	ret->tab = ft_memalloc(rows * sizeof(void *));
	while (rows--)
		(ret->tab)[rows] = ft_memalloc(cols * sizeof(void *));
	return (ret);
}
