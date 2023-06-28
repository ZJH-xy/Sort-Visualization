#pragma once
#ifndef _BUBBLE_H_
#define _BUBBLE_H_
#include"../Window/Window.h"
// 冒泡
class Bubble :private Window
{
public:
	Bubble(size_t size);
	~Bubble();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

Bubble::Bubble(size_t size)
{
	// !!! 错误 !!!
	//data = ((DATATYPE*) new DATATYPE(size));
	data = ((DATATYPE*) new DATATYPE[size]);
	this->len = size;
	this->swapTimes = 0;
	for (size_t i = 0; i < size; i++)//赋值
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}
Bubble::~Bubble()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Bubble 冒泡\n";
}


bool Bubble::start()
{
	//静态存储变量
	static size_t i, j;
	//每发生一次元素交换, 返回false, 再次调用函数时继续排序
	for (; i < len - 1; i++)
	{
		for (; j < len - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				std::swap(data[j], data[j + 1]);
				this->swapTimes++;
				j++;
				return  false;
			}
		}
		j = 0;
	}
	i = j = 0;
	//返回true 表示排序已经完成
	return true;
}

#endif // !_BUBBLE_H_