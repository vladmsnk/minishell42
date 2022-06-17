/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:09:14 by jjhezane          #+#    #+#             */
/*   Updated: 2022/05/23 12:58:47 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;

	if (s)
	{
		if (start >= ft_strlen(s))
		{
			sub_str = (char *)malloc(sizeof(char));
			if (!sub_str)
				return (NULL);
			*sub_str = '\0';
			return (sub_str);
		}
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub_str)
			return (NULL);
		ft_strlcpy(sub_str, s + start, len + 1);
		return (sub_str);
	}
	return (NULL);
}
