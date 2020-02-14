// StatePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	enum  Input
	{
		PRESS_B,
		PRESS_DOWN,
	};
	//class Heroine
	//{
	//public:
	//	Heroine() {}
	//	void HandleInput(Input input)
	//	{
	//		if (input == PRESS_B)
	//		{
	//			//do jump
	//		}
	//	}
	//};

	class Heroine;

	class HeroineState
	{
	public:
		~HeroineState() {}
		virtual HeroineState* handleInput(Heroine &heroine, Input input)
		{
			return nullptr;
		}

		virtual void entry(Heroine &heroine)
		{
		}

		virtual void update(Heroine &heroine)
		{

		}

		virtual void exit(Heroine &heroine)
		{

		}
		
	};

	class Heroine
	{
	public:
		void handleInput(Input input)
		{
			HeroineState* state = state_->handleInput(*this, input);
			if (state != nullptr)
			{
				state_->exit(*this);
				delete state_;
				state_ = state;
				state_->entry(*this);
			}
		}

		void udate()
		{
			if (state_ != nullptr)
			{
				state_->update(*this);
			}
		}

	private:
		HeroineState *state_;
	};

}

int main()
{
	cp::Heroine heroine;
	heroine.handleInput(cp::PRESS_B);

	return 0;
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
