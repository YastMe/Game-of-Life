/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:35:30 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/16 18:35:57 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_readint(char	*prompt)
{
	char	*line;
	int		ret;

	if (prompt)
		ft_printf(prompt);
	line = get_next_line(STDIN_FILENO);
	ret = ft_atoi(line);
	free(line);
	return (ret);
}
