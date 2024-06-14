#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char name[20];
int accountNo,depositAmt, amount=10000;
int main_exit, i;
char surety[5];
void Menu();
void quit();

struct date{
    int day,month,year;
};
struct {
    char name[50];
    int age,acc_no;
    char address[60];
    double phone;
    float amount;
    struct date DOB;
    struct date deposit;
    struct date withdraw;
}add,upd,check,rem,transaction,receiver,AtmFeatures;


void fordelay(int j){

    int i,k;
    for(i=0;i<j;i++)
        k=i;

}//gecikme döngüsü
void login(){
    float number = 1234;
    int pass;
    printf("\n\n\t\t\tEnter the PIN No:");
    scanf("%d", &pass);

    if (pass == number)
    {
        printf("\n\nPIN Matched!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
    }
    else
    {
        printf("Invalid\n Try Again");
        login();
    }
}
void mainMenu(int accountNo) {

    printf("\n\n\t\t==========Welcome to ATM Feature==========\n\n");
    printf("\n\t\t Selected Account Number : %d\n\n",accountNo);
    printf("\n\t\t----Please choose one of the options below----\n");
    printf("\n\t\t< 1 >  Check Balance\n");
    printf("\n\t\t< 2 >  Deposit\n");
    printf("\n\t\t< 3 >  Withdraw\n");
    printf("\n\t\t< 4 >  Back to Menu\n");
    printf("\n\t\t< 5 >  Exit\n\n");

}
void checkBalance(float balance) {
    printf("You Choose to See your Balance\n");
    printf("****Your Available Balance is:   $%.2f\n\n", balance);

}
float moneyDeposit(float balance) {
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);


    balance += deposit;

    printf("****Your New Balance is:   $%.2f\n\n", balance);
    return balance;


}
float moneyWithdraw(float balance){
    float withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);

    while (back){
        printf("please enter your amount to withdraw:\n");
        scanf("%f",&withdraw);

        if (withdraw < balance){
            back = false;
            balance -= withdraw;
            printf("$$$$Your withdrawing money is:  $%.2f\n", withdraw);
            printf("****Your New Balance is:   $%.2f\n\n", balance);
        }else{
            printf("+++You don't have enough money+++\n");
            printf("Please contact to your Bank Customer Services\n");
            printf("****Your Balance is:   $%.2f\n\n", balance);
        }

    }
    return balance;
}
void backMenu(){
    Menu();
}
void MenuExit(){
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Bank Machine!!!-----\n");
    sleep(2);
    exit(0);
}

