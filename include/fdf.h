/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:51:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/11 17:30:48 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

# define USAGE_MSG	"fdf: \033[0;31merror:\033[0m no input file"
# define LINE_ERR	"Found wrong line length. Exiting ..."
# define WIN_TITLE	"FdF"
# define WIN_WIDTH	800
# define WIN_HEIGHT	600
# define OFFSET		10
# define DTAB_SIZE	5120
# define SUCCESS		0
# define ERROR_NARGS	1
# define CLIPPED		2

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_F			3
# define KEY_H			4
# define KEY_G			5
# define KEY_Z			6
# define KEY_X			7
# define KEY_C			8
# define KEY_V			9
# define KEY_B			11
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_Y			16
# define KEY_T			17
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_6			22
# define KEY_5			23
# define KEY_EQUALS		24
# define KEY_9			25
# define KEY_7			26
# define KEY_MINUS		27
# define KEY_8			28
# define KEY_0			29
# define KEY_RBRACKET	30
# define KEY_O			31
# define KEY_U			32
# define KEY_LBRACKET	33
# define KEY_I			34
# define KEY_P			35
# define KEY_RETURN		36
# define KEY_L			37
# define KEY_J			38
# define KEY_APOSTROPHE 39
# define KEY_K			40
# define KEY_SEMICOLON	41
# define KEY_FRONTSLASH	42
# define KEY_COMMA		43
# define KEY_BACKSLASH	44
# define KEY_N			45
# define KEY_M			46
# define KEY_PERIOD		47
# define KEY_TAB		48
# define KEY_BACKAPOST	50
# define KEY_DELETE		51
# define KEY_ESCAPE		53
# define KEY_COMMAND	55
# define KEY_SHIFT		56
# define KEY_CAPSLOCK	57
# define KEY_OPTION		58
# define KEY_CONTROL	59
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

typedef struct	s_matrix
{
	double		**tab;
	size_t		rows;
	size_t		cols;
}				t_matrix;

typedef struct	s_line
{
	long		x0;
	long		y0;
	long		z0;
	long		x1;
	long		y1;
	long		z1;
	long		dx;
	long		dy;
	long		dz;
	int			neg;
	int			lt1;
}				t_line;

typedef struct	s_cache
{
	t_matrix	*viewpoint;
	t_matrix	*normal;
	t_matrix	*prjmtrx;
	t_matrix	*mapmtrx;
	t_matrix	*rotzmtrx;
	t_matrix	*transmtrx;
	t_matrix	*sclmtrx;
}				t_cache;

typedef struct	s_imgdata
{
	void		*img_ptr;
	char		*buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_queue		*points;
	t_queue		*mapped;
	long		xymax;
	long		zmin;
	long		zmax;
	t_matrix	*origin;
	t_matrix	*x_dir;
	t_matrix	*y_dir;
	t_cache		*cache;
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
}				t_imgdata;

typedef struct	s_windata
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_imgdata	*img_data;
	size_t		*pfn;
}				t_windata;

t_matrix		*ft_mtrxnew(size_t rows, size_t cols);
void			ft_mtrxdel(t_matrix **mat);
t_matrix		*ft_mtrxadd(t_matrix *m1, t_matrix *m2);
t_matrix		*ft_mtrxsub(t_matrix *m1, t_matrix *m2);
t_matrix		*ft_mtrxmul(t_matrix *m1, t_matrix *m2);
t_matrix		*ft_mtrxtrsp(t_matrix *mat);
t_matrix		*ft_mtrxsclr(t_matrix *mat, double v);
t_matrix		*ft_mtrxunit(size_t size);
t_matrix		*ft_mtrxinv3x3(t_matrix *m);
void			ft_mtrxput(t_matrix *mat);

void			ft_rvmtrxn(t_matrix *m, t_matrix *rv, int r);
t_matrix		*ft_mtrxncv(t_matrix *m, int c);

t_matrix		*ft_prjmtrx(t_matrix *v, t_matrix *n);
t_matrix		*ft_mapmtrx(t_matrix *xdir, t_matrix *ydir, t_matrix *origin);

