/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 18:59:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_start(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	trim_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, (char *)s1 + start, end - start + 1);
	return (newstr);
}

// static int	is_set(char c, char *set)
// {
// 	int	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	len_str(char *s1, char *set)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (is_set(s1[i], set))
// 		i++;
// 	while (s1[i])
// 	{
// 		i++;
// 		len++;
// 	}
// 	i--;
// 	while (is_set(s1[i], set))
// 	{
// 		i--;
// 		len--;
// 	}
// 	return (len);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*str;

// 	if (!s1 || !set)
// 		return (NULL);
// 	if (!(*set))
// 		return (ft_strdup(s1));
// 	len = len_str((char *)s1, (char *)set);
// 	str = (char *) malloc (sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (is_set(s1[i], (char *)set))
// 		i++;
// 	j = 0;
// 	while (j < len)
// 	{
// 		str[j] = s1[i];
// 		i++;
// 		j++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }
// int main()
// {
//         char s1[] = " lorem ipsum dolor sit amet";
//         char    *dst;

//         dst = ft_strtrim(s1, "l ");
//         printf("%s\n", dst);
//         free(dst);
// }
