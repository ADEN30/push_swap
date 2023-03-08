/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:19:56 by agallet           #+#    #+#             */
/*   Updated: 2023/02/03 13:47:40 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	clear_list(t_list **list);
int		ft_tablen(char **str);

void	swap_list(t_list **a, char c);
void	swap_ab(t_list **a, t_list **b);
void	push_list(t_list **source, t_list **depots, char c);
void	rotate_list(t_list **source, char c);
void	rotate_lists(t_list **a, t_list **b);
void	reverse_rotate_list(t_list **source, char c);
void	reverse_rotate_lists(t_list **a, t_list **b);
void	put_list(t_list *list);

t_list	*inputs(char **str, long *nb);
void	parse_pile(t_list **a, t_list **b);

int		search_distance(t_list **list, int nb);
int		search_max(t_list *list);
int		search_min(t_list *list);
int		not_inter(t_list **temp, int fleche);
int		inter_b(t_list *b, t_list *nb);

void	choice_length(t_list *list, int *mv);
void	(*rr_o_r(t_list *list, int move))(t_list **, char);
int		verif_tri(t_list *a);
void	clear_table(char **table);

int		check_lists(int length_a, int length_b, int nb_a, int nb_b);
void	actionss(t_list **a, t_list **b, void (*f)
			(t_list **, t_list **), int nb);
int		move_lists(int *nba, int *nbb);
void	move_ff(t_list **a, t_list **b, int *nb_a, int *nb_b);
void	action_ff(t_list **a, t_list **b, int nb_a, int nb_b);

void	actions(t_list **a, void (*f)(t_list **, char), int nb, char c);
void	action_f(t_list **a, t_list **b, int nba, int nbb);
void	action_master(t_list **a, t_list **b, int nb_a, int nb_b);

void	sort_master(t_list **a, t_list **b);
void	little_lists(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);
#endif
