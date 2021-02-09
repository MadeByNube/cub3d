/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:48:43 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/09 11:27:45 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESCAPE			53
# define KEY_F1 			122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F4				118
# define KEY_F5				96
# define KEY_F6				97
# define KEY_F7				98
# define KEY_F8				100
# define KEY_F9				101
# define KEY_F10			109
# define KEY_F11			103
# define KEY_F12			111
# define KEY_F13			105
# define KEY_F14			107
# define KEY_F15			113
# define KEY_F16			106
# define KEY_F17			64
# define KEY_F18			79
# define KEY_F19			80
# define KEY_TILDE			50
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_BACKSPACE		51
# define KEY_TAB			48
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_OPEN_BRACKET	33
# define KEY_OPEN_BRACE		33
# define KEY_CLOSE_BRACKET	30
# define KEY_CLOSE_BRACE	30
# define KEY_BACKSLASH		42
# define KEY_PIPE			42
# define KEY_CAPSLOCK		272
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_COLON			41
# define KEY_SEMI_COLON		41
# define KEY_SIMPLE_QUOTE	39
# define KEY_DOUBLE_QUOTES	39
# define KEY_ENTER			36
# define KEY_SHIFT_LEFT		257
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46
# define KEY_LESS_THAN		43
# define KEY_COMMA			43
# define KEY_GREATER_THAN	47
# define KEY_DOT			47
# define KEY_SLASH			44
# define KEY_QUESTION_MARK	44
# define KEY_SHIFT_RIGHT	258
# define KEY_CTRL_LEFT		256
# define KEY_COMMAND_LEFT	259
# define KEY_OPTION_LEFT	261
# define KEY_ALT			261
# define KEY_SPACEBAR		49
# define KEY_COMMAND_RIGHT	260
# define KEY_ALT_GR			262
# define KEY_FN				279
# define KEY_CTRL_RIGHT		269
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DEL			117
# define KEY_HOME			115
# define KEY_END			119
# define KEY_PAGE_UP		116
# define KEY_PAGE_DOWN		121
# define KEY_CLEAR			71
# define KEY_PAD_1			83
# define KEY_PAD_2			84
# define KEY_PAD_3			85
# define KEY_PAD_4			86
# define KEY_PAD_5			87
# define KEY_PAD_6			88
# define KEY_PAD_7			89
# define KEY_PAD_8			91
# define KEY_PAD_9			92
# define KEY_PAD_0			82
# define KEY_PAD_EQUAL		81
# define KEY_PAD_DIVIDE		75
# define KEY_PAD_MULTIPLY	67
# define KEY_PAD_SUB		78
# define KEY_PAD_ADD		69
# define KEY_PAD_ENTER		76
# define KEY_PAD_DOT		65
# define MOVESPEED			0.09
# define ROTSPEED			0.13089975
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_beta/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_textures
{
	void			*img;
	char			*addr;
	char			*rute;
	int				size;
	int				bpp;
	int				width;
	int				height;
	int				endian;
}					t_textures;

typedef struct		s_raycast
{
	double			plposx;
	double			plposy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camx;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			olddirx;
	double			oldplanex;
}					t_raycast;

typedef struct		s_datos
{

	char			*initmaplane;
	char			*mapname;
	char			*r;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*f;
	char			*c;
	char			*cnew;
	char			*fnew;
	char			**mapa;
	int				filmap;
	int				nomaplines;
	int				rflag;
	int				noflag;
	int				soflag;
	int				weflag;
	int				eaflag;
	int				sflag;
	int				fflag;
	int				cflag;
	int				**mapint;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*dir;
	int				r1;
	int				r2;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	void			*texture;
	char			*text_img;
	char			cardinal;
	int				keyw;
	int				keys;
	int				keya;
	int				keyd;
	int				right;
	int				left;
	int				keyesc;
	t_textures		tex[5];
	int				text;
	t_raycast		*rct;
	int				texnum;
	double			wallx;
	int				tex_x;
	double			step;
	double			texpos;
	int				texy;
	unsigned int	color;
	double			*zbuffer;
	int				sprcount;
	int				**sprarray;
	int				*spr_ord;
	double			*spr_dist;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				save;
	int				stripe;
}					t_datos;

