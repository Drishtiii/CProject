#include<stdio.h>
#include"rlyres.h"
#include"conio2.h"
#include<ctype.h>
#include<string.h>
int enterchoice()
{
    int choice,i;
    gotoxy(28,1);
    textcolor(YELLOW);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<=77;i++)
    {
        printf("-");
    }

    printf("\nSelect an option\n");
    printf("1.View Train\n2.Book Ticket\n3.View Ticket\n4.Search Ticket No\n5.View All Bookings\n6.View Train Bookings\n7.Cancel Ticket\n8.Cancel Train\n9.Quit\n\n ");

    printf("\nEnter choice:");
    scanf("%d",&choice);
    return (choice);
}
void add_trains()

{
    FILE *fp;
    fp=fopen("d:\\My Project\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360},
    };
    fp=fopen("d:\\My Project\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(Train),1,fp);
    fclose(fp);
}
else
{
    fclose(fp);
}

}
void view_trains()
{
    clrscr();
    FILE *fp;
    Train T;
   int i;
   textcolor(YELLOW);
   printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
   for(i=0;i<=77;i++)
    {
        printf("-");

    }
    printf("\n");
    fp=fopen("d:\\My Project\\alltrains.dat","rb");
    while(fread(&T,sizeof(T),1,fp)==1)
    {
        printf("%s\t\t%s\t%s\t%d\t\t%d\n",T.train_no,T.from,T.to,T.fac_fare,T.sac_fare);
    }
    textcolor(WHITE);
    printf("\n\n\nPress any key to back to main screen.");
    getch();
    fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp;
    Train tr;
    fp=fopen("d:\\My Project\\alltrains.dat","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {

       if(strcmp(tr.train_no,trainno)==0)
       {
           fclose(fp);
           return 1;
       }
    }
    fclose(fp);
    return 0;
}
Passenger* get_passenger_details()
{
    clrscr();
    gotoxy(64,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(RED);
        gotoxy(1,25);
        printf("Reservation Cancelled!");
        getch();
        textcolor(RED);
        return NULL;
    }
    int valid;
    textcolor(YELLOW);
    printf("Enter gender M/F:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
        textcolor(RED);
        gotoxy(1,25);
        printf("Error! Gender should be M or F (in uppercase)");
        valid=0;
        getch();
        gotoxy(18,2);
        printf(" \b");
        textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,3);
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {
            textcolor(RED);
            gotoxy(1,25);
            textcolor(RED);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
       valid=check_train_no(psn.train_no);
       if(valid==0)
       {
          textcolor(RED);
            gotoxy(1,25);
            printf("Error!Invalid Train No ");
            getch();
            textcolor(YELLOW);
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);
       }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(First AC-F,Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(RED);
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("Error!Travelling class should be F or S(in uppercase)");
            valid=0;
            getch();
            gotoxy(48,4);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter Address:");
    fflush(stdin);
    fgets(psn.address,20,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(RED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter age:");
      do
    {
        valid=1;
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(RED);
            return NULL;
        }
        if(psn.age<=0)
        {
        textcolor(RED);
        gotoxy(1,25);
        printf("Error!Age should be positive");
        valid=0;
        getch();
        gotoxy(11,6);
        printf("\t\t\t\t\t\t");
        gotoxy(11,6);
        textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter mobile number:");
    do
    {
        fflush(stdin);
        fgets(psn.mob_no,11,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
          *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(RED);
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("Error!Invalid mobile number");
            getch();
            valid=0;
            gotoxy(21,7);
            printf("\t\t\t\t\t\t");
            gotoxy(21,7);
            textcolor(YELLOW);
        }
        }while(valid==0);
        return &psn;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("d:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
            ++count;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp;
    fp=fopen("d:\\My Project\\allbookings.dat","rb");

    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
    {
        textcolor(LIGHTBLUE);
        printf("All seats full in train no %s in %c class!\n",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("d:\\My Project\\allbookings.dat","ab");
    if(fp==NULL)
    {
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}
int accept_ticket_no()
{
    printf("Enter ticket no:");
    int valid;
    int ticket_no;
      do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTBLUE);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelleing Input...");
            getch();
            textcolor(RED);
            return 0;

        }
        if(ticket_no<0)
        {
        textcolor(LIGHTBLUE);
        gotoxy(1,25);
        printf("Error!Ticket number should be positive");
        valid=0;
        getch();
        gotoxy(16,1);
        printf("\t\t\t\t\t\t");
        gotoxy(16,1);
        textcolor(RED);
        }
    }while(valid==0);
    return ticket_no;
}
int view_ticket(int ticket_no)
{
    FILE *fp=fopen("d:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTBLUE);
        printf("\nNo bookings done yet");
        return;
    }
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",
                   pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            printf("\n\n");
            found=1;
            break;
        }
    }
    if(!found)
    {
        textcolor(LIGHTBLUE);
        printf("\nNo details of ticket no %d found! ",ticket_no);
    }
    fclose(fp);
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("d:\\My Project\\allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTBLUE);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("d:\\My Project\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\My Project\\temp.dat");
    }
    else
    {
        remove("d:\\My Project\\allbookings.dat");
        rename("d:\\My Project\\temp.dat","d:\\My Project\\allbookings.dat");
    }
    return found;
}
char* accept_train_no()
{
    static char train_no[10];
    int valid;
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTBLUE);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling input...");
            textcolor(RED);
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTBLUE);
            gotoxy(1,25);
            printf("Error!Invalid Train No");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(RED);
        }
    }while(valid==0);
    clrscr();
    return train_no;
}
int cancel_train(char *ptrain_no)
  {
    FILE *fp1=fopen("d:\\My Project\\allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTBLUE);
        printf("\nNo Bookings Done Yet");
        return -1;
    }
    FILE *fp2=fopen("d:\\My Project\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,ptrain_no)!=0)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
       {
            found=1;
        }
    }
    fclose(fp1);

    fclose(fp2);
    if(found==0)
    {
        remove("d:\\My Project\\temp.dat");
    }
    else
    {
        remove("d:\\My Project\\allbookings.dat");
        rename("d:\\My Project\\temp.dat","d:\\My Project\\allbookings.dat");
    }
    return found;
}
char* accept_mob_no()
{
    static char mob_no[11];
    char *pos;
    int valid;
    printf("Enter mobile number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
         if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTBLUE);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input...");
            getch();
            textcolor(RED);
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTBLUE);
            gotoxy(1,25);
            printf("Error!Invalid Mobile No");
            getch();
            gotoxy(21,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(21,1);
            textcolor(RED);
        }
    }while(valid==0);
    clrscr();
    return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp=fopen("d:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }

    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTBLUE);
        printf("Sorry!No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(RED);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("-------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    textcolor(RED);
    getch();
}
void view_all_bookings()
{
    Passenger pr;
    int i;
    int count=0;
    textcolor(YELLOW);
    FILE *fp;
    fp=fopen("d:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        printf("\nNo bookings done yet!");
        return -1;
    }
    textcolor(YELLOW);
    printf("TRAIN NO\tTICKET NO\tCLASS\t  NAME\t\tMOBILE\n");
     for(i=0;i<=76;i++)
    {
        printf("-");

    }
    printf("\n");
    int x=42;
    int y=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%s\t\t%d\t\t%c\t\n",pr.train_no,pr.ticketno,pr.p_class);
        {
            gotoxy(x,y);
            printf("%s\t%s\n",pr.p_name,pr.mob_no);
            y++;
        }
        count++;
    }
    textcolor(WHITE);
    printf("\n\nPress any key to back to main screen");
    getch();
    fclose(fp);
}
void view_bookings(char* p_train_no)
{
    FILE *fp=fopen("d:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("\nNo bookings done yet");
        return -1;
    }
    Passenger pr;
    int i,count=0;
    textcolor(YELLOW);
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(i=0;i<=76;i++)
    {
        printf("-");

    }

    printf("\n");
    int x=42;
    int y=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,p_train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            {
                gotoxy(x,y);
                printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
                y++;
            }
            count++;
        }
    }
    if(count==0)
    {
        textcolor(RED);
        printf("\nNo details of ticket no %d found! ",pr.ticketno);
    }
    fclose(fp);
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    getch();

}


