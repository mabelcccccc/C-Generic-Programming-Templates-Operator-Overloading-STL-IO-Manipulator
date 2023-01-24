#include "Point3D.h"

void Point3D::setDistFrOrigin()
{
    distFrOrigin = sqrt(x * x + y * y + z * z);
}

//empty constructor
Point3D::Point3D() {}

//constructor to initialize with given (x,y,z)
//call the super class constructor first
Point3D::Point3D(int x, int y, int z): Point2D(x, y), z(z)
{
    setDistFrOrigin();
}

//getter and setter methods
int Point3D::getZ()
{
    return this->z;
}
void Point3D::setZ(int z)
{
    this->z = z;
    setDistFrOrigin();
}

void Point3D::setX(int x)
{
    this->x = x;
    setDistFrOrigin();
}
void  Point3D::setY(int y)
{
    this->y = y;
    setDistFrOrigin();
}

Point3D::Point3D(std::string val)
{
	if(val.empty()!=true){ //we don't process that line from the file, if that line is just empty
	    
		// we iterate though the string, check each character and remove brackets and spaces if any
	    // then store that string into newString
	    std::string newVal;
	    for(char ch : val)
	    {
			if(ch != '[' && ch != ' ')
			{
				newVal.push_back(ch);//we can treat a string like a vector in STL
			}
	    }

	    //new val is surely in x,y,z from

		//so search for the commas and split the newVal into 3 separate strings to extract each ordinates
		//find the first comma
	    int commaPos1 = newVal.find(','); //find the position of the comma

	    //find the second comma, from the first comma till the end of the string
	    int commaPos2 = newVal.find(',', commaPos1 + 1);

	    //substr(0,commaPos) returns a substring from 0 to before the first comma
	    //substr(commaPos1 + 1, commaPos2 - commaPos1)   returns a substrign from character after first comma to the 2nd comma
		//substr(commaPos2 + 1) returns a substring from second comma till the end of the string
	    std::string xx = newVal.substr(0, commaPos1);
	    std::string yy = newVal.substr(commaPos1 + 1, commaPos2 - commaPos1);
	    std::string zz = newVal.substr(commaPos2 + 1);

	    //now convert those string to integer using stoi() then assign it to the Point2D object's x,y,z's attributes
	    this->x = std::stoi(xx);
	    this->y = std::stoi(yy);
	    this->z = std::stoi(zz);
	    setDistFrOrigin();
	}
}

double Point3D::getScalarValue()
{
    return this->distFrOrigin;
}

//overload the equality operator
bool Point3D::operator ==(Point3D other)
{
    return x == other.getX() && y == other.getY() && z == other.getZ();
}


//overload << operator to print Point 
std::ostream &operator<<( std::ostream &output, Point3D &p )
{

    output << "[" << p.getX() << ", " << p.getY() << ", " << p.getZ() << "] distFrOrigin : " << std::setprecision(3) << std::fixed << p.getScalarValue();
    return output;
}


//returns a string to print Point3D on the screen or file
//[  29,  -29,  999]  3.140
std::string Point3D::toString()
{
    //we create a stringstream to use io-manipulator like setw() setprecision()
	//std::setw(4) sets the minimum width to print to 4 
    std::stringstream output;
    output << "[" << std::setw(4) << getX() << ", " << std::setw(4) << getY() << ", " << std::setw(4) << getZ() << "]  " << std::setprecision(3) << std::fixed << getScalarValue()<<"\n";

    return output.str();
}

//overload < operator to sort and remove duplicates easily
bool Point3D::operator <(const Point3D &p1)
{

    if(x == p1.x)
    {
        if(y == p1.y)return z < p1.z;

        return y < p1.y;
    }
    return x < p1.x;
}


//functions on how to sort my Point3D, all of them sort int ascending order
bool Point3D::sortByX(const Point3D &a, const Point3D &b)
{
    return a.x < b.x;
}
bool Point3D::sortByY(const Point3D &a, const Point3D &b)
{
    return a.y < b.y;
}
bool Point3D::sortByZ(const Point3D &a, const Point3D &b)
{
    return a.z < b.z;
}
bool Point3D::sortByDistFrOrigin(const Point3D &a, const Point3D &b)
{
    return a.distFrOrigin < b.distFrOrigin;
}
