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
	char		*buff;
	static char	*main_str;
	int			old_len;
	char		*new_str;
	char		*to_return_str;

	if(!main_str) 
	{
		main_str = (char *)malloc(1);
		main_str[0] = '\0';
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);

	while(read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		old_len = ft_strlen(main_str);
		main_str = ft_realloc(main_str, ft_strlen(buff) + ft_strlen(main_str) + 1);
		
		main_str[old_len] = '\0';
		ft_strlcat(main_str, buff, ft_strlen(buff) + ft_strlen(main_str) + 1);
		if((new_str = ft_strnstr(main_str, "\n", ft_strlen(main_str))))
		{
			to_return_str = malloc(new_str - main_str + 2);
			ft_memcpy(to_return_str, main_str, new_str - main_str + 1);
			to_return_str[new_str - main_str + 1] = '\0';
			ft_memcpy(main_str, new_str + 1, ft_strlen(new_str));

			free(buff);
			return (to_return_str);
		}
	}

	free(buff);
	if(ft_strlen(main_str) > 0)
		return (main_str);
	else
	{
		free(main_str);
		return (NULL);
	}
}

int	main(void)
{
	int		fd;
	int		round;
	char	*result;

	fd = open("files/mypao", O_RDWR);
	round = 1;
	if(fd != -1)
	{
		while((result = get_next_line(fd)))
		{
			printf("%d. Line is %s*\n", round++, result);
			free(result);
		}
	}
	// if(fd != -1)
	// {
	// 	result = get_next_line(fd);
	// 	printf("%d. Line is %s*\n", round++, result);
	// 	free(result);
	// }
	close(fd);
	return (0);
}
