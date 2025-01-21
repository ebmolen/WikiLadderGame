/*
 * File: parser.cpp
 * ----------------
 * Implemenation for the Parser class.
 * Code is self-documenting.  Implementation notes are minimal.
 */


#include "parser.h"
#include <vector>
#include <string>
#include "vertex.h"
#include <cpr/cpr.h>
#include <iostream>


Parser::Parser(Vertex* cpage){
    page = cpage;
}

/*
 * Function: searchWikiPage
 * ------------------------
 * Implemenation Notes: Uses the cpr library to obtain html file for a Wikipedia page.
 * The page url is the key for the Vertex *page member variable of the Parser class.
 * The function then walks through a string of the url file.  Once it finds a "<p>", representing the start of a paragraph,
 * a flag is set to 1.  Once a paragraph closing "</p>" is found, the flag is set to 0.  While the flag is 1 (meaning
 * inside a Wikipedia page paragraph), the function looks for links by identifying them with "<a href=" and then looking for a link
 * start of "/wiki" to identify it as a Wikipedia link.  Certain links are eliminated as they do not got to Wikipedia article pages.
 * Strings of Wikipedia are page urls are added to a vector of strings (links). The function returns links.
 */
std::vector<std::string> Parser::searchWikiPage () const {
    cpr::Response r = cpr::Get(cpr::Url{this->getPage()->getKey()});
    std::vector<std::string_view> paragraphs;
    std::vector<std::string> links;
    std::string temp;
    int findStart = 0;

    int length = r.text.length();
    int i = 0;
    while (i < length - 2)  {
        if (r.text.substr(i, 3) == "<p>") {
            findStart = 1;
            i = i + 3;
        } else if (findStart > 0 && r.text.substr(i, 8) == "<a href=") {
            int j = 1;
            while (r.text[i +  8 + j] != '\"') {
                j++;
            }
            std::string tempLink = r.text.substr(i + 9, j - 1);
            if (tempLink.substr(0, 5) == "/wiki" && tempLink.substr(0, 15) != "/wiki/Category:" && tempLink.substr(0, 11) != "/wiki/File:" && tempLink.substr(0, 16) != "/wiki/Wikipedia:" && tempLink.substr(0, 15) != "/wiki/Template:" && tempLink.substr(0, 20) != "/wiki/Template_talk:" && tempLink.substr(0, 14) != "/wiki/Special:" && tempLink.substr(0, 13) != "/wiki/Module:" && tempLink.substr(0, 13) != "/wiki/Portal:" && tempLink.substr(0, 15) != "/wiki/Main_Page" && tempLink.substr(0, 11) != "/wiki/Help:") {
                tempLink = "https://en.wikipedia.org" + tempLink;
                std::cout << tempLink << std::endl;
                links.push_back(tempLink);
            }
            i = i + 10 + j;
        } else if (r.text.substr(i, 4) == "</p>") {
            findStart = 0;
            i = i + 4;
        } else {
            i++;
        }
    }
    return links;
}


void Parser::setPage(Vertex * cpage){
    page = cpage;
}

Vertex * Parser::getPage() const{
    return page;
}



