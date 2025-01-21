//! parser.h - interface for the Parser class

/*!
 * File: parser.h
 * --------------
 * This file contains the interface for the Parser class.
 * Class pulls the html file for a Wikipedia page identifies additional links in the paragraph sections of a Wikipedia page.
 */

#ifndef parser_h
#define parser_h

#include "vertex.h"
#include <vector>
#include <string>
#include <cpr/cpr.h>

class Parser {

    public:

        //! Constructor for the Parser class.
        /*!
         * Usage: Parser(Vertex *cpage);
         * -----------------------------
         * @param cpage a Vertex *
         */
        Parser(Vertex *cpage);

        //! Identifies the links in the paragraph portions of a Wikipedia page.
        /*!
         * Usage: std::vector<std::string> links = searchWikiPage();
         * ---------------------------------------------------------
         * No parameters.
         * @return std::vector<std::string> links, a string vector containing the urls of other Wikipedia page links in the paragraph
         * sections of the key value of the Vertex * member variable of the Parser object.
         */
        std::vector<std::string> searchWikiPage () const;

        //! setter for the page member variable.
        /*!
         * Usage: setPage(Vertex *cpage);
         * ------------------------------
         * @param cpage a Vertex *
         */
        void setPage(Vertex *cpage);

        //! getter for the page member variable.
        /*!
         * Usage Vertex *page = getPage();
         * -------------------------------
         * No parametrs.
         * @return Vertex *page, the Vertex* variable for a Parser object.
         */
        Vertex * getPage() const;

        //! destructor for the Parser class.
        /*!
         * Usage: ~Parser();
         * -----------------
         * No parameters.
         */
        ~ Parser(){}

    private:
        Vertex *page;

};

#endif