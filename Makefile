# fdf Makefile

CC := gcc
AR := ar
LD := ld
CFLAGS := -g -Wall -Werror -Wextra -c \
		-I./include -I./libft/include -I./minilibx
ARFLAGS := -q -c
LDFLAGS := -lc -lm -L./libft -lft -L./minilibx -lmlx \
			-framework OpenGL -framework AppKit \
			-e _main -arch x86_64 -macosx_version_min 10.13

INCDIR := include 
SRCDIR := src
OBJDIR := build

SRCS := $(addprefix $(SRCDIR)/, \
		main.c ft_fdf.c ft_parse_input.c \
		ft_handle_error.c \
		ft_init_window.c ft_init_image.c \
		ft_linenew.c ft_linedel.c ft_lineplot.c \
		ft_imgplot.c ft_freenode.c \
		ft_add_hooks.c \
		ft_mtrxnew.c ft_mtrxdel.c ft_vecnew.c \
		ft_vecprj.c ft_vecmap.c \
		ft_mtrxadd.c ft_vwpipln.c \
		ft_mtrxmul.c ft_mtrxput.c \
		ft_mtrxsub.c ft_mtrxsclr.c \
		ft_mtrxtrsp.c ft_mtrxunit.c ft_mtrxinv3x3.c \
		ft_vecdot.c ft_veccrs.c \
		ft_xyplot.c ft_lineplot_utils.c \
		ft_fbclr.c ft_dcxform.c \
		ft_cachenew.c ft_cachedel.c \
		ft_prjmtrx.c ft_mapmtrx.c \
		ft_transmtrx.c ft_rotmtrx.c ft_sclmtrx.c \
		ft_refmtrx.c ft_mtrxfree.c\
		ft_vecxform.c ft_vecscl.c ft_vectrans.c \
		ft_mtrxncv.c ft_rvmtrxn.c ft_vecmag.c \
		ft_vecnorm.c ft_queuecp.c \
		ft_cb_quitzoom.c ft_cb_move.c ft_cb_incviewpoint.c \
		ft_cb_decviewpoint.c ft_cb_prj.c)


OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

NAME := fdf

all : $(NAME)

$(NAME) : $(OBJS)
#	make -C ./minilibx
#	make -C ./libft
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@if [[ ! -e $(OBJDIR) ]]; then mkdir $(OBJDIR); fi
	@$(CC) $(CFLAGS) $< -o $@

.PNOHY : all clean fclean re

clean :
	@if [[ -e $(OBJDIR) ]]; then rm -rf $(OBJDIR); fi
#	@make clean -C ./minilibx
#	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
#	@make fclean -C ./libft

re : fclean all