/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refmtrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:02:00 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:46:48 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		*ft_refyz_mtrx(void)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 4);
	(ret->tab)[0][0] = -1;
	(ret->tab)[1][1] = 1;
	(ret->tab)[2][2] = 1;
	(ret->tab)[3][3] = 1;
	return (ret);
}

t_matrix		*ft_refxz_mtrx(void)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 4);
	(ret->tab)[0][0] = 1;
	(ret->tab)[1][1] = -1;
	(ret->tab)[2][2] = 1;
	(ret->tab)[3][3] = 1;
	return (ret);
}

t_matrix		*ft_refxy_mtrx(void)
{
	t_matrix	*ret;

	ret = ft_mtrxnew(4, 4);
	(ret->tab)[0][0] = 1;
	(ret->tab)[1][1] = 1;
	(ret->tab)[2][2] = -1;
	(ret->tab)[3][3] = 1;
	return (ret);
}
