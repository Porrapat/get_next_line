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

char	*make_main_str(int fd, int *read_return, char buff[])
{
	static char	*main_str;
	char		*in_to_return_str;
	int			old_len;
	char		*new_str;

	*read_return = read(fd, buff, BUFFER_SIZE);
	while (*read_return > 0)
	{
		buff[*read_return] = 0;
		old_len = ft_strlen(main_str);
		main_str = ft_realloc(main_str, *read_return + old_len + 1);
		main_str[old_len] = '\0';
		ft_strlcat(main_str, buff, *read_return + old_len + 1);
		new_str = ft_strnstr(main_str, "\n", old_len + 1);
		if (new_str)
		{
			in_to_return_str = malloc(new_str - main_str + 2);
			ft_memcpy(in_to_return_str, main_str, new_str - main_str + 1);
			in_to_return_str[new_str - main_str + 1] = '\0';
			ft_memcpy(main_str, new_str + 1, ft_strlen(new_str));
			free(buff);
			return (in_to_return_str);
		}
		*read_return = read(fd, buff, BUFFER_SIZE);
	}
}

char	*check_for_read_return(int *read_return)
{
	static char	*main_str;
	char		*new_new_str;

	if (*read_return == -1)
		return (NULL);
	if (*read_return == 0)
	{
		if (ft_strlen(main_str) > 0)
		{
			new_new_str = malloc(ft_strlen(main_str) + 1);
			ft_memcpy(new_new_str, main_str, ft_strlen(main_str));
			new_new_str[ft_strlen(main_str)] = '\0';
			free(main_str);
			return (new_new_str);
		}
		else
			return (NULL);
	}
}

char	*get_next_line_main_logic(int fd)
{
	static char	*main_str;
	char		*buff;
	int			read_return;
	char		*new_str;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_str = make_main_str(fd, &read_return, buff);
	if (new_str)
		return (new_str);
	else
	{
		free(buff);
		return (NULL);
	}
	new_str = check_for_read_return(&read_return);
	if (new_str)
		return (new_str);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*main_str;
	char		*to_return_str;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	if (!main_str)
	{
		main_str = (char *)malloc(1);
		main_str[0] = '\0';
	}
	to_return_str = get_next_line_main_logic(fd);
	return (to_return_str);
}

/*
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
	if(fd != -1)
	{
		while((result = get_next_line(fd)))
		{
			printf("%d. Line is %s*\n", round++, result);
			free(result);
			result = NULL;
		}
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
	close(fd);
	return (0);
}
*/
