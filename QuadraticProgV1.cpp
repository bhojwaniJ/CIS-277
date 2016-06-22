//	*********************
//	Jiten Bhojwani		*
//	CIS-277				*
//	Quadratic Structure *
//	2/23/16				*
//	*********************

#include <iostream>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

// Quadratic Struct
struct quadratic
{
	double a; // First value in quadratic
	double b; // Second value in quadratic
	double c; // Third value in quadratic
	string n; // Name of the quadratic
};

// Vertex Struct
struct vertex
{
	double x; // Vertex's x coordinate
	double y; // Vertex's y coordinate
};

// Function Prototypes
void get_quadratic(quadratic &);
void print_quad(quadratic &);
void calc_sum(quadratic &, quadratic &, quadratic &);
double eval(quadratic &, double);
void find_vertex(quadratic &, vertex &);
void menu();

// Main
int main()
{
	// List of Variables
	quadratic	quad1,		// First quadratic
				quad2,		// Second quadratic
				sum;		// Sum of two quadratics
				sum = {0, 0, 0, "Sum"};
	vertex vertex_result;	// Vertex of a quadratic
	double x;				// Value used to evaluate quadratic
	
	int menuchoice;			// Holds value for menu selection
	int evalchoice;			// Holds value to select which quadratic to evaluate
	int vertexchoice;		// Holds value to select which quadratic to use
	
	bool QuadFlag = 0;		// Flag used to determine if quadratics
							// were declared before using other
							// options
						
	bool SumFlag = 0;		// Flag used to determine if two quadratics
							// were previously summed
						
	bool QUIT = 0;			// Variable to quit menu
	
	// Main While Loop. Loops through menu.
	while (QUIT == 0)
	{
		// Intro message
		cout << "Welcome to the Quadratic Math program!" << endl;
		
		// Menu options
		menu();
		
		// Prompt user to enter option
		cin >> menuchoice;
		cout << endl;
		
		// Input validation
		while (menuchoice < 1 || menuchoice > 6)
		{
			cout << "You entered an invalid option!" << endl;
			cout << "Please re-enter the number of the operation" << endl;
			cin >> menuchoice;
		}
		
		while (menuchoice >= 2 && menuchoice <=5 && QuadFlag == 0)
		{
			cout << "You have not declared quadratics first!" << endl;
			cout << "Please select menu option 1 to declare quadratics" << endl;
			menu();
			cin >> menuchoice;
			cout << endl;
		}
		
		switch (menuchoice)
		{
			// Enter new quadratic values
			case 1:
				get_quadratic(quad1);
				cout << endl;
				get_quadratic(quad2);
				cout << endl;
				QuadFlag = 1;
				SumFlag = 0;
				break;
				
			// Print current quadratics
			case 2:
				print_quad(quad1);
				print_quad(quad2);
				cout << endl;
				break;
				
			// Sum two quadratics
			case 3:
				calc_sum(quad1, quad2, sum);
				cout << "Sum = " << sum.a << "x^2 + " << sum.b << "x + " << sum.c << endl << endl;
				SumFlag = 1;
				break;
				
			// Evaluate a quadratic
			case 4:
				// Pick which quadratic to use
				cout << "Enter the number of the quadratic you would like to use" << endl << endl;
				cout << "1. " << quad1.n << endl;
				cout << "2. " << quad2.n << endl;
				if (SumFlag == 1)
					cout << "3. " << sum.n << endl;
				cin >> evalchoice;
				cout << endl;
				
				// Input Validation
				if (SumFlag == 0)
				{
					while (evalchoice < 1 || evalchoice > 2)
					{
						cout << "You entered an invalid option!" << endl;
						cout << "Please re-enter the number of the quadratic you would like to use" << endl;
						cin >> evalchoice;
						cout << endl;
					}
				}
				else if (SumFlag == 1)
				{
					while (evalchoice < 1 || evalchoice > 3)
					{
						cout << "You entered an invalid option!" << endl;
						cout << "Please re-enter the number of the quadratic you would like to use" << endl;
						cin >> evalchoice;
						cout << endl;
					}
				}
				
				// Get x used to evaluate quadratic
				cout << "What will be your x value used to evaluate the equation?" << endl;
				cin >> x;
				cout << endl;
				
				// Call evalchoice based on which quadratic to use
				switch (evalchoice)
				{
					// Quadratic 1
					case 1:
						cout << quad1.n << " = " << quad1.a << "x^2 + " << quad1.b << "x + " << quad1.c << ", x = " << x << endl;
						cout << quad1.n << " = " << eval(quad1, x) << endl;
						cout << endl;
						break;
					// Quadratic 2
					case 2:
						cout << quad2.n << " = " << quad2.a << "x^2 + " << quad2.b << "x + " << quad2.c << ", x = " << x << endl;
						cout << quad2.n << " = " << eval(quad2, x) << endl;
						cout << endl;
						break;
					// Sum
					case 3:
						cout << sum.n << " = " << sum.a << "x^2 + " << sum.b << "x + " << sum.c << ", x = " << x << endl;
						cout << sum.n << " = " << eval(sum, x) << endl;
						cout << endl;
						break;
				}
				break;
			// Find the vertex of a quadratic
			case 5:
				// Pick which quadratic to use
				cout << "Enter the number of the quadratic you would like to use" << endl << endl;
				cout << "1. " << quad1.n << endl;
				cout << "2. " << quad2.n << endl;
				if (SumFlag == 1)
					cout << "3. " << sum.n << endl;
				cin >> vertexchoice;
				cout << endl;
				
				// Input validation
				if (SumFlag == 0)
				{
					while (vertexchoice < 1 || vertexchoice > 2)
					{
						cout << "You entered an invalid option!" << endl;
						cout << "Please re-enter the number of the quadratic you would like to use" << endl;
						cin >> vertexchoice;
						cout << endl;
					}
				}
				else if (SumFlag == 1)
				{
					while (vertexchoice < 1 || vertexchoice > 3)
					{
						cout << "You entered an invalid option!" << endl;
						cout << "Please re-enter the number of the quadratic you would like to use" << endl;
						cin >> vertexchoice;
						cout << endl;
					}
				}
				
				// Call find_vertex based on which quadratic to use
				switch(vertexchoice)
				{
					// Quadratic 1
					case 1:
						find_vertex(quad1, vertex_result);
						cout << quad1.n << "'s Vertex = (" << vertex_result.x << ", " << vertex_result.y << ")" << endl;
						cout << endl;
						break;
					// Quadratic 2
					case 2:
						find_vertex(quad2, vertex_result);
						cout << quad2.n << "'s Vertex = (" << vertex_result.x << ", " << vertex_result.y << ")" << endl;
						cout << endl;
						break;
					// Sum
					case 3:
						cout << sum.n << "'s Vertex = (" << vertex_result.x << ", " << vertex_result.y << ")" << endl;
						cout << endl;
						break;
				}
				break;
			// Exit program
			case 6:
				QUIT = 1;
				break;
		}
	}
	
return 0;

}

