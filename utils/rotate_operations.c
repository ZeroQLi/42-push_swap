/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:59:37 by zeroql            #+#    #+#             */
/*   Updated: 2025/03/23 16:56:09 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **a, int only)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	
	*a = stack_last(*a);
	(*a)->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
	if (only == 1)
		ft_printf("ra\n");
}

void reverse_rotate_a(t_stack **a, int only)
{
	t_stack *tmp;

	if (!*a || !(*a)->next)
		return;

	tmp = stack_last(*a);
	tmp->prev->next = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	*a = tmp;
	tmp->next->prev = tmp;
	if (only == 1)
		ft_printf("rra\n");
}