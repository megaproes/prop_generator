#pragma once
#include "ReportGenerator.h"
#include "pugixml-master/pugixml.hpp"

class XmlReportGenerator : public ReportGenerator
{

public:
	XmlReportGenerator() = default;
	std::string getFileExtension() const override;
	void writeData(std::ofstream &outputFile, const std::vector<std::string> &data) override;
};
