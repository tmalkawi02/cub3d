/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:17 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
	t_list	*lst = ft_lstnew("should be last");
	t_list	*second = ft_lstnew("should be second");
	t_list	*first = ft_lstnew("should be first");
	ft_lstadd_front(&lst, second);
	ft_lstadd_front(&lst, first);
	for (; first; first = first->next) {
		printf("first->content = %s\n", (char *)first->content);
	}
}
*/
