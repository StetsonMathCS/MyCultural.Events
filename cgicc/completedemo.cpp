/*
 *  $Id: test_8cpp-source.html,v 1.3 2008/01/19 21:53:50 sebdiaz Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
 *                       2007 Sebastien DIAZ <sebastien.diaz@gmail.com>
 *  Part of the GNU cgicc library, http://www.gnu.org/software/cgicc
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
 */

#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "../database.h"


#if HAVE_SYS_UTSNAME_H
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

#include "styles.h"

using namespace std;
using namespace cgicc;

// Function prototypes
void dumpEnvironment(const CgiEnvironment& env);
void dumpList(const Cgicc& formData);
void showForm(const Cgicc& formData);

// Print the form for this CGI
	void
printForm(const Cgicc& cgi)
{
	cout << "<form method=\"post\" onsubmit=\"checkName(cgi)\" action=\"" 
		<< cgi.getEnvironment().getScriptName() << "\">" << endl;

	cout << "<table>" << endl;

	/*   cout << "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css\" integrity=\"sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm\" crossorigin=\"anonymous\">";

	 */
	cout << "";
	cout << "<html>\n";
	cout << "<head>\n";
//	 cout << "<h1>The Cultural Events</h1>\n";
	cout << "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css\" integrity=\"sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm\" crossorigin=\"anonymous\">";
	cout << "<script></script>\n";
	cout << "<div class=\"container\">\n";
	cout << "<form>\n";

	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">First Name</label>";
	cout << "<input type=\"text\" class=\"form-control\" name=\"name\" value = \"\" aria-describedby=\"emailHelp\" placeholder=\"Enter first name\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Enter your first name.</small>";
	cout << "</div>";

	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">E-mail Address</label>";
	cout << "<input type=\"email\" class=\"form-control\" name=\"email\" value = \"\" aria-describedby=\"emailHelp\" placeholder=\"example@stetson.edu\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Enter your email address</small>";
	cout << "</div>";

	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">Graduation Year</label>";
	cout << "<input type=\"number\" class=\"form-control\" name=\"years\" value = \"2018\" min=\"2018-01-01\" aria-describedby=\"emailHelp\" placeholder=\"2018\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Enter the year you will graduate</small>";
	cout << "</div>";

	
	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">Graduation Semester</label>";
	cout << "<input type=\"text\" class=\"form-control\" name=\"semesters\" value = \"\" min=\"2018-01-01\" aria-describedby=\"emailHelp\" placeholder=\"Enter a semester\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Enter the semester you will graduate</small>";
	cout << "</div>";


	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">Cultural Credits</label>";
	cout << "<input type=\"number\" class=\"form-control\" name=\"credits\" value = \"0\" aria-describedby=\"emailHelp\" placeholder=\"Enter # of credits\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Number of desired cultural credits.</small>";
	cout << "</div>";

	cout << "<div class=\"form-group\">\n";	
	cout <<	"<label for=\"name\">Event preference</label>";
	cout << "<input type=\"text\" class=\"form-control\" name=\"events\" value = \"\" aria-describedby=\"emailHelp\" placeholder=\"E.g. tech\">";
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Enter a word related to your interests</small>";
	cout << "</div>";
/*

	cout << "<tr><td class=\"title\">In the output, show</td>"
		<< "<td class=\"form\">"
		<< "<input type=\"checkbox\" name=\"showEnv\" checked=\"checked\" />"
		<< "Data from CgiEnvironment<br />"
		<< "<input type=\"checkbox\" name=\"showFE\" checked=\"checked\" />"
		<< "All FormEntries<br />"
		<< "<input type=\"checkbox\" name=\"showForm\" checked=\"checked\" />"
		<< "Data from Cgicc"
		<< "</td></tr>" << endl;



	cout << "<tr><td class=\"title\">Exception Handling</td>"
		<< "<td class=\"form\">"
		<< "<input type=\"checkbox\" name=\"throw\" />"
		<< "Throw an exception to test error handling"
		<< "</td></tr>" << endl;

	cout << "<tr><td class=\"title\">Save and Restore</td>"
		<< "<td class=\"form\">"
		<< "<input type=\"checkbox\" name=\"save\" />"
		<<" Save submission to a file<br />"
		<< "<input type=\"checkbox\" name=\"restore\" />"
		<< "Restore data from the last saved submission"
		<< "</td></tr>" << endl;

	cout << "</table>" << endl;
*/
	cout << "<div class=\"center\"><p>"
		<< "<input type=\"submit\" name=\"submit\"  value=\"Submit\" />"
		<< "<input type=\"reset\" value=\"Nevermind\" />"
		<< "</p></div></form>" << endl;
}

