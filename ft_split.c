/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:57:10 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 09:25:17 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sublen;
	char	*substr;

	if (!s)
		return (NULL);
	sublen = ft_strlen(s) - start;
	if (sublen < len)
		len = sublen;
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (len > i)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	count_words(char const *s, char sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i] != sep && s[i] && ((s[i + 1] == sep) || (s[i + 1] == '\0')))
			len++;
		if (s[i] != sep && s[i])
			i++;
	}
	return (len);
}

static char	**ft_check(const char *s, char **all, char c)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
		{
			if (s[i] != c && s[i] && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			{
				all[x] = ft_substr(s, j, (i - j + 1));
				x++;
			}
			i++;
		}
	}
	all[x] = NULL;
	return (all);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**all;

	count = count_words(s, c) + 1;
	all = (char **)malloc(count * sizeof(char *));
	if (all == NULL)
		return (NULL);
	return (ft_check(s, all, c));
}
