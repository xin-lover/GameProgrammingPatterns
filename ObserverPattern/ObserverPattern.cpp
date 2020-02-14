// ObserverPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace cp
{
	class Entity
	{
	public:
		Entity(std::string name):name_(name) {}
		~Entity() {}

		std::string GetName() const
		{
			return name_;
		}

	private:
		std::string name_;
	};

	class Event
	{
	public:
		Event() {}
		~Event() {}
	};

	class Observer
	{
	public:
		virtual ~Observer() {}
		virtual void onNotify(const Entity& entity, Event event)
		{
			std::cout <<"notify " << entity.GetName() << std::endl;
		}

		int GetID()
		{
			return id_;
		}

	private:
		int id_;
	};

	class Subject
	{
	public:
		void addObserver(Observer* observer)
		{
			observers_.push_back(observer);
		}

		void removeObserver(Observer* observer)
		{
			auto it = find(observers_.begin(), observers_.end(), observer);
			if (it != observers_.end())
			{
				observers_.erase(it);
			}
		}

		void Notify(const Entity& entity, Event event)
		{
			for (auto a : observers_)
			{
				a->onNotify(entity, event);
			}
		}

	private:
		vector<Observer*> observers_;
	};
}

int main()
{
	cp::Subject subject;
	cp::Observer ob1;
	cp::Observer ob2;
	subject.addObserver(&ob1);
	subject.addObserver(&ob2);
	cp::Entity ent1("abc");
	subject.Notify(ent1, cp::Event());
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
