#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define buffersize 100 
// 사용자 공백 입력 예제 문자열 입력전 공백 제거 문자사이 다수 공백 한개로 처리 문자뒤에공백 제거 출력 
//https://www.youtube.com/watch?v=7ucjJca3MB4&list=PL52K_8WQO5oXIATx2vcTvqwxXxoGxxsIz&index=3   출처

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
