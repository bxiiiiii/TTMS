#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include "./View/Main_Menu.h"

//系统运行入口函数main 
int main(void) 
{
	setvbuf(stdout, NULL, _IONBF, 0);
	Start();
	//Main_Menu();
	return EXIT_SUCCESS;
}