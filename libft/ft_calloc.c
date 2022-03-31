/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:36 by ncathy            #+#    #+#             */
/*   Updated: 2021/10/18 11:05:39 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return ((void *)str);
}
