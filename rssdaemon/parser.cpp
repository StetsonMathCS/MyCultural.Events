#include "pugixml.hpp"
#include <iostream>
#include "../database.h"
#include "../ccevent.h"

using namespace std;

int main()
{
	pugi::xml_document doc;
	doc.load_file("cultural-credits.rss");
	pugi::xml_node root = doc.child("rss").child("channel");
	database db;
	const string NC = "\e[0m";
	const string BOLD = "\e[1m";
	const string RED = "\e[38;5;196m";

	for (pugi::xml_node item = root.child("item"); item; item = item.next_sibling("item"))
	{
		string title = item.child("title").child_value();
		if (title.find('*')!=string::npos)
		{
			for (unsigned int i = 0; i < title.length(); i++)

				title = title.substr(1,title.length()-1);
		}
		string description = item.child("description").child_value();
		string pubdate = item.child("pubDate").child_value();
		string link = item.child("link").child_value();
		string guid = item.child("guid").child_value();
		
		
		//cout << RED << "title: " << NC << BOLD << title << NC << endl;
		if (description!="")
		{	
			//cout << RED << "description: " << NC << description << endl;
		} else 
		{
			//cout << RED << "no description" << NC << endl;
		}
		//cout << RED << "pubDate: " << NC << pubdate << endl;
		//cout << RED << "link: " << NC << link << endl;
		//cout << RED << "guid: " << NC << guid << endl;
		//cout << endl << endl;
		/*
		bool hasEvent = false;
		for (int i = 1; i <= db.rowsInEventTable(); i++)
		{
			vector<CCEvent> vector = db.searchEventById(i);
			if (vector.size() != 0)
			{
				CCEvent event = vector[0];
				if (title == event.getTitle())
				{
					hasEvent = true;
				}
			}	
		}
		if (hasEvent == false)
		{
			db.insertEventData(title, pubdate, "no location", description);
		}
		*/
	}
	
			
	for (int i = 1; i <= db.rowsInEventTable(); i++)
	{
		db.searchEventById(i);
		cout << i << endl;
	}
	cout << db.rowsInEventTable() << " rows" << endl;
}
