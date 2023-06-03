#include "ReportGenerators/XmlReportGenerator.h"

std::string XmlReportGenerator::getFileExtension() const
{
	return "xml";
}
void XmlReportGenerator::writeData(std::ofstream &outputFile, const std::vector<std::string> &data)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode{doc.append_child("Data")};

	for (const auto &entry : data)
	{
		pugi::xml_node entryNode{rootNode.append_child("Entry")};

		std::stringstream ss(entry);
		std::string line;
		while (std::getline(ss, line))
		{
			// For each line in the entry, add it as a child node to the entry node
			size_t separator = line.find(':');
			if (separator != std::string::npos)
			{
				std::string key = line.substr(0, separator);
				std::string value = line.substr(separator + 2); // Skip ": " after the key
				entryNode.append_child(key.c_str()).text().set(value.c_str());
			}
		}
	}
	// Convert the XML document to a string and write it to the output file
	std::stringstream ss;
	doc.save(ss);
	outputFile << ss.str();
}
