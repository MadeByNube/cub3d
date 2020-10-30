/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:52 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/30 11:28:36 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int args, char **argv)
{
	t_datos	*dat;

	if (args != 3)
		ft_errorargs();
	if (!(dat = (t_datos *)malloc(sizeof(t_datos))))
		return (-1);
	ft_genmap(argv[1], dat);
	dat->mapname = argv[1];
	ft_errors(dat);
	ft_frees(dat);
	system("leaks cub3D");
	return(0);
}
