#pragma once
#ifndef _QUICK_H_
#define _QUICK_H_
#include"../Window/Window.h"
#include<stack>		//std::stack ( 引入栈 )
//快速
class Quick :private Window
{
public:
	Quick(size_t size);
	~Quick();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

Quick::Quick(size_t size)
{
	data = ((DATATYPE*) new DATATYPE[size]);
	this->len = size;
	this->swapTimes = 0;
	//赋值
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}

Quick::~Quick()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Quick 快排\n";
}

///原函数备份
//bool quickSort(int arr[], int left, int right) {
//	std::stack<int> stk;	// 用一个栈来保存待排序区间的左右边界
//	stk.push(left);
//	stk.push(right);
//
//	while (!stk.empty())	// 栈不为空时继续排序
//	{
//		int r = stk.top();	// 取出右边界
//		stk.pop();
//		int l = stk.top();	// 取出左边界
//		stk.pop();
//
//		int pivot = arr[(l + r) / 2];	// 选取中间元素作为基准值
//		int i = l, j = r;
//		while (i <= j)		// 双指针法进行划分
//		{
//			while (arr[i] < pivot) i++;
//			while (arr[j] > pivot) j--;
//			if (i <= j) {
//				std::swap(arr[i], arr[j]);
//				i++;
//				j--;
//			}
//		}
//
//		if (l < j)		// 如果左边区间还有未排序的部分，将其入栈
//		{
//			stk.push(l);
//			stk.push(j);
//		}
//		if (i < r)		// 如果右边区间还有未排序的部分，将其入栈
//		{
//			stk.push(i);
//			stk.push(r);
//		}
//	}
//	return true;
//}

bool quickSort(DATATYPE arr[], int left, int right) {
	static bool flag1, flag2, flag3;
	static std::stack<int> stk; // 用一个栈来保存待排序区间的左右边界
	static int r, l;
	static int pivot, i, j;
	if (flag3)
		goto goo;

	if (!flag1)
	{
		stk.push(left);
		stk.push(right);
		flag1 = true;
	}
	while (!stk.empty()) { // 栈不为空时继续排序
		if (!flag2)
		{
			r = stk.top(); // 取出右边界
			stk.pop();
			l = stk.top(); // 取出左边界
			stk.pop();
			pivot = arr[(l + r) / 2]; // 选取中间元素作为基准值
			i = l, j = r;
			flag2 = true;
		}
	goo:
		while (i <= j) { // 双指针法进行划分
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i <= j) {
				if (arr[i] != arr[j])//
					std::swap(arr[i], arr[j]);
				i++;
				j--;
				flag3 = true;
				return false;
			}
		}
		if (l < j) { // 如果左边区间还有未排序的部分，将其入栈
			stk.push(l);
			stk.push(j);
		}
		if (i < r) { // 如果右边区间还有未排序的部分，将其入栈
			stk.push(i);
			stk.push(r);
		}
		flag2 = flag3 = false;
	}
	flag1 = flag2 = flag3 = false;
	return true;
}


bool Quick::start()
{
	if (quickSort(data, 0, len - 1))
	{
		return true;
	}
	else
	{
		this->swapTimes++;
		return false;
	}
}

/*
* 快速排序折磨了我两天, 递归版本想要可视化难度太高, 索性让GPT 帮我写了
* 用了一个goto 跳转,实际上goto 确实是一个快捷方便的解决方案,
*/


#endif // !_QUICK_H_
