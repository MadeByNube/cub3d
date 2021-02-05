/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:27:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 12:57:20 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static char	*ft_texturesthings(char *src)
{
	char **aux;
	char *dst;

	aux = ft_split(src, ' ');
	dst = ft_strdup(aux[1]);
	ft_freematrix(aux);
	return (dst);
}

void		ft_texturas(t_datos *dat)
{
	int i;

	i = 0;
	dat->tex[0].rute = ft_texturesthings(dat->no);
	dat->tex[1].rute = ft_texturesthings(dat->so);
	dat->tex[2].rute = ft_texturesthings(dat->we);
	dat->tex[3].rute = ft_texturesthings(dat->ea);
	dat->tex[4].rute = ft_texturesthings(dat->s);
	while (i < 5)
	{
		dat->tex[i].img = mlx_xpm_file_to_image(dat->mlx_ptr,
			dat->tex[i].rute, &dat->tex[i].width, &dat->tex[i].height);
		dat->tex[i].addr = mlx_get_data_addr(dat->tex[i].img,
			&dat->tex[i].bpp, &dat->tex[i].size, &dat->tex[i].endian);
		i++;
	}
}
