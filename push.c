/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:28:17 by agallet           #+#    #+#             */
/*   Updated: 2023/01/20 14:28:56 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_list(t_list **source, t_list **depots, char c)
{
	t_list	*temp;

	temp = NULL;
	if (*source)
	{
		temp = (*source);
		*source = (*source)->next;
		ft_lstadd_front(&(*depots), temp);
	}
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else
		ft_putendl_fd("pb", 1);
}
