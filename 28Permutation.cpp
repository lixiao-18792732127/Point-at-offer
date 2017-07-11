#include<iostream>
using namespace std;

void Permutation(char* Str, char* Begin)
{
	if (Begin == '\0')
	{
		printf("%s\n", Str);
	}
	else
	{
		for (char* ch = Begin; *ch != '\0'; ++ch)
		{
			char tmp = *ch;
			*ch = *Begin;
			*Begin = tmp;
			Permutation(Str, Begin + 1);
			tmp = *ch;
			*ch = *Begin;
			*Begin = tmp;
		}
	}
}

void Permutation(char* Str)
{
	if (Str == NULL)
	{
		return;
	}
	Permutation(Str, Str);
}