/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:34:38 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 12:58:40 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int			ft_lenint(int n)
{
	int len;

	len = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static int			ft_iterative_power(int nb, int power)
{
	int cnb;

	cnb = nb;
	if (power == 0)
	{
		return (1);
	}
	else if (power < 0)
	{
		return (0);
	}
	else
	{
		while (power > 1)
		{
			cnb = cnb * nb;
			power--;
		}
	}
	return (cnb);
}

static void			ft_fillret(int n, int len, char *ret, int i)
{
	while (len > 0)
	{
		if (len > 1)
		{
			ret[i] = n / ft_iterative_power(10, (len - 1)) + '0';
			n = n % ft_iterative_power(10, (len - 1));
		}
		else
			ret[i] = n + '0';
		len--;
		i++;
	}
	ret[i] = '\0';
}

static char			*ft_except(void)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * 12)))
		return (NULL);
	ret = (ft_strdup("-2147483648"));
	return (ret);
}

char				*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		i;

	if (n == -2147483648)
	{
		ret = ft_except();
		return (ret);
	}
	len = ft_lenint(n);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		if (!(ret = malloc(sizeof(char) * len + 2)))
			return (NULL);
		ret[0] = '-';
		n = n * -1;
		i++;
	}
	else if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_fillret(n, len, ret, i);
	return (ret);
}
