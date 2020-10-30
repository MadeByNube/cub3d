#include "../headers/cub3d.h"

void ft_initializedat(t_datos *dat)
{
	dat->mapa = NULL;
	dat->filmap = 0;
	dat->r = NULL;
	dat->no = NULL;
	dat->so = NULL;
	dat->we = NULL;
	dat->ea = NULL;
	dat->s = NULL;
	dat->f = NULL;
	dat->c = NULL;
	dat->mapname = NULL;
}

void	ft_saveconfig(int fdmap, t_datos *dat)
{
	char *line;
	int comp;

	while((comp = getnextline(&line, fdmap)) > 0)
	{
		if (line[0] == 'R' && line[1] == ' ')
			dat->r = ft_strdup(line);
		else if (line[0] == 'N' && line[1] == 'O')
			dat->no = ft_strdup(line);
		else if (line[0] == 'S' && line[1] == 'O')
			dat->so = ft_strdup(line);
		else if (line[0] == 'W' && line[1] == 'E')
			dat->we = ft_strdup(line);
		else if (line[0] == 'E' && line[1] == 'A')
			dat->ea = ft_strdup(line);
		else if (line[0] == 'S' && line[1] == ' ')
			dat->s = ft_strdup(line);
		else if (line[0] == 'F' && line[1] == ' ')
			dat->f = ft_strdup(line);
		else if (line[0] == 'C' && line[1] == ' ')
			dat->c = ft_strdup(line);
		else break;
		dat->nomaplines++;
		free(line);
	}
	free(line);
}

static int	ft_contarfilas(int fdmap)
{
	int i;
	char *line;

	line = NULL;
	i = 0;
	while (((getnextline(&line, fdmap)) > 0) && (ft_strncmp(line, "\n", ft_strlen(line)) == 1))
		free(line);
	free(line);
	while((getnextline(&line, fdmap)) > 0)
	{
		i++;
		free(line);
	}
	i = i + 2;
	free(line);
	return (i);
}

void	ft_savemap(t_datos *dat, int fdmap)
{
	char *line;
	int i;
	int cont;

	cont = 0;
	i = 0;
	line = NULL;
	while (cont < dat->nomaplines)
	{
		getnextline(&line, fdmap);
		free(line);
		cont++;
	}
	while (((getnextline(&line, fdmap)) > 0) && (ft_strncmp(line, "\n", ft_strlen(line)) == 1))
		free(line);
	getnextline(&dat->mapa[i], fdmap);
	i++;
	while (i < dat->filmap)
	{
		getnextline(&dat->mapa[i], fdmap);
		i++;
	}
	dat->mapa[i] = NULL;
	free(line);
}

void		ft_genmap(char *archivo, t_datos *dat)
{
	int fdmap;

	ft_initializedat(dat);
	fdmap = open(archivo, O_RDONLY);
	ft_saveconfig(fdmap, dat);
	dat->filmap = ft_contarfilas(fdmap);
	close(fdmap);
	fdmap = open(archivo, O_RDONLY);
	dat->mapa = malloc(sizeof(char **) * (dat->filmap + 1));
	ft_savemap(dat, fdmap);
	close(fdmap);
}
