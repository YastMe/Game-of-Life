/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:55:27 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:48 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Reserves (using malloc(3)) an array of strings resulting from separating
	the string 's' in substrings using the character 'c' as delimiter. The
	array must end with a NULL pointer.

RETURN VALUE
	The array of new strings resulting from the separation. NULL if the
	memory reservation fails.
*/

#include "../../include/libft.h"

static	int	ft_count_words(char	*s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
		else
			i++;
	}
	return (words);
}

static	char	*ft_word_dup(char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = (char *) malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	**ft_safeguard(char	**split, int words)
{
	while (words >= 0)
	{
		free(split[words]);
		words--;
	}
	free (split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	int		i;
	char	*aux;

	words = ft_count_words((char *) s, c);
	split = (char **) malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	aux = (char *) s;
	while (i < words && *aux)
	{
		while (*aux == c && *aux)
			aux++;
		split[i] = ft_word_dup(aux, c);
		if (!split[i])
			return (ft_safeguard(split, i));
		i++;
		while (*aux != c && *aux)
			aux++;
	}
	split[i] = 0;
	return (split);
}
