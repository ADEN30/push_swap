/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:39:26 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:48:01 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_end(t_list **list, char c)
{
	int	front;
	int	middle;
	int	length;

	length = ft_lstsize(*list);
	while (!verif_tri(*list))
	{
		front = *(int *)(*list)->content;
		if ((*list)->next)
		{
			middle = *(int *)(*list)->next->content;
			if (front == search_max(*list) && c == 'a')
				rotate_list(&(*list), c);
			else if (front > middle && c == 'a')
				swap_list(&(*list), 'a');
			else if (middle == search_max(*list) && c == 'a')
				reverse_rotate_list(&(*list), c);
			else
				break ;
		}	
	}	
}

int	addition_move(t_list *a, t_list *b, int move_1, int move_2)
{
	int	length_a;
	int	length_b;
	int	move;

	length_b = ft_lstsize(b);
	length_a = ft_lstsize(a);
	move = 0;
	if (check_lists(length_a, length_b, move_1, move_2))
	{
		choice_length(a, &move_1);
		choice_length(b, &move_2);
		if (move_1 < move_2)
			move = move_1 + (move_2 - move_1);
		else if (move_2 < move_1)
			move = move_2 + (move_1 - move_2);
		else
			move = move_1;
	}
	else
	{
		choice_length(a, &move_1);
		choice_length(b, &move_2);
		move = move_1 + move_2;
	}
	return (move);
}

void	sort_master(t_list **a, t_list **b)
{
	t_list	*temp;
	int		move_a;
	int		move_b;
	int		i;

	temp = *a;
	move_a = 0;
	move_b = inter_b((*b), temp);
	i = 0;
	while (temp)
	{
		if (*b && addition_move(*a, *b, move_a, move_b)
			> addition_move(*a, *b, i, inter_b((*b), temp)))
		{
			move_a = i;
			move_b = inter_b((*b), temp);
		}
		temp = temp->next;
		i++;
	}
	action_master(&(*a), &(*b), move_a, move_b);
}

void	little_lists(t_list **a, t_list **b)
{
	int		min;
	int		length;
	void	(*f)(t_list **, char);
	int		i;

	i = 0;
	sort_end(&(*a), 'a');
	if (!verif_tri(*a))
	{
		while (i < 2)
		{
			min = search_min(*a);
			length = search_distance(&(*a), min);
			f = rr_o_r(*a, length);
			choice_length(*a, &length);
			actions(&(*a), f, length, 'a');
			push_list(&(*a), &(*b), 'b');
			i++;
		}
		sort_end(&(*a), 'a');
		while (*b)
			push_list(&(*b), &(*a), 'a');
	}
}

void	sort(t_list **a, t_list **b)
{
	int		i;
	int		length;
	void	(*f)(t_list **, char);

	i = 0;
	length = ft_lstsize(*a);
	while (*a)
		sort_master(&(*a), &(*b));
	length = search_distance(&(*b), search_max(*b));
	f = rr_o_r(*b, length);
	choice_length(*b, &length);
	actions(&(*b), f, length, 'b');
	length = ft_lstsize(*b);
	while (i < length)
	{
		push_list(&(*b), &(*a), 'a');
		i++;
	}
}
