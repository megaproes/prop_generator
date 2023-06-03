#pragma once
#include <vector>
#include <string>
#include <iomanip>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

#include <chrono>
#include <ctime>

class ReportGenerator
{
public:
	virtual ~ReportGenerator() = default;
	void generate(const std::vector<std::string> &data);

protected:
	virtual std::string getFileExtension() const = 0;
	virtual void writeData(std::ofstream &outputFile, const std::vector<std::string> &data) = 0;

private:
	std::string generateFilename() const;
};
