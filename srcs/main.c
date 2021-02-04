/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:52 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/04 13:39:13 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int args, char **argv)
{
	t_datos	*dat;
	dat = ft_calloc(sizeof(t_datos), 1);
	dat->rct = ft_calloc(sizeof(t_raycast), 1);
	ft_args(args, argv, dat);
	ft_genmap(argv[1], dat);
	dat->mapname = argv[1];
	ft_errors(dat);
	ft_preraycasting(dat);
	ft_raycasting(dat);
	ft_frees(dat);
	return (0);
}
