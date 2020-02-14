#pragma once
#define PLATFORM 3
#define PLAYSTATION3 2

#include <iostream>
namespace cp
{
	class FileSystem
	{
	public:
		static FileSystem& instance();

		virtual void create()
		{
			std::cout << "filesystem create" << std::endl;
		}

	protected:
		FileSystem() {}
		//static FileSystem* instance_;
	};

	//FileSystem* FileSystem::instance_ = nullptr;

	class PS3FileSystem :public FileSystem
	{
	public:
		virtual void create() override
		{
			std::cout << "ps3 filesystem create" << std::endl;
		}

	private:
		//PS3FileSystem() {}
	};

	class WiiFileSystem :public FileSystem
	{
	public:
		virtual void create() override
		{
			std::cout << "wii filesystem create" << std::endl;
		}

	private:
		//WiiFileSystem() {}
	};

}

