// DoubleBuffer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Framebuffer
	{
	public:
		Framebuffer() {}
		~Framebuffer() {}

		void clear()
		{
			for (int i = 0; i < kWidth*kHeight; ++i)
			{
				pixels_[i] = 0;
			}
		}

		void draw(int x, int y)
		{
			pixels_[y*kWidth + x] = 1;
		}

		const char* getPixels()
		{
			return pixels_;
		}

	private:
		static const int kWidth = 160;
		static const int kHeight = 120;
		char pixels_[kWidth * kHeight];
	};

	//class Scene
	//{
	//public:
	//	void draw()
	//	{
	//		buffer_.clear();
	//		buffer_.draw(1, 1);
	//		buffer_.draw(1, 2);
	//		buffer_.draw(3, 2);
	//	}

	//	Framebuffer& getBuffer()
	//	{
	//		return buffer_;
	//	}

	//private:
	//	Framebuffer buffer_;
	//};

	class Scene
	{
	public:
		void draw()
		{
			next_->clear();
			next_->draw(1, 1);
			next_->draw(1, 2);
			next_->draw(3, 2);
			swap();
		}

		Framebuffer& getBuffer()
		{
			return *current_;
		}

		void swap()
		{
			Framebuffer* tmp = current_;
			current_ = next_;
			next_ = tmp;
		}

	private:
		Framebuffer buffers_[2];
		Framebuffer *current_;
		Framebuffer *next_;
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
