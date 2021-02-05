/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirpos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 12:53:38 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_dirpos2(t_datos *dat)
{
	if (dat->cardinal == 'W')
	{
		dat->rct->dirx = 0;
		dat->rct->diry = -1;
		dat->rct->planex = -0.66;
		dat->rct->planey = 0;
	}
	else if (dat->cardinal == 'E')
	{
		dat->rct->dirx = 0;
		dat->rct->diry = 1;
		dat->rct->planex = 0.66;
		dat->rct->planey = 0;
	}
}

void	ft_dirpos(t_datos *dat)
{
	if (dat->cardinal == 'N')
	{
		dat->rct->dirx = -1;
		dat->rct->diry = 0;
		dat->rct->planex = 0;
		dat->rct->planey = 0.66;
	}
	else if (dat->cardinal == 'S')
	{
		dat->rct->dirx = 1;
		dat->rct->diry = 0;
		dat->rct->planex = 0;
		dat->rct->planey = -0.66;
	}
	else
		ft_dirpos2(dat);
}
