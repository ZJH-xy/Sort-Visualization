#pragma once
#ifndef _BUBBLE_H_
#define _BUBBLE_H_
#include"../Window/Window.h"
// ð��
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
	// !!! ���� !!!
	//data = ((DATATYPE*) new DATATYPE(size));
	data = ((DATATYPE*) new DATATYPE[size]);
	this->len = size;
	this->swapTimes = 0;
	for (size_t i = 0; i < size; i++)//��ֵ
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}
Bubble::~Bubble()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Bubble ð��\n";
}


bool Bubble::start()
{
	//��̬�洢����
	static size_t i, j;
	//ÿ����һ��Ԫ�ؽ���, ����false, �ٴε��ú���ʱ��������
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
	//����true ��ʾ�����Ѿ����
	return true;
}

#endif // !_BUBBLE_H_