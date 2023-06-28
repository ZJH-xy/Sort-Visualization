#pragma once
#ifndef _HAIF_INSERTION_H_
#define _HAIF_INSERTION_H_
#include"../Window/Window.h"
// �۰����
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
	for (size_t i = 0; i < size; i++)//��ֵ
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}
HalfInsertion::~HalfInsertion()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Half insertion �۰����\n";
}

/**
 * ʹ���۰��������������������
 * @param arr �����������
 * @param len ����ĳ���
 * @param last �������ʼλ�ã����ϴ�����Ľ���
 * @return ��������Ѿ���ȫ�����򷵻�true�����򷵻�false
 */
 /*
 bool binaryInsertionSort(int arr[], int len, int last) {
	 bool sorted = true; // ��������Ƿ��Ѿ���ȫ����
	 int start = (last == 0) ? 1 : last + 1; // �����������ʼλ��
	 for (int i = start; i < len; i++) {
		 int temp = arr[i]; // ����ǰλ�õ�ֵ���浽��ʱ������
		 int left = 0, right = i - 1; // ��ʼ���۰���ҵ����ұ߽�
		 while (left <= right) {
			 int mid = (left + right) / 2; // �����м�λ��
			 if (arr[mid] > temp) { // �����ǰλ�õ�ֵ����ʱ������ֵ��
				 right = mid - 1; // ���ұ߽���С���м�λ�����
			 }
			 else { // �����ǰλ�õ�ֵ����ʱ������ֵС�����
				 left = mid + 1; // ����߽������м�λ���Ҳ�
			 }
		 }
		 // ��[left, i-1]��Χ�ڵ�����Ԫ�������ƶ�һ��λ��
		 for (int j = i - 1; j >= left; j--) {
			 arr[j + 1] = arr[j];
			 sorted = false; // �������δ��ȫ����
		 }
		 arr[left] = temp; // ����ʱ�������뵽��ȷ��λ��
		 if (left != i) { // ������������ݽ���
			 sorted = false; // �������δ��ȫ����
			 return false; // ����false
		 }
	 }
	 return sorted;
 }
 */

 //���� (GPT д��
/*
bool binaryInsertionSort2(int arr[], int len, int last)
{
	bool sorted = true;						// ��������Ƿ��Ѿ���ȫ����
	int start = (last == 0) ? 1 : last + 1; // �����������ʼλ��
	for (int i = start; i < len; i++)
	{
		int temp = arr[i];					// ����ǰλ�õ�ֵ���浽��ʱ������
		int left = 0, right = i - 1;		// ��ʼ���۰���ҵ����ұ߽�
		while (left <= right)
		{
			int mid = (left + right) / 2;	// �����м�λ��
			if (arr[mid] > temp)
			{						// �����ǰλ�õ�ֵ����ʱ������ֵ��
				right = mid - 1;	// ���ұ߽���С���м�λ�����
			}
			else
			{						// �����ǰλ�õ�ֵ����ʱ������ֵС�����
				left = mid + 1;		// ����߽������м�λ���Ҳ�
			}
		}
		// ��[left, i-1]��Χ�ڵ�����Ԫ�������ƶ�һ��λ��
		for (int j = i - 1; j >= left; j--)
		{
			//arr[j + 1] = arr[j];
			std::swap(arr[j + 1], arr[j]);
			return sorted = false; // �������δ��ȫ����
		}
		//arr[left] = temp; // ����ʱ�������뵽��ȷ��λ��
		if (left != i)
		{ // ������������ݽ���
			sorted = false; // �������δ��ȫ����
			return false; // ����false
		}
	}
	return sorted;
}
*/

/**
 * �۰��������
 * @param arr ���������������
 * @param n ����ĳ���
 * @return ������ɺ󷵻�true
 */
bool binaryInsertionSort(int arr[], int n) {

	static bool flag;
	static int i = 1, j = 1;
	static int key, left, right, mid, min;

	// �ӵڶ���Ԫ�ؿ�ʼ��������
	for (; i < n; ) {
		if (flag)
			goto F1;
		// ���浱ǰҪ�����Ԫ��
		key = arr[i];
		// �������ұ߽�
		left = 0, right = i - 1;
		// ���ֲ��Ҳ���λ��
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] > key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		// ������λ�ú����Ԫ�غ���һλ
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
		// ��Ԫ�ز��뵽��ȷ��λ��
		arr[left] = key;
		flag = false;
		i++;
		return false;
	}
	i = 1;
	// ����true��ʾ�������
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
