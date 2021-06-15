#include "Play.h"

/*
标识符：TTMS_SCU_Play_Srv_Add
函数功能：调用Play_Perst_Insert添加剧目
参数说明：data为play_t类型指针，表示待存储的剧目信息
返回值：整型，返回1表示添加成功，否则表示失败
*/ 
int Play_Srv_Add(play_t *data)
{
	int i = Play_Perst_Insert(data)；
	if(i == 1)
		return 1;
	else
		return -1;
}

/*
标识符：TTMS_SCU_Play_Srv_FetchAll
函数功能：调用Play_Perst_SelectAll获取全部剧目信息
参数说明：list为play_list_t类型指针，表示记录所有剧目信息的链表头指针
返回值：返回值>0表示载入剧目数量， 为0表示失败
*/ 
int Play_Srv_FetchAll(Play_list_t list)
{
	return Play_Perst_SelectAll(list);	
}