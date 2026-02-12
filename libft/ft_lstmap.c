/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:50:59 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/12 09:51:15 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del && new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*#include <stdio.h>
#include <string.h>
void	del(void *content)
{
	free(content);//funcion para usar del.
}
void	*auxdup(void *content)
{
	return ft_strdup((char *)content);//funcio para usar (f)
}
int	main(void)
{
	t_list	*list = NULL;//crear lista vacia
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*newlist;//crear nueva lista

	nodo1 = ft_lstnew(ft_strdup("hola"));//creacio nodo1
	nodo2 = ft_lstnew(ft_strdup("hello"));//creacio nodo2

	ft_lstadd_front(&list, nodo1);//poner en lista 1ro
	ft_lstadd_back(&list, nodo2);//poner en lista ultimo

	newlist = ft_lstmap(list, auxdup, del);//funcion map crear nueva lista
	
	printf("lista original = %d\n\n", ft_lstsize(list));//size lista orig.
	printf("lista nueva = %d\n", ft_lstsize(newlist));//size nueva lista

	return (0);
}*/
/*en esta funcion lo que tenemos que hacer es crear una nueva lista aplicando
cambios con la (*f)=funcion que nos pasan por parametros,eso quiere decir
que hacemos una replica del contenido original pero con los cambios que 
querramos y la lista orgirinal no se toca, se mantiene y solo se aplican los 
cambios deseados a la nueva lista en este caso si la lista llega a fallar tiene 
que liberar todos los nodos creador de la nueva lista
para eso necesitamos crear una nueva lista, nuevos nodos y el contenido que 
modificaremos con "f" para pasarlo a los nuevos nodos */
