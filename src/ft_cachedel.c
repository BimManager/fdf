/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cachedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:19:04 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 13:39:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cachedel(t_cache **cache)
{
	ft_mtrxdel(&(*cache)->prjmtrx);
	ft_mtrxdel(&(*cache)->sclmtrx);
	ft_mtrxdel(&(*cache)->mapmtrx);
	ft_mtrxdel(&(*cache)->prjmtrx);
	ft_mtrxdel(&(*cache)->rotzmtrx);
	ft_mtrxdel(&(*cache)->transmtrx);
	free(*cache);
	*cache = NULL;
}
