/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:07:33 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/27 17:42:09 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	*mgrant(int size)
{
	void	*memory_alloc;

	memory_alloc = malloc(size);
	if (!memory_alloc)
		farewell(NULL, 2);
	else
		return (memory_alloc);
}

void	set_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 1);
	if (fd == -1)
		farewell(NULL, 3);
	return (fd);
}
