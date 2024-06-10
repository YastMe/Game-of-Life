/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:27:37 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/29 11:53:56 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstrn(char *str);
int	ft_putptrn(__UINTPTR_TYPE__ ptr);
int	ft_putnbrn(int n);
int	ft_putunsignedn(unsigned int n);
int	ft_puthexn(unsigned int n, const char format);
int	ft_putpercentage(void);
int	ft_printf(char const *str, ...);

#endif