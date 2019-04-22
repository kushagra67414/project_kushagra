#include<iostream>
#include<cstring>
#include<conio.h>

using namespace std;

class String
{
protected:
	char str[200];
public:
	String(){}
	String(char* xstr){ strcpy(str, xstr);	}
        void show() { cout << str << endl; }
	char* operator+(String);
	char* operator=(String);
	char *operator+=(String);
        int stringlen();
        int stringsize();
	void tolower();
	void toupper();
};

char* String::operator+(String xstr)
{
	strcat(str, xstr.str);
	return str;
}
char* String::operator+=(String xstr)
{
	strcat(str, xstr.str);
	return str;
}
int String::stringsize()
{
	return (strlen(str) + 1);
}
char* String::operator=(String xstr)
{
	strcpy(str, xstr.str);
	return str;
}
int String::stringlen()
	{
		return strlen(str);
	}


void String::tolower()
{
	for (int i = 0; str[i] != '\0'; i++)
		if (isupper(str[i]))
			str[i] += 32;
}
void String::toupper()
{
	for (int i = 0; str[i] != '\0'; i++)
		if (islower(str[i]))
			str[i] -= 32;
}


int main()
{
	String a = "Hello", b = " World", c;
	
	/*Testing Functions*/

	/*Hello World*/
	c = a + b;
	c.show();
        
	/*HELLO*/
	a.toupper();
	a.show();
	
	/*hello*/
	a.tolower();
	a.show();
	
	/* World */
	a=b;
	a.show();
	
	/*5*/
	cout << a.stringlen() << endl;
       
        /*6*/
	cout << a.stringsize() << endl;

        /*Hello World World*/
	a += b;
	a.show();


	_getch();
	return 0;
}
#include<iostream>
#include<conio.h>
#define FALSE 0
#define TRUE 1
using namespace std;
class linklist
{
private:
	struct node
	{
		int data;
		node* link;
	}*p;
public:
	linklist();
	void append(int num);
	void addatbeg(int num);
	void addafter(int c, int num);
	void del(int num);
	void display();
	
	//To compare two linked list
	int operator==(linklist);
	
	//To copt ylist from one to another.
	void operator=(linklist);
};

linklist::linklist()
{
	p = NULL;
}

void linklist::append(int num)
{
	node *q, *t;
	if (p == NULL)
	{
		p = new node;
		p->data = num;
		p->link = NULL;
	}
	else
	{
		q = p;
		while (q->link != NULL)
			q = q->link;
		t = new node;
		t->data = num;
		t->link = NULL;
	}
}

void linklist::addatbeg(int num)
{
	node *q;
	q = new node;
	q->data = num;
	q->link = p;
	p = q;
}
void linklist::addafter(int c, int num)
{
	node *q, *t; int i;

	for (i = 0, q = p; i < c; i++)
	{
		q = q->link;
		if (q == NULL)
		{
			cout << endl << "There are less than " << c << "elements.";
			return;
		}
	}
	t = new node;
	t->data = num;
	t->link = q->link;
	q->link = t;
}

void linklist::del(int num)
{
	node *q, *r;
	q = p;
	if(q->data == num)
	{
		p = q->link;
		delete q;
		return;
	}

	r = q;
	while (q != NULL)
	{
		if (q->data == num)
		{
			r->link = q->link;
			delete q;
			return;
		}
		r = q;
		q = q->link;
	}
	cout << endl << "Element " << num << " not found.";
}

void linklist::display()
{
	node *q;
	cout << endl;
	for (q = p; q != NULL; q = q->link)
		cout << endl << q->data;
}

void linklist::operator=(linklist t)
{
	p = t.p;
}

int linklist::operator==(linklist t)
{
	int flag = FALSE;
	node *a = p, *b = t.p;
	if (a == NULL && b == NULL)
	{
		flag = TRUE;
		return flag;
	}
	while (a != NULL && b != NULL)
	{
		if (a->data != b->data)
			return flag;
		a = a->link;
		b = b->link;
	}
	flag = TRUE;
	return flag;
}

int main()
{
	linklist a, b;
	a.addatbeg(5);
	a.addatbeg(4);
	a.addatbeg(3);
	
	b = a; //Copying two linked lists.
	cout <<"linked list : b";
	b.display();
	
	if(a == b)//Comparing two linked lists.
		cout << "a and b are quivalent.\n";
	else
		cout <<"a and b are not equivalent.\n";
	
	_getch();
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 

// Declare linked list node 

struct Node { 
	int data; 
	struct Node* link; 
}; 
struct Node* top; 

// Utility function to add an element data in the stack 
// insert at the beginning 
void push(int data) 
{ 
	// create new node temp and allocate memory 
	struct Node* temp; 
	temp = (struct Node*)malloc(sizeof(struct Node)); 

	// check if stack (heap) is full. Then inserting an element would 
	// lead to stack overflow 
	if (!temp) { 
		printf("\nHeap Overflow"); 
		exit(1); 
	} 

	// initialize data into temp data field 
	temp->data = data; 

	// put top pointer reference into temp link 
	temp->link = top; 

	// make temp as top of Stack 
	top = temp; 
} 

// Utility function to check if the stack is empty or not 
int isEmpty() 
{ 
	return top == NULL; 
} 

// Utility function to return top element in a stack 
int peek() 
{ 
	// check for empty stack 
	if (!isEmpty(top)) 
		return top->data; 
	else
		exit(EXIT_FAILURE); 
} 

// Utility function to pop top element from the stack 

void pop() 
{ 
	struct Node* temp; 

	// check for stack underflow 
	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		// top assign into temp 
		temp = top; 

		// assign second node to top 
		top = top->link; 

		// destroy connection between first and second 
		temp->link = NULL; 

		// release memory of top node 
		free(temp); 
	} 
} 
void display() // remove at the beginning 
{ 
	struct Node* temp; 

	// check for stack underflow 
	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL) { 

			// print node data 
			printf("%d->", temp->data); 

			// assign temp link to temp 
			temp = temp->link; 
		} 
	} 
} 

