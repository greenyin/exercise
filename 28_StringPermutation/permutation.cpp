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
//假设输入的pstr与pbegin都是"abc"
void Permutation(char *pstr,char *pbegin)
{
	if(*pbegin == '\0'){
		cout<<pstr<<endl;
	}else{
		char *pch = pbegin;
		for(;*pch != '\0';++pch){
			//第一步：交换
			//这三次循环分别得到的结果（交换后）：abc，bac，cba
			char tmp = *pch;
			*pch = *pbegin;
			*pbegin = tmp;

			//第二步：递归后面的字符
			//第一次循环的递归结果：bc 然后进入循环，交换后会得到：bc，cb
			//第二次循环的递归结果：ac 然后进入循环，交换后会得到：ac，ca
			//第三次循环的递归结果：ba 然后进入循环，交换后会得到：ba，ab
			Permutation(pstr,pbegin+1);

			//第三步：恢复交换
			//恢复交换的目的是为了下一次的循环不受影响
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
