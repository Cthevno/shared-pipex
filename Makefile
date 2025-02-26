NAME = pipex
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/exec_cmd.c
SRCS_DIR = ./srcs
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar
ARFLAGS = rcs
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

all : $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJS) pipex.h
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
