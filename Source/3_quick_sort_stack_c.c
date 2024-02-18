/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_quick_sort_stack_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:28 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 14:15:40 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	*create_stack_c(t_list **begin_a, int input_size)
{
	t_list	*cur_a;
	int		i;
	int		*stack_c;

	stack_c = (int *)malloc(sizeof(int) * (input_size));
	if (!stack_c)
		return (NULL);
	i = 0;
	cur_a = *begin_a;
	while (cur_a != NULL)
	{
		stack_c[i] = cur_a->data;
		cur_a = cur_a->next;
		i++;
	}
	return (stack_c);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[start];
	i = end + 1;
	j = end;
	while (j > start)
	{
		if (array[j] > pivot)
		{
			i--;
			swap(&array[i], &array[j]);
		}
		j--;
	}
	swap(&array[i - 1], &array[j]);
	return (i - 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end - 1);
		quick_sort(array, start, pivot_index);
		quick_sort(array, pivot_index + 1, end);
	}
}
