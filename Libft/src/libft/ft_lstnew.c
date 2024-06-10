/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:19:42 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:08 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Create a new node using malloc(3). The variable 'content' is initialized
	with the content of the 'content' parameter. The variable variable 'next'
	is initialized with NULL.

RETURN VALUE
	The new node
*/

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return ((void *)0);
	ret -> content = content;
	ret -> next = (void *)0;
	return (ret);
}
