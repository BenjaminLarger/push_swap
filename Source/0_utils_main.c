/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_utils_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:48:23 by blarger           #+#    #+#             */
/*   Updated: 2024/02/12 16:17:25 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	print_error(void)
{
	return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
}

int	ft_len_a(char *str)
{
	int	len;
	int	i;
	int	in_int;

	i = 0;
	len = 0;
	in_int = 0;
	while (str[i] != '\0')
	{
		if (((str[i] >= '0' && str[i] <= '9') || str[i] == '-') && in_int == 0)
		{
			len++;
			in_int = 1;
		}
		else if ((str[i] >= 9 && str[i] <= 13)
			|| (str[i] == ' ' && in_int == 1))
			in_int = 0;
		else if (in_int == 0 && !is_digit(str[i]))
			return (print_error(), -1);
		i++;
	}
	return (len);
}

int	get_next_index(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*read_from_input(void)
{
	char	*str;
	int		bytes_read;

	str = (char *)malloc(sizeof(char) * 1080);
	if (!str)
		return (print_error(), NULL);
	bytes_read = read(STDIN_FILENO, str, sizeof(char) * 1080);
	if (bytes_read == -1)
		return (free(str), print_error(), NULL);
	str[bytes_read - 1] = '\0';
	return (str);
}
