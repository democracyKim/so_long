/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:31:38 by minkim3           #+#    #+#             */
/*   Updated: 2022/12/09 19:26:41 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;

	count = 0;
	ptr = (unsigned char *)b;
	while (count < len)
	{
		*(ptr + count) = (unsigned char)c;
		count++;
	}
	return (b);
}