void new_account(){
    FILE *NewAccount;

    NewAccount = fopen("Record.txt","a+");
    system("cls");
    account_no:
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d.%d.%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the account number:");

    scanf("%d",&add.acc_no);
    while(fscanf(NewAccount,"%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n",&check.acc_no,check.name,&check.DOB.month,&check.DOB.day,&check.DOB.year,&check.age,check.address,&check.phone,&check.amount,&check.deposit.month,&check.deposit.day,&check.deposit.year)!=EOF)
    {
        if (add.acc_no==check.acc_no)
        {printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;

        }
    }
    check.acc_no = add.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d.%d.%d",&add.DOB.month,&add.DOB.day,&add.DOB.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amount);

    fprintf(NewAccount,"%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n",add.acc_no,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.phone,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);

    fclose(NewAccount);
    sleep(1);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        Menu();
    else if(main_exit==0)
        quit();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }

}
void edit(){
    int test = 0,choice,testChoice;
    FILE *oldRec,*newRec;
    oldRec = fopen("record.txt","r");
    newRec = fopen("new.txt", "w");
    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);

    while (fscanf(oldRec,"%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n",&add.acc_no,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no == upd.acc_no){
            test=1;
            try_again_change:
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            switch (choice) {
                case 1:
                    printf("enter your new adress:");
                    scanf("%s", upd.address);
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name, add.DOB.month,
                            add.DOB.day, add.DOB.year, add.age, upd.address, add.phone, add.amount,
                            add.deposit.month, add.deposit.day, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                    sleep(2);
                    break;
                case 2:
                    printf("enter your new phone:");
                    scanf("%lf", &upd.phone);
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name, add.DOB.month,
                            add.DOB.day, add.DOB.year, add.age, add.address, upd.phone, add.amount,
                            add.deposit.month, add.deposit.day, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                    sleep(2);
                    break;
                default:
                    printf("your choice is invalid!!write 1 to try again 2 to exit");
                    scanf("%d", &testChoice);
                    if (choice == 1) {
                        goto try_again_change;
                    } else {
                        quit();
                    }
                    break;
            }
        }
        else{
            fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name, add.DOB.month,
                    add.DOB.day, add.DOB.year, add.age, add.address, add.phone, add.amount,
                    add.deposit.month, add.deposit.day, add.deposit.year);

        }
    }

    if (test != 1){
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        GoToTry:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        switch (main_exit) {
            case 0:
                edit();
                break;
            case 1:
                Menu();
                break;
            case 2:
                quit();
                break;
            default:
                printf("\nInvalid!\a");
                goto GoToTry;
        }
    }
    fclose(oldRec);
    fclose(newRec);

    remove("record.txt");
    rename("new.txt","record.txt");

}
void transact() {
    int choice, tryChoice;
    int test = 0;
    float transactionAmount;
    int isSenderThere = 0,isReceiverThere = 0;
    int controller = 0;
    FILE *oldRec;
    FILE *newRec;
    oldRec = fopen("record.txt", "r+");
    newRec = fopen("new.txt", "w");

    printf("please enter account no of the custumer");
    scanf("%d", &transaction.acc_no);
    printf("please enter account no of the receiver");
    scanf("%d",&receiver.acc_no);

    while (fscanf(oldRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", &add.acc_no, add.name, &add.DOB.month, &add.DOB.day,
                  &add.DOB.year, &add.age, add.address, &add.phone, &add.amount, &add.deposit.month, &add.deposit.day,
                  &add.deposit.year) != EOF) {
        if (add.acc_no== transaction.acc_no){
            isSenderThere = 1;
            transaction = add;
        }else if (add.acc_no == receiver.acc_no){
            isReceiverThere = 1;
            receiver = add;
        }else{
            fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name, add.DOB.month,
                    add.DOB.day, add.DOB.year, add.age, add.address, add.phone, add.amount,
                    add.deposit.month, add.deposit.day, add.deposit.year);
        }

    }
    if (isSenderThere == 1 && isReceiverThere == 1){
        test = 1;
        goToStart:
        printf("\n\nDo you want to\n1.transfer\n2.receive?\n\nEnter your choice(1 for transfer and 2 for receive):");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("enter the amount you want to transfer");
                scanf("%f", &transactionAmount);
                if (transaction.amount > transactionAmount) {
                    transaction.amount = transaction.amount- transactionAmount;
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", transaction.acc_no, transaction.name,
                            transaction.DOB.month,
                            transaction.DOB.day, transaction.DOB.year, transaction.age, transaction.address,
                            transaction.phone, transaction.amount,
                            transaction.deposit.month, transaction.deposit.day, transaction.deposit.year);
                    receiver.amount = transactionAmount +receiver.amount;
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", receiver.acc_no, receiver.name,
                            receiver.DOB.month,
                            receiver.DOB.day, receiver.DOB.year, receiver.age, receiver.address, receiver.phone,
                            receiver.amount,
                            receiver.deposit.month, receiver.deposit.day, receiver.deposit.year);
                    system("cls");
                    system("color 2");
                    printf("\n\ntransfered successfully!");
                    sleep(3);
                } else {
                    system("cls");
                    system("color 4");
                    printf("\n\n\t\tthere isn't enough money in that account! try again");
                    sleep(3);
                    goto goToStart;
                }
                break;
            case 2:
                printf("enter the amount you want to receive");
                scanf("%f", &transactionAmount);
                if (receiver.amount > transactionAmount) {
                    transaction.amount = transactionAmount+transaction.amount;
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", transaction.acc_no, transaction.name,
                            transaction.DOB.month,
                            transaction.DOB.day, transaction.DOB.year, transaction.age, transaction.address,
                            transaction.phone, transaction.amount,
                            transaction.deposit.month, transaction.deposit.day, transaction.deposit.year);
                    receiver.amount = receiver.amount - transactionAmount;
                    fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", receiver.acc_no, receiver.name,
                            receiver.DOB.month,
                            receiver.DOB.day, receiver.DOB.year, receiver.age, receiver.address, receiver.phone,
                            receiver.amount,
                            receiver.deposit.month, receiver.deposit.day, receiver.deposit.year);
                    system("cls");
                    system("color 2");
                    printf("\n\nReceived successfully!");
                    sleep(3);
                } else {
                    system("cls");
                    system("color 4");
                    printf("\n\n\t\tthere isn't enough money in that account! try again");
                    sleep(3);
                    goto goToStart;
                }
                break;
            default:
                system("cls");
                system("color 4");
                printf("\n\n\t\t INVALID");
                system("cls");
                system("color 7");
                goto goToStart;
        }
    }else if (isSenderThere == 0 && isReceiverThere == 1){
        printf("receiver bulunuyor sender yok");
        sleep(3);
        fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", receiver.acc_no, receiver.name,
                receiver.DOB.month,
                receiver.DOB.day, receiver.DOB.year, receiver.age, receiver.address, receiver.phone,
                receiver.amount,
                receiver.deposit.month, receiver.deposit.day, receiver.deposit.year);
    }else if (isSenderThere == 1 && isReceiverThere == 0){
        printf("sender bulunuyor receiver yok");
        sleep(3);
        fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", transaction.acc_no, transaction.name,
                transaction.DOB.month,
                transaction.DOB.day, transaction.DOB.year, transaction.age, transaction.address,
                transaction.phone, transaction.amount,
                transaction.deposit.month, transaction.deposit.day, transaction.deposit.year);
    }


    fclose(oldRec);
    fclose(newRec);
    remove("record.txt");
    rename("new.txt", "record.txt");
    if (test != 1) {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        GoToTest1:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        switch (main_exit) {
            case 0:
                transact();
                break;
            case 1:
                Menu();
                break;
            case 2:
                quit();
                break;
            default:
                printf("\nInvalid!\a");
                goto GoToTest1;
        }
    }else{
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1){
            Menu();
        }
        else if(main_exit == 0) {
            quit(0);
        } else{
            printf("your choice is invalid you are going to go to Menu");
            sleep(2);
            Menu();
        }
    }
}
void delete(){
    int test = 1;
    FILE *oldRec,*newRec;
    oldRec = fopen("record.txt","r");
    newRec = fopen("newRec.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(oldRec,"%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n",&add.acc_no,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,&add.phone,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no == rem.acc_no){
            test++;
            printf("\n Record is deleted successfully");
        }else{
            fprintf(newRec, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name, add.DOB.month,
                    add.DOB.day, add.DOB.year, add.age, add.address, add.phone, add.amount,
                    add.deposit.month, add.deposit.day, add.deposit.year);
        }

    }
    fclose(oldRec);
    fclose(newRec);
    remove("record.txt");
    rename("newRec.txt","record.txt");

    if (test == 0){
        printf("\n Record not found");
        returnMainExit:
        printf("\nEnter 0 to try again 1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        switch (main_exit) {
            case 0:
                delete();
                break;
            case 1:
                Menu();
                break;
            case 2:
                quit();
                break;
            default:
                printf("\nInvalid!\a");
                goto returnMainExit;
        }
    } else{

        printf("\nEnter 1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        switch (main_exit) {
            case 1:
                Menu();
                break;
            case 2:
                quit();
                break;
            default:
                printf("\nInvalid!\a");
                sleep(1);
                exit(0);
        }

    }

}
void view_list() {
    FILE *view_listFile;
    int test = 0;
    view_listFile = fopen("record.txt", "r");
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\t\tDEPOSIT MONEY\n");
    while (fscanf(view_listFile, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", &add.acc_no, add.name, &add.DOB.month,
                  &add.DOB.day, &add.DOB.year, &add.age, add.address, &add.phone, &add.amount, &add.deposit.month,
                  &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf\t\t%.2f", add.acc_no, add.name, add.address, add.phone,add.amount);
        test++;
    }
    fclose(view_listFile);
    if (test == 0) {
        system("cls");
        printf("\nNO RECORD\n");
    }
    returnMainExit:
    printf("\n\nEnter 1 to return to main menu and 2 to exit:");
    scanf("%d", &main_exit);
    switch (main_exit) {
        case 1:
            Menu();
            break;
        case 2:
            quit();
            break;
        default:
            printf("\nInvalid!\a");
            goto returnMainExit;
    }
}
void atm() {

        bool again = true;
        int AtmFeatureOption;
        int returnChoise;
        int accountNo;
        int wrongAccNo,test = 0;
        FILE *Oldrecords,*NewRecords;

    Oldrecords = fopen("record.txt","r");
    tryAgainAccNO:
    printf("which account do you choose");
    scanf("%d",&accountNo);
    while (fscanf(Oldrecords, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", &add.acc_no, add.name, &add.DOB.month, &add.DOB.day,
                  &add.DOB.year, &add.age, add.address, &add.phone, &add.amount, &add.deposit.month, &add.deposit.day,
                  &add.deposit.year) != EOF){
        if (add.acc_no == accountNo){
            AtmFeatures = add;
            test = 1 ;
        }
    }
    if (test != 1){
        system("cls");
        system("color 4");
        printf("the account you entered isn't matched");
        system("cls");
        system("color 7");
        printf("what do you want ?(1 to try again 2 to exit)");
        scanf("%d", &wrongAccNo);
        switch (wrongAccNo) {
            case 1:
                goto tryAgainAccNO;
            case 2:
                quit();
        }
    }
    fclose(Oldrecords);

        login();
        mainMenu(AtmFeatures.acc_no);
        while (again) {

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Your Selection:\t");
            scanf("%d", &AtmFeatureOption);
            system("cls");

            switch (AtmFeatureOption) {
                case 1:
                    checkBalance(AtmFeatures.amount);
                    break;
                case 2:
                    AtmFeatures.amount = moneyDeposit(AtmFeatures.amount);
                    break;
                case 3:
                    AtmFeatures.amount = moneyWithdraw(AtmFeatures.amount);
                    break;
                case 4:
                    fclose(Oldrecords);
                    fclose(NewRecords);
                    remove("new.txt");
                    backMenu();
                    break;
                case 5:
                    fclose(Oldrecords);
                    fclose(NewRecords);
                    remove("new.txt");
                    MenuExit();
                    break;
                default:
                    printf("+++!!!You selected invalid number!!!+++\n");
                    break;
            }

            Oldrecords = fopen("record.txt","r");
            NewRecords = fopen("new.txt","w");
            while (fscanf(Oldrecords, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", &add.acc_no, add.name, &add.DOB.month, &add.DOB.day,
                          &add.DOB.year, &add.age, add.address, &add.phone, &add.amount, &add.deposit.month, &add.deposit.day,
                          &add.deposit.year) != EOF){
                if (add.acc_no == accountNo){
                    fprintf(NewRecords, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", AtmFeatures.acc_no, AtmFeatures.name,
                            AtmFeatures.DOB.month,
                            AtmFeatures.DOB.day, AtmFeatures.DOB.year, AtmFeatures.age, AtmFeatures.address,
                            AtmFeatures.phone, AtmFeatures.amount,
                            AtmFeatures.deposit.month, AtmFeatures.deposit.day, AtmFeatures.deposit.year);
                }else{
                    fprintf(NewRecords, "%d %s %d.%d.%d %d %s %lf %f %d.%d.%d\n", add.acc_no, add.name,
                            add.DOB.month,
                            add.DOB.day, add.DOB.year, add.age, add.address,
                            add.phone, add.amount,
                            add.deposit.month, add.deposit.day, add.deposit.year);
                }
            }
            fclose(Oldrecords);
            fclose(NewRecords);
            remove("record.txt");
            rename("new.txt","record.txt");

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Would you like to do another transaction:\n");
            printf("< 1 > Yes\n");
            printf("< 2 > No\n");
            scanf("%d", &returnChoise);
            system("CLS");


            if (returnChoise == 2) {
                again = false;
                MenuExit();

            } else {
                mainMenu(AtmFeatures.acc_no);
            }
        }

}
void quit() {
        system("cls");
        for (i = 3; i > 0; i--) {
            printf("Thank you!\n");
            printf("%d second for exit", i);
            sleep(1);
            system("cls");
        }
        exit(0);
}
void Menu() {
        int choise;
        system("cls");
        system("color 7");
        printf("\n\n\t\t\t       BANK MANAGEMENT SYSTEM");
        printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\n\t\t[1] Create new account\n\t\t[2] Update existing account\n\t\t[3] Online Transactions\n\t\t[4] Remove existing account\n\t\t[5] View customer's list\n\t\t[6] ATM Feature\n\t\t[7] Exit\n\n\n\t\t Enter your choice:");
        scanf("%d", &choise);
        switch (choise) {
            case 1:
                new_account();
                break;
            case 2:
                edit();
                break;
            case 3:
                transact();
                break;
            case 4:
                delete();
                break;
            case 5:
                view_list();
                break;
            case 6:
                atm();
                break;
            case 7://main menu exit
                system("cls");
                printf("are you sure want to exit");
            ReturnExit:
                scanf("%s", &surety);
                if (strcmp(surety, "yes") == 0) {
                    system("cls");
                    quit();
                } else if (strcmp(surety, "no") == 0) {
                    system("cls");
                    for (i = 3; i > 0; i--) {
                        printf("you are going to go menu in %d second", i);
                        sleep(1);
                        system("cls");
                    }
                    Menu();
                } else {
                    printf("please enter a correct answer (yes or no)");
                    goto ReturnExit;
                }
                break;
            default:
                system("cls");
                system("color 4");
                printf("\n\n\t\tPLEASE ENTER A CORRECT ANSWER");
                sleep(2);
                Menu();
                break;
        }
}
int main() {

        printf("***** ETERNAL BANK ***** \n ---------------------------------------------\n");
        retry_login:
        printf("Enter your name : ");
        scanf("%s", name);
        printf("\n");
        printf("Enter your account password : ");
        scanf("%d", &accountNo);

        if (strcmp(name, "admin") == 0 && accountNo == 1234) {
            printf("\n\nPassword Match!\nLOADING");
            for (i = 0; i <= 6; i++) {
                fordelay(100000000);
                printf(". ");
            }
            printf("\n");
//        system("pause");
//        system("cls");
            Menu();
        } else {
            printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d", &main_exit);
            if (main_exit == 1) {
                system("cls");
                goto retry_login;
            } else if (main_exit == 0) {
                quit();
            } else {
                printf("Invalid \n try again!!\a\a\a");
                system("cls");
                goto login_try;
            }
        }


        return 0;
}




