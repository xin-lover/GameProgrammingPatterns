// FlyweightPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <random>

//享元模式，简单的来说就是把数据分为两种类型，一种是不变的数据,一种是对象独享的数据，不变的数据可以让多个对象共享；
//当我们有成千上万个对象的时候这种模式很可观减少内存的使用
namespace cp
{
	class Texture
	{
	public:
		Texture(int id) :
			id_(id)
		{

		}
		int id_;
	};
	class Terrain
	{
	public:
		Terrain(int moveCost, bool isWater, Texture texture):
			moveCost_(moveCost),
			isWater_(isWater),
			texture_(texture)
		{

		}

		int getMoveCost()
		{
			return moveCost_;
		}
	private:
		int moveCost_;
		bool isWater_;
		Texture texture_;
	};

	class World
	{
	public:
		World() :
			grassTerrain_(1, false, Texture(1)),
			riverTerrain_(2, false, Texture(2)),
			hillTerrain_(3, false, Texture(3))
		{

		}

		void generateTerrain()
		{
			std::default_random_engine random;
			std::uniform_int_distribution<int> u(0, 9);
			for (int i = 0; i < kWidth; ++i)
			{
				for (int j = 0; j < kHeight; ++j)
				{
					if (u(random) < 2)
					{
						titles_[i][j] = &hillTerrain_;
					}
					else
					{
						titles_[i][j] = &grassTerrain_;
					}


				}
			}

			std::uniform_int_distribution<int> u100(0, kWidth-1);
			int x = u100(random);
			for (int i = 0; i < kHeight; ++i)
			{
				titles_[x][i] = &riverTerrain_;
			}
		}

		const Terrain& getTile(int x, int y) const
		{
			return *titles_[x][y];
		}

		
	private:
		const static int kWidth = 100;
		const static int kHeight = 100;
		Terrain* titles_[kWidth][kHeight];

		Terrain grassTerrain_;
		Terrain riverTerrain_;
		Terrain hillTerrain_;
	};
}

int main()
{
	cp::World world;
	world.generateTerrain();
	std::uniform_int_distribution<int> u(0, 99);
	std::default_random_engine e;

	for (int i = 0; i < 10; ++i)
	{
		int x = u(e);
		int y = u(e);
		cp::Terrain t = world.getTile(x, y);
		std::cout <<"x:" << x << " y:" << y << " cost:"<< t.getMoveCost() << std::endl;
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
