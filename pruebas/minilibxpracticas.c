/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibxpracticas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:08:53 by cnavarro          #+#    #+#             */
/*   Updated: 2020/09/21 12:42:05 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 400, 400, "Se hacer una puta ventana joder soy el puto amo");
    mlx_loop(mlx_ptr);
}
