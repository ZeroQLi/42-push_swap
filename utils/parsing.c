/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:04:18 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/20 16:52:40 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_arg(char *str)
{
	long long int ans;
	int result;

	ans = 0;
	result = 1;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
		ft_error();
	return (result * ans);
}

void parse_string(char *str)
{
	char **arr;

	arr = ft_split(str, ' ');
	while (*arr)
		check_arg(*arr++);
}

int	check_dup(t_stack *stk)
{
	t_stack	*tmp;

	while(stk)
	{
		tmp = stk->next;
		while (tmp)
		{
			if (tmp->num == stk->num)
				ft_error();
			tmp = tmp->next;
		}
		stk = stk->next;
	}
	return (0);
}
