/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxunit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:07:20 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/04 17:07:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtrxunit(size_t size)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(size, size);
	while (size--)
		(ret->tab)[size][size] = 1;
	return (ret);
}
