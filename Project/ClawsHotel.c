    #include<stdio.h>
    #include <stdlib.h>
    #include<string.h>
    #include<time.h>
    #include <windows.h>
    #include<string.h>
    #include<conio.h>


    typedef struct staff
    {   char pos[20];          //position
        char name[50];
        int id;
        char address[120];
        int salary;
        char worktime[15];
        int contact;
    }st;

    st s,temp,*a;

    typedef struct logininfo
    { char u[15];
      char p[55];}log;
    log l[3],x,t;

    void login();                     //for login
    void renew_pass(log *l);          //if user forgets password
    void welcome();                   //welcome message for hotel
    void menu();                      //display of features
    void inv();                         //message for entering invalid option
    void view();                       //display of staff list
    void del();                        //delete a staff record
    void add();                        //add a staff record
    void sort();                       //sort staff records
    void edit();                        //edit a staff record
    void search();                       //search a staff record
    void cngU(log *l);                    //change Username
    void cngP(log *l);                    //Change Password
    void SetColor(int ForgC);            //set console color
    void check(int ID);                  //to enter unique id


    FILE *f1,*f2,*f;       // f1 for pass.dat ,f2 for staffmem.dat, f for temp.dat

    int i,c,found=0,ID;
    char catagories[][20]={"Cook","Waiter","Cleaner","Reception","Supervisor","K.manager"};   //positions in the hotel



    //////////////////////////LOGIN/////////////////////////////

    void login()
    { char up[55],us[15];

      int at=1;
    f1=fopen("pass.dat","rb");
    i=0;
    while(!feof(f1) && i<3)
    {   fscanf(f1,"%s %s",&l[i].u,&l[i].p);
         i++;}
    fclose(f1);


    Try:   printf("\n\n");
        printf("   ****************************  | LOGIN |  *************************** \n");

      printf("\n\n\tUsername:"); scanf("%s",&us);

        printf("\tEnter Password:");


    i=0;
    do{ up[i]=getch();

       if(up[i]!='\r'){printf("*");}
    i++;
    }while(up[i-1]!='\r');

    up[i-1]='\0';


    if(strcmp(l[0].p,up)==0 && strcmp(l[0].u,us)==0)
                                              {menu();}
    else
        {printf("\nIncorrect Password/Username\n");
        printf("1.Try again\n");
        printf("2.Forgot Password\n");

        int pp;
        scanf("%d",&pp);

       if(pp==1 && at<3)
                       {
                            getch();
                            system("cls");
                            printf("Attepmt %d.\n",at);
                            at++;
                            goto Try;}

       else if(pp==2)
                  { renew_pass(l);}

     else
        {printf("\nNo attempts left.");
         return -1;}

    }
    }


    //////////////////////////FORGOT PASS--->RENEW/////////////////////////////

    void renew_pass(log *l)
    { system("cls");

    printf("Username:"); scanf("%s",&x.u);

        if(strcmp(x.u,l[0].u)==0)
    {  f1=fopen("pass.dat","r+b");
      printf("New password:");
      scanf("%s",&x.p);
      fprintf(f1,"%s %s",x.u,x.p);
      fclose(f1);
      }
     else
        {printf("Wrong username!"); return -1;}

     printf("\nNew password has been saved.\n\n");
     getch();
     return login();
     }

    //////////////////////////CHANGE USERNAME/////////////////////////////
     void cngU(log *l)
     {
         f1=fopen("pass.dat","r+b");
     printf("Password:");
     scanf("%s",&t.p);

     if(strcmp(l[0].p,t.p)==0)
     {
     printf("New username:");
      scanf("%s",&x.u);
      strcpy(l[0].u,x.u);
      fprintf(f1,"%s %s",l[0].u,l[0].p);
      fclose(f1);
    printf("\n\tSuccessfully changed Username!");
    }
    else {
        printf("\n\tCan not change password!!");
        printf("\n\tEnter any key to continue.......");
        getch();
        system("cls");
        return menu();
    }
    system("cls");
    menu();
     }


     //////////////////////////CHANGE PASSWORD/////////////////////////////


       void cngP(log *l)
     {
    f1=fopen("pass.dat","r+b");

     printf("Old password:");
     scanf("%s",&t.p);

     if(strcmp(l[0].p,t.p)==0)
     {printf("New password:");
      scanf("%s",&x.p);
      strcpy(l[0].p,x.p);
      fprintf(f1,"%s %s",l[0].u,l[0].p);
      fclose(f1);
      printf("\n\tSuccessfully changed Password!");
    }

    else {
        printf("\n\tCan not change password!!");
        printf("\n\tEnter any key to continue.......");
        getch();
        system("cls");
        return menu();
    }
    system("cls");
    menu();
     }

     //////////////////////////CHANGE CONSOLE COLOR/////////////////////////////

    void SetColor(int ForgC)
    {
         WORD wColor;
         HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
         CONSOLE_SCREEN_BUFFER_INFO csbi;

         if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
         {wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
              SetConsoleTextAttribute(hStdOut, wColor);
         }
         return;
    }

    //////////////////////////WELCOME MESSAGE/////////////////////////////


    void welcome()
    {time_t t;
        time(&t);

    printf("\n\n");
    SetColor(11);
    for(int i=0;i<128;i++)
        printf("\xbd");
     printf("\n");
     printf("\t\t\t\t\t\t\tCLAWS HOTEL\n");
     printf("\n\n");

        printf("\t\t\t\t\t\t%s",ctime(&t));
     printf("\n");
    for(int i=0;i<128;i++)
        printf("\xbd");
     printf("\n\n");
     SetColor(9);
    printf("\t\t\t\t\t\t   | BY TEAM CLAWS |\n");
     SetColor(15);
     printf("\n\n\t\t\t\tEnter any key to continue...........");
     getch();
     system("cls");
        return;
    }

    //////////////////////////MENU/////////////////////////////

    void menu()
    {    system("cls");

         SetColor(12);
         while(1)
         {printf("\n\n");
         printf("   ****************************  | MENU |  *************************** \n");
         SetColor(3);
         printf("\n\t\t1-->View Staff Details\n");
         printf("\t\t2-->Add Staff \n");
         printf("\t\t3-->Delete Staff \n");
         printf("\t\t4-->Search Staff \n");
         printf("\t\t5-->Edit Staff Details\n");
         printf("\t\t6-->Sort Staff Details \n");
         printf("\t\t7-->Change Username\n");
         printf("\t\t8-->Change Password\n");
         printf("\t\t9-->Exit program\n");

        printf("Enter your choice:");
        scanf("%d",&c);
    SetColor(15);
         switch(c)
         {
         case 1: view(); break;
          case 2: add(); break;
          case 3: del(); break;
          case 4: search(); break;
           case 5: edit(); break;
           case 6: sort(); break;
           case 7: cngU(l);break;
           case 8: cngP(l);break;
           case 9: system("cls");
           SetColor(11);
           printf("\n\n");
    printf("\t\t*************Hotel Staff Management System**************\n");
    printf("\t\tProject in C\n");
    printf("\t\tis brought to you by\n");
    printf("\t\tTEAM CLAWS\n\n");
    getch();
    exit(0);
    break;
           default: inv(); getch(); break;

         }
    }
    }


    //////////////////////////MESSAGE FOR INVALID INPUT/////////////////////////////

    void inv()
    {
        printf("\nInvalid Input!!!!......\n");
        printf("Enter any Key to continue........... ");
        getch();
        system("cls");
        return;
    }

    //////////////////////////VIEW/////////////////////////////


    void view()
    {  system("cls");
        int i;

        f2=fopen("staffmem.dat","rb");
        if(f2==NULL)
            exit(0);

        printf("CATAGORY   ");
        printf("\tNAME\t");
        printf("\tID\t ");
        printf("\tAddress\t\t");
        printf("\tSALARY\t ");
        printf("\t WORK TIME\t");
        printf("    CONTACT\n");


        for(i=0; i<118; i++)
            printf("-");
       while(fread(&s,sizeof(s),1,f2))
        {

            printf("\n");
            printf("%-15s",s.pos);
            printf("%-17s",s.name);
            printf("%-7d",s.id);
            printf("%-32s",s.address);
            printf("%-16d",s.salary);
            printf("%-18s",s.worktime);
            printf("%12d",s.contact);

        }
        printf("\n");
        for(i=0; i<118; i++)
            printf("-");

        fclose(f2);
        printf("\n\tEnter any key to continue.......");
        getch();
        system("cls");
    }

    //////////////////////////ADD/////////////////////////////

    void add()
    {  system("cls");
        found=0;

       f2=fopen("staffmem.dat","a+b");
        if(f2==NULL)
            exit(0);

           printf("   ****************************  |Select Catagory|  *************************** \n");
           for(i=0;i<6;i++)
           {
               printf("\t\t%d-->%s\n",i+1,catagories[i]);
           }
              printf("\t\t7-->Return\n");
               printf("Enter your choice:");
          scanf("%d",&c);
          if(c>=1 && c<=6)
         {

        strcpy(s.pos,catagories[c-1]);

        printf("Enter name:");       scanf("%s",&s.name);
        printf("Enter ID:");         scanf("%d",&s.id);
                                     check(s.id);
        printf("Enter Address:");    scanf("%s",&s.address);
        printf("Enter Salary:");     scanf("%d",&s.salary);
        printf("Enter Worktime:");   scanf("%s",&s.worktime);
        printf("Enter Contact:");    scanf("%d",&s.contact);

    fwrite(&s,sizeof(s),1,f2);


    printf("\nSuccessfully Added staff!!!\n");

    fclose(f2);

      printf("\nSave any more?(Y / N):");

    if(getch()=='n')

    {system("cls");
    return menu();}

    else

    {system("cls");

    add();

    }}
    else if(c==7){  return menu();  }
    else { inv(); return add();}

    }
    ///////////////////For Unique ID//////////////////
    void check(int ID)
    { f2=fopen("staffmem.dat","rb");
        while (fread(&s,sizeof(s),1,f2))
      {
          if(s.id==ID)
          {found=1;}

      }
      if(found!=1)
      {return;}
      else
      {
          printf("\n\t\tID already exists!");
          printf("\n\tEnter any key to continue.......");
           getch();
           system("cls");
           return menu();

      }
    fclose(f2);

    }


    //////////////////////////DELETE/////////////////////////////

    void del()
    {

        int ID,found=0;
        f2=fopen("staffmem.dat","rb");
        f=fopen("temp.dat","wb");
            if (f==NULL)
            exit(0);
            if (f2==NULL)
            exit(0);

            system("cls");
        printf("Enter the ID of a staff to be deleted: \n");
        scanf("%d",&ID);

      while (fread(&s,sizeof(s),1,f2))
      {
          if(s.id==ID)
          {
              found=1;
          }
          else
              fwrite(&s,sizeof(s),1,f);
      }
    fclose(f2);
    fclose(f);

    if(found==1) {
         f=fopen("temp.dat","rb");
         f2=fopen("staffmem.dat","wb");

      while (fread(&s,sizeof(s),1,f))
        {
        fwrite(&s,sizeof(s),1,f2);
      }
      printf("   **********************  Record Successfully Deleted  ********************* \n");
      }

    else {

            printf("\n\t\tNo record is found to Delete.\n");
           printf("\t\tEnter any Key to continue.....");

           getch();
      }
    fclose(f2);
    fclose(f);

      printf("\nDelete any more?(Y / N):");

    if(getch()=='n')

    {system("cls");
    return menu();}

    else

    {system("cls");

    del();

    }

    }

    /////////////////////////SEARCH/////////////////////////////

    void search()
    {
        system("cls");
        int i,c,g,found=0;

        char Nam[50];
        int ID;
        f2 = fopen("staffmem.dat","rb+");
        rewind(f2);
        if(f2==NULL)
            {printf("File isn't created."); return-1;}


           printf("   **************************  |Search BY|  ************************* \n");
          printf("\t1-->Name\n");
          printf("\t2-->ID\n");
          printf("\t3-->POSITION\n");
          printf("\t4-->RETURN\n");
          printf("Enter your choice:");
          scanf("%d",&c);
          fflush(stdin);

     system("cls");
    if(c==1)
            { printf("Enter Name to search: ");
                gets(Nam);
             while(fread(&s,sizeof(s),1,f2))
             {
                 if(strcmp(Nam,s.name)==0)
                 {  found=1;}

             }
             if(found==1)
             { printf("The Staff is available\n");
                 rewind(f2);
              while(fread(&s,sizeof(s),1,f2))
             {
                 if(strcmp(Nam,s.name)==0)
                       {printf("%s",s.pos);
            printf("Name:%s\n",s.name);
            printf("ID:%d\n",s.id);
            printf("Addres:%s\n",s.address);
            printf("Salary:%d\n",s.salary);
            printf("Worktime:%s\n",s.worktime);
            printf("Contact:%d\n",s.contact);
             }}}
             else  {printf("\nNo Record Found"); goto XX;}
    }


    else if(c==2)
            {
                printf("Enter ID to search: ");
                scanf("%d",&ID);
              while(fread(&s,sizeof(s),1,f2))
             {  if(ID==s.id)
                 {  f=1;}
             }

                if(f==1)
             { printf("The Staff is available\n");
                 rewind(f2);
              while(fread(&s,sizeof(s),1,f2))
             {
                 if(ID==s.id){

            printf("%s",s.pos);
            printf("Name:%s\n",s.name);
            printf("Id:%d\n",s.id);
            printf("Address:%s\n",s.address);
            printf("Salary:%d\n",s.salary);
            printf("Worktime:%s\n",s.worktime);
            printf("%Contact:d\n",s.contact);
             }}}


    else  {printf("\nNo Record Found"); goto XX;}
    }


    else if(c==3)
      {        printf("   **************************  |Select Catagory to Search|  ************************* \n");
           for(i=0;i<6;i++)
           {
               printf("\t\t%d-->%s\n",i+1,catagories[i]);
           }
            printf("Enter your choice:");
          scanf("%d",&g);
          if(g>=1 && g<=6)
         {

        strcpy(Nam,catagories[g-1]);

              while(fread(&s,sizeof(s),1,f2))
             {  if(strcmp(Nam,s.pos)==0)
                 {f=1;}
                 }
                if(f==1)
             { printf("Staff is available\n");

       printf("CATAGORY   \tNAME\t\tID\t \tAddress\t\t\tSALARY\t \t WORK TIME\t    CONTACT\n");
       for(i=0; i<118; i++)
            printf("-");
            printf("\n");
                 rewind(f2);
              while(fread(&s,sizeof(s),1,f2))
             {
                 if(strcmp(Nam,s.pos)==0)
                     printf("%-15s%-17s%-7d%-32s%-16d%-18s%12d\n",s.pos,s.name,s.id,s.address,s.salary,s.worktime,s.contact);}
             }
             else  {printf("\nNo Record Found"); goto XX;}}

    else{ inv(); goto XX;}
      }
    else if(c==4)
              {return menu();}
    else
         {inv(); search();}




    XX: fclose(f2);

      printf("\nSearch any more?(Y / N):");

    if(getch()=='n')

    return menu() ;

    else

    {system("cls");

    search();}
    }

    /////////////////////////EDIT/////////////////////////////

    void edit()
    {
        int ID,found=0;
        f2=fopen("staffmem.dat","r+b");
        f=fopen("temp.dat","w+b");
            if (f==NULL)
            exit(0);
            if (f2==NULL)
            exit(0);

            system("cls");


     printf("Enter ID to EDIT: ");
                scanf("%d",&ID);

        while (fread(&s,sizeof(s),1,f2))
      {
        if(s.id==ID)
          {found=1;}

          }
              if(found==1)
             { rewind(f2);
              while(fread(&s,sizeof(s),1,f2))
             {
                 if(ID==s.id)
                     {  again:
                         printf("Enter Position: (choose any)\n");
                         for(i=0;i<6;i++)
                         { printf("(%d)%s ",i+1,catagories[i]);

                         }
                         printf("\n");

                         scanf("%d",&c);
                       if(c>=1 && c<=6)
                        {strcpy(temp.pos,catagories[c-1]);}
                        else { printf("Wrong input!!"); getch(); system("cls"); goto again; }
                         printf("Enter name:");       scanf("%s",&temp.name);
                         printf("Enter ID:");         scanf("%d",&temp.id);
                         printf("Enter Address:");    scanf("%s",&temp.address);
                         printf("Enter Salary:");     scanf("%d",&temp.salary);
                         printf("Enter Worktime:");   scanf("%s",&temp.worktime);
                        printf("Enter Contact:");    scanf("%d",&temp.contact);

                         s=temp; }
                         fwrite(&s,sizeof(s),1,f);

             }
            fclose(f2);
           fclose(f);

            f=fopen("temp.dat","r+b");
            f2=fopen("staffmem.dat","w+b");
           while (fread(&s,sizeof(s),1,f))
           {fwrite(&s,sizeof(s),1,f2);}

             }
             else  {printf("\nNo Record Found");   printf("\n\tEnter any key to continue......."); getch(); }
             fclose(f2);
           fclose(f);

    printf("\nEdit any more?(Y / N):");

    if(getch()=='n')

    return menu() ;

    else

    {system("cls");

    edit();}
    }

    /////////////////////////SORT/////////////////////////////

      void sort()
      {
        system("cls");
        int i,j;

           f2=fopen("staffmem.dat","rb+");
           fseek(f2,0, SEEK_END);
          int n=ftell(f2)/sizeof(st);
           rewind(f2);
    a=(st*)calloc(n,sizeof(st));
     for(i=0;i<n;i++)
        fread(&a[i],sizeof(st),1,f2);

        printf("   **************************  |Sort By|  ************************* \n");
        printf("\t\t1.ID\n");
        printf("\t\t2.Salary\n");
         printf("Enter your choice:");
        scanf("%d",&c);
        system("cls");
    if(c==1){
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++){
            if(a[i].id>a[j].id){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }printf("According to ID: \n");
    }


    else if(c==2){
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++){
            if(a[j].salary>a[i].salary){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    } printf("According to Salary: \n");
    }
    else {

        inv(); return menu();
    }
    for(i=0; i<118; i++) printf("-"); printf("\n");
    printf("CATAGORY   \tNAME\t\tID\t \tAddress\t\t\tSALARY\t \t WORK TIME\t    CONTACT\n");
    for(i=0; i<118; i++)
            printf("-");
            printf("\n");
           for(i=0; i<n; i++)
        {
            printf("%-15s",a[i].pos);
            printf("%-17s",a[i].name);
            printf("%-7d",a[i].id);
            printf("%-32s",a[i].address);
            printf("%-16d",a[i].salary);
            printf("%-18s",a[i].worktime);
            printf("%12d\n",a[i].contact);


        printf("\n");}

     fclose(f2);
    printf("\n\tEnter any key to continue.......");
     getch();
     system("cls");
     return menu();
      }

     /////////////////////////MAIN FUNC()/////////////////////////////

    int main()
     {

         welcome();

         login();

    }
