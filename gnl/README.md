*Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s.*

## Descripción

`get_next_line` es una función en C que implementé para leer un descriptor de fichero línea a línea. Cada vez que se llama, devuelve la siguiente línea del fichero, incluyendo el carácter de salto de línea `\n` cuando está presente. Cuando no hay más líneas que leer, devuelve `NULL`.

El objetivo del proyecto fue entender e implementar una función que mantiene estado entre llamadas usando una variable estática, y que gestiona la lectura en bloques de tamaño fijo independientemente de la longitud real de cada línea.

**Prototipo de la función:**
```c
char *get_next_line(int fd);
```

---

## Instrucciones

### Ficheros

| Fichero | Descripción |
|---|---|
| `get_next_line.c` | Función principal |
| `get_next_line_utils.c` | Funciones auxiliares |
| `get_next_line.h` | Fichero de cabecera |

### Compilación

El proyecto se puede compilar con o sin el flag `-D BUFFER_SIZE`, que controla cuántos bytes se leen de una vez. Si no se proporciona, se usa el valor por defecto definido en el header.

```bash
# Con BUFFER_SIZE personalizado
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Sin flag (usa el BUFFER_SIZE por defecto definido en el header)
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Uso

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("fichero.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Pruebas

```bash
# Prueba con BUFFER_SIZE=1 (caso más extremo)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl && ./gnl fichero.txt

# Prueba con BUFFER_SIZE grande
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c main.c -o gnl && ./gnl fichero.txt
```

---

## Algoritmo

### Visión general

El reto principal que tuve que resolver es que `read()` lee un número fijo de bytes (`BUFFER_SIZE`) cada vez, lo que puede cortar líneas por la mitad o incluir varias líneas en una sola lectura. La función debe por tanto recordar lo que se leyó pero aún no se devolvió entre llamadas.

### La variable estática

Declaré un `static char *stash` dentro de la función. A diferencia de las variables locales normales, una variable estática persiste entre llamadas. Empieza siendo `NULL` y va acumulando contenido a lo largo de las llamadas.

### Paso a paso

**1. Leer en bloques**
Reservo un buffer de `BUFFER_SIZE + 1` bytes. Leo del descriptor de fichero en un bucle, añadiendo cada bloque al stash mediante `ft_strjoin`, hasta que encuentro un `\n` en el stash o se acaba el fichero.

**2. Extraer la línea**
Una vez que el stash contiene un `\n` (o el fichero ha terminado), `ft_extract_line` copia todo desde el inicio del stash hasta el `\n` inclusive en un nuevo string. Ese string es lo que devuelvo.

**3. Actualizar el stash**
`ft_update_stash` descarta la línea devuelta del stash y conserva solo el resto (todo lo que hay después del `\n`). Este resto estará disponible en la siguiente llamada sin necesidad de volver a leer del fichero.

**4. Devolver**
Devuelvo la línea extraída. En la siguiente llamada, el proceso se repite desde el stash, leyendo más del fichero solo si es necesario.

### Por qué elegí este enfoque

Este enfoque es eficiente en memoria y fácil de razonar. El stash actúa como una ventana deslizante sobre el contenido del fichero: nunca contiene más de lo necesario y se actualiza en cada llamada. El uso de una variable estática me permite evitar pasar estado externamente, manteniendo la firma de la función limpia (solo `int fd`).

### Funciones auxiliares que implementé

| Función | Propósito |
|---|---|
| `ft_has_newline` | Devuelve 1 si existe un `\n` en el string, 0 si no |
| `ft_strjoin` | Concatena el stash y el buffer, liberando el stash anterior |
| `ft_extract_line` | Copia desde el inicio del stash hasta el `\n` inclusive |
| `ft_update_stash` | Devuelve todo lo que hay después del `\n`, liberando el stash anterior |
| `ft_strlen` | Devuelve la longitud de un string, gestiona NULL |

---

## Recursos

### Documentación
- [`read()` man page](https://man7.org/linux/man-pages/man2/read.2.html) — llamada al sistema que usé para leer bytes de un descriptor de fichero
- [`open()` man page](https://man7.org/linux/man-pages/man2/open.2.html) — llamada al sistema para abrir ficheros
- [Variables estáticas en C](https://en.wikipedia.org/wiki/Static_variable) — explicación de cómo las variables locales estáticas persisten entre llamadas

### Artículos y tutoriales
- [E/S de ficheros en C](https://www.learn-c.org/en/File_IO) — introducción a la lectura de ficheros en C
- [Gestión de memoria en C](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Memory-Allocation.html) — malloc, free y cómo evitar memory leaks

### Uso de IA

Usé Claude (Anthropic) como asistente de aprendizaje a lo largo de este proyecto. En concreto:

- **Explicación conceptual**: antes de escribir ningún código, pedí que me explicaran el algoritmo general y el flujo de datos para tener un modelo mental claro.
- **Implementación guiada**: escribí cada función auxiliar de forma independiente, y Claude me daba feedback sobre bugs, casos edge y problemas específicos de C.
- **Depuración**: Claude me ayudó a identificar problemas como terminadores `\0` faltantes, errores de use-after-free y condiciones de bucle incorrectas, pero las correcciones las escribí yo siempre.
- **Sin código directo**: escribí todas las funciones desde cero. El papel de Claude fue hacerme preguntas y señalar problemas en lugar de darme soluciones.