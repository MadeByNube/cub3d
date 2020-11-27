/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:57:44 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/26 12:04:27 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	ft_hexadigit(char *hex)
{
	int i;

	i = 0;
	while (hex[i] != '\0')
	{
		if (hex[i] <= 10)
			hex[i] = hex[i] + '0' - 1;
		else
			hex[i] = hex[i] - 10 + 'a' - 1;
		i++;
	}
}

static char	*ft_reverse(char *hex)
{
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(hex);
	cpy = malloc(sizeof(char) * i + 1);
	i--;
	while (i >= 0)
	{
		cpy[j] = hex[i];
		j++;
		i--;
	}
	cpy[j] = '\0';
	free(hex);
	return (cpy);
}

char		*ft_makehex(t_datos *dat)
{
	char				*hex;
	int					i;
	unsigned long int	mod;

	mod = dat->unsint;
	hex = malloc(sizeof(char) * ft_digitcount(dat, dat->unsint));
	i = 0;
	while (mod >= 16)
	{
		hex[i] = mod % 16 + 1;
		mod = mod / 16;
		i++;
	}
	hex[i] = mod + 1;
	i++;
	hex[i] = '\0';
	ft_hexadigit(hex);
	hex = ft_reverse(hex);
	return (hex);
}
