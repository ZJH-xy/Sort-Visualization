#include<iostream>
#include<thread>	//���߳�
#include<easyx.h>	//easyX ͼ�ο�
#include<Windows.h>
#include"src/Window/Window.h"
#include"src/Sort/Bubble.h"
#include"src/Sort/Insertion.h"
#include"src/Sort/Quick.h"
#include"src/Sort/Merge.h"
#include"src/Sort/Chell.h"
#include"src/Sort/Simple selection.h"
#include"src/Sort/Half insertion.h"
#define ARRAYSIZE 80	//���������С
#define SLEEPSIZE 160	//����ʱ��ͣʱ��
clock_t TIME;			//���򻨷ѵ�ʱ��, ��TIMER ����
bool	TIMEFLAG;		//��ʱ������

/*
* @brief ��ʱ��:
* @brief TIMEFLAG Ϊtrueʱ���¿�ʼ��ʱ, �޸�ȫ�ֱ���TIME
*/
//��ʱ�߳�
void TIMER()
{
	//�ѷ���: 
	//���ݽ��̾�����ͽ������ȼ���?ʹ�� CreateThread ʱʹ��
	//GetCurrentThreadId	���ؽ���ID	std::get_id
	//OpenProcess			���ؽ��̾��
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

//����ͼ��
void print(Window window, DATATYPE* data, size_t len, size_t swapTimes)
{
	static const	size_t	hight = window.getWidth() / len;		//��λ���
	static			TCHAR	Text[128], timeText[128];				//�ı�
	static			RECT	r1, r2;									//��������
	r1 = { 0,window.getHeight() / 20,window.getWidth(),window.getHeight() };
	r2 = { 0,0,window.getWidth(),window.getHeight() };

	BeginBatchDraw();	//��ʼ������ͼ
	for (size_t i = 0; i < len; i++)
	{
		solidrectangle(hight * i, window.getHeight(), hight * (i + 1), window.getHeight() - data[i]);
		_stprintf_s(Text, _T("SwapTimes: %lld"), swapTimes);
		_stprintf_s(timeText, _T("Time: %ld ms"), TIME);
		drawtext(Text, &r1, DT_LEFT);
		drawtext(timeText, &r2, DT_LEFT);
		//ÿ�ν������ӡ����Ԫ��
		//std::cout << data[i] << " ";
	}
	//std::cout << "\n";

	FlushBatchDraw();	//ִ��δ��ɵĻ�������
	cleardevice();		//ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
}

int main()
{
	srand((unsigned int)time(NULL));
	//Window window(800, 600, NULL);
	Window window(800, 600, EX_SHOWCONSOLE);
	std::thread Timer(TIMER);	//�������̼߳�ʱ

	char operate;		//�û�����

	for (; ; )
	{
		std::cout << "1) ð������ bubble\n";
		std::cout << "2) �������� insertion\n";
		std::cout << "3) �������� quick\n";
		std::cout << "4) �鲢���� Merge\n";
		std::cout << "5) ϣ������ Chell\n";
		std::cout << "6) ��ѡ������ Simple selection\n";
		std::cout << "7) �۰�������� Half insertion\n";

		std::cout << "- ������: \n";
		std::cin >> operate;

		//������switch �����
		if ('1' == operate)			//ð��
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
		else if ('2' == operate)	//����
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
		else if ('3' == operate)	//����
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
		else if ('4' == operate)	//�鲢
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
		else if ('5' == operate)	//ϣ��
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
		else if ('6' == operate)	//��ѡ��
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
		else if ('7' == operate)	//�۰����
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
			std::cout << "�Ƿ�����! " << std::endl;
			//��ռ��̻�����
			std::cin.ignore((std::streamsize)std::numeric_limits< std::streamsize >::max, '\n');
			//std::numeric_limits< std::streamsize >::max() �൱��IO��������ַ�����
			Sleep(1000);
			system("cls");
		}
	}

	Timer.detach();
	system("pause");
	return 0;
}