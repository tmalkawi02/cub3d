/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:20:04 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}

/*
void	destroy(void *content)
{
	if (!content)
		return ;
	free(content);
}

int main()
{
	t_list	*lst = ft_lstnew("should be last");
	t_list	*second = ft_lstnew("should be second");
	t_list	*first = ft_lstnew("should be first");
	ft_lstadd_front(&lst, second);
	ft_lstadd_front(&lst, first);
	ft_lstclear(&first, &destroy);
	printf("value of lst -> %p", first);
}
*/
