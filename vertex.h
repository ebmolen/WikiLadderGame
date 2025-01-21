//! vertex.h - interface for Vertex class
/*!
 * File: Vertex.h
 * ---------------
 * This file contains the interface for the Vertex class.
 * Class represents a node/vertex element to go in a WikiTree object.
 */


#ifndef VERTEX_H
#define VERTEX_H
#include <string>

class Vertex {

    public:

        //! Default constructor for Vertex class.
        /*!
         * Usage: Vertex();
         * ---------------
         * No parameters.
         */
        Vertex();

        //! Constructor for the Vertex class.
        /*!
         * Usage: Verex(const std::string &key);
         * --------------------------------------
         * @param ckey a reference to a const std:string.
         */
        Vertex(const std::string &ckey);

        //! Constructor for the Vertex class.
        /*!
         * Usage: Vertex(const std::string &key);
         * --------------------------------------
         * @param ckey a reference to a const std:string.
         * @param cparent a Vertex pointer.
         * @param ccolor a reference to a const std::string.
         */
        Vertex(const std::string & ckey, Vertex *cparent, const std::string &ccolor);

        //! setter for key member variable
        /*!
         * Usage setKey(const std::string & ckey);
         * --------------------------------------
         * Sets the key value for a Vertex object.
         * @param ckey a reference to a const std::string.
         */
        void setKey(const std::string &ckey);

        //! getter for key member variable
        /*!
         * Usage: std::string key = getKey();
         * ----------------------------------
         * No parameters.
         * @return std::string key, the key value for a Vertex object.
         */
        std::string getKey() const;

        //! setter for parent member variable
        /*!
         * Usage: setParent(Vertex *cparent);
         * -----------------------------------
         * Sets the parent value for a Vertex object.
         * @param cparent a Vertex pointer.
         */
        void setParent(Vertex *cparent);

        //! getter for parent member variable
        /*!
         * Usage: Vertex *parent = getParent();
         * ------------------------------------
         * No parameters.
         * @return Vertex *parent, the parent variable for a Vertex object.
         */
        Vertex * getParent() const;

        //! setter for color member variable
        /*!
         * Usage: setColor(const std::string & ccolor);
         * --------------------------------------------
         * sets the color variable for the Vertex object.
         * @param ccolor a reference to a const std::string.
         */
        void setColor(const std::string &ccolor);

        //! getter for color member variable
        /*!
         * Usage: std::string color = getColor();
         * --------------------------------------
         * No parameters.
         * @return std::string color, the color variable for a Verex object.
         */
        std::string getColor() const;

        //! setter for distance member variable
        /*!
         * Usage: setDistance(const int &cdistance);
         * -----------------------------------------
         * Sets the distance variable for a Vertex object.
         * @param cdistance a reference to a const int.
         */
        void setDistance(const int &cdistance);

        //! getter for distance member variable
        /*!
         * Usage: int distance = getDistance();
         * ------------------------------------
         * No paramters.
         * @return int distance, the distance variable for a Vertex object, representing the distance of the Vertex from a root Vertex.
         */
        int getDistance () const;

        //! Destructor for Vertex class.
        /*!
         * Usage: ~Vertex();
         * -----------------
         * No parameters.
         */


        ~Vertex(){}

    private:
        std::string key;

        std::string color;

        int distance;

        Vertex *parent;
};



#endif //VERTEX_H
