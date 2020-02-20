/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:34:07 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:25:59 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*returned_string;

	index = 0;
	if (!(returned_string = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[index])
	{
		returned_string[index] = s1[index];
		index++;
	}
	returned_string[index] = '\0';
	return (returned_string);
}
