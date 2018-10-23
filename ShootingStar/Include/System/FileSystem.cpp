#include "../stdafx.h"
#include "FileSystem.h"

namespace shootingStar
{
	namespace system
	{
		bool FileSystem::FileExists(const std::string & path)
		{
			return GetFileSize(path);
		}
		long FileSystem::GetFileSize(const std::string & path)
		{
			std::ifstream file(path, std::ifstream::ate | std::ifstream::binary);
			long size = file.tellg();
			file.close();
			return size;  // if file is ot exists return -1
		}
		char * FileSystem::ReadFile(const std::string & path)
		{
			long length = GetFileSize(path);

			if (length < 1)
			{
				std::cout << "File not exist" << std::endl;
				exit(0);
			}
			char* buffer = new char[length];
			if (ReadFile(path, buffer, length))
				return buffer;
			delete[] buffer;
			return nullptr;
		}
		bool FileSystem::ReadFile(const std::string & path, char * buffer, long length)
		{
			std::ifstream file(path, std::ifstream::in | std::ifstream::binary);
			if (!file)
				return false;
			file.seekg(0, file.end);
			if (length < 0)
				length = file.tellg();
			file.seekg(0, file.beg);
			file.read(buffer, length);
			file.close();
			return true;
		}
		std::string FileSystem::ReadTextFile(const std::string & path)
		{
			std::ifstream file(path, std::ifstream::in);
			if (!file)
				return std::string("");
			std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
			return str;
		}
		bool FileSystem::WriteFile(const std::string & path, char * buffer, bool overwrite)
		{
			if (!overwrite && FileExists(path))
				return false;
			std::ofstream file(path.c_str(), std::ifstream::binary);
			file.write(buffer, strlen(buffer));
			file.close();
			return true;
		}
		bool FileSystem::WriteTextFile(const std::string & path, const std::string & text, bool overwrite)
		{
			return WriteFile(path, (char*)&text[0], overwrite);
		}	
	}
}