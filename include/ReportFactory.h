#pragma once
#include "ReportGenerator.h"

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
	static std::unique_ptr<ReportGenerator> createReportGenerator(ReportFactory::ReportType type);
};
