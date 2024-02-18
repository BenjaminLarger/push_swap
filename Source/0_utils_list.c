/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_utils_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:49:55 by blarger           #+#    #+#             */
/*   Updated: 2024/02/11 16:44:42 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	ft_free_list(t_list **cur)
{
	t_list	*tmp;

	while (*cur != NULL)
	{
		tmp = *cur;
		*cur = (*cur)->next;
		free(tmp);
	}
}

int	no_double(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size < 2)
		return (0);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

t_list	*create_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*ft_create_list(int	*a, int size)
{
	t_list	*head;
	t_list	*prev;
	t_list	*cur;
	int		i;

	prev = NULL;
	head = NULL;
	i = 0;
	while (i < size)
	{
		cur = create_node(a[i]);
		if (!cur)
			return (free(a), NULL);
		if (prev)
		{
			prev->next = cur;
			cur->prev = prev;
		}
		else
			head = cur;
		prev = cur;
		i++;
	}
	return (head);
}

int	belong_to_a(t_list **begin_a, int ref)
{
	t_list	*cur;

	cur = *begin_a;
	while (cur != NULL)
	{
		if (cur->data == ref)
			return (1);
		cur = cur->next;
	}
	return (0);
}