// main function 

int main(void) 
{ 
	// push the elements of stack 
	push(11); 
	push(22); 
	push(33); 
	push(44); 

	// display stack elements 
	display(); 

	// print top elementof stack 
	printf("\nTop element is %d\n", peek()); 

	// delete top elements of stack 
	pop(); 
	pop(); 

	// display stack elements 
	display(); 

	// print top elementof stack 
	printf("\nTop element is %d\n", peek()); 
	return 0; 
} 
#new code

/* Program to implement a stack using  
two queue */
#include<bits/stdc++.h> 
  
using namespace std; 
  
class Stack 
{  
    // Two inbuilt queues 
    queue<int> q1, q2; 
      
    // To maintain current number of 
    // elements 
    int curr_size; 
  
    public: 
    Stack() 
    { 
        curr_size = 0; 
    } 
  
    void push(int x) 
    { 
        curr_size++; 
  
        // Push x first in empty q2 
        q2.push(x); 
  
        // Push all the remaining  
        // elements in q1 to q2.  
        while (!q1.empty()) 
        { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        // swap the names of two queues 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void pop(){ 
  
        // if no elements are there in q1  
        if (q1.empty()) 
            return ; 
        q1.pop(); 
        curr_size--; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
        return q1.front(); 
    } 
  
    int size() 
    { 
        return curr_size; 
    } 
}; 
  
// driver code 
int main() 
{ 
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
  
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
} 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL;

void insert() {
    struct node *temp;
    struct node *nn = (struct  node*)malloc(sizeof(struct node));
    printf("enter  the data\n");
    scanf("%d", &nn->data);
    temp = first;
    while (temp->next != first)
        temp = temp->next;
    temp->next = nn;
    nn->next = NULL;
}

void display() {
    struct node *temp;
    temp = first;
    if (temp == NULL) {
        printf("no elements\n");
        return;
    }
    printf("elements in linked list are\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void deletion() {
    struct node  *temp;
    temp = first;
    first = first->next;
    temp->next = NULL;
    free(temp);
}

int main() {
    int  op;  
    do {
        printf("1.insertion\n2.deletion\n3.display\n4.exit\n");
        printf("enter option\n");
        scanf("%d", &op);
        switch (op) {
          case 1:
             insert();
             break;
          case 2:
             deletion();
             break;
          case 3:
             display(); 
             break;
        }
    } while (op != 6);
}
// left rotation of the array
#include <iostream>
using namespace std;

int main()
{
	int n,d;

	//input value of n and d
	cout<<"Enter the value of n and d"<<endl;
	cin>>n>>d;
	int a[n];

	//input array elements
	cout<<"enter the array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	//print the elements of array after rotation
	cout<<"array elements after rotation : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[(i+d)%n]<<" ";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node{// linked list Node
	int data;
	Node * next;
};

Node *newNode(int k){ //defining new node
	Node *temp = (Node*)malloc(sizeof(Node)); 
	temp->data = k; 
	temp->next = NULL; 
	return temp; 
}

//Used to add new node at the end of the list
Node *addNode(Node* head, int k){
	if(head == NULL){
		head = newNode(k);
	}
	else{
		Node * temp = head;
		Node * node = newNode(k);
		while(temp->next!= NULL){
			temp = temp->next;
		}
		temp-> next = node;
	}

	return head;
}

// Used to create new linked list and return head
Node *createNewLL(){
	int cont = 1;
	int data;
	Node* head = NULL;
	while(cont){
		cout<<"Enter the data of the Node"<<endl;
		cin>>data;
		head = addNode(head,data);
		cout<<"Do you want to continue?(0/1)"<<endl;
		cin>>cont;
	}
	return head;
}

//Function for finding the node
int findNodeInLL(Node* head, int data){
	//Used to keep track of the Node Index
	int index = 0;              
	Node * temp = head;
	//LinkedList traversal for finding the node
	while(temp!=NULL){
		if(temp->data == data){         
			//If element found return index
			return index;               
		}
		temp = temp->next;
		index++;
	}   
	//If element not found
	return -1;                  
}


//Driver Main
int main(){
	Node * head = createNewLL();

	int data;
	cout<<"Enter the data of the linked list to be found."<<endl;
	cin>>data;
	int index = findNodeInLL(head,data);
	cout<<"It is present at "<<index<< endl;

	return 0;
}
