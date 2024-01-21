/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:01:35 by blarger           #+#    #+#             */
/*   Updated: 2024/01/20 18:44:51 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	get_sign(const char *str, int *sign, int i)
{
	if ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1]))
	{
		if (str[i] == '-')
			*sign = -*sign;
		i++;
	}
	return (i);
}

int	ft_atoi_check_when_inputs(char *str, int *a)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	i = get_sign(&str[i], &sign, i);
	while (is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result > ((long long int)INT_MAX + 1) && sign == -1)
			return (free(a), print_error(), -1);
		if (result > INT_MAX && sign == 1)
			return (free(a), print_error(), -1);
	}
	if (str[i] != '\0')
		return (free(a), print_error(), -1);
	return (sign * result);
}

int	ft_atoi_check(const char *str, int *a)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	i = get_sign(&str[i], &sign, i);
	while (is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result > ((long long int)INT_MAX + 1) && sign == -1)
			return (free(a), print_error(), -1);
		if (result > INT_MAX && sign == 1)
			return (free(a), print_error(), -1);
	}
	if (!is_whitespace(str[i]) && str[i] != '\0')
		return (free(a), print_error(), -1);
	return (sign * result);
}
/* static int	ft_atoi_check_when_inputs(const char *str, int *a)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if (result < 0)
			return (free(a), print_error(), -1);
		i++;
	}
	if (str[i] != '\0')
		return (free(a), print_error(), -1);
	return (sign * result);
} */
