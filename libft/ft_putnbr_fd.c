/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:07:21 by iibarra-          #+#    #+#             */
/*   Updated: 2019/11/12 17:57:35 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char aux;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb <= 9)
	{
		aux = nb + '0';
		write(fd, &aux, 1);
	}
	else
	{
		aux = (nb % 10) + '0';
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &aux, 1);
	}
}