bool checkCredits(const Cgicc& cgi){
	const_form_iterator credit = cgi.getElement("credits");
	if(credit->getIntegerValue() < 24 && credit->getIntegerValue() > 0 && !credit->isEmpty()){
		return true;
	}else{
		return false;
	}

}
//found how to check if only letters on cpp forums
bool checkName(const Cgicc& cgi){
	const_form_iterator name = cgi.getElement("name");
	std::string temp;
	bool letters =true;
	temp = name->getStrippedValue();
	for(int i =0; i< temp.length(); i++){
		int upper = toupper(temp[i]);
		if(upper < 'A' || upper > 'Z'){
			letters = false;
		}
	}
	if(temp.length() <= 30 && letters == true){
		return true;
	}else{

		return false;
	}	


}
bool checkEvents(const Cgicc& cgi){
	const_form_iterator name = cgi.getElement("events");
	std::string temp;
	bool letters =true;
	temp = name->getStrippedValue();
	for(int i =0; i< temp.length(); i++){
		int upper = toupper(temp[i]);
		if(upper < 'A' || upper > 'Z'){
			letters = false;
		}
	}
	if(temp.length() <= 10 && letters == true){
		return true;
	}else{

		return false;
	}	
}

bool checkDate(const Cgicc& cgi){
	const_form_iterator year = cgi.getElement("years");
	std::string temp = year->getStrippedValue();
	bool letters = false;
	for(int i =0; i< temp.length(); i++){
		int upper = toupper(temp[i]);
		if(upper < 'A' || upper > 'Z'){
			letters = true;
		}
	}
	if(temp.length() <= 4 && letters == true&& year->getIntegerValue() > 2017){
		return true;
	}else{

		return false;
	}	

}

bool checkSem(const Cgicc& cgi){
	const_form_iterator sem = cgi.getElement("semesters");
	std::string temp = sem->getStrippedValue();	
	if(temp == "Spring" || temp == "Fall"){
		return true;
	}else{
		return false;
	}

}


