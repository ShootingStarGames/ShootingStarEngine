#pragma once

namespace shootingStar
{
	namespace system
	{
		class FileSystem
		{
		private:
			FileSystem() = delete;
		
		public:
			static bool FileExists(const std::string& path);
			static long GetFileSize(const std::string& path);

			static char* ReadFile(const std::string& path);
			static bool ReadFile(const std::string& path, char* buffer, long length = -1);
			static std::string ReadTextFile(const std::string& path);

			static bool WriteFile(const std::string& path, char* buffer, bool overwrite = true);
			static bool WriteTextFile(const std::string& path, const std::string& text, bool overwrite = true);
		};
	}
}

