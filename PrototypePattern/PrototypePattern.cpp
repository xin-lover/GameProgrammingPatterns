// PrototypePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Monster
	{
	public:
		virtual Monster* clone() = 0;
	};

	class Ghost:public Monster
	{
	public:
		Ghost(int health, int speed) :
			health_(health),
			speed_(speed)
		{

		}
		virtual Monster* clone()
		{
			return new Ghost(health_, speed_);
		}

		int health_;
		int speed_;

	};

	//原型模式
	class Spawner
	{
	public:
		Spawner(Monster* prototype) :
			prototype_(prototype)
		{

		}

		Monster* spawerMonster()
		{
			return prototype_->clone();
		}

	private:
		Monster *prototype_;
	};

	//使用生成器类
	//class Spawner
	//{
	//public:
	//	virtual ~Spawner() {}
	//	virtual Monster* spawnerMonster() = 0;
	//};

	//class GhostSpawner :Spawner
	//{
	//public:
	//	virtual Monster* spawnerMonster()
	//	{
	//		return new Ghost();
	//	}
	//};

	//template<typename T>
	//class SpawnerFor : public Spawner
	//{
	//public:
	//	virtual Monster* spawnerMonster()
	//	{
	//		return new T();
	//	}
	//};

	//生成器函数
	//using SpawnerCallback = Monster* (*)();

	//Monster* spawnerGhost()
	//{
	//	return new Ghost();
	//}

	//class Spawner
	//{
	//public:
	//	Spawner(SpawnerCallback callback) :
	//		spaw_(callback)
	//	{

	//	}

	//	Monster* spawnerMonster()
	//	{
	//		return spaw_();
	//	}

	//private:
	//	SpawnerCallback spaw_;
	//};
}

int main()
{
	//cp::SpawnerFor<cp::Ghost> spawner;
	//cp::Monster* monster = spawner.spawnerMonster();

	//cp::Spawner spawner(cp::spawnerGhost);
	//cp::Monster* monster = spawner.spawnerMonster();

	cp::Ghost *monster=new cp::Ghost(12, 5);
	cp::Spawner spawner(monster);
	spawner.spawerMonster();

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