/*bool checkEvents(const Cgicc& cgi){
	const_form_iterator events = cgi.getElement("event");
	std::string temp = events->getStrippedValue();
	if(temp.length() < 40){
		return true;
	}else{
		return false;
	}
*/
int main(int /*argc*/, 
		char ** /*argv*/)
{
	try {
#if HAVE_GETTIMEOFDAY
		timeval start;
		gettimeofday(&start, NULL);
#endif

		// Create a new Cgicc object containing all the CGI data
		Cgicc cgi;
		//	Database data;

	
		// If the user wants to throw an exception, go ahead and do it
		if(cgi.queryCheckbox("throw") && ! cgi.queryCheckbox("restore"))
			throw std::runtime_error("User-requested Exception thrown in main()");

		// Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
		cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
		cout << html().set("lang", "en").set("dir", "ltr") << endl;

		// Set up the page's header and title.
		// I will put in lfs to ease reading of the produced HTML. 
		cout << head() << endl;

		// Output the style sheet portion of the header
		cout << style() << comment() << endl;
		cout << styles;
		cout << comment() << style() << endl;

		cout << title() << "MYCULTURAL.EVENTS" << title() << endl;

		cout << head() << endl;

		// Start the HTML body
		cout << body() << endl;

		cout << h1() << "<center>MYCULTURAL.EVENTS" << h1() << endl;

		// Get a pointer to the environment
		const CgiEnvironment& env = cgi.getEnvironment();

		// Generic thank you message
		cout << comment() << "This page generated by cgicc for "
			<< env.getRemoteHost() << comment() << endl;
	



		// If the user wants to restore from the last submission, do it
		if(cgi.queryCheckbox("restore")) {
			cgi.restore("save");
			cout << p(h2("Data Restored")) << endl;

			cout << cgicc::div().set("class", "notice") << endl;
			cout << "The data displayed has been restored from a file on disk."
				<< endl << cgicc::div() << p() << endl;
		}
	cout << br() << endl;
		printForm(cgi);
		cout << hr().set("class", "half") << endl;

		// Information on cgicc
	//	cout << cgicc::div().set("align","center").set("class","smaller") << endl;
	//	cout << "GNU cgi" << span("cc").set("class","red") << " v";
	//	cout << cgi.getVersion() << br() << endl;
	//	cout << "Compiled at " << cgi.getCompileTime();
	//	cout << " on " << cgi.getCompileDate() << br() << endl;

	//	cout << "Configured for " << cgi.getHost();  
#if HAVE_UNAME
		struct utsname info;
		if(uname(&info) != -1) {
			cout << ". Running on " << info.sysname;
			cout << ' ' << info.release << " (";
			cout << info.nodename << ")." << endl;
		}
#else
		cout << "." << endl;
#endif

#if HAVE_GETTIMEOFDAY
		// Information on this query
		timeval end;
		gettimeofday(&end, NULL);
		long us = ((end.tv_sec - start.tv_sec) * 1000000)
			+ (end.tv_usec - start.tv_usec);

		cout << br() << "Total time for request = " << us << " us";
		cout << " (" << static_cast<double>(us/1000000.0) << " s)";
#endif

		// End of document
		cout << cgicc::div() << endl;
		cout << body() << html() << endl;

			if (checkSem(cgi)&&checkName(cgi)&&checkCredits(cgi)&&checkDate(cgi)&&checkEvents(cgi)){ 
				
			const_form_iterator name = cgi.getElement("name");
			const_form_iterator mail = cgi.getElement("email");
			const_form_iterator year = cgi.getElement("years");
			const_form_iterator semesters = cgi.getElement("semesters");
			const_form_iterator credit = cgi.getElement("credits");
			const_form_iterator tags = cgi.getElement("events");
			database db;
			db.insertStudentData(name->getStrippedValue(),mail->getStrippedValue(),credit->getIntegerValue(), semesters->getStrippedValue(), year->getIntegerValue(), tags->getStrippedValue());
		}
	

		// No chance for failure in this example
		return EXIT_SUCCESS;
	}

	// Did any errors occur?
	catch(const std::exception& e) {

		// This is a dummy exception handler, as it doesn't really do
		// anything except print out information.

		// Reset all the HTML elements that might have been used to 
		// their initial state so we get valid output
		html::reset();      head::reset();          body::reset();
		title::reset();     h1::reset();            h4::reset();
		comment::reset();   td::reset();            tr::reset(); 
		table::reset();     cgicc::div::reset();    p::reset(); 
		a::reset();         h2::reset();            colgroup::reset();

		// Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
		cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
		cout << html().set("lang","en").set("dir","ltr") << endl;

		// Set up the page's header and title.
		// I will put in lfs to ease reading of the produced HTML. 
		cout << head() << endl;

		// Output the style sheet portion of the header
		cout << style() << comment() << endl;
		cout << "body { color: black; background-color: white; }" << endl;
		cout << "hr.half { width: 60%; align: center; }" << endl;
		cout << "span.red, STRONG.red { color: red; }" << endl;
		cout << "div.notice { border: solid thin; padding: 1em; margin: 1em 0; "
			<< "background: #ddd; }" << endl;

		cout << comment() << style() << endl;

		cout << title("GNU cgicc exception") << endl;
		cout << head() << endl;

		cout << body() << endl;

		cout << h1() << "GNU cgi" << span("cc", set("class","red"))
			<< " caught an exception" << h1() << endl; 

		cout << cgicc::div().set("align","center").set("class","notice") << endl;

		cout << h2(e.what()) << endl;

		// End of document
		cout << cgicc::div() << endl;
		cout << hr().set("class","half") << endl;
		cout << body() << html() << endl;
		
		

		return EXIT_SUCCESS;
	}


}

// Print out a table of the CgiEnvironment
	void
