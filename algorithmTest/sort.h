/*************************************************************************
	> File Name: sort.cpp
	> Author: sjh
	> Mail: sjh_qdu@163.com 
	> Created Time: 2018年05月14日 星期一 20时21分59秒
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;


/************BubbleSort*************
分类-----------------------内部比较排序
数据结构-------------------数组
最差时间复杂度-------------O(n^2)
最优时间复杂度-------------如果能在内部循环第一次运行时，使用一个旗标表示有无交换的可能，可以把最优时间复杂度降到O(n)
平均时间复杂度-------------O(n^2)
所需辅助空间---------------O(1)
稳定性---------------------稳定
************************************/
void BubbleSort(vector<int> &arry)
{
	for(vector<int>::iterator j = arry.begin(); j !=arry.end() - 1; ++j){
		for(vector<int>::iterator i = arry.begin(); i != arry.end() - 1; ++i){
			if(*i > *(i + 1))
				swap(*i,*(i + 1));		//如果条件改变成A[i] >= A[i+1]，则变为不稳定的排序算法
		}
	}
}

/***********鸡尾酒排序************
 *分类---------------------内部比较排序
 数据结构------------------数组
 最差时间复杂度------------O(n^2)
 最优时间复杂度------------如果序列一开始已经大部分排序过的话，会接近O(n)
 平均时间复杂度------------O(n^2)
 所需辅助空间--------------O(1)
 稳定性--------------------稳定
*********************************/

void CocktailSort(vector<int> &arry)
{
	int left = 0;
	int right = arry.size() - 1;
	while(left < right){
		for(int i = left; i < right; ++i){
			if(arry[i] > arry[i + 1])
				swap(arry[i],arry[i + 1]);
		}
		right--;
		for(int i = right; i > left; --i){
			if(arry[i] < arry[i - 1])
				swap(arry[i],arry[i - 1]);
		}
		left++;
	}
}
