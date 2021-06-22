//统计票房界面 

#include "SalesAnalysis_UI.h"
#include "../Common/list.h"
#include "../Common/common.h"
#include "../Service/SalesAnalysis.h"
#include <conio.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

//外部变量gl_CurUser 用于存储登录用户信息
extern account_t gl_CurUser;

//定义分页机制中页面大小为5
static const int SALESANALYSIS_PAGE_SIZE = 5;

//剧院销售排行榜函数,降序显示截止目前剧院电影票房排行榜

void SalesAnalysis_UI_MgtEntry() {
	int i;
	char choice;

	salesanalysis_list_t head;
	salesanalysis_node_t *pos;
	Pagination_t paging;

	List_Init(head, salesanalysis_node_t);
	paging.offset = 0;
	paging.pageSize = 5;

	//载入数据
	paging.totalRecords = SalesAnalysis_Srv_StaticSale(head);
	//if(head == NULL)
	//{
	//	printf("HHHH\n");
	//} 
	//else
	//{
	//	printf("YYY\n"); 
	//}
	//SalesAnalysis_Srv_SortBySale(head);   //根据票房排序

	Paging_Locate_FirstPage(head, paging);
	do{
		system("cls"); 
		printf("=========================================================================\n");
		printf("================================票房图表=================================\n");
		printf("-------------------------------------------------------------------------\n");
		printf("剧目名\t\t出品地区\t售票数\t票房\t上映时间\t下映时间\n");

		Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
		{
			//printf("AAA\n");
			printf("%-10s\t%-10s\t%-5ld\t%-5ld\t%d-%d-%d\t%d-%d-%d\t\n",
					pos->data.name, pos->data.area, pos->data.totaltickets,pos->data.sales,
					pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day,
					pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day);
		}
		printf("--------------- 共 %2d 项 --------------------------- 第 %2d/%2d 页 --------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("*************************************************************************\n");
		printf("[P]上一页	|	[N]下一页	|	[R]返回\n");
		printf("=========================================================================\n");
		fflush(stdin);
		printf("请选择功能：");
		scanf("%c",&choice);

		switch(choice)
		{
			case 'P':
			case 'p':
					if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, salesanalysis_node_t);
					}
				break;
			case 'N':
			case 'n':
					if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, salesanalysis_node_t);
					}
				break;
		}
	} while(choice!='R' && choice!='r');
		List_Destroy(head, salesanalysis_node_t);
}