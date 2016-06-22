//	*********************
//	Jiten Bhojwani		*
//	CIS-277				*
//	ADT - Queues		*
//	3/10/16				*
//	*********************

#include <iostream>

using namespace std;

//	InfoRec Type Definition
typedef int INFO_RC;

//	Queue Structure Declaration
struct queue
{
	INFO_RC i[20];
	int back;
};

//	Function Prototypes
void create_queue(queue &);
int empty(queue &);
void enque(queue &,INFO_RC &);
void deque(queue &,INFO_RC &);
void purge(queue &);
void print_queue(queue &);
void menu();

int main()
{
	// Storage for data queue and temporary item
	queue data;
	INFO_RC item;
	
	// Variables to hold choices
	int menuchoice;
	int testchoice;
	
	// Flags to set upon operation completion
	bool DataFlag = 0;
	bool CategoryFlag = 0;
	bool QUIT = 0;
	
	// Initial test data
	int testdata[18] = {3, 22, 12, 6, 10, 34, 65, 29, 9, 30, 81, 4, 5, 19, 20, 57, 44, 99};
	
	while (QUIT == 0)
	{
		//	Welcome message
		cout << "Welcome to the Queues program!" << endl;
		
		//	Output menu to user
		menu();
		
		//	Receive menu choice
		cin >> menuchoice;
		cout << endl;
		
		//	Input Validation
		while (menuchoice < 1 || menuchoice > 8)
		{
			cout << "Invalid input! Please enter a number between 1 and 6" << endl;
    		cin >> menuchoice;
		}
		
		while (menuchoice >= 2 && menuchoice <= 7 && DataFlag == 0)
		{
			cout << "You have not created a queue first!" << endl;
			cout << "Please select menu option 1 to create a queue" << endl;
			menu();
			cin >> menuchoice;
			cout << endl;
		}
		
		switch (menuchoice)
		{
			case 1:
				create_queue(data);
				DataFlag = 1;
				
				cout << "Your data queue was created!" << endl;
				cout << "Would you like to load the test data?" << endl;
				cout << "1.	Yes" << endl;
				cout << "2.	No" << endl;
				cin >> testchoice;
				
				while (testchoice < 1 || testchoice > 2)
				{
					cout << "You entered an invalid option!" << endl;
					cout << "Would you like to load the test data?" << endl;
					cout << "1.	Yes" << endl;
					cout << "2.	No" << endl;
					cin >> testchoice;
				}
				
				switch (testchoice)
				{
					case 1:
						for (int x = 0; x <= 17; x++)
						{
							data.i[x] = testdata[x];
							data.back++;
						}
						break;
					case 2:
						cout << endl;
						break;
				}
				
				break;
			
			case 2:
				cout << "Please enter the number to push onto the queue" << endl << endl;
				cin >> item;
				enque(data, item);
				break;
				
			case 3:
				deque (data, item);
				cout << "The item " << item << " was dequed from the data" << endl;
				break;
				
			case 4:
				if (empty(data))
					cout << "The queue is empty" << endl << endl;
				else
					cout << "The queue is not empty" << endl << endl;
				
				break;
					
			case 5:
				purge(data);
				break;
				
			case 6:
				queue q_1_9;
				queue q_10_19;
				queue q_20_29;
				queue q_30;
				queue temp;
				
				create_queue(q_1_9);
				create_queue(q_10_19);
				create_queue(q_20_29);
				create_queue(q_30);
				
				for (int j = 0; j <= temp.back; j++)
				{
					temp.i[j] = data.i[j];
					temp.back++;
				}
				
				while (temp.back != -1)
				{
					deque(temp,item);
					
					if (item < 10)
					{
						enque(q_1_9, item);
					}
					else if (item >= 10 && item < 20)
					{
						enque(q_10_19, item);
					}
					else if (item >= 20 && item < 30)
					{
						enque(q_20_29, item);
					}
					else if (item >= 30 && item <= 100)
					{
						enque(q_30, item);
					}
					
				}
				
				CategoryFlag = 1;
				break;
				
			case 7:
				
				if (CategoryFlag == 0)
				{
					cout << "Data: ";
					print_queue(data);
					cout << endl;
				}
				else
				{
					cout << "Data: ";
					print_queue(data);
					cout << endl;
					
					cout << "1 to 9: ";
					print_queue(q_1_9);
					cout << endl;
					
					cout << "10 to 19: ";
					print_queue(q_10_19);
					cout << endl;
					
					cout << "20 to 29: ";
					print_queue(q_20_29);
					cout << endl;
					
					cout << "30 or more: ";
					print_queue(q_30);
					cout << endl << endl;
				}
			
					break;
					
			case 8:
				QUIT = 1;
				break;
					
		}
			
	}
}

//	Functions

// Outputs the menu
void menu()
{
	cout << "Please enter the number of the operation you would like to perform" << endl << endl;
	cout << "1.	Create data queue"					<< endl;
	cout <<	"2.	Enque into data"					<< endl;
	cout <<	"3.	Deque from data"					<< endl;
	cout <<	"4.	Check if data queue is empty"		<< endl;
	cout <<	"5.	Purge data queue"					<< endl;
	cout <<	"6.	Categorize data"					<< endl;
	cout << "7.	Print all queues"					<< endl;
	cout << "8.	Quit"								<< endl;
}

//	Creates the queue
void create_queue(queue & q)
{
	q.back = -1;
}

//	Enques into data queue
void enque(queue & q, INFO_RC & item)
{
	q.back++;
	
	if (q.back == 20)
	{
		cout << "Queue overflow! ";
		cout << "The queue is currently full. Please deque first." << endl;
	}
		
	q.i[q.back] = item;
}

//	Deques from data queue
void deque(queue & q, INFO_RC & item)
{
	int ct;
	item = q.i[0];
	
	for (ct = 1; ct <= q.back; ct ++)
	{
		q.i[ct-1] = q.i[ct];
	}
	q.back--;
}

//	Checks if the data queue is empty
int empty(queue & q)
{
	return (q.back == -1);
}

//	Purges the data queue by resetting q.back
void purge(queue & q)
{
	q.back = -1;
}

void print_queue(queue & q)
{
	for (int k = 0; k <= q.back; k++)
	{
		cout << q.i[k] << " ";
	}
}
