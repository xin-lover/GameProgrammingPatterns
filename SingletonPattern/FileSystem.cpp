#include "pch.h"
#include "FileSystem.h"

using namespace cp;

FileSystem& FileSystem::instance()
{
	//if (instance_ == nullptr)
	//{
	//	instance_ = new FileSystem();
	//}

	//return *instance_;

	//c++11
	//static FileSystem *instance_ = new FileSystem();
	//return *instance_;

#if PLATFORM == PLAYSTATION3
	static FileSystem* instance_ = new PS3FileSystem();
#else
	static FileSystem* instance_ = new WiiFileSystem();
#endif

	return *instance_;
}
