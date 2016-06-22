// Designed by Jiten Bhojwani
// Doubly Dynamic Linked List using Structures

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//	Forward declaration of node struct
struct node;

//	Struct to hold list start pointer
//	and total count of nodes
struct list
{
	int count;
	node *head;
	node *tail;
};

//	Structure for a single node
//	Contains a unique ID number, a name,
//	and a pointer to the next node
struct node
{
	int ID;
	string name;
	node *nxt;
	node *prv;
};


//	Function Prototypes
void create_list(list&);
void add_node(list&, node&, node&);
void delete_node(list&, node&, node&);
void modify_node(list&, node&, node&);
//bool search_by_key(list&, node&);
bool search_by_key(list&, node&, node&);
void middleNodefinder(list&, node&);
void menu();
void node_input(node&);
void node_ID(node&);
void display_list(list&);


//	Main
int main()
{
	int menuchoice;
	node temp;
	node middlenode;
	list z;
	
	bool QUIT = 0;
	bool ListCreateFlag = 0;
	
	cout << "Welcome to the Doubly Linked List program!" << endl;
	
	while (QUIT == 0)
	{
		
		if (ListCreateFlag == 1)
		{
			cout << "Total Number of Nodes: " << z.count << endl;
			if (z.count > 1)
			{
				middleNodefinder(z, middlenode);
			}
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
				//cout << endl << "Input successful" << endl;		//	Debugging statement
				if (z.count > 1)
				{
					//cout << endl << "Middle node finder successful" << endl;	//	Debugging statement
					if (search_by_key(z, temp, middlenode))
					{
						cout << "This ID already exists in the list!" << endl << endl;
					}
					else
					{
						//cout << endl << "Comparison successful" << endl;		//	Debugging statement
						add_node(z, temp, middlenode);
						cout <<"The node with ID number " << temp.ID << " was added to your list.\n" << endl;
					}
				}
				else
				{
					add_node(z, temp, middlenode);
					cout << "The node with ID number " << temp.ID << " was added to your list.\n" << endl;
				}
				
				break;
			case 3:
				node_ID(temp);
				middleNodefinder(z, middlenode);
				if (search_by_key(z, temp, middlenode))
				{
					delete_node(z, temp, middlenode);
					cout << "The node with ID number " << temp.ID << " was deleted from your list." << endl;
				}
				else
				{
					cout << endl << "The ID you input does not exist in your current list!" << endl;
				}
				
				break;
			case 4:
				node_ID(temp);
				middleNodefinder(z, middlenode);
				if (search_by_key(z, temp, middlenode))
				{
					modify_node(z, temp, middlenode);
				}
				else
				{
					cout << endl << "The ID you input does not exist in your current list!" << endl;
				}
				
				break;
			case 5:
				node_ID(temp);
				middleNodefinder(z, middlenode);
				if (search_by_key(z, temp, middlenode))
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
void add_node(list &z, node &n, node &m)
{
	//	Sets up index for Middle Node
	double middleNodeindex;
	
	if (z.count % 2 == 0)
	{
		middleNodeindex = z.count/2;
	}
	else
	{
		middleNodeindex = ceil((double)z.count/2);
	}
	
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
		z.tail = input;
	}
	else
	{
		
		if (z.count == 1)	//	If there is one item on the list
		{
			if (n.ID < current->ID)
			{
				z.head = input;
				input->nxt = current;
				current->prv = input;
				input->prv = NULL;
				z.tail = current;
			}
			else if (n.ID > current->ID)
			{
				current->nxt = input;
				input->nxt = NULL;
				input->prv = current;
				z.tail = input;
			}
		}
		else if (z.count > 1)	//	If there is more than one item on the list
		{
			if (m.ID > n.ID)	//	If the input is less than the middle node
			{
				if (n.ID < current->ID)	//	If the input is less than the first node
				{
					z.head = input;
					input->nxt = current;
					current->prv = input;
					input->prv = NULL;
				}
				else
				{
					current = current->nxt;	//	Advance the current pointer to set up
											//		comparison of input between two
											//		consecutive nodes.
					
					for (int count = 0; count < middleNodeindex; count++)	//	Count corresponds to the position of 'previous'
																	//		in the list
					{
						if (n.ID > previous->ID && n.ID < current->ID)	//	If input is between two consecutive nodes
						{
							input->nxt = current;
							current->prv = input;
							input->prv = previous;
							previous->nxt = input;
							break;
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
			else if (m.ID < n.ID)	//	If the input is greater than the middle node
			{
				current = z.tail;
				previous = z.tail;
				
				if (n.ID > current->ID)
				{
					current->nxt = input;
					input->prv = current;
					input->nxt = NULL;
					z.tail = input;
				}
				else
				{
					current = current->prv;
					
					for (int count = 0; count < middleNodeindex; count++)
					{
						if (n.ID > current->ID && n.ID < previous->ID)
						{
							input->nxt = previous;
							previous->prv = input;
							input->prv = current;
							current->nxt = input;
							break;
						}
						else
						{
							previous = previous->prv;
							current = current->prv;
						}
					}
				}
			}
		}
	}
	
	z.count++;
}

//	Deletes a node
void delete_node(list &z, node &n, node &m)
{
	//	Sets up index for Middle Node
	double middleNodeindex;
	
	if (z.count % 2 == 0)
	{
		middleNodeindex = z.count/2;
	}
	else
	{
		middleNodeindex = ceil((double)z.count/2);
	}
	
	node *current = z.head;	
	node *previous = z.head;
	
	if (z.count == 0)	//	If there are no nodes
	{
		cout << "Your list is already empty!" << endl;
	}
	else if (z.count == 1)	//	If there is one node
	{
		z.head = NULL;
		z.tail = NULL;
		delete current;
	}
	else if (z.count > 1)	//	If there is more than one node
	{
		if (n.ID <= m.ID)	//	If the node we want to delete is towards
							//		the front of the list
		{
			current = current->nxt;
			
			for (int count = 1; count <= middleNodeindex; count++)
			{
				if (count == 1 && previous->ID == n.ID)		//	If we're deleting the first node
				{
					current->prv = NULL;
					z.head = current;
					delete previous;
					break;
				}
				else if (count < z.count && current->ID == n.ID)	//	If we're deleting a node between
																	//		the first and the middle
				{
					previous->nxt = current->nxt;
					(current->nxt)->prv = previous;
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
		else if (n.ID > m.ID)	//	If the node we are trying to delete
								//		is towards the back of the list
		{
			current = z.tail;
			previous = z.tail;
			
			current = current->prv;
			
			for (int count = 1; count <= middleNodeindex; count++)
			{
				if (count == 1 && previous->ID == n.ID)		//	If we're deleting the last node
				{
					current->nxt = NULL;
					z.tail = current;
					delete previous;
					break;
				}
				else if (count < z.count && current->ID == n.ID)	//	If we're trying to delete a node
																	//		in between the middle and last
				{
					previous->prv = current->prv;
					(current->prv)->nxt = previous;
					delete current;
					break;
				}
				else
				{
					previous = previous->prv;
					current = current->prv;
				}
			}
		}
		
	}
	
	z.count--;
}

//	Searches for a node in a list
//		Uses the ID number to identify if a
//		node is in the list
bool search_by_key(list &z, node &n, node &m)
{
	bool found = 0;
	
	node *temp;
	
	//	Sets up index for Middle Node
	double middleNodeindex;
	
	if (z.count % 2 == 0)
	{
		middleNodeindex = z.count/2;
	}
	else
	{
		middleNodeindex = ceil((double)z.count/2);
	}
	
	if (z.count == 1)
	{
		temp = z.head;
		
		if (n.ID == temp->ID)
		{
			found = 1;
		}
	}
	else if (z.count > 1)
	{
		if (m.ID >= n.ID)
		{
			temp = z.head;
			
			for (int count = 0; count < middleNodeindex; count++)
			{
				if (n.ID == temp->ID)
				{
					found = 1;
					break;
				}
				else
				{
					temp = temp->nxt;
				}
			}
		}
		else if ( m.ID < n.ID)
		{
			temp = z.tail;
			
			for (int count = 0; count < middleNodeindex; count++)
			{
				if (n.ID == temp->ID)
				{
					found = 1;
					break;
				}
				else
				{
					temp = temp->prv;	
				}
			}
		}
	}
	
	return found;
}

//	Searches for a middle node in a list
//		Stores the Middle Node's ID number
//		for use in other functions
void middleNodefinder(list &z, node &m)
{
	/* Commented out because it is not as fast as other method
	node *slow_ptr = z.head;
	node *fast_ptr = z.head;
	
	if (z.head!= NULL)
	{
		while (fast_ptr != NULL && fast_ptr->nxt !=NULL)
		{
			fast_ptr = (fast_ptr->nxt)->nxt;
			slow_ptr = slow_ptr->nxt;
		}
		
		m.ID = slow_ptr->ID;
	}
	*/
	
	double middleNodeindex;
	
	if (z.count % 2 == 0)
	{
		middleNodeindex = z.count/2;
	}
	else
	{
		middleNodeindex = ceil((double)z.count/2);
	}
	
	//cout << endl << "Middle Node Index: " << middleNodeindex << endl;		//	Debugging statement
	
	node *temp = z.head;
	
	for (int i=1; i <= middleNodeindex; i++)
	{
		if (i == middleNodeindex)
		{
			m.ID = temp->ID;
		}
		else
		{
			temp = temp->nxt;
		}
	}
	//cout << endl << "Middle Node ID: " << m.ID << endl;		//	Debugging statement
	
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
void modify_node(list &z, node &n, node &m)
{
	string newname;
	
	//	Sets up index for Middle Node
	double middleNodeindex;
	
	if (z.count % 2 == 0)
	{
		middleNodeindex = z.count/2;
	}
	else
	{
		middleNodeindex = ceil((double)z.count/2);
	}
	
	node *temp = z.head;
	
	if (m.ID >= n.ID)
	{
		temp = z.head;
	
		for (int count = 0; count < middleNodeindex; count++)
		{
			if (n.ID == temp->ID)
			{
				cout << "Please enter the new name: ";
				cin >> newname;
				cout << endl;
				
				temp->name = newname;
				break;
			}
			else
			{
				temp = temp->nxt;
			}
		}
	}
	else if ( m.ID < n.ID)
	{
		temp = z.tail;
		
		for (int count = 0; count < middleNodeindex; count++)
		{
			if (n.ID == temp->ID)
			{
				cout << "Please enter the new name: ";
				cin >> newname;
				cout << endl;
				
				temp->name = newname;
				break;
			}
			else
			{
				temp = temp->prv;	
			}			
		}
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
