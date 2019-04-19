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

	char* operator+(String);

	void show() { cout << str << endl; }
	int stringlen();
	
};

char* String::operator+(String xstr)
{
	strcat(str, xstr.str);
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
	
	/*5*/
	cout << a.stringlen() << endl;




	_getch();
	return 0;
}
