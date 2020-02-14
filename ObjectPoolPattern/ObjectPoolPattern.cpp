// ObjectPoolPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <assert.h>

namespace cp
{
	//class Particle
	//{
	//public:
	//	Particle() :framesLeft_(0)
	//	{}

	//	void init(double x, double y, double xVel, double yVel, int lifeTime)
	//	{
	//		x_ = x;
	//		y_ = y;
	//		xVel_ = xVel;
	//		yVel_ = yVel;
	//		framesLeft_ = lifeTime;

	//	}

	//	void animate()
	//	{
	//		if (!inUse()) return;
	//		framesLeft_--;
	//		x_ += xVel_;
	//		y_ += yVel_;
	//	}


	//	bool inUse() const
	//	{
	//		return framesLeft_ > 0;
	//	}

	//private:
	//	int framesLeft_;
	//	double x_, y_;
	//	double xVel_, yVel_;
	//};

	//class ParticlePool
	//{
	//public:
	//	void  create(double x, double y, double xVel, double yVel, int lifeTime)
	//	{
	//		for (int i = 0; i < POOL_SIZE; ++i)
	//		{
	//			if (!particles_[i].inUse())
	//			{
	//				particles_[i].init(x, y, xVel, yVel, lifeTime);
	//				return;
	//			}
	//		}
	//	}

	//	void animate()
	//	{
	//		for (int i = 0; i < POOL_SIZE; ++i)
	//		{
	//			particles_[i].animate();
	//		}
	//	}

	//private:
	//	static const int POOL_SIZE = 100;
	//	Particle particles_[POOL_SIZE];
	//};

	class Particle
	{
	public:
		void init(double x,double y,double xVel,double yVel,int time)
		{

		}
		Particle* getNext() const { return state_.next; };
		void setNext(Particle* next)
		{
			state_.next = next;
		}

		bool inUse()
		{
			return framesLeft_ > 0;
		}

		bool animate()
		{
			if (!inUse()) return false;

			framesLeft_--;
			x_ += xVel_;
			y_ += yVel_;

			return framesLeft_ == 0;
		}

	private:
		int framesLeft_;
		double x_, y_;
		double xVel_, yVel_;

		union
		{
			struct
			{
				double x, y, xVel, yVel;
			} live;

			Particle* next;
		} state_;
	};

	class ParticlePool
	{
	public:
		ParticlePool()
		{
			//The first one is available.
			firstAvailable_ = &particles_[0];

			//each particle points to the next..
			for (int i = 0; i < POOL_SIZE - 1; ++i)
			{
				particles_[i].setNext(&particles_[i + 1]);
			}

			//the last one terminates the list.
			particles_[POOL_SIZE - 1].setNext(NULL);
		}

		void create(double x, double y, double xVel, double yVel,
			int lifetime)
		{
			//make sure the pool isn't full.
			assert(firstAvailable_ != NULL);

			//Remove is from the available_ list.
			Particle* newParticle = firstAvailable_;
			firstAvailable_ = newParticle->getNext();

			newParticle->init(x, y, xVel, yVel, lifetime);
		}

		void animate()
		{
			for (int i = 0; i < POOL_SIZE; ++i)
			{
				if (particles_[i].animate())
				{
					//add this particle to the front of the list..
					particles_[i].setNext(firstAvailable_);
					firstAvailable_ = &particles_[i];
				}
			}
		}

	private:
		Particle* firstAvailable_;
		static const int POOL_SIZE = 100;
		Particle particles_[POOL_SIZE];
		int framesLeft_;
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
