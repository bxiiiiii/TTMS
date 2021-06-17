#include "Play_UI.h"
#include "Play.h"
#include "List.h"
#include <stdio.h>

/*
标识符：TTMS_SCU_Play_UI_MgtEnt
函数功能：显示管理剧目界面
参数说明：无
返回值：无
*/ 
int Play_UI_MgtEntry(void)
{
	int id, num, i, PageNum;
	char choice;
	play_list_t head, pos;
	play_t buf;
	Pagination_t paging;
		
	List_Init(head, play_node_t);
	num = Play_Srv_FetchAll(head);

	List_Paging(head, paging, play_node_t)
	paging.totalRecords = num;
	paging.offset = 0;
	paging.pageSize = 5;
	Paging_Locate_FirstPage(head, paging);
	PageNum = Pageing_TotalPages(paging);
	
	Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
		printf("id:%d\t名称:%d\t类型%d\t出品地区:%s\t等级%d\t时长:%d\t开始放映时间:%d\t结束放映时间:%d\t建议票价:%d\n", pos->data.id, pos->data.name
		, pos->data.type, pos->data.area ,pos->data.rating, pos->data.duration, pos->data.start_date, pos->data.end_date, pos->data.price);
		
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
		if(Pageing_CurPage(paging)>1)
		{
			Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
			Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
				printf("id:%d\t名称:%d\t类型%d\t出品地区:%s\t等级%d\t时长:%d\t开始放映时间:%d\t结束放映时间:%d\t建议票价:%d\n", pos->data.id, pos->data.name
						, pos->data.type, pos->data.area ,pos->data.rating, pos->data.duration, pos->data.start_date, pos->data.end_date, pos->data.price);
		}
		else
			printf("无法跳转\n");
	}else if((choice == 'n') || (choice == 'N'))
	{
		if(Pageing_CurPage(paging)<PageNum)
		{
			Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
			Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
				printf("id:%d\t名称:%d\t类型%d\t出品地区:%s\t等级%d\t时长:%d\t开始放映时间:%d\t结束放映时间:%d\t建议票价:%d\n", pos->data.id, pos->data.name
						, pos->data.type, pos->data.area ,pos->data.rating, pos->data.duration, pos->data.start_date, pos->data.end_date, pos->data.price);
		}
		else
			printf("无法跳转\n");
	}else if((choice == 's') || (choice == 'S'))
	{
		printf("输入剧目id:");
		scanf("%d", &id);
		if(Play_Srv_FetchByID(id, &buf) == 0)
			printf("该剧目id不存在\n");
		else
			Schedule_UI_MgtEntry(id);
	}else if((choice == 'r') || (choice == 'R'))
		return ;

	return ;
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

/*
标识符：TTMS_SCU_Play_UI_Mod
函数功能：修改剧目
参数说明：id为待修改剧目id
返回值；返回1表示成功，否则失败
*/ 
int Play_UI_Modify(int id) 
{
	play_t buf;
	int i;
	char choice;
	
	i = Play_Srv_FetchByID(id, &buf);
	if(i != 1)
	{
		printf("获取信息失败\n");
		return -1;
	}
	
	printf("剧目id: %d\n", buf.id);
	printf("剧目名称： %s\n", buf.name); 
	printf("剧目类型： %s\n", buf.type);
	printf("剧目出品地区 : %s\n", buf.area);
	printf("剧目等级： %s\n", buf.rating);
	printf("剧目时长: %d\n", buf.duration);
	printf("开始放映日期: %d\n", buf.start_date);
	printf("结束放映日期: %d\n", buf.end_date);
	printf("建议票价: %d\n", buf.price);
	
	printf("-----------------------------------------------------------------------\n");
	printf("剧目名称(n/N)\t剧目类型(t/T)\t剧目出品地区(a/A)\t剧目等级(r/R)\n");
	printf("剧目时长(d/D)\t开始放映日期(s/S)\t结束放映日期(e/E)\t建议票价(p/P)\n"); 
	printf("-----------------------------------------------------------------------\n");
	printf("选择需要修改的项:");
	choice = getchar();
	
	if((choice == 'n') || (choice == 'N'))
	{
		printf("输入新的剧目名称:");
		scanf("%s", buf.name);
	}else if((choice == 't') || (choice == 'T'))
	{
		printf("选择新的剧目类型:");
		printf("1.电影\n");
		printf("2.歌剧\n");
		printf("3.音乐会\n");
		scanf("%d", &buf.type);
	}else if((choice == 'a') || (choice == 'A'))
	{
		printf("输入新的剧目出品地区:");
		scanf("%s", buf.area);
	}else if((choice == 'r') || (choice == 'R'))
	{
		printf("选择剧目等级：");
		printf("1.适合儿童\n");
		printf("2.适合青少年\n");
		printf("3.适合成人\n");
		scanf("%d", &buf.rating); 
	}else if((choice == 'd') || (choice == 'D'))
	{
		printf("输入新的时长：");
		scanf("%d", &buf.duration); 
	}else if((choice == 's') || (choice == 'S'))
	{
		printf("输入新的开始放映日期：");
		scanf("%d", &buf.start_date); 
	}else if((choice == 'e') || (choice == 'E'))
	{
		printf("输入新的结束放映日期：");
		scanf("%d", &buf.start_date); 
	}else if((choice == 'p') || (choice == 'P'))
	{
		printf("输入新的票价：");
		scanf("%d", &buf.price); 
	}
	
	return Play_Srv_Modify(&buf);
}

/*
标识符：TTMS_SCU_Play_UI_Del
函数功能：调用 Play_Srv_DelectByID删除剧目
参数说明：id为待删除剧目id
返回值：1表示成功，否则失败
*/ 
int Play_UI_Delect(int id)
{
	return Play_Srv_DelectByID(id);
}

/*
标识符：TTMS_SCU_Play_UI_Qry
函数功能：调用 Play_Srv_FetchByID查询
参数说明：id为待查询剧目id
返回值：1表示成功，否则失败 
*/
int Play_UI_Query(int id)
{
	play_t buf;
	int i = Play_Srv_FetchByID(id, &buf);
	if(i != 1)
		return -1;
		
	printf("剧目id: %d\n", buf.id);
	printf("剧目名称： %s\n", buf.name); 
	printf("剧目类型： %s\n", buf.type);
	printf("剧目出品地区 : %s\n", buf.area);
	printf("剧目等级： %s\n", buf.rating);
	printf("剧目时长: %d\n", buf.duration);
	printf("开始放映日期: %d\n", buf.start_date);
	printf("结束放映日期: %d\n", buf.end_date);
	printf("建议票价: %d\n", buf.price);
	
	return 1;
}