#include "ReportGenerators/JsonReportGenerator.h"

std::string JsonReportGenerator::getFileExtension() const
{
	return "json";
}

void JsonReportGenerator::writeData(std::ofstream &outputFile, const std::vector<std::string> &data)
{
	nlohmann::json jsonArray;
	for (auto &entry : data)
	{
		jsonArray.push_back(entry);
	}

	outputFile << jsonArray.dump(4);

	outputFile.close();
}

// void JsonReportGenerator::generate(const std::vector<std::string> &data)
// {
// 	auto now{std::chrono::system_clock::now()};
// 	std::time_t current_time_t{std::chrono::system_clock::to_time_t(now)};

// 	// Преобразуем время в строку
// 	std::stringstream ss;
// 	ss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d-%H-%M-%S");

// 	// Создаем имя файла
// 	std::string filename{ss.str() + "_json_properties.json"};

// 	// Проверяем текущий путь и добавляем к нему имя файла
// 	std::filesystem::path currentPath{std::filesystem::current_path()};
// 	currentPath /= filename;

// 	std::ofstream outputFile{currentPath.string()};

// 	nlohmann::json jsonArray;

// 	for (auto &entry : data)
// 	{
// 		jsonArray.push_back(entry);
// 	}

// 	outputFile << jsonArray.dump(4);

// 	outputFile.close();
// }
