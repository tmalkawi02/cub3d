/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:50:17 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int main()
{
	t_list	*lst = ft_lstnew("should be last");
	t_list	*second = ft_lstnew("should be second");
	t_list	*first = ft_lstnew("should be first");
	ft_lstadd_front(&lst, second);
	ft_lstadd_front(&lst, first);
	t_list	*last = ft_lstlast(lst);
	printf("is lst last ? %s", (char *)last->content);
}
*/
