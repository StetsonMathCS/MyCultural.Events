#include <curl/curl.h>
#include <iostream>
#include <string>

std::string escape(std::string const &s)
{
	std::size_t n = s.length();
	std::string escaped;
	escaped.reserve(n * 2);

for (std::size_t i = 0; i < n; ++i)
{
	if (s[i] == '\\' || s[i] == '\"')
	escaped += '\\';
	escaped += s[i];
}
return escaped;
}

void emails(std::string toemail, std::string subject, std::string body)
{
	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_ALL);

	//get a curl handle
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

	//set the URL to receive the POST DATA
	struct curl_slist *chunk = NULL;
	std::string key= "Authorization: Bearer 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";
	std::string content= "Content-Type: application/json";
	std::cout << content << std::endl;
	std::cout << key << std::endl;
	chunk = curl_slist_append(chunk, key.c_str());
        chunk = curl_slist_append(chunk, content.c_str());
	res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST"); 
	curl_easy_setopt(curl, CURLOPT_URL, "https://api.sendgrid.com/v3/mail/send");
	curl_easy_setopt(curl, CURLOPT_POST, 1);
	
	//especify the POST DATA
	std::string postbody = "{\"personalizations\": [{\"to\": [{\"email\": \"" + escape(toemail) + "\"}]}],\"from\": {\"email\": \"myculturalevents@stetson.edu\"},\"subject\": \"" + escape(subject) + "\",\"content\": [{\"type\": \"text/plain\", \"value\": \"" + escape(body) +"\"}]}";
	std::cout << postbody << std::endl;
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postbody.c_str());

//	res = curl_easy_perform(curl);

	//perform the request, and resquest will get the return code
	curl_easy_perform(curl);

	//clean up
	curl_easy_cleanup(curl);
//	curl_slist_free_all(chunk);
}
