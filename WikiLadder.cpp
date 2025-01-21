/*
 * File: WikiLadder.cpp
 * --------------------
 * Implementation for the WikiLadder class.
 * Code is self-documenting.  Implementation notes are minimal.
 */

#include "WikiLadder.h"
#include <iostream>
#include "WikiTree.h"

WikiLadder::WikiLadder(const std::string & cstart, const std::string & cstop) {
    start = new Vertex(cstart);
    stop = cstop;
    pathLength = 0;
}

void WikiLadder::setStop(const std::string &newStop) {
    stop = newStop;
}


std::string WikiLadder::getStop() {
    return stop;
}


/*
 * Function: Play
 * --------------
 * Implementation Notes: "wrapper" function to abstract the user playing the WikiLadder game from the Vertex, WikiTree, and Parser classes.
 * Function plays the game and adds the pages to the path string vector.
 */

void WikiLadder::Play() {
    WikiTree wikiPlay(start);
    const Vertex * end = wikiPlay.buildWikiTree(stop);
    pathLength = end->getDistance();
    path.push_back(end->getKey());
    while (end->getParent() != nullptr) {
        path.push_back(end->getParent()->getKey());
        end = end->getParent();
    }
}

int WikiLadder::getPathLength() const {
    return pathLength;
}

std::vector<std::string> WikiLadder::getPath() const {
    return path;
}


