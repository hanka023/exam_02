#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	char *str = argv[1];
	char *s;
	//char *start = str;

	int i = 0;
	int j = 0;
	int len = 0;

	while (str[i] != '\0')
		++i;
	
	len = i;
	s = malloc(sizeof (char ) * (len + 1));

	--i;
	while (i >= 0)
	{
		while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		{
			s[j] = str[i];
			--i;
			++j;	
		}
		s[j] = '\0';
		--j;
		while ( j >= 0)
		{
			write (1, &s[j], 1);
			--j;
		}
		j = 0;
		if (str[i] == ' ' || str[i] == '\t')
		{
			write (1, " ", 1);
			--i;
		}
		while  (str[i] == ' ' || str[i] == '\t')
			--i;
	}
	free (s);
	write (1, "\n", 1);
	return (0);
	
}


