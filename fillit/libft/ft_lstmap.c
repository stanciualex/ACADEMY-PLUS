/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:39:50 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 15:41:18 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;
	t_list *aux;

	aux = (*f)(lst);
	p = aux;
	if (p == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		aux->next = (*f)(lst);
		if (aux->next == NULL)
			return (NULL);
		aux = aux->next;
	}
	return (p);
}
