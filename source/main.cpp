#include <iostream>
#include <vector>
#include "ReportFactory.h"
#include "DirectoryReader.h"

std::vector<std::string> readDirectory(const std::string &directoryPath)
{
	DirectoryReader reader;
	try
	{
		return reader.read(directoryPath);
	}
	catch (const std::runtime_error &exc)
	{
		std::cerr << exc.what() << '\n';
		exit(1);
	}
}

void generateReport(ReportFactory::ReportType reportType, const std::vector<std::string> &data)
{
	try
	{
		std::unique_ptr<ReportGenerator> reportGenerator{ReportFactory::createReportGenerator(reportType)};
		reportGenerator->generate(data);
	}
	catch (const std::runtime_error &exc)
	{
		std::cerr << exc.what() << '\n';
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "Wrong format . . ." << std::endl;
		std::cout << "Usage: "
				<< " <directory> <report_type_1> ...<report_type_n>" << std::endl;
		return 1;
	}
	const std::string directoryPath{argv[1]};
	std::vector<std::string> data = readDirectory(directoryPath);

	const auto reportTypeMap = std::unordered_map<std::string, ReportFactory::ReportType>{
	    {"txt", ReportFactory::ReportType::Txt},
	    {"json", ReportFactory::ReportType::Json},
	    {"xml", ReportFactory::ReportType::Xml},
	    {"csv", ReportFactory::ReportType::Csv}};

	for (int i = 2; i < argc; i++)
	{
		const std::string reportTypeStr{argv[i]};
		const auto it = reportTypeMap.find(reportTypeStr);
		if (it == reportTypeMap.end())
		{
			std::cout << "Invalid report type: " << reportTypeStr << std::endl;
			continue;
		}
		generateReport(it->second, data);
	}

	std::cout << "Success" << std::endl;
	return 0;
}
