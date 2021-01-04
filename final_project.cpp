/*
My Name: Ahmed Khalid Abdelrahman Hassan
Class: Second Year
Department: Computer Engineering
*/

#include<iostream> // input and output library
#include<fstream> // file management library
#include<string> // string library

using namespace std; // standard line analyze
ofstream myFile; // to output from the program to the file

class Node{ // A linked list node
	public:
		string data; // defining the data as a string
		Node *next;
};
void append(Node** head_ref, string new_data) // the append element function
{ 
	// allocate node
	Node* new_node = new Node(); 

	Node *last = *head_ref; // used in step 5

	// put in the data
	new_node->data = new_data; 

	// This new node is going to be the last node, so make next of it as NULL
	new_node->next = NULL; 

	// If the Linked List is empty, then make the new node as head
	
	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node; 
		return; 
	} 

	// Else traverse till the last node
	while (last->next != NULL) 
		last = last->next; 

	// Change the next of last node
	last->next = new_node; 
	return; 
}
void deleteNode(Node** head_ref, string key) 
{
	// Store head node 
	Node* temp = *head_ref; 
	Node* prev = NULL; 
	// If head node itself holds 
	// the key to be deleted 
	if (temp != NULL && temp->data == key) 
	{ 
		*head_ref = temp->next; // Changed head 
		delete temp;		 // free old head 
		return; 
	} 
	// Else Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
	while (temp != NULL && temp->data != key) 
	{ 
		prev = temp; 
		temp = temp->next; 
	}
	// If key was not present in linked list 
	if (temp == NULL) 
		return;
	// Unlink the node from linked list 
	prev->next = temp->next;
	// Free memory 
	delete temp; 
}
printList(Node *node) // This function prints contents of linked list starting from head
{
    while (node!=NULL)
    {
        myFile<<node->data<<"\t"; // adds the data directly to the file
        node=node->next;
    }
}
// Delete n-th line from given file 
void delete_line(const char *file_name, int n) 
{ 
    // open file in read mode or in mode 
    ifstream is(file_name); 
  
    // open file in write mode or out mode 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
  
    // loop getting single characters 
    char c; 
    int line_no = 1; 
    while (is.get(c)) 
    { 
        // if a newline character 
        if (c == '\n') 
        line_no++; 
  
        // file content not to be deleted 
        if (line_no != n) 
            ofs << c; 
    } 
  
    // closing output file 
    ofs.close(); 
  
    // closing input file 
    is.close(); 
  
    // remove the original file 
    remove(file_name); 
  
    // rename the file 
    rename("temp.txt", file_name); 
}
	 
main() // the main function
{	// Start with the empty list
	Node* head = NULL; // defining the linked list in this scope
	myFile.open("Contacts.csv"); // creating the csv file
	// printing the header into the first row the csv file 
	myFile<<"No.\tName\tGiven Name\tAdditional Name\tFamily Name\tYomi Name\tGiven Name Yomi\tAdditional Name Yomi\tFamily Name Yomi\tName Prefix\tName Suffix\tInitials\tNickname\tShort Name\tMaiden Name\tBirthday\tGender\tLocation\tBilling Information\tDirectory Server\tMileage\tOccupation\tHobby\tSensitivity\tPriority\tSubject\tNotes\tLanguage\tGroup Membership\tE-mail 1 - Type\tE-mail 1 - Value\tE-mail 2 - Type\tE-mail 2 - Value\tPhone 1 - Type\tPhone 1 - Value\tPhone 2 - Type\tPhone 2 - Value\tPhone 3 - Type\tPhone 3 - Value\tPhone 4 - Type\tPhone 4 - Value\tOrganization 1 - Type\tOrganization 1 - Name\tOrganization 1 - Yomi Name\tOrganization 1 - Title\tOrganization 1 - Department\tOrganization 1 - Symbol\tOrganization 1 - Location\tOrganization 1 - Job Description\tWebsite 1 - Type\tWebsite 1 - Value"<<endl;
	string a, con, con2; // the linked list element n, the condition strings con and con2
	int n; // the line number integer
	
	for(int i=1;i>=1;i++) // for loop to add the contact's content
	{
		myFile<<i<<"\t"; // printing i as a contact number into the file
		cout<<"Contact No."<<i<<endl; // showing the contact number
		
		// inserting the contact's content using getline for the string a
		// then appending the element to the file and delete it to prevent memory overuse
		cout<<"Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Given Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Additional Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Family Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Yomi Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Given Name Yomi: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Additional Name Yomi: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Family Name Yomi: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Name Prefix: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Name Suffix: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Initials: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Nickname: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Short Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Maiden Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Birthday: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Gender: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Location: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Billing Information: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Directory Server: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Mileage: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Occupation: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Hobby: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Sensitivity: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Priority: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Subject: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Notes: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Language: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Group Membership: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"E-mail 1 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"E-mail 1 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"E-mail 2 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"E-mail 2 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 1 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 1 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 2 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 2 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 3 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 3 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 4 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Phone 4 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Yomi Name: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Title: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Department: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Symbol: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Location: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Organization 1 - Job Description: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Website 1 - Type: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		cout<<"Website 1 - Value: ";getline(cin, a);append(&head, a);printList(head);deleteNode(&head, a);
		
		myFile<<endl; // print new line into the file
		cout<<"\n--------------------------------\n";
		cout<<"Do you want to add another contact? (y/n) ";cin>>con; // enter "y" to continue or "n" to exit
		if (con=="n")
		break; // printing "n" breaks the loop
		cout<<"--------------------------------\n";
		getline(cin, a);
	}
	
	myFile.close(); // closing the file minimize the memory usage
	
	for(int ii=1;ii>=1;ii++) // for loop to control the delete operation
	{
		cout<<"Do you want to delete a contact? (y/n) ";cin>>con2; // enter "y" to continue or "n" to exit
		if (con2=="n")
		break; // printing "n" breaks the loop
		cout<<"Enter the contact no. you want to delete: ";cin>>n; // "n" is the line number
		n=n+1; // adding 1 to skip the header in the file
		delete_line("Contacts.csv", n); // deletes the whole line (the contact)
	}
	return 0; // all the values will return to 0
}
