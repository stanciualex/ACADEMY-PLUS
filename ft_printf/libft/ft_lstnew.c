/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:10:40 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 15:43:00 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		p->content = (void *)malloc(sizeof(content) * content_size);
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}
