#ifndef PLAY_UI_H
#define PLAY_UI_H

typedef enum{
	PLAY_TYPE_FILM = 1,		//电影 
	PLAY_TYPE_OPEAR = 2,	//歌剧 
	PLAY_TYPE_CONCERT = 3	//音乐会 
}play_type_t;

typedef enum{
	PLAY_RATE_CHILD = 1,	//适合儿童 
	PLAY_RATE_TEENAGE = 2,	//适合青少年 
	PLAY_RATE_ADULT = 3		//适合成人 
}play_rating_t;

typedef struct {
	int year;
	int month;
	int day;
}ttms_date_t;

typedef struct {
	int id;					//剧目ID 
	char name[31];			//剧目名称 
	play_type_t type;		//剧目类型 
	char area[9];			//剧目出品地区 
	play_rating_t rating;	//剧目等级 
	int duration;			//剧目时长 
	ttms_date_t start_date;	//开始放映日期 
	ttms_date_t end_date;	//放映结束日期 
	int price;				//建议票价 
}play_t;

typedef struct play_node{
	play_t data;
	struct play_node *next;
	struct play_node *prev;
}play_node_t, *play_list_t;


//标识符：TTMS_SCU_Play_UI_MgtEnt
//函数功能：显示管理剧目界面
int Play_UI_MgtEntry(void);


//标识符：TTMS_SCU_Play_UI_Add
//函数功能：显示添加新剧目界面 
int Play_UI_Add(void);
#endif PLAY_UI_H