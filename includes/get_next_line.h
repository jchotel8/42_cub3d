/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:32:03 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/28 12:24:01 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define SUCCESS_CODE_GNL 1
# define EOF_CODE_GNL 0
# define ERROR_CODE_GNL -1
# define BUFFER_SIZE 32

int				get_next_line(int fd, char **line);
int				contains_char(char *s, char c);
int				free_string_and_return(char **str, int return_value);
#endif
