/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:01:36 by agallet           #+#    #+#             */
/*   Updated: 2023/02/02 11:13:01 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_length(t_list *list, int *mv)
{
	int	length;

	length = ft_lstsize(list);
	if (length / 2 < *mv)
		*mv = length - *mv;
}

void	(*rr_o_r(t_list *list, int move))
(t_list **, char)
{
	int	length;

	length = ft_lstsize(list);
	if (move <= length / 2)
		return (&rotate_list);
	else
		return (&reverse_rotate_list);
}

int	verif_tri(t_list *list)
{
	while (list)
	{
		if (list->next)
		{
			if (*(int *)list->content > *(int *)list->next->content)
				return (0);
		}
		list = list->next;
	}
	return (1);
}

void	clear_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	table = NULL;
}

void	put_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *(int *)list->content);
		list = list->next;
	}
}
