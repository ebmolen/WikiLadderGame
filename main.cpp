/*!
 * File: main.cpp
 * --------------
 * main program to implement the WikiLinks game.
 */

#include <iostream>
#include "cpr/cpr.h"
#include <vector>
#include <string_view>
#include <string>
#include "vertex.h"
#include "WikiLadder.h"
#include "WikiTree.h"
#include "UnitTests.h"


//  int main() {
//
//      //Unit Tests
//      std::cout << "Beginning Unit Tests" << std::endl;
//
//      std::cout << "\nTesting Vertex class: " << std::endl;
//
//      UnitTests tests;
//
//      tests.testVertexFunctions();
//      //tests.testWikiTreeGetRoot(); //calling WikiTreeFunctions instead.
//      tests.testWikiTreeFunctions();
//      tests.testWikiLadderClass();
//      tests.testParserClass();
//
//      std::cout << "All tests passed" << std::endl;
//
//      return 0;
// }


int main()
{

    int response = 1;

    while (response == 1) {
        std::cout << "*************************************************************************" << std::endl;
        std::cout << std::endl;
        std::cout << "Welcome to the WikiLadder Game!!!" << std::endl;
        std::cout << std::endl;
        std::cout << "Let's find the shortest path betweeen two Wikipedia pages!" << std::endl;
        std::cout << std::endl;
        std::cout << "You will provide the starting and ending Wikipedia pages, " << std::endl;
        std::cout << "and we'll provide the shortest path between the two pages." << std::endl;
        std::cout << std::endl;
        std::cout << "While you're waiting we'll display all pages searched!" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::string startPage;
        std::cout << "Please provide the starting Wikipedia page: ";
        std::cin >> startPage;

        while (startPage.substr(0, 24) != "https://en.wikipedia.org") {
            std::cout << "Please provide a valid Wikipedia page: ";
            std::cin >> startPage;
        }

        std::string endPage;
        std::cout << "Please provide the ending Wikipedia page: ";
        std::cin >> endPage;

        while (endPage.substr(0, 24) != "https://en.wikipedia.org") {
            std::cout << "Please provide a valid Wikipedia page: ";
            std::cin >> endPage;
        }

        WikiLadder playWiki(startPage, endPage);
        playWiki.Play();

        std::cout << std::endl;
        std::cout << "Shortest path from " << startPage << " to " << endPage << ": " << std::endl;

        int pathLength = playWiki.getPathLength();
        std::vector<std::string> path = playWiki.getPath();

        for (int i = pathLength; i > 0; i--) {
            std::cout << path[i] << " --> ";
        }
        std::cout << path[0] << std::endl;

        std::cout << "\n" << std::endl;

        char r;
        std::cout << "Would you like to play again? (y/n)? ";
        std::cin >> r;
        while(r != 'y' && r != 'n') {
            std::cout << "Please provide a valid response.  Would you like to play again? (y/n)? ";
            std::cin >> r;
        }
        if (r == 'n') {
            response = 0;
        }

    }

    std::cout << "*************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "Goodbye!  Thank you for playing the WikiLinks Game!" << std::endl;
    std::cout << std::endl;
    std::cout << "*************************************************************************" << std::endl;


    return 0;


}

