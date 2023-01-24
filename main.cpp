#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"
using namespace std;

//for storing related objects;
vector<Point2D> Point2DVector;
vector<Point3D> Point3DVector;
vector<Line2D> Line2DVector;
vector<Line3D> Line3DVector;


//string representation of our options

vector<string> filterCriteria = {"Point2D", "Point3D", "Line2D", "Line3D"};

vector<string> sortBy = {"x-ordinate", "y-ordinate", "z-ordinate", "Dist Fr Origin", "Pt. 1", "Pt. 2", "length"};

vector<string> order = {"ASC", "DSC"};

//these variables holds the criteria options
int currentFilter = 0;
int currentSorting = 0;
int currentOrder = 0;

void ReadInData()
{
    //clear all previous data
    Point2DVector.clear();
    Point3DVector.clear();
    Line2DVector.clear();
    Line3DVector.clear();

    string filename;
    cout << "\nPlease enter filename : ";
    cin >> filename;

    int recordCount = 0;


    fstream newfile;
    newfile.open(filename,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string line;
        while(getline(newfile, line)){
            //now we need to determine what type of data this line represents
            //We find the first comma in this line and extract the name
            int firstCommaPos = line.find(',');

            string name = line.substr(0, firstCommaPos);

            string data = line.substr(firstCommaPos + 1); //rest of the data without name

            //so far if a line is Point2D, [2, 5]
            //name has the value "Point2D"
            //data has the value [2, 5]

            //add the object to appropriate containers
            //by calling the appropriate constructors
            if(name == "Point2D")
            {
                Point2DVector.push_back( Point2D(data) );
            }
            else if(name == "Point3D")
            {
                Point3DVector.push_back(Point3D(data));
            }
            else if(name == "Line2D")
            {
                Line2DVector.push_back(Line2D(data));
            }
            else Line3DVector.push_back(Line3D(data));

        recordCount++;

        }
        newfile.close(); 
        //remove duplicates from each vector
        //std::unique wont work if the elements are no sorted
        //sort will use default < comparison that we overloaded in each class

        sort(Point2DVector.begin(), Point2DVector.end());
        sort(Point3DVector.begin(), Point3DVector.end());
        sort(Line2DVector.begin(), Line2DVector.end());
        sort(Line3DVector.begin(), Line3DVector.end());

        //std:unique() removes the duplicates and returns the iterator to the last element
        //of the new formed container
        auto it = std::unique (Point2DVector.begin(), Point2DVector.end());
        auto it1 = std::unique (Point3DVector.begin(), Point3DVector.end());
        auto it2 = std::unique (Line2DVector.begin(), Line2DVector.end());
        auto it3 = std::unique (Line3DVector.begin(), Line3DVector.end());

        //unique() removes the duplicates but the container size remains same
        //so we resize the container
        Point2DVector.resize( std::distance(Point2DVector.begin(), it) );
        Point3DVector.resize( std::distance(Point3DVector.begin(), it1) );
        Line2DVector.resize( std::distance(Line2DVector.begin(), it2) );
        Line3DVector.resize( std::distance(Line3DVector.begin(), it3) );

        cout << "\n" << recordCount << " records read in successfully!" << endl;
        cout << "\nGoing back to main menu..." << endl;
    }
    else{
        cout << "Error! Could not load the file : " + filename << endl;
    }
}

void FilterCriteria()
{

    cout << "\n[ Specifying filtering criteria (current : " << filterCriteria[currentFilter] << ") ]\n\n";
    cout << "\ta)\tPoint2D records\n";
    cout << "\tb)\tPoint3D records\n";
    cout << "\tc)\tLine2D records\n";
    cout << "\td)\tLine3D records\n";

    cout << "\n\tPlease enter your criteria (a-d): ";
    char choice;
    cin >> choice;
    if(choice >= 'a' && choice <= 'd')
    {
        if(choice == 'a'){
            currentFilter = 0;
        }

        else if(choice == 'b'){
            currentFilter = 1;
        }

        else if(choice == 'c'){
            currentFilter = 2;
        }

        else if(choice == 'd'){
            currentFilter = 3;
        }

        if(currentFilter==2 || currentFilter==3){ //set the default sorting criteria for Lines
            currentSorting=4;
        }
        else{
            //set the default sorting criteria for points
            currentSorting=0;
        }
        cout << "\tFilter criteria successfully set to " + filterCriteria[currentFilter] << "!" << endl;
    }
    else
    {
        cout << "\tError!  Invalid choice!" << endl;
    }
    cout << "..." << endl;
}

