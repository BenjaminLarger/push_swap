/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:36:57 by blarger           #+#    #+#             */
/*   Updated: 2024/01/21 17:03:08 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Ft_libft/libft.h"
# include "../Ft_printf/ft_printf.h"

//0_utils_main.c
char		*read_from_input(void);
int			get_next_index(int n);
int			ft_len_a(char *str);
void		print_error(void);
int			ft_atoi_check(const char *str, int *a);

	//list
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				index;
}					t_list;

//0_atoi.c
int			ft_atoi_check_when_inputs(char *str, int *a);
int			get_sign(const char *str, int *sign, int i);
int			ft_atoi_check(const char *str, int *a);

//0_utils_list.c
t_list		*ft_create_list(int	*a, int size);
void		ft_free_list(t_list **cur);
int			no_double(int *a, int size);
int			belong_to_a(t_list **begin_a, int ref);

//1_instructions.c
void		swap_x(t_list **begin_list, char x);
void		double_swap(t_list **begin_a, t_list **begin_b);
void		push_x_to_y(t_list **begin_x, t_list **begin_y, char x);
void		rotate_x(t_list	**begin_list, char x);
void		double_rotate(t_list **begin_a, t_list **begin_b);

//1_utils_instructions.c
void		reverse_rotate_x(t_list **begin_list, char x);
void		double_reverse_rotate(t_list **begin_a, t_list **begin_b);
t_list		*last_node(t_list **begin_a);
void		push_x_down_to_up(t_list **bx, t_list **y, int ref, char x);
void		push_x_up_to_down(t_list **bx, t_list **y, int ref, char x);

//1_utils_instructions2.c
int			is_max(t_list **begin_a, int ref);
int			is_min(t_list **begin_a, int ref);
int			is_sorted(t_list **begin_a);
void		insert_min_at_top_b(t_list **begin_a, t_list **begin_b);
int			optimal_way(t_list **begin, t_list **to_find);

//2_añgo_for_small_dataset.c
void		sort_small_dataset(t_list **a, t_list **b, int input_size);
void		sort_three(t_list **beg_a, t_list **beg_b);
void		sort_four_or_five(t_list **a, t_list **b, int input_size);

//3_algo_for_big_dataset.c
void		sort_big_dataset(t_list **a, t_list **b, int size_input);
void		put_a_to_b_by_chunk(t_list **a, t_list **b, int *c, int size);
void		order_b_to_a(t_list **a, t_list **b, int *stack_c, int size);

//3_quick_sort_stack.c
int			*create_stack_c(t_list **begin_a, int input_size);
void		swap(int *a, int *b);
void		quick_sort(int *array, int start, int end);

//3_get_ref_in_stack_c
int			get_max(int *stack_c, int input_size);
int			get_min(int *stack_c, int input_size);
int			is_whitespace(char c);
int			is_digit(char c);

//3_utils_chunk.c
void		push_ref(t_list **begin_a, t_list **begin_b, int ref, char x);
int			not_in_stack(int *stack_c, int size);
int			find_closest_in_chunk(t_list **a, int *c, int size, int chunk);
int			belong_to_chunk(int cur_chunk, int size, int *stack_c, int ref);
void		print_list(t_list **a, char x);
void		print_reverse_list(t_list **a, char x);

#endif