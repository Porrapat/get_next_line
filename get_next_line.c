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
#include <string.h>

char	*get_next_line(int fd)
{
	char	*buff;
	int		return_bytes;

	return_bytes = 0;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	return_bytes = read(fd, buff, BUFFER_SIZE);
	if(return_bytes == 0)
	{
		free(buff);
		return (NULL);
	}
	buff[BUFFER_SIZE] = '\0';
	return (buff);
}

int	main(void)
{
	int		fd;
	char	*result;
	int		round;

	fd = 0;
	fd = open("files/mypao", O_RDWR);

	round = 1;
	if(fd != -1)
	{
		// result = get_next_line(fd);
		// if(result == NULL)
		// 	return (0);
		// printf("1. Line is %s", result);
		// free(result);

		// result = get_next_line(fd);
		// if(result == NULL)
		// 	return (0);
		// printf("2. Line is %s", result);
		// free(result);

		// result = get_next_line(fd);
		// if(result == NULL)
		// 	return (0);
		// printf("3. Line is %s", result);
		// free(result);

		while(result = get_next_line(fd))
		{
			printf("%d. Line is %s", round++, result);
			free(result);
		}


		// printf("2. Line is %s", get_next_line(fd));
		// printf("3. Line is %s", get_next_line(fd));
		// free(buff);

		// printf("ft strlen is %ld\n", ft_strlen("Hello"));
	}
	// printf("%d\n", fd);

	return (0);
}
