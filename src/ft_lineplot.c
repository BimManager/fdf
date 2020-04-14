/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineplot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:46:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 14:42:53 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lineplot(t_imgdata *imgdt, t_matrix *vec0, t_matrix *vec1)
{
	t_line	*line;

	line = ft_linenew(vec0, vec1);
	if (!line->dy)
		ft_lineplot_hrz(imgdt, line);
	else if (!line->dx)
		ft_lineplot_vrt(imgdt, line);
	else if (line->dx == line->dy)
		ft_lineplot_dgl(imgdt, line);
	else if (line->dx > line->dy)
		ft_lineplot_low(imgdt, line);
	else
		ft_lineplot_high(imgdt, line);
	ft_linedel(&line);
	return (SUCCESS);
}
