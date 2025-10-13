#include<stdio.h>
#include<string.h>


struct Hotel {
    int roomno;
    char name[20];
    int booked;
};

struct Hotel hotel[50];
int roomcount=0;

void addroom();
void displayroom();
void bookroom();
void cancelbooking();
void customerdetails();


int main()
{
    int choice;
    do
    {
        printf("\n===============================================\n");
        printf("              HOTEL MANAGEMENT SYSTEM           ");
        printf("\n===============================================\n");
        printf("1. Add Room\n");
        printf("2. Display Room\n");
        printf("3. Book Room\n");
        printf("4. Cancel Booking\n");
        printf("5. Customer Details\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
            addroom();
            break;

            case 2:
            displayroom();
            break;

            case 3:
            bookroom();
            break;

            case 4:
            cancelbooking();
            break;

            case 5:
            customerdetails();
            break;

            case 6:
            printf("Thank you for using my system !\n");
            break;

            default:
            printf("\nInvalid choice\n");
        }
        
    } while (choice != 6);
    return 0;
    
}


void addroom()
{
    int n;
    printf("Enter number of rooms to add: \n");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        printf("Enter room number:\n");
        scanf("%d", &hotel[roomcount].roomno);

        hotel[roomcount].booked = 0;

        roomcount++;
        printf("Room added succesfully! \n");
    }
}

void displayroom()
{
    if(roomcount==0)
    {
        printf("\n No rooms has been added\n");
    }


    printf("\n----------------------------------------\n");
    printf("| Room No |   Status    | Customer Name |\n");
    printf("----------------------------------------\n");

    for(int i =0;i<roomcount;i++)
    {
        printf("%d", hotel[i].roomno);
        if(hotel[i].booked==0)
        {
            printf("Available");
        }

        else 
        {
            printf("Booked");
        }
    }

}

    void bookroom()
    {
        int roomnumb;
        printf("\nEnter room no to book: ");
        scanf("%d", &roomnumb);

        for(int i =0 ;i<roomcount;i++)
        {
            if(hotel[i].roomno == roomnumb)
            {
                if(hotel[i].booked == 0)
                {
                    printf("Enter customers name: ");
                    scanf("%s", hotel[i].name);
                    hotel[i].roomno = 1;
                    printf("\nRoom succesfully booked");
                }
                else 
                {
                    printf("\nSorry, this room is already booked");
                }
              
            }
        }
    }


void cancelbooking()
{
    int roomnumb;
    printf("Enter room no to cancel booking: ");
    scanf("%d",roomnumb);

    for(int i =0 ; i<roomcount; i++)
    {
        if(hotel[i].roomno == roomnumb)
        {
            if(hotel[i].booked == 1)
            {
                hotel[i].booked = 0;
                printf("\n Booking cancel succesfully.");
            }
            else
            {
                printf("Room is not currently booked.");
            }
        }
    }
}


void customerdetails()
{
    int roomnumb;
    printf("Enter room number for details:");
    scanf("%d", &roomnumb);

    for (int i =0 ;i<roomcount;i++)
    {
        if(hotel[i].roomno==roomnumb)
        {
            if (hotel[i].booked == 1)
            {
                printf("\n Room numb is %d\n:", hotel[i].roomno);
                printf("\n customer name %s\n", hotel[i].name);
                printf("status: booked\n");

            }
            else{
                printf("\n room no: %d", hotel[i].roomno);
                printf("\nstatus: available (no customer)\n");

            }
        }
    }
}
