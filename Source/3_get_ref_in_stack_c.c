/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_get_ref_in_stack_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:04:59 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 14:01:11 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	get_max(int *stack_c, int input_size)
{
	int	i;
	int	max;

	max = stack_c[0];
	i = 0;
	while (i <= input_size)
	{
		if (stack_c[i] > max)
			max = stack_c[i];
		i++;
	}
	return (max);
}

int	get_min(int *stack_c, int input_size)
{
	int	i;
	int	min;

	min = stack_c[0];
	i = 0;
	while (i < input_size)
	{
		if (stack_c[i] < min)
			min = stack_c[i];
		i++;
	}
	return (min);
}

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	else
		return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
