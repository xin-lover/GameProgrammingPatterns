// SpatialPartitionPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

namespace cp
{
	class Unit
	{
		friend class Grid;
	public:
		Unit(Grid* grid, double x, double y) :
			grid_(grid),
			x_(x),
			y_(y), 
			prev_(NULL),
			next_(NULL)
		{
			grid_->add(this);
		}

		void move(double x, double y)
		{
			grid_->move(this, x, y);
		}
	private:
		double x_, y_;
		Grid* grid_;
		Unit* prev_;
		Unit* next_;
	};

	class Grid
	{
	public:
		Grid()
		{
			//clear grid
			for (int x = 0; x < NUM_CELLS; ++x)
			{
				for (int y = 0; y < NUM_CELLS; ++y)
				{
					cells_[x][y] = NULL;
				}
			}
		}

		void add(Unit* unit)
		{
			//Determine which grid cell it's in.
			int cellX = (int)(unit->x_ / Grid::CELL_SIZE);
			int cellY = (int)(unit->y_ / Grid::CELL_SIZE);

			//add to the front of list for the cell it's in.
			unit->prev_ = NULL;
			unit->next_ = cells_[cellX][cellY];
			cells_[cellX][cellY] = unit;

			if (unit->next_ != NULL)
			{
				unit->next_->prev_ = unit;
			}
		}



		void move(Unit* unit, double x, double y)
		{
			//see which cell it was in.
			int oldCellX = (int)(unit->x_ / Grid::CELL_SIZE);
			int oldCellY = (int)(unit->y_ / Grid::CELL_SIZE);

			//see which cell it's moving to.
			int cellX = (int)(x / Grid::CELL_SIZE);
			int cellY = (int)(y / Grid::CELL_SIZE);

			unit->x_ = x;
			unit->y_ = y;

			//if don't change cell, we're done.
			if (oldCellX == cellX && oldCellY == cellY) return;

			//Unlink it from the list of its old cell.
			if (unit->prev_ != NULL)
			{
				unit->prev_->next_ = unit->next_;
			}

			if (unit->next_ != NULL)
			{
				unit->next_->prev_ = unit->prev_;
			}

			//if it's the head of a list,remove it
			if (cells_[oldCellX][oldCellY] == unit)
			{
				cells_[oldCellX][oldCellY] == unit->next_;
			}

			//Add it back to the grid at its new cell.
			add(unit);
		}

		void handleCell(Unit* unit)
		{
			while (unit != NULL)
			{
				Unit* other = unit->next_;
				while (other != NULL)
				{
					if (unit->x_ == other->x_ && unit->y_ == other->y_)
					{
						handleAttack(unit, other);
					}

					other = other->next_;
				}

				unit = unit->next_;
			}
		}

		void handleAttack(Unit* unit, Unit* other)
		{
			//attack code
		}

		//which attack by distance
		//if(distance(unit,other) < ATTACK_DISTANCE)
		//{
		//	handleAttack(unit, other);
		//}
		//void handleUnit(Unit* unit, Unit* other)
		//{
		//	while (other != NULL)
		//	{
		//		if (distance(unit, other) < ATTACK_DISTANCE)
		//		{
		//			handleAttack(unit, other);
		//		}

		//		other = other->next_;
		//	}
		//}

		//void handleCell(int x, int y)
		//{
		//	Unit* unit = cells_[x][y];
		//	while (unit != NULL)
		//	{
		//		//Handle other units in this cell。
		//		handleUnit(unit, unit->next_);

		//		//also try the neighboring cells.
		//		if (x > 0) handleUnit(unit, cells_[x - 1][y]);
		//		if (y > 0) handleUnit(unit, cells_[x - 1][y]);
		//		if (x > 0 && y > 0)
		//			handleUnit(unit, cells_[x - 1][y - 1]);
		//		if (x > 0 && y < NUM_CELLS - 1)
		//			handleUnit(unit, cells_[x - 1][y + 1]);

		//		unit = unit->next_;
		//	}
		//}

		static const int NUM_CELLS = 10;
		static const int CELL_SIZE = 20;
	private:
		Unit* cells_[NUM_CELLS][NUM_CELLS];
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
