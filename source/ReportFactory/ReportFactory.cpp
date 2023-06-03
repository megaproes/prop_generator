#include "ReportFactory/ReportFactory.h"
#include "ReportGenerators/TxtReportGenerator.h"
#include "ReportGenerators/JsonReportGenerator.h"
#include "ReportGenerators/XmlReportGenerator.h"
#include "ReportGenerators/CsvReportGenerator.h"
std::unique_ptr<ReportGenerator> ReportFactory::createReportGenerator(ReportFactory::ReportType type)
{
	switch (type)
	{
	case ReportFactory::ReportType::Txt:
		return std::make_unique<TxtReportGenerator>();
		break;
	case ReportFactory::ReportType::Json:
		return std::make_unique<JsonReportGenerator>();
		break;
	case ReportFactory::ReportType::Csv:
		return std::make_unique<CsvReportGenerator>();
		break;
	case ReportFactory::ReportType::Xml:
		return std::make_unique<XmlReportGenerator>();
		break;

	default:
		throw std::runtime_error("Invalid report type");
	}
}
