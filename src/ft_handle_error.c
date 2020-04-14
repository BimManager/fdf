/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:18:03 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/01 14:23:36 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_error(const char *msg)
{
	char	*err;

	if (msg)
	{
		ft_printf("%s\n", msg);
		exit(1);
	}
	if (errno)
	{
		err = strerror(errno);
		perror(err);
		exit(errno);
	}
}
