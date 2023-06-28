#pragma once
#ifndef _QUICK_H_
#define _QUICK_H_
#include"../Window/Window.h"
#include<stack>		//std::stack ( ����ջ )
//����
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
	//��ֵ
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
	std::cout << "~Quick ����\n";
}

///ԭ��������
//bool quickSort(int arr[], int left, int right) {
//	std::stack<int> stk;	// ��һ��ջ�������������������ұ߽�
//	stk.push(left);
//	stk.push(right);
//
//	while (!stk.empty())	// ջ��Ϊ��ʱ��������
//	{
//		int r = stk.top();	// ȡ���ұ߽�
//		stk.pop();
//		int l = stk.top();	// ȡ����߽�
//		stk.pop();
//
//		int pivot = arr[(l + r) / 2];	// ѡȡ�м�Ԫ����Ϊ��׼ֵ
//		int i = l, j = r;
//		while (i <= j)		// ˫ָ�뷨���л���
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
//		if (l < j)		// ���������仹��δ����Ĳ��֣�������ջ
//		{
//			stk.push(l);
//			stk.push(j);
//		}
//		if (i < r)		// ����ұ����仹��δ����Ĳ��֣�������ջ
//		{
//			stk.push(i);
//			stk.push(r);
//		}
//	}
//	return true;
//}

bool quickSort(DATATYPE arr[], int left, int right) {
	static bool flag1, flag2, flag3;
	static std::stack<int> stk; // ��һ��ջ�������������������ұ߽�
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
	while (!stk.empty()) { // ջ��Ϊ��ʱ��������
		if (!flag2)
		{
			r = stk.top(); // ȡ���ұ߽�
			stk.pop();
			l = stk.top(); // ȡ����߽�
			stk.pop();
			pivot = arr[(l + r) / 2]; // ѡȡ�м�Ԫ����Ϊ��׼ֵ
			i = l, j = r;
			flag2 = true;
		}
	goo:
		while (i <= j) { // ˫ָ�뷨���л���
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
		if (l < j) { // ���������仹��δ����Ĳ��֣�������ջ
			stk.push(l);
			stk.push(j);
		}
		if (i < r) { // ����ұ����仹��δ����Ĳ��֣�������ջ
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
* ����������ĥ��������, �ݹ�汾��Ҫ���ӻ��Ѷ�̫��, ������GPT ����д��
* ����һ��goto ��ת,ʵ����goto ȷʵ��һ����ݷ���Ľ������,
*/


#endif // !_QUICK_H_
