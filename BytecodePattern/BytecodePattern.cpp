// BytecodePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace cp
{
	//解释器
	class Expression
	{
	public:
		virtual ~Expression() {}
		virtual double evaluate() = 0;
	};


	class NumberExpression :public Expression
	{
	public:
		NumberExpression(double value) :value_(value)
		{}

		virtual double evaluate() { return value_; }

	private:
		double value_;
	};

	class AdditionExpression : public Expression
	{
	public:
		AdditionExpression(Expression* left,Expression* right) :left_(left),right_(right)
		{}

		virtual double evaluate()
		{
			//Evaluate the operands.
			double left = left_->evaluate();
			double right = right_->evaluate();

			//add them.
			return left + right;
		}
	private:
		Expression* left_;
		Expression* right_;
	};

	//字节码
	enum Instruction
	{
		INST_SET_HEALTH = 0X00,
		INST_SET_WISDOM = 0X01,
		INST_SET_AGILITY = 0X02,
		INST_PLAY_SOUND = 0X03,
		INST_SPAWN_PARTICLES = 0X04
	};

	void setHealth(int wizard, int amount) {}

	void setWisdom(int wizard, int amount) {}

	void setAgility(int wizard, int amount) {}

	void playSound(int soundId) {}

	void spawnParticles(int particleType) {}

	class VM
	{
	public:
		VM() :stackSize_(0) {}

		void interpret(char bytecode[], int size)
		{
			for (int i = 0; i < size; ++i)
			{
				char instruction = bytecode[i];
				switch (instruction)
				{
					//handle instruction...
				case INST_SET_HEALTH:
					int amount = pop();
					int wizard = pop();
					setHealth(wizard, amount);
					break;
					//......
				default:
					break;
				}
			}
		}

	private:
		static const int MAX_STACK = 128;
		int stackSize_;
		int stack_[MAX_STACK];

		void push(int value)
		{
			//check
			assert(stackSize_ < MAX_STACK);
			stack_[stackSize_++] = value;
		}

		int pop()
		{
			//check
			assert(stackSize_ > 0);
			return stack_[--stackSize_];
		}
	};

	//带标签的联合体
	enum ValueType
	{
		TYPE_INT,
		TYPE_DOUBLE,
		TYPE_STRING
	};

	struct Value
	{
		ValueType type;
		union
		{
			int intValue;
			double doubleValue;
			char* stringValue;
		};
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
