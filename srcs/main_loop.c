/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:49:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/08 12:51:32 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		ft_main_loop(t_datos *dat)
{
	dat->img = mlx_new_image(dat->mlx_ptr, dat->r1, dat->r2);
	dat->dir = mlx_get_data_addr(dat->img, &dat->bits_per_pixel,
		&dat->line_length, &dat->endian);
	if (dat->save == 1)
		dat->line_length = dat->r1 * 4;
	key_hook(dat);
	ft_rays(dat);
	if (dat->save == 1)
		ft_image(dat);
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	mlx_destroy_image(dat->mlx_ptr, dat->img);
	return (0);
}

void	ft_image(t_datos *dat)
{
	t_bmp *bmp;

	if (!(bmp = malloc(sizeof(t_bmp))))
	{
		perror("Error:\n No se reserva memoria para bmp");
		exit(32);
	}
	ft_writeheader(dat, bmp);
	exit(0);
}

void	ft_writeheader(t_datos *dat, t_bmp *bmp)
{
	ft_initsave(dat, bmp);
	write(bmp->fdsave, "B", sizeof(unsigned char));
	write(bmp->fdsave, "M", sizeof(unsigned char));
	write(bmp->fdsave, &bmp->filesize, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->offset_begin, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->header_bytes, sizeof(unsigned int));
	write(bmp->fdsave, &dat->r1, sizeof(unsigned int));
	write(bmp->fdsave, &dat->r2, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->bmpplane, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->bmpbpx, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->imagesize, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	ft_writebmp(dat, bmp);
	close(bmp->fdsave);
}

void	ft_initsave(t_datos *dat, t_bmp *bmp)
{
	bmp->filesize = 54 + dat->r2 * dat->line_length;
	bmp->imagesize = dat->r1 * dat->r2;
	bmp->unused = 0;
	bmp->offset_begin = 54;
	bmp->header_bytes = 40;
	bmp->bmpplane = 1;
	bmp->bmpbpx = dat->bits_per_pixel;
	bmp->fdsave = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (bmp->fdsave < 0)
	{
		perror("Error:\nCaptura no creada");
		exit(34);
	}
}

void	ft_writebmp(t_datos *dat, t_bmp *bmp)
{
	int x;
	int y;
	int line;

	y = 0;
	while (y <= dat->r2)
	{
		x = 0;
		line = (dat->line_length / 4) * (dat->r2 - y);
		while (x < dat->r1)
		{
			write(bmp->fdsave, &dat->dir[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}
