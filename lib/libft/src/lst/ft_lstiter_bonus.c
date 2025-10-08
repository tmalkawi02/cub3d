/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:38:24 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:20 by amaryllis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void	iter(void *str)
{
	char	*temp;

	temp = (char *)str;
	temp = "haha got you";
}
*/

/*
#include "libft.h"
int main()
{
	t_list	*first = ft_lstnew("should be first");
	t_list	*second = ft_lstnew("should be second");
	t_list	*last = ft_lstnew("should be last");
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, last);
	ft_lstiter(first, &iter);
	for (; first; first = first->next) {
		printf("first->content = %s\n", (char *)first->content);
	}
}
*/
