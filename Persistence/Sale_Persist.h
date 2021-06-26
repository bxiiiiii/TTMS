#ifndef SALE_PERSIST_H_
#define SALE_PERSIST_H_
#include"../Service/Sale.h"
int Sale_Perst_Insert( sale_t *data);


int Ticket_Perst_Update(const ticket_t *data);

int Ticket_Srv_SelBySchID(int id,ticket_list_t list);

int Sale_Perst_SelByTicketID (int ticket_id, sale_t *sale);

int Sale_Perst_SelByID (sale_list_t list, int usrID);

int Select_Price_By_Playid(int id, sale_t *buf);

int Sale_Perst_DeleteByID(int saleID);

int Sale_Perst_SelectByUsrID(sale_list_t list, int usrID, user_date_t curDate, int ice) ;

int Sale_Perst_SelectByUsrID_1(sale_list_t list, int usrID, user_date_t stDate, user_date_t enDate);

#endif