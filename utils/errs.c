/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:30:54 by mtangalv          #+#    #+#             */
/*   Updated: 2025/04/05 18:20:57 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// free the given stack
void ft_free(t_stack **stack)
{
	t_stack *tmp;
	t_stack	*current;
	
	if (!(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->num = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_error_stack(t_stack **stk)
{
	ft_free(stk);
	ft_printf("Error\n");
	exit(1);
}
int	ft_error_string(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	ft_printf("Error\n");
	exit(1);
}