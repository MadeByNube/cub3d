/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:52 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/20 11:01:40 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int args, char **argv)
{
	int i;
	if (args != 3)
		i = 0;
	i = 0;
	t_datos	*dat;

	if (!(dat = (t_datos *)malloc(sizeof(t_datos))))
		return (-1);
	ft_genmap(argv[1], dat);
	dat->mapname = argv[1];
	ft_errors(dat);
	return(0);
}
