## *Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s.*

## Descripción
En este proyecto implementé mi propia versión de la función estándar `printf` de C, llamada **ft_printf**.  
El objetivo principal fue entender cómo funciona internamente el formateo de salida básico en C y el manejo de argumentos variables (`va_list`).

Mi implementación soporta las siguientes conversiones:
- `%c`: Imprime un solo carácter.
- `%s`: Imprime una cadena de caracteres (string).
- `%p`: El puntero `void *` dado como argumento se imprime en formato hexadecimal.
- `%d`: Imprime un número decimal (base 10).
- `%i`: Imprime un entero en base 10.
- `%u`: Imprime un número decimal sin signo (unsigned).
- `%x`: Imprime un número hexadecimal (base 16) en minúsculas.
- `%X`: Imprime un número hexadecimal (base 16) en mayúsculas.
- `%%`: Imprime el signo de porcentaje.

---

## Instrucciones

### 1. Compilación
Para compilar el proyecto y generar la librería estática, ejecuta:

```bash
make
```

Esto generará el archivo `libftprintf.a`.

### 2. Limpieza

Para eliminar los archivos objeto (.o):

```bash
make clean
```

Para eliminar también la librería `libftprintf.a`:

```bash
make fclean
```

Para recompilar desde cero:

```bash
make re
```

---

### 3. Uso de la librería

Para usar `ft_printf` en tus proyectos, debes incluir el header y enlazar la librería compilada.

#### 3.1 Incluir el header

En tu archivo fuente (`.c`):

```c
#include "ft_printf.h"
```

#### 3.2 Ejemplo de uso

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Caracter: %c\n", 'A');
    ft_printf("String: %s\n", "Hola mundo");
    ft_printf("Entero: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    int x;
    ft_printf("Puntero: %p\n", &x);
    return (0);
}
```

#### 3.3 Compilar tu programa

Asumiendo que tienes un `main.c` y la librería `libftprintf.a` en el mismo directorio:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o mi_programa
```

---

## Implementación

El funcionamiento de `ft_printf` es directo y se basa en el manejo de argumentos variables:

1.  Recorre la cadena de formato (`format`) carácter por carácter.
2.  Si encuentra un `%`, lee el siguiente carácter para determinar el tipo de conversión.
3.  Llama a una función auxiliar específica (`dispatch`) que extrae el argumento correspondiente usando `va_arg` y lo imprime con la función helper adecuada (`ft_putchar`, `ft_putstr`, `ft_putnbr`, etc.).
4.  Lleva la cuenta de todos los caracteres impresos y la retorna al final, o `-1` si ocurre un error de escritura.

---

## Recursos utilizados
* `man 3 printf`
* `man 3 stdarg`

---

## Limitaciones

Esta versión **no implementa**:
*   Flags (`-`, `0`, `#`, `+`, espacio).
*   Ancho mínimo de campo (`width`).
*   Precisión (`.` followed by a number).
*   Modificadores de longitud (`l`, `ll`, `h`, `hh`).
