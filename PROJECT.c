#include <stdio.h>           //THIS IS THE FINAL 01 OF PROJECT// 
#include <stdlib.h>             // ICT RESTERAUNT PROJECT //
#include <conio.h>                   // PROTOTYPE 01 //
#include <string.h>               
#include <time.h>
#include <windows.h>

int people,tbn,tbn1,choice,chD=-1,chF=-1,seat,status[10],Table[10][8],a=0,b=0,c=0,K,F,M,T,C,O,W;
int month[10],rand_month,rand_name,cancle;
char yesno,enter,name[10][30];

void BookTable();
void Order();
void ClearBill();
void Exit();
void Invalid_choice();

void Menu()
{
    system("cls");
    Sleep(30); printf("======================================\n");
    Sleep(30); printf("ICT Restaurant System\n");
    Sleep(30); printf("======================================\n");
    Sleep(30); printf("[1] Book a table\n");
    Sleep(30); printf("[2] Order food & drink\n");
    Sleep(30); printf("[3] Display and clear a bill\n");
    Sleep(30); printf("[0] Exit\n");
    Sleep(30); printf("--------------------------------------\n");
    Sleep(30); printf("Enter the choice: ");
    scanf("%d",&choice);
    (choice == 1)? BookTable(): (choice == 2)? Order(): (choice == 3)? ClearBill(): (choice == 0)? Exit(): Invalid_choice();
}

void BookTable()
{
    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    Sleep(10); printf("P"); Sleep (10); printf("l"); Sleep(10); printf("e"); Sleep(10); printf("a"); Sleep(10); printf("s"); Sleep(10); printf("e"); Sleep(10); printf(" "); Sleep(10); printf("w"); Sleep(10); printf("a"); Sleep(10); printf("i"); Sleep(10); printf("t");
    Sleep(50); printf("."); Sleep(50); printf("."); Sleep(50); printf("."); 
    Sleep(450);

    system("cls");
    printf("[Book a table]\n\n");
    while(1)
    {
        printf("Enter the number of people: ");
        scanf("%d",&people);
        if(people <= 0 || people > 8)
            printf("This restaurant is only available for 1 - 8 people.\n");  
        else    break; 
    }

    system("cls"); 
    Sleep(30); printf("\n=========================================================\n");
    Sleep(30); printf("List of tables\t\t\t\tStatus\n");
    Sleep(30); printf("=========================================================\n");
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 3)        seat = 2;
        else if(i >= 4 && i <= 7)   seat = 4;
        else                        seat = 8;    
        if(people <= seat && status[i] != 2)     status[i] = 0;
        else if(status[i] == 2)     status[i] = 2;
        else                        status[i] = 1; 
        Sleep(30); printf("Table %d: %d seats\t\t\t%s\n",i+1,seat,(status[i] == 0)? "Available": (status[i] == 1)? "Not enough seat": "Occupied");
    }
    while(1)
    {
        printf("\nEnter a table number (input 0 to cancel): ");
        scanf("%d",&tbn);
        if(tbn < 0 || tbn > 10)
            printf("Invalid choice!\n");
        else if(tbn == 0)     Menu();
        else if(status[tbn-1] != 0)
            printf("Please enter the available table.\n");
        else    
        {
            status[tbn-1] = 2;       
            Table[tbn-1][7] = 1; 
            break; 
        }
    }

    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    char booking1[14] = {'P','l','e','a','s','e',' ','w','a','i','t','.','.','.'};
    for(int i=0 ; i<= 13 ; i++)
    {
        Sleep(10);
        printf("%c",booking1[i]);
    }
    printf("\n \n \t \t \t \t \t \t \t");
    Sleep(500);
    char booking2[22] = {'W','e',' ','a','r','e',' ','b','o','o','k','i','n','g',' ','f','o','r',' ','y','o','u'};
    for(int i=0 ; i<= 21 ; i++)
    {
        Sleep(60);
        printf("%c",booking2[i]);
    }
    Sleep(940);
    
    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    printf("[Your table is %d]\n",tbn);
    printf("\n \t \t \t \t \t \t \tEnter your name: ");
    scanf("%s",&name[tbn-1]);
    while(1)
    {   
        printf("\n \t \t \t \t \t \t \t");
        printf("Enter your birth month(1-12): ");
        scanf("%d",&month[tbn-1]);
        if(month[tbn-1] < 1 || month[tbn-1] > 12)
            printf("\t\t\t\t\t\t\tPlease enter your real birth month.\n");  
        else    break; 
    }

    char GLHF[9] = {'G','o','o','d','l','u','c','k','!'};
    printf("\n \t \t \t \t \t \t \t");
    for(int i=0 ; i<=8 ; i++)
    {   
        Sleep(10);
        printf("%c",GLHF[i]);
    }
    Sleep(1300);
    
    Menu();
}

