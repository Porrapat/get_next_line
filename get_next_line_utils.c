/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/13 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/13 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_realloc(char *s, size_t n)
{
	char	*res;

	res = (char *)malloc(n * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_memmove(res, s, ft_strlen(s));
	free(s);
	return (res);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
	{
		while (src[j] && (dst_len + j) < dstsize)
			dst[i++] = src[j++];
		if ((dst_len + j) == dstsize && dst_len < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (src_len + dst_len);
	}
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nh;
	size_t	nn;

	if (needle[0] == '\0')
		return ((char *) haystack);
	if (haystack[0] == '\0' || len == 0)
		return (NULL);
	nh = 0;
	nn = 0;
	while (1)
	{
		if (needle[nn] == '\0')
			return ((char *)(haystack + nh - nn));
		if (haystack[nh] == needle[nn])
			nn++;
		else
		{
			nh -= nn;
			nn = 0;
		}
		if (haystack[nh] == '\0' || (nh >= len && haystack[nh] != '\0'))
			return (NULL);
		nh++;
	}
}
