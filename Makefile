NAME = pipex
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/exec_cmd.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/process.c $(SRCS_DIR)/pipex.c
SRCS_BONUS = $(SRCS_DIR)/main_bonus.c $(SRCS_DIR)/exec_cmd.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/process.c $(SRCS_DIR)/pipex.c
SRCS_DIR = ./srcs
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
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

bonus : $(LIBFT) $(OBJS_BONUS) pipex.h
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

rebuild : $(LIBFT) $(OBJS) pipex.h
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME)_bonus
	$(MAKE) -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re bonus
