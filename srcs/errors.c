/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:58:31 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/06 13:39:05 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_errorsmap(t_datos *dat)
{
	char **mapa;
	int i;

	i = 0;
	mapa = malloc(sizeof(char **) * (dat->filmap + 1));
	while (dat->mapa[i])
	{
		mapa[i] = ft_strdup(dat->mapa[i]);
		i++;
	}
	mapa[i] = NULL;
	ft_charsmap(mapa);
	ft_valmap(mapa, dat);
	ft_freematrix(mapa);
}

void	ft_errorsconfig(t_datos *dat)
{
	ft_erroresgeneral(dat);
	ft_errorerre(dat->r);
	ft_errortexture(dat->no);
	ft_errortexture(dat->so);
	ft_errortexture(dat->we);
	ft_errortexture(dat->ea);
	ft_errortexture(dat->s);
	ft_errorfoc(dat->f);
	ft_errorfoc(dat->c);
}

void	ft_errors(t_datos *dat)
{
	ft_errorsconfig(dat);
	ft_errorsmap(dat);
}

void	ft_errorargs(void)
{
	perror("Error\nNumero de argumentos invalidos");
	exit(8);
}