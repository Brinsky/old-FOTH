#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include "FOTHUtility.h"

foth::dir foth::getOppositeDir(dir a_dir)
{
	dir oppDir = North;

	switch (a_dir)
	{
		case North:
			oppDir = South;
			break;
		case West:
			oppDir = East;
			break;
		case South:
			oppDir = North;
			break;
		case East:
			oppDir = West;
			break;
		default:
			break;
	}

	return oppDir;
}

/// Parses a level file and returns a pointer to a corresponding Grid.
/// Level files should be XML files in accordance with the Schema
/// FOTHLevelSchema.xsd.
/// Thanks to the following posts for the clever vector usage idea
/// (using &vector[0] to access the underlying memory block):
/// http://codereview.stackexchange.com/a/22907
/// http://stackoverflow.com/a/5443512
/// and to the following post about RapidXML usage:
/// http://www.setnode.com/blog/quick-notes-on-how-to-use-rapidxml/
void foth::getLevelGrid(const std::string &filename)
{
    // Get file contents into a RapidXML friendly form

    std::string xmlContents = getFileAsString(filename);

    std::vector<char> xmlData(xmlContents.begin(), xmlContents.end());

    // Final terminating character is required by RapidXML
    xmlData.push_back('\0');

    std::cout << &xmlData[0] << std::endl;

    // Create RapidXML document using file data

    rapidxml::xml_document<> doc;
    doc.parse<0>(&xmlData[0]);



    // Find Grid node and get attributes
    rapidxml::xml_node<>* cur_node = doc.first_node("Grid");
    // I'd rather not use atoi, but C++ 11's stoi isn't well supported yet
    // (e.g. MingW 32-bit)
    int gridWidthGsu = std::atoi(cur_node->first_attribute("width")->value());
    int gridHeightGsu = std::atoi(cur_node->first_attribute("height")->value());

    std::cout << "Grid is of size < " << gridWidthGsu << " , " << gridHeightGsu
        << " >" << std::endl;

    // Find Train node and get attributes
    cur_node = cur_node->first_node("Train");
    int trainXGsu = std::atoi(cur_node->first_attribute("x")->value());
    int trainYGsu = std::atoi(cur_node->first_attribute("y")->value());

    std::cout << "Train will start at ( " << trainXGsu << " , " << trainYGsu
        << " )" << std::endl;
}

/// Reads a file into a string and returns it.
std::string foth::getFileAsString(const std::string &filename)
{
    std::string xmlContents;
    std::string line;

    std::ifstream in(filename.c_str());

    while(std::getline(in,line))
        xmlContents += line;

    return xmlContents;
}
