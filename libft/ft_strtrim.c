/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:21 by mkirkgoz          #+#    #+#             */
/*   Updated: 2022/12/10 22:47:22 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*result;

	if (!s1 || !set)
		return (0);
	start = s1;
	end = start + ft_strlen(s1);
	while (ft_strchr(set, *start) != NULL && *start)
		start++;
	while (ft_strchr(set, *(end - 1)) != NULL && start < end)
		end--;
	result = ft_substr(start, 0, (end - start));
	return (result);
}
