// DirtyFlagPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Transform
	{
	public:
		static Transform origin();

		Transform combine(Transform& other);
	};

	class Mesh;

	class GraphNode
	{
	public:
		GraphNode(Mesh* mesh)
			:mesh_(mesh),                                                                                                                                                                                                                                                                            
			local_(Transform::origin()),
			dirty_(true)
		{}

		void renderMesh(Mesh* mesh, Transform world)
		{

		}
		//void render(Transform parent)
		//{
		//	Transform world = local_.combine(parent);
		//	if (mesh_) renderMesh(mesh_, world);

		//	for (int i = 0; i < numChildren_; ++i)
		//	{
		//		children_[i]->render(world);
		//	}
		//}
		void render(Transform parentWorld, bool dirty)
		{
			dirty |= dirty_;
			if (dirty)
			{
				world_ = local_.combine(parentWorld);
				dirty_ = false;
			}

			if (mesh_) renderMesh(mesh_, world_);
			for (int i = 0; i < numChildren_; ++i)
			{
				children_[i]->render(world_, dirty);
			}
		}


		void RenderMesh(Mesh* mesh, Transform& transform)
		{
			//render  code
		}

		void setTransform(Transform local)
		{
			local_ = local;
			dirty_ = true;
		}


	private:
		Transform local_;
		Mesh* mesh_;

		static const int MAX_CHILDREN = 100;
		GraphNode* children_[MAX_CHILDREN];
		int numChildren_;
		bool dirty_;
		Transform world_;
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