typedef struct		s_bmp
{
	int				fdsave;
	int				filesize;
	int				unused;
	int				offset_begin;
	int				header_bytes;
	int				imagesize;
	short int		bmpplane;
	short int		bmpbpx;
}					t_bmp;

char				*ft_strjoingnl(char *str1, char car);

int					getnextline(char **line, int fdmap);
void				ft_genmap(char *mapa, t_datos *dat);

void				ft_args(int args, char **argv, t_datos *dat);
void				ft_erroresgeneral(t_datos *dat);
void				ft_errorextmap(t_datos *dat);
void				ft_errorargs(void);
void				ft_errorf(t_datos *dat);
void				ft_errorc(t_datos *dat);
void				ft_focnumerico(char **aux2);
void				ft_rnumerico(char **aux);
void				ft_focmaximo(char **aux2);
void				ft_errortexture(char *texture);
void				ft_errorerre(char *r);
void				ft_errors(t_datos *dat);
void				ft_errorsmap(t_datos *dat);
void				ft_saveconfig(int fdmap, t_datos *dat);
void				ft_saveconfigb(t_datos *dat, int i, char *line);
void				ft_correctconfig(t_datos *dat);
void				ft_quitaespacios2000f(t_datos *dat);
void				ft_quitaespacios2000c(t_datos *dat);
char				*ft_convtexture(char *texture);

void				ft_saveorerror_r(t_datos *dat, char *line);
void				ft_saveorerror_no(t_datos *dat, char *line);
void				ft_saveorerror_so(t_datos *dat, char *line);
void				ft_saveorerror_we(t_datos *dat, char *line);
void				ft_saveorerror_ea(t_datos *dat, char *line);
void				ft_saveorerror_s(t_datos *dat, char *line);
void				ft_saveorerror_f(t_datos *dat, char *line);
void				ft_saveorerror_c(t_datos *dat, char *line);

void				ft_valmap(char **mapa, t_datos *dat);
void				ft_valmap2(char **mapa, int x, int y, t_datos *dat);

void				ft_frees(t_datos *dat);
void				ft_freematrix(char **matrix);
void				ft_charsmap(char **mapa);

void				ft_raycasting(t_datos *dat);
void				ft_preraycasting(t_datos *dat);
void				ft_intmap(t_datos *dat);
void				ft_configadd(t_datos *dat);
void				ft_mlx_pixel_put(t_datos *dat, int x, int y, int color);
int					ft_color(char *cadena);
int					key_hook(t_datos *dat);
int					ft_main_loop(t_datos *dat);
void				ft_texturas(t_datos *dat);
void				ft_rays(t_datos *dat);
void				ft_dirpos(t_datos *dat);
void				ft_prerays(t_datos *dat);
void				ft_verline(int x, t_datos *dat);
int					ft_keypress(int key, t_datos *dat);
int					ft_keyrelease(int key, t_datos *dat);
int					ft_exit(t_datos *dat);
int					ft_wallorient(t_datos *dat);
int					ft_pixel_get(t_datos *dat, int x, int y);
void				ft_presprites(t_datos *dat);
int					ft_count2(t_datos *dat);
void				ft_arraylogs(t_datos *dat);
void				ft_sortsprites(t_datos *dat);
void				ft_sortsprites2(t_datos *dat);
void				ft_spritesbucle(t_datos *dat);
void				ft_aftersort(t_datos *dat, int i);
void				ft_drawsprite(t_datos *dat);
void				ft_image(t_datos *dat);
void				ft_writeheader(t_datos *dat, t_bmp *bmp);
void				ft_initsave(t_datos *dat, t_bmp *bmp);
void				ft_writebmp(t_datos *dat, t_bmp *bmp);
#endif
