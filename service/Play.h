#ifndef PLAY_H
#define PLAY_H

//标识符：TTMS_SCU_Play_Srv_Add
//函数功能：调用Play_Perst_Insert添加剧目 
int Play_Srv_Add(play_t *data);

//标识符：TTMS_SCU_Play_Srv_FetchAll
//函数功能：调用Play_Perst_SelectAll获取全部剧目信息 
int Play_Srv_FetchAll(Play_list_t list);

#endif PLAY_H