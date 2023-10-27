/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:22:07 by fde-mour          #+#    #+#             */
/*   Updated: 2023/04/18 15:27:17 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*var;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[j + start] != '\0' && j < len)
		j++;
	var = (char *)malloc(sizeof(char) * (j + 1));
	if (!var)
		return (0);
	while (s[start] != 0 && i < j)
	{
		var[i] = s[start];
		i++;
		start++;
	}
	var[i] = '\0';
	return (var);
}
