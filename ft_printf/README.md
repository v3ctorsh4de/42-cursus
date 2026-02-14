## *Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s.*

## Descripción
En este proyecto implementé mi propia versión de la función estándar `printf` de C, llamada **ft_printf**.  
El objetivo principal fue entender cómo funciona internamente el formateo de salida en C y cómo manejar especificadores, ancho, precisión y flags.

Mi implementación soporta los formatos más usados, como:
- `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

La idea es que el resultado sea lo más parecido posible al comportamiento de `printf` en casos comunes y límites.

---

## Instrucciones

### 1. Compilación
Para compilar el proyecto, ejecuto:

```bash
make
````

Esto genera el archivo:

```
libftprintf.a
```

---

### 2. Limpieza

Para eliminar los archivos objeto (.o):

```bash
make clean
```

Para eliminar también la librería:

```bash
make fclean
```

Para recompilar desde cero:

```bash
make re
```

---

### 3. Uso de la librería (cómo utilizar ft_printf)

#### 3.1 Incluir el header

En mi archivo `main.c` incluyo:

```c
#include "ft_printf.h"
```

#### 3.2 Ejemplo básico

```c
int main(void)
{
    ft_printf("Hola %s, numero %d, hex %x\n", "mundo", 42, 255);
    return (0);
}
```

#### 3.3 Compilar mi programa usando la librería

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

> `-L.` indica que la librería está en la carpeta actual y `-lftprintf` enlaza `libftprintf.a`.

---

## Recursos

* Documentación oficial de `printf` (man 3 printf)
* [Referencia de conversiones y especificadores](https://en.cppreference.com/w/c/io/fprintf)
* Tutoriales y guías de formateo de strings en C
* Ejemplos de implementación de `printf` en C

### Uso de IA

Durante el desarrollo de este proyecto utilicé IA únicamente para:

* Generar ideas sobre la estructura del código.
* Resolver dudas puntuales sobre lógica y formateo.
* Revisar errores comunes y sugerir mejoras.

No utilicé IA para copiar implementaciones completas ni para sustituir el trabajo propio del proyecto.

---

## Algoritmo y estructura de datos (Explicación y justificación)

### Estructura de datos

Para almacenar los parámetros del formato (`flags`, `width`, `precision`, `specifier`) creé una estructura `t_format`:

```c
typedef struct s_format
{
    int  flag_minus;
    int  flag_zero;
    int  width;
    int  precision;
    int  precision_specified;
    char specifier;
} t_format;
```

**Justificación:**

* Un struct me permite agrupar todos los parámetros en un solo lugar.
* Facilita pasar esta información entre funciones sin usar muchas variables.
* Me permite ampliar el proyecto si necesito añadir nuevos flags o especificadores.

---

### Algoritmo principal

El algoritmo general de `ft_printf` que implementé sigue estos pasos:

1. Recorrer la cadena de formato (`format`) carácter por carácter.
2. Cuando encuentro un `%`, parseo el formato completo hasta llegar al especificador.
3. Guardo flags, ancho, precisión y especificador en `t_format`.
4. Selecciono la función adecuada según el especificador:

   * `%c` → imprimir caracter
   * `%s` → imprimir string
   * `%p` → imprimir puntero en hexadecimal
   * `%d` / `%i` → imprimir entero con signo
   * `%u` → imprimir entero sin signo
   * `%x` / `%X` → imprimir entero en hexadecimal
   * `%%` → imprimir `%`
5. La función de impresión se encarga de:

   * aplicar ancho (`width`)
   * aplicar precisión (`precision`)
   * respetar flags (`-`, `0`)
   * retornar el número de caracteres impresos

**Justificación del algoritmo:**

* Me permite dividir el problema en partes pequeñas y manejables.
* Separa el parseo del formato y la impresión, lo que hace el código más modular.
* Reduce errores al evitar variables globales y facilita futuras ampliaciones.

---

## Ejemplos de uso

```c
ft_printf("String: %s\n", "hola");
ft_printf("Entero: %d\n", 42);
ft_printf("Hex: %x\n", 255);
ft_printf("Puntero: %p\n", &ft_printf);
ft_printf("Porcentaje: %%\n");
```

---

## Limitaciones conocidas

* No implementé especificadores avanzados como `%f`, `%e` o `%g`.
* No soporté flags avanzados como `+` o espacio.
* No implementé modificadores de longitud (`l`, `ll`, `h`, `hh`).

```
```
