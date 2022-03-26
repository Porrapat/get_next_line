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

static char	*make_result_str(int fd)
{
	if (fd)
		return (NULL);
	return (NULL);
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
