// UpdateMethodPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Entity
	{
	public:
		Entity() :x_(0), y_(0) {}
		virtual ~Entity() {}

		virtual void update() = 0;

		double x() const { return x_; }
		double y() const { return y_; }

		void setX(double x) { x_ = x; }
		void setY(double y) { y_ = y; }

	private:
		double x_;
		double y_;
	};

	class World
	{
	public:
		World() :numEntities_(0) {}
		void gameLoop();

		const static int MAX_ENTITIES = 100;
	private:
		Entity* entities_[MAX_ENTITIES];
		int numEntities_;
	};

	void World::gameLoop()
	{
		//handle input...

		while (true)
		{
			for (int i = 0; i < numEntities_; ++i)
			{
				entities_[i]->update();
			}
		}

		//physics and rendering...
	}

	class Skeleton :public Entity
	{
	public:
		Skeleton() : patrollingLeft_(false) {}

		virtual void update()
		{
			if (patrollingLeft_)
			{
				setX(x() - 1);
				if (x() == 0) patrollingLeft_ = false;
			}
			else
			{
				setX(x() + 1);
				if (x() == 100) patrollingLeft_ = true;
			}
		}
		private:
			bool patrollingLeft_;
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
