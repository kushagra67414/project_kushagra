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
