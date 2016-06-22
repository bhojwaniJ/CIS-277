//Vector Project
//Prof. Almajal
//Due by 2/4/2016


#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/*Structure VECTOR. Will have two variables for the two values of the 
two-dimentional vector, and variable for the name */

struct VECTOR
{
	float 	x, // Vector's first value
		 	y; // Vector's second value
	string  n; // Vector's name
};

//Function Prototypes
void get_vector (VECTOR&); 
void calc_sum (VECTOR, VECTOR, VECTOR&); 	
void print_vector (VECTOR);					
void calc_differ (VECTOR, VECTOR, VECTOR&);	
void scalar_mult (VECTOR, int, VECTOR&);	
float scalar_prod (VECTOR, VECTOR);			
float magnitude (VECTOR);

int main()
{
 // List of Variables
	VECTOR 	vec1 ={0,0, "Vector 1"}, 	// First vector. Initialized to display first values on the menu
			vec2 ={0,0, "Vector 2"}, 	// Second vector. Initialized to display first values on the menu
			sum,		// Sum of the two vectors
			differ,		// Difference of the two vectors
			s_mult; 	// Scalar multiplication 
	
	int k = 10; 	// Constant variable for the scalar multiplication
	int x;			// Will hold a value to select an option from the menu
	bool QUIT;		// Variable to quit the menu
	
//Main while loop for the menu	
	while (QUIT == 0)
	{
		//Intro message
		cout << "Welcome to our Vector Math program!" << endl;
		
		//Print function to display the values the user is working with
		cout << "These are your current vector values:" << endl;
		print_vector(vec1); 
		print_vector(vec2);
		
		//Menu options
		cout << "Please enter the number of the operation you would like to perform" << endl << endl;
		cout << "1. Enter new vector values" << endl;
		cout << "2. Add" << endl;
		cout << "3. Subtract" << endl;
		cout << "4. Scalar Multiplication" << endl;
		cout << "5. Scalar Product" << endl;
		cout << "6. Magnitude of Vector 1" << endl; 
		cout << "0. Exit program" << endl;
		
		//Prompt user to enter option
		cin >> x;
		cout << endl;
		
		//Input validation
		if (x < 0 || x > 6)
			{
				cout << "Invalid entry!" << endl;
				cout << "Please enter the number of the operation you would like to perform" << endl;
				cin >> x;
			}
		
		//Switch statement based on the menu options
		switch (x)
		{
			//Get vector values from user
			case 1: 
				get_vector(vec1);
				get_vector(vec2);
				break;
			
			//Calculate sum of vectors	
			case 2:
				calc_sum (vec1, vec2, sum);
				cout << "Sum: ";
				print_vector(sum);
				break;
			
			//Calculate difference of vectors
			case 3:
				calc_differ (vec1, vec2, differ);
				cout << "Difference: ";
				print_vector (differ);	
				break;
			
			//Calculate scalar multiplication of vector 1	
			case 4:
				scalar_mult (vec1, k, s_mult);
				cout << "Scalar multiple";
				print_vector(s_mult);
				break;
			
			//Calculate scalar product	
			case 5:
				
				cout << "Scalar product: ";
				cout << scalar_prod (vec1, vec2)<<endl; 
				break;
			
			//Calculate magnitude of vector 1	
			case 6:
				cout << "Magnitude of " <<  vec1.n << ":";
				cout << magnitude(vec1)<<endl; 
				break;
			//Stops the loop and exits the program	
			case 0:
				QUIT = 1;
				break;
		}
	}

 return 0;   

}

//FUNCTIONS

//Asks user for values and names of vectors
void get_vector (VECTOR &v)
{
	cout << "Please enter a value for the vector's first dimension" << endl;
	cin >> v.x;
	cout << "Please enter a value for the vector's second dimension" << endl;
	cin >> v.y;
	cout << "Please enter the name of the vector" << endl;
	cin.ignore();
	getline (cin,v.n);
	cout << endl;
	
}

//Adds the vectors
void calc_sum (VECTOR v1, VECTOR v2, VECTOR& s)
{
	s.x = v1.x + v2.x;
	s.y = v1.y + v2.y;
}

//Prints the vector desired
void print_vector (VECTOR v)
{
	cout << v.n << ": " << v.x << ", " << v.y << endl;
}

//Subtracts the two vectors
void calc_differ (VECTOR v1, VECTOR v2, VECTOR& d)
{
	d.x = v1.x - v2.x;
	d.y = v1.y - v2.y;
} 

// Multiplies Vector 1 times a constant variable
void scalar_mult (VECTOR v, int k, VECTOR& m)
{
	m.x = k * v.x;
	m.y = k * v.y;
}

// Multiplies the first dimention of vectors 1 and 2, and adds with the product of the second dimention of vectors 1 and 2
float scalar_prod (VECTOR v1, VECTOR v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

// Square root of the addition between the first dimention of vector 1 squared, and the second dimention of vector 1 squared
float magnitude (VECTOR v1)
{
	return  sqrt(pow(v1.x, 2.0) + pow(v1.y ,2.0)); 
}