dumpEnvironment(const CgiEnvironment& env ) 
{
	// This is just a brain-dead dump of information.
	// Almost all of this code is for HTML formatting
	cout << h2("Environment information from CgiEnvironment") << endl;

	cout << cgicc::div().set("align","center") << endl;

	cout << table() << endl;

	cout << tr() << td("Request Method").set("class","title") 
		<< td(env.getRequestMethod()).set("class","data") << tr() << endl;
	cout << tr() << td("Path Info").set("class","title") 
		<< td(env.getPathInfo()).set("class","data") << tr() << endl;
	cout << tr() << td("Path Translated").set("class","title") 
		<< td(env.getPathTranslated()).set("class","data") << tr() << endl;
	cout << tr() << td("Script Name").set("class","title") 
		<< td(env.getScriptName()).set("class","data") << tr() << endl;
	cout << tr() << td("HTTP Referrer").set("class","title") 
		<< td(env.getReferrer()).set("class","data") << tr() << endl;
	cout << tr() << td("HTTP Cookie").set("class","title") 
		<< td(env.getCookies()).set("class","data") << tr() << endl;
	cout << tr() << td("Query String").set("class","title") 
		<< td(env.getQueryString()).set("class","data") << tr() << endl;
	cout << tr() << td("Content Length").set("class","title") 
		<< td().set("class","data") << env.getContentLength() 
		<< td() << tr() << endl;
	cout << tr() << td("Post Data").set("class","title")
		<< td().set("class","data")
		<< pre(env.getPostData()).set("class","data") << td() 
		<< tr() << endl;
	cout << tr() << td("Remote Host").set("class","title") 
		<< td(env.getRemoteHost()).set("class","data") << tr() << endl;
	cout << tr() << td("Remote Address").set("class","title") 
		<< td(env.getRemoteAddr()).set("class","data") << tr() << endl;
	cout << tr() << td("Authorization Type").set("class","title") 
		<< td(env.getAuthType()).set("class","data") << tr() << endl;
	cout << tr() << td("Remote User").set("class","title") 
		<< td(env.getRemoteUser()).set("class","data") << tr() << endl;
	cout << tr() << td("Remote Identification").set("class","title") 
		<< td(env.getRemoteIdent()).set("class","data") << tr() << endl;
	cout << tr() << td("Content Type").set("class","title") 
		<< td(env.getContentType()).set("class","data") << tr() << endl;
	cout << tr() << td("HTTP Accept").set("class","title") 
		<< td(env.getAccept()).set("class","data") << tr() << endl;
	cout << tr() << td("User Agent").set("class","title") 
		<< td(env.getUserAgent()).set("class","data") << tr() << endl;
	cout << tr() << td("Server Software").set("class","title") 
		<< td(env.getServerSoftware()).set("class","data") << tr() << endl;
	cout << tr() << td("Server Name").set("class","title") 
		<< td(env.getServerName()).set("class","data") << tr() << endl;
	cout << tr() << td("Gateway Interface").set("class","title") 
		<< td(env.getGatewayInterface()).set("class","data") << tr() << endl;
	cout << tr() << td("Server Protocol").set("class","title") 
		<< td(env.getServerProtocol()).set("class","data") << tr() << endl;
	cout << tr() << td("Server Port").set("class","title") 
		<< td().set("class","data") << env.getServerPort() 
		<< td() << tr() << endl;
	cout << tr() << td("HTTPS").set("class","title")
		<< td().set("class","data") << (env.usingHTTPS() ? "true" : "false")
		<< td() << tr() << endl;
	cout << tr() << td("Redirect Request").set("class","title") 
		<< td(env.getRedirectRequest()).set("class","data") << tr() << endl;
	cout << tr() << td("Redirect URL").set("class","title") 
		<< td(env.getRedirectURL()).set("class","data") << tr() << endl;
	cout << tr() << td("Redirect Status").set("class","title") 
		<< td(env.getRedirectStatus()).set("class","data") << tr() << endl;

	cout << table() << cgicc::div() << endl;
}

// Print out the value of every form element
void
showForm(const Cgicc& formData) 
{ 		

	cout << "<div class=\"form-group\">\n";
	cout << "<font size=\"+5\">Thank You!</font>"; 	
	cout << "<small id=\"emailHelp\" class=\"form-text text-muted\">Your information was stored successfully!</small>";
	cout << "</div>";

}
