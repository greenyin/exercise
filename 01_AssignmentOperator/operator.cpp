#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

class MyString{
	public:
		MyString():_ptr(NULL){}
		MyString(const char *str);
		MyString(const MyString& S);
		MyString& operator=(const MyString& S);
		~MyString();
	public:
		void Show()
		{
			cout<<this->_ptr<<endl;
		}
	private:
		char *_ptr;
};

MyString::MyString(const char *str)
{
	if(str == NULL){
		_ptr = new char[1];
		assert(_ptr);
		*_ptr = '\0';
	}else{
		int length = strlen(str);
		_ptr = new char[length+1];
		assert(_ptr);
		strcpy(_ptr,str);
	}
}

/*
MyString::MyString(const MyString& S)
{
	int length = strlen(S._ptr);
	_ptr = new char[length+1];
	strcpy(_ptr,S._ptr);
}
*/

MyString::MyString(const MyString& S):_ptr(NULL)
{
	MyString Tmp(S._ptr);
	char *p = _ptr;
	_ptr = Tmp._ptr;
	Tmp._ptr = p;
}


MyString& MyString::operator=(const MyString& S)
{
	if(this == &S)
		return *this;
	delete []_ptr;
	int length = strlen(S._ptr);
	_ptr = new char[length+1];
	strcpy(_ptr,S._ptr);
	return *this;
}
/*
MyString& MyString::operator=(const MyString& S)
{
	if(this != &S){
		MyString Tmp(S._ptr);
		char *p = _ptr;
		_ptr = Tmp._ptr;
		Tmp._ptr = p;
	}
	return *this;
}

MyString& MyString::operator=(MyString S)
{
	char *p = _ptr;
	_ptr = S._ptr;
	S._ptr = p;
	return *this;
}
*/

MyString::~MyString()
{
	delete []_ptr;
}


int main()
{
	MyString str1("hello");
	MyString str2(str1);
	MyString str3;
	str3 = str1;
	str1.Show();
	str2.Show();
	str3.Show();
	return 0;
}
