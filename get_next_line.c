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

// norminette
// gcc -Wall -Wextra -Werror get_next_line.c
// gcc -Wall -Wextra -Werror get_next_line.c && ./a.out && rm -rf a.out
// gcc get_next_line.c && ./a.out && rm -rf a.out
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int	main(void)
{
	int fd;
	int ret;
	char *buff;

	fd = 0;
	fd = open("files/mypao", O_RDWR);
	ret = 0;
	if(fd == -1)
	{

	}
	else
	{
		printf("%d\n", fd);
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';

		printf("ret is %d\n", ret);
		printf("Buff is %s\n", buff);

		ret = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';

		printf("ret is %d\n", ret);
		printf("Buff is %s\n", buff);

		free(buff);
	}
	printf("%d\n", fd);

	// char *get_next_line(int fd);
	return (0);
}
