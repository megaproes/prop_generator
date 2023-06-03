#include "DirectoryReader/DirectoryReader.h"

std::vector<std::string> DirectoryReader::read(const std::string &directoryPath)
{
	std::vector<std::string> properties;
	fs::path dir{directoryPath};
	if (fs::exists(dir) && fs::is_directory(dir))
	{
		for (const auto &entry : fs::directory_iterator{dir})
		{
			std::string property;
			property += "File: " + entry.path().filename().string() + "\n";
			if (fs::is_regular_file(entry))
			{
				property += "Size: " + std::to_string(fs::file_size(entry)) + " bytes\n";
			}
			else
			{
				property += "Size: .\n";
			}
			try
			{
				auto lastWriteTime = fs::last_write_time(entry);
				property += "Modified: " + getTimeString(lastWriteTime) + "\n";
			}
			catch (const std::filesystem::filesystem_error &ex)
			{
				property += std::string{"Modified: Access Denied"} + "\n";
			}

			property += "Type: " + getFileType(entry) + "\n";
			property += "Read-only: " + std::string(fs::is_regular_file(entry) && isReadOnly(entry) ? "Yes" : "No") + "\n";

			properties.push_back(property);
		}
	}
	else
		throw std::runtime_error{directoryPath + " does not exist or not a directory"};

	return properties;
}

std::string DirectoryReader::getTimeString(const std::filesystem::file_time_type &time)
{
	auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(time - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
	std::time_t c_time = std::chrono::system_clock::to_time_t(sctp);
	std::string timeString = std::ctime(&c_time);
	timeString.pop_back(); // Removes newline character from the end
	return timeString;
}
std::string DirectoryReader::getFileType(const std::filesystem::directory_entry &entry)
{
	if (fs::is_directory(entry))
		return "Directory";
	else if (fs::is_regular_file(entry))
		return "Regular File";
	else if (fs::is_symlink(entry))
		return "Symbolic Link";
	else
		return "Unknown";
}
bool DirectoryReader::isReadOnly(const std::filesystem::directory_entry &entry)
{
	auto p = fs::status(entry).permissions();

	return (p & fs::perms::owner_write) == fs::perms::none && (p & fs::perms::group_write) == fs::perms::none && (p & fs::perms::others_write) == fs::perms::none;
}
