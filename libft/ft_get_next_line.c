/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:13:48 by muraler           #+#    #+#             */
/*   Updated: 2022/11/01 14:08:56 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*newline_after_line(char *str)
{
	int		sayac;
	int		sayaciki;
	char	*yeni_str;

	sayac = 0;
	sayaciki = 0;
	while (str[sayac] && str[sayac] != '\n')
		sayac++;
	if (!str[sayac])
	{
		free(str);
		return (0);
	}
	yeni_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - sayac + 1));
	if (!yeni_str)
		return (0);
	sayac++;
	while (str[sayac])
		yeni_str[sayaciki++] = str[sayac++];
	yeni_str[sayaciki] = '\0';
	free(str);
	return (yeni_str);
}

char	*newline_before_line(char *str)
{
	int		sayac;
	char	*yeni_str;

	sayac = 0;
	if (!str[sayac])
		return (0);
	while (str[sayac] != '\n' && str[sayac] != '\0')
		sayac++;
	yeni_str = (char *)malloc(sizeof(char) * (sayac + 2));
	if (!yeni_str)
		return (0);
	sayac = 0;
	while (str[sayac] && str[sayac] != '\n')
	{
		yeni_str[sayac] = str[sayac];
		sayac++;
	}
	if (str[sayac] == '\n')
	{
		yeni_str[sayac] = str[sayac];
		sayac++;
	}
	yeni_str[sayac] = '\0';
	return (yeni_str);
}

char	*put_line(int fd, char *line)
{
	char	*buff;
	int		readss;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	readss = 1;
	while (!ft_strchr(line, '\n') && readss != 0)
	{
		readss = read(fd, buff, BUFFER_SIZE);
		if (readss == -1)
		{
			free(buff);
			return (0);
		}
		buff[readss] = '\0';
		line = fstrjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = put_line(fd, line);
	if (line)
	{	
		s = newline_before_line(line);
		line = newline_after_line(line);
		return (s);
	}
	return (0);
}
