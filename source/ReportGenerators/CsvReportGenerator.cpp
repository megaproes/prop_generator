#include "ReportGenerators/CsvReportGenerator.h"

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