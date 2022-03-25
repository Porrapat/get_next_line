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
	int			return_bytes;
	char	*main_str;
	int			old_len;

	main_str = (char *)malloc(1);
	main_str[0] = '\0';
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);

	while(read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[BUFFER_SIZE] = '\0';

		old_len = ft_strlen(main_str);
		printf("old_len is %d\n", old_len);
		// ft_strlen(buff);
		main_str = ft_realloc(main_str, ft_strlen(buff) + ft_strlen(main_str) + 1);
		main_str[old_len] = '\0';
		
		ft_strlcat(main_str, buff, ft_strlen(buff) + ft_strlen(main_str) + 1);

		printf("-----\n");
	}

	free(buff);
	if(ft_strlen(main_str) > 0)
		return (main_str);
	else
	{
		free(main_str);
		return (NULL);
	}
		

	// return_bytes = 0;
	// buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// return_bytes = read(fd, buff, BUFFER_SIZE);
	// if (return_bytes == 0)
	// {
	// 	free(buff);
	// 	return (NULL);
	// }
	// buff[return_bytes] = '\0';
	// main_str = (char *)malloc(1);
	// main_str[0] = '\0';

	// while(ft_strnstr(buff, "\n", ft_strlen(buff) == NULL))
	// {
	// 	old_len = ft_strlen(main_str);
	// 	main_str = ft_realloc(main_str, ft_strlen(buff) + ft_strlen(main_str) + 1);
	// 	main_str[old_len] = '\0';
		
	// 	ft_strlcat(main_str, buff, ft_strlen(buff) + ft_strlen(main_str) + 1);

	// free(main_str);

	// free(buff);
	// while(ft_strnstr(buff, "\n", ft_strlen(buff) == NULL))
	// {
	// 	printf("No Find Newline\n");
	// 	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// 	return_bytes = read(fd, buff, BUFFER_SIZE);
	// 	if(return_bytes == 0)
	// 	{
	// 		free(buff);
	// 		return (NULL);
	// 	}
	// 	buff[return_bytes] = '\0';
	// }


	// return (buff);
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
		while(result = get_next_line(fd))
		{
			printf("%d. Line is %s*\n", round++, result);
			free(result);
		}
	}
	close(fd);
	return (0);
}



// 1. Read แล้วต่อ String เรื่อยๆ จนกว่าเจอ \n แล้ว Return ออกอันนึง จากนั้น Read ต่ออีก
// 1.1 เราต้องมีฟังก์ชันที่ใช้อะไรบ้าง

// ft_strchr ---> X ไม่ใช้
// ft_substr
// ft_strlcat ต่อสตริง เอาความยาวจากสตริง Len ทั้งคู่มาต่อกัน
// ft_strjoin ต่อสตริง ---> x ไม่ใช้
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)


// Story 1
// int		fd;
// char	*result;
// int		round;

// fd = 0;
// fd = open("files/mypao", O_RDWR);

// round = 1;
// if(fd != -1)
// {
// 	while(result = get_next_line(fd))
// 	{
// 		printf("%d. Line is %s*", round++, result);
// 		free(result);
// 	}
// }


// // Story 2
// int ret = 0;
// const char *src = "def";
// char *dst;

// dst = (char *)malloc(4);
// dst[0] = 'a';
// dst[1] = 'b';
// dst[2] = 'c';
// dst[3] = '\0';

// int old_len = ft_strlen(dst);
// dst = ft_realloc(dst, ft_strlen(src) + ft_strlen(dst) + 1);
// dst[old_len] = '\0';

// ret = ft_strlcat(dst, src, ft_strlen(src) + ft_strlen(dst) + 1);
// printf("dst is %s\n", dst);
// printf("ret is %d\n", ret);
// free(dst);

// // Story 3
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

// const char *myhay = "abcde\ndef\nghijk";

// // char *myhay;
// // myhay = (char *)malloc(16);
// // ft_memcpy(myhay, "abcde\ndef\nghijk", 16);

// char *temp;

// // printf("%s---", myhay);

// temp = ft_strnstr(myhay, "\n", ft_strlen(myhay));
// printf("+%s+", myhay);
// printf("+%s+", temp+1);
// // free(myhay);