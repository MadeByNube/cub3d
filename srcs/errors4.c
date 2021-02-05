/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:23:53 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 13:43:14 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_focmaximo(char **aux2)
{
	int	x;

	x = 0;
	while (aux2[x])
	{
		if (ft_atoi(aux2[x]) < 0 || ft_atoi(aux2[x]) > 255)
		{
			perror("Error\nColor incorrecto");
		}
		x++;
	}
}
