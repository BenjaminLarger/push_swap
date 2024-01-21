/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_algo_for_big_dataset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:10:18 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 13:36:00 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	get_max_in_list(t_list **begin_a)
{
	int		max;
	t_list	*cur;

	cur = (*begin_a)->next;
	max = (*begin_a)->data;
	while (cur != NULL)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

void	put_a_to_b_by_chunk(t_list **a, t_list **b, int *stack_c, int size)
{
	int		cur_chunk;
	int		next_insertion;
	int		n;

	n = not_in_stack(stack_c, size);
	cur_chunk = 1;
	while (*a != NULL)
	{
		next_insertion = find_closest_in_chunk(a, stack_c, size, cur_chunk);
		if (next_insertion == n)
			cur_chunk++;
		else
			push_ref(a, b, next_insertion, 'b');
	}
}

void	order_b_to_a(t_list **beg_a, t_list **beg_b, int *stack_c, int size)
{
	push_ref(beg_b, beg_a, get_max(stack_c, size), 'a');
	while (*beg_b != NULL)
	{
		push_ref(beg_b, beg_a, get_max_in_list(beg_b), 'a');
	}
}

void	sort_big_dataset(t_list **begin_a, t_list **begin_b, int size_input)
{
	int	*stack_c;

	stack_c = create_stack_c(begin_a, size_input);
	if (!stack_c)
		return (ft_free_list(begin_a), ft_free_list(begin_b), print_error());
	quick_sort(stack_c, 0, size_input);
	put_a_to_b_by_chunk(begin_a, begin_b, stack_c, size_input);
	order_b_to_a(begin_a, begin_b, stack_c, size_input);
	free(stack_c);
}
