/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_push_b_to_a_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:24:13 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 14:15:19 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	push_three_next_max_in_b(t_list **b, int *stack_c, int n_ref, t_list *list)
{
	list->ref_a = stack_c[list->size - n_ref - 1];
	list->ref_b = stack_c[list->size - n_ref - 2];
	list->ref_c = stack_c[list->size - n_ref - 3];
	return (find_closest_of_three_ref(stack_c, b, list));
	return (0);
}

int	find_closest_of_three_ref(int *stack_c, t_list **beg_b, t_list *list)
{
	t_list	*forw;
	t_list	*back;
	int		cost_forw;
	int		cost_back;

	cost_forw = 0;
	cost_back = 1;
	forw = *beg_b;
	while (forw != NULL && !three_next_max(forw->data, list))
	{
		cost_forw++;
		forw = forw->next;
	}
	if (forw == NULL)
		return (not_in_stack(stack_c, list->size));
	back = last_node(beg_b);
	while (back && back != *beg_b && !three_next_max(back->data, list))
	{
		cost_back++;
		back = back->prev;
	}
	if (cost_forw < cost_back)
		return (forw->data);
	return (back->data);
}

int	three_next_max(int ref, t_list *list)
{
	if (ref != list->ref_a && ref != list->ref_b
		&& list->ref_c != ref)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	sort_three_big_algo(t_list **beg_a, t_list **beg_b)
{
	t_list	*cur_b;

	cur_b = *beg_b;
	if (is_min(beg_a, (*beg_a)->data, 3))
	{
		push_x_to_y(beg_a, beg_b, 'b');
		check_double_swap(beg_a, beg_b, 'a');
		push_x_to_y(beg_b, beg_a, 'a');
	}
	else if (is_max(beg_a, (*beg_a)->data, 3))
	{
		rotate_x(beg_a, 'a');
		if ((*beg_a)->data > (*beg_a)->next->data)
			check_double_swap(beg_a, beg_b, 'a');
		push_x_to_y(beg_a, beg_b, 'b');
		push_x_to_y(beg_a, beg_b, 'b');
		reverse_rotate_x(beg_a, 'a');
		push_x_to_y(beg_b, beg_a, 'a');
		push_x_to_y(beg_b, beg_a, 'a');
	}
	else
	{
		sort_when_max_at_middle(beg_a, beg_b);
	}
}

void	sort_when_max_at_middle(t_list **beg_a, t_list **beg_b)
{
	t_list	*cur_b;

	cur_b = *beg_b;
	if (is_max(beg_a, (*beg_a)->next->data, 3))
	{
		push_x_to_y(beg_a, beg_b, 'b');
		check_double_swap(beg_a, beg_b, 'a');
		push_x_to_y(beg_b, beg_a, 'a');
		check_double_swap(beg_a, beg_b, 'a');
	}
	else
		check_double_swap(beg_a, beg_b, 'a');
}
