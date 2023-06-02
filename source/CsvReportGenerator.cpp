#include "CsvReportGenerator.h"

std::string CsvReportGenerator::getFileExtension() const
{
	return "csv";
}

void CsvReportGenerator::writeData(std::ofstream &outputFile, const std::vector<std::string> &data)
{
	auto writer = csv::make_csv_writer(outputFile);
	writer << std::vector<std::string>({"File", "Size", "Modified", "Type", "Read-only"});
	for (const auto &entry : data)
	{
		std::istringstream iss(entry);
		std::vector<std::string> row;
		std::string line;
		while (std::getline(iss, line))
		{
			row.push_back(line);
		}
		writer << row;
	}
}

// void CsvReportGenerator::generate(const std::vector<std::string> &data)
// {
// 	// Получаем текущее время
// 	auto now{std::chrono::system_clock::now()};
// 	std::time_t current_time_t{std::chrono::system_clock::to_time_t(now)};

// 	// Преобразуем время в строку
// 	std::stringstream ss;
// 	ss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d-%H-%M-%S");

// 	// Создаем имя файла
// 	std::string filename{ss.str() + "_csv_properties.csv"};

// 	// Проверяем текущий путь и добавляем к нему имя файла
// 	std::filesystem::path currentPath{std::filesystem::current_path()};
// 	currentPath /= filename;

// 	std::ofstream outputFile{currentPath.string()};
// 	auto writer = csv::make_csv_writer(outputFile);
// 	writer << std::vector<std::string>({"File", "Size", "Modified", "Type", "Read-only"});
// 	for (const auto &entry : data)
// 	{
// 		std::istringstream iss(entry);
// 		std::vector<std::string> row;
// 		std::string line;
// 		while (std::getline(iss, line))
// 		{
// 			row.push_back(line);
// 		}
// 		writer << row;
// 	}
// 	outputFile.close();
// }