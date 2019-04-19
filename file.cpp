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
	int stringlen();
	
};

int String::stringlen()
	{
		return strlen(str);
	}

int main()
{
	String a = "Hello", b = " World", c;
	
	/*Testing Functions*/

	/*5*/
	cout << a.stringlen() << endl;




	_getch();
	return 0;
}
