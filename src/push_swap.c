/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:11:47 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/29 16:43:02 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(t_stack *stk)
{
	int	num;

	num = stk->num;
	while (stk)
	{
		if (stk->num < num)
			return (0);
		num = stk->num;
		stk = stk->next;
	}
	return (1);
}

static void sort_stack(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(a) == 2)
		swap_a(&a, 1);
	if (stack_size(a) == 3)
		sort_three(&a, 1);
	else
		sort_big(&a, &b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int	i;

	i = 1;
	stack_a = NULL;
	if (argc == 1)
		(exit(1));
	if (argc == 2)
		parse_string(argv[1]);
	else
	{
		while(i < argc)
			check_arg(argv[i++]);
	}
	stack_a = init_stack(argc, argv);
	check_dup(stack_a);
	if (!stack_sorted(stack_a))
		sort_stack(stack_a);
	ft_free(stack_a);
	return (0);
}
