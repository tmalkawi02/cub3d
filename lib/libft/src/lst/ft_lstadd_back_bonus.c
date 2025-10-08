/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:56 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			p = ft_lstlast(*lst);
			p->next = new;
		}
	}
	return ;
}

/*
#include "libft.h"
int main()
{
	t_list	*first = ft_lstnew("should be first");
	t_list	*second = ft_lstnew("should be second");
	t_list	*last = ft_lstnew("should be last");
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, last);
	for (; first; first = first->next) {
		printf("first->content = %s\n", (char *)first->content);
	}
}
*/
