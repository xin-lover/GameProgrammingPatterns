// DataLocalityPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class GameEntity
	{
	public:
		GameEntity(AIComponent* ai,
			PhysicsComponent* physics,
			RenderComponent* render)
			:ai_(ai), physics_(physics), render_(render)
		{
		}

		AIComponent* ai() { return ai_; }
		PhysicsComponent* physics() { return physics_; }
		RenderComponent* render() { return render_; }

	private:
		AIComponent* ai_;
		PhysicsComponent* physics_;
		RenderComponent* render_;
	};

	class AIComponent
	{
	public:
		void update()
		{
			//work with and modify state...
		}

	private:
		//Goals,mood
	};

	class PhysicsComponent
	{
	public:
		void update()
		{
			//work with and modify state...
		}

	private:
		//properties...
	};

	class RenderComponent
	{
	public:
		void update()
		{
			//work with and modify state..
		}

	private:
		//mesh,textures
	};


	class Game
	{
	public:
		void update()
		{
			while (!gameOver)
			{
				for (int i = 0; i < numEntities; ++i)
				{
					entities[i]->ai()->update();
				}

				for (int i = 0; i < numEntities; ++i)
				{
					entities[i]->physics()->update();
				}

				for (int i = 0; i < numEntities; ++i)
				{
					entities[i]->render()->update();
				}

				//改进，连续数组
				//while (!gameOver)
				//{
				//	//process AI
				//	for (int i = 0; i < numEntities; ++i)
				//	{
				//		aiComponents[i].update();
				//	}

				//	//update physics
				//	for (int i = 0; i < numEntities; ++i)
				//	{
				//		pysicsComponents[i].update();
				//	}

				//	//update render
				//	for (int i = 0; i < numEntities; ++i)
				//	{
				//		renderComponents[i].update();
				//	}

				//	//other game loop   
				//}

				//改进，把活动的对象都移动到数组前端
				//void ParticleSystem::update()
				//{
				//	if (particles_[i].isActive)
				//	{
				//		particles_[i].update();
				//	}
				//}

				//移动活动对象到队头
				//void ParticleSystem::activateParticle(int index)
				//{
				//	//shuldn't already be active
				//	assert(index >= numActive_);

				//	//swap it with the first inactive particle right
				//	//after the active ones
				//	particle tmp = particles_[numActive_];
				//	particles_[numActive_] = particles_[index];
				//	particles_[index] = tmp;

				//	numActive_++;
				//}

				//反激活对象
				//void ParticleSystem::deactivateParticle(int index)
				//{
				//	//shuldn't alreay be inactive
				//	assert(index <= numActive);

				//	numActive__;

				//	//swap ti ithe the last active particle right
				//	//before the inactive ones.

				//	Particle tmp = particles_[numActive_];
				//	particles_[numActive_] = particles_[index];
				//	particles_[index] = tmp;
				//}
			}
		}

	private:
		bool gameOver;
		static const int numEntities = 100;
		GameEntity* entities[numEntities];
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
