/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxsclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:00:15 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:15:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxsclr(t_matrix *mat, double v)
{
	int	rows;
	int	cols;

	rows = mat->rows;
	while (rows--)
	{
		cols = mat->cols;
		while (cols--)
			(mat->tab)[rows][cols] *= v;
	}
	return (mat);
}
