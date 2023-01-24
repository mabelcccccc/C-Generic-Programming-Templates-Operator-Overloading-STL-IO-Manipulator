#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Line2D.h"
#include<cmath>
#include<string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;


class Line3D:public Line2D
{
	//private members
    Point3D pt1,pt2;
protected:
	void setLength();

public:
	//empty constructor
	Line3D();

	//initialize by taking two 2D points
	Line3D(Point3D p1,Point3D p2);

	//constructor that takes a string in
    //[x1, y1, z1], [x2, y2, z2] form
    Line3D(std::string val);

    //getters setters
    Point3D getPt1();
    Point3D getPt2();
    double getScalarValue();
    void setPt1(Point3D p1);
    void setPt2(Point3D p1);

   //overload the equality operator
   bool operator ==(Line3D);
   
	//overload << operator to print the point information
   friend std::ostream &operator<<( std::ostream &output, Line3D &D );
   
   //returns a string to print on the screen or file as described
   std::string toString();


   //overload < operator to sort and remove duplicates easily
   bool operator <(const Line3D &l1);

  //static functions to sort lines
   static bool sortByPt1(Line3D &a,Line3D &b);
   static bool sortByPt2(Line3D &a,Line3D &b);
   static bool sortByLength(Line3D &a,Line3D &b);
	
};

#endif // LINE3D_H
