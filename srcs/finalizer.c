/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:07:17 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/26 11:22:42 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_frees(t_datos *dat)
{
	if (dat->mapa)
		free(dat->mapa);
	if (dat->r)
		free(dat->r);
	if (dat->no)
		free(dat->no);
	if (dat->so)
		free(dat->so);
	if (dat->we)
		free(dat->we);
	if (dat->ea)
		free(dat->ea);
	if (dat->s)
		free(dat->s);
	if (dat->f)
		free(dat->f);
	if (dat->c)
		free(dat->c);
	if (dat->mapname)
		free(dat->mapname);
}
