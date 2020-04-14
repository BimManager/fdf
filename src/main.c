/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:50:57 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/28 10:48:11 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("%s\n", USAGE_MSG);
		return (ERROR_NARGS);
	}
	ft_fdf(argv[1]);
	return (EXIT_FAILURE);
}
