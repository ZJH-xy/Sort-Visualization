#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<iostream>
#include<easyx.h>
#define ARRAYMAX 512	//�������������ı߽�
typedef int DATATYPE;	//�����������������

class Window
{
private:
	//������Ϣ
	int _width;
	int _height;
	//eaxyx ��ͼ���ڵ���ʽ
	int _consolFlag;

	//��ʼ������
	void initWindow();

public:
	Window(int width, int height, int flag);
	Window();
	virtual ~Window();	//û�лᱨ��( �ݲ����ԭ�� )

	//��ȡ������Ϣ
	int getHeight();
	int getWidth();
	int getFlag();
};


#endif // !_WINDOW_H_

