#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	str1[] = "Hola Mundo!";
	char	*res;
	/*const char	str2[] = "Hola Mundo!";
	char	dest1[] = "EOE";
	char	dest2[] = "EOE";*/
	
	res = ft_strdup(str1);
	if (res == NULL)
	{
		printf("Error al copiar el string");
		return (1);
	}
	printf("%s\n", res);
	return (0);
}
