#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

static char		*ft_z_ia(int n)
{
	char	s[12];
	int		i;
	long	nl;

	nl = n;
	i = 0;
	while (nl)
	{
		s[i++] = nl % 10 + '0';
		nl /= 10;
	}
	if(n < 10)
		s[i] = '0';
	s[++i] = '\0';
	ft_strreverse(s);
	return (ft_strdup(s));
}


char				**free_mx(char ***arr)
{
	char			**tmp;

	tmp = *arr;
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		free(*tmp);
		*tmp++ = NULL;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

int					fill_mx(char **ar, int num)
{
	char	*x;
	char 	*y;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	j = 1;
	if (!ar)
		return (0);

	while(*(ar + count))
	{
		printf("**ar=%p\n", *(ar + count));
		if (!(x = ft_z_ia(i)))
			return (0);
		if (!(y = ft_z_ia(j)))
			return (0);
	//	ft_strncpy(*(ar + count), x, 2);
	//	printf("x=%s, y=%s\n",x, y);
	//	 ft_strncpy(*(ar + count + 2), y, 2);
	//	 printf("ar+count=%s\n",*(ar + count));
        if (!(*(ar + count) = ft_strncpy(*(ar + count), x, 5)))
            return (0);
	    printf("ar+count=%s\n",*(ar + count));
        getchar();
        *(ar + count) = ft_strcat(*(ar + count), y);
	    printf("ar+count=%s\n",*(ar + count));
        getchar();
		free(x);
		free(y);
		if (j++ > num)
		{
			j = 1;
			++i;
		getchar();
		}
		++count;
		printf("i=%d, j=%d, count=%d\n", i, j, count);

	}
	return (1);
}

char				**create_ch(char ***new, int num)
{
	char			**tmp;
	int				count;

	count = (num * num);
	if (!(*new = (char**)malloc((count + 1) * sizeof(char*))))
		return (NULL);
	tmp = *new;
	while (count--)
	{
		if (!(*(*new)++ = (char*)malloc(5 * sizeof(char))))
		{
			free_mx(&tmp);
			return (NULL);
		}
	}
    printf("cr_ch=%d\n", num * num + 1);
	*(*new) = NULL;
	return (tmp);
}

int main()
{
    char **ch = create_ch(&ch, 5);
    fill_mx(ch, 7);
}