# Libft

*Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s.*

## Descripción

Libft es el primer proyecto de 42 que consiste en recrear desde cero una biblioteca de funciones estándar de C. El objetivo principal es comprender el funcionamiento interno de estas funciones, mejorar las habilidades de programación en C y crear una biblioteca personal reutilizable para futuros proyectos del cursus.

Este proyecto incluye la implementación de funciones de manipulación de strings, memoria, conversión de datos y listas enlazadas, todas cumpliendo con la Norminette de 42.

## Instrucciones

### Compilación

Para compilar la biblioteca, ejecuta:
```bash
make
```

Esto generará el archivo `libft.a` que podrás enlazar con tus proyectos.

### Comandos disponibles

- `make` - Compila la biblioteca
- `make clean` - Elimina los archivos objeto (.o)
- `make fclean` - Elimina los archivos objeto y libft.a
- `make re` - Recompila todo desde cero

### Uso en tus proyectos
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putstr_fd(str, 1);
    free(str);
    return (0);
}
```

## Recursos

### Documentación y Referencias
- [Manual de C (man pages)](https://man7.org/linux/man-pages/)
- [The C Programming Language - Kernighan & Ritchie](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)

### Uso de IA
Se ha utilizado Claude AI para:
- **Debugging**: Identificación de errores de sintaxis y lógica en funciones específicas
- **Optimización**: Sugerencias para simplificar código repetitivo (ejemplo: uso de ft_strchr en ft_strtrim)
- **Clarificación de conceptos**: Explicación de punteros const y castings en funciones de memoria

El código final ha sido escrito y comprendido completamente por el estudiante.

## Descripción de la Librería

### Funciones de Comprobación de Caracteres
- `ft_isalpha` - Verifica si es una letra
- `ft_isdigit` - Verifica si es un dígito
- `ft_isalnum` - Verifica si es alfanumérico
- `ft_isascii` - Verifica si es ASCII
- `ft_isprint` - Verifica si es imprimible

### Funciones de Manipulación de Strings
- `ft_strlen` - Calcula la longitud de un string
- `ft_strchr` - Busca un carácter en un string
- `ft_strrchr` - Busca un carácter desde el final
- `ft_strncmp` - Compara n caracteres de dos strings
- `ft_strnstr` - Busca un substring en otro string
- `ft_strdup` - Duplica un string
- `ft_substr` - Extrae un substring
- `ft_strjoin` - Concatena dos strings
- `ft_strtrim` - Elimina caracteres del inicio y final
- `ft_split` - Divide un string por un delimitador
- `ft_strmapi` - Aplica una función a cada carácter
- `ft_striteri` - Itera aplicando una función

### Funciones de Memoria
- `ft_memset` - Llena memoria con un byte
- `ft_bzero` - Pone a cero un bloque de memoria
- `ft_memcpy` - Copia n bytes de memoria
- `ft_memmove` - Copia n bytes (con overlapping)
- `ft_memchr` - Busca un byte en memoria
- `ft_memcmp` - Compara n bytes de memoria
- `ft_calloc` - Asigna memoria inicializada a cero

### Funciones de Conversión
- `ft_atoi` - Convierte string a entero
- `ft_itoa` - Convierte entero a string
- `ft_tolower` - Convierte a minúscula
- `ft_toupper` - Convierte a mayúscula

### Funciones de Salida
- `ft_putchar_fd` - Escribe un carácter en un fd
- `ft_putstr_fd` - Escribe un string en un fd
- `ft_putendl_fd` - Escribe un string + newline en un fd
- `ft_putnbr_fd` - Escribe un número en un fd

### Bonus: Funciones de Listas Enlazadas
- `ft_lstnew` - Crea un nuevo nodo
- `ft_lstadd_front` - Añade nodo al principio
- `ft_lstadd_back` - Añade nodo al final
- `ft_lstsize` - Cuenta los nodos
- `ft_lstlast` - Obtiene el último nodo
- `ft_lstdelone` - Elimina un nodo
- `ft_lstclear` - Elimina todos los nodos
- `ft_lstiter` - Itera aplicando una función
- `ft_lstmap` - Crea nueva lista aplicando función

## Normas de 42

Todas las funciones cumplen con:
- ✅ Norminette v3
- ✅ Sin memory leaks
- ✅ Manejo correcto de casos edge
- ✅ Protección contra NULL pointers

---

**Nota**: Este proyecto es solo con fines educativos como parte del programa de 42.

