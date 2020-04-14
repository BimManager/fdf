/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecprj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:39:04 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 13:28:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vecprj(t_matrix **cvec, t_matrix *prjmtrx)
{
	t_matrix	*rv;
	t_matrix	*tmp;

	rv = ft_mtrxtrsp(*cvec);
	tmp = ft_mtrxmul(rv, prjmtrx);
	ft_mtrxdel(cvec);
	*cvec = ft_mtrxtrsp(tmp);
	ft_mtrxdel(&tmp);
	ft_mtrxdel(&rv);
}
