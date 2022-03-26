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
#include <stdio.h>

static char	*check_newline_in_str(char *left_str)
{
	char	*ret;
	size_t	len;

	if (left_str == NULL)
	{
		len = 0;
		ret = NULL;
	}
	else
	{
		len = ft_strlen(left_str);
		ret = ft_strnstr(left_str, "\n", len);
	}
	return (ret);
}

static char	*get_next_line_main_logic(int fd, char *main_str)
{
	char	*buff;
	int		rd_bytes;
	char	*ret;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	ret = check_newline_in_str(main_str);
	while (!ret && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		main_str = ft_strmycat(main_str, buff);
		ret = check_newline_in_str(main_str);
	}
	free(buff);
	return (main_str);
}

static char	*get_to_return_line_from_main_str(char *main_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_new_main_str(char *main_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(main_str) - i));
	if (!str)
		return (NULL);
	j = ft_strlen(main_str + i) - 1;
	ft_memmove(str, main_str + i, j);
	str[j] = '\0';
	free(main_str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*main_str;
	char		*to_return_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 2048)
		return (NULL);
	main_str = get_next_line_main_logic(fd, main_str);
	if (!main_str)
		return (NULL);
	to_return_line = get_to_return_line_from_main_str(main_str);
	main_str = get_new_main_str(main_str);
	return (to_return_line);
}
