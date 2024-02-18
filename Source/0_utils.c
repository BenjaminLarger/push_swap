/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:55:00 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 13:59:49 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	check_double_swap(t_list **x, t_list **y, char c)
{
	if (!(*y) || !(*y)->next)
		return (swap_x(x, c));
	if (c == 'a' && (*y)->data < (*y)->next->data)
		double_swap(x, y);
	else if (c == 'b' && (*y)->data > (*y)->next->data)
		double_swap(x, y);
	else
		swap_x(x, c);
}

void	get_prev_in_b(t_list **begin_b)
{
	t_list	*cur;
	t_list	*prev;

	cur = (*begin_b)->next;
	prev = *begin_b;
	while (cur)
	{
		cur->prev = prev;
		cur = cur->next;
		prev = prev->next;
	}
}
