#pragma once
#ifndef _HAIF_INSERTION_H_
#define _HAIF_INSERTION_H_
#include"../Window/Window.h"
// 折半插入
class HalfInsertion :private Window
{
public:
	HalfInsertion(size_t size);
	~HalfInsertion();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

HalfInsertion::HalfInsertion(size_t size)
{
	data = ((DATATYPE*) new DATATYPE[size]);
	this->len = size;
	this->swapTimes = 0;
	for (size_t i = 0; i < size; i++)//赋值
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}
HalfInsertion::~HalfInsertion()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Half insertion 折半插入\n";
}

/**
 * 使用折半插入排序对数组进行排序
 * @param arr 待排序的数组
 * @param len 数组的长度
 * @param last 排序的起始位置，即上次排序的进度
 * @return 如果数组已经完全排序，则返回true，否则返回false
 */
 /*
 bool binaryInsertionSort(int arr[], int len, int last) {
	 bool sorted = true; // 标记数组是否已经完全排序
	 int start = (last == 0) ? 1 : last + 1; // 计算排序的起始位置
	 for (int i = start; i < len; i++) {
		 int temp = arr[i]; // 将当前位置的值保存到临时变量中
		 int left = 0, right = i - 1; // 初始化折半查找的左右边界
		 while (left <= right) {
			 int mid = (left + right) / 2; // 计算中间位置
			 if (arr[mid] > temp) { // 如果当前位置的值比临时变量的值大
				 right = mid - 1; // 将右边界缩小到中间位置左侧
			 }
			 else { // 如果当前位置的值比临时变量的值小或相等
				 left = mid + 1; // 将左边界扩大到中间位置右侧
			 }
		 }
		 // 将[left, i-1]范围内的所有元素向右移动一个位置
		 for (int j = i - 1; j >= left; j--) {
			 arr[j + 1] = arr[j];
			 sorted = false; // 标记数组未完全排序
		 }
		 arr[left] = temp; // 将临时变量插入到正确的位置
		 if (left != i) { // 如果发生了数据交换
			 sorted = false; // 标记数组未完全排序
			 return false; // 返回false
		 }
	 }
	 return sorted;
 }
 */

 //弃用 (GPT 写的
/*
bool binaryInsertionSort2(int arr[], int len, int last)
{
	bool sorted = true;						// 标记数组是否已经完全排序
	int start = (last == 0) ? 1 : last + 1; // 计算排序的起始位置
	for (int i = start; i < len; i++)
	{
		int temp = arr[i];					// 将当前位置的值保存到临时变量中
		int left = 0, right = i - 1;		// 初始化折半查找的左右边界
		while (left <= right)
		{
			int mid = (left + right) / 2;	// 计算中间位置
			if (arr[mid] > temp)
			{						// 如果当前位置的值比临时变量的值大
				right = mid - 1;	// 将右边界缩小到中间位置左侧
			}
			else
			{						// 如果当前位置的值比临时变量的值小或相等
				left = mid + 1;		// 将左边界扩大到中间位置右侧
			}
		}
		// 将[left, i-1]范围内的所有元素向右移动一个位置
		for (int j = i - 1; j >= left; j--)
		{
			//arr[j + 1] = arr[j];
			std::swap(arr[j + 1], arr[j]);
			return sorted = false; // 标记数组未完全排序
		}
		//arr[left] = temp; // 将临时变量插入到正确的位置
		if (left != i)
		{ // 如果发生了数据交换
			sorted = false; // 标记数组未完全排序
			return false; // 返回false
		}
	}
	return sorted;
}
*/

/**
 * 折半插入排序
 * @param arr 待排序的整数数组
 * @param n 数组的长度
 * @return 排序完成后返回true
 */
bool binaryInsertionSort(int arr[], int n) {

	static bool flag;
	static int i = 1, j = 1;
	static int key, left, right, mid, min;

	// 从第二个元素开始遍历数组
	for (; i < n; ) {
		if (flag)
			goto F1;
		// 保存当前要插入的元素
		key = arr[i];
		// 定义左右边界
		left = 0, right = i - 1;
		// 二分查找插入位置
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] > key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		// 将插入位置后面的元素后移一位
		if (!flag)
		{
			j = i - 1;
		}
	F1:
		for (; j >= left; ) {
			arr[j + 1] = arr[j];
			flag = true;
			j--;
			return false;
		}
		// 将元素插入到正确的位置
		arr[left] = key;
		flag = false;
		i++;
		return false;
	}
	i = 1;
	// 返回true表示排序完成
	return true;
}

bool HalfInsertion::start()
{
	if (binaryInsertionSort(data, len))
	{
		return true;
	}
	else
	{
		this->swapTimes++;
		return false;
	}
}

#endif // !_HAIF_INSERTION_H_
