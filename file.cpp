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


int main()
{
	String a = "Hello", b = " World", c;
	
	/*Testing Functions*/

	/*Hello World*/
	c = a + b;
	c.show();
	
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
