#pragma once
#ifndef _INSERTION_H_
#define _INSERTION_H_
#include"../Window/Window.h"
//插入
class Insertion :private Window
{
public:
	Insertion(size_t size);
	~Insertion();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

Insertion::Insertion(size_t size)
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

Insertion::~Insertion()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Insertion 插入\n";
}

bool Insertion::start()
{
	/*
	static DATATYPE key;
	static size_t i = 1, j;

	for (; i < len; )
	{
		key = data[i];
		j = i - 1;
		while ((j >= 0) && (key < data[j]))
		{
			//data[j + 1] = data[j];
			std::swap(data[j], data[j + 1]);
			j--;

			this->swapTimes++;

			return false;
		}
		data[j + 1] = key;
		i++;

		this->swapTimes++;
		return false;
	}
	i = j = 0;
	return true;
	*/

	/*	菜鸟
	void insertion_sort(int arr[],int len){
		for(int i=1;i<len;i++){
				int key=arr[i];
				int j=i-1;
				while((j>=0) && (key<arr[j])){
						arr[j+1]=arr[j];
						j--;
				}
				arr[j+1]=key;
		}
	}*/

	static size_t i, j;

	/*
	* 插入 ? 看起来是插入那它就是插入
	* 数据交换次数过多了, 但看上去基本与插入无异
	*/
#if 1
	for (; i < this->len - 1; )
	{
		j = 0;
		for (; j < this->len - i - 1; )
		{
			if (data[j] > data[j + 1])
			{
				//交换数据
				std::swap(data[j], data[j + 1]);
				swapTimes++;
				j++;
				return false;
			}
			j++;
		}
		i++;
	}
	i = j = 0;
	return true;
#endif //伪插入???

}


#endif // !_INSERTION_H_
