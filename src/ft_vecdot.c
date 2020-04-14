/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:41:43 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/04 12:54:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_vecdot(t_matrix *v1, t_matrix *v2)
{
	int	i;
	int	j;
	int	res;

	if (v1->rows != v2->rows
		|| v1->cols != v2->cols)
		return (-1);
	i = v1->rows;
	j = v1->cols;
	res = 0;
	if (i > j)
		while (i--)
			res += (v1->tab)[i][0] * (v2->tab)[i][0];
	else
		while (j--)
			res += (v1->tab)[0][j] * (v2->tab)[0][j];
	return (res);
}
