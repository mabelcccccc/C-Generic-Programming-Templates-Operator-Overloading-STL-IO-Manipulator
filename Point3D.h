#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

#include<cmath>
#include<string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Point3D:public Point2D{

 protected:
 	int z;

	//calculates distance from origin (0,0);
	void setDistFrOrigin();

public:
    //empty constructor
    Point3D();

    //constructor to initialize with given (x,y)
    Point3D(int x,int y,int z);

    Point3D(std::string val);

   //getters and setters methods
   int getZ();
   void setZ(int z);

   double getScalarValue();

   //override setters otherwise
   //setDistFrOrigin() would be called from Point2D class
   //which is not right formula for Point2D

   void setX(int x);
   void setY(int y);
   
   //overload the equality operator
   bool operator ==(Point3D p);
   
   //overload << operator to print the point information
   friend std::ostream &operator<<( std::ostream &output, Point3D &D );
   
   //returns a string to print on the screen or file as described
   string toString();

   //overload < operator to sort and remove duplicates easily
   bool operator <(const Point3D &p1);

   //static functions to sort points
   static bool sortByX(const Point3D &a,const Point3D &b); 
   static bool sortByY(const Point3D &a,const Point3D &b); 
   static bool sortByDistFrOrigin(const Point3D &a,const Point3D &b); 
   static bool sortByZ(const Point3D &a,const Point3D &b); 

};

#endif // POINT3D_H
