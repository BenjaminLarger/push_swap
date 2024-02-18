/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_algo_for_small_dataset.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:44:10 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 16:12:32 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	sort_small_dataset(t_list **beg_a, t_list **beg_b, int input_size)
{
	if (input_size == 3)
		sort_three(beg_a, beg_b);
	else
		sort_four_or_five(beg_a, beg_b, input_size);
}

void	sort_three(t_list **beg_a, t_list **beg_b)
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
		if (is_sorted(beg_a) != 1)
			check_double_swap(beg_a, beg_b, 'a');
	}
	else
	{
		if (is_max(beg_a, (*beg_a)->next->data, 3))
			reverse_rotate_x(beg_a, 'a');
		else
			check_double_swap(beg_a, beg_b, 'a');
	}
}

void	sort_four_or_five(t_list **beg_a, t_list **beg_b, int input_size)
{
	insert_min_at_top_b(beg_a, beg_b, input_size);
	if (input_size == 5)
		insert_min_at_top_b(beg_a, beg_b, 4);
	if (!is_sorted(beg_a))
		sort_three(beg_a, beg_b);
	push_x_to_y(beg_b, beg_a, 'a');
	if (input_size == 5)
		push_x_to_y(beg_b, beg_a, 'a');
}
