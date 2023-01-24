#include "Point2D.h"

void Point2D::setDistFrOrigin()
{
    distFrOrigin = sqrt((x * x) + (y * y));
}

//empty constructor
Point2D::Point2D() {}

//constructor to initialize with given (x,y)
Point2D::Point2D(int x, int y): x(x), y(y)
{
   setDistFrOrigin();
}

//getters and setters methods
int Point2D::getX()
{
    return this->x;
}
void Point2D::setX(int x)
{
    this->x = x;
    setDistFrOrigin();
}
int Point2D::getY()
{
    return this->y;
}
void  Point2D::setY(int y)
{
    this->y = y;
    setDistFrOrigin();
}
double Point2D::getScalarValue()
{
    return this->distFrOrigin;
}

Point2D::Point2D(string val)
{
	if(val.empty()!=true){	//we don't process that line from the file, if that line is just empty
	    
		// we iterate though the string, check each character and remove brackets and spaces if any
	    // then store that string into newString
	    string newString;
	    for(char ch : val)
	    {
			if(ch != '[' && ch != ' ')
			{
				newString.push_back(ch);//we can treat a string like a vector in STL
			}
	    }

	    //now new val is in x,y from

	    //so search for the comma and split the newVal into 2 separate strings to extract each ordinates
		//find the position of the comma
	    int commaPos = newString.find(','); 

	    //substr(0,commaPos) returns a substring from 0 to before the comma
	    //substr(commaPos + 1)   returns a substrign from character after comma to end of the string
	    string xx = newString.substr(0, commaPos);
	    string yy = newString.substr(commaPos + 1);

	    //now convert those string to integer using stoi() then assign it to the Point2D object's x and y attributes
	    this->x = stoi(xx);
	    this->y = stoi(yy);
	    setDistFrOrigin();
	}
}

//overload the equality operator
bool Point2D::operator ==(Point2D other){
   return x==other.getX() && y==other.getY();
}

//overload << operator to print the to print a Point2D object
std::ostream &operator<<( std::ostream &output, Point2D &p ){
   
	//setprecision(3) makes sure no more than 3 d.p
	//std::fixed is used to set fixed 3 d.p
	output<<"["<<p.getX()<<", "<<p.getY()<<"] distFrOrigin : "<<setprecision(3)<<fixed<<p.getScalarValue();

    return output;
                                                        
}

//to print a Point2D object in the below format
string Point2D::toString(){
	//we create a stringstream to use io-manipulator like setw() setprecision()
	//std::setw(4) sets the minimum width to print to 4 
   stringstream output;
   output<<"["<<setw(4)<<getX()<<", "<<setw(4)<<getY()<<"]  "<<setprecision(3)<<fixed<<getScalarValue()<<"\n";
   
   return output.str();
}

//overload < operator to sort and remove duplicates easily
bool Point2D::operator <(const Point2D &p1){

    if(x==p1.x){
       return y<p1.y;
    }
    return x<p1.x;
}

//functions on how to sort my Point2D, all of them sort int ascending order
bool Point2D::sortByX(const Point2D &a,const Point2D &b){
     return a.x<b.x;
}
bool Point2D::sortByY(const Point2D &a,const Point2D &b){
     return a.y<b.y;
}
bool Point2D::sortByDistFrOrigin(const Point2D &a,const Point2D &b){
     return a.distFrOrigin<b.distFrOrigin;
}
