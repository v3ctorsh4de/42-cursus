## *Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s.*

## Descripción

Get Next Line es un proyecto de 42 que consiste en crear una función que lee y devuelve una línea completa desde un descriptor de archivo (file descriptor). Este proyecto es fundamental para comprender la gestión de memoria dinámica, el uso de variables estáticas y el manejo de buffers en C.

**Objetivo principal:** Implementar una función que, al ser llamada repetidamente, lea un archivo línea por línea de manera eficiente, gestionando correctamente la memoria y manejando diferentes tamaños de buffer.

**Contexto:** Este proyecto enseña conceptos esenciales de programación en C como:
- Gestión de memoria dinámica (malloc/free)
- Variables estáticas para mantener estado entre llamadas
- Lectura de archivos mediante system calls (read)
- Manejo de buffers y optimización de lecturas
- Edge cases y gestión de errores

## Instrucciones

### Compilación

```bash
# Clonar el repositorio
git clone [URL_del_repositorio]
cd get_next_line

# Compilar con un BUFFER_SIZE específico (ejemplo: 42)
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Compilar con valor por defecto (si está definido en el código)
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
```

### Ejecución

Para probar la función, necesitas crear un programa main que la utilice:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
# Compilar con tu main
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl

# Ejecutar
./gnl
```

### Valores de BUFFER_SIZE Recomendados para Pruebas

```bash
# BUFFER_SIZE pequeño (cada read obtiene pocos bytes)
cc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# BUFFER_SIZE mediano (valor típico)
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# BUFFER_SIZE grande (lectura de grandes bloques)
cc -Wall -Werror -Wextra -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c

