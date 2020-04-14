/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:06:24 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 11:37:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_cnvtz(char *str, t_imgdata *imgdt)
{
	long	cur;
	char	*pc;

	if ((pc = ft_strchr(str, ',')))
		*pc = '\0';
	cur = ft_strtol(str, 0);
	if (!cur)
		return (cur);
	if (cur > imgdt->zmax)
		imgdt->zmax = cur;
	if (cur < imgdt->zmin)
		imgdt->zmin = cur;
	return (cur);
}

static void	ft_parse_line(char *line, t_imgdata *imgdt)
{
	t_matrix	*vec;
	t_list		*points;
	t_list		*it;
	int			x;
	static int	y;

	x = 0;
	points = ft_splitws_lst(line);
	it = points;
	while (it)
	{
		vec = ft_cvecnew(x++, y, ft_cnvtz(it->content, imgdt), 1);
		ft_enqueue(imgdt->points, vec, sizeof(t_matrix));
		free(vec);
		it = it->next;
	}
	++y;
	x = x < y ? y : x;
	imgdt->xymax = imgdt->xymax < x ? x : imgdt->xymax;
	ft_enqueue(imgdt->points, NULL, 0);
	ft_lstdel(&points, &ft_freenode);
}

void		ft_parse_input(const char *filename, t_imgdata *imgdt)
{
	int		fd;
	char	*line;

	imgdt->points = ft_queuenew(NULL, 0);
	if (-1 != (fd = open(filename, O_RDONLY)))
	{
		while ((get_next_line(fd, &line)))
		{
			ft_parse_line(line, imgdt);
			free(line);
		}
		close(fd);
	}
	else
		ft_handle_error(NULL);
}
