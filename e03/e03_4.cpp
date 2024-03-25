// e03_4.cpp
// Accessors (Getters) and Mutators (Setters)


// #include <cmath>         // Prior to C++23 header file for the std::sqrt() function
// #include <print>			// Prior to C++23 header file for std::print and std::println
import std;                 // Since C++23  

// Point class with lower limits
class Point{							// Definition of the Point Class with low-limits
public:
	double distanceFromZero();			// Calculates and returns the distance of a point from (0,0)
	// Getters:
	int getX() { return m_x; }         // Accessor for x coordinate
	int getY() { return m_y; }         // Accessor for y coordinate
	int getMIN_x() { return MIN_x; }   // Accessor for the limit of the x coordinate
	int getMIN_y() { return MIN_y; }   // Accessor for the limit of the y coordinate
	// Setters:
	void setX(int);
	void setY(int);
	// Setters for constant memebers are useless
	//void setMIN_x(int);               // Setter for the const member is useless
	//void setMIN_y(int);               // Setter for the const member is useless
private:
	// Lower Limits of x and y. They are constants equal to zero 
	//Constants are usually defined as static members! (See static members)
	const int MIN_x { };				// Minimum value for x is zero
	const int MIN_y { };				// Minimum value for y is zero
	// x and y coordinates are initialized to their minimum values
	int m_x{ MIN_x }, m_y{ MIN_y };
};

// ***** Bodies of Member Functions *****

 // Calculates and returns the distance of a point from (0,0)
double Point::distanceFromZero() {
	return std::sqrt(m_x * m_x + m_y * m_y);   // distance from (0,0)
	// The sqrt() function returns the square root of a number. This function is defined in the cmath header file.
}

// Setters
// They checks the input values.
// The values are accepted only if they fall within the limits.
void Point::setX(int new_x){
    if (new_x >= MIN_x) m_x = new_x;	// Accepts only valid values 
  }
 void Point::setY(int new_y){
    if (new_y >= MIN_y) m_y = new_y;	// Accepts only valid values 
  }


 // Main function to test the Point class
int main()
{
  Point point1;							// point1 object is defined
  std::println("x = {} y= {}", point1.getX(), point1.getY());
  std::println("Distance from Zero = {}", point1.distanceFromZero() );

  point1.setX(10);    // Accepted
  point1.setY(-10);	  // Not accepted
  std::println("The low-limits for the coordinates are:");
  std::println("MIN_x = {} MIN_y= {}", point1.getMIN_x(), point1.getMIN_y() );
  std::println("The currrent coordinates are:");
  std::println("x = {} y= {}", point1.getX(), point1.getY() );
  std::println("Distance from Zero = {}", point1.distanceFromZero() );
  return 0;
}