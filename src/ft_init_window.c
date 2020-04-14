/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:34:33 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 15:36:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		add_funcs(t_windata *windt)
{
	*(windt->pfn + KEY_ESCAPE) = (size_t)&ft_quit;
	*(windt->pfn + KEY_EQUALS) = (size_t)&ft_zoomin;
	*(windt->pfn + KEY_MINUS) = (size_t)&ft_zoomout;
	*(windt->pfn + KEY_LEFT) = (size_t)&mvleft;
	*(windt->pfn + KEY_RIGHT) = (size_t)&mvright;
	*(windt->pfn + KEY_UP) = (size_t)&mvup;
	*(windt->pfn + KEY_DOWN) = (size_t)&mvdown;
	*(windt->pfn + KEY_X) = (size_t)&xinc;
	*(windt->pfn + KEY_Y) = (size_t)&yinc;
	*(windt->pfn + KEY_Z) = (size_t)&zinc;
	*(windt->pfn + KEY_S) = (size_t)&xdec;
	*(windt->pfn + KEY_J) = (size_t)&ydec;
	*(windt->pfn + KEY_A) = (size_t)&zdec;
	*(windt->pfn + KEY_R) = (size_t)&zrot;
	*(windt->pfn + KEY_0) = (size_t)&prj0;
	*(windt->pfn + KEY_1) = (size_t)&prj1;
	*(windt->pfn + KEY_2) = (size_t)&prj2;
}

t_windata		*ft_init_window(int width, int height, char *title)
{
	t_windata	*data;

	data = malloc(sizeof(t_windata));
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr)
		data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	else
		ft_handle_error(NULL);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->pfn = malloc(DTAB_SIZE);
	ft_bzero(data->pfn, DTAB_SIZE);
	add_funcs(data);
	return (data);
}
