/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:30:54 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/20 16:33:45 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// free the given stack
// void ft_free(t_stack *stack)
// {
// 	t_stack *tmp;

// 	if (!stack)
// 		return;
// 	while (stack)
// 	{
// 		tmp = (stack)->next;
// 		(stack)->num = 0;
// 		free(stack);
// 		stack = tmp;
// 	}
// }

int	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
