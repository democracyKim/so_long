/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:16:53 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 12:59:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/so_long.h"

static int print_arg_error(void)
{
	error_exit("arg error\n");
	return (ERROR);
}

static int	validate_arg(int ac, char **av)
{
	int		index;
	char	*start;
	char	*slash;
	char	*str;
	
	index = 0;
	start = NULL;
	str = ".ber";
	if (ac != 2)
		return (print_arg_error());
	start = ft_strnstr(av[1], str, ft_strlen(av[1]));
	if (start == NULL)
		return (print_arg_error());
	if (start[4] != '\0')
		return (print_arg_error());
	slash = ft_strrchr(av[1], '/');
	if (slash == NULL)
		return (1);
	while (++slash != start)
	{
		if (*slash == '.')
			return (print_arg_error());
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (validate_arg(ac, av) == ERROR)
		return (0);
	so_long(av[1]);
	return (0);
}