void Order()
{
    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    Sleep(10); printf("P"); Sleep (10); printf("l"); Sleep(10); printf("e"); Sleep(10); printf("a"); Sleep(10); printf("s"); Sleep(10); printf("e"); Sleep(10); printf(" "); Sleep(10); printf("w"); Sleep(10); printf("a"); Sleep(10); printf("i"); Sleep(10); printf("t");
    Sleep(50); printf("."); Sleep(50); printf("."); Sleep(50); printf("."); 
    Sleep(450);

    system("cls");
    printf("[Order food & drinks]\n\n");
    printf("List of occupied tables:\n");
    for(int i = 0; i < 10; i++)
    {
        if(status[i] == 2)
            printf("Table %d\n",i+1);  
        else if(status[i] == 0 || status[i] == 1)     b++;               
    }
    (b == 10)? printf("None\n"), b = 0: b == 0;
    printf("\nEnter the table number [1-10] (0 to exit): ");
    scanf("%d",&tbn1);  
    if(tbn1 == 0)      Menu();  
    if(Table[tbn1-1][7] != 1)    
    {
        printf("\nThis table have not booked yet.\n");         
        while(1)
        {
            printf("Press Enter to go back to the main menu.\n");
            enter = getch();
            if(enter == 13)      Menu();
        }
    }
    Sleep(30); printf("\n===========================================================\n");
    Sleep(30); printf("Order food & drinks\n");
    Sleep(30); printf("===========================================================\n\n");
    Sleep(30); printf("%-8s %40s","Food Menu","Price (Baht)\n");
    Sleep(30); printf("-----------------------------------------------------------\n");
    Sleep(30); printf("%-8s %22s","[1] Kao Pad Kra Pao","45.0\n");
    Sleep(30); printf("%-8s %27s","[2] Fried Rice","45.0\n");
    Sleep(30); printf("%-8s %20s","[3] Kha Nar Mhoo Krob","50.0\n");
    Sleep(30); printf("%-8s %15s","[4] Tom Yum Koong Nam Khon","60.0\n");
    Sleep(30); printf("-----------------------------------------------------------\n");
    while(1)
    {
        printf("Enter the choice (input 0 to stop): ");
        scanf("%d",&chF);
        if(chF < 0 || chF > 4)
            printf("Invalid choice!\n");
        else
        {
            (chF == 1)? Table[tbn1-1][0]++: (chF == 2)? Table[tbn1-1][1]++:
            (chF == 3)? Table[tbn1-1][2]++: (chF == 4)? Table[tbn1-1][3]++: 0;       
            if(chF == 0)         break;
        }                
    }                   
    Sleep(30); printf("%-8s %40s","\nDrink Menu","Price (Baht)\n");
    Sleep(30); printf("-----------------------------------------------------------\n");
    Sleep(30); printf("%-8s %29s","[1] Coca Cola","20.0\n");
    Sleep(30); printf("%-8s %26s","[2] Orange Juice","30.0\n");
    Sleep(30); printf("%-8s %27s","[3] Still Water","10.0\n");
    Sleep(30); printf("-----------------------------------------------------------\n");
    while(1)
    {
        printf("Enter the choice (input 0 to stop): ");
        scanf("%d",&chD);
        if(chD < 0 || chD >= 4)
            printf("Invalid choice!\n");
        else
        {
            (chD == 1)? Table[tbn1-1][4]++: (chD == 2)? Table[tbn1-1][5]++: (chD == 3)? Table[tbn1-1][6]++: 0; 
            if(chD == 0)         break;  
        }     
    }

    system("cls");
    printf("\nKhun %s has order the following:\n",name[tbn1-1]); 
    for(int i = 1 ; i<40 ; i++)
    {
        Sleep(20);
        printf("-");
    }
    printf("\n");
    for(int i = 0; i <= 6; i++)
        {
            if(Table[tbn1-1][i] != 0)
                printf("[%c] %s x%d\n",(i>=0 && i<=3)? 70: 68,(i==0)? "Kao Pad Kra Pao": (i==1)? "Fried Rice": (i==2)? "Kha Nar Mhoo Krob": (i==3)?"Tom Yum Koong Nam Khon":
            (i==4)? "Coca Cola": (i==5)? "Orange Juice": "Still Water" ,Table[tbn1-1][i]);
        }
    while(1)
    {
        printf("Confirm? (y|n): ");
        scanf(" %c",&yesno);
        if(yesno == 'y' || yesno == 'Y' || yesno == 'n'|| yesno == 'N') 
        {
            if(yesno == 'y' || yesno == 'Y')
                break;
            else if(yesno == 'n' || yesno == 'N')
            { 
                printf("\n");
                printf("Would you like to cancle some order?\n");
                printf("Please enter the number of digits you want to cancle.\n");
                printf("Input [0] if you don't want to cancle.\n");
                for(int i = 0; i <= 6; i++)
                {
                    if(Table[tbn1-1][i] != 0)
                    {
                        printf("[%c] %s : ",(i>=0 && i<=3)? 70: 68,(i==0)? "Kao Pad Kra Pao": (i==1)? "Fried Rice": (i==2)? "Kha Nar Mhoo Krob": (i==3)?"Tom Yum Koong Nam Khon":
                    (i==4)? "Coca Cola": (i==5)? "Orange Juice": "Still Water");
                        scanf("%d",&cancle);
                        (cancle!=0 && cancle>0)? Table[tbn1-1][i] -= cancle: 0;
                    }
                    else
                        Table[tbn1-1][i] = 0;
                }
            }
        }
        else
            printf("Please confirm again.\n");
    }       
    Menu();
}

