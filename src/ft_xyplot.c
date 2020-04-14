/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xyplot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:14 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 17:27:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_xypos(t_imgdata *imgdt, int x, int y)
{
	int	ret;

	ret = x * imgdt->bits_per_pixel / BYTE + y * imgdt->size_line;
	if (!ret)
		return (ret);
	if (!(4 % ret))
		return (ret);
	else
		ret = ret - ret % 4;
	return (ret);
}

static int	ft_colorclr(t_imgdata *imgdt, t_line *line)
{
	int	v;

	v = 0x800000;
	if (!line->neg && line->lt1)
		line->z0 += (WIN_HEIGHT * line->dz / (line->dx + 1));
	else if (line->lt1)
		line->z1 -= (WIN_HEIGHT * line->dz / (line->dx + 1));
	else if (!line->dy)
		line->z0 += (WIN_HEIGHT * line->dz / (line->dx + 1));
	else if (!line->dx)
		line->z0 += (WIN_HEIGHT * line->dz / (line->dy + 1));
	else
		line->z0 += (WIN_HEIGHT * line->dz / (line->dy + 1));
	return (v + imgdt->zmin + line->z0);
}

int			ft_xyplot(t_imgdata *imgdt, t_line *line)
{
	int	byte0;
	int	*pbuf;

	if (0 > line->x0 || 0 > line->y0)
		return (CLIPPED);
	if (WIN_WIDTH <= line->x0 || WIN_HEIGHT <= line->y0)
		return (CLIPPED);
	byte0 = ft_xypos(imgdt, line->x0, line->y0);
	pbuf = (int *)&imgdt->buffer[byte0];
	*pbuf = ft_colorclr(imgdt, line);
	return (SUCCESS);
}
