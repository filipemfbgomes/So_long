/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:20:30 by fde-mour          #+#    #+#             */
/*   Updated: 2023/04/28 11:31:28 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(char const *s, char c)
{
	int		i;
	int		word;
	int		is_word;

	i = 0;
	word = 0;
	is_word = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && is_word == 1)
		{
			word = word + 1;
			is_word = 0;
		}
		else if (s[i] == c && is_word == 0)
			is_word = 1;
		i++;
	}
	return (word);
}

int	ft_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_fill(int words, char *s, char **ptr, char c)
{
	int	i;
	int	sep;
	int	len;

	sep = 0;
	i = 0;
	while (sep < words)
	{
		i = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		s = s + i;
		len = ft_char(s, c);
		ptr[sep] = ft_substr(s, 0, len);
		if (ptr[sep] == NULL)
			return (NULL);
		s = s + len;
		sep++;
	}
	ptr[sep] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**var;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	var = (char **)malloc((sizeof(char *)) * (words + 1));
	if (!var)
		return (NULL);
	var = ft_fill(words, (char *)s, var, c);
	return (var);
}

/*int	main(void)
{
	char *test = {"Boas,,,Gabriel"};
	char **res;
	res = ft_split(test, ',');
	int	i;
	i = 0;
	while (i < 2)
	{
		printf("%s\n", res[i]);
		i++;	
	}
	return (0);
}*/