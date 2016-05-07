#include <iostream>
using namespace std;

void ReOrder(int *pData,unsigned int length)
{
	if(pData == NULL || length <= 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData+length-1;
	while(pBegin < pEnd){
		while(pBegin<pEnd && (*pBegin & 0x1)!=0)
			pBegin++;
		while(pBegin<pEnd && (*pEnd & 0x1)==0)
			pEnd--;

		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//thinking about extension...

void ReOrder(int *pData,unsigned int length)
{
	if(pData == NULL || length <= 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData+length-1;
	while(pBegin < pEnd){
		while(pBegin<pEnd && !func(*pBegin))
			pBegin++;
		while(pBegin<pEnd && func(*pEnd))
			pEnd--;

		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n&0x1)==0;
}

//thinking about order 
//bubble
void ReOrderBubble(int *pData,unsigned int length)
{
	if(pData == NULL || length <= 0)
		return;
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1;j++){
			if((pData[j]&0x1 == 0) &&(pData[j+1]&0x1 != 0)){
				int tmp = pData[j];
				pData[j] = pData[j+1];
				pData[j+1] = tmp;
			}
		}
	}
}
