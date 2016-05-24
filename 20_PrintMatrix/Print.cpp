#include <iostream>
using namespace std;


void PrintMatrix(int **numbers,int columns,int rows)
{
	if(numbers == NULL || columns==0 || rows==0)
		return;
	int start=0;
	//一圈一圈的打印
	while(columns > start*start && rows > start*start){
		int endX = rows - start - 1;//终止行
		int endY = columns - start - 1;//终止列
		for(int i=start;i<=endX;i++)//从左到右打印
			cout<<numbers[start][i]<<" ";
		if(endY > start){//从上到下打印的条件
			for(int i=start+1;i<=endY;i++)//打印
				cout<<numbers[i][endY]<<" ";
		}
		if(endX > start && start < endY){//从右向左打印的条件
			for(int i=endX-1;i>=start;i--)//打印
				cout<<numbers[endY][i]<<" ";
		}
		if(start < endY-1 && start < endX){//从下向上打印的条件
			for(int i=endY -1;i>start;i--)//打印
				cout<<numbers[i][start]<<" ";
		}
		start++;//里面一圈
	}
	cout<<endl;
}
int main()
{
	int columns,rows;
	cout<<"column : ";
	cin>>columns;
	cout<<"\nrows : ";
	cin>>rows;
	int **numbers = new int*[rows];
	for(int i=0;i<rows;++i){
		numbers[i] = new int[columns];
		for(int j=0;j<columns;++j){
			numbers[i][j] = i*columns + j + 1;
		}
	}
	//int numbers[4][4] = {
	//	{1,2,3,4},
	//	{5,6,7,8},
	//	{9,10,11,12},
	//	{13,14,15,16}
	//};
	PrintMatrix(numbers,columns,rows);
    
	for(int i=0;i<rows;++i)
	    delete [](int*)numbers[i];

	delete []numbers;
	return 0;
}
