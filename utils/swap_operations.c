/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:10:46 by zeroql            #+#    #+#             */
/*   Updated: 2025/03/29 17:16:04 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack	**a, int only)
{
	t_stack *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (only == 1)
		ft_printf("sa\n");
}
void swap_b(t_stack **b, int only)
{
	swap_a(b, 0);
	if (only == 1)
		ft_printf("sb\n");
}