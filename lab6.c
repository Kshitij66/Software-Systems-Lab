#include<unistd.h>

int main()
{
	char mem[200];
	int values;

	values= read(STDIN_FILENO, mem, sizeof(mem));
	write(STDOUT_FILENO, mem, values);

	return 0;

}

