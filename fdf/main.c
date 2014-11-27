/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:10:26 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/27 20:16:31 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	/*if (ac < 4)
	{
		ft_putstr("\nwrong param:\n\n1st: File Name.\n2nd: Bottom Color (0xRRGGBB).\n3rd: Middle Color (0xRRGGBB).\n\n");
		return (0);
	}*/
	if (ac < 1)
		return (0);
	if (!av[0])
		return (0);
	//open_f(av[1]);
	init();
	return (0);
}