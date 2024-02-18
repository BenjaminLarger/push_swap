/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils_instructions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:43:07 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 13:56:42 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	optimal_way(t_list **begin, t_list **to_find)
{
	int		start_to_find;
	int		end_to_find;
	t_list	*cur;

	cur = *begin;
	start_to_find = 0;
	while (cur != *to_find && cur != NULL)
	{
		start_to_find++;
		cur = cur->next;
	}
	if (cur != *to_find)
		return (free(begin), print_error(), -1);
	end_to_find = 1;
	while (cur != NULL)
	{
		end_to_find++;
		cur = cur->next;
	}
	if (end_to_find < start_to_find)
		return (1);
	else
		return (2);
}

int	is_max(t_list **begin_a, int ref, int n)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = *begin_a;
	while (i < n)
	{
		if (cur->data > ref)
			return (0);
		cur = cur -> next;
		i++;
	}
	return (1);
}

int	is_min(t_list **begin_a, int ref, int n)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = *begin_a;
	while (cur != NULL && i < n)
	{
		if (cur->data < ref)
		{
			return (0);
		}
		cur = cur -> next;
		i++;
	}
	return (1);
}

int	is_sorted(t_list **begin_a)
{
	t_list	*cur;

	cur = *begin_a;
	if (cur == NULL || cur->next == NULL)
		return (1);
	while (cur->next != NULL)
	{
		if (cur->data > cur->next->data)
		{
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

void	insert_min_at_top_b(t_list **begin_a, t_list **begin_b, int n)
{
	t_list	*cur_a;

	cur_a = *begin_a;
	while (cur_a != NULL)
	{
		if (is_min(begin_a, cur_a->data, n) == 1)
		{
			if (optimal_way(begin_a, &cur_a) == 1)
				return (push_x_up_to_down(begin_a, begin_b, cur_a->data, 'b'));
			else
				return (push_x_down_to_up(begin_a, begin_b, cur_a->data, 'b'));
		}
		cur_a = cur_a->next;
	}
}
