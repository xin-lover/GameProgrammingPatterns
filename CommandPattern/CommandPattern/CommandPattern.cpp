// CommandPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace cp
{
	class Command;

class GameActor
{
public:
	void Jump()
	{
		std::cout << "Jump" << std::endl;
	}

	void Fire()
	{
		std::cout << "fire" << std::endl;
	}

};

class Command
{
public:
	~Command() {}
	virtual void Excute(GameActor& actor) = 0;
	virtual void Undo() = 0;
};

class JumpCommand : public Command
{
public:
	virtual void Excute(GameActor& actor) override
	{
		actor.Jump();
	}

	virtual void Undo() override
	{
		std::cout << "jump undo" << std::endl;
	}
};

class FireCommand : public Command
{
public:
	virtual void Excute(GameActor& actor) override
	{
		actor.Fire();
	}

	virtual void Undo() override
	{
		std::cout << "fire undo" << std::endl;
	}
};


class InputHandler
{
public:
	InputHandler()
	{
		jump_ = make_shared<JumpCommand>();
		fire_ = make_shared<FireCommand>();
	}
	shared_ptr<Command> HandleInput(int order)
	{
		if (order== 1)
		{
			return jump_;
		}
		else if (order == 2)
		{
			return fire_;
		}
		else
		{
			std::cout << "error order" << std::endl;
			return shared_ptr<Command>(nullptr);
		}
	}

private:
	shared_ptr<Command> jump_;
	shared_ptr<Command> fire_;
};

}



int main()
{
	cp::InputHandler handler;
	int c = 0;
	cp::GameActor actor;
	vector<shared_ptr<cp::Command>> commands_;
	int current_ = 0;
	while (c != 100)
	{
		std::cin >> c;
		if (!cin.good())
		{
			break;
		}
		shared_ptr<cp::Command> cmd = handler.HandleInput(c);
		if (cmd)
		{
			commands_.push_back(cmd);
			cmd->Excute(actor);
		}
	}
	for (auto a : commands_)
	{
		a->Undo();
	}
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
