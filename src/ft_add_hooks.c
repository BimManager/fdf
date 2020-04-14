/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:17:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/10 14:54:22 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_key_hook(int keycode, void *param)
{
	t_windata	*windt;
	void		*pv;

	windt = (t_windata*)param;
	if ((pv = (void *)*(windt->pfn + keycode)))
		((void (*)(t_windata *))pv)(windt);
	return (0);
}

static int	ft_loop_hook(void *param)
{
	(void)param;
	return (SUCCESS);
}

void		ft_add_hooks(t_windata *windt)
{
	mlx_key_hook(windt->win_ptr, &ft_key_hook, windt);
	mlx_loop_hook(windt->mlx_ptr, &ft_loop_hook, NULL);
}
