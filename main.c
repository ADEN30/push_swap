/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:25:57 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:42:32 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_tablen(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

long	*check_arg(int argv, char **argc)
{
	long	*tab;
	int		length;
	int		i;
	char	**str;

	str = NULL;
	i = 0;
	length = 0;
	if (argv == 2)
	{
		str = ft_split(argc[1], ' ');
		length = ft_tablen(str);
		tab = malloc(sizeof(long) * (length));
		clear_table(str);
	}
	else
		tab = malloc(sizeof(long) * (argv));
	return (tab);
}

void	clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

int	main(int argv, char **argc)
{
	t_list	*a;
	t_list	*b;
	long	*nb;

	a = NULL;
	b = NULL;
	nb = NULL;
	if (argv > 1)
	{
		nb = check_arg(argv, argc);
		a = inputs(argc, nb);
		if (ft_lstsize(a) < 6 && a)
			little_lists(&a, &b);
		else if (a && !verif_tri(a))
			sort(&a, &b);
		else if (!a)
			ft_putendl_fd("Error", 2);
	}
	if (nb)
		free(nb);
	clear_list(&a);
	return (0);
}
