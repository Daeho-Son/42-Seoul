/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:50:00 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:51:18 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**free_words(char **words)
{
	size_t	index;

	index = 0;
	while (words[index])
	{
		free(words[index]);
		index++;
	}
	free(words);
	return (NULL);
}

static size_t	get_words_count(char const *s, char c)
{
	size_t	words_count;
	size_t	index;

	index = 0;
	words_count = 0;
	while (s[index])
	{
		if (s[index] != c && (index == 0 || s[index - 1] == c))
			words_count++;
		index++;
	}
	return (words_count);
}

static char	**fill_words(char **words, char const *s, char c)
{
	size_t			w_index;
	size_t			index;
	unsigned int	start;
	size_t			len;

	w_index = 0;
	index = 0;
	start = 0;
	while (s[index])
	{
		if (s[index] != c && (index == 0 || s[index - 1] == c))
		{
			len = 0;
			start = index;
			while ((s[start + len] != c) && (s[start + len] != '\0'))
				len++;
			words[w_index] = ft_substr(s, start, len);
			if (!words[w_index])
				return (free_words(words));
			w_index++;
		}
		index++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = get_words_count(s, c);
	words = (char **)ft_calloc(words_count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	fill_words(words, s, c);
	return (words);
}
