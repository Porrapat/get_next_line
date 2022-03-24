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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		ret;

	ret = 0;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	return (buff);
}

int	main(void)
{
	int		fd;

	fd = 0;
	fd = open("files/mypao", O_RDWR);

	if(fd != -1)
	{
		printf("1. Line is %s", get_next_line(fd));
		printf("2. Line is %s", get_next_line(fd));
		printf("3. Line is %s", get_next_line(fd));
		// free(buff);
	}
	// printf("%d\n", fd);

	return (0);
}
