#include "Line2D.h"

void Line2D::setLength()
{
    int xd = pt1.getX() - pt2.getX();
    int yd = pt1.getY() - pt2.getY();

    this->length = sqrt((xd * xd) + (yd * yd));
}

//empty constructor
Line2D::Line2D(){}

//constructor to initialize by taking two 2D points
Line2D::Line2D(Point2D p1, Point2D p2){
	pt1=p1;
	pt2=p2;
	setLength();
}

//getters setters
Point2D Line2D::getPt1(){
	return pt1;
}
Point2D Line2D::getPt2(){
	return pt2;
}
double Line2D::getScalarValue(){
	return this->length;
}
void Line2D::setPt1(Point2D p1){
	this->pt1=p1;
	setLength();
}
void Line2D::setPt2(Point2D p2){
	this->pt2=p2;
	setLength();
}


Line2D::Line2D(std::string val)
{
    //search from start, returns position of first comma
    int comma1 = val.find(',');

    //search for comma again but search starts
    //right after the first comma's position
    int comma2 = val.find(',', comma1 + 1);
                                          

    //[x1, y1], [x2, y2] 
    //0       ^comma2
    this->pt1=Point2D(val.substr(0,comma2));

    //[x1, y1], [x2, y2]
    //         ^comma2+1 to end
    this->pt2=Point2D(val.substr(comma2+1));
                                             
    setLength();
}


//overload the equality operator
bool Line2D::operator ==(Line2D other){
   return pt1==other.getPt1() && pt2==other.getPt2();
}



//to print with scalar value in the below format
//overload << operator to print the point information
std::ostream &operator<<( std::ostream &output, Line2D &line ){
    //make use of the fact that we already overloaded << for Point2D
    Point2D p1=line.getPt1();
    Point2D p2=line.getPt2();

    //setprecision(3) prints up to 3 d.p
    //use std::fixed makes sure to print 3 d.p
    output<<"( "<<p1<<" to "<<p2<<" ) length : "<< std::setprecision(3)<<std::fixed<<line.getScalarValue();

    return output;

}



//returns a string to print Line2D object on the screen or file
//in the below format (pt1 pt2 length)
//[   9,   -9]   [   69, -459]   3.140
std::string Line2D::toString(){
    //we create a stringstream to use io-manipulator like setw() setprecision()
    //std::setw(4) sets the minimum width to print to 4  

   std::stringstream output;
   output<<
   "["<<std::setw(4)<<pt1.getX()<<", "<<std::setw(4)<<pt1.getY()<<"]  " //first point
   "["<<std::setw(4)<<pt2.getX()<<", "<<std::setw(4)<<pt2.getY()<<"]  " //second point
   <<std::setprecision(3)<<std::fixed<<getScalarValue()<<"\n"; //length

   return output.str();                     
}



//overload < operator to sort and remove duplicates easily
bool Line2D::operator <(const Line2D &l1){
    if(pt1==l1.pt1){
       return pt2<l1.pt2;
    }
    return pt1<l1.pt1;
}


//functions on how to sort my Line2D, all of them sort int ascending order
bool Line2D::sortByPt1(Line2D &a,Line2D &b){
     //use the overloaded < operator of point class
    return a.pt1<b.pt1;
}
bool Line2D::sortByPt2(Line2D &a,Line2D &b){
     //use the overloaded < operator of point class
    return a.pt2<b.pt2;
}
bool Line2D::sortByLength(Line2D &a,Line2D &b){
     //use the overloaded < operator of point class
    return a.length<b.length;
}
