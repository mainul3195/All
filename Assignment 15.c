#include<stdio.h>

typedef struct
{
    char info[50];
    char police_station[20];
    char post_office[20];
    char district[20];
    char country[20];
} add;

typedef struct
{
    int day;
    int month;
    int year;
} date;

struct
{
    long long reg;
    char name[20];
    char session[10];
    add address;
    int age;
    int weight;
    int height;
    char result[5];
    float cgpa;
} student[100];

struct
{
    long long id;
    char name[20];
    char designation[20];
    char dep_name[10];
    add address;
    int age;
    int height;
    int weight;
    int salary;
    date joining_date;
} teacher[100];

struct
{
    long long id;
    char name[20];
    char designation[20];
    char office_name[10];
    add address;
    int age;
    int height;
    int weight;
    int salary;
    date joining_date;
} officer[100];

struct
{
    long long id;
    char name[20];
    char designation[20];
    char office_name[10];
    add address;
    int age;
    int height;
    int weight;
    int salary;
    date joining_date;
} staff[100];

int main()
{
    int stu,t,s,o,i,j,m,x;
    long long y;
    printf("First enter required information\n-------------------------------\nNo. of student's information you want to enter: ");
    scanf("%d", &stu);
    printf("No. of teacher's information you want to enter: ");
    scanf("%d", &t);
    printf("No. of officer's information you want to enter: ");
    scanf("%d", &o);
    printf("No. of staff's information you want to enter: ");
    scanf("%d", &s);

    for(i=0; i<stu; i++)
    {
        printf("\n\nEnter the information of student %d\n----------------------------------\nRegistration No.\t: ",i+1);
        scanf("%lld", &student[i].reg);
        printf("Name\t: ");
        scanf(" %[^\n]",student[i].name);
        printf("Session\t: ");
        scanf(" %[^\n]",student[i].session);
        printf("Enter address: \n\tInfo: ");
        scanf(" %[^\n]",student[i].address.info);
        printf("\tPolice Station: ");
        scanf(" %[^\n]",student[i].address.police_station);
        printf("\tPost Office: ");
        scanf(" %[^\n]",student[i].address.post_office);
        printf("\tDistrict: ");
        scanf(" %[^\n]",student[i].address.district);
        printf("\tCountry: ");
        scanf(" %[^\n]",student[i].address.country);
        printf("Age\t: ");
        scanf("%d", &student[i].age);
        printf("Weight(in kg)\t: ");
        scanf("%d", &student[i].weight);
        printf("Height (in cm)\t: ");
        scanf("%d", &student[i].height);
        printf("Result\t: ");
        scanf(" %[^\n]",student[i].result);
        printf("CGPA\t: ");
        scanf("%f", &student[i].cgpa);
    }


    for(i=0; i<t; i++)
    {
        printf("\n\nEnter the information of teacher %d\n----------------------------------\nID No.\t: ",i+1);
        scanf("%lld", &teacher[i].id);
        printf("Name\t: ");
        scanf(" %[^\n]",teacher[i].name);
        printf("Designation\t: ");
        scanf(" %[^\n]",teacher[i].designation);
        printf("Department Name: ");
        scanf(" %[^\n]",teacher[i].dep_name);
        printf("Enter address: \n\tInfo: ");
        scanf(" %[^\n]",teacher[i].address.info);
        printf("\tPolice Station: ");
        scanf(" %[^\n]",teacher[i].address.police_station);
        printf("\tPost Office: ");
        scanf(" %[^\n]",teacher[i].address.post_office);
        printf("\tDistrict: ");
        scanf(" %[^\n]",teacher[i].address.district);
        printf("\tCountry: ");
        scanf(" %[^\n]",teacher[i].address.country);
        printf("Age\t: ");
        scanf("%d", &teacher[i].age);
        printf("Weight(in kg)\t: ");
        scanf("%d", &teacher[i].weight);
        printf("Height(in cm)\t: ");
        scanf("%d", &teacher[i].height);
        printf("Salary\t: ");
        scanf("%d", &teacher[i].salary);
        printf("Joining date (dd/mm/yyyy)\t: ");
        scanf("%d/%d/%d", &teacher[i].joining_date.day, &teacher[i].joining_date.month, &teacher[i].joining_date.year);
    }


    for(i=0; i<t; i++)
    {
        printf("\n\nEnter the information of officer %d\n----------------------------------\nID No.\t: ",i+1);
        scanf("%lld", &officer[i].id);
        printf("Name\t: ");
        scanf(" %[^\n]",officer[i].name);
        printf("Designation\t: ");
        scanf(" %[^\n]",officer[i].designation);
        printf("Office Name: ");
        scanf(" %[^\n]",officer[i].office_name);
        printf("Enter address: \n\tInfo: ");
        scanf(" %[^\n]",officer[i].address.info);
        printf("\tPolice Station: ");
        scanf(" %[^\n]",officer[i].address.police_station);
        printf("\tPost Office: ");
        scanf(" %[^\n]",officer[i].address.post_office);
        printf("\tDistrict: ");
        scanf(" %[^\n]",officer[i].address.district);
        printf("\tCountry: ");
        scanf(" %[^\n]",officer[i].address.country);
        printf("Age\t: ");
        scanf("%d", &officer[i].age);
        printf("Weight(in kg)\t: ");
        scanf("%d", &officer[i].weight);
        printf("Height(in cm)\t: ");
        scanf("%d", &officer[i].height);
        printf("Salary\t: ");
        scanf("%d", &officer[i].salary);
        printf("Joining date (dd/mm/yyyy)\t: ");
        scanf("%d/%d/%d", &officer[i].joining_date.day, &officer[i].joining_date.month, &officer[i].joining_date.year);
    }



    for(i=0; i<t; i++)
    {
        printf("\n\nEnter the information of staff %d\n----------------------------------\nID No.\t: ",i+1);
        scanf("%lld", &staff[i].id);
        printf("Name\t: ");
        scanf(" %[^\n]",staff[i].name);
        printf("Designation\t: ");
        scanf(" %[^\n]",staff[i].designation);
        printf("Office Name: ");
        scanf(" %[^\n]",staff[i].office_name);
        printf("Enter address: \n\tInfo: ");
        scanf(" %[^\n]",staff[i].address.info);
        printf("\tPolice Station: ");
        scanf(" %[^\n]",staff[i].address.police_station);
        printf("\tPost Office: ");
        scanf(" %[^\n]",staff[i].address.post_office);
        printf("\tDistrict: ");
        scanf(" %[^\n]",staff[i].address.district);
        printf("\tCountry: ");
        scanf(" %[^\n]",staff[i].address.country);
        printf("Age\t: ");
        scanf("%d", &staff[i].age);
        printf("Weight(in kg)\t: ");
        scanf("%d", &staff[i].weight);
        printf("Height(in cm)\t: ");
        scanf("%d", &staff[i].height);
        printf("Salary\t: ");
        scanf("%d", &staff[i].salary);
        printf("Joining date (dd/mm/yyyy)\t: ");
        scanf("%d/%d/%d", &staff[i].joining_date.day, &staff[i].joining_date.month, &staff[i].joining_date.year);
    }

    printf("\n\n**Thanks for entering the information**\n\nNo. of queries you want to perform: ");
    scanf("%d", &m);
    for(j=1; j<=m; j++)
    {
        printf("Enter value for x & y: ");
        scanf("%d %lld", &x, &y);
        switch(x)
        {
        case 1:
            for(i=0; i<stu; i++)
                if(student[i].reg==y)
                    break;
            if(i==stu)
            {
                printf("Match not found!\n\n");
                break;
            }
            printf("\n\nRegistration No.\t: %lld\n",student[i].reg);
            printf("Name\t: ");
            puts(student[i].name);
            printf("Session\t: ");
            puts(student[i].session);
            printf("Address: \n\tInfo: ");
            puts(student[i].address.info);
            printf("\tPolice Station: ");
            puts(student[i].address.police_station);
            printf("\tPost Office: ");
            puts(student[i].address.post_office);
            printf("\tDistrict: ");
            puts(student[i].address.district);
            printf("\tCountry: ");
            puts(student[i].address.country);
            printf("Age\t: %d\n", student[i].age);
            printf("Weight(in kg)\t: %d\n", student[i].weight);
            printf("Height (in cm)\t: %d\n", student[i].height);
            printf("Result\t: ");
            puts(student[i].result);
            printf("CGPA\t: %.2f\n", student[i].cgpa);
            break;

        case 2:
            for(i=0; i<t; i++)
                if(teacher[i].id==y)
                    break;
            if(i==t)
            {
                printf("Match not found!\n\n");
                break;
            }
            printf("\n\nRegistration No.\t: %lld\n",teacher[i].id);
            printf("Name\t: ");
            puts(teacher[i].name);
            printf("Designation\t: ");
            puts(teacher[i].designation);
            printf("Department Name: ");
            puts(teacher[i].dep_name);
            printf("Enter address: \n\tInfo: ");
            printf("Address: \n\tInfo: ");
            puts(teacher[i].address.info);
            printf("\tPolice Station: ");
            puts(teacher[i].address.police_station);
            printf("\tPost Office: ");
            puts(teacher[i].address.post_office);
            printf("\tDistrict: ");
            puts(teacher[i].address.district);
            printf("\tCountry: ");
            puts(teacher[i].address.country);
            printf("Age\t: %d\n", teacher[i].age);
            printf("Weight(in kg)\t: %d\n", teacher[i].weight);
            printf("Height (in cm)\t: %d\n", teacher[i].height);
            printf("Salary\t: %d", teacher[i].salary);
            printf("Joining date (dd/mm/yyyy)\t: %d/%d/%d", &teacher[i].joining_date.day, &teacher[i].joining_date.month, &teacher[i].joining_date.year);
            break;


        case 3:
            for(i=0; i<o; i++)
                if(officer[i].id==y)
                    break;
            if(i==o)
            {
                printf("Match not found!\n\n");
                break;
            }
            printf("\n\nRegistration No.\t: %lld\n",officer[i].id);
            printf("Name\t: ");
            puts(officer[i].name);
            printf("Designation\t: ");
            puts(officer[i].designation);
            printf("Office Name: ");
            puts(officer[i].office_name);
            printf("Enter address: \n\tInfo: ");
            printf("Address: \n\tInfo: ");
            puts(officer[i].address.info);
            printf("\tPolice Station: ");
            puts(officer[i].address.police_station);
            printf("\tPost Office: ");
            puts(officer[i].address.post_office);
            printf("\tDistrict: ");
            puts(officer[i].address.district);
            printf("\tCountry: ");
            puts(officer[i].address.country);
            printf("Age\t: %d\n", officer[i].age);
            printf("Weight(in kg)\t: %d\n", officer[i].weight);
            printf("Height (in cm)\t: %d\n", officer[i].height);
            printf("Salary\t: %d", officer[i].salary);
            printf("Joining date (dd/mm/yyyy)\t: %d/%d/%d", &officer[i].joining_date.day, &officer[i].joining_date.month, &officer[i].joining_date.year);
            break;

        case 4:
            for(i=0; i<s; i++)
                if(staff[i].id==y)
                    break;
            if(i==s)
            {
                printf("Match not found!\n\n");
                break;
            }
            printf("\n\nRegistration No.\t: %lld\n",staff[i].id);
            printf("Name\t: ");
            puts(staff[i].name);
            printf("Designation\t: ");
            puts(staff[i].designation);
            printf("Office Name: ");
            puts(staff[i].office_name);
            printf("Enter address: \n\tInfo: ");
            printf("Address: \n\tInfo: ");
            puts(staff[i].address.info);
            printf("\tPolice Station: ");
            puts(staff[i].address.police_station);
            printf("\tPost Office: ");
            puts(staff[i].address.post_office);
            printf("\tDistrict: ");
            puts(staff[i].address.district);
            printf("\tCountry: ");
            puts(staff[i].address.country);
            printf("Age\t: %d\n", staff[i].age);
            printf("Weight(in kg)\t: %d\n", staff[i].weight);
            printf("Height (in cm)\t: %d\n", staff[i].height);
            printf("Salary\t: %d", staff[i].salary);
            printf("Joining date (dd/mm/yyyy)\t: %d/%d/%d", &staff[i].joining_date.day, &staff[i].joining_date.month, &staff[i].joining_date.year);
            break;
        }
    }
    return 0;
}

