#pragma once
#include "ReportGenerator.h"
#include "nlohmann/json.hpp"

class JsonReportGenerator : public ReportGenerator
{
public:
	JsonReportGenerator() = default;
	std::string getFileExtension() const override;
	void writeData(std::ofstream &outputFile, const std::vector<std::string> &data) override;
};