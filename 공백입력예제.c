#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define buffersize 100 
// ����� ���� �Է� ���� ���ڿ� �Է��� ���� ���� ���ڻ��� �ټ� ���� �Ѱ��� ó�� ���ڵڿ����� ���� ��� 
//https://www.youtube.com/watch?v=7ucjJca3MB4&list=PL52K_8WQO5oXIATx2vcTvqwxXxoGxxsIz&index=3   ��ó

int main()
{
	char buffer[buffersize];

	while (1)
	{
		printf("$ ");
		int len = readline(buffer, buffersize);
		printf("%s: %d\n ", buffer, len);
	}



	return 0;
}

int readline(char arra[], int arraylen)
{
	int ch, i = 0;
	while ((ch=getchar())!='\n')
	{
		if (i < arraylen - 1 && (!isspace(ch) || i>0 && !isspace(arra[i - 1]))) {
			arra[i++] = ch;
		}
	}
	if (i > 0 && isspace(arra[i-1]))
		i--;
	arra[i] = '\0';
	return i;
}
