/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:15:07 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:27 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_insert_string(char **table, char *str)
{
	int		i;
	char	**aux;

	i = 0;
	while (table[i] != NULL)
		i++;
	i = i + 2;
	aux = malloc(i * sizeof(char *));
	i = 0;
	while (table[i] != NULL)
	{
		aux[i] = table[i];
		i++;
	}
	aux[i] = str;
	aux[i + 1] = NULL;
	free(table);
	return (aux);
}
