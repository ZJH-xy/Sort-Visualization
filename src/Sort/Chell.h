#pragma once
#ifndef _CHELL_H_
#define _CHELL_H_
#include"../Window/Window.h"
// Ï£¶û
class Chell :private Window
{
public:
	Chell(size_t size);
	~Chell();

	DATATYPE* data;
	size_t len;
	size_t swapTimes;

	bool start();
};

Chell::Chell(size_t size)
{
	data = ((DATATYPE*) new DATATYPE[size]);
	this->len = size;
	this->swapTimes = 0;
	//¸³Öµ
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = rand() % ARRAYMAX + 1;
		std::cout << i << " " << data[i] << "\n";
	}
}

Chell::~Chell()
{
	if (this->data)
		this->data = nullptr;
	std::cout << "~Chell Ï£¶û\n";
}

/*
template<typename T>
void shell_sort(T array[], int length) {
	int h = 1;
	while (h < length / 3) {
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < length; i++) {
			for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
				std::swap(array[j], array[j - h]);
			}
		}
		h = h / 3;
	}
}
*/

bool Chell::start()
{
	static size_t h, i, j;
	static bool flag = false;
	while (!flag && (h < this->len / 3))
	{
		h = 3 * h + 1;
	}
	flag = true;

	while (h >= 1)
	{
		for (i = h; i < this->len; i++)
		{
			for (j = i; j >= h && data[j] < data[j - h]; )
			{
				std::swap(data[j], data[j - h]);
				this->swapTimes++;
				j -= h;
				return false;
			}
		}
		h = h / 3;
	}
	h = i = j = flag = 0;
	return true;
}


#endif // !_CHELL_H_
