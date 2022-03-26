/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/13 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/13 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	mystatic(void)
{
	static int	i = 100;

	i++;
	printf("in my static %d\n", i);
}

int	main(void)
{
	static int	i = 1000;

	i = 100;
	mystatic();
	mystatic();
	mystatic();
	mystatic();
	mystatic();
	mystatic();
	mystatic();
	printf("%d", i);
	return (0);
}
