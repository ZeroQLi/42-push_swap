/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:57:38 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/04 23:40:39 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_str(char *argv)
{
	t_stack *a = NULL;
	char **arr;
	int i;

	i = 0;
	arr = ft_split(argv, ' ');
	while (arr[i])
	{
		stack_add_back(&a, new_stack_node(ft_atoi(arr[i]), i));
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (a);
}

t_stack *init_stack(int argc, char **argv)
{
	t_stack *a;
	char **arr;
	int i;
	int index;

	i = 0;
	index = 0;
	a = NULL;
	if (argc == 2)
		a = init_str(argv[1]);
	else
	{
		i = 1;
		arr = argv;
		while (i < argc)
			stack_add_back(&a, new_stack_node(ft_atoi(arr[i++]), index++));
	}
	return (a);
}