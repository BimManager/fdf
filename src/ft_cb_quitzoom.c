/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_quitzoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:28:38 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 15:46:26 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_quit(t_windata *windt)
{
	ft_queuedel(&windt->img_data->points, &ft_mtrxfree);
	ft_queuedel(&windt->img_data->mapped, &ft_mtrxfree);
	mlx_destroy_window(windt->mlx_ptr, windt->win_ptr);
	exit(SUCCESS);
}

void	ft_zoomin(t_windata *windt)
{
	ft_vecscl(windt->img_data, 2, 2);
	ft_imgplot(windt, windt->img_data->mapped);
}

void	ft_zoomout(t_windata *windt)
{
	ft_vecscl(windt->img_data, 0.5, 0.5);
	ft_imgplot(windt, windt->img_data->mapped);
}
