/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecxform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:28:51 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/08 16:30:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vecxform(t_list *it, t_matrix *xform)
{
	t_matrix	*res;

	while (it)
	{
		if (it->content_size)
		{
			res = ft_mtrxmul(xform, it->content);
			ft_mtrxdel((t_matrix **)&(it->content));
			it->content = res;
		}
		it = it->next;
	}
}
