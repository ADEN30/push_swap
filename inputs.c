/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:25:06 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:33:43 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	duplicate(long *tab, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length)
	{
		while (j < length)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static	char	**parse_inputs(char	*str)
{
	char	**table;

	table = NULL;
	table = ft_split(str, ' ');
	if (!*table)
		return (NULL);
	return (table);
}

static	int	add_pile(t_list **pile, char **table, long *nb)
{
	int			i;
	static int	j;
	t_list		*new;
	int			stop;

	i = 0;
	new = NULL;
	stop = 1;
	if (!table)
		return (0);
	while (table[i] && stop)
	{	
		(nb)[j] = ft_atoi(table[i]);
		if (nb[j] > 2147483647 || nb[j] < -2147483648)
			stop = 0;
		new = ft_lstnew(&((nb)[j]));
		ft_lstadd_back(&(*pile), new);
		i++;
		j++;
	}
	if (table)
		clear_table(table);
	if (duplicate(nb, j) || !stop)
		return (0);
	return (1);
}

static	int	errors(char **str)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			c = str[i][j];
			if ((c == '-' || c == '+')
				&& (str[i][j + 1] < '0' || str[i][j + 1] > '9'))
				return (-1);
			else if (c != '-' && (c < '0' || c > '9') && c != ' ')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_list	*inputs(char **str, long *nb)
{
	t_list	*pile;
	int		i;
	int		error;

	i = 1;
	pile = NULL;
	error = 1;
	if (errors(str) != -1)
	{
		while (str[i])
		{
			error = add_pile(&pile, parse_inputs(str[i]), nb);
			if (!error)
			{
				clear_list(&pile);
				return (NULL);
			}
			i++;
		}
	}
	return (pile);
}
