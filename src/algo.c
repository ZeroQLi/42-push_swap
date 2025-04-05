/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:22:22 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:14:14 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, int only)
{
	t_stack	*largest_node;

	largest_node = stack_max(*a);
	if (*a == largest_node)
		rotate_a(a, only);
	else if ((*a)->next == largest_node)
		reverse_rotate_a(a, only);
	if ((*a)-> num > (*a)->next->num)
		swap_a(a, only);
}

static void	min_top(t_stack **stk)
{
	while ((*stk)->num != stack_min(*stk)->num)
	{
		if (stack_min(*stk)->above_median == 1)
			rotate_a(stk, 1);
		else
			reverse_rotate_a(stk, 1);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(b, a, 1);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(b, a, 1);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a, 1);
	while (*b)
	{
		init_b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_median(*a);
	min_top(a);
}
