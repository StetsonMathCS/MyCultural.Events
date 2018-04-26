#include "pugixml.hpp"
#include <iostream>

using namespace pugi;

int main()
{
	xml_document doc;
	doc.load_file("cultural-credits.rss");
	xml_node root = doc.child("rss").child("channel");
	const std::string NC = "\e[0m";
	const std::string BOLD = "\e[1m";
	const std::string RED = "\e[38;5;196m";
	std::cout << std::endl;

	for (xml_node item = root.child("item"); item; item = item.next_sibling("item"))
	{
		std::cout << RED << "title: " << NC << BOLD << item.child("title").child_value() << NC << std::endl;
		std::string description = item.child("description").child_value();
		if (description!="")
		{	
			std::cout << RED << "description: " << NC << item.child("description").child_value() << std::endl;
		} else 
		{
			std::cout << RED << "no description" << NC << std::endl;
		}
		std::cout << RED << "pubDate: " << NC << item.child("pubDate").child_value() << std::endl;
		std::cout << RED << "link: " << NC << item.child("link").child_value() << std::endl;
		std::cout << RED << "guid: " << NC << item.child("guid").child_value() << std::endl;
		std::cout << std::endl << std::endl;
	}
}
