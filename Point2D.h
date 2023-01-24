#ifndef POINT2D_H
#define POINT2D_H

#include<cmath>
#include<string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Point2D{

protected:
	int x,y;
	double distFrOrigin;
	
	//calculates distance from origin (0,0);
	void setDistFrOrigin();

public:
    //empty constructor
    Point2D();

    //constructor to initialize with given (x,y)
    Point2D(int x,int y);

    Point2D(string val);

   //getters and setters methods
   int getX();
   void setX(int x);

   int getY();
   void setY(int y);

   double getScalarValue();

   //overload the equality operator
   bool operator ==(Point2D p1);

   //overload << operator to print the point information
   friend std::ostream &operator<<( std::ostream &output, Point2D &D );
   
   //returns a string to print on the screen or file as described
   string toString();

   //overload < operator to sort and remove duplicates easily
   bool operator <(const Point2D &p1);

   //static functions to sort points
   static bool sortByX(const Point2D &a,const Point2D &b); 
   static bool sortByY(const Point2D &a,const Point2D &b); 
   static bool sortByDistFrOrigin(const Point2D &a,const Point2D &b); 
};

#endif // POINT2D_H