// Functions

// Asks the user for the names and values of quadratics
void get_quadratic(quadratic &q)
{
	cout << "Please enter a name for your quadratic" << endl;
	cin.ignore();
	getline(cin, q.n);
	cout << "\nPlease enter a value for a in ax^2 + bx + c" << endl;
	cin >> q.a;
	cout << "\nPlease enter a value for b in ax^2 + bx + c" << endl;
	cin >> q.b;
	cout << "\nPlease enter a value for c in ax^2 + bx + c" << endl;
	cin >> q.c;
}

// Prints a quadratic to the screen
void print_quad(quadratic &q)
{
	cout << q.n << " = " << q.a << "x^2 + " << q.b << "x + " << q.c << endl;
}

// Calculates the sum of two quadratic equations
void calc_sum(quadratic &q1, quadratic &q2, quadratic &s)
{
	s.a = q1.a + q2.a;
	s.b = q1.b + q2.b;
	s.c = q1.c + q2.c;
}

// Evaluates a quadratic using a value for x
// and returns the result
double eval(quadratic &q, double x)
{
	return (q.a * pow(x, 2.0)) + (q.b * x) + q.c;
}

// Finds the vertex of a quadratic
void find_vertex(quadratic &q, vertex &v)
{
	v.x = - q.b / (2 * q.a);
	v.y = (q.c - q.a) / (4 * q.a);
}

// Outputs the menu
void menu()
{
	cout << "Please enter the number of the operation you would like to perform" << endl << endl;
	cout << "1.	Enter new quadratic values" << endl;
	cout <<	"2.	Print current quadratics"	<< endl;
	cout <<	"3.	Sum two quadratics"			<< endl;
	cout <<	"4.	Evaluate a quadratic"		<< endl;
	cout <<	"5.	Find the vertex of a quadratic"	<< endl;
	cout <<	"6.	Exit program"				<< endl;
}
