/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:21:25 by ahssaini          #+#    #+#             */
/*   Updated: 2021/09/25 18:21:36 by ahssaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 6, 0, julia_new, fractol);
}

int	get_mouse_state(int i)
{
	if (i == 0)
		return (1);
	return (0);
}

void	ctl(int key, t_fractol *fractol)
{
	if (key == 69)
		fractol->it_max += 5;
	if (key == 78)
	{
		fractol->it_max -= 5;
		if (fractol->it_max < 4)
			fractol->it_max = 1;
	}
	if (key == 1)
		fractol->julia_mouse = get_mouse_state(fractol->julia_mouse);
	if (key == 49)
		fractol->palette = (fractol->palette + 1) % 8;
	if (key == 53 || key == 123 || key == 124 || key == 125
		|| key == 126 || key == 69 || key == 78 || key == 1
		|| key == 49)
		draw(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == 53)
		free_exit(&fractol);
	if (key == 123)
		fractol->o_x += 20 / fractol->zoom;
	if (key == 124)
		fractol->o_x -= 20 / fractol->zoom;
	if (key == 125)
		fractol->o_y -= 20 / fractol->zoom;
	if (key == 126)
		fractol->o_y += 20 / fractol->zoom;
	ctl(key, fractol);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->o_x += x / fractol->zoom - (x / (fractol->zoom * 1.3));
		fractol->o_y += y / fractol->zoom - (y / (fractol->zoom * 1.3));
		fractol->zoom *= 1.3;
		draw(fractol);
	}
	if (button == 5)
	{
		fractol->o_x += x / fractol->zoom - (x / (fractol->zoom / 1.3));
		fractol->o_y += y / fractol->zoom - (y / (fractol->zoom / 1.3));
		fractol->zoom /= 1.3;
		draw(fractol);
	}
	return (0);
}
