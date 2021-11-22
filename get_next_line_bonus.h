/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:46:29 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 12:46:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef	MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_gnl_data
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;
}t_gnl_data;

typedef struct s_trim_data
{
	int		len;
	char	*line;
	char	*tmp;
}t_trim_data;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);

#endif
