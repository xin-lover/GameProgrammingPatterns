// EventQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Audio
	{
	public:
		static void init() { head_ = 0; tail_ = 0; }
		void playSound(SoundId id, int volume)
		{
			assert((tail_ + 1) % MAX_PENDING_ != head_);
			pending_[tail_].id = id;
			pending_[tail_].volume = volume;
			tail_ = (tail_ + 1) % MAX_PENDING;
		}

		void update()
		{
			if (head_ == tail_) return;

			ResourceId resource = loadSound(pending_[head_].id);
			int channel = findOpenChannel();
			if (channel == -1) return;
			startSound(resource, channel, pending_[head_].volume);

			head_ = (head_ + 1) % MAX_PENDING;
		}

	private:
		static const int MAX_PENDING = 16;

		PlayMessage pending_[MAX_PENDING];
		int head_;
		int tail_;
	};
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
