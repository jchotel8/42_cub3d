/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:36:34 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:25:59 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		contains_char(char *s, char c)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] == c)
			return (SUCCESS_CODE_GNL);
		index++;
	}
	return (0);
}

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	unsigned int	len;
	unsigned int	index;

	index = 0;
	len = ft_strlen(dest);
	while (src[index] && index < nb)
		dest[len++] = src[index++];
	dest[len] = 0;
	return (dest);
}

char	*ft_strnew(size_t n)
{
	char	*string;
	int		index;

	if (!(string = (char *)malloc(n + 1)))
		return (NULL);
	index = 0;
	string[index] = 0;
	while (index < n)
		string[index++] = 0;
	return (string);
}

int		free_string_and_return(char **string, int val)
{
	if (*string)
		free(*string);
	*string = NULL;
	return (val);
}
