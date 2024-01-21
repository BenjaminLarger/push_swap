/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_utils_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:33:14 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 11:46:34 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	push_ref(t_list **begin_a, t_list **begin_b, int ref, char x)
{
	t_list	*cur_a;

	cur_a = *begin_a;
	while (cur_a != NULL)
	{
		if (cur_a->data == ref)
		{
			if (optimal_way(begin_a, &cur_a) == 1)
				return (push_x_up_to_down(begin_a, begin_b, cur_a->data, x));
			else
				return (push_x_down_to_up(begin_a, begin_b, cur_a->data, x));
		}
		cur_a = cur_a->next;
	}
}

int	not_in_stack(int *stack_c, int size)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	while (i < size)
	{
		if (n == stack_c[i])
		{
			n--;
			i = 0;
		}
		else
			i++;
	}
	return (n);
}

int	find_closest_in_chunk(t_list **a, int *c, int size, int chunk)
{
	t_list	*forw;
	t_list	*back;
	int		cost_forw;
	int		cost_back;

	cost_forw = 0;
	cost_back = 1;
	forw = *a;
	while (forw != NULL && !belong_to_chunk(chunk, size, c, forw->data))
	{
		cost_forw++;
		forw = forw->next;
	}
	if (forw == NULL)
		return (not_in_stack(c, size));
	back = last_node(a);
	while (back && back != *a && !belong_to_chunk(chunk, size, c, back->data))
	{
		cost_back++;
		back = back->prev;
	}
	if (cost_forw < cost_back)
		return (forw->data);
	return (back->data);
}

int	belong_to_chunk(int cur_chunk, int size, int *stack_c, int ref)
{
	int	start;
	int	end;
	int	n_chunk;

	if (size <= 50)
		n_chunk = size / 2;
	else if (size <= 100)
		n_chunk = 5;
	else
		n_chunk = 12;
	end = (size / n_chunk) * cur_chunk;
	start = end - (size / n_chunk);
	end--;
	while (start <= end)
	{
		if (stack_c[start] == ref)
			return (1);
		start++;
	}
	return (0);
}
