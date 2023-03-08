/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:32:32 by agallet           #+#    #+#             */
/*   Updated: 2023/01/20 14:33:03 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_list(t_list **source, char c)
{
	int		i;
	t_list	*temp1;
	t_list	*temp3;
	int		length;

	length = ft_lstsize(*source);
	i = 0;
	temp1 = ft_lstlast(*source);
	temp3 = *source;
	while (i < length - 2)
	{
		(*source) = (*source)->next;
		i++;
	}
	(*source)->next = NULL;
	ft_lstadd_back(&temp1, temp3);
	*source = temp1;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_lists(t_list **a, t_list **b)
{
	ft_putendl_fd("rrr", 1);
	reverse_rotate_list(&(*a), 'c');
	reverse_rotate_list(&(*b), 'c');
}
