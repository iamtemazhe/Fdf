/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:13:03 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 14:00:05 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= n)
	{
		j = 0;
		if (haystack[i] == needle[j])
			while (i < n)
			{
				if (!(haystack[i] && needle[j]) || \
					haystack[i] != needle[j])
					break ;
				i++;
				j++;
			}
		if (!needle[j])
			return (char*)(haystack + i - j);
		if (!haystack[i])
			break ;
		i -= j;
		i++;
	}
	return (NULL);
}
