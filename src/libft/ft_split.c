/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:15:21 by hchartie          #+#    #+#             */
/*   Updated: 2025/11/24 15:26:56 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numwords(char const *s, char c);
static int	ft_split_words(char **res, char const *s, char c, int word);
static void	free_all(char	**strs, size_t	idx);

/**
 * @brief Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char** The array of new strings resing from the split.
NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_numwords(s, c) + 1));
	if (!res)
		return (NULL);
	if (!ft_split_words(res, s, c, 0))
		return (NULL);
	return (res);
}

static int	ft_numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

static int	ft_split_words(char **res, char const *s, char c, int word)
{
	int		start_cur;
	int		end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur])
	{
		if (s[end_cur] == c || s[end_cur] == 0)
			start_cur = end_cur + 1;
		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
		{
			res[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!res[word])
			{
				free_all(res, word);
				return (0);
			}
			ft_strlcpy(res[word], (s + start_cur), end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	res[word] = 0;
	return (1);
}

static void	free_all(char	**strs, size_t	idx)
{
	while (strs[idx - 1] && strs)
	{
		free(strs[idx]);
		idx--;
	}
	free(strs);
}
