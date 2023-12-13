/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:10:29 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/13 21:22:09 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_TITLE "Byte's Escape, Yo!"

typedef struct s_window
{
	int	height;
	int	width;
}		t_window;

int		init_window(t_window *r_w_ptr);
#endif
