/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:23:56 by asibille          #+#    #+#             */
/*   Updated: 2022/01/31 11:20:56 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_buf_to_str_newbuf(char **buf);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_buffer(char *s1);
char	*ft_nul_return(char **buf);
char	*ft_no_read_case(char **buf);

#endif
