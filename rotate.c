/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:33:18 by agallet           #+#    #+#             */
/*   Updated: 2023/01/20 14:33:20 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_list **source, char c)
{
	t_list	*temp;

	temp = (*source)->next;
	(*source)->next = NULL;
	ft_lstadd_back(&temp,*source);
	*source = temp;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
}

void	rotate_lists(t_list **a, t_list **b)
{
	ft_putendl_fd("rr", 1);
	rotate_list(&(*a), 'c');
	rotate_list(&(*b), 'c');
}
