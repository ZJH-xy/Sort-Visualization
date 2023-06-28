#pragma once
#ifndef _MERGE_H_
#define _MERGE_H_
#include"../Window/Window.h"
//归并
class Merge :private Window
{
public:
	Merge(size_t size);
	~Merge();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

Merge::Merge(size_t size)
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
Merge::~Merge()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Merge 归并\n";
}

/*
参考（菜鸟教程）
//迭代版：
template<typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
bool merge_sort(T* arr, int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
	return true;
}
*/

///GPT 详细注释版
/*
template<typename T>
bool merge_sort(T* arr, int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) { // seg为子序列的长度，每次循环将子序列长度加倍
		for (int start = 0; start < len; start += seg + seg) { // start为子序列的起始位置，每次循环跳到下一个子序列
			int low = start; // 左子序列的起始位置
			int mid = min(start + seg, len); // 左子序列的结束位置，右子序列的起始位置
			int high = min(start + seg + seg, len); // 右子序列的结束位置
			int k = low; // 记录当前位置
			int start1 = low, end1 = mid; // 左子序列的起始位置和结束位置
			int start2 = mid, end2 = high; // 右子序列的起始位置和结束位置
			while (start1 < end1 && start2 < end2) { // 将左右子序列中的元素按从小到大的顺序合并到b数组中
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			while (start1 < end1) { // 如果左子序列还有剩余元素，将其直接复制到b数组中
				b[k++] = a[start1++];
			}
			while (start2 < end2) { // 如果右子序列还有剩余元素，将其直接复制到b数组中
				b[k++] = a[start2++];
			}
		}
		T* temp = a; // 交换a和b数组的指针
		a = b;
		b = temp;
	}
	if (a != arr) { // 如果a指针不指向原始数组，说明最终结果保存在了b数组中，需要将其复制到原始数组中
		for (int i = 0; i < len; i++) {
			b[i] = a[i];
		}
		b = a;
	}
	delete[] b; // 释放b数组的内存
	return true;
}
*/

//迭代版：
template<typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
bool merge_sort(T* arr, int len)
{
	static bool F1, F2, F3;	//跳转标记

	static T* a;	//原始数组
	//= arr;
	if (!a)
		a = arr;
	static T* b = new T[len];
	static T* c = new T[len];	//代替a 与b 比较排序, 实际交换

	static int low, mid, high;
	static int k;
	static int start1, end1;
	static int start2, end2;

	static int start;
	static int seg = 1;

	for (; seg < len; )
	{
		for (; start < len; start += seg + seg)
		{
			if (F1) {
				F1 = false;
				goto F1;
			}
			else if (F2) {
				F2 = false;
				goto F2;
			}
			else if (F3) {
				F3 = false;
				goto F3;
			}
			else
			{
				low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
				k = low;
				start1 = low, end1 = mid;
				start2 = mid, end2 = high;
				//int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
				//int k = low;
				//int start1 = low, end1 = mid;
				//int start2 = mid, end2 = high;
			}
		F1:
			while (start1 < end1 && start2 < end2)
			{
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];

				F1 = true;
				return false;
			}
		F2:
			while (start1 < end1)
			{
				b[k++] = a[start1++];

				F2 = true;
				return false;
			}
		F3:
			while (start2 < end2)
			{
				b[k++] = a[start2++];

				F3 = true;
				return false;
			}
			//low = 0, mid = 0, high = 0;
			//k = 0;
			//start1 = 0, end1 = 0;
			//start2 = 0, end2 = 0;
		}
		start = 0;
		std::swap(a, b);//
		seg += seg;
		return false;
	}
	seg = 1;//
	if (a != arr)
	{
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	start = 0;
	a = nullptr;
	return true;
}


bool Merge::start()
{
	if (merge_sort<DATATYPE>(data, len))
	{
		return true;
	}
	else
	{
		this->swapTimes++;
		return false;
	}
}


#endif // !_MERGE_H_
