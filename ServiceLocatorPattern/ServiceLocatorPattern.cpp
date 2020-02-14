// ServiceLocatorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Locator
	{
	public:
		static void initialize()
		{
			service_ = &nullService_;
		}

		static Audio& getAudio()
		{
			return &service_;
		}

		static void provide(Audio* service)
		{
			if (service == nullptr)
			{
				service = &nullService_;
			}

			service_ = service;
		}
	private:
		Audio* service_;
		NullAudio nullService_;
	};

	class LoggedAudio :public Audio
	{
	public:
		LoggedAudio(Audio& wrapped) : wrapped_(wrapped) {}

		virtual playSound(int soundId)
		{
			log("play sound");
			wrapped_.playSound(soundId);
		}

		virtual stopSound(int soundId)
		{
			log("stop sound");
			wrapped_.stopSound(soundId);
		}

		virtual stopAllSounds()
		{
			log("stop all sound");
			wrapped_.stopAllSounds();
		}
	private:
		void log(const char* message)
		{
			//log code..
		}

		Audio& wrapped_;
	};

//	class Locator
//	{
//	public:
//		static Audio& getAudio()
//		{
//			return audio_;
//		}
//
//	private:
//#if DEBUG
//		static DebugAudio service_;
//#else
//		static ReleaseAudio service_;
//#endif
//	};

	//class Location
	//{
	//public:
	//	static Audio& getAudio()
	//	{
	//		Audio* service = NULL;
	//		//code here to locate service...

	//		assert(service != NULL);
	//		return NULL;
	//	}
	//};

	//class Base
	//{
	//public:
	//	//Mothods to locate service and set service..

	//protected:
	//	static Audio& getAudio()
	//	{
	//		return *service_;
	//	}

	//private:
	//	static Audio* service_;
	//};
}

int main()
{
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
