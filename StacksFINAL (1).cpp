//	Jiten Bhojwani
//	Frank Yoo
//	Joseph Elikishvili
//	Matheus Barbosa
//	David Ribeiro
//
//  Stacks program
//	Due Date: 2/11/16

// Constant for the size of the stack
const int SIZE = 10;

//Structures
struct inforec
{
	int number;
};

struct Stack
{
	inforec i[SIZE];
	int top;
};

//Function Prototypes
void createStack (Stack&);
int empty (Stack&);
void pop (Stack&, inforec&);
int top (Stack&);				
void push (Stack&, inforec&);
void purge (Stack&);

//const int SIZE = 10;

#include <iostream>
using namespace std;
int main()
{
    
    Stack s;				// Variable for structure Stack
	inforec item;			// Variable for structure inforec 
	int x;					// Variable for user selection
    bool QUIT; 				// Variable to quit the menu
    
    s.top = -2;				//Initialization of s.top for input validation. When a stack is created, it becomes -1, and the user can access the functions
    
	while (QUIT == 0)
	 {
    	cout << "YOU MUST CHOOSE!" << endl;
    	cout << "1.) Create a stack." << endl;
    	cout << "2.) Is it empty?" << endl;
    	cout << "3.) Push something on the stack." << endl;
    	cout << "4.) Pop something off the stack." << endl;
    	cout << "5.) The stack top." << endl;
    	cout << "6.) Kill the stack." << endl;
    	cout << "0.) Leave." << endl;
    	cin >> x;
    
    
    	//Input validation
    	while (x < 0 || x > 6)
    	{
    		cout << "Invalid input! Please enter a number between 1 and 6" << endl;
    		cin >> x;
    	}
    
    	//Switch statement based on the menu options.
    	switch (x)
    	{
        	// Create a stack.
        	case 1:
         		createStack(s);
         		cout << "The stack has been created!" << endl << endl;
            	break;
        	
    		//Check whether the stack is empty.
        	case 2:
        		//Input validation. If the stack was not created, user cannot proceed
        		if (s.top < -1)
        		{
        			cout << "The stack has not been created. Please create a stack" << endl << endl;
    				break;
    			}
    			else
    				if (empty(s))
    				{
						cout << "The stack is empty" << endl << endl;
					}
					else
						cout << "The stack is not empty" << endl << endl;
             	break;
            
            //Push a record onto the stack.
        	case 3:
        		if (s.top < -1)
        		{
        			cout << "The stack has not been created. Please create a stack" << endl << endl;
    				break;
    			}
    		
    			cout << "Please enter a number you want to push onto the stack" << endl << endl;
    			cin >> item.number;
    		
     			push(s, item);
            	break;
            
        	//Pop a record off of the stack.
        	case 4:
        		//Input validation. If stack was not created, user cannot proceed
        		if (s.top < -1)
        		{
        			cout << "The stack has not been created. Please create a stack" << endl << endl;
    				break;
    			}
    		
    			//Input validation. User is not able to pop empty stacks.
    			//if (s.top = -1)
    			//{
    			//	cout << "There are no items to pop" << endl << endl;
    			//	break;
    			//}
    		
    			pop(s, item);
            	break;
            
        	//Get the current top of the stack.
        	case 5:
        		//Input validation. If the stack was not created, user cannot proceed
        		if (s.top < -1)
        		{
        			cout << "The stack has not been created. Please create a stack" << endl << endl;
    				break;
    			}
    		
    			cout << "Current Top item: " << top(s) << endl;
            	break;
            
            //Purge the stack contents
        	case 6:
           		if (s.top < -1)
        		{
        			cout << "The stack has not been created. Please create a stack" << endl << endl;
    				break;
    			}
    			
    			purge(s);
            	break;
            
            //Quit the program.
        	case 0:
            	QUIT = 1;
            	break;
    	}
 	}
    return 0;
}

//Functions

void createStack (Stack & s)
{
    s.top = -1;
    //int count = 0;
}

int empty(Stack & s)
{
	return (s.top == -1);
}

void pop(Stack & s, inforec & item) 
 {
 	if (s.top == -1)
 	{
 		cout << "Stack underflow! There is nothing on the stack." << endl << endl;
	}
	
 	item = s.i[s.top --]; 
 } 
 
void push(Stack & s, inforec & item) 
 {
 	++ s.top;
 	
	if (s.top == SIZE)
	{
		cout << "Stack overflow! The stack is currently full." << endl << endl;
	}
	
	s.i[s.top] = item; 
 } 

int top(Stack & s) 
 {
   return (s.i[s.top].number); 
 } 
 	
void purge(Stack & s)
{
	s.top = -2;
	cout << "The stack has been deleted!" << endl << endl;
}
