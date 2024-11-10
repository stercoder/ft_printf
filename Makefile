CC = gcc
CFLAGS = -Wall -Wextra -Werror
 
NAME = libftprintf.a
SRCS = src/ft_printf.c \
		src/print_char.c \
		src/print_str.c \
		src/print_pointer.c \
		src/print_int.c \
		src/print_unsigned.c \
		src/print_hex.c \
		src/utils.c
OBJS = $(SRCS:.c=.o)

OBJ_DIR = obj
SRC_DIR = .

AR = ar rcs
RM = rm -f


all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Library $(NAME) cleaned."

re: fclean all
