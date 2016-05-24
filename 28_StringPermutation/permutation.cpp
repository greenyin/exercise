#include <iostream>
using namespace std;

void Permutation(char *pstr,char *pbegin);

void Permutation(char *pstr)
{
	if(pstr == NULL)
		return;
	Permutation(pstr,pstr);
}

//用递归的方式
void Permutation(char *pstr,char *pbegin)
{
	if(*pbegin == '\0'){
		cout<<pstr<<endl;
	}else{
		char *pch = pbegin;
		for(;*pch != '\0';++pch){
			char tmp = *pch;
			*pch = *pbegin;
			*pbegin = tmp;

			Permutation(pstr,pbegin+1);

			tmp = *pch;
			*pch = *pbegin;
			*pbegin = tmp;
		}
	}
}

int main()
{
	char str[1] = {'\0'};
	char str0[] = "a";
	char str1[] = "ab";
	char str2[] = "abc";
	Permutation(str);
	cout<<endl;
	Permutation(str0);
	cout<<endl;
	Permutation(str1);
	cout<<endl;
	Permutation(str2);
	cout<<endl;
	return 0;
}
