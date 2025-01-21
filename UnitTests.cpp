//
// Created by SamMi on 12/6/2024.
//

#include "UnitTests.h"
#include <cassert>
#include <iostream>
#include <ostream>

#include "vertex.h"
#include "WikiLadder.h"
#include "WikiTree.h"
#include "parser.h"

    //tests for vertex class
    void UnitTests::testSetKeyGetKey() {
        Vertex vertextest("foo1");
        vertextest.setKey("test1");
        assert(vertextest.getKey() == "test1");
        std::cout << "Vertex set key/get key unit test passed" << std::endl;
    }

    void UnitTests::testSetParentGetParent() {
        Vertex vertextest("foo");
        Vertex vertextest2("bar");
        vertextest.setParent(&vertextest2);
        assert(vertextest.getParent() == &vertextest2);
        std::cout << "Vertex set parent/get parent unit test passed" << std::endl;
    }

    void UnitTests::testSetParent2(){
        Vertex *v = new Vertex("https://en.wikipedia.org/wiki/Chicago");
        Vertex *u = new Vertex("https://en.wikipedia.org/wiki/Kuala_Lumpur");
        Vertex *p = new Vertex("https://en.wikipedia.org/wiki/Malaysian_Mandarin");
        v->setParent(u);
        assert(p != v->getParent());
        delete(v);
        delete(u);
        delete(p);
    }

    void UnitTests::testSetDistanceGetDistance() {
        Vertex vertextest("foo");
        vertextest.setDistance(5);
        assert(vertextest.getDistance() == 5);
        std::cout << "Vertex set distance/get distance unit test passed" << std::endl;
    }

    //function to simplify unit test calls
    void UnitTests::testVertexFunctions() {
        testSetKeyGetKey();
        testSetParentGetParent();
        testSetParent2();
        testSetDistanceGetDistance();
    }

    //tests for wikitree
    void UnitTests::testWikiTreeGetRoot() {
        Vertex * vertextest = new Vertex("foo");
        WikiTree wikiTree(vertextest);
        assert(wikiTree.getRoot() == vertextest);
        std::cout << "WikiTree get root unit test passed" << std::endl;
    }

    void UnitTests::testWikiTreeGetRootNotEqual() {
        Vertex *v = new Vertex("https://en.wikipedia.org/wiki/Pacific_Ocean");
        Vertex *u = new Vertex("https://en.wikipedia.org/wiki/Arctic_Ocean");
        WikiTree test (v);
        assert(u != test.getRoot());
        std::cout << "WikiTree get root unit test not equal passed" << std::endl;


    }

    void UnitTests::testWikiTreeFunctions() {
        testWikiTreeGetRoot();
        testWikiTreeGetRootNotEqual();
    }


    // void testWikiTreeBuild() {
    //     Vertex vertextest("");
    //     Vertex vertextest2("bar");
    //     WikiTree testWikiTree(&vertextest);
    //
    //
    // }

    //tests for wikiLadder
    void UnitTests::testWikiLadderSetStopGetStop() {
        std::string foo = "foo";
        std::string bar = "bar";
        WikiLadder wikiladder(foo,bar);
        wikiladder.setStop("stop");
        std::string test = "stop";
        assert(wikiladder.getStop() == test);
        std::cout << "WikiLadder set stop/get stop unit test passed" << std::endl;
    }

    void UnitTests::testWikiLadderPlay() {
        WikiLadder wikiladder("https://en.wikipedia.org/wiki/Pittsburgh_Steelers", "https://en.wikipedia.org/wiki/Times_Square");
        wikiladder.Play();
        assert(wikiladder.getPathLength() == 2);
        std::cout << "WikiLadder play unit test passed" << std::endl;
    }

    void UnitTests::testWikiLadderPlay2(){
        WikiLadder test ("https://en.wikipedia.org/wiki/Pickle", "https://en.wikipedia.org/wiki/Berlin");
        test.Play();
        assert(test.getPathLength() == 3);
        std::cout << "WikiLadder play unit test 2 passed" << std::endl;

    }

    void UnitTests::testWikiLadderGetPathLength() {
        WikiLadder wikiladder("foo", "bar");
        wikiladder.getPathLength();
        assert(wikiladder.getPathLength() == 0);
        std::cout << "WikiLadder getPathLength unit test passed" << std::endl;
    }

    void UnitTests::testWikiLadderGetPath() {
        WikiLadder wikiladder("https://en.wikipedia.org/wiki/Pittsburgh_Steelers", "https://en.wikipedia.org/wiki/Times_Square");
        wikiladder.Play();
        std::vector<std::string> testPath = wikiladder.getPath();
        assert(testPath[2] == "https://en.wikipedia.org/wiki/Pittsburgh_Steelers");
        assert(testPath[1] == "https://en.wikipedia.org/wiki/NBC_Sunday_Night_Football");
        assert(testPath[0] == "https://en.wikipedia.org/wiki/Times_Square");
        std::cout << "WikiLadder play unit test passed" << std::endl;
    }

    void UnitTests::testWikiLadderClass() {
        testWikiLadderSetStopGetStop();
        testWikiLadderPlay();
        testWikiLadderGetPath();
        testWikiLadderGetPathLength();
    }

    // tests for Parser class.

    void UnitTests::testSearchWikiPage1(){
        Vertex *v = new Vertex ("https://en.wikipedia.org/wiki/Foot_Locker_Cross_Country_Championships");
        Parser p (v);
        std::vector<std::string> path = p.searchWikiPage();
        assert(path.size() == 16);
        delete(v);
        std::cout << "Parser SearchWikiPage1 unit test passed" << std::endl;

    }

    void UnitTests::testSearchWikiPage2(){
        Vertex *v = new Vertex ("https://en.wikipedia.org/wiki/Tour_of_California");
        Parser p (v);
        std::vector<std::string> path = p.searchWikiPage();
        assert(path.size() == 41);
        delete(v);
        std::cout << "Parser SearchWikiPage2 unit test passed" << std::endl;

    }

    void UnitTests::testSetPage(){
        Vertex *v = new Vertex ("https://en.wikipedia.org/wiki/Tour_of_California");
        Parser p (v);
        Vertex *u = new Vertex ("https://en.wikipedia.org/wiki/Tour_of_California");
        p.setPage(u);
        assert(u == p.getPage());
        delete(v);
        delete(u);
        std::cout << "Parser set page unit test passed" << std::endl;

    }

    void UnitTests::testGetPage(){
        Vertex *v = new Vertex("https://en.wikipedia.org/wiki/Peanut_butter");
        Parser p(v);
        assert(p.getPage()->getKey() == "https://en.wikipedia.org/wiki/Peanut_butter");
        delete(v);
        std::cout << "Parser get page unit test passed" << std::endl;

    }

    void UnitTests::testParserClass() {
        testSearchWikiPage1();
        testSearchWikiPage2();
        testSetPage();
        testGetPage();
    }