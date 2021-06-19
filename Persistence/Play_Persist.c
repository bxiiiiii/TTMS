#include "Play_Persist.h"
#include "../Service/Play.h"
#include "../Common/List.h"
#include <stdio.h>
#include <stdlib.h>

/*
标识符：TTMS_SCU_Play_Perst_SelAll
函数功能：从文件Play.dat中载入所有剧目信息，加载到链表list上
参数说明：list为play_list_t类型指针，表示记录所有剧目信息的链表头指针
返回值：返回值>0表示载入剧目数量， 为-1表示失败
*/
int Play_Perst_SelectAll(play_list_t list)
{
    FILE *fp;
    play_t data;
    int recCount = 0;
     
    fp = fopen("Play.dat", "rb");
    if(fp == NULL)
    {
        printf("文件Play.dat 不存在\n");
        return -1;
    }
     
    while(!feof(fp))
    {
        if(fread(&data, sizeof(play_t), 1, fp))
        {
        	play_list_t newNode = (play_list_t) malloc (sizeof(play_node_t));
	        newNode->data = data;
	        List_AddTail(list, newNode);
	        recCount++; 
    	}
    }
     
    fclose(fp);
    return recCount;
} 
 
/*
标识符：TTMS_SCU_Play_Perst_Insert
函数功能：向剧目数据文件Play.dat的末尾添加一条新的剧目信息
参数说明：data为play_t类型指针，表示待存储的剧目信息
返回值：整型，返回1表示存储剧目成功，否则存储剧目失败 
*/
int Play_Perst_Insert(play_t *data)
{
    FILE *fp;
    int rtn;
     
    data->id = EntKey_Perst_GetNewKeys("Play", 1);
    if(data->id == 0)
    {
        printf("获取主键失败\n");
        return -1;
    }
     
    fp = fopen("Play.dat", "ab");
    if(fp == NULL)
    {
        printf("打开文件Play.dat失败\n");
        return -1;
    }
    
    rtn = fwrite(data, sizeof(play_t), 1, fp);
    fclose(fp);
     
    return 1;
}
 
/*
标识符：TTMS_SCU_Play_Perst_Update
函数功能：更新文件play.dat中的一条剧目信息
参数说明：data为play_t类型指针，表示待存储的剧目信息
返回值：返回1表示更新剧目成功，否则表示失败
*/
int Play_Perst_Update(const play_t *data)
{
    FILE *fp;
    play_t buf;
    int found = 0;
     
    fp = fopen("Play.dat", "rb+");
    if(fp == NULL)
    {
        printf("文件Play.dat 不存在\n");
        return found;
    }
     
    while(!feof(fp))
    {
        if(fread(&buf, sizeof(buf), 1, fp))
        {
        	if(buf.id == data->id)
	        {
	            fseek(fp, -sizeof(play_t), SEEK_CUR);
	            fwrite(data, sizeof(data), 1, fp);
	            found = 1;
	            break;
	        }
		}
    }
    fclose(fp);
     
    return found;
}
 
/*
标识符：TTMS_SCU_Play_Perst_RemByID
函数功能：删除Play.dat中指定ID的剧目信息
参数说明: id为待删除剧目id
返回值：返回1b=表示成功，否则失败
*/
int Play_Perst_RemByID(int id)
{
    FILE *fp1;
    FILE *fp2;
    play_t buf;
    
    rename("Play.dat", "PlayTmp.dat");
    
    fp1 = fopen("PlayTmp.dat", "rb");
    fp2 = fopen("Play.dat", "wb");
    if(fp1 == NULL)
    {
        printf("文件Play.dat打开失败\n");
        return -1;
    }
     
    while(!feof(fp1))
    {
        if(fread(&buf, sizeof(play_t), 1, fp1))
        {
        	if(buf.id != id)
            	fwrite(&buf, sizeof(play_t), 1, fp2);
		}
    }
    
    fclose(fp1);
    fclose(fp2);
   
    remove("playTmp.dat");
    
    return 1;
}
 
/*
标识符；TTMS_SCU_Play_Perst_SelByID
函数功能：在文件Play.dat中载入指定id的信息加载到buf中
参数说明：id为载入剧目id,buf存放id的信息
返回值: 1表示成功，否则失败
*/
int Play_Perst_SelectByID(int id, play_t *buf)
{
    FILE *fp;
    play_t data;
     
    fp = fopen("Play.dat", "rb");
    if(fp == NULL)
    {
        printf("文件Play.dat打开失败\n");
        return -1;
    }
     
    while(!feof(fp))
    {
        if(fread(&data, sizeof(play_t), 1, fp))
        {
        	if(id == data.id)
	        {
	            *buf = data;
	            return 1;
	        }
		}
    }
    fclose(fp);
    return 0;
}