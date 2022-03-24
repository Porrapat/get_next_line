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

// 1. Read แล้วต่อ String เรื่อยๆ จนกว่าเจอ \n แล้ว Return ออกอันนึง จากนั้น Read ต่ออีก
// 1.1 เราต้องมีฟังก์ชันที่ใช้อะไรบ้าง

// ft_strchr ---> X ไม่ใช้
// ft_substr
// ft_strlcat ต่อสตริง เอาความยาวจากสตริง Len ทั้งคู่มาต่อกัน
// ft_strjoin ต่อสตริง ---> x ไม่ใช้
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

// ft_strlen()
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
		while(result = get_next_line(fd))
		{
			printf("%d. Line is %s*", round++, result);
			free(result);
		}
	}
	return (0);
}
