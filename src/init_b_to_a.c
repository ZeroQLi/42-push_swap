/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:04:25 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/04 21:28:41 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_b;
	long	closest_num;
	
	while (b)
	{
		closest_num = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < closest_num)
			{
				closest_num = current_a->num;
				target_b = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_num == LONG_MAX)
			b->target = stack_min(a);
		else
			b->target = target_b;
		b = b->next;
	}
}

void	init_b_to_a(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	target_b(a, b);
}
