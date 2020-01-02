#include <iostream>
#include <cmath>

using namespace std;

void errorCheck(string var1, double &var2); 
void areaErrorCheck(string var1, double &var2);

int main(void) {

	/* User inputs information for square 1 */


	double sqr1_UpperLeftX, sqr1_UpperLeftY, sqr1_area;  // Variables for Square 1

	cout << "Enter the information for the first square" << endl;


	cout << "x-coordinate: " ;
	cin >> sqr1_UpperLeftX;
	errorCheck("x-coordinate", sqr1_UpperLeftX);


	cout << "y-coordinate: " ;
	cin >> sqr1_UpperLeftY;
	errorCheck("y-coordinate", sqr1_UpperLeftY);

	cout << "area: " ;
	cin >> sqr1_area; 
	areaErrorCheck("area", sqr1_area);


	double sqr1_sideLength = sqrt(sqr1_area);		// side length of the square is computed using s = sqrt(A) formula

	double sqr1_LowerRightX = sqr1_UpperLeftX + sqr1_sideLength;		// Upper x bound of square computed

	double sqr1_LowerRightY = sqr1_UpperLeftY - sqr1_sideLength; 		// Lower y bound of square computed




	/* User inputs information for square 2 */


	double sqr2_UpperLeftX, sqr2_UpperLeftY, sqr2_area;		// Variables for square 2

	cout << "Enter the information for the second square" << endl;

	cout << "x-coordinate: " ;
	cin >> sqr2_UpperLeftX;
	errorCheck("x-coordinate", sqr2_UpperLeftX); 

	cout << "y-coordinate: " ;
	cin >> sqr2_UpperLeftY;
	errorCheck("y-coordinate", sqr2_UpperLeftY); 


	cout << "area: " ;
	cin >> sqr2_area; 
	areaErrorCheck("area", sqr2_area);

	double sqr2_sideLength = sqrt(sqr2_area);

	double sqr2_LowerRightX = sqr2_UpperLeftX + sqr2_sideLength;

	double sqr2_LowerRightY = sqr2_UpperLeftY - sqr2_sideLength; 



	/*Output*/

	// If either square is higher (in terms of their y bounds) than the other, they cannot intersect

	if ((sqr1_LowerRightY - sqr2_UpperLeftY > 0) || (sqr2_LowerRightY - sqr1_UpperLeftY > 0)) {
		cout << "THE SQUARES DO NOT INTERSECT" << endl;
		return 0;;
	}

	// If either square is to the left or right of each other with space in between them

	if ((sqr1_UpperLeftX - sqr2_LowerRightX > 0) || (sqr2_UpperLeftX - sqr1_LowerRightX > 0)) 
		cout << "THE SQUARES DO NOT INTERSECT" << endl;

	// Otherwise, they intersect

	else 
		cout << "THE SQUARES INTERSECT" << endl;


	return 0;
}


/*Function that passes by value the string associated with the value being error checked
and passes by reference the variable that is being error checked
Use cin.clear and cin.ignore to flush input buffer
If the user enters an invalid input they are prompted again*/

void errorCheck(string var1, double &var2)  {
	while (!cin) {
		cin.clear();	// Clears input stream 
		cin.ignore(4000, '\n');		// clears all letters including /n in the input buffer
		cout << "Please enter a real number!" << endl ;
		cout << var1 << ": " ;
		cin >> var2;
	} 
}

// Error checking for areas. Area can't be 0 or negative

void areaErrorCheck(string var1, double &var2)  {
	while (!cin || var2 <= 0) {
		cin.clear();	// Clears input stream 
		cin.ignore(4000, '\n');		// clears all letters including /n in the input buffer
		cout << "Please enter a nonzero positive real number!" << endl ;
		cout << var1 << ": " ;
		cin >> var2;
	} 
}

