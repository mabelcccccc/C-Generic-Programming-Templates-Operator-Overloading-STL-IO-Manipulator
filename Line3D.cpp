#include "Line3D.h"

void Line3D::setLength()
{
    int xd = pt1.getX() - pt2.getX();
    int yd = pt1.getY() - pt2.getY();
    int zd = pt1.getZ() - pt2.getZ();

    this->length = sqrt(xd * xd + yd * yd + zd*zd);
}

//empty constructor
Line3D::Line3D(){}

//constructor to initialize by taking two 2D points
Line3D::Line3D(Point3D p1, Point3D p2){
	pt1=p1;
	pt2=p2;
	setLength();
}

//getters setters
Point3D Line3D::getPt1(){
	return pt1;
}
Point3D Line3D::getPt2(){
	return pt2;
}
double Line3D::getScalarValue(){
	return this->length;
}
void Line3D::setPt1(Point3D p1){
	this->pt1=p1;
	setLength();
}
void Line3D::setPt2(Point3D p2){
	this->pt2=p2;
	setLength();
}



Line3D::Line3D(std::string val)
{

    //search from start, returns position of first comma
    int comma1 = val.find(',');
    
    //search for comma again for 2nd comma
    //but search starts right after the first comma's position
    int comma2 = val.find(',', comma1 + 1);
                                           
    //search for comma again for 3rd comma
    //but search starts right after the second comma's position
    int comma3 = val.find(',', comma2 + 1); 
                                           
    //[x1, y1, z1], [x2, y2, z2]
    //0           ^comma3
    this->pt1=Point3D(val.substr(0,comma3));  
                                             

    //[x1, y1, z1], [x2, y2, z2] 
    //             ^comma3+1 to end
    this->pt2=Point3D(val.substr(comma3+1)); 
                                             
    setLength();
}



//overload the equality operator
bool Line3D::operator ==(Line3D other){
   return pt1==other.getPt1() && pt2==other.getPt2();
}


//overload << operator to print the point information
std::ostream &operator<<( std::ostream &output, Line3D &line ){
    //make use of the fact that we already overloaded << for Point2D
    Point3D p1=line.getPt1();
    Point3D p2=line.getPt2();

    output<<"( "<<p1<<" to "<<p2<<" ) length : "<<std::setprecision(3)<<std::fixed<<line.getScalarValue();

    return output;

}


//returns a string to print Line3DD on the screen or file in the below format
//[   9,   -9, 123]   [   69, -459,  -12]   3.140
std::string Line3D::toString(){

   std::stringstream output;
   output<<
   "["<<std::setw(4)<<pt1.getX()<<", "<<std::setw(4)<<pt1.getY()<<", "<<std::setw(4)<<pt1.getZ()<<"]  " //first point
   "["<<std::setw(4)<<pt2.getX()<<", "<<std::setw(4)<<pt2.getY()<<", "<<std::setw(4)<<pt2.getZ()<<"]  " //second point
   <<std::setprecision(3)<<std::fixed<<getScalarValue()<<"\n"; //length

   return output.str();
                      
}


//overload < operator to sort and remove duplicates easily
bool Line3D::operator <(const Line3D &l1){

    if(pt1==l1.pt1){
       return pt2<l1.pt2;
    }
    return pt1<l1.pt1;
}



//functions on how to sort my Line3D, all of them sort int ascending order
bool Line3D::sortByPt1(Line3D &a,Line3D &b){
     //use the overloaded < operator of point class
    return a.pt1<b.pt1;
}
bool Line3D::sortByPt2(Line3D &a,Line3D &b){
     //use the overloaded < operator of point class
    return a.pt2<b.pt2;
}
bool Line3D::sortByLength(Line3D &a,Line3D &b){
     //use the overloaded < operator of point class
    return a.length<b.length;
}
