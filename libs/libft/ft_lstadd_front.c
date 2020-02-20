/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:33:35 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:25:59 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
}
