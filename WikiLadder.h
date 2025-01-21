//! WikiLadder.h - interface for the WikiLadder class.
/*!
 * File: WikiLadder.h
 * -------------------
 * Class to create and play the WikiLadder game.
 */

#ifndef WIKILADDER_H
#define WIKILADDER_H

#include "vertex.h"
#include <string>
#include "WikiTree.h"


class WikiLadder {

    public:
        //! constructor for the WikiLadder class.
        /*!
         * Usage: WikiLadder(const std::string & cstart, const std::string & cstop);
         * -------------------------------------------------------------------------
         * @param cstart a reference to a const std::string.
         * @param cstop a reference to a const std::string.
         */
        WikiLadder(const std::string & cstart, const std::string & cstop);

        //! setter for the stop member variable.
        /*!
         * Usage: setStop(const std::string &newStop);
         * ------------------------------------
         * @param newStop a refernce to a const std::string.
         */
        void setStop(const std::string &newStop);

        //! getter for the stop member variable.
        /*!
        * Usage: std::string stop = getStop();
        * ------------------------------------
        * No parameters.
        * @return std::string stop.
        */
        std::string getStop();


        //! Builds a WikiTree from start to a Vertex with stop as its key values.  Sets path and pathLength member variables.
        /*!
         * Usage: Play();
         * ---------------
         * No parameters.
         */
        void Play();

        //! getter for the path length member variable;
        /*!
         * Usage: int pathLength = getPathLength();
         * ----------------------------------------
         * No parameters.
         * @return int pathLength, the length of the path between the start Vertex and a Vertex with stop as its key value.
         */
        int getPathLength() const;

        //! getter for the path member variable;
        /*!
         * Usage: std::vectors<std::string> path = getPath();
         * ---------------------------------------------
         * @return std::vectors<std::string> path, a vector of strings with the key values of the Vertices in the path between start and and a Vertex with stop as its key value.
         */
        std::vector<std::string> getPath() const;

        //! Destructor for the WikiLadder class.
        /*!
         * Usage: ~WikiLadder();
         * --------------------
         * No parameters.
         */
        ~WikiLadder(){};


    private:
        Vertex * start;

        std::string stop;

        std::vector<std::string> path;

        int pathLength;

};

#endif //WIKILADDER_H
