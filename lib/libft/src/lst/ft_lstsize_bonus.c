/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:33:18 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}

/*
int main()
{
	t_list	*lst = ft_lstnew("should be last");
	t_list	*second = ft_lstnew("should be second");
	t_list	*first = ft_lstnew("should be first");
	ft_lstadd_front(&lst, second);
	ft_lstadd_front(&lst, first);
	int	size = ft_lstsize(lst);
	printf("lst size -> %d", size);
}
*/
