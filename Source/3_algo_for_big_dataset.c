/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_algo_for_big_dataset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:10:18 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 14:09:41 by blarger          ###   ########.fr       */
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

int	size_list(t_list **a, int *c, int size)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = *a;
	while (cur)
	{
		if (cur->data != c[size - 1] && cur->data != c[size - 2]
			&& cur->data != c[size - 3])
			return (0);
		i++;
		cur = cur->next;
	}
	if (i == 3)
		return (i);
	return (0);
}

void	put_a_to_b_by_chunk(t_list **a, t_list **b, int *stack_c, int size)
{
	int		cur_chunk;
	int		next_insertion;
	int		n;

	n = not_in_stack(stack_c, size);
	cur_chunk = 1;
	while (!size_list(a, stack_c, size))
	{
		next_insertion = find_closest_in_chunk(a, stack_c, size, cur_chunk);
		if (next_insertion == n)
		{
			cur_chunk++;
		}
		if (next_insertion != n && next_insertion != stack_c[size - 1]
			&& next_insertion != stack_c[size - 2]
			&& next_insertion != stack_c[size - 3])
			push_ref(a, b, next_insertion, 'b');
	}
	sort_three(a, b);
}

void	order_b_to_a(t_list **beg_a, t_list **beg_b, int *stack_c, t_list *list)
{
	int		i;
	int		next_insertion;

	i = 0;
	while (i < list->size - 3)
	{
		while (1)
		{
			next_insertion = push_three_next_max_in_b(beg_b, stack_c, i, list);
			if (next_insertion == not_in_stack(stack_c, list->size))
				break ;
			push_ref(beg_b, beg_a, next_insertion, 'a');
		}
		if (!is_sorted(beg_a))
			sort_three_big_algo(beg_a, beg_b);
		i = i + 3;
	}
	if (list->size - i > 2)
		push_ref(beg_b, beg_a, stack_c[2], 'a');
	if (list->size - i > 1)
		push_ref(beg_b, beg_a, stack_c[1], 'a');
	push_ref(beg_b, beg_a, stack_c[0], 'a');
}

void	sort_big_dataset(t_list **begin_a, t_list **begin_b, int size_input)
{
	int		*stack_c;
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (free(list), ft_free_list(begin_a),
			ft_free_list(begin_b), print_error());
	list->size = size_input;
	stack_c = create_stack_c(begin_a, size_input);
	if (!stack_c)
		return (ft_free_list(begin_a), ft_free_list(begin_b), print_error());
	quick_sort(stack_c, 0, size_input);
	put_a_to_b_by_chunk(begin_a, begin_b, stack_c, size_input);
	get_prev_in_b(begin_b);
	order_b_to_a(begin_a, begin_b, stack_c, list);
	free(stack_c);
	free(list);
}
