/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:58:31 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/04 13:39:04 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_errorsmap(t_datos *dat)
{
	char **mapa;
	int i;

	i = 0;
	mapa = ft_calloc(sizeof(char **) * (dat->filmap + 1), 1);
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

void	ft_args(int args, char **argv, t_datos *dat)
{
	if (!(args == 3 || args == 2))
		ft_errorargs();
	if (args == 3 && (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0))
		ft_errorargs();
	if (args == 3 && (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0))
		dat->save = 1;
}