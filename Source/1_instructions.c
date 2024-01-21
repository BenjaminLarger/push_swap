/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:29 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 11:46:15 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	swap_x(t_list **begin_list, char x)
{
	t_list	*sec;
	int		temp;

	sec = (*begin_list)->next;
	temp = (*begin_list)->data;
	(*begin_list)->data = sec->data;
	sec->data = temp;
	if (x != 'a' && x != 'b' && x != 's')
		return ;
	ft_printf("s%c\n", x);
}

void	double_swap(t_list **begin_a, t_list **begin_b)
{
	swap_x(begin_a, 's');
	swap_x(begin_b, 'x');
}

void	push_x_to_y(t_list **begin_x, t_list **begin_y, char x)
{
	t_list	*top_x;

	if (!begin_x || !*begin_x)
		return ;
	top_x = *begin_x;
	*begin_x = (*begin_x)->next;
	if (*begin_x)
		(*begin_x)->prev = NULL;
	top_x->next = *begin_y;
	top_x->prev = NULL;
	*begin_y = top_x;
	ft_printf("p%c\n", x);
}

void	rotate_x(t_list	**begin_list, char x)
{
	t_list	*temp;
	t_list	*cur;

	if (!begin_list || !(*begin_list) || !(*begin_list)->next)
		return ;
	temp = *begin_list;
	*begin_list = (*begin_list)->next;
	(*begin_list)->prev = NULL;
	temp->next = NULL;
	cur = *begin_list;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = temp;
	temp->prev = cur;
	if (x != 'a' && x != 'b' && x != 'r')
		return ;
	ft_printf("r%c\n", x);
}

void	double_rotate(t_list **begin_a, t_list **begin_b)
{
	rotate_x(begin_a, 'r');
	rotate_x(begin_b, 'x');
}
