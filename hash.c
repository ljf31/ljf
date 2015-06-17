#include <stdio.h>

unsigned long
hash(unsigned char *str)
{
 unsigned long hash = 5381;
 int c;

 while (c = *str++)
   hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

   return hash;
}

int main()
{
	char str[100];
	while (scanf("%s", str))
	{
		printf("hash value is %ul\n", hash(str));
	}
	
	return 0;
}