void ClearBill()
{
    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    Sleep(10); printf("P"); Sleep (10); printf("l"); Sleep(10); printf("e"); Sleep(10); printf("a"); Sleep(10); printf("s"); Sleep(10); printf("e"); Sleep(10); printf(" "); Sleep(10); printf("w"); Sleep(10); printf("a"); Sleep(10); printf("i"); Sleep(10); printf("t");
    Sleep(50); printf("."); Sleep(50); printf("."); Sleep(50); printf("."); 
    Sleep(450);

    system("cls");
    printf("[Display and clear a bill]\n\n");
    printf("List of occupied tables:\n");
    for(int i = 0; i < 10; i++)
    {
        if(status[i] == 2)
            printf("Table %d\n",i+1);  
        else if(status[i] == 0 || status[i] == 1)     c++;               
    }
    (c == 10)? printf("None\n"), c = 0: c == 0;
    printf("\nEnter the table number [1-10] (0 to exit): ");
    scanf("%d",&tbn);
    if(tbn == 0)    Menu(); 
    if(Table[tbn-1][7] != 1)  
    {
        printf("\nThere is no one sitting at the table.\n");
        while(1)
        {
            printf("Press Enter to go back to the main menu.\n");
            enter = getch();
            if(enter == 13)      Menu();
        }
    }
    for(int i = 0; i <=6; i++)
    {
        if(Table[tbn-1][7] == 1 && Table[tbn-1][i] != 0)      a++;
    }
    if(a == 0)
    {
        printf("\nThere is no any ordered food or drink.\n");
        while(1)
         {
            printf("Press Enter to go back to the main menu.\n");
            enter = getch();
            if(enter == 13)      Menu();
        }
    }

    system("cls");
    printf("\n\nKhun %s has order the following:\n\n",name[tbn-1]);  
    printf("%-2s %25s %18s","Food Menu","Qty.","Price (Baht)\n");
    printf("-----------------------------------------------------------\n");
    (Table[tbn-1][0]==0 && Table[tbn-1][1]==0 && Table[tbn-1][2]==0 && Table[tbn-1][3]==0)? printf("None\n"): 0;
    (Table[tbn-1][0] != 0)? printf("[1] Kao Pad Kra Pao %12d\t %.1f\n",Table[tbn-1][0],45.0*Table[tbn-1][0]), Table[tbn-1][8] = Table[tbn-1][8] + (45.0*Table[tbn-1][0]): 0;
    (Table[tbn-1][1] != 0)? printf("[2] Fried Rice %17d\t %.1f\n",Table[tbn-1][1],45.0*Table[tbn-1][1]), Table[tbn-1][8] = Table[tbn-1][8] + (45.0*Table[tbn-1][1]):  0;
    (Table[tbn-1][2] != 0)? printf("[3] Kha Nar Mhoo Krob %10d\t %.1f\n",Table[tbn-1][2],50.0*Table[tbn-1][2]), Table[tbn-1][8] = Table[tbn-1][8] + (50.0*Table[tbn-1][2]):  0;
    (Table[tbn-1][3] != 0)? printf("[4] Tom Yum Koong Nam Khon %5d\t %.1f\n",Table[tbn-1][3],60.0*Table[tbn-1][3]), Table[tbn-1][8] = Table[tbn-1][8] + (60.0*Table[tbn-1][3]): 0;
    printf("-----------------------------------------------------------\n");
    printf("%-2s %24s %18s","Drink Menu","Qty.","Price (Baht)\n");
    printf("-----------------------------------------------------------\n");
    (Table[tbn-1][4]==0 && Table[tbn-1][5]==0 && Table[tbn-1][6]==0)? printf("None\n"):  0;
    (Table[tbn-1][4] != 0)? printf("[1] Coca Cola %18d\t %.1f\n",Table[tbn-1][4],20.0*Table[tbn-1][4]), Table[tbn-1][8] = Table[tbn-1][8] + (20.0*Table[tbn-1][4]): 0;
    (Table[tbn-1][5] != 0)? printf("[2] Orange Juice %15d\t %.1f\n",Table[tbn-1][5],30.0*Table[tbn-1][5]), Table[tbn-1][8] = Table[tbn-1][8] + (30.0*Table[tbn-1][5]): 0;
    (Table[tbn-1][6] != 0)? printf("[3] Still Water %16d\t %.1f\n",Table[tbn-1][6],10.0*Table[tbn-1][6]), Table[tbn-1][8] = Table[tbn-1][8] + (10.0*Table[tbn-1][6]):  0;
    printf("-----------------------------------------------------------\n\n");
    if(rand_name == tbn-1 && Table[tbn-1][7] == 1)    
        printf("Congratulations for Khun %s!!! You are a lucky person.Free meal for all.\n\n",name[tbn-1]);
    else if(month[tbn-1] == rand_month)
    {
        printf("Congratulations!!! Your birth month correspond to the restaurant's promotion.\nYou get 50 percent discount.\n");
        printf("Discount:%11.2f\tFrom total: %.2f\n",Table[tbn-1][8] * 0.5,Table[tbn-1][8]+0.0);
        printf("Total amount:%7.2f\n", Table[tbn-1][8] - (Table[tbn-1][8] * 0.5));
    }
    else
        printf("** Total amount: %d.00\n\n",Table[tbn-1][8]);
    while(1)
    {
        printf("Do you want to clear a bill? (y|n):");
        scanf(" %c",&yesno);
        if(yesno == 'y' || yesno == 'Y' || yesno == 'n'|| yesno == 'N')
        {
            if(yesno == 'y'|| yesno == 'Y' )  
            {
                for(int i = 0; i <= 8; i++)
                    Table[tbn-1][i] = 0;
                status[tbn-1] = 0;
                name[tbn-1][1] = 0;
                month[tbn-1] = 0;
                a = 0;      b = 0;      c = 0;
                break;
            }  
            else    
            {
                Table[tbn-1][8] = Table[tbn-1][8] - Table[tbn-1][8];
                break;
            }
        }
        else
            printf("There's only 2 alphabets choices YES or NO\n");
            printf("Please confirm again.\n");
    }
    Menu();
}
void Exit()
{
    FILE *fptr;
    system("cls");
    printf("\n\n");
    Sleep(40); printf("\t \t \t \t \t========================================================================================\n");
    Sleep(40);printf("\t \t \t \t \t=====--------------------------THANKS FOR COMING!!---------------------------------=====\n");
    Sleep(40); printf("\t \t \t \t \t=====---------------------------HAVE A NICE DAY :)---------------------------------=====\n");
    Sleep(40); printf("\t \t \t \t \t========================================================================================\n");
    printf("\n \t \t \t \t \t \t \t \t");

    Sleep(100); printf("P");Sleep(100); printf("r");Sleep(100); printf("e");Sleep(100); printf("s");Sleep(100); printf("e");Sleep(100); printf("n");Sleep(100); printf("t");Sleep(100); printf("e");Sleep(100); printf("d");Sleep(100); printf(" ");Sleep(100); printf("b");Sleep(100); printf("y");Sleep(100); printf(" ");Sleep(100); printf("M");Sleep(100); printf("U");
    Sleep(100); printf("I");Sleep(100); printf("C");Sleep(100); printf("T");Sleep(100); printf(" ");Sleep(100); printf("S");Sleep(100); printf("t");Sleep(100); printf("u");Sleep(100); printf("d");Sleep(100); printf("e");Sleep(100); printf("n");Sleep(100); printf("t");Sleep(100); printf(" ");Sleep(100); printf("G");Sleep(100); printf("r");Sleep(100); printf("o");
    Sleep(100); printf("u");Sleep(100); printf("p");Sleep(100); printf(" ");Sleep(100); printf("I");

    printf("\n\n");
    printf("\t \t \t \t \t");
    for(int i = 1 ; i <= 88 ; i++)
    {
        Sleep(3);
        printf("=");
    }
    
    printf("\n\n");
    printf("\t \t \t \t \t");
    char kimmy[26] = {'6','1','8','8','0','0','9',' ','A','l','i','s','a',' ','U','t','h','i','k','a','m','p','o','r','n'};
    char yoda[32] = {'6','1','8','8','0','2','0',' ','C','h','a','n','a','t','h','i','p',' ','S','i','r','i','s','a','n','g','p','a','i','v','a','l'};
    char mook[31] = {'6','1','8','8','0','4','6',' ','J','i','r','a','c','h','a','y','a',' ','W','o','n','g','s','u','p','p','a','k','a','r','n'};
    char baitoey[24] = {'6','1','8','8','0','9','1',' ','K','a','m','u','p','s','o','r','n',' ','S','a','n','s','u','k'};
    char nutty[26] = {'6','1','8','8','1','0','8',' ','N','a','t','a','r','e','e',' ','M','a','n','e','e','s','a','w','a','t'};
    for(int i=0 ; i<=24 ; i++)
    {
        Sleep(30);
        printf("%c",kimmy[i]);
    }
    printf("\n");
    printf("\t \t \t \t \t");
    for(int i=0 ; i<=31 ; i++)
    {
        Sleep(30);
        printf("%c",yoda[i]);
    }
    printf("\n");
    printf("\t \t \t \t \t");
    for(int i=0 ; i<=30 ; i++)
    {
        Sleep(30);
        printf("%c",mook[i]);
    }
    printf("\n");
    printf("\t \t \t \t \t");
    for(int i=0 ; i<=23 ; i++)
    {
        Sleep(30);
        printf("%c",baitoey[i]);
    }
    printf("\n");
    printf("\t \t \t \t \t");
    for(int i=0 ; i<=25 ; i++)
    {
        Sleep(30);
        printf("%c",nutty[i]);
    }
    printf("\n\n");
    printf("\t \t \t \t \t");
    for(int i = 1 ; i <= 88 ; i++)
    {
        Sleep(3);
        printf("=");
    }
    printf("\n\n");
    printf("\t \t \t \t \t \t \t \t \t ");
    char Seeya[18] = {'S','E','E',' ','Y','O','U',' ','N','E','X','T',' ','T','I','M','E','!'};
    for(int i=0 ; i<= 17 ; i++)
    {
        Sleep(30);
        printf("%c",Seeya[i]);
    }
    
    Sleep(8000);
    system("cls");

    fclose(fptr);
}
void Invalid_choice()
{
    printf("Invalid choice.\n");
    printf("Please enter available choice.\n");
    while(1)
    {
        printf("Press Enter to go back to the main menu.\n");
        enter = getch();
        if(enter == 13)      Menu();
    }
}
int main()
{
    srand(time(NULL));
    rand_month = 1 + rand() % 12;
    rand_name = 1 + rand() % 10;

    system("cls");
    printf("\n\n");
    printf("\t \t \t \t \t========================================================================================\n");
    printf("\t \t \t \t \t=====---------------------WELCOME TO ICT RESTAURANT SYSTEM-------------------------=====\n");
    printf("\t \t \t \t \t========================================================================================\n");
    printf("\t \t \t \t \t");
    for(int i = 1 ; i<89 ; i++)
    {
        Sleep(20);
        printf("-");
    }
    Sleep(500);
    system("cls");

    printf("\n \t \t \t \t \t \t \t");
    Sleep(50); printf("A"); Sleep(50); printf("n"); Sleep(50); printf("a"); Sleep(50); printf("l"); Sleep(50); printf("y"); Sleep(50); printf("z"); Sleep(50); printf("i"); Sleep(50); printf("n"); Sleep(50); printf("g");
    Sleep(50); printf(" "); Sleep(50); printf("D"); Sleep(50); printf("a"); Sleep(50); printf("t"); Sleep(50); printf("a"); Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800);

    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    Sleep(10); printf("N"); Sleep(10); printf("o"); Sleep(10); printf("w"); Sleep(10); printf(" "); Sleep(10); printf("l"); Sleep(10); printf("o"); Sleep(10); printf("a"); Sleep(10); printf("d"); Sleep(10); printf("i"); Sleep(10); printf("n"); Sleep(10); printf("g");
    printf("\t");
    Sleep(10); printf("P"); Sleep (10); printf("l"); Sleep(10); printf("e"); Sleep(10); printf("a"); Sleep(10); printf("s"); Sleep(10); printf("e"); Sleep(10); printf(" "); Sleep(10); printf("w"); Sleep(10); printf("a"); Sleep(10); printf("i"); Sleep(10); printf("t");
    Sleep(50); printf("."); Sleep(50); printf("."); Sleep(50); printf(".");
    printf("\n\n");

    printf("\t \t \t \t \t \t \t");
    printf("[");
    for(int i = 1 ; i <= 50 ; i++)
    {
        Sleep(40); 
        printf("|");
    }
    printf("]");
    printf("\n");
    
    system("cls");
    printf("\n \t \t \t \t \t \t \t");
    Sleep(30); printf("C"); Sleep(30); printf("o"); Sleep(30); printf("m"); Sleep(30); printf("p"); Sleep(30); printf("l"); Sleep(30); printf("e"); Sleep(30); printf("t"); Sleep(30); printf("e");
    Sleep(1000);
    
    Menu();
    return 0;
}