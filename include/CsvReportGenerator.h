#pragma once
#include "ReportGenerator.h"

class CsvReportGenerator : public ReportGenerator
{
public:
	CsvReportGenerator() = default;
	std::string getFileExtension() const override;
	void writeData(std::ofstream &outputFile, const std::vector<std::string> &data) override;
};
