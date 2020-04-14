/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineplot_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:39:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/10 11:18:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lineplot_low(t_imgdata *imgdt, t_line *line)
{
	long	two_dx;
	long	two_dy;
	long	yi;
	long	d;

	two_dx = line->dx << 1;
	two_dy = line->dy << 1;
	yi = line->neg ? -1 : 1;
	d = two_dy - line->dx;
	++line->dx;
	while ((line->dx)--)
	{
		ft_xyplot(imgdt, line);
		if (0 > d)
			d += two_dy;
		else
		{
			line->y0 += yi;
			d += two_dy - two_dx;
		}
		++line->x0;
	}
}

void	ft_lineplot_high(t_imgdata *imgdt, t_line *line)
{
	long	two_dx;
	long	two_dy;
	long	yi;
	long	d;

	two_dx = line->dx << 1;
	two_dy = line->dy << 1;
	yi = line->neg ? -1 : 1;
	d = two_dx - line->dy;
	++line->dy;
	while ((line->dy)--)
	{
		ft_xyplot(imgdt, line);
		if (0 > d)
			d += two_dx;
		else
		{
			++line->x0;
			d += two_dx - two_dy;
		}
		line->y0 += yi;
	}
}

void	ft_lineplot_hrz(t_imgdata *imgdt, t_line *line)
{
	++line->dx;
	while ((line->dx)--)
	{
		ft_xyplot(imgdt, line);
		++line->x0;
	}
}

void	ft_lineplot_vrt(t_imgdata *imgdt, t_line *line)
{
	++line->dy;
	while ((line->dy)--)
	{
		ft_xyplot(imgdt, line);
		if (line->neg)
			--line->y0;
		else
			++line->y0;
	}
}

void	ft_lineplot_dgl(t_imgdata *imgdt, t_line *line)
{
	++line->dy;
	++line->dx;
	while ((line->dy)--)
	{
		ft_xyplot(imgdt, line);
		if (line->neg)
			--line->y0;
		else
			++line->y0;
		++line->x0;
	}
}