# BUFFER_SIZE muy grande (prueba de límites)
cc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 get_next_line.c get_next_line_utils.c
```

## Algoritmo Seleccionado

### Descripción del Algoritmo

He implementado un **algoritmo de lectura con buffer estático y acumulación progresiva** que mantiene el contenido no procesado entre llamadas sucesivas mediante una variable estática.

**Funcionamiento detallado:**

1. **Inicialización:** Se declara una variable estática `backup` que persiste entre llamadas a la función, almacenando los bytes leídos pero aún no devueltos.

2. **Lectura incremental:** 
   - Se lee el archivo en bloques de tamaño `BUFFER_SIZE` usando `read()`
   - Cada lectura se añade al `backup` mediante concatenación
   - Este proceso continúa hasta encontrar un `\n` o llegar al final del archivo (EOF)

3. **Extracción de línea:**
   - Se busca el primer `\n` en el `backup`
   - Se extrae todo hasta (e incluyendo) el `\n` como la línea a devolver
   - El resto se mantiene en `backup` para la siguiente llamada

4. **Gestión del residuo:**
   - Lo que queda en `backup` después de extraer la línea se conserva
   - En la siguiente llamada, se usa este residuo antes de leer más del archivo
   - Esto evita lecturas innecesarias y mantiene eficiencia

5. **Casos especiales:**
   - **Última línea sin `\n`:** Se devuelve el contenido completo del `backup`
   - **EOF alcanzado:** Se devuelve `NULL` y se libera `backup`
   - **Error en `read()`:** Se libera memoria y se devuelve `NULL`

### Justificación de la Elección

#### Eficiencia

- **Complejidad temporal:** O(n) donde n es el tamaño de la línea
  - Cada byte se lee y procesa exactamente una vez
  - No hay relecturas innecesarias del mismo contenido
  
- **Complejidad espacial:** O(BUFFER_SIZE + longitud_línea_máxima)
  - Memoria proporcional al tamaño del buffer y la línea más larga
  - La variable estática reutiliza espacio entre llamadas

#### Ventajas del Enfoque

- **Lectura mínima:** Solo lee lo necesario, cumpliendo con el requisito del subject
- **Estado persistente:** La variable estática permite mantener contexto entre llamadas sin variables globales
- **Flexibilidad:** Funciona correctamente con cualquier BUFFER_SIZE (1, 42, 9999, 10000000)
- **Manejo robusto:** Gestiona correctamente archivos, stdin, EOF y errores

#### Comparación con Alternativas

**Alternativa 1: Lectura byte a byte**
- ❌ Extremadamente ineficiente: una syscall `read()` por cada carácter
- ❌ No aprovecha el BUFFER_SIZE
- ✅ Simple de implementar
- **Por qué no:** El número excesivo de llamadas al sistema degradaría severamente el rendimiento

**Alternativa 2: Leer todo el archivo de una vez**
- ❌ Viola el requisito de "leer lo menos posible"
- ❌ Consumo de memoria proporcional al tamaño total del archivo
- ❌ No funciona con archivos enormes o streams infinitos
- **Por qué no:** Ineficiente en memoria y no cumple las especificaciones

**Alternativa 3: Buffer circular sin variable estática**
- ❌ Requeriría variables globales (prohibidas) o estructuras complejas
- ❌ Mayor complejidad sin beneficios reales
- **Por qué no:** La variable estática ofrece una solución más elegante y simple

#### Adecuación al Problema

Este algoritmo es **óptimo** para get_next_line porque:

1. **Cumple todos los requisitos:**
   - Devuelve líneas completas con `\n`
   - Gestiona correctamente el EOF sin `\n` final
   - No usa variables globales ni `lseek`
   - Lee lo mínimo necesario en cada llamada

2. **Escalabilidad:**
   - Funciona con BUFFER_SIZE=1 (caso extremo, muchas lecturas pequeñas)
   - Funciona con BUFFER_SIZE=10000000 (caso extremo, pocas lecturas grandes)
   - Autoajusta su comportamiento según el BUFFER_SIZE

3. **Robustez:**
   - Maneja múltiples file descriptors simultáneamente (con array estático)
   - Gestión de memoria sin fugas (leaks)
   - Comportamiento predecible en todos los escenarios

### Optimizaciones Implementadas

1. **Concatenación eficiente:** Uso de funciones auxiliares optimizadas para minimizar realocaciones
2. **Liberación temprana:** La memoria del backup se libera tan pronto como no es necesaria
3. **Reutilización de buffer:** El contenido sobrante se mantiene para evitar relecturas
4. **Validación temprana:** Comprobación de errores al inicio para salir rápido en casos inválidos

### Consideraciones sobre BUFFER_SIZE

**BUFFER_SIZE = 1:**
- Funciona correctamente pero con máximo número de syscalls
- Útil para detectar edge cases
- Lento pero correcto

**BUFFER_SIZE = 42 (valor típico):**
- Balance óptimo entre número de syscalls y memoria usada
- Rendimiento eficiente para archivos normales

**BUFFER_SIZE = 9999:**
- Muy eficiente para archivos con líneas largas
- Pocas llamadas a read()
- Mayor uso de memoria

**BUFFER_SIZE = 10000000:**
- Puede causar problemas de memoria en sistemas con recursos limitados
- Funciona, pero el beneficio marginal es mínimo comparado con valores menores
- Útil para archivos con líneas extremadamente largas

## Características

- ✅ Lectura línea por línea desde cualquier file descriptor
- ✅ Manejo correcto de stdin
- ✅ Gestión de archivos sin `\n` final
- ✅ Sin memory leaks
- ✅ Funciona con cualquier BUFFER_SIZE válido
- ✅ Manejo de múltiples file descriptors (bonus - si implementado)
- ✅ Comportamiento correcto con archivos vacíos
- ✅ Gestión de errores robusta

## Decisiones Técnicas

### Uso de Variable Estática

**Decisión:** Utilizar una variable estática para mantener el buffer entre llamadas.

**Justificación:**
- Las variables globales están prohibidas
- La variable estática permite mantener estado sin romper las reglas
- Cada file descriptor puede tener su propio backup (array estático)
- Solución elegante y eficiente para el problema planteado

### Estructura del Código

**Decisión:** Separar funciones auxiliares en `get_next_line_utils.c`.

**Justificación:**
- Código más modular y mantenible
- Cumple con la norma de 42 (funciones de máximo 25 líneas)
- Facilita el testing individual de componentes
- Reutilización de código entre funciones

### Gestión de Memoria

**Decisión:** Liberar memoria inmediatamente cuando ya no se necesita.

**Justificación:**
- Evita memory leaks
- Minimiza la huella de memoria del programa
- Cumple con las buenas prácticas de programación en C

## Recursos

### Documentación Oficial

- [Man page de read(2)](https://man7.org/linux/man-pages/man2/read.2.html) - System call para lectura de archivos
- [Man page de malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html) - Asignación dinámica de memoria
- [Man page de open(2)](https://man7.org/linux/man-pages/man2/open.2.html) - Apertura de file descriptors
- [File descriptors en Linux](https://en.wikipedia.org/wiki/File_descriptor) - Concepto de descriptores de archivo

### Artículos y Tutoriales

- [Understanding Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Explicación detallada de variables estáticas
- [File I/O in C](https://www.tutorialspoint.com/cprogramming/c_file_io.htm) - Tutorial sobre entrada/salida de archivos
- [Memory Management in C](https://www.programiz.com/c-programming/c-dynamic-memory-allocation) - Gestión de memoria dinámica
- [Buffer Overflow Prevention](https://owasp.org/www-community/vulnerabilities/Buffer_Overflow) - Prevención de desbordamientos

### Libros y Referencias Clásicas

- **The C Programming Language** por Brian Kernighan y Dennis Ritchie - Capítulos 7 y 8 (I/O y sistema Unix)
- **Advanced Programming in the UNIX Environment** por W. Richard Stevens - Capítulo 3 (File I/O)
- **C Interfaces and Implementations** por David R. Hanson - Técnicas de gestión de memoria

### Vídeos y Cursos

- [Oceano's Get Next Line Tutorial](https://www.youtube.com/watch?v=8E9siq7apUU) - Tutorial específico para el proyecto
- [Jacob Sorber - File I/O in C](https://www.youtube.com/watch?v=BQJBe4IbsvQ) - Conceptos de lectura de archivos
- [Code Vault - Static Variables](https://www.youtube.com/watch?v=OngGUoENgWo) - Explicación de variables estáticas

### Uso de Inteligencia Artificial

**Herramientas utilizadas:**
- Claude (Anthropic) para consultas conceptuales y debugging
- ChatGPT para generación de casos de prueba

**Tareas específicas en las que se utilizó IA:**

1. **Comprensión de variables estáticas** - Fase inicial de diseño
   - Descripción: Consulta sobre el comportamiento y alcance de variables estáticas en C
   - Uso: Para entender cómo mantener estado entre llamadas a funciones sin usar variables globales
   - Resultado: Comprensión teórica que luego implementé manualmente

2. **Casos edge case** - Fase de testing
   - Descripción: Generación de lista de casos límite a probar (BUFFER_SIZE=1, archivos vacíos, sin \n final, etc.)
   - Uso: Para asegurar que la función maneja todos los escenarios posibles
   - Resultado: Lista de 15+ escenarios de prueba que implementé y validé

3. **Optimización de concatenación de strings** - Fase de optimización
   - Descripción: Consulta sobre técnicas para minimizar realocaciones de memoria al concatenar strings
   - Uso: Para optimizar la función de join/concatenación en utils
   - Resultado: Comprensión de estrategias que adapté a mi implementación

4. **Debugging de memory leaks** - Fase de depuración
   - Descripción: Análisis de patrones comunes de memory leaks en funciones similares
   - Uso: Para identificar dónde podría haber fugas en mi código
   - Resultado: Checklist de puntos a verificar con valgrind

5. **Documentación y README** - Fase de documentación
   - Descripción: Estructura y formato para README profesional según estándares de 42
   - Uso: Para crear documentación clara y completa del proyecto
   - Resultado: Template que personalicé con la información específica de mi proyecto

**Aclaraciones:**
- **Todo el código fue escrito personalmente** - La IA nunca generó código directamente
- La IA se utilizó como **herramienta de consulta y aprendizaje**, similar a leer Stack Overflow o documentación
- Cada concepto sugerido fue **estudiado, comprendido y validado** antes de implementarlo
- El algoritmo final es resultado de **mi propio análisis y diseño**, no de sugerencias de IA
- Uso ético: la IA aceleró el aprendizaje, pero **no reemplazó el proceso de comprensión**

## Ejemplos de Uso

### Ejemplo 1: Lectura de archivo simple

**Archivo test.txt:**
```
Hola mundo
Segunda línea
Tercera línea
```

**Código:**
```c
int fd = open("test.txt", O_RDONLY);
char *line;

