#include<stdio.h>
#include<conio.h>
#include<string.h>

void writetoxy(char msg[50],int x,int y)
{
    gotoxy(x,y);
    printf(msg);
}
void writetoid(int id,int x,int y)
{
    gotoxy(x,y);
    printf("%c",id);
}
struct CourseOperations
{
    int cid;
    char cname[20];
    char ctype[15];
    char content[15];
    int duration,fees;
};
struct CourseId
{
    int courseid;
};
struct Students
{
    int rn;
    char sname[20];
    char fname[20];
    char contact[20];
    char address[30];
    int s_cid;
    char s_cname[20];
    char s_ctype[15];
    int s_cduration,s_cfees;
};
struct StudentId
{
    int sid;
};
void box()
{
    int x,y;
    for(x=1;x<=79;x++)
    {
	writetoid(205,x,1);
	writetoid(205,x,25);
    }
    for(y=1;y<=24;y++)
    {
	writetoid(186,1,y);
	writetoid(186,79,y);
    }
    writetoid(201,1,1);
    writetoid(187,79,1);
    writetoid(188,79,25);
    writetoid(200,1,25);
    writetoid(204,1,5);
    writetoid(185,79,5);
    writetoxy("BHARTI COMPUTER EDUCATION",28,2);
    writetoxy("MAIN MARKET NAJAFGARH NEW DELHI-110043",23,3);
    for(x=1;x<=79;x++)
    {
	writetoid(205,x,5);
    }
    writetoid(204,1,5);
    writetoid(185,79,5);
}
void MainMenu()
{
    int x,y;
    for(x=1;x<=79;x++)
    {
	writetoid(205,x,7);
    }
    writetoxy("MAIN MENU",35,6);
    //second line corners
    writetoid(204,1,7);
    writetoid(185,79,7);
}
// Function for adding course //
void AddCourse()
{
    FILE *fp,*fp1;
    CourseOperations co;
    CourseId ci;
    writetoxy("Course id                    :",15,10);
    writetoxy("Course Name                  :",15,12);
    writetoxy("Course Type                  :",15,14);
    writetoxy("(Diploma/Certificate/Crash)",15,15);
    writetoxy("Course Content               :",15,17);
    writetoxy("(Ex: Programming,MS Office)",15,18);
    writetoxy("Duration(in months)	   :",15,20);
    writetoxy("Total Fees                   :",15,22);

    fp1=fopen("COURSE.TXT","r");
    fseek(fp1,0,2);
    int rec=ftell(fp1)/sizeof(CourseOperations);
    fseek(fp1,0,0);
    fclose(fp1);

    if(rec==0)
    {
	ci.courseid=101;
    }
    else
    {
	fp=fopen("COURSEID.TXT","r");
	fread(&ci,sizeof(CourseId),1,fp);
	fclose(fp);
	ci.courseid+=1;
    }
    char ch;
    int x,y;
    fp1=fopen("COURSE.TXT","a");
    co.cid=ci.courseid;
    gotoxy(52,10);
    printf("%d",co.cid);
    gotoxy(52,12);
    fflush(stdin);
    gets(co.cname);
    gotoxy(52,14);
    fflush(stdin);
    gets(co.ctype);
    gotoxy(52,17);
    fflush(stdin);
    gets(co.content);
    writetoxy("months",54,20);
    gotoxy(52,20);
    scanf("%d",&co.duration);
    writetoxy("Rs.",52,22);
    gotoxy(55,22);
    scanf("%d",&co.fees);
    for(x=68;x<=77;x++)
    {
	writetoid(196,x,20);
	writetoid(196,x,23);
    }
    writetoid(218,68,20);
    writetoid(191,77,20);
    for(y=21;y<=23;y++)
    {
	writetoid(179,68,y);
	writetoid(179,77,y);
    }
    writetoid(217,77,23);
    writetoid(192,68,23);
    writetoxy("Save it?",69,21);
    writetoxy("(y/n)",70,22);
    ch=getche();
    if(ch=='y')
    {
	fwrite(&co,sizeof(CourseOperations),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
}
// Function to display course list //
void DisplayCourse()
{
    FILE* fp;
    CourseOperations co;
    int x,y;
    writetoxy("COURSE ID",3,8);
    for(y=7;y<=25;y++)
    {
	writetoid(179,13,y);
	writetoid(179,37,y);
	writetoid(179,52,y);
	writetoid(179,65,y);
    }
    writetoid(209,13,7);
    writetoid(207,13,25);
    writetoid(209,37,7);
    writetoid(207,37,25);
    writetoid(209,52,7);
    writetoid(207,52,25);
    writetoid(209,65,7);
    writetoid(207,65,25);
    writetoxy("COURSE NAME",20,8);
    writetoxy("TYPE",43,8);
    writetoxy("DURATION",55,8);
    writetoxy("FEES",70,8);
    for(x=1;x<=79;x++)
    {
	writetoid(196,x,9);
    }
    writetoid(199,1,9);
    writetoid(182,79,9);
    writetoid(197,13,9);
    writetoid(197,37,9);
    writetoid(197,52,9);
    writetoid(197,65,9);

    fp=fopen("COURSE.TXT","r");
    fseek(fp,0,2);
    int rec=ftell(fp)/sizeof(CourseOperations);
    fseek(fp,0,0);

    int y1=10;
    int x1;
    int i;
    for(i=1;i<=rec;i++)
    {
	x1=5;
	fread(&co,sizeof(CourseOperations),1,fp);
	gotoxy(x1,y1);
	printf("%d",co.cid);
	x1+=12;
	gotoxy(x1,y1);
	printf("%s",co.cname);
	x1+=23;
	gotoxy(x1,y1);
	printf("%s",co.ctype);
	x1+=15;
	gotoxy(x1,y1);
	printf("%d",co.duration);
	writetoxy("months",57,y1);
	writetoxy("Rs.",68,y1);
	x1+=16;
	gotoxy(x1,y1);
	printf("%d",co.fees);
	y1+=1;
    }
}
// Function to Modify Course Details //
void ModifyCourse()
{
    FILE *fp,*fp1;
    CourseOperations co;
    int id,i,x,y;
    char ch;
    char name[20],type[15],content[15];
    int duration,fees;

    fp1=fopen("COURSE.TXT","r");
    fseek(fp1,0,2);
    int rec=ftell(fp1)/sizeof(CourseOperations);
    fseek(fp1,0,0);

    fp=fopen("CTEMP.TXT","w");
    writetoxy("Enter Course id : ",30,14);
    scanf("%d",&id);

    int flag=0;
    for(i=1;i<=rec;i++)
    {
	fread(&co,sizeof(CourseOperations),1,fp1);
	if(id==co.cid)
	{
	    flag=1;
	    clrscr();
	    box();
	    for(x=1;x<=79;x++)
	    {
		writetoid(205,x,7);
	    }
	    writetoid(204,1,7);
	    writetoid(185,79,7);
	    writetoxy("ENTER NEW DETAILS",32,6);
	    writetoxy("Course id                    :",15,10);
	    writetoxy("Course Name                  :",15,12);
	    writetoxy("Course Type                  :",15,14);
	    writetoxy("(Diploma/Certificate/Crash)",15,15);
	    writetoxy("Course Content               :",15,17);
	    writetoxy("(Ex: Programming,MS Office)",15,18);
	    writetoxy("Duration(in months)	   :",15,20);
	    writetoxy("Total Fees                   :",15,22);
	    gotoxy(52,10);
	    printf("%d",co.cid);
	    gotoxy(52,12);
	    fflush(stdin);
	    gets(name);
	    gotoxy(52,14);
	    fflush(stdin);
	    gets(type);
	    gotoxy(52,17);
	    fflush(stdin);
	    gets(content);
	    writetoxy("months",54,20);
	    gotoxy(52,20);
	    scanf("%d",&duration);
	    writetoxy("Rs.",52,22);
	    gotoxy(55,22);
	    scanf("%d",&fees);
	    for(x=68;x<=77;x++)
	    {
		writetoid(196,x,20);
		writetoid(196,x,23);
	    }
	    writetoid(218,68,20);
	    writetoid(191,77,20);
	    for(y=21;y<=23;y++)
	    {
		writetoid(179,68,y);
		writetoid(179,77,y);
	    }
	    writetoid(217,77,23);
	    writetoid(192,68,23);
	    writetoxy("Save it?",69,21);
	    writetoxy("(y/n)",70,22);
	    ch=getche();
	    if(ch=='y')
	    {
		strcpy(co.cname,name);
		strcpy(co.ctype,type);
		strcpy(co.content,content);
		co.duration=duration;
		co.fees=fees;
		fwrite(&co,sizeof(CourseOperations),1,fp);
	    }
	    else if(ch=='n')
	    {
		fwrite(&co,sizeof(CourseOperations),1,fp);
	    }
	}
	else
	{
	    fwrite(&co,sizeof(CourseOperations),1,fp);
	}
    }
    if(flag==0)
    {
	writetoxy("InValid Id!!",34,18);
    }
    fclose(fp);
    fclose(fp1);
    remove("COURSE.TXT");
    rename("CTEMP.TXT","COURSE.TXT");
}
//Function to display particular course details//
void KnowTheCourse()
{
    FILE *fp1;
    CourseOperations co;
    fp1=fopen("COURSE.TXT","r");
    fseek(fp1,0,2);
    int rec=ftell(fp1)/sizeof(CourseOperations);
    fseek(fp1,0,0);

    int id,x,i;
    writetoxy("Enter Course id : ",30,14);
    scanf("%d",&id);

    int flag=0;
    for(i=1;i<=rec;i++)
    {
	fread(&co,sizeof(CourseOperations),1,fp1);
	if(id==co.cid)
	{
	    flag=1;
	    clrscr();
	    box();
	    for(x=1;x<=79;x++)
	    {
		writetoid(205,x,7);
	    }
	    writetoid(204,1,7);
	    writetoid(185,79,7);
	    writetoxy("COURSE DETAILS",34,6);
	    writetoxy("Course id                    :",15,10);
	    writetoxy("Course Name                  :",15,12);
	    writetoxy("Course Type                  :",15,14);
	    writetoxy("(Diploma/Certificate/Crash)",15,15);
	    writetoxy("Course Content               :",15,17);
	    writetoxy("(Ex: Programming,MS Office)",15,18);
	    writetoxy("Duration(in months)	   :",15,20);
	    writetoxy("Total Fees                   :",15,22);

	    gotoxy(52,10);
	    printf("%d",co.cid);
	    gotoxy(52,12);
	    printf("%s",co.cname);
	    gotoxy(52,14);
	    printf("%s",co.ctype);
	    gotoxy(52,17);
	    printf("%s",co.content);
	    writetoxy("months",54,20);
	    gotoxy(52,20);
	    printf("%d",co.duration);
	    writetoxy("Rs.",52,22);
	    gotoxy(55,22);
	    printf("%d",co.fees);
	}
    }
    if(flag==0)
    {
	writetoxy("INVALID ID!!",35,19);
    }
    fclose(fp1);
}
//Function to DELETE a course//
void DeleteCourse()
{
    FILE *fp,*fp1;
    CourseOperations co;
    fp=fopen("COURSE.TXT","r");
    fseek(fp,0,2);
    int rec=ftell(fp)/sizeof(CourseOperations);
    fseek(fp,0,0);

    int id,flag=0,i;
    fp1=fopen("CTEMP.TXT","w");
    writetoxy("Enter Course id : ",30,14);
    scanf("%d",&id);

    for(i=1;i<=rec;i++)
    {
	fread(&co,sizeof(CourseOperations),1,fp);
	if(id!=co.cid)
	{
	    fwrite(&co,sizeof(CourseOperations),1,fp1);
	}
	else
	{
	    flag=1;
	}
    }
    if(flag==1)
    {
	writetoxy("Course Removed Successfully!!",28,20);
    }
    else
    {
	writetoxy("Invalid Course Id!!",31,19);
	writetoxy("Please try again!!",31,21);
    }
    fclose(fp);
    fclose(fp1);
    remove("COURSE.TXT");
    rename("CTEMP.TXT","COURSE.TXT");
}
//Function to display List of courses//
void CourseList()
{
    FILE* fp;
    CourseOperations co;
    int x,y;
    for(x=54;x<=78;x++)
    {
	writetoid(196,x,8);
	writetoid(196,x,24);
	writetoid(196,x,10);
    }
    for(y=8;y<=24;y++)
    {
	writetoid(179,54,y);
	writetoid(179,78,y);
	writetoid(179,58,y);
    }
    writetoid(218,54,8);
    writetoid(191,78,8);
    writetoid(217,78,24);
    writetoid(192,54,24);
    writetoid(194,58,8);
    writetoid(193,58,24);
    writetoid(195,54,10);
    writetoid(180,78,10);
    writetoid(197,58,10);
    writetoxy("ID",56,9);
    writetoxy("Course Name",63,9);

    fp=fopen("COURSE.TXT","r");
    fseek(fp,0,2);
    int rec=ftell(fp)/sizeof(CourseOperations);
    fseek(fp,0,0);

    int i;
    int x1,y1=11;
    for(i=1;i<=rec;i++)
    {
	x1=55;
	fread(&co,sizeof(CourseOperations),1,fp);
	gotoxy(x1,y1);
	printf("%d",co.cid);
	x1+=5;
	gotoxy(x1,y1);
	printf("%s",co.cname);
	y1+=1;
    }
}
void ClearCourseList()
{
    int x,y;
    for(x=54;x<=78;x++)
    {
	writetoxy(" ",x,8);
	writetoxy(" ",x,24);
	writetoxy(" ",x,10);
    }
    for(y=8;y<=24;y++)
    {
	writetoxy(" ",54,y);
	writetoxy(" ",78,y);
	writetoxy(" ",58,y);
    }
    writetoxy(" ",54,8);
    writetoxy(" ",78,8);
    writetoxy(" ",78,24);
    writetoxy(" ",54,24);
    writetoxy(" ",58,8);
    printf(" ",58,24);
    writetoxy(" ",54,10);
    writetoxy(" ",78,10);
    writetoxy(" ",58,10);
    writetoxy("   ",56,9);
    writetoxy("             ",63,9);
    int x1,y1;
    for(y1=11;y1<=22;y1++)
    {
	x1=55;
	writetoxy("   ",x1,y1);
	x1+=5;
	writetoxy("                  ",x1,y1);
    }
}
void smallbox()
{
    int x,y;
    for(x=51;x<=77;x++)
    {
	writetoid(196,x,19);
	writetoid(196,x,24);
    }
    for(y=19;y<=24;y++)
    {
	writetoid(179,51,y);
	writetoid(179,77,y);
    }
    writetoid(218,51,19);
    writetoid(191,77,19);
    writetoid(217,77,24);
    writetoid(192,51,24);
}
void StudentAdmission()
{
    FILE *fp,*fp1,*fp2;
    Students st;
    StudentId si;
    CourseOperations co;
    int cid,rec,rec1,x,y,i,flag=0;
    char ch;
    do
    {
	clrscr();
	box();
	for(x=1;x<=79;x++)
	{
	    writetoid(205,x,7);
	}
	writetoid(204,1,7);
	writetoid(185,79,7);
	writetoxy("ENTER STUDENT DETAILS",30,6);
	writetoxy("Roll Number         :",4,9);
	writetoxy("Student Name        :",4,11);
	writetoxy("Father's Name       :",4,13);
	writetoxy("Contact No.         :",4,15);
	writetoxy("Address	       :",4,17);
	writetoxy("(H.No.,landmark,City)",4,18);
	writetoxy("Course Id           :",4,21);

	fp=fopen("STUDENT.TXT","r");
	fseek(fp,0,2);
	rec=ftell(fp)/sizeof(Students);
	fseek(fp,0,0);
	fclose(fp);
	if(rec==0)
	{
	    si.sid=1;
	}
	else
	{
	    fp1=fopen("ID.TXT","r");
	    fread(&si,sizeof(StudentId),1,fp1);
	    fclose(fp1);
	    si.sid+=1;
	}
	fp=fopen("STUDENT.TXT","a");
	st.rn=si.sid;
	gotoxy(26,9);
	printf("%d",st.rn);
	gotoxy(26,11);
	fflush(stdin);
	gets(st.sname);
	gotoxy(26,13);
	fflush(stdin);
	gets(st.fname);
	gotoxy(26,15);
	fflush(stdin);
	gets(st.contact);
	gotoxy(26,17);
	fflush(stdin);
	gets(st.address);
	CourseList();
	gotoxy(27,21);
	scanf("%d",&cid);
	ClearCourseList();
	fp1=fopen("COURSE.TXT","r");
	fseek(fp1,0,2);
	rec1=ftell(fp1)/sizeof(CourseOperations);
	fseek(fp1,0,0);
	flag=0;
	for(i=1;i<=rec1;i++)
	{
	    fread(&co,sizeof(CourseOperations),1,fp1);
	    if(cid==co.cid)
	    {
		flag=1;
		break;
	    }
	}
	fclose(fp1);
	if(flag==1)
	{
	    smallbox();
	    writetoxy("Course Details",56,20);
	    writetoxy("Name : ",52,21);
	    gotoxy(59,21);
	    printf("%s",co.cname);
	    writetoxy("Duration : ",52,22);
	    gotoxy(62,22);
	    printf("%d months",co.duration);
	    writetoxy("Fees : ",52,23);
	    gotoxy(59,23);
	    printf("Rs. %d   ",co.fees);
	    writetoxy("Save it?(y/n) : ",32,24);
	    ch=getche();
	    if(ch=='y')
	    {
		st.s_cid=co.cid;
		strcpy(st.s_cname,co.cname);
		strcpy(st.s_ctype,co.ctype);
		st.s_cduration=co.duration;
		st.s_cfees=co.fees;
		fwrite(&st,sizeof(Students),1,fp);
		fclose(fp);
		fp2=fopen("ID.TXT","w");
		fwrite(&si,sizeof(StudentId),1,fp2);
		fclose(fp2);
	    }
	}
	else if(flag==0)
	{
	    writetoxy("INVALID COURSE ID!!",55,23);
	    getch();
	}
    }while(cid!=co.cid);
}
// Function for showing List of students //
void StudentsList()
{
    int x,y,rec,x1,y1;
    FILE* fp;
    Students st;
    for(x=1;x<=79;x++)
    {
	writetoid(196,x,9);
	writetoid(196,x,11);
    }
    writetoid(199,1,9);
    writetoid(182,79,9);
    writetoid(199,1,11);
    writetoid(182,79,11);

    for(y=7;y<=25;y++)
    {
	writetoid(179,33,y);
    }
    for(y=9;y<=25;y++)
    {
	writetoid(179,11,y);
	writetoid(179,45,y);
	writetoid(179,69,y);
    }
    writetoid(209,33,7);
    writetoid(207,33,25);
    writetoid(197,33,9);
    writetoid(207,11,25);
    writetoid(194,11,9);
    writetoid(194,45,9);
    writetoid(207,45,25);
    writetoid(194,69,9);
    writetoid(207,69,25);
    writetoid(197,11,11);
    writetoid(197,45,11);
    writetoid(197,69,11);
    writetoid(197,33,11);

    writetoxy("STUDENT DETAILS",11,8);
    writetoxy("COURSE ENROLLED",48,8);
    writetoxy("ROLL NO.",3,10);
    writetoxy("STUDENT NAME",16,10);
    writetoxy("COURSE ID",35,10);
    writetoxy("COURSE NAME",51,10);
    writetoxy("FEES",72,10);

    fp=fopen("STUDENT.TXT","r");
    fseek(fp,0,2);
    rec=ftell(fp)/sizeof(Students);
    fseek(fp,0,0);
    y1=12;
    for(int i=1;i<=rec;i++)
    {
	fread(&st,sizeof(Students),1,fp);
	x1=6;
	gotoxy(x1,y1);
	printf("%d",st.rn);
	x1+=10;
	gotoxy(x1,y1);
	printf("%s",st.sname);
	x1+=22;
	gotoxy(x1,y1);
	printf("%d",st.s_cid);
	x1+=10;
	gotoxy(x1,y1);
	printf("%s",st.s_cname);
	x1+=24;
	gotoxy(x1,y1);
	printf("%d",st.s_cfees);
	y1+=1;
    }
    fclose(fp);
}
//Function for details of a particular student//
void StudentDetails()
{
    FILE *fp;
    Students st;
    int roll,i,y,x;
    fp=fopen("STUDENT.TXT","r");
    fseek(fp,0,2);
    int rec=ftell(fp)/sizeof(Students);
    fseek(fp,0,0);
    writetoxy("Enter Roll number : ",27,13);
    scanf("%d",&roll);
    int flag=0;
    for(i=1;i<=rec;i++)
    {
	fread(&st,sizeof(Students),1,fp);
	if(roll==st.rn)
	{
	    flag=1;
	    clrscr();
	    box();
	    for(x=1;x<=79;x++)
	    {
		writetoid(205,x,7);
	    }
	    writetoid(204,1,7);
	    writetoid(185,79,7);
	    writetoxy("STUDENT DETAILS",33,6);
	    for(y=7;y<=25;y++)
	    {
		writetoid(179,41,y);
	    }
	    writetoid(209,41,7);
	    writetoid(207,41,25);
	    for(x=1;x<=79;x++)
	    {
		writetoid(196,x,9);
	    }
	    writetoid(197,41,9);
	    writetoid(199,1,9);
	    writetoid(182,79,9);
	    writetoxy("PERSONAL DETAILS",13,8);
	    writetoxy("COURSE DETAILS",52,8);
	    writetoxy("Roll Number   :  ",4,12);
	    writetoxy("Student Name  :  ",4,14);
	    writetoxy("Father's Name :  ",4,16);
	    writetoxy("Contact No.   :  ",4,18);
	    writetoxy("Address :  ",4,20);
	    writetoxy("Course id    :  ",44,12);
	    writetoxy("Course name  :  ",44,14);
	    writetoxy("Course Type  :  ",44,16);
	    writetoxy("Duration	:  ",44,18);
	    writetoxy("Total Fees   :  ",44,20);
	    gotoxy(20,12);
	    printf("%d",st.rn);
	    gotoxy(20,14);
	    printf("%s",st.sname);
	    gotoxy(20,16);
	    printf("%s",st.fname);
	    gotoxy(20,18);
	    printf("%s",st.contact);
	    gotoxy(14,20);
	    printf("%s",st.address);
	    gotoxy(59,12);
	    printf("%d",st.s_cid);
	    gotoxy(59,14);
	    printf("%s",st.s_cname);
	    gotoxy(59,16);
	    printf("%s",st.s_ctype);
	    gotoxy(59,18);
	    printf("%d months",st.s_cduration);
	    gotoxy(59,20);
	    printf("Rs. %d",st.s_cfees);
	}
    }
    if(flag==0)
    {
	writetoxy("Roll number not registered!!",25,20);
    }
    fclose(fp);
}
//Function for MODIFYING details of a student//
void ModifyStudent()
{
    FILE* fp,*fp1,*fp2;
    Students st;
    CourseOperations co;
    int rn,cid,i,y,j;
    char ch;
    fp1=fopen("STUDENT.TXT","r");
    fseek(fp1,0,2);
    int rec=ftell(fp1)/sizeof(Students);
    fseek(fp1,0,0);
    fp=fopen("TEMP.TXT","w");
    writetoxy("Enter Roll Number : ",28,14);
    scanf("%d",&rn);
    int flag=0;
    for(i=1;i<=rec;i++)
    {
	fread(&st,sizeof(Students),1,fp1);
	if(rn==st.rn)
	{
	    flag=1;
	    clrscr();
	    box();
	    int x;
	    for(x=1;x<=79;x++)
	    {
		writetoid(205,x,7);
	    }
	    writetoid(204,1,7);
	    writetoid(185,79,7);
	    writetoxy("ENTER NEW DETAILS",30,6);
	    writetoxy("Roll Number         :",4,9);
	    writetoxy("Student Name        :",4,11);
	    writetoxy("Father's Name       :",4,13);
	    writetoxy("Contact No.         :",4,15);
	    writetoxy("Address	       :",4,17);
	    writetoxy("(H.No.,landmark,City)",4,18);
	    writetoxy("Course Id           :",4,21);
	    gotoxy(26,9);
	    printf("%d",st.rn);
	    gotoxy(26,11);
	    fflush(stdin);
	    gets(st.sname);
	    gotoxy(26,13);
	    fflush(stdin);
	    gets(st.fname);
	    gotoxy(26,15);
	    fflush(stdin);
	    gets(st.contact);
	    gotoxy(26,17);
	    fflush(stdin);
	    gets(st.address);
	    CourseList();
	    gotoxy(27,21);
	    scanf("%d",&cid);
	    ClearCourseList();
	    fp2=fopen("COURSE.TXT","r");
	    fseek(fp2,0,2);
	    int rec1=ftell(fp2)/sizeof(CourseOperations);
	    fseek(fp2,0,0);
	    int flag1=0;
	    for(j=1;j<=rec1;j++)
	    {
		fread(&co,sizeof(CourseOperations),1,fp2);
		if(cid==co.cid)
		{
		    flag1=1;
		    break;
		}
	    }
	    if(flag1==1)
	    {
		for(x=51;x<=77;x++)
		{
		    writetoid(196,x,19);
		    writetoid(196,x,24);
		}
		for(y=19;y<=24;y++)
		{
		    writetoid(179,51,y);
		    writetoid(179,77,y);
		}
		writetoid(218,51,19);
		writetoid(191,77,19);
		writetoid(217,77,24);
		writetoid(192,51,24);
		writetoxy("Course Details",56,20);
		writetoxy("Name : ",52,21);
		gotoxy(59,21);
		printf("%s",co.cname);
		writetoxy("Duration : ",52,22);
		gotoxy(62,22);
		printf("%d months",co.duration);
		writetoxy("Fees : ",52,23);
		gotoxy(59,23);
		printf("Rs. %d   ",co.fees);
		writetoxy("Save it?(y/n) : ",30,24);
		ch=getche();
		if(ch=='y')
		{
		    st.s_cid=co.cid;
		    strcpy(st.s_cname,co.cname);
		    strcpy(st.s_ctype,co.ctype);
		    st.s_cduration=co.duration;
		    st.s_cfees=co.fees;
		    fwrite(&st,sizeof(Students),1,fp);
		}
		else if(ch=='n')
		{
		    fwrite(&st,sizeof(Students),1,fp);
		}
	    }
	    if(flag1==0)
	    {
		writetoxy("INVALID COURSE ID!!",55,23);
	    }
	}
	else
	{
	    fwrite(&st,sizeof(Students),1,fp);
	}
    }
    if(flag==0)
    {
	writetoxy("Roll Number not registered!!",26,20);
    }
    fclose(fp2);
    fclose(fp);
    fclose(fp1);
    remove("STUDENT.TXT");
    rename("TEMP.TXT","STUDENT.TXT");
}
//Function for DELETING a student record//
void RemoveStudent()
{
    FILE* fp,* fp1;
    Students st;
    int rn,i;
    fp=fopen("STUDENT.TXT","r");
    fseek(fp,0,2);
    int rec=ftell(fp)/sizeof(Students);
    fseek(fp,0,0);
    fp1=fopen("TEMP.TXT","w");
    writetoxy("Enter Roll Number : ",28,14);
    scanf("%d",&rn);
    int flag=0;
    for(i=1;i<=rec;i++)
    {
	fread(&st,sizeof(Students),1,fp);
	if(rn!=st.rn)
	{
	    fwrite(&st,sizeof(Students),1,fp1);
	}
	else
	{
	    flag=1;
	}
    }
    if(flag==1)
    {
	writetoxy("Student Removed Successfully!!",26,20);
    }
    else
    {
	writetoxy("Roll number not registered!!",26,20);
    }
    fclose(fp);
    fclose(fp1);
    remove("STUDENT.TXT");
    rename("TEMP.TXT","STUDENT.TXT");
}
//*****MAIN METHOD*****//
void main()
{
    clrscr();
    int x,y;
    char choice;
    box();
    writetoxy("WELCOME BACK ADMIN!!",31,14);
    getch();
    clrscr();
    clrscr();
    do
    {
	clrscr();
	box();
	MainMenu();
	writetoxy("1. STUDENT PORTAL",31,12);
	writetoxy("2. COURSE PORTAL",31,14);
	writetoxy("3. EXIT",31,16);
	writetoxy("Enter your choice : ",31,19);
	choice=getche();
	switch(choice)
	{
	    case '1':
		clrscr();
		box();
		char choice1;
		do
		{
		  clrscr();
		  box();
		  for(x=1;x<=79;x++)
		  {
		      writetoid(205,x,7);
		  }
		  writetoid(204,1,7);
		  writetoid(185,79,7);
		  writetoxy("STUDENT PORTAL",33,6);
		  writetoxy("1. STUDENT ADMISSION",30,10);
		  writetoxy("2. VIEW STUDENT DETAILS",30,12);
		  writetoxy("3. LIST OF STUDENTS",30,14);
		  writetoxy("4. MODIFY STUDENT DETAILS",30,16);
		  writetoxy("5. REMOVE A STUDENT",30,18);
		  writetoxy("6. RETURN TO MAIN MENU",30,20);
		  writetoxy("Enter your choice : ",30,23);
		  choice1=getche();
		  switch(choice1)
		  {
		      case '1':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("ENTER STUDENT DETAILS",30,6);
			  StudentAdmission();
			  getch();
			  clrscr();
			  break;
		      case '2':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("STUDENT DETAILS",33,6);
			  StudentDetails();
			  getch();
			  clrscr();
			  break;
		      case '3':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("LIST OF STUDENTS ENROLLED",29,6);
			  StudentsList();
			  getch();
			  clrscr();
			  break;
		      case '4':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("MODIFY STUDENT DETAILS",29,6);
			  ModifyStudent();
			  getch();
			  clrscr();
			  break;
		      case '5':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("REMOVE A STUDENT",31,6);
			  RemoveStudent();
			  getch();
			  clrscr();
			  break;
		      case '6':
			  break;
		  }
		}while(choice1!='6');
		getch();
		break;
	    case '2':
		clrscr();
		box();
		char choice2;
		do
		{
		  box();
		  for(x=1;x<=79;x++)
		  {
		      writetoid(205,x,7);
		  }
		  writetoid(204,1,7);
		  writetoid(185,79,7);
		  writetoxy("COURSE PORTAL",34,6);
		  writetoxy("1. ADD COURSE",33,9);
		  writetoxy("2. MODIFY COURSE",33,11);
		  writetoxy("3. DELETE COURSE",33,13);
		  writetoxy("4. DISPLAY COURSES",33,15);
		  writetoxy("5. KNOW THE COURSE",33,17);
		  writetoxy("6. RETURN TO MAIN MENU",33,19);
		  writetoxy("Enter your choice : ",33,22);
		  choice2=getche();
		  switch(choice2)
		  {
		      case '1':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("ENTER COURSE DETAILS",30,6);
			  AddCourse();
			  getch();
			  clrscr();
			  break;
		      case '2':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("MODIFY COURSE",34,6);
			  ModifyCourse();
			  getch();
			  clrscr();
			  break;
		      case '3':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("DELETE COURSE",34,6);
			  DeleteCourse();
			  getch();
			  clrscr();
			  break;
		      case '4':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("COURSES",35,6);
			  DisplayCourse();
			  getch();
			  clrscr();
			  break;
		      case '5':
			  clrscr();
			  box();
			  for(x=1;x<=79;x++)
			  {
			      writetoid(205,x,7);
			  }
			  writetoid(204,1,7);
			  writetoid(185,79,7);
			  writetoxy("KNOW THE COURSE",33,6);
			  KnowTheCourse();
			  getch();
			  clrscr();
			  break;
		      case '6':
			  break;
		  }
		}while(choice2!='6');
		getch();
		break;
	    case '3':
		clrscr();
		box();
		writetoxy("...THANK YOU...",33,15);
		break;
	}
    }
    while(choice!='3');
    getch();
}
