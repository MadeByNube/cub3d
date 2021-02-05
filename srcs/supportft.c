/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:08:14 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 12:39:02 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_freematrix(char **matrix)
{
	int x;

	x = 0;
	while (matrix[x])
	{
		free(matrix[x]);
		x++;
	}
	free(matrix);
}
