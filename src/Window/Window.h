#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<iostream>
#include<easyx.h>
#define ARRAYMAX 512	//随机生成最大数的边界
typedef int DATATYPE;	//排序数组的数据类型

class Window
{
private:
	//窗口信息
	int _width;
	int _height;
	//eaxyx 绘图窗口的样式
	int _consolFlag;

	//初始化窗口
	void initWindow();

public:
	Window(int width, int height, int flag);
	Window();
	virtual ~Window();	//没有会报错( 暂不清楚原理 )

	//获取窗口信息
	int getHeight();
	int getWidth();
	int getFlag();
};


#endif // !_WINDOW_H_

