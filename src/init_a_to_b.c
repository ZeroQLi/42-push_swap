/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:14 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/02 18:07:55 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index(t_stack *stk)
{
	int	i;

	i = 0;
	if (!stk)
		return ;
	while (stk)
	{
		stk->index = i;
		stk = stk->next;
		++i;
	}
}

void	set_median(t_stack *stk)
{
	int	median;
	
	median = (stack_size(stk) - 1) / 2;
	if (!stk)
		return;
	while (stk)
	{
		if (stk->index <= median)
			stk->above_median = 1;
		else
			stk->above_median = 0;
		stk = stk->next;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	ft_printf("A: \n");
	print_stack(a, 0);
	ft_printf("B: \n");
	print_stack(b, 0);
}

void	init_a_to_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_median(a);
	set_median(b);
	target_a(a, b);
}