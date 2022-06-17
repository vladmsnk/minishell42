#include "includes/headers.h"
#include "includes/structs.h"

unsigned int	count_words(const char *str, char c)
{
	unsigned int	i;
	unsigned int	quote;
	unsigned int	wcnt;

	i = 0;
	quote = 0;
	wcnt = 0;
	while (str[i] != '\0')
	{
		if (!quote && str[i] == '"')
			quote++;
		else if (!quote && str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			wcnt++;
		else if (quote == 1 && str[i] == '"')
		{
			wcnt++;
			quote--;
		}
		i++;
	}
	return (wcnt);
}


static char	**clear(char **splitted, unsigned int n)
{
	unsigned int	iter;

	iter = 0;
	if (n > 0)
	{
		while (iter < n)
			free(splitted[iter++]);
	}
	free(splitted);
	return (NULL);
}



static char	**get_words(char **splitted, char const *s, char c)
{
	int				bgn;
	unsigned int	iter;
	unsigned int	n;
	unsigned int	quote;

	bgn = -1;
	quote = 0;
	n = 0;
	iter = 0;
	while (iter <= ft_strlen(s))
	{
		if (s[iter] != c && bgn == -1)
			bgn = iter;
		if (!quote && s[iter] == '"')
			quote++;
		else if (bgn != -1 && !quote && (s[iter] == c || s[iter] == '\0'))
		{
			*(splitted + n) = (char *)malloc(sizeof(char) * (iter - bgn + 1));
			if (!(*(splitted + n)))
				return (clear(splitted, n));
			ft_strlcpy(*(splitted + n), s + bgn, iter - bgn + 1);
			bgn = -1;
			n++;
		}
		else if (bgn != -1 && (quote && s[iter] == '"'))
		{
			*(splitted + n) = (char *)malloc(sizeof(char) * (iter - bgn + 2));
			if (!(*(splitted + n)))
				return (clear(splitted, n));
			ft_strlcpy(*(splitted + n), s + bgn, iter - bgn + 2);
			quote--;
			bgn = -1;
			n++;
		}
		iter++;
	}
	*(splitted + n) = NULL;
	return (splitted);
}

char    **ft_qsplit(const char *input_str, char c)
{
	unsigned int	word_cnt;
	char			**splitted;

	word_cnt = count_words(input_str, c);
	splitted = (char **)malloc(sizeof(char *) * word_cnt);
	if (!splitted)
		return (NULL);
	return (get_words(splitted, input_str, c));
}
