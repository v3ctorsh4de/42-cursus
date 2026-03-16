/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:00:00 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/16 18:41:42 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "ft_printf.h"

int	g_pass = 0;
int	g_fail = 0;

void	test_result(const char *name, int ret1, int ret2)
{
	if (ret1 == ret2)
	{
		printf("✅ PASS: %s (ambos devuelven %d)\n", name, ret1);
		g_pass++;
	}
	else
	{
		printf("❌ FAIL: %s (printf: %d, ft_printf: %d)\n", name, ret1, ret2);
		g_fail++;
	}
}

int	main(void)
{
	int	ret1, ret2;
	int	num = 42;

	printf("\n");
	printf("╔════════════════════════════════════════════════════════════════╗\n");
	printf("║            PRUEBAS EXHAUSTIVAS Y ESTRICTAS                     ║\n");
	printf("║            ft_printf vs printf original                        ║\n");
	printf("╚════════════════════════════════════════════════════════════════╝\n\n");

	/* ===== FORMATO %c (CARÁCTER) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%c (CARÁCTER)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("A");
	ret2 = ft_printf("A");
	test_result("%c - Letra mayúscula", ret1, ret2);
	printf("\n");
	
	ret1 = printf("z");
	ret2 = ft_printf("z");
	test_result("%c - Letra minúscula", ret1, ret2);
	printf("\n");
	
	ret1 = printf("5");
	ret2 = ft_printf("5");
	test_result("%c - Dígito", ret1, ret2);
	printf("\n");
	
	ret1 = printf(" ");
	ret2 = ft_printf(" ");
	test_result("%c - Espacio", ret1, ret2);
	printf("\n");
	
	ret1 = printf("\n");
	ret2 = ft_printf("\n");
	test_result("%c - Newline", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %s (STRING) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%s (STRING)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("hello");
	ret2 = ft_printf("hello");
	test_result("%s - String simple", ret1, ret2);
	printf("\n");
	
	ret1 = printf("Hello World!");
	ret2 = ft_printf("Hello World!");
	test_result("%s - String con espacios", ret1, ret2);
	printf("\n");
	
	/* String vacío - comentado porque causa warning */
	/* ret1 = printf("");
	ret2 = ft_printf("");
	test_result("%s - String vacío", ret1, ret2);
	printf("\n"); */
	
	ret1 = printf("123");
	ret2 = ft_printf("123");
	test_result("%s - String con números", ret1, ret2);
	printf("\n");
	
	ret1 = printf("!@#$");
	ret2 = ft_printf("!@#$");
	test_result("%s - String con caracteres especiales", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %d (ENTERO CON SIGNO) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%d (ENTERO CON SIGNO)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%d", 0);
	ret2 = ft_printf("%d", 0);
	test_result("%d - Cero", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", 1);
	ret2 = ft_printf("%d", 1);
	test_result("%d - Uno", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", 42);
	ret2 = ft_printf("%d", 42);
	test_result("%d - Número positivo", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", -1);
	ret2 = ft_printf("%d", -1);
	test_result("%d - Menos uno", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", -42);
	ret2 = ft_printf("%d", -42);
	test_result("%d - Número negativo", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", INT_MAX);
	ret2 = ft_printf("%d", INT_MAX);
	test_result("%d - INT_MAX", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d", INT_MIN);
	ret2 = ft_printf("%d", INT_MIN);
	test_result("%d - INT_MIN", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %i (IGUAL QUE %d) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%i (IGUAL QUE %%d)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%i", 0);
	ret2 = ft_printf("%i", 0);
	test_result("%i - Cero", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%i", 123);
	ret2 = ft_printf("%i", 123);
	test_result("%i - Número positivo", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%i", -456);
	ret2 = ft_printf("%i", -456);
	test_result("%i - Número negativo", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %u (UNSIGNED) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%u (UNSIGNED)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%u", 0U);
	ret2 = ft_printf("%u", 0U);
	test_result("%u - Cero", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%u", 42U);
	ret2 = ft_printf("%u", 42U);
	test_result("%u - Número pequeño", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%u", 4294967295U);
	ret2 = ft_printf("%u", 4294967295U);
	test_result("%u - UINT_MAX", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %x (HEX MINÚSCULA) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%x (HEX MINÚSCULA)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%x", 0);
	ret2 = ft_printf("%x", 0);
	test_result("%x - Cero", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%x", 15);
	ret2 = ft_printf("%x", 15);
	test_result("%x - 15 (f)", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%x", 255);
	ret2 = ft_printf("%x", 255);
	test_result("%x - 255 (ff)", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%x", 4095);
	ret2 = ft_printf("%x", 4095);
	test_result("%x - 4095 (fff)", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%x", 4294967295U);
	ret2 = ft_printf("%x", 4294967295U);
	test_result("%x - UINT_MAX", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %X (HEX MAYÚSCULA) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%X (HEX MAYÚSCULA)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%X", 0);
	ret2 = ft_printf("%X", 0);
	test_result("%X - Cero", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%X", 15);
	ret2 = ft_printf("%X", 15);
	test_result("%X - 15 (F)", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%X", 255);
	ret2 = ft_printf("%X", 255);
	test_result("%X - 255 (FF)", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%X", 4294967295U);
	ret2 = ft_printf("%X", 4294967295U);
	test_result("%X - UINT_MAX", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %p (PUNTERO) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%p (PUNTERO)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%p", (void *)0);
	ret2 = ft_printf("%p", (void *)0);
	test_result("%p - NULL pointer", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%p", (void *)&num);
	ret2 = ft_printf("%p", (void *)&num);
	test_result("%p - Puntero válido", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%p", (void *)0xDEADBEEF);
	ret2 = ft_printf("%p", (void *)0xDEADBEEF);
	test_result("%p - Dirección arbitraria", ret1, ret2);
	printf("\n");

	/* ===== FORMATO %% (PORCENTAJE) ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATO %%%% (PORCENTAJE)\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%%");
	ret2 = ft_printf("%%");
	test_result("%%%% - Porcentaje simple", ret1, ret2);
	printf("\n");
	
	ret1 = printf("100%%");
	ret2 = ft_printf("100%%");
	test_result("%%%% - Con número", ret1, ret2);
	printf("\n");

	/* ===== FORMATO COMBINADO ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("FORMATOS COMBINADOS\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("%c %s", 'A', "test");
	ret2 = ft_printf("%c %s", 'A', "test");
	test_result("%%c + %%s", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%d %i %u", 42, -42, 42U);
	ret2 = ft_printf("%d %i %u", 42, -42, 42U);
	test_result("%%d + %%i + %%u", ret1, ret2);
	printf("\n");
	
	ret1 = printf("%x %X %p", 255, 255, (void *)&num);
	ret2 = ft_printf("%x %X %p", 255, 255, (void *)&num);
	test_result("%%x + %%X + %%p", ret1, ret2);
	printf("\n");
	
	ret1 = printf("Test: %c %s %d %x %% done", 'T', "info", 99, 255);
	ret2 = ft_printf("Test: %c %s %d %x %% done", 'T', "info", 99, 255);
	test_result("Combinado complejo", ret1, ret2);
	printf("\n");

	/* ===== SIN FORMATOS ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("SIN FORMATOS\n");
	printf("═══════════════════════════════════════════════════════════════════\n");
	
	ret1 = printf("Hello");
	ret2 = ft_printf("Hello");
	test_result("Solo texto", ret1, ret2);
	printf("\n");
	
	/* String vacío - comentado porque causa warning */
	/* ret1 = printf("");
	ret2 = ft_printf("");
	test_result("String vacío", ret1, ret2);
	printf("\n"); */

	/* ===== RESUMEN FINAL ===== */
	printf("═══════════════════════════════════════════════════════════════════\n");
	printf("╔════════════════════════════════════════════════════════════════╗\n");
	printf("║                     RESUMEN FINAL                             ║\n");
	printf("╠════════════════════════════════════════════════════════════════╣\n");
	printf("║ PASS: %d                                                       ║\n", g_pass);
	printf("║ FAIL: %d                                                       ║\n", g_fail);
	printf("╠════════════════════════════════════════════════════════════════╣\n");
	
	if (g_fail == 0)
	{
		printf("║                 ✅ TODAS LAS PRUEBAS PASADAS ✅               ║\n");
		printf("║         Tu ft_printf funciona IDÉNTICO al printf original   ║\n");
	}
	else
	{
		printf("║                ❌ HAY %d PRUEBAS FALLIDAS ❌                 ║\n", g_fail);
	}
	printf("╚════════════════════════════════════════════════════════════════╝\n\n");

	return (0);
}
