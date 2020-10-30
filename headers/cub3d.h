/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:43 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/29 10:54:27 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
typedef struct	s_datos
{
	char *mapname;
	char *r;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	char *f;
	char *c;
	char **mapa;
	int filmap;
	int nomaplines;
}				t_datos;

char		*ft_strjoingnl(char *str1, char car);

int			getnextline(char **line, int fdmap);
void		ft_genmap(char *mapa, t_datos *dat);

void		ft_erroresgeneral(t_datos *dat);
void		ft_errorextmap(t_datos *dat);
void		ft_errorfoc(char *f);
void		ft_errortexture(char *texture);
void		ft_errorerre(char *r);
void		ft_errors(t_datos *dat);
void		ft_errorsmap(t_datos *dat);
void		ft_valmap(char **mapa, t_datos *dat);
void		ft_valmap2(char **mapa, int x, int y, t_datos *dat);

void	ft_frees(t_datos *dat);
void    ft_freematrix(char **matrix);
void	ft_charsmap(char **mapa);

#endif