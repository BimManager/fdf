/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:25:59 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 14:48:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_fdf(char *filename)
{
	t_windata	*windt;

	windt = ft_init_window(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	windt->img_data = ft_init_image(windt, WIN_WIDTH, WIN_HEIGHT);
	ft_parse_input(filename, windt->img_data);
	windt->img_data->cache = ft_cachenew(windt->img_data);
	ft_add_hooks(windt);
	ft_vwpipln(windt->img_data);
	ft_imgplot(windt, windt->img_data->mapped);
	mlx_loop(windt->mlx_ptr);
	return (SUCCESS);
}
