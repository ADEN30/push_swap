/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:26:14 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:45:07 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions(t_list **a, void (*f)
(t_list**, char), int nb, char c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_lstsize(*a);
	while (i < nb)
	{
		f(&(*a), c);
		i++;
	}
}

void	action_f(t_list **a, t_list **b, int nba, int nbb)
{
	void	(*f)(t_list **, char);

	f = rr_o_r(*a, nba);
	choice_length(*a, &nba);
	actions(&(*a), f, nba, 'a');
	if (ft_lstsize(*b) < 1)
		push_list(&(*a), &(*b), 'b');
	f = rr_o_r(*b, nbb);
	choice_length(*b, &nbb);
	actions(&(*b), f, nbb, 'b');
}

void	action_master(t_list **a, t_list **b, int nb_a, int nb_b)
{
	int	length_a;
	int	length_b;

	length_b = ft_lstsize(*b);
	length_a = ft_lstsize(*a);
	if (check_lists(length_a, length_b, nb_a, nb_b))
		action_ff(&(*a), &(*b), nb_a, nb_b);
	else
		action_f(&(*a), &(*b), nb_a, nb_b);
	push_list(&(*a), &(*b), 'b');
}
