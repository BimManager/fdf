/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:34:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 13:51:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_imgdata	*ft_init_image(t_windata *windata, int width, int height)
{
	t_imgdata	*imgdt;

	imgdt = malloc(sizeof(t_imgdata));
	ft_bzero(imgdt, sizeof(t_imgdata));
	imgdt->img_ptr = mlx_new_image(windata->mlx_ptr, width, height);
	imgdt->buffer = mlx_get_data_addr(imgdt->img_ptr,
		&imgdt->bits_per_pixel, &imgdt->size_line, &imgdt->endian);
	imgdt->mapped = ft_queuenew(NULL, 0);
	imgdt->origin = ft_rvecnew(0, 0, 0, 1);
	imgdt->x_dir = ft_rvecnew(1, 0, 0, 0);
	imgdt->y_dir = ft_rvecnew(1, 1, 0, 0);
	return (imgdt);
}
