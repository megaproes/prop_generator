#include "DirectoryReader/DirectoryReader.h"

// Method to read the properties of all the files and directories in the given directoryPath
std::vector<std::string> DirectoryReader::read(const std::string &directoryPath)
{
	// Vector to store properties of files/directories
	std::vector<std::string> properties;

	fs::path dir{directoryPath};

	// Check if the directory exists and it is actually a directory
	if (fs::exists(dir) && fs::is_directory(dir))
	{
		// Iterate over each entry in the directory
		for (const auto &entry : fs::directory_iterator{dir})
		{
			std::string property;

			// Getting the name of the file
			property += "File: " + entry.path().filename().string() + "\n";

			// Checking if entry is a file to get its size
			if (fs::is_regular_file(entry))
			{
				property += "Size: " + std::to_string(fs::file_size(entry)) + " bytes\n";
			}
			else
			{
				property += "Size: .\n";
			}

			// Getting the last modification time
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
		// If directory doesn't exist or path isn't a directory, throw an error
		throw std::runtime_error{directoryPath + " does not exist or not a directory"};

	return properties;
}

// Method to convert filesystem time to a string representation
std::string DirectoryReader::getTimeString(const std::filesystem::file_time_type &time)
{
	// Convert filesystem time to system time
	auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(time - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());

	std::time_t c_time = std::chrono::system_clock::to_time_t(sctp);

	std::string timeString = std::ctime(&c_time);

	// Removes newline character from the end
	timeString.pop_back();

	return timeString;
}

// Method to determine the type of the file
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

// Method to check if a file is read-only
bool DirectoryReader::isReadOnly(const std::filesystem::directory_entry &entry)
{
	// Get the file permissions
	auto p = fs::status(entry).permissions();

	// Check if write permissions are denied for all (owner, group, others)
	return (p & fs::perms::owner_write) == fs::perms::none && (p & fs::perms::group_write) == fs::perms::none && (p & fs::perms::others_write) == fs::perms::none;
}
