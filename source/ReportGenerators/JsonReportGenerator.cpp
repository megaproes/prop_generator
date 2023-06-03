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
