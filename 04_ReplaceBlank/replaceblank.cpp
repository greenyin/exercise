#include <iostream>
#include <string.h>
using namespace std;

void replaceSpace(char *str,int length)
{
	int numofspace = 0;
	char *cur = str;
	while(*cur){
		if(*cur == '')
			numberofspace++;
		cur++;
	}
	int remove_len = 2*numofspace;
	char *front = str + length;
	char *rear = str+length+remove_len;
	while(front < rear){
		if(*front != ' '){
			*rear-- = *front--;
		}else{
			*rear-- = '0';
			*rear-- = '2';
			*rear-- = '%';
			front--;
		}
	}
}

int main()
{
	const int length = 100;
	char string[length] = "hello world";
    replaceSpace(string,strlen(string));
	return 0;
}
