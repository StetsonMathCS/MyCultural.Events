#include "pugixml.hpp"
#include <iostream>
#include <stdlib.h>
#include "../database.h"
#include "../ccevent.h"

using namespace std;

int main()
{
	system("curl -o feed.rss https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss");
	pugi::xml_document RSSfeed;
	RSSfeed.load_file("feed.rss");
	//RSSfeed.load_file("cultural-credits.rss");
	pugi::xml_node root = RSSfeed.child("rss").child("channel");
	database db;
	
	const string NC = "\e[0m";
	const string BOLD = "\e[1m";
	const string RED = "\e[38;5;196m";

	for (pugi::xml_node item = root.child("item"); item; item = item.next_sibling("item"))
	{
		string title = item.child("title").child_value();
		string description = item.child("description").child_value();
		string pubdate = item.child("pubDate").child_value();
		string link = item.child("link").child_value();
		string guid = item.child("guid").child_value();
		
		string curl = "curl -o tmp.html ";
		string command = curl.append(link);
		system(command.c_str());
		pugi::xml_document eventPage;
		eventPage.load_file("tmp.html");
		string location = eventPage.child("html").child("body").child("div").child("article").child("div").last_child().child_value();
		system("rm tmp.html");

		cout << RED << "title: " << NC << BOLD << title << NC << endl;
		if (description!="")
		{	
			//cout << RED << "description: " << NC << description << endl;
		} else 
		{
			//cout << RED << "no description" << NC << endl;
		}
		//cout << RED << "pubDate: " << NC << pubdate << endl;
		//cout << location << endl;
		//cout << RED << "link: " << NC << link << endl;
		//cout << RED << "guid: " << NC << guid << endl;
		//cout << endl << endl;
		
		
		bool hasEvent = false;
		for (int i = 1; i <= db.rowsInEventTable(); i++)
		{
			vector<CCEvent> vector = db.searchEventById(i);
			if (vector.size() != 0)
			{
				CCEvent event = vector[0];
				if (title == event.getTitle() && pubdate == event.getDateTime())
				{
					hasEvent = true;
				}
			}	
		}
		if (hasEvent == false)
		{
			db.insertEventData(title, pubdate, location, description);
		}
	}
	
	cout << endl << endl << endl;
	for (int i = 1; i <= db.rowsInEventTable(); i++)
	{
		db.searchEventById(i);
	}
}
