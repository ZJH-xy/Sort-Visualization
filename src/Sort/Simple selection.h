#pragma once
#ifndef _SIMPLE_SELECTION_H_
#define _SIMPLE_SELECTION_H_
#include"../Window/Window.h"
// 简单选择
class SimpleSelection :private Window
{
public:
	SimpleSelection(size_t size);
	~SimpleSelection();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

SimpleSelection::SimpleSelection(size_t size)
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
SimpleSelection::~SimpleSelection()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~SimpleSelection 简单选择\n";
}

//将最小值放最前面
bool SimpleSelection::start()
{
	static size_t i, j, num;
	for (; i < len; i++)
	{
		for (j = i + num + 1; j < len; j++)  // 从 i+1 开始查找最小值
		{
			if (data[j] < data[i])
			{
				std::swap(data[j], data[i]);
				this->swapTimes++;
				return false;
			}
		}
		num = 0;
	}
	i = 0;
	return true;
}

//将最小值放最前面
/*bool SimpleSelection::start()
{
	static size_t i, j, num;
	static DATATYPE min;
	for (; i < len; )
	{
		min = data[i];				//记录最小值
		for (j = i + num; j < len; j++)	//与其余的元素比较
		{
			if (data[j] < data[i])
			{
				std::swap(data[j], data[i]);
				this->swapTimes++;
				return false;
			}
			num++;
		}
		num = 0;
		i++;
		return false;

	}
	i = 0;
	return true;

}
*/

#endif // !_SIMPLE_SELECTION_H_
