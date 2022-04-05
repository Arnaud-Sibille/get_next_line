/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:50 by asibille          #+#    #+#             */
/*   Updated: 2022/01/31 11:26:38 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[256];
	char		*str;
	int			ret;

	if (BUFFER_SIZE < 0 || (fd < 0) || (fd > 255))
		return (NULL);
	str = NULL;
	if (buf[fd])
		str = ft_buf_to_str_newbuf(&buf[fd]);
	while (!str)
	{
		buf[fd] = ft_strjoin_buffer(buf[fd]);
		ret = read(fd, &buf[fd][ft_strlen(buf[fd])], BUFFER_SIZE);
		if (ret == -1)
			return (ft_no_read_case(&buf[fd]));
		else if (ret == 0)
		{
			str = ft_nul_return(&buf[fd]);
			return (str);
		}
		else
			str = ft_buf_to_str_newbuf(&buf[fd]);
	}
	return (str);
}

char	*ft_buf_to_str_newbuf(char **buf)
{
	char	*str;
	char	*buf_cpy;
	int		i;

	i = 0;
	buf_cpy = *buf;
	while (*buf_cpy)
	{
		if (*buf_cpy == '\n')
		{
			str = *buf;
			buf_cpy = ft_strdup(buf_cpy + 1);
			str[i + 1] = 0;
			*buf = buf_cpy;
			return (str);
		}
		++(buf_cpy);
		++i;
	}
	return (NULL);
}

char	*ft_nul_return(char **buf)
{
	char	*buf_cpy;
	char	*str;

	buf_cpy = *buf;
	if (ft_strlen(buf_cpy))
	{
		str = buf_cpy;
		*buf = NULL;
		return (str);
	}
	else
	{
		free(buf_cpy);
		*buf = NULL;
		return (NULL);
	}
}

char	*ft_no_read_case(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (NULL);
}
