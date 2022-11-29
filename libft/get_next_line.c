/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:37:20 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/24 13:37:34 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *buff)
{
	char	*newbuff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newbuff = ft_calloc((ft_strlen_gnl(buff) - i + 1), 1);
	i++;
	while (buff[i])
		newbuff[j++] = buff[i++];
	free(buff);
	return (newbuff);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
		line = ft_calloc (i + 1, 1);
	else if (buff[i] == '\n')
		line = ft_calloc (i + 2, 1);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_fd(int fd, char *buff)
{
	char	*temp;
	char	*str;
	int		n;

	if (!buff)
		buff = ft_calloc(1, 1);
	n = 1;
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	while (n > 0 && !ft_strchr_gnl(str, '\n'))
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n == -1)
		{
			free(str);
			return (NULL);
		}
		str[n] = '\0';
		temp = ft_strjoin_gnl(buff, str);
		free(buff);
		buff = temp;
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff != NULL)
			free (buff);
		buff = NULL;
		return (NULL);
	}
	buff = ft_read_fd(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	buff = ft_next(buff);
	return (line);
}
