/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:11:47 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/20 17:02:57 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack *init_str(char *argv)
{
	t_stack *a = NULL;
	char **arr;
	int i;

	i = 0;
	arr = ft_split(argv, ' ');
	while(arr[i])
	{
		stack_add_back(&a, new_stack_node(ft_atoi(arr[i]), i));
		i++;
	}
	free(arr);
	return (a);
}

static t_stack *init_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**arr;
	int		i;
	int		index;

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;
	stack_b = NULL;

	i = 1;
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
}
