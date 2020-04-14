/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxinv3x3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 09:59:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 13:44:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_matrix	*ft_veccrstrsp(t_matrix *v0, t_matrix *v1)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = ft_veccrs(v0, v1, 0);
	res = ft_mtrxtrsp(tmp);
	ft_mtrxdel(&tmp);
	return (res);
}

static int		ft_detcalc(t_matrix *x0, t_matrix *x1, t_matrix *x2)
{
	t_matrix	*res;
	int			det;

	res = ft_veccrs(x1, x2, 0);
	det = ft_vecdot(x0, res);
	ft_mtrxdel(&res);
	return (det);
}

static int		ft_caclxs(t_matrix *m, t_matrix **x1x2,
					t_matrix **x2x0, t_matrix **x0x1)
{
	t_matrix	*x0;
	t_matrix	*x1;
	t_matrix	*x2;
	int			det;

	x0 = ft_mtrxncv(m, 0);
	x1 = ft_mtrxncv(m, 1);
	x2 = ft_mtrxncv(m, 2);
	*x1x2 = ft_veccrstrsp(x1, x2);
	*x2x0 = ft_veccrstrsp(x2, x0);
	*x0x1 = ft_veccrstrsp(x0, x1);
	det = ft_detcalc(x0, x1, x2);
	ft_mtrxdel(&x0);
	ft_mtrxdel(&x1);
	ft_mtrxdel(&x2);
	return (det);
}

t_matrix		*ft_mtrxinv3x3(t_matrix *m)
{
	t_matrix	*x1x2;
	t_matrix	*x2x0;
	t_matrix	*x0x1;
	t_matrix	*ret;
	int			det;

	if (!(det = ft_caclxs(m, &x1x2, &x2x0, &x0x1)))
		return (NULL);
	ret = ft_mtrxnew(m->rows, m->cols);
	ft_rvmtrxn(ret, x1x2, 0);
	ft_rvmtrxn(ret, x2x0, 1);
	ft_rvmtrxn(ret, x0x1, 2);
	ft_mtrxsclr(ret, 1.0 / det);
	ft_mtrxdel(&x1x2);
	ft_mtrxdel(&x2x0);
	ft_mtrxdel(&x0x1);
	return (ret);
}
