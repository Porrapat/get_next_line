/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/13 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/13 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		round;
	char	*result;

	fd = open("files/mypao", O_RDWR);
	// fd = open("files/empty", O_RDWR);
	// fd = open("files/nl", O_RDWR);
	// fd = open("files/41_no_nl", O_RDWR);
	// fd = open("files/41_with_nl", O_RDWR);
	round = 1;
	printf("fd is %d\n", fd);
	printf("BUFFER is %d\n", BUFFER_SIZE);
	if(fd != -1)
	{
		result = get_next_line(fd);
		while (result)
		{
			printf("%d. Line is %s*\n", round++, result);
			free(result);
			result = NULL;
			result = get_next_line(fd);

			if (round == 100)
			{
				if(result)
				{
					free(result);
					result = NULL;
				}
				break;
			}
		}

	}
	close(fd);
	return (0);
}

// if(fd != -1)
// {
// 	result = get_next_line(fd);
// 	printf("%d. Line is %s*\n", round++, result);
// 	if(result)
// 	{
// 		free(result);
// 		result = NULL;
// 	}
// }
// if(fd != -1)
// {
// 	result = get_next_line(fd);
// 	printf("%d. Line is %s*\n", round++, result);
// 	if(result != NULL)
// 	{
// 		free(result);
// 		result = NULL;
// 	}
// }