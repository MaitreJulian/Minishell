#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str != c)
		return (NULL);
	return ((char *)str);
}