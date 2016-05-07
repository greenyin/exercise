#include <iostream>
using namespace std;

bool FindInMatrix(int matrix[][],int rows,int columns,int val)
{
	bool found = false;

	if(matrix != NULL && rows > 0 && column > 0){
		int i = 0;
		int j = columns - 1;
		while(i >= 0 && j < column){
			if(val > matrix[i][j]){
				j++;
			}else if(target < array[i][j]){
				i--;
			}else{
				found = true;
			}
		}
	}
	return found;
}

int main()
{
	return 0;
}
