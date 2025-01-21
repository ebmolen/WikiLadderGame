//
// Created by SamMi on 12/6/2024.
//

#ifndef UNITTESTS_H
#define UNITTESTS_H


class UnitTests {
    public:
    //tests for vertex class
    void testSetKeyGetKey();
    void testSetParentGetParent();
    void testSetParent2();
    void testSetDistanceGetDistance();

    void testVertexFunctions();

    //tests for wikitree class
    void testWikiTreeGetRoot();
    void testWikiTreeGetRootNotEqual();

    void testWikiTreeFunctions();

    //tests for wikiladder class
    void testWikiLadderSetStopGetStop();
    void testWikiLadderPlay();
    void testWikiLadderPlay2();
    void testWikiLadderGetPathLength();
    void testWikiLadderGetPath();

    void testWikiLadderClass();

    //tests for parser class
    void testSearchWikiPage1();
    void testSearchWikiPage2();
    void testSetPage();
    void testGetPage();

    void testParserClass();



};



#endif //UNITTESTS_H
