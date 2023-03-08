/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:08:01 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:45:17 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lists(int length_a, int length_b, int nb_a, int nb_b)
{
	if ((length_a / 2 <= nb_a && length_b / 2 <= nb_b
			&& length_a > 2 && length_b > 2)
		|| (length_a / 2 >= nb_a && length_b / 2 >= nb_b
			&& nb_a != 0 && nb_b != 0))
		return (1);
	else
		return (0);
}

void	actionss(t_list **a, t_list **b, void (*f)
(t_list**, t_list **), int nb)
{
	int	i;
	int	length;

	i = 0;
	length = ft_lstsize(*a);
	while (i < nb)
	{
		f(&(*a), &(*b));
		i++;
	}
}

int	move_lists(int *nba, int *nbb)
{
	int	nb_a;
	int	nb_b;

	nb_a = *nba;
	nb_b = *nbb;
	if (*nba < *nbb)
	{
		*nbb = *nbb - *nba;
		*nba = 0;
		return (nb_a);
	}
	else if (*nbb < *nba)
	{
		*nba = *nba - *nbb;
		*nbb = 0;
		return (nb_b);
	}
	else
	{
		*nba = 0;
		*nbb = 0;
		return (nb_a);
	}
}

void	move_ff(t_list **a, t_list **b, int *nb_a, int *nb_b)
{
	int	length_a;
	int	length_b;

	length_a = ft_lstsize(*a);
	length_b = ft_lstsize(*b);
	if (length_a / 2 <= *nb_a && length_b / 2 <= *nb_b)
	{
		*nb_a = length_a - *nb_a;
		*nb_b = length_b - *nb_b;
	}
}

void	action_ff(t_list **a, t_list **b, int nb_a, int nb_b)
{
	int		length_a;
	int		length_b;
	void	(*f)(t_list **, char);
	void	(*ff)(t_list **, t_list **);

	length_b = ft_lstsize(*b);
	length_a = ft_lstsize(*a);
	if (length_a / 2 >= nb_a && length_b / 2 >= nb_b)
	{
		ff = &rotate_lists;
		f = &rotate_list;
	}
	else
	{
		move_ff(&(*a), &(*b), &nb_a, &nb_b);
		ff = &reverse_rotate_lists;
		f = &reverse_rotate_list;
	}
	actionss(&(*a), &(*b), ff, move_lists(&nb_a, &nb_b));
	actions(&(*a), f, nb_a, 'a');
	actions(&(*b), f, nb_b, 'b');
}
