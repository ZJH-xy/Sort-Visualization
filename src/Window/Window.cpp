#include "Window.h"

void Window::initWindow()	//´´½¨´°¿Ú
{
	initgraph(_width, _height, _consolFlag);
}

Window::Window(int width, int height, int flag)
{
	this->_width = width;
	this->_height = height;
	this->_consolFlag = flag;

	this->initWindow();
}
Window::Window()
{
	std::cout << "Window\n";
}
Window::~Window()
{
	//std::cout << "~Window\n";
}

int Window::getHeight()
{
	return this->_height;
}

int Window::getWidth()
{
	return this->_width;
}

int Window::getFlag()
{
	return this->_consolFlag;
}
