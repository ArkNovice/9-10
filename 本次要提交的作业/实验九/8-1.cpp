#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];
	char face[10];
};
int main()
{
	char *Suit[]={"Spades", "Hearts", "Clubs", "Diamonds"};
	char *Face[]={"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	int i, j;
	struct CARD card[52], temp;
	for(i=0;i<52;i++)
	{
		strcpy(card[i].suit, Suit[i/13]);
		strcpy(card[i].face, Face[i%13]);
	}
	srand(time(NULL));
	for(i=0;i<52;i++)
	{
		j=rand()%52;
		temp=card[i];
		card[i]=card[j];
		card[j]=temp;
	}
	for(i=0;i<52;i++)
	{
		printf("%10s%10s\n", card[i].suit, card[i].face);
	}
	return 0;
}
