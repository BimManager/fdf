/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuecp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:16:34 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 11:39:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_queueclean(t_queue **dstq)
{
	if (ft_queue_isempty(*dstq))
		return ;
	ft_queuedel(dstq, &ft_mtrxfree);
	*dstq = ft_queuenew(NULL, 0);
}

static t_matrix	*ft_xform(t_cache *cache, t_matrix *vec)
{
	t_matrix	*ret;
	t_matrix	*tmp;

	tmp = ft_mtrxmul(cache->sclmtrx, vec);
	ret = ft_mtrxmul(cache->rotzmtrx, tmp);
	ft_mtrxdel(&tmp);
	return (ret);
}

void			ft_queuecp(t_queue **dstq, t_queue *srcq, t_cache *cache)
{
	t_list		*it;
	t_matrix	*cp;

	ft_queueclean(dstq);
	it = ft_queuepeek(srcq);
	while (it)
	{
		if (it->content_size)
		{
			cp = ft_xform(cache, it->content);
			ft_enqueue(*dstq, cp, sizeof(t_matrix));
			free(cp);
		}
		else
			ft_enqueue(*dstq, it->content, it->content_size);
		it = it->next;
	}
}
