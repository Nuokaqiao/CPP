/*************************************************************************
	> File Name: main.cpp
	> Author: sjh
	> Mail: sjh_qdu@163.com 
	> Created Time: 2018年05月14日 星期一 21时50分02秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

int main()
{
	int A[8] = {6,5,3,1,8,7,2,4};
	vector<int> arry(A,A+8);	
	//BubbleSort(arry);
	CocktailSort(arry);
	std::cout<< "鸡尾酒：";
	for(vector<int>::iterator it = arry.begin(); it != arry.end(); ++it)
		cout << *it;
	cout << endl;
	return 0;
}
