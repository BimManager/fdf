/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:00:46 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/01 15:06:00 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mtrxput(t_matrix *mat)
{
	size_t	r;
	size_t	c;

	r = -1;
	while (++r < mat->rows)
	{
		c = -1;
		while (++c < mat->cols)
			ft_printf("%10.2f", mat->tab[r][c]);
		ft_printf("\n");
	}
	ft_printf("\n");
}
