/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:43:33 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/16 10:02:15 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *full_str, char *buffer);
char	*ft_get_line_gnl(char *full_str);
char	*ft_get_remain_gnl(char *full_str);
char	*get_next_line(int fd);

#endif
