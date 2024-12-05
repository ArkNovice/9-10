#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
struct STUDENT
{
	int studentID;
	char studentName[10];
	char studentSex[4];
	struct date timeOfEnter;
	int score[4];
};
struct STUDENT stu[30]={{1,"令狐冲","男",{1990,12,20},{90,83,72,82}},
						{2,"林平之","男",{1999,07,06},{78,92,88,78}},
						{3,"岳灵珊","女",{1999,07,06},{89,72,98,66}},
						{4,"任莹莹","女",{1999,07,06},{78,95,87,90}}};
int main()
{
	struct STUDENT *pt=stu;
	float sum[4], average[4];
	int i;
	char *scoreName[]={"Computer", "English", "Math", "Music"};
	for(i=0;i<4;i++)
	{
		sum[i]=0;
		for(pt=stu; pt<stu+30;pt++)
		{
			sum[i]=sum[i]+pt->score[i];
		}
		average[i]=sum[i]/4;
		printf("%10s:%4.2f\n", scoreName[i], average[i]);
	}
	return 0;
}
