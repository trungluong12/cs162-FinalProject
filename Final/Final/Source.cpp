#include "Final.h"
#include"console.h"

void Login()
{
	SetWindowSize(100, 50);
	SetScreenBufferSize(100, 50);


	for (int i = 27; i <= 64; i++)
	{
		gotoXY(i, 17);  putchar('*'); 
		gotoXY(i, 25);  putchar('*'); 
	}
	for (int i = 18; i <= 24; i++)
	{
		gotoXY(26, i); putchar('*');
		gotoXY(65, i); putchar('*');
	}


	gotoXY(30, 20);
	cout << "ID          :" << endl;
	gotoXY(30, 23);
	cout << "PASSWORD    :" << endl;
	while(1)
	{
		
	}
}