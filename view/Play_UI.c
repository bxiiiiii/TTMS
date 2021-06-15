#include "Play_UI.h"
#include <stdio.h>

/*
标识符：TTMS_SCU_Play_UI_MgtEnt
函数功能：显示管理剧目界面
参数说明：无
返回值：无
*/ 
int Play_UI_MgtEntry(void)
{
	int id;
	char choice;
	play_list_t head;
		
	List_Init(head, play_list_t);
	Play_Src_FetchAll(head);
	
	while(1)
	{	
		printf("-----------------------\n");
		printf("1.显示上一页(p/P)\n");
		printf("2.显示下一页(n/N)\n");
		printf("3.添加新剧目(a/A)\n");
		printf("4.修改剧目(u/U)\n");
		printf("5.删除剧目(d/D)\n");
		printf("6.查询剧目并安排演出(s/S)\n");
		printf("7.退出(r/R)\n");
		printf("------------------------\n");
		printf("输入相应字母："); 
		choice = getchar();
		
		if((choice == 'a') || (choice == 'A'))
			Play_UI_Add();
		else if((choice == 'u') || (choice == 'U'))
		{
			printf("输入剧目id:");
			scanf("%d", &id);
			Play_UI_Modify(id);
		}else if((choice == 'd') || (choice == 'D'))
		{
			printf("输入剧目id:");
			scanf("%d", &id);
			Play_UI_Delect(id);
		}else if((choice == 'p') || (choice == 'P'))
		{
		/*	if(page < 1)
				break;
			Paging_Locate_OffsetPage();*/
		}else if((choice == 'n') || (choice == 'N'))
		{
		/*	if(page < 1)
				break;
			Paging_Locate_OffsetPage();*/
		}else if((choice == 's') || (choice == 'S'))
		{
			printf("输入剧目id:");
			scanf("%d", &id);
			Schedule_UI_MgtEntry(id);
		}else if((choice == 'r') || (choice == 'R'))
			break;
		else{
			printf("请输入正确内容!\n");
		}
	}
}

/*
标识符：TTMS_SCU_Play_UI_Add
函数功能：显示添加新剧目界面
参数说明：无
返回值：返回值>0表示添加成功， 为0表示添加失败
*/ 
int Play_UI_Add(void)
{
	char choice;
	play_t data;
	int newCount = 0, i;
	
	while(1)
	{
		printf("输入剧目名称：");
		scanf("%s", data.name);
		printf("选择剧目类型：");
		printf("1.电影\n");
		printf("2.歌剧\n");
		printf("2.音乐会\n");
		scanf("%d", &data.type);
		printf("输入剧目出品地区:");
		scanf("%s", data.area);
		printf("选择剧目等级：");
		printf("1.适合儿童\n");
		printf("2.适合青少年\n");
		printf("3.适合成人\n");
		scanf("%d", &data.rating); 
		
		i = Play_Srv_Add(&data); 
		if(i == 1)
		{
			newCount++;
			printf("添加成功\n");
		}
		else
			printf("添加失败\n");
		
		while(1)
		{
			printf("----------------------\n");
			printf("1.继续添加(a/A)\n");
			printf("2.返回(r/R)\n");
			printf("----------------------\n");
			printf("输入相应字母:");
			choice = getchar();
			
			if((choice == 'a') || (choice == 'A'))
				break;
			else if((choice == 'r') || (choice == 'R'))
				return newCount;
			else
				printf("请输入正确内容!\n");
		}
	}
}