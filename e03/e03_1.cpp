// e03_1.cpp
// Declaring and defining classes
// Point class
// As we have not yet covered all the subjects, this program has some shortcomings.
// We will improve it later

// #include <print>			// Prior to C++23 header file for std::print and std::println
import std;                 // Since C++23         

class Point{					// Definition of the Point Class
public:
	void move(int, int);		// A function to move points
	void print();				// to print cordinates on the screen
	bool isOnZero();		   // is point on the zero point(0,0)?
private:
	int m_x{}, m_y{};		   // Properties: x and y coordinates. Initial values: 0,0
};

// ***** Bodies of Member Functions *****

// A function to move the points 
void Point::move(int new_x, int new_y)
{
	m_x = new_x;				// assigns new value to x coordinat
	m_y = new_y;				// assigns new value to y coordinat 
}

// To print the coordinates on the screen 
void Point::print()
{
	std::println("X= {}, Y= {}", m_x, m_y);
}
				
// is the point on the zero point(0,0)
bool Point::isOnZero()
{
	return (m_x == 0) && (m_y == 0);	  
}

// Main function to test the Point class
int main()
{
	Point point1, point2;					// 2 object are defined: point1 and point2
	std::print("Cooridnates of the point1: ");
	point1.print();							// point1's coordinates to the screen
	point1.move(500,50);			// point1 moves to (100,50)
	std::print("Cooridnates of the point1: ");
	point1.print();							// point1's coordinates to the screen
	std::print("Cooridnates of the point2: ");
	point2.print();							// point2's coordinates to the screen
	if(point1.isOnZero())					// is point1 on (0,0)?
		std::println("point1 is on zero point(0,0)");
	else
		std::println("point1 is NOT on zero point(0,0)");
	if(point2.isOnZero())					// is point2 on (0,0)?
		std::println("point2 is on zero point(0,0)");
	else
		std::println("point2 is NOT on zero point(0,0)");
	return 0;
}