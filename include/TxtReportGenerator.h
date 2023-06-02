#pragma once
#include "ReportGenerator.h"

class TxtReportGenerator : public ReportGenerator
{
public:
	TxtReportGenerator() = default;
	std::string getFileExtension() const override;
	void writeData(std::ofstream &outputFile, const std::vector<std::string> &data) override;
};