# Nombre del archivo

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c \
	  ft_substr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_split.c ft_strlcat.c \
	  ft_strnstr.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
	  ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c ft_isalnum.c \
	  ft_isprint.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strtrim.c
OBJS = $(SRCS:.c=.o)

# Archivo de encabezado
AR = ar rcs
RM = rm -f

# Reglar por defecto que lo compila todo
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compilacion de archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto (temporales)
clean:
	$(RM) $(OBJS)

# Limpieza total
fclean: clean
	$(RM) $(NAME)

# Recompilacion total
re: fclean
	$(MAKE) all

# Evitar conflicto entre archivos con el mismo nombre
.PHONY: all clean fclean re
