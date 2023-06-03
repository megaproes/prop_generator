#pragma once
#include "ReportGenerators/ReportGenerator.h"
#include <memory>
class ReportFactory
{
public:
	enum class ReportType
	{
		Txt,
		Json,
		Xml,
		Csv
	};
	// Factory method for creating the right report generator based on the given report type
	static std::unique_ptr<ReportGenerator> createReportGenerator(ReportFactory::ReportType type);
};
