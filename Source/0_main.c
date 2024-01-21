/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:14:34 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 18:26:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

static int	go_to_function(int *input_arr, int input_size)
{
	t_list	*a;
	t_list	*b;
	t_list	*print;

	a = ft_create_list(input_arr, input_size);
	b = NULL;
	if (is_sorted(&a))
		return (free(input_arr), ft_free_list(&a), 0);
	else if (input_size == 2)
		return (rotate_x(&a, 'a'), free(input_arr), ft_free_list(&a), 0);
	else if (input_size <= 5)
		sort_small_dataset(&a, &b, input_size);
	else
		sort_big_dataset(&a, &b, input_size);
	print = a;
	return (free(input_arr), ft_free_list(&a), ft_free_list(&b), 0);
}

static int	get_int_array(char *str)
{
	int	i;
	int	j;
	int	*a;

	if (!str || str[0] == '\0')
		return (print_error(), -1);
	i = 0;
	j = 0;
	a = (int *)malloc(sizeof(int) * ((ft_len_a(str)) + 1));
	if (!a)
		return (print_error(), -1);
	while (j < ft_len_a(str))
	{
		a[j] = ft_atoi_check(&str[i], a);
		i = i + get_next_index(a[j]) + 1;
		j++;
	}
	if (no_double(a, j) == -1 || j < 2)
		return (free(a), print_error(), -1);
	return (go_to_function(a, j));
}

static int	get_int_array_free_str(char *str)
{
	int	i;
	int	j;
	int	*a;

	if (!str || str[0] == '\0')
		return (print_error(), -1);
	i = 0;
	j = 0;
	a = (int *)malloc(sizeof(int) * ((ft_len_a(str)) + 1));
	if (!a)
		return (print_error(), -1);
	while (j < ft_len_a(str))
	{
		a[j] = ft_atoi_check(&str[i], a);
		i = i + get_next_index(a[j]) + 1;
		j++;
	}
	if (no_double(a, j) == -1)
		return (free(a), free(str), print_error(), -1);
	return (free(str), go_to_function(a, j));
}

int	main(int argc, char **argv)
{
	int	i;
	int	*a;

	i = 0;
	if (argc == 1)
		return (get_int_array_free_str(read_from_input()));
	else if (argc == 2)
		return (get_int_array(argv[1]));
	else
	{
		a = (int *)malloc(sizeof(int) * argc);
		if (!a)
			return (print_error(), -1);
		while (i < argc - 1)
		{
			a[i] = ft_atoi_check_when_inputs(argv[i + 1], a);
			i++;
		}
		if (no_double(a, i) == -1 || i < 2)
			return (free(a), print_error(), -1);
		return (go_to_function(a, i));
	}
}
