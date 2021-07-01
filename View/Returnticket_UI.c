#include <stdio.h>
#include "Ticket_UI.h"
#include "../Service/Sale.h"
#include "Sale_UI.h"

void Sale_UI_RetfundTicket()
{
	int ticket_id;
	int user_id;
	ticket_t tt;
	sale_t refound;
	printf("请输入票的ID：");
	scanf("%d", &ticket_id);
	
	if(Ticket_Srv_FetchByticketID(ticket_id, &tt) != 1)
	{
		printf("无此票\n");
		return ;
	}
	
	if(tt.status == 0)
	{
		printf("该票未售出\n");
		return ;
	}
	
	printf("请输入售票员的ID：");
	scanf("%d", &user_id);
	
	tt.status = 0; 
	Ticket_Srv_Modify(&tt);
	
	refound.ticket_id = ticket_id;
	refound.user_id =user_id ;
	refound.date = DateNow();
	refound.time = TimeNow();
	refound.value = -tt.price;
	refound.type = -1;
	printf("退票成功\n");
	printf("按任意键继续....");
	fflush(stdin);
	getchar();
	Sale_Srv_Add(&refound);	
}