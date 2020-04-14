/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotmtrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:56:12 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/08 11:59:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_rotx_mtrx(double alpha)
{
	t_matrix	*rot_x;

	rot_x = ft_mtrxnew(4, 4);
	(rot_x->tab)[0][0] = 1;
	(rot_x->tab)[1][1] = cos(alpha);
	(rot_x->tab)[1][2] = -sin(alpha);
	(rot_x->tab)[2][1] = sin(alpha);
	(rot_x->tab)[2][2] = cos(alpha);
	(rot_x->tab)[3][3] = 1;
	return (rot_x);
}

t_matrix	*ft_roty_mtrx(double beta)
{
	t_matrix	*rot_y;

	rot_y = ft_mtrxnew(4, 4);
	(rot_y->tab)[0][0] = cos(beta);
	(rot_y->tab)[0][2] = sin(beta);
	(rot_y->tab)[1][1] = 1;
	(rot_y->tab)[2][0] = -sin(beta);
	(rot_y->tab)[2][2] = cos(beta);
	(rot_y->tab)[3][3] = 1;
	return (rot_y);
}

t_matrix	*ft_rotz_mtrx(double gamma)
{
	t_matrix	*rot_z;

	rot_z = ft_mtrxnew(4, 4);
	(rot_z->tab)[0][0] = cos(gamma);
	(rot_z->tab)[0][1] = -sin(gamma);
	(rot_z->tab)[1][0] = sin(gamma);
	(rot_z->tab)[1][1] = cos(gamma);
	(rot_z->tab)[2][2] = 1;
	(rot_z->tab)[3][3] = 1;
	return (rot_z);
}

t_matrix	*ft_rotxy_mtrx(double alpha, double beta)
{
	t_matrix	*rot_x;
	t_matrix	*rot_y;
	t_matrix	*rot_xy;

	rot_x = ft_rotx_mtrx(alpha);
	rot_y = ft_roty_mtrx(beta);
	rot_xy = ft_mtrxmul(rot_x, rot_y);
	ft_mtrxdel(&rot_x);
	ft_mtrxdel(&rot_y);
	return (rot_xy);
}

t_matrix	*ft_rotxyz_mtrx(double gamma, double x, double y)
{
	t_matrix	*rot_z;
	t_matrix	*trns;
	t_matrix	*ret;

	rot_z = ft_rotz_mtrx(gamma);
	trns = ft_transmtrx(-x, -y, 0);
	ret = ft_mtrxmul(rot_z, trns);
	ft_mtrxdel(&rot_z);
	ft_mtrxdel(&trns);
	trns = ft_transmtrx(x, y, 0);
	rot_z = ret;
	ret = ft_mtrxmul(ret, trns);
	ft_mtrxdel(&rot_z);
	ft_mtrxdel(&trns);
	return (ret);
}
