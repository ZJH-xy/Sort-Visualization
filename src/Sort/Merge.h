#pragma once
#ifndef _MERGE_H_
#define _MERGE_H_
#include"../Window/Window.h"
//�鲢
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
	//��ֵ
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
	std::cout << "~Merge �鲢\n";
}

/*
�ο�������̳̣�
//�����棺
template<typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)���\���ӹ���
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

///GPT ��ϸע�Ͱ�
/*
template<typename T>
bool merge_sort(T* arr, int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) { // segΪ�����еĳ��ȣ�ÿ��ѭ���������г��ȼӱ�
		for (int start = 0; start < len; start += seg + seg) { // startΪ�����е���ʼλ�ã�ÿ��ѭ��������һ��������
			int low = start; // �������е���ʼλ��
			int mid = min(start + seg, len); // �������еĽ���λ�ã��������е���ʼλ��
			int high = min(start + seg + seg, len); // �������еĽ���λ��
			int k = low; // ��¼��ǰλ��
			int start1 = low, end1 = mid; // �������е���ʼλ�úͽ���λ��
			int start2 = mid, end2 = high; // �������е���ʼλ�úͽ���λ��
			while (start1 < end1 && start2 < end2) { // �������������е�Ԫ�ذ���С�����˳��ϲ���b������
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			while (start1 < end1) { // ����������л���ʣ��Ԫ�أ�����ֱ�Ӹ��Ƶ�b������
				b[k++] = a[start1++];
			}
			while (start2 < end2) { // ����������л���ʣ��Ԫ�أ�����ֱ�Ӹ��Ƶ�b������
				b[k++] = a[start2++];
			}
		}
		T* temp = a; // ����a��b�����ָ��
		a = b;
		b = temp;
	}
	if (a != arr) { // ���aָ�벻ָ��ԭʼ���飬˵�����ս����������b�����У���Ҫ���临�Ƶ�ԭʼ������
		for (int i = 0; i < len; i++) {
			b[i] = a[i];
		}
		b = a;
	}
	delete[] b; // �ͷ�b������ڴ�
	return true;
}
*/

//�����棺
template<typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)���\���ӹ���
bool merge_sort(T* arr, int len)
{
	static bool F1, F2, F3;	//��ת���

	static T* a;	//ԭʼ����
	//= arr;
	if (!a)
		a = arr;
	static T* b = new T[len];
	static T* c = new T[len];	//����a ��b �Ƚ�����, ʵ�ʽ���

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
