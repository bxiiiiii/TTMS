/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: Main_Menu.c			 	 
* Description : TTMS 系统主菜单	
* Author:   XUPT  		 
* Version:  v.1 	 
* Da
*/

#include "Main_Menu.h"

#include <stdio.h>

#include "Studio_UI.h"

#include "Sale_UI.h"

#include "SalesAnalysis_UI.h"

#include "Returnticket_UI.h"
#include "Account_UI.h"
//系统主菜单 
void Main_Menu_Adinm(void)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    color(10); printf("                                              河西村剧院\n\n\n");
    color(12); printf("                                              管理演出厅\n");
    color(7);  printf("                                              管理账户\n");
    color(7);  printf("                                              退出\n");
    int ch, a = 1;
    while (1)
    {
        ch = getch();
        system("cls");
        if (ch == 80)
            a++;
        if (a > 3) a = 3;
        if (ch == 72)
            a--;
        if (a < 1) a = 1;
        printf("\n\n\n\n\n\n\n\n");
        color(10); printf("                                              河西村剧院\n\n");
        if (a == 1)
        {
            color(12); printf("                                               管理演出厅\n");
        }
        else
        {
            color(7);  printf("                                               管理演出厅\n");
        }
        if (a == 2) {
            color(12); printf("                                               管理账户\n");
        }
        else
        {
            color(7);  printf("                                               管理账户\n");
        }
        
        if (a == 3)
        {
            color(12); printf("                                               退出\n");
        }
        else
        {
            color(7);  printf("                                               退出\n");
        }
        if (ch == 13)
        {
            if (a == 1)
            {
                Studio_UI_MgtEntry();
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                              河西村剧院\n\n");
                color(12); printf("                                              管理演出厅\n");
                color(7);  printf("                                              管理账户\n");
                color(7);  printf("                                              退出\n");
            }
            if (a == 2)
            {
                Account_UI_MgtEntry();
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                              河西村剧院\n");
                color(7);  printf("                                              管理演出厅\n");
                color(12); printf("                                              管理账户\n");
                color(7);  printf("                                              退出\n");
            }
            if (a == 3)
            {
                
                system("cls");
				    printf("\n\n\n\n\n\n\n\n");
				    color(10); printf("                                            河西村剧院\n\n");
				    color(12); printf("                                               登录\n");
				    color(7);  printf("                                               退出\n");
				    return;
            }
        }
        if (ch == 27)
        {
        	system("cls");
			    printf("\n\n\n\n\n\n\n\n");
			    color(10); printf("                                            河西村剧院\n\n");
			    color(12); printf("                                               登录\n");
			    color(7);  printf("                                               退出\n");
            return;
        }
    }
}
void Main_Menu_manger(void)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    color(10); printf("                                            河西村剧院\n\n");
    color(12); printf("                                               管理剧目\n");
    color(7);  printf("                                               查询\n");
    color(7);  printf("                                               统计票房\n");
    color(7);  printf("                                               统计销售额\n");
    color(7);  printf("                                               退出\n");
    int ch, a = 1;
    while (1)
    {
        ch = getch();
        system("cls");
        if (ch == 80)
            a++;
        if (a > 5) a = 5;
        if (ch == 72)
            a--;
        if (a < 1) a = 1;
        printf("\n\n\n\n\n\n\n\n");
        color(10); printf("                                            河西村剧院\n\n");
        if (a == 1)
        {
            color(12); printf("                                               管理剧目\n");
        }
        else
        {
            color(7);  printf("                                               管理剧目\n");
        }
        if (a == 2) {
            color(12); printf("                                               查询\n");
        }
        else
        {
            color(7);  printf("                                               查询\n");
        }
        if (a == 3)
        {
            color(12); printf("                                               统计票房\n");
        }
        else
        {
            color(7);  printf("                                               统计票房\n");
        }
        if (a == 4)
        {
            color(12); printf("                                               统计销售额\n");
        }
        else
        {
            color(7);  printf("                                               统计销售额\n");
        }
        if (a == 5)
        {
            color(12); printf("                                               退出\n");
        }
        else
        {
            color(7);  printf("                                               退出\n");
        }
        if (ch == 13)
        {
            if (a == 1)
            {
                Play_UI_MgtEntry(0);
                system("cls");
				    printf("\n\n\n\n\n\n\n\n");
				    color(10); printf("                                            河西村剧院\n\n");
				    color(12); printf("                                               管理剧目\n");
				    color(7); printf("                                               查询\n");
				    color(7); printf("                                               统计票房\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 2)
            {
                Queries_Menu();
                system("cls");
				    printf("\n\n\n\n\n\n\n\n");
				    color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               管理剧目\n");
				    color(12); printf("                                               查询\n");
				    color(7); printf("                                               统计票房\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 3)
            {
                SalesAnalysis_UI_MgtEntry();
                system("cls");
				    printf("\n\n\n\n\n\n\n\n");
				    color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               管理剧目\n");
				    color(7); printf("                                               查询\n");
				    color(12); printf("                                               统计票房\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 4)
            {
                StaSales_UI_MgtEntry();
                system("cls");
				    printf("\n\n\n\n\n\n\n\n");
				    color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               管理剧目\n");
				    color(7); printf("                                               查询\n");
				    color(7); printf("                                               统计票房\n");
				    color(12); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 5)
            {
            	system("cls");
				printf("\n\n\n\n\n\n\n\n");
				color(10); printf("                                            河西村剧院\n\n");
				color(12); printf("                                               登录\n");
				color(7);  printf("                                               退出\n");
                return;
            }
        }
        if (ch == 27)
        {
        	system("cls");
			    printf("\n\n\n\n\n\n\n\n");
			    color(10); printf("                                            河西村剧院\n\n");
			    color(12); printf("                                               登录\n");
			    color(7); printf("                                               退出\n");
            return;
            
        }
    }
}
void Main_Menu_Sale(void)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    color(10); printf("                                            河西村剧院\n\n");
    color(12); printf("                                               售票\n");
    color(7); printf("                                               退票\n");
    color(7); printf("                                               查询\n");
    color(7); printf("                                               统计销售额\n");
    color(7); printf("                                               退出\n");
    int ch, a = 1;
    while (1)
    {
        ch = getch();
        system("cls");
        if (ch == 80)
            a++;
        if (a > 5) a = 5;
        if (ch == 72)
            a--;
        if (a < 1) a = 1;
        printf("\n\n\n\n\n\n\n\n");
        color(10); printf("                                            河西村剧院\n\n");
        if (a == 1)
        {
            color(12); printf("                                               售票\n");
        }
        else
        {
            color(7); printf("                                               售票\n");
        }
        if (a == 2) {
            color(12); printf("                                               退票\n");
        }
        else
        {
            color(7); printf("                                               退票\n");
        }
        if (a == 3)
        {
            color(12); printf("                                               查询\n");
        }
        else
        {
            color(7); printf("                                               查询\n");
        }
        if (a == 4)
        {
            color(12); printf("                                               统计销售额\n");
        }
        else
        {
            color(7); printf("                                               统计销售额\n");
        }
        if (a == 5)
        {
            color(12); printf("                                               退出\n");
        }
        else
        {
            color(7); printf("                                               退出\n");
        }
        if (ch == 13)
        {
            if (a == 1)
            {
                Sale_UI_MgtEntry();
                system("cls");printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                            河西村剧院\n\n");
				    color(12); printf("                                               售票\n");
				    color(7); printf("                                               退票\n");
				    color(7); printf("                                               查询\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 2)
            {
                Sale_UI_RetfundTicket();
                 system("cls");printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               售票\n");
				    color(12); printf("                                               退票\n");
				    color(7); printf("                                               查询\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 3)
            {
                Queries_Menu();
                 system("cls");printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               售票\n");
				    color(7); printf("                                               退票\n");
				    color(12); printf("                                               查询\n");
				    color(7); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 4)
            {
                StaSales_UI_MgtEntry();
                 system("cls");printf("\n\n\n\n\n\n\n\n");
                color(10); printf("                                            河西村剧院\n\n");
				    color(7); printf("                                               售票\n");
				    color(7); printf("                                               退票\n");
				    color(7); printf("                                               查询\n");
				    color(12); printf("                                               统计销售额\n");
				    color(7); printf("                                               退出\n");
            }
            if (a == 5)
            {
            	system("cls");
				printf("\n\n\n\n\n\n\n\n");
				color(10); printf("                                            河西村剧院\n\n");
				color(12); printf("                                               登录\n");
				color(7);  printf("                                               退出\n");
                return;
            }
        }
        if (ch == 27)
        {
        	system("cls");
			    printf("\n\n\n\n\n\n\n\n");
			    color(10); printf("                                            河西村剧院\n\n");
			    color(12); printf("                                               登录\n");
			    color(7); printf("                                               退出\n");
            return;
        }
    }
}


void Queries_Menu()
{
	system("cls");
	printf("=====================================\n");
	printf("1.查询演出\n");
	printf("2.查询演出票\n");
	printf("3.退出\n");
	printf("=====================================\n");
	printf("请输入你的选择：");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:Schedule_UI_ListAll();
			break;
		case 2:Ticket_UI_Query();
			break;
		case 3:return ;
		default :
			printf("输入有误\n");
			system("pause");
	}
}