void SortCriteria(){

    char choice;

    cout << "\n[ Specifying sorting criteria (current : " << sortBy[currentSorting] << ") ]\n" << endl;
	
    if(currentFilter == 0){
        cout << "\ta)\tX ordinate value\n";
        cout << "\tb)\tY ordinate value\n";
        cout << "\tc)\tDist Fr Origin value\n";
        cout << "\n\tPlease enter your criteria (a-c): ";
        cin>>choice;

        if(choice=='a'){
            currentSorting=0;
            cout << "\tSorting criteria successfully set to " + sortBy[currentSorting] << endl;
        }

        else if(choice=='b'){
            currentSorting=1;
            cout << "\tSorting criteria successfully set to " + sortBy[currentSorting] << endl;
        }

        else if(choice=='c'){
            currentSorting=3;
            cout << "\tSorting criteria successfully set to " + sortBy[currentSorting] << endl;
        }

        else{
            cout << "\tError! Invalid choice! " << endl;
        }
    }

    else if(currentFilter == 1){
        cout << "\ta)   X ordinate value " << endl;
        cout << "\tb)   Y ordinate value " << endl;
        cout << "\tc)   Z ordinate value " << endl;
        cout << "\td)   Dist Fr Origin value " << endl;
        cout << "\n     Please enter your criteria (a-d): ";
        cin>>choice;
        
        if(choice=='a'){
            currentSorting=0;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }
        else if(choice=='b'){
            currentSorting=1;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }
        else if(choice=='c'){
            currentSorting=2;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }
        else if(choice=='d'){
            currentSorting=3;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }

        else{
            cout << "\tError! Invalid choice! " << endl;
        }
    }

    else{
        cout << "\ta)\tPt. 1\'s (x, y) values" << endl;
        cout << "\tb)\tPt. 2\'s (x, y) values" << endl;
        cout << "\tc)\tLength value" << endl;
        cout << "\n\tPlease enter your criteria (a-c): ";
        cin>>choice;
        
        if(choice=='a'){
            currentSorting=4;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }
        else if(choice=='b'){
            currentSorting=5;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl;
        }
        else if(choice=='c'){
            currentSorting=6;
            cout << "\tSorting criteria successfully set to \'" + sortBy[currentSorting] + "\'" << endl << endl;
        }
        else{
            cout << "\tError! Invalid choice! " << endl <<endl;
        }
    }
}

void OrderCriteria(){

    cout << "\n[ Specifying sorting order (current : " << order[currentOrder] << ") ]" << endl;
    cout << "\ta)\tASC (Ascending order)" << endl;
    cout << "\tb)\tDSC (Descending order)" << endl;

    cout << "\n\tPlease enter your criteria (a-b): ";
    char choice;
    cin >> choice;
    if(choice == 'a') {
        currentOrder = 0;
        cout << "\tSorting order successfully set to \'" + order[currentOrder] + "\'" << endl;
    }

    else if (choice == 'b'){
        currentOrder = 1;
        cout << "\tSorting order successfully set to \'" + order[currentOrder] + "\'" << endl;
    }
    else
    {
        cout << "\tError!\n\tInvalid choice!" << endl;
    }

}


void sortData(){
     
     if(currentFilter==0){

          if(currentSorting==0)
            sort(Point2DVector.begin(), Point2DVector.end(),Point2D::sortByX);
          
          else if(currentSorting==1)
            sort(Point2DVector.begin(), Point2DVector.end(),Point2D::sortByY);
          
          else if(currentSorting==3)
            sort(Point2DVector.begin(), Point2DVector.end(),Point2D::sortByDistFrOrigin);
        
        //if sorting order is is descending just reverse the vector 
        if(currentOrder==1)
            reverse(Point2DVector.begin(), Point2DVector.end());
     }
     else if(currentFilter==1){

          if(currentSorting==0)
            sort(Point3DVector.begin(), Point3DVector.end(),Point3D::sortByX);
          
          else if(currentSorting==1)
            sort(Point3DVector.begin(), Point3DVector.end(),Point3D::sortByY);
          
          else if(currentSorting==2)
            sort(Point3DVector.begin(), Point3DVector.end(),Point3D::sortByZ);
          
          else if(currentSorting==3)
            sort(Point3DVector.begin(), Point3DVector.end(),Point3D::sortByDistFrOrigin);
        
        //if sorting order is is descending just reverse the vector 
        if(currentOrder==1)
            reverse(Point3DVector.begin(), Point3DVector.end());
     }
     else if(currentFilter==2){

           if(currentSorting == 4)
            sort(Line2DVector.begin(), Line2DVector.end(),Line2D::sortByPt1);

           else if(currentSorting == 5)
            sort(Line2DVector.begin(), Line2DVector.end(),Line2D::sortByPt2);

           else if(currentSorting == 6)
            sort(Line2DVector.begin(), Line2DVector.end(),Line2D::sortByLength);
     
        if(currentOrder==1)
            reverse(Line2DVector.begin(), Line2DVector.end());
     }
     else if(currentFilter==3){

           if(currentSorting == 4)
            sort(Line3DVector.begin(), Line3DVector.end(),Line3D::sortByPt1);

           else if(currentSorting == 5)
            sort(Line3DVector.begin(), Line3DVector.end(),Line3D::sortByPt2);

           else if(currentSorting == 6)
            sort(Line3DVector.begin(), Line3DVector.end(),Line3D::sortByLength);
     
        if(currentOrder==1)
            reverse(Line3DVector.begin(), Line3DVector.end());
     }
}

