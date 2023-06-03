#include "ReportGenerators/TxtReportGenerator.h"

std::string TxtReportGenerator::getFileExtension() const
{
	return "txt";
}
void TxtReportGenerator::writeData(std::ofstream &outputFile, const std::vector<std::string> &data)
{
	for (const auto &vs : data)
	{
		outputFile << vs << std::endl;
	}
}

// void TxtReportGenerator::generate(const std::vector<std::string> &data)
// {
// 	// Получаем текущее время
// 	auto now{std::chrono::system_clock::now()};
// 	std::time_t current_time_t{std::chrono::system_clock::to_time_t(now)};

// 	// Преобразуем время в строку
// 	std::stringstream ss;
// 	ss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d-%H-%M-%S");

// 	// Создаем имя файла
// 	std::string filename{ss.str() + "_txt_properties.txt"};

// 	// Проверяем текущий путь и добавляем к нему имя файла
// 	std::filesystem::path currentPath{std::filesystem::current_path()};
// 	currentPath /= filename;

// 	std::ofstream outputFile{currentPath.string()};
// 	for (const auto &vs : data)
// 	{
// 		outputFile << vs << std::endl;
// 	}

// 	outputFile.close();
// }