line = get_next_line(fd);  // "Hola mundo\n"
free(line);
line = get_next_line(fd);  // "Segunda línea\n"
free(line);
line = get_next_line(fd);  // "Tercera línea\n"
free(line);
line = get_next_line(fd);  // NULL (EOF)
close(fd);
```

### Ejemplo 2: Lectura desde stdin

```bash
$ echo -e "Primera\nSegunda\nTercera" | ./gnl
Primera
Segunda
Tercera
```

### Ejemplo 3: Archivo sin \n final

**Archivo test2.txt:**
```
Línea uno
Línea dos sin salto de línea```

**Resultado:**
```c
line = get_next_line(fd);  // "Línea uno\n"
line = get_next_line(fd);  // "Línea dos sin salto de línea"
line = get_next_line(fd);  // NULL
```

### Ejemplo 4: Archivo vacío

```c
int fd = open("empty.txt", O_RDONLY);
char *line = get_next_line(fd);  // NULL
close(fd);
```

### Ejemplo 5: Línea muy larga con BUFFER_SIZE pequeño

**Con BUFFER_SIZE=1:**
```c
// Archivo con línea de 1000 caracteres
// La función hará ~1000 llamadas a read()
// Pero devolverá correctamente la línea completa
```

## Testing

### Pruebas Manuales

```bash
# Crear archivos de prueba
echo -e "Línea 1\nLínea 2\nLínea 3" > test.txt
echo -n "Sin salto final" > test_no_nl.txt
touch empty.txt

