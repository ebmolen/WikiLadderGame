//! WikiTree.h - interface for the WikiTree class.

/*!
 * File: WikiTree.h
 * ----------------
 * This file contains the interface for the WikiTree class.
 * A WikiTree represent a graph of WikiPedia pages.
 */

#ifndef WIKITREE_H
#define WIKITREE_H
#include <vector>
#include <string>
#include "vertex.h"
#include "cpr/cpr.h"

class WikiTree {

    private:

        Vertex * root;

        std::vector<Vertex *> vertexList;


    public:

        //! Constructor for the WikiTree class.
        /*!
         * Usage: WikiTree(Vertex *croot);
         * -------------------------------
         * @param croot a Vertex *
         */
        WikiTree(Vertex *croot);

        //! getter for the root member variable.
        /*!
         * Usage: Vertex *root = getRoot();
         * --------------------------------
         * No parameters.
         * @return Vertex *root, the root variable for a WikiTree object.
         */
        Vertex * getRoot() const;

        //! method to add edge to WikiTree.
        /*!
         * Usage: addEdge(Vertex *cparent, Vertex *cchild);
         * ------------------------------------------------
         * @param cparent a Vertex *
         * @param cchild a Vertex *
         */
        void addEdge(Vertex *cparent, Vertex *cchild);

        //! Builds a WikiTree from the root member variable until a Vertex with a specified key value is found. Returns the Vertex.
        /*!
         * Usage: Vertex *end = buildWikiTree(const std::string &stopUrl);
         * ----------------------------------------------------------------
         * Function builds a WikiTree, a graph of Vertex objects with Wikipedia page urls as their key values.
         * While building searches for a Vertex with stopUrl as its key value.
         * @param stopUrl a reference to a const std::string.
         * @return Vertex *end, a pointer to the Vertex with key variable of stopUrl.
         * If Vertex is not found, returns a pointer to the root Vertex.
         */
        Vertex * buildWikiTree(const std::string &stopUrl);

        //! Destructor for the WikiTree class.
        /*!
         * Usage: ~WikiTree();
         * --------------------
         * No parameters.
         */
        ~WikiTree();


};



#endif //WIKITREE_H
