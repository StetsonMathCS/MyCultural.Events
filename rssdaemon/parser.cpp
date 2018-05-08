#include "pugixml.hpp"
#include <iostream>
#include <stdlib.h>
#include "../database.h"
#include "../ccevent.h"

using namespace std;

int main(int argc, const char **argv)
{
	if (argc !=2)
	{
		cout << "Usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}

	system("curl -o feed.rss https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss");
	pugi::xml_document RSSfeed;
	RSSfeed.load_file("feed.rss");
	pugi::xml_node root = RSSfeed.child("rss").child("channel");

	database db(argv[1]);
	
	const string NC = "\e[0m";
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

		cout << endl << RED << "title: " << NC << title << endl;
		cout << RED << "pubDate: " << NC << pubdate << endl << endl;
		db.insertEventData(title, pubdate, location, description);
	}
}
