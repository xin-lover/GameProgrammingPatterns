// ComponentPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class World;
	class Graphics;
	class Velume;
	class Sprite;

	enum JoystickDir
	{
		DIR_LEFT,
		DIR_RIGHT
	};

	class Controller
	{
	public:
		static JoystickDir getJoystickDirection()
		{
			return DIR_LEFT;
		}
	};

	class OldBjorn
	{
	public:
		OldBjorn() :velocity_(0), x_(0), y_(0) {}
		void update(World& world, Graphics& graphics);
	private:
		static const int WALK_ACCELERATION = 1;
		int velocity_;
		int x_, y_;
		Velume volume_;
		Sprite spriteStand_;
		Sprite spriteWalkLeft_;
		Sprite spriteWalkRight_;
	};

	void OldBjorn::update(World& world, Graphics& graphics)
	{
		//Apply user input to hero's velocity.
		switch (Controller::getJoystickDirection())
		{
		case DIR_LEFT:
			velocity_ -= WALK_ACCELERATION;
			break;
		case DIR_RIGHT:
			velocity_ += WALK_ACCELERATION;
			break;
		default:
			break;
		}

		x_ += velocity_;
		world.resolveCollision(volume_, x_, y_, velocity_);

		//Draw the apropriate sprite
		Sprite* sprite = &spriteStand_;
		if (velocity_ < 0) sprite = &spriteWalkLeft_;
		else if (velocity_ > 0) sprite = &spriteWalkRight_;

		graphics.draw(*sprite, x_, y_);

	};

	class PhysicsComponent
	{
		public：
			void update(Bjorn& bjorn, World& world)
		{
			bjorn.x += bjorn.velocity;
			world.resolveCollision(volume_, bjorn.x, bjorn.y, bjorn.velocity);
		}

	private:
		Volume volume_;
	};

	class GraphicsComponent
	{
	public:
		void update(Bjorn& bjorn, Graphics& graphics)
		{
			Sprite* sprite = &spriteStand_;
			if (bjorn.velocity < 0)
			{
				sprite = &spriteWalkLeft_;
			}
			else if (bjorn.velocity > 0)
			{
				sprite = &spriteWalkRight_;
			}

			graphics.draw(*sprite, bjorn.x, bjorn.y);
		}

	private:
		Sprite spriteStand_;
		Sprite spriteWalkLeft_;
		Sprite spriteWalkRight_;
	};

	class GameObject
	{
	public:
		int velocity;
		int x, y;

		GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics)
			:input_(input), physics_(physics), graphics_(graphics)
		{

		}


		void update(World& world, Graphics& graphics)
		{
			input_->update(*this);
			physics_->update(*this, world);
			graphics_->update(*this, graphics);
		}

	private:
		InputComponent *input_;
		PhysicsComponent *physics_;
		GraphicsComponent *graphics_;
	};

	GameObject* createBjorn()
	{
		return new GameObject(
			new PlayerInputComponent(),
			new BjornPhysicsComponent(),
			new BjornGraphicsComponent());
	}
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
