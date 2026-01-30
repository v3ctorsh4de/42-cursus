# Nombre del archivo de salida
NAME        = libft.a

# Compilador y flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Archivos fuente (basado en tu lista)
SRC         = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
              ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
              ft_memcpy.c ft_strlcpy.c ft_strlcat.c \
              ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
              ft_strncmp.c ft_memchr.c ft_memmove.c ft_memcmp.c \
			  ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c \

# Transformamos los .c en .o
OBJ         = $(SRC:.c=.o)

# Regla principal
all: $(NAME)

# Creación de la librería estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilación de archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos temporales
clean:
	rm -f $(OBJ)

# Limpieza total
fclean: clean
	rm -f $(NAME)

# Re-compilación total
re: fclean all

# Evita conflictos con archivos del mismo nombre
.PHONY: all clean fclean re
