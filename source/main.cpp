#include <iostream>
#include <vector>
#include "ReportFactory/ReportFactory.h"
#include "DirectoryReader/DirectoryReader.h"

std::vector<std::string> readDirectory(const std::string &directoryPath)
{
	DirectoryReader reader;
	try
	{
		return reader.read(directoryPath);
	}
	catch (const std::runtime_error &exc)
	{
		std::cerr << "Error reading directory: " << exc.what() << '\n';
		throw;
	}
}

void generateReport(ReportFactory::ReportType reportType, const std::vector<std::string> &data)
{
	try
	{
		auto reportGenerator = ReportFactory::createReportGenerator(reportType);
		reportGenerator->generate(data);
	}
	catch (const std::runtime_error &exc)
	{
		std::cerr << "Error generating report: " << exc.what() << '\n';
		throw;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "Usage: <directory> <report_type_1> ...<report_type_n>" << std::endl;
		return 1;
	}

	const std::string directoryPath{argv[1]};
	std::vector<std::string> data;

	try
	{
		data = readDirectory(directoryPath);
	}
	catch (const std::runtime_error &)
	{
		return 1;
	}

	const std::unordered_map<std::string, ReportFactory::ReportType> reportTypeMap{
	    {"txt", ReportFactory::ReportType::Txt},
	    {"json", ReportFactory::ReportType::Json},
	    {"xml", ReportFactory::ReportType::Xml},
	    {"csv", ReportFactory::ReportType::Csv}};

	int failedReportsCount = 0;
	for (int i = 2; i < argc; ++i)
	{
		const std::string reportTypeStr{argv[i]};
		const auto it = reportTypeMap.find(reportTypeStr);

		if (it == reportTypeMap.end())
		{
			std::cout << "Invalid report type: " << reportTypeStr << std::endl;
			++failedReportsCount;
			continue;
		}

		try
		{
			generateReport(it->second, data);
		}
		catch (const std::runtime_error &)
		{
			++failedReportsCount;
		}
	}

	const int successfulReportsCount = argc - 2 - failedReportsCount;
	if (successfulReportsCount > 0)
	{
		std::cout << successfulReportsCount << " files are generated to '" << directoryPath << "'\n";
	}
	else
	{
		std::cout << "No files generated. Make sure there is a correct format: <directory> <report_type_1> ...<report_type_n>\n";
	}

	return 0;
}
