# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

# Library Name
NAME    = libft.a

# Libft Source Files
LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c

# ft_printf Source Files
PRINTF_DIR = printf
PRINTF_UTIL_DIR = $(PRINTF_DIR)/ft_printf_util

PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_format.c
PRINTF_UTIL_SRCS = $(PRINTF_UTIL_DIR)/ft_char_format.c $(PRINTF_UTIL_DIR)/ft_str_format.c \
	$(PRINTF_UTIL_DIR)/ft_decimal_format.c $(PRINTF_UTIL_DIR)/ft_unsigned_format.c \
	$(PRINTF_UTIL_DIR)/ft_ptr_format.c $(PRINTF_UTIL_DIR)/ft_hex_format.c

# Object Files
LIBFT_OBJ = $(LIBFT_SRCS:%.c=%.o)
PRINTF_OBJS = $(PRINTF_SRCS:$(PRINTF_DIR)/%.c=$(PRINTF_DIR)/%.o)
PRINTF_UTIL_OBJS = $(PRINTF_UTIL_SRCS:$(PRINTF_UTIL_DIR)/%.c=$(PRINTF_UTIL_DIR)/%.o)
# Default Rule
all: $(NAME)

# Create the Library
$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJS) $(PRINTF_UTIL_OBJS)
	ar rcs $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJS) $(PRINTF_UTIL_OBJS)
	@echo "Library $(NAME) created successfully!"

# Compile Source Files into Object Files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean:
	rm -f $(LIBFT_OBJ) $(PRINTF_OBJS) $(PRINTF_UTIL_OBJS)
	@echo "Object files cleaned!"

fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed!"

re: fclean all

# Phony Targets
.PHONY: all clean fclean re
