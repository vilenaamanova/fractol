/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:09:17 by ncathy            #+#    #+#             */
/*   Updated: 2021/10/18 11:09:20 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*trm;

	if (s1 && set)
	{
		i = 0;
		while (s1 != '\0' && set_char(set, s1[i]))
			i++;
		len = ft_strlen(s1);
		while (len > i && set_char(set, s1[len - 1]))
			len--;
		j = 0;
		trm = (char *)malloc(sizeof(char) * (len - i + 1));
		if (!trm)
			return (NULL);
		while (i < len)
			trm[j++] = s1[i++];
		trm[j++] = '\0';
		return (trm);
	}
	return (NULL);
}
