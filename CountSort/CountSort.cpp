// CountSort.cpp : 定义控制台应用程序的入口点。
#include"iostream"
#include<assert.h>
using namespace std;
void CountSort(int *a, int size)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int *tmp = new int[range];
	memset(tmp, 0, sizeof(int)*range);
	//统计数字出现的次数
	for (int i = 0; i < size; i++)
	{
		tmp[a[i] - min]++;
	}
	//还原原始数组
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[index++] = i + min;
		}
	}
	delete []tmp;
}
int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	CountSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}