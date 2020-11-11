/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:43 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/11 13:24:09 by cnavarro         ###   ########.fr       */
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
	char *initmaplane;
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
	int rflag;
	int noflag;
	int soflag;
	int weflag;
	int eaflag;
	int sflag;
	int fflag;
	int cflag;
}				t_datos;


char		*ft_strjoingnl(char *str1, char car);

int			getnextline(char **line, int fdmap);
void		ft_genmap(char *mapa, t_datos *dat);

void		ft_args(int args, char **argv);
void		ft_erroresgeneral(t_datos *dat);
void		ft_errorextmap(t_datos *dat);
void		ft_errorargs(void);
void		ft_errorfoc(char *f);
void		ft_focnumerico(char **aux2);
void		ft_rnumerico(char **aux);
void		ft_focmaximo(char **aux2);
void		ft_errortexture(char *texture);
void		ft_errorerre(char *r);
void		ft_errors(t_datos *dat);
void		ft_errorsmap(t_datos *dat);
void		ft_saveconfig(int fdmap, t_datos *dat);
void		ft_correctconfig(t_datos *dat);
void		ft_quitaespacios2000(char *f);
char		*ft_convtexture(char *texture);

void    	ft_saveorerror_r(t_datos *dat, char *line);
void		ft_saveorerror_no(t_datos *dat, char *line);
void		ft_saveorerror_so(t_datos *dat, char *line);
void		ft_saveorerror_we(t_datos *dat, char *line);
void		ft_saveorerror_ea(t_datos *dat, char *line);
void		ft_saveorerror_s(t_datos *dat, char *line);
void		ft_saveorerror_f(t_datos *dat, char *line);
void		ft_saveorerror_c(t_datos *dat, char *line);


void		ft_valmap(char **mapa, t_datos *dat);
void		ft_valmap2(char **mapa, int x, int y, t_datos *dat);

void		ft_frees(t_datos *dat);
void		ft_freematrix(char **matrix);
void		ft_charsmap(char **mapa);
#endif