/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:29:31 by akahir            #+#    #+#             */
/*   Updated: 2025/01/19 18:40:36 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	int	over_flow(int signe)
{
	if (signe == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	result;
	unsigned long long	max;

	signe = 1;
	i = 0;
	result = 0;
	max = 9223372036854775807;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (max - (str[i] - '0')) / 10)
			return (over_flow(signe));
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	return (result * signe);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	free_memory(char **ptr, size_t count)
{
	size_t	k;

	k = 0;
	while (k < count)
	{
		free(ptr[k]);
		k++;
	}
	free(ptr);
}

static size_t	skip_delimiters(const char *s, size_t i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int	handle_word(const char *s, size_t *i, char **ptr, char c)
{
	size_t	len_words;
	size_t	j;

	len_words = 0;
	if (s[*i] != c)
	{
		while (s[*i + len_words] && s[*i + len_words] != c)
			len_words++;
		*ptr = (char *)malloc((len_words + 1) * sizeof(char));
		if (!*ptr)
			return (0);
		j = 0;
		while (j < len_words)
		{
			(*ptr)[j] = s[*i + j];
			j++;
		}
		(*ptr)[j] = '\0';
		*i += len_words;
		return (1);
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	stock;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = skip_delimiters(s, 0, c);
	stock = 0;
	while (s[i])
	{
		if (handle_word(s, &i, &ptr[stock], c))
			stock++;
		else
		{
			free_memory(ptr, stock);
			return (NULL);
		}
		i = skip_delimiters(s, i, c);
	}
	ptr[stock] = NULL;
	return (ptr);
}
