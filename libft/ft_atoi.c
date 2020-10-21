/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:13 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 12:14:35 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_space_spaces(const char *str, int i)
{
	while ((str[i]) == '\t' || (str[i]) == '\n' ||
	(str[i]) == '\v' || (str[i]) == '\f' ||
	(str[i]) == '\r' || (str[i]) == ' ')
	{
		i++;
	}
	return (i);
}

static int	ft_setnumber(const char *str, int i, int neg)
{
	int n;

	n = 0;
	while ((str[i]) >= '0' && (str[i]) <= '9')
	{
		n = ((n * 10) + (str[i]) - '0');
		i++;
	}
	n = n * neg;
	return (n);
}

int			ft_atoi(const char *str)
{
	int n;
	int i;
	int neg;

	neg = 1;
	i = 0;
	i = ft_space_spaces(str, i);
	if ((str[i]) == '+')
		i++;
	else if ((str[i]) == '-')
	{
		neg = -1;
		i++;
	}
	else if ((str[i]) < '0' || (str[i]) > '9')
		return (0);
	if ((str[i]) < '0' || (str[i]) > '9')
		return (0);
	n = ft_setnumber(str, i, neg);
	return (n);
}
