#include "pugixml.hpp"
#include <iostream>
#include <stdlib.h>
#include "../database.h"
#include "../ccevent.h"

using namespace std;

int main(int argc, const char **argv)
{	
	//checks if you put in location of database as an argument
	if (argc !=2)
	{
		cout << "Usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}
	database db(argv[1]);
	
	//downloads rss feed
	system("curl -o feed.rss https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss");
	pugi::xml_document RSSfeed;
	RSSfeed.load_file("feed.rss");
	pugi::xml_node root = RSSfeed.child("rss").child("channel");

	//strings for making text red and changing it back to white
	const string NC = "\e[0m";
	const string RED = "\e[38;5;196m";
	
	//for each cultural event in the feed
	for (pugi::xml_node item = root.child("item"); item; item = item.next_sibling("item"))
	{
		string title = item.child("title").child_value();
		string description = item.child("description").child_value();
		string pubdate = item.child("pubDate").child_value();
		string link = item.child("link").child_value();
		
		//downloads file from cultural event link and retrives the location that is not present in rss file
		string curl = "curl -o tmp.html ";
		string command = curl.append(link);
		system(command.c_str());
		pugi::xml_document eventPage;
		eventPage.load_file("tmp.html");
		string location = eventPage.child("html").child("body").child("div").child("article").child("div").last_child().child_value();
		system("rm tmp.html");
		
		//prints out title and pubDate for debugging pourposes
		cout << endl << RED << "title: " << NC << title << endl;
		cout << RED << "pubDate: " << NC << pubdate << endl << endl;

		//inserts the event into the database
		db.insertEventData(title, pubdate, location, description);
	}
}
