/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:52 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/11 10:39:35 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int args, char **argv)
{
	t_datos	*dat;
	dat = malloc(sizeof(t_datos));
	ft_args(args, argv);
	ft_genmap(argv[1], dat);
	dat->mapname = argv[1];
	ft_errors(dat);
	ft_frees(dat);
	system("leaks cub3D");
	printf("hola\n\n");
	return (0);
}
