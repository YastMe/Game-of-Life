/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:32:48 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/16 18:42:32 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_readline(const char *prompt)
{
	char	*ret;

	if (prompt)
		ft_printf(prompt);
	ret = get_next_line(STDIN_FILENO);
	return (ret);
}
