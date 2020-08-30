
#include <stdio.h>
 
void foo(char**);

int main(void)
{
	char* ch[] = { "12", "34", "56", "78", "90", "ab" };
	foo(ch);
	return 0;
}

void foo(char** pp)
{
	char* ch;
	ch = (pp += sizeof(int))[-1];
	printf("%s", ch);
}