void viewData(){

     sortData();

     string content;
     if(currentFilter==0){
        content.append("    X     Y   Dist. Fr Origin \n");
        content.append("------------------------------ \n");
        for(auto &x:Point2DVector)
            content.append(x.toString());
        
     }    
     else if(currentFilter==1){
        content.append("    X     Y     Z   Dist. Fr Origin \n");
        content.append("-------------------------------------- \n");
        for(auto &x:Point3DVector)
            content.append(x.toString());
     }    
     else if(currentFilter==2){
        content.append(" P1-X  P1-Y    P2-X  p2-Y   Length \n");
        content.append("--------------------------------------- \n");
        for(auto &x:Line2DVector)
            content.append(x.toString());
     }    
     else if(currentFilter==3){
        content.append(" P1-X  P1-Y  P1-Z    P2-X  p2-Y  P2-Z   Length \n");
        content.append("--------------------------------------------------- \n");
        for(auto &x:Line3DVector)
            content.append(x.toString());
     }

    cout<< endl << "[View data ...]" << endl;
    cout<<" filtering criteria : "<<filterCriteria[currentFilter]<<endl;
    cout<<" sorting criteria : "<<sortBy[currentSorting]<<endl;
    cout<<" sorting order : "<<order[currentOrder]<<endl;;
    cout<<content<<endl;

    cout<<"Press any key to go back to main menu ..." << endl;

    getchar();
    getchar();


}



void storeData(){

    sortData(); //make sure we sort the data first according to the filter criteria selected before saving to a file
    int recordsToWrite; 
    string content;

    string filename;
    cout<<" Please enter filename : ";
    cin>>filename;


    ofstream outData;
    outData.open(filename);

    if (outData.is_open()){   //checking whether the file is open{
        if(currentFilter==0){
            content.append("    X     Y   Dist. Fr Origin \n");
            content.append("------------------------------ \n");
            for(auto &x:Point2DVector)
                content.append(x.toString());

            recordsToWrite=Point2DVector.size();
        }    
        else if(currentFilter==1){
            content.append("    X     Y     Z   Dist. Fr Origin \n");
            content.append("-------------------------------------- \n");
            for(auto &x:Point3DVector)
                content.append(x.toString());

            recordsToWrite=Point3DVector.size();
        }    
        else if(currentFilter==2){
            content.append(" P1-X  P1-Y    P2-X  p2-Y   Length \n");
            content.append("--------------------------------------- \n");
            for(auto &x:Line2DVector)
                content.append(x.toString());

            recordsToWrite=Line2DVector.size();
        }    
        else if(currentFilter==3){
            content.append(" P1-X  P1-Y  P1-Z    P2-X  p2-Y  P2-Z   Length \n");
            content.append("--------------------------------------------------- \n");
            for(auto &x:Line3DVector)
                content.append(x.toString());
            
            recordsToWrite=Line3DVector.size();
        }
        
        outData<<"filtering criteria : "<<filterCriteria[currentFilter]<<endl;
        outData<<"sorting criteria : "<<sortBy[currentSorting]<<endl;
        outData<<"sorting order : "<<order[currentOrder]<<endl;
        outData<<content<<endl;

        cout<<"\n"<<recordsToWrite<<" records output successfully!" << endl;
        cout<<"Going back to main menu ..." << endl;
        outData.close();
    }

    else{
        cout<<"Error! Could not open file" << endl;
        return;
    }
}

void displayMainMenuOptions ()
{
	cout << "1)    Read in data" << endl;
    cout << "2)    Specify filtering criteria (current : " << filterCriteria[currentFilter] << ")" << endl;
    cout << "3)    Specify sorting criteria (current : " << sortBy[currentSorting] << ")" << endl;
    cout << "4)    Specify sorting order (current : " << order[currentOrder] << ")" << endl;
    cout << "5)    View data" << endl;
    cout << "6)    Store data" << endl;
    cout << "8)	   Quit" << endl;
    cout << "Please enter your choice : ";
}



int main(){

    cout << "Student ID   : 7311849" << endl;
    cout << "Student Name : " << "Roxy Charisse Abastillas Libor" << endl;
    cout << "----------------------------------------------------" << endl;

    int usersChoice = 0;
    do
    {
        displayMainMenuOptions ();
		while (true)
 		{
    		cin >> usersChoice;
    		if (!cin){
      			cout << "Please enter a valid choice " << endl;
      			cin.clear();
      			cin.ignore(numeric_limits<streamsize>::max(), '\n');
      			continue;
    		}
    		else break;
  		}
        cout << endl;
        
        switch (usersChoice)
        {
            case 1 : 
				{	
					ReadInData();
				}
				break;
				
       	    case 2 : 
				{	
					FilterCriteria();
				}
				break;
				
			case 3 : 
				{
					SortCriteria();	
				}
				break;
				
			case 4 : 
				{
                    OrderCriteria();
				}
				break;	

            case 5 : 
				{
                    viewData();
				}
				break;

            case 6 : 
				{
                    storeData();
				}
				break;

            case 8 : 
				{cout << endl << "Have a nice day!"  << endl << 		endl; }
				break;
				
			default: cout <<  "You have entered an invalid value. Please enter a valid option"   ;   
        }
    } while (usersChoice != 8);
	return (0);

}
