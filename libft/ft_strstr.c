/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:45:43 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 13:39:02 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (1)
	{
		j = 0;
		if (haystack[i] == needle[j])
			while (1)
			{
				if (!(haystack[i] && needle[j]))
					break ;
				else if (haystack[i] != needle[j])
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