t_matrix		*ft_transmtrx(double x, double y, double z);
t_matrix		*ft_rotx_mtrx(double alpha);
t_matrix		*ft_roty_mtrx(double beta);
t_matrix		*ft_rotz_mtrx(double gamma);
t_matrix		*ft_rotxy_mtrx(double alpha, double beta);
t_matrix		*ft_rotxyz_mtrx(double alpha, double x, double y);
t_matrix		*ft_sclmtrx(double x, double y, double z);
t_matrix		*ft_refyz_mtrx(void);
t_matrix		*ft_refxz_mtrx(void);
t_matrix		*ft_refxy_mtrx(void);

t_cache			*ft_cachenew(t_imgdata *imgdt);
void			ft_cachedel(t_cache **cache);

int				ft_vecdot(t_matrix *v1, t_matrix *v2);
t_matrix		*ft_veccrs(t_matrix *v1, t_matrix *v2, int kill);
double			ft_rvecmag(t_matrix *vec);
double			ft_cvecmag(t_matrix *vec);
t_matrix		*ft_cvecnorm(t_matrix *vec);
void			ft_vecxform(t_list *it, t_matrix *xform);
void			ft_vecscl(t_imgdata *imgdt, double x, double y);
void			ft_vectrans(t_imgdata *imgdt, double x, double y);
void			ft_vecrot(t_imgdata *imgdt, double alpha, double beta);
t_matrix		*ft_rvecnew(double x, double y, double z, double w);
t_matrix		*ft_cvecnew(double x, double y, double z, double w);

t_line			*ft_linenew(t_matrix *vec0, t_matrix *vec1);
void			ft_linedel(t_line **line);
void			ft_lineplot_low(t_imgdata *imgdt, t_line *line);
void			ft_lineplot_high(t_imgdata *imgdt, t_line *line);
void			ft_lineplot_hrz(t_imgdata *imgdt, t_line *line);
void			ft_lineplot_vrt(t_imgdata *imgdt, t_line *line);
void			ft_lineplot_dgl(t_imgdata *imgdt, t_line *line);
int				ft_lineplot(t_imgdata *imgdt, t_matrix *vec0, t_matrix *vec1);
int				ft_xyplot(t_imgdata *imgdt, t_line *line);

void			ft_vecprj(t_matrix **cvec, t_matrix *prjmtrx);
void			ft_vecmap(t_matrix **cvec, t_matrix *mapmtrx);
void			ft_dcxform(t_matrix **vec, t_imgdata *imgdt);
void			ft_vwpipln(t_imgdata *imgdt);
void			ft_imgplot(t_windata *windt, t_queue *q);

int				ft_fdf(char *filename);
void			ft_handle_error(const char *msg);
void			ft_add_hooks(t_windata *windt);
void			ft_parse_input(const char *filename, t_imgdata *imgdt);
int				ft_imgrndr(t_windata *windt);
void			ft_fbclr(t_imgdata *imgdt);

t_windata		*ft_init_window(int width, int height, char *title);
t_imgdata		*ft_init_image(t_windata *windt, int width, int height);

void			ft_freenode(void *pv, size_t size);
void			ft_mtrxfree(void *pv, size_t size);

void			ft_queuecp(t_queue **dstq, t_queue *srcq, t_cache *cache);

void			ft_quit(t_windata *windt);
void			ft_zoomin(t_windata *windt);
void			ft_zoomout(t_windata *windt);

void			mvleft(t_windata *windt);
void			mvright(t_windata *windt);
void			mvup(t_windata *windt);
void			mvdown(t_windata *windt);
void			chng(t_windata *windt, int col, int val);
void			xinc(t_windata *windt);
void			yinc(t_windata *windt);
void			zinc(t_windata *windt);
void			xdec(t_windata *windt);
void			ydec(t_windata *windt);
void			zdec(t_windata *windt);
void			zrot(t_windata *windt);
void			prj0(t_windata *windt);
void			prj1(t_windata *windt);
void			prj2(t_windata *windt);

#endif