# Compilar y probar
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
./gnl
```

### Verificación de Memory Leaks

```bash
# Con valgrind
valgrind --leak-check=full --show-leak-kinds=all ./gnl

# Debe mostrar: "All heap blocks were freed -- no leaks are possible"
```

### Testers Recomendados

```bash
# Tripouille's GNL Tester
git clone https://github.com/Tripouille/gnlTester.git
cd gnlTester
make m

# 42-Tests
git clone https://github.com/Mazoise/42TESTERS-GNL.git
cd 42TESTERS-GNL
./all_tests.sh
```

### Diferentes BUFFER_SIZE

```bash
# Test con múltiples BUFFER_SIZE
for size in 1 10 42 100 1000 10000 9999 10000000; do
    echo "Testing with BUFFER_SIZE=$size"
    cc -Wall -Werror -Wextra -D BUFFER_SIZE=$size main.c get_next_line.c get_next_line_utils.c -o gnl
    ./gnl test.txt
    echo "---"
done
```

## Norma (Norminette)

El código cumple estrictamente con la Norma de 42:

```bash
# Verificar todos los archivos
norminette get_next_line.c get_next_line_utils.c get_next_line.h

# Salida esperada: "OK!" para todos los archivos
```

## Archivos del Proyecto

```
get_next_line/
├── get_next_line.c           # Función principal
├── get_next_line_utils.c     # Funciones auxiliares
├── get_next_line.h           # Header con prototipos
└── README.md                 # Este archivo
```

## Consideraciones Importantes

### ⚠️ Comportamiento Indefinido

Según el subject, get_next_line() tiene comportamiento indefinido en estos casos:
- El archivo cambió entre llamadas (sin haber llegado a EOF)
- Lectura de archivos binarios (aunque se puede manejar)

### ✅ Requisitos Cumplidos

- ✅ Retorna la línea leída incluyendo el `\n`
- ✅ Retorna la última línea sin `\n` si el archivo no termina en `\n`
- ✅ Retorna NULL al llegar a EOF o en caso de error
- ✅ Funciona con archivos y stdin
- ✅ Compila con y sin `-D BUFFER_SIZE=n`
- ✅ No usa libft, lseek ni variables globales
- ✅ Solo usa read, malloc y free

### 🎯 Bonus (si implementado)

- Manejo de múltiples file descriptors simultáneamente
- Un solo backup estático maneja varios fd

## Autor

**jreyes-s** - 42 Madrid - Fecha de finalización: [MM/YYYY]

## Licencia

Este proyecto es parte del currículo educativo de 42. Consulta las políticas de tu campus sobre compartir código.

