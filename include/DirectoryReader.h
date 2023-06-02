#pragma once
#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
class DirectoryReader
{
public:
	DirectoryReader() = default;
	std::vector<std::string> read(const std::string &_directoryPath);

private:
	std::string getTimeString(const std::filesystem::file_time_type &time);
	std::string getFileType(const std::filesystem::directory_entry &entry);
	bool isReadOnly(const std::filesystem::directory_entry &entry);
};
