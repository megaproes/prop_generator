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
