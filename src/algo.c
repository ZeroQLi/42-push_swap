/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:22:22 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/02 16:08:38 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, int only)
{
	t_stack	*largest_node;

	largest_node = stack_max(*a);
	if ((stack_last(*a))->num == largest_node->num)
	{
		if (!stack_sorted(*a))
			swap_a(a, only);
	}
	if ((*a)->num == largest_node->num)
	{
		rotate_a(a, only);
		if ((stack_last(*a))->num == largest_node->num)
		{
			if (!stack_sorted(*a))
				swap_a(a, only);
		}
	}
	if ((*a)->next->num == largest_node->num)
	{
		reverse_rotate_a(a, only);
		if (!stack_sorted(*a))
			swap_a(a, only);
	}
}
void	sort_big(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) // If stack `a` has more than three nodes and aren't sorted
		push_b(b, a, 1);
	if (len_a-- > 3 && !stack_sorted(*a)) // If stack `a` still has more than three nodes and aren't sorted
		push_b(b, a, 1);
	init_a_to_b(*a, *b);
	// while (len_a-- > 3 && !stack_sorted(*a))
	// {
	// 	init_a_to_b(a, b);
	// }
	// ft_printf("A: \n");
	// print_stack(*a, 0);
	// ft_printf("B: \n");
	// print_stack(*b, 0);
}