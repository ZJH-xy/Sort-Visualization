#include<iostream>
#include<thread>	//多线程
#include<easyx.h>	//easyX 图形库
#include<Windows.h>
#include"src/Window/Window.h"
#include"src/Sort/Bubble.h"
#include"src/Sort/Insertion.h"
#include"src/Sort/Quick.h"
#include"src/Sort/Merge.h"
#include"src/Sort/Chell.h"
#include"src/Sort/Simple selection.h"
#include"src/Sort/Half insertion.h"
#define ARRAYSIZE 80	//排序数组大小
#define SLEEPSIZE 160	//排序时暂停时间
clock_t TIME;			//排序花费的时间, 由TIMER 控制
bool	TIMEFLAG;		//计时器开关

/*
* @brief 计时器:
* @brief TIMEFLAG 为true时重新开始计时, 修改全局变量TIME
*/
//计时线程
void TIMER()
{
	//已废弃: 
	//根据进程句柄降低进程优先级，?使用 CreateThread 时使用
	//GetCurrentThreadId	返回进程ID	std::get_id
	//OpenProcess			返回进程句柄
	//SetPriorityClass(OpenProcess(PROCESS_TERMINATE, false, GetCurrentThreadId()), PROCESS_MODE_BACKGROUND_BEGIN);
	//ResumeThread(OpenProcess(PROCESS_TERMINATE, false, GetCurrentThreadId()));
	//SetThreadPriority(OpenProcess(PROCESS_TERMINATE, false, GetCurrentThreadId()), THREAD_MODE_BACKGROUND_BEGIN);
	static clock_t flag;

	for (; ; )
	{
		if (TIMEFLAG)
		{
			flag = clock();
			TIMEFLAG = false;
		}
		TIME = clock() - flag;
		Sleep(0);
	}
}

//绘制图形
void print(Window window, DATATYPE* data, size_t len, size_t swapTimes)
{
	static const	size_t	hight = window.getWidth() / len;		//单位宽度
	static			TCHAR	Text[128], timeText[128];				//文本
	static			RECT	r1, r2;									//计算坐标
	r1 = { 0,window.getHeight() / 20,window.getWidth(),window.getHeight() };
	r2 = { 0,0,window.getWidth(),window.getHeight() };

	BeginBatchDraw();	//开始批量绘图
	for (size_t i = 0; i < len; i++)
	{
		solidrectangle(hight * i, window.getHeight(), hight * (i + 1), window.getHeight() - data[i]);
		_stprintf_s(Text, _T("SwapTimes: %lld"), swapTimes);
		_stprintf_s(timeText, _T("Time: %ld ms"), TIME);
		drawtext(Text, &r1, DT_LEFT);
		drawtext(timeText, &r2, DT_LEFT);
		//每次交换后打印数组元素
		//std::cout << data[i] << " ";
	}
	//std::cout << "\n";

	FlushBatchDraw();	//执行未完成的绘制任务
	cleardevice();		//使用当前背景色清空绘图设备
}

int main()
{
	srand((unsigned int)time(NULL));
	//Window window(800, 600, NULL);
	Window window(800, 600, EX_SHOWCONSOLE);
	std::thread Timer(TIMER);	//创建多线程计时

	char operate;		//用户输入

	for (; ; )
	{
		std::cout << "1) 冒泡排序 bubble\n";
		std::cout << "2) 插入排序 insertion\n";
		std::cout << "3) 快速排序 quick\n";
		std::cout << "4) 归并排序 Merge\n";
		std::cout << "5) 希尔排序 Chell\n";
		std::cout << "6) 简单选择排序 Simple selection\n";
		std::cout << "7) 折半插入排序 Half insertion\n";

		std::cout << "- 请输入: \n";
		std::cin >> operate;

		//这里用switch 会出错
		if ('1' == operate)			//冒泡
		{
			Bubble Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('2' == operate)	//插入
		{
			Insertion Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('3' == operate)	//快速
		{
			Quick Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('4' == operate)	//归并
		{
			Merge Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('5' == operate)	//希尔
		{
			Chell Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('6' == operate)	//简单选择
		{
			SimpleSelection Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else if ('7' == operate)	//折半插入
		{
			HalfInsertion Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}

		else if ('0' == operate)
		{
			Quick Arr(ARRAYSIZE);
			TIMEFLAG = true;
			for (bool i = false; i != true; )
			{
				i = Arr.start();
				print(window, Arr.data, Arr.len, Arr.swapTimes);
				Sleep(SLEEPSIZE);
			}
		}
		else
		{
			std::cout << "非法输入! " << std::endl;
			//清空键盘缓冲区
			std::cin.ignore((std::streamsize)std::numeric_limits< std::streamsize >::max, '\n');
			//std::numeric_limits< std::streamsize >::max() 相当于IO流的最大字符个数
			Sleep(1000);
			system("cls");
		}
	}

	Timer.detach();
	system("pause");
	return 0;
}