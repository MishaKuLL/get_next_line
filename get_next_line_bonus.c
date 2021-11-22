/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:46:33 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 12:46:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(*str) * size);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

int	check_null_terminated_string(char **str)
{
	if ((*str)[0] == '\0')
	{
		ft_strdel(str);
		return (1);
	}
	return (0);
}

char	*trim_line(char **raw_str)
{
	t_trim_data	data;

	data.len = 0;
	if (check_null_terminated_string(raw_str) == 1)
		return (NULL);
	while ((*raw_str)[data.len] && (*raw_str)[data.len] != '\n')
		data.len++;
	if ((*raw_str)[data.len] == '\n')
	{
		data.line = ft_substr(*raw_str, 0, data.len + 1);
		data.tmp = ft_strdup(&(*raw_str)[data.len + 1]);
		free(*raw_str);
		if (data.tmp)
		{
			*raw_str = ft_strdup(data.tmp);
			free(data.tmp);
		}
		check_null_terminated_string(raw_str);
	}
	else
	{
		data.line = ft_strdup(*raw_str);
		ft_strdel(raw_str);
	}
	return (data.line);
}

char	*get_next_line(int fd)
{
	t_gnl_data	data;
	static char	*raw_str[MAX_FD];

	if (fd < 0 || read(fd, data.buff, 0) == -1)
		return (NULL);
	if (raw_str[fd] == NULL)
		raw_str[fd] = ft_strnew(0);
	while (ft_strchr(raw_str[fd], '\n') == NULL \
			|| ft_strchr(raw_str[fd], '\0') == NULL)
	{
		data.bytes_read = read(fd, data.buff, BUFFER_SIZE);
		data.buff[data.bytes_read] = '\0';
		if (data.bytes_read == 0)
			return (trim_line(&raw_str[fd]));
		data.tmp = ft_strjoin(raw_str[fd], data.buff);
		free(raw_str[fd]);
		raw_str[fd] = ft_strdup(data.tmp);
		free(data.tmp);
	}
	return (trim_line(&raw_str[fd]));
}
