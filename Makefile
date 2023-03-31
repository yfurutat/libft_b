_SRCS_	=	strlen \
			isalpha isdigit isalnum isprint isascii \
			tolower toupper \
			memset bzero \
			memcpy memmove \
			strlcpy strlcat \
			memchr strchr strrchr \
			memcmp strncmp strnstr \
			calloc atoi itoa \
			strdup substr strjoin \
			putchar_fd putstr_fd putendl_fd \
			putnbr_fd \
			split strtrim \
			striteri strmapi

UTIL	=	isspace islower isupper \

_BSRCS_	=	lstnew \
			lstlast lstsize \
			lstadd_front lstadd_back \
			lstdelone lstclear \
			lstiter lstmap \

ifdef ADD_BONUS
_SRCS_ += $(_BSRCS_)
endif

SRCS = $(addsuffix .c, $(addprefix ft_, $(_SRCS_) $(UTIL)))
BSRCS = $(addsuffix .c, $(addprefix ft_, $(_BSRCS_)))

OBJS	=	$(SRCS:.c=.o)
BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar -rcs
HFILE	=	libft.h
			
$(NAME)	:	$(OBJS)
			time $(AR) $(NAME) $(OBJS)

all		:	$(NAME)
clean	:
			time $(RM) $(OBJS) $(BOBJS)
fclean	:	clean
			time $(RM) $(NAME)
re		:	fclean all
bonus	:
			@ time make all ADD_BONUS=42

reb		:	fclean bonus

touchm	:
			@touch $(SRCS) $(HFILE)
touchb	:	
			@touch $(BSRCS)
norm	:
			@ time norminette $(HFILE) $(SRCS) $(BSRCS)
normd	:
			@ time norminette -R CheckDefine $(HFILE) $(SRCS) $(BSRCS)
normf	:
			@ time norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRCS) $(BSRCS)
norma	:	norm normd normf

commit	:	fclean
			git add $(SRCS) $(BSRCS) $(HFILE) Makefile
			git commit -m "commit through Makefile"
			git log --numstat | grep -cE '^[0-9]+[[:space:]]+[0-9]+[[:space:]]+'

.PHONY	:	all clean fclean re bonus commit norm normd normf norma

# .DEFAULT_GOAL := fclean

# SRCS_	=	$(addprefix ft_, $(_SRCS_) $(UTIL))
# SRCS	=	$(addsuffix .c, $(SRCS_))
# BSRCS_	=	$(addprefix ft_, $(_BSRCS_))
# BSRCS	=	$(addsuffix .c, $(BSRCS_))