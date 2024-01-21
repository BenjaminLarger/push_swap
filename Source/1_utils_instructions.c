/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:21:45 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 13:35:47 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	reverse_rotate_x(t_list **begin_list, char x)
{
	t_list	*last;
	t_list	*second_to_last;

	if (!begin_list || !(*begin_list) || (*begin_list)->next == NULL)
		return ;
	second_to_last = NULL;
	last = *begin_list;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last -> next;
	}
	if (second_to_last)
		second_to_last->next = NULL;
	last->next = *begin_list;
	(*begin_list)->prev = last;
	*begin_list = last;
	if (x != 'a' && x != 'b' && x != 'r')
		return ;
	ft_printf("rr%c\n", x);
}

void	double_reverse_rotate(t_list **begin_list_a, t_list **begin_list_b)
{
	reverse_rotate_x(begin_list_a, 'r');
	reverse_rotate_x(begin_list_b, 'x');
}

void	push_x_down_to_up(t_list **beg_x, t_list **beg_y, int ref, char x)
{
	t_list	*cur;
	char	y;

	cur = *beg_x;
	if (x == 'a')
		y = 'b';
	else if (x == 'b')
		y = 'a';
	while (cur != NULL)
	{
		if (cur->data == ref)
		{
			while ((*beg_x)->data != ref)
				rotate_x(beg_x, y);
			return (push_x_to_y(beg_x, beg_y, x));
		}
		cur = cur->next;
	}
	return (ft_free_list(beg_x), ft_free_list(beg_y), print_error());
}

void	push_x_up_to_down(t_list **beg_x, t_list **beg_y, int ref, char x)
{
	t_list	*cur;
	char	y;

	if (x == 'a')
		y = 'b';
	else if (x == 'b')
		y = 'a';
	cur = *beg_x;
	while (cur != NULL)
	{
		if (cur->data == ref)
		{
			while ((*beg_x)->data != ref)
				reverse_rotate_x(beg_x, y);
			return (push_x_to_y(beg_x, beg_y, x));
		}
		cur = cur->next;
	}
	return (ft_free_list(beg_x), ft_free_list(beg_y), print_error());
}

t_list	*last_node(t_list **begin_a)
{
	t_list	*cur;

	if (*begin_a == NULL)
		return (NULL);
	cur = *begin_a;
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}
