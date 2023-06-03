#include "ReportGenerators/XmlReportGenerator.h"

std::string XmlReportGenerator::getFileExtension() const
{
	return "xml";
}
void XmlReportGenerator::writeData(std::ofstream &outputFile, const std::vector<std::string> &data)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode{doc.append_child("Data")};

	for (const auto &entry : data)
	{
		pugi::xml_node entryNode{rootNode.append_child("Entry")};

		std::stringstream ss(entry);
		std::string line;
		while (std::getline(ss, line))
		{
			size_t separator = line.find(':');
			if (separator != std::string::npos)
			{
				std::string key = line.substr(0, separator);
				std::string value = line.substr(separator + 2); // Skip ": " after the key
				entryNode.append_child(key.c_str()).text().set(value.c_str());
			}
		}
	}

	std::stringstream ss;
	doc.save(ss);
	outputFile << ss.str();
}

// void XmlReportGenerator::generate(const std::vector<std::string> &data)
// {
// 	auto now{std::chrono::system_clock::now()};
// 	std::time_t current_time_t{std::chrono::system_clock::to_time_t(now)};

// 	// Преобразуем время в строку
// 	std::stringstream ss;
// 	ss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d-%H-%M-%S");

// 	// Создаем имя файла
// 	std::string filename{ss.str() + "_xml_properties.xml"};

// 	// Проверяем текущий путь и добавляем к нему имя файла
// 	std::filesystem::path currentPath{std::filesystem::current_path()};
// 	currentPath /= filename;

// 	pugi::xml_document doc;
// 	pugi::xml_node rootNode{doc.append_child("Data")};

// 	for (const auto &entry : data)
// 	{
// 		pugi::xml_node entryNode{rootNode.append_child("Entry")};

// 		std::stringstream ss(entry);
// 		std::string line;
// 		while (std::getline(ss, line))
// 		{
// 			size_t separator = line.find(':');
// 			if (separator != std::string::npos)
// 			{
// 				std::string key = line.substr(0, separator);
// 				std::string value = line.substr(separator + 2); // Skip ": " after the key
// 				entryNode.append_child(key.c_str()).text().set(value.c_str());
// 			}
// 		}
// 	}

// 	if (!doc.save_file(currentPath.c_str()))
// 	{
// 		std::cout << "Some error" << std::endl;
// 	}
// }
