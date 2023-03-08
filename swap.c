/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:33:26 by agallet           #+#    #+#             */
/*   Updated: 2023/01/23 13:56:56 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list **a, char c)
{
	t_list	*temp1;

	temp1 = NULL;
	if (*a && (*a)->next)
	{
		temp1 = (*a)->next;
		(*a)->next = temp1->next;
		temp1->next = *a;
		*a = temp1;
		if (c == 'a')
			ft_putendl_fd("sa", 1);
		else if (c == 'b')
			ft_putendl_fd("sb", 1);
	}
}

void	swap_ab(t_list **a, t_list **b)
{
	ft_putendl_fd("ss", 1);
	swap_list(&(*a), 'a');
	swap_list(&(*b), 'b');
}
