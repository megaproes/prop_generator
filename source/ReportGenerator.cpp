#include "ReportGenerator.h"
void ReportGenerator::generate(const std::vector<std::string> &data)
{
	auto filename = generateFilename();
	std::filesystem::path currentPath{std::filesystem::current_path()};
	currentPath /= filename;
	
	std::ofstream outputFile{currentPath.string()};
	if (!outputFile.is_open())
	{
		throw std::runtime_error("Failed to open file for writing");
	}
	
	writeData(outputFile, data);

	outputFile.close();
}

std::string ReportGenerator::generateFilename() const
{
	auto now{std::chrono::system_clock::now()};
	std::time_t current_time_t{std::chrono::system_clock::to_time_t(now)};

	std::stringstream ss;
	ss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d-%H-%M-%S");

	return ss.str() + "_" + getFileExtension() + "_properties." + getFileExtension();
}
