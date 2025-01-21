/*
 * File: vertex.cpp
 * ----------------
 * Implemenation for the Vertex class.
 * Coding is self-documenting. Implementation notes are minimal.
 */


#include "vertex.h"
#include <string>
#include <vector>

Vertex::Vertex() {
    distance = 0;
    parent = nullptr;
}

Vertex::Vertex(const std::string &ckey){
    key = ckey;
    distance = 0;
    parent = nullptr;
}

Vertex::Vertex(const std::string & ckey, Vertex *cparent, const std::string & ccolor){
    key = ckey;
    parent = cparent;
    color = ccolor;
    distance = 0;
}

void Vertex::setKey(const std::string & ckey){
    key = ckey;
}

std::string Vertex::getKey() const{
    return key;
}

void Vertex::setParent(Vertex *cparent){
    parent = cparent;
}

Vertex * Vertex::getParent() const{
    return parent;
}


void Vertex::setColor(const std::string & ccolor){
    color = ccolor;
}

std::string Vertex::getColor() const{
    return color;
}


void Vertex::setDistance(const int & cdistance) {
    distance = cdistance;
}

int Vertex::getDistance () const {
    return distance;

}



