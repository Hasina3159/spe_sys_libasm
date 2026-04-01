NAME = libasm.a
ASM_SRCS = ft_strlen.s ft_write.s
ASM_OBJS = $(ASM_SRCS:.s=.o)
CC = gcc
AS = nasm
ASFLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ASM_OBJS)
	ar rcs $@ $^

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(ASM_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
