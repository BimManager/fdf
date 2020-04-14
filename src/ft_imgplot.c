/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgplot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:19:38 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:30:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*ft_y0plot(t_imgdata *imgdt, t_deque *dq, t_list *it)
{
	while (it && it->content_size)
	{
		if (ft_dequekeep(dq))
			ft_lineplot(imgdt, ft_dequekeep(dq)->content, it->content);
		ft_dequesnoc(dq, it->content, it->content_size);
		it = it->next;
	}
	return (it);
}

static void		ft_ximgplot(t_imgdata *imgdt, t_list *it, t_deque *dq)
{
	t_list		*tmp;

	while (it)
	{
		if (it->content_size && ft_dequepeek(dq))
		{
			tmp = ft_dequepop(dq);
			if (tmp->content_size)
				ft_lineplot(imgdt, it->content, tmp->content);
			if (ft_dequekeep(dq) && ft_dequekeep(dq)->content_size)
				ft_lineplot(imgdt, ft_dequekeep(dq)->content, it->content);
			ft_lstdel(&tmp, &ft_freenode);
		}
		if (ft_dequepeek(dq) && !ft_dequepeek(dq)->content_size)
		{
			tmp = ft_dequepop(dq);
			ft_lstdel(&tmp, &ft_freenode);
		}
		ft_dequesnoc(dq, it->content, it->content_size);
		it = it->next;
	}
}

void			ft_imgplot(t_windata *windt, t_queue *q)
{
	t_list		*it;
	t_deque		*dq;
	t_imgdata	*imgdt;

	imgdt = windt->img_data;
	ft_fbclr(imgdt);
	dq = ft_dequenew();
	it = ft_queuepeek(q);
	it = ft_y0plot(imgdt, dq, it);
	ft_ximgplot(imgdt, ft_queuepeek(q), dq);
	ft_dequedel(&dq, &ft_freenode);
	mlx_put_image_to_window(windt->mlx_ptr,
		windt->win_ptr, imgdt->img_ptr, 0, 0);
}
