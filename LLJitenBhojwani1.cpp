// Designed by Jiten Bhojwani
// Dynamic Linked List using Structures

#include <iostream>
#include <string>

using namespace std;

//	Forward declaration of node struct
struct node;

//	Struct to hold list start pointer
//	and total count of nodes
struct list
{
	int count;
	node *head;
};

//	Structure for a single node
//	Contains a unique ID number, a name,
//	and a pointer to the next node
struct node
{
	int ID;
	string name;
	node *nxt;
};


//	Function Prototypes
void create_list(list&);
void add_node(list&, node&);
void delete_node(list&, node&);
void modify_node(list&, node&);
bool search_by_key(list&, node&);
void menu();
void node_input(node&);
void node_ID(node&);
void display_list(list&);


//	Main
int main()
{
	int menuchoice;
	node temp;
	list z;
	
	bool QUIT = 0;
	bool ListCreateFlag = 0;
	
	cout << "Welcome to the Linked List program!" << endl;
	
	while (QUIT == 0)
	{
		
		if (ListCreateFlag == 1)
		{
			cout << "Total Number of Nodes: " << z.count << endl;
			display_list(z);
			cout << endl << endl;
		}
		
		menu();
		cin >> menuchoice;
		cout << endl << endl;
		
		while(!cin)
		{
			cin.clear();
			cin.ignore();
			cout << "You did not enter a number for input" << endl;
			cout << "Your choice: ";
			cin >> menuchoice;
			cout << endl;
		}
		
		while (menuchoice < 1 || menuchoice > 6)
		{
			cout << "Invalid input! Please enter a number between 1 and 6" << endl;
    		cin >> menuchoice;
		}
		
		while (menuchoice >= 2 && menuchoice <= 5 && ListCreateFlag == 0)
		{
			cout << "You have not created a list first!" << endl;
			cout << "Please select menu option 1 to create a list" << endl;
			menu();
			cin >> menuchoice;
			cout << endl;
		}
		
		switch (menuchoice)
		{
			case 1:
				if (ListCreateFlag == 0)
				{
					create_list(z);
					ListCreateFlag = 1;
				}
				else if (ListCreateFlag == 1)
				{
					cout << endl << "You already created a list!" << endl;
				}
				
				break;
			case 2:
				node_input(temp);
				if (search_by_key(z, temp))
				{
					cout << "This ID already exists in the list!" << endl << endl;
				}
				else
				{
					add_node(z, temp);
					cout <<"The node with ID number " << temp.ID << " was added to your list.\n" << endl;
				}
				
				break;
			case 3:
				node_ID(temp);
				if (search_by_key(z, temp))
				{
					delete_node(z,temp);
					cout << "The node with ID number " << temp.ID << " was deleted from your list." << endl;
				}
				else
				{
					cout << endl << "The ID you input does not exist in your current list!" << endl;
				}
				
				break;
			case 4:
				node_ID(temp);
				if (search_by_key(z, temp))
				{
					modify_node(z, temp);
				}
				else
				{
					cout << endl << "The ID you input does not exist in your current list!" << endl;
				}
				
				break;
			case 5:
				node_ID(temp);
				if (search_by_key(z, temp))
				{
					cout << endl << "The node with ID number " << temp.ID << " and name ";
					cout << temp.name << " exists in your list" << endl;
				}
				else
				{
					cout << endl << "The ID you input does not exist in your current list!" << endl;
				}
				
				break;
			case 6:
				QUIT = 1;
				
				break;
				
		}
		
	}
	
	
}

//	Outputs the menu
void menu()
{
	cout << "	----------	" << endl;
	cout << "Please enter the number of the operation you would like to perform" << endl;
	cout << "	----------	" << endl;
	cout << "(1)	Create a list"				<< endl;
	cout <<	"(2)	Add a node"					<< endl;
	cout <<	"(3)	Delete a node"				<< endl;
	cout <<	"(4)	Modify a node"				<< endl;
	cout <<	"(5)	Search for a node"			<< endl;
	cout << "(6)	Quit"						<< endl;
	cout << "Your Choice: ";
}

//	Creates a list
void create_list(list& z)
{
     z.count = 0;
     z.head = NULL;
}

