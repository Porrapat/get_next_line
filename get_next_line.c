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

static char	*make_result_str(int fd)
{
	static char	main_str[] = "1";
	char *result_str;
	char *pao_str = "23";

	result_str = malloc(ft_strlen(main_str) + 1);
	ft_memmove(result_str, main_str, ft_strlen(main_str) + 1);
	if (fd == -1)
		return (NULL);

	// // main_str = pao_str;
	// ft_strlen(main_str);
	// ft_strlen(pao_str);
	ft_strlcat(main_str, pao_str, ft_strlen(main_str) + ft_strlen(pao_str) + 1);
	
	// printf("----- In make_result_str -----\n");
	// printf("main_str = %s\n", main_str);
	
	// free(result_str);
	// return (NULL);
	return (result_str);
}

static char	*get_next_line_main_logic(int fd)
{
	char	*result_str;

	result_str = make_result_str(fd);
	return (result_str);
}

char	*get_next_line(int fd)
{
	char		*to_return_str;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	to_return_str = get_next_line_main_logic(fd);
	return (to_return_str);
}
