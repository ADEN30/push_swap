/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:01:22 by agallet           #+#    #+#             */
/*   Updated: 2023/02/02 10:52:11 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max(t_list *list)
{
	t_list	*mini;
	int		i;

	i = 0;
	mini = list;
	while (list)
	{
		if (*(int *)mini->content < *(int *)(list)->content)
		{
			mini = list;
			i++;
		}
		(list) = (list)->next;
	}
	return (*(int *)mini->content);
}

int	search_min(t_list *list)
{
	t_list	*mini;
	int		i;

	i = 0;
	mini = list;
	while (list)
	{
		if (*(int *)mini->content > *(int *)(list)->content)
		{
			mini = list;
			i++;
		}
		(list) = (list)->next;
	}
	return (*(int *)mini->content);
}

int	search_distance(t_list **list, int nb)
{
	int		i;
	int		length;
	t_list	*temp;

	i = 0;
	length = ft_lstsize(*list);
	temp = *list;
	while (temp)
	{
		if (*(int *)(temp)->content == nb)
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}

int	not_inter(t_list **temp, int fleche)
{
	if (*temp)
	{
		if (fleche > search_max(*temp))
			return (search_distance(&(*temp), search_max(*temp)));
		else if (fleche < search_min(*temp))
			return (search_distance(&(*temp), search_min(*temp)) + 1);
	}
	return (0);
}

int	inter_b(t_list *b, t_list *nb)
{
	int		fleche;
	int		cible;
	t_list	*temp;

	fleche = 0;
	cible = 0;
	temp = b;
	while (b)
	{
		if (nb)
			fleche = *(int *)nb->content;
		cible = *(int *)(b)->content;
		if ((b)->next)
		{
			if (fleche < cible
				&& fleche > *(int *)(b)->next->content)
				return (search_distance(&temp, cible) + 1);
		}
		b = (b)->next;
	}
	return (not_inter(&temp, fleche));
}
