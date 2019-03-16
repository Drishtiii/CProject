#include<stdio.h>
#include<stdlib.h>
#include"rlyres.h"
#include"conio2.h"
int main()
{
    int choice;
    Passenger *ptr;
    int result;
    char *ptrain_no;
    char *pmob_no;
    int *pticket_no;
    int ticket_no,train_no;
    add_trains();
    while(1)
    {
       choice=enterchoice();
       if(choice==9)
       {
        exit(0);
       }
       switch(choice)
       {
       case 1:
           clrscr();
        view_trains();
        getch();
        clrscr();
        break;
       case 2:
           ptr=get_passenger_details();
           clrscr();
           if(ptr!=NULL)
           {
               ticket_no=book_ticket(*ptr);
               if(ticket_no==-1)
               {
                   textcolor(RED);
                   printf("Booking Failed");
               }
               else
               {
                   textcolor(BLUE);
                   printf("Ticket successfully booked\nYour ticket no is %d",ticket_no);
               }
               textcolor(WHITE);
               printf("\n\n\nPress any key to go back to main screen");
               getch();
               clrscr();
           }
              break;
       case 3:
           clrscr();
           ticket_no=accept_ticket_no();
           if(ticket_no!=0)
            view_ticket(ticket_no);
           textcolor(WHITE);
           printf("\nPress any key to go back to the main screen");
           getch();
           clrscr();

        break;
       case 4:
           clrscr();
           pmob_no=accept_mob_no();
           if(pmob_no!=NULL)
           {
               pticket_no=get_ticket_no(pmob_no);
               view_all_tickets(pmob_no,pticket_no);
           }
           getch();
           clrscr();
        break;
       case 5:
           clrscr();
           view_all_bookings();
           getch();
           clrscr();
        break;
       case 6:
            clrscr();
            train_no=accept_train_no();
            if(ticket_no!=0)
                view_bookings(train_no);
            getch();
            clrscr();
            break;
       case 7:
           clrscr();
           ticket_no=accept_ticket_no();
           if(ticket_no!=0)
           {
               result=cancel_ticket(ticket_no);
               if(result==0)
               {
                   textcolor(RED);
                   printf("Sorry!No tickets booked against ticket no %d",ticket_no);
               }
               else if(result==1)
               {
                   textcolor(BLUE);
                   printf("\n\nTicket no %d successfully cancelled!",ticket_no);
               }
               textcolor(WHITE);
               printf("\n\nPress any key to go back to main screen");
           }
           getch();
           clrscr();
        break;
       case 8:
           clrscr();
           ptrain_no=accept_train_no();
           if(ptrain_no!=NULL)
           {
               result=cancel_train(ptrain_no);
               if(result==0)
               {
                   textcolor(LIGHTBLUE);
                   printf("Sorry!No tickets booked in train no %s",ptrain_no);
               }
               else
               {
                   textcolor(BLUE);
                   printf("Train no %s successfully cancelled!",ptrain_no);
               }
               textcolor(YELLOW);
               printf("\n\nPress any key to go back to main screen");
           }
           getch();
           clrscr();
        break;

       default:
           textcolor(RED);
        printf("Wrong Choice! Try Again\n");
        getch();
        clrscr();
    }
}
return 0;
}



























