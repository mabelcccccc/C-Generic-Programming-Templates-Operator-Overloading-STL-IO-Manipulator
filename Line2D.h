#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"
#include<cmath>
#include<string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Line2D
{
	//private members
    Point2D pt1,pt2;
protected:
	double length;
	void setLength();

public:
	//empty constructor
	Line2D();

	//initialize by taking two 2D points
	Line2D(Point2D p1,Point2D p2);

	//constructor that takes a string in
    //[x1, y1], [x2, y2] form

    Line2D(std::string val);

    //getters setters
    Point2D getPt1();
    Point2D getPt2();
    double getScalarValue();
    void setPt1(Point2D p1);
    void setPt2(Point2D p2);
   
   //overload the equality operator
   bool operator ==(Line2D line);
   

	//overload << operator to print the point information
   friend std::ostream &operator<<( std::ostream &output, Line2D &D );
   
   //returns a string to print on the screen or file as described
   std::string toString();


   //overload < operator to sort and remove duplicates easily
   bool operator <(const Line2D &l1);

   //static functions to sort lines
   static bool sortByPt1(Line2D &a,Line2D &b);
   static bool sortByPt2(Line2D &a,Line2D &b);
   static bool sortByLength(Line2D &a,Line2D &b);

};

#endif // LINE2D_H
