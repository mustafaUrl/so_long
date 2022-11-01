/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:13:23 by muraler           #+#    #+#             */
/*   Updated: 2022/03/14 10:13:32 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fstrjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*dizi;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dizi)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		dizi[i] = s1[i];
	a = -1;
	while (s2[++a] != '\0')
		dizi[i + a] = s2[a];
	dizi[i + a] = '\0';
	free (s1);
	return (dizi);
}

/*char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
*/