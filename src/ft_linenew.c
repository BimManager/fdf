/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:56:50 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 15:56:41 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_lineattrs(t_line *line)
{
	line->neg = 0;
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	if (line->z0 > line->z1)
		ft_swap(&line->z0, &line->z1, sizeof(long));
	line->dz = line->z1 - line->z0;
	if (0 > line->dy)
	{
		line->dy *= -1;
		line->neg = 1;
		ft_swap(&line->z0, &line->z1, sizeof(long));
	}
	if (line->dx > line->dy)
		line->lt1 = 1;
	else
		line->lt1 = 0;
}

t_line		*ft_linenew(t_matrix *vec0, t_matrix *vec1)
{
	t_line	*ret;

	ret = malloc(sizeof(t_line));
	if ((vec1->tab)[0][0] > (vec0->tab)[0][0])
	{
		ret->x0 = (vec0->tab)[0][0];
		ret->y0 = (vec0->tab)[1][0];
		ret->z0 = (vec0->tab)[2][0];
		ret->x1 = (vec1->tab)[0][0];
		ret->y1 = (vec1->tab)[1][0];
		ret->z1 = (vec1->tab)[2][0];
	}
	else
	{
		ret->x0 = (vec1->tab)[0][0];
		ret->y0 = (vec1->tab)[1][0];
		ret->z0 = (vec1->tab)[2][0];
		ret->x1 = (vec0->tab)[0][0];
		ret->y1 = (vec0->tab)[1][0];
		ret->z1 = (vec0->tab)[2][0];
	}
	ft_lineattrs(ret);
	return (ret);
}
