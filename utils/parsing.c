/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:04:18 by mtangalv          #+#    #+#             */
/*   Updated: 2025/04/14 16:46:54 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(char *str)
{
	long long int	ans;
	int				result;

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
		if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
			ft_error();
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	return (result * ans);
}

static int	check_arg_string(char *str, char **arr)
{
	long long int	ans;
	int				result;

	ans = 0;
	result = 1;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error_string(arr);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error_string(arr);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
		ft_error_string(arr);
	return (result * ans);
}

void	parse_string(char *str)
{
	int		i;
	char	**arr;

	if (ft_strlen(str) == 0)
		ft_error();
	i = 0;
	arr = ft_split(str, ' ');
	if (!*arr)
	{
		free(arr);
		arr = NULL;
		ft_error();
	}
	while (arr[i])
		check_arg_string(arr[i++], arr);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i++] = NULL;
	}
	free(arr);
	arr = NULL;
}

int	check_dup(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*check;

	check = *stk;
	while (check)
	{
		tmp = check->next;
		while (tmp)
		{
			if (tmp->num == check->num)
				ft_error_stack(stk);
			tmp = tmp->next;
		}
		check = check->next;
	}
	return (0);
}