//	Adds a node
void add_node(list &z, node &n)
{
	//	Dynamically allocate node for inputted data
	node *input = new node;
	input->ID = n.ID;
	input->name = n.name;
	input->nxt = NULL;
	
	//	Create pointers for tracking flow through list
	node *current = z.head;
	node *previous = z.head;
	
	if (z.count == 0)	//	If there are no items on the list
	{
		z.head = input;
	}
	else
	{
		
		if (z.count == 1)	//	If there is one item on the list
		{
			if (n.ID < current->ID)
			{
				z.head = input;
				input->nxt = current;
			}
			else
			{
				current->nxt = input;
				input->nxt = NULL;
			}
		}
		else if (z.count > 1)	//	If there is more than one item on the list
		{
			if (n.ID < current->ID)	//	If the input is less than the first node
			{
				z.head = input;
				input->nxt = current;
			}
			else
			{
				current = current->nxt;	//	Advance the current pointer to set up
										//		comparison of input between two
										//		consecutive nodes.
				
				for (int count = 1; count < z.count; count++)	//	Count corresponds to the position of 'previous'
																//		in the list
				{
					if (n.ID > previous->ID && n.ID < current->ID)	//	If input is between two consecutive nodes
					{
						input->nxt = current;
						previous->nxt = input;
					}
					else if (n.ID > current->ID && count == z.count-1)	//	If input is greater than the last item
																		//		in the list
					{
						current->nxt = input;
						input->nxt = NULL;
					}
					else												//	If input does not meet any requirements
																		//		advance pointers and iterate loop.
					{
						previous = previous->nxt;
						current = current->nxt;
					}
				}
			}
		}
	}
	
	z.count++;
}

//	Deletes a node
void delete_node(list &z, node &n)
{
	node *current = z.head;
	
	node *previous = z.head;
	
	if (z.count == 0)
	{
		cout << "Your list is already empty!" << endl;
	}
	else
	{
		
		if (z.count == 1)
		{
			z.head = z.head->nxt;
			delete current;
		}
		else if (z.count > 1)
		{
			
			current = current->nxt;
			
			for (int count = 1; count < z.count ; count++)
			{
				if (count == 1 && previous->ID == n.ID)
				{
					z.head = current;
					delete previous;
				}
				else if (count < z.count && current->ID == n.ID)
				{
					previous->nxt = current->nxt;
					delete current;
					break;
				}
				else
				{
					previous = previous->nxt;
					current = current->nxt;
				}
			}
		}
	}
	
	z.count--;
}

//	Searches for a node in a list
//		Uses the ID number to identify if a
//		node is in the list
bool search_by_key(list &z, node &n)
{
	bool found = 0;
	
	node *temp = z.head;
	
	while(temp != NULL)
	{
		if (n.ID == temp->ID)
		{
			found = 1;
		}
	
		temp = temp->nxt;
	}
	
	return found;
}

//	Takes input for a node
void node_input(node &n)
{
	//	Prompts user to enter ID number
	cout << "Please enter the ID number: ";
	cin >> n.ID;
	while(!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "You did not enter a number for input" << endl;
		cout << "Please enter the ID number: ";
		cin >> n.ID;
		cout << endl;
	}
	cout << endl;
	
	cin.ignore();
	
	//	Prompts user to enter a name
	cout << "Please enter the name: ";
	getline(cin, n.name);
	cout << endl;
}

//	Takes input for a node
void node_ID(node &n)
{
	//	Prompts user to enter ID number
	cout << "Please enter the ID number: ";
	cin >> n.ID;
	while(!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "You did not enter a number for input" << endl;
		cout << "Please enter the ID number: ";
		cin >> n.ID;
		cout << endl;
	}
	cout << endl;
}

//	Modifies a node
void modify_node(list &z, node &n)
{
	string newname;
	
	node *temp = z.head;
	
	while(temp != NULL)
	{
		if (n.ID == temp->ID)
		{
			cout << "Please enter the new name: ";
			cin >> newname;
			cout << endl;
			
			temp->name = newname;
		}
	
		temp = temp->nxt;
	}
}

//	Outputs the list of nodes
void display_list(list &z)
{
	node *temp = z.head;
	
	do
	{
		if (temp == NULL)
		{
			cout << "Empty List" << endl;
		}
		else
		{
			cout << "-------------------------" << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Name: " << temp->name << endl;
			cout << "-------------------------" << endl;
			
			temp = temp->nxt;
		}
	} while(temp != NULL);
}
