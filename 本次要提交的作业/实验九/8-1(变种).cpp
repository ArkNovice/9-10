#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];
	char face[10];
};
void FillCard(struct CARD wCard[], char *wFace[], char *wSuit[])
{
	int i;
	for(i=0;i<52;i++)
	{
	strcpy(wCard[i].suit, wSuit[i/13]);
	strcpy(wCard[i].face, wFace[i%13]);
	}
}
void Shuffle(struct CARD *wCard)
{
	int i, j;
	struct CARD temp;
	for(i=0;i<52;i++)
	{
		j=rand()%52;
		temp=wCard[i];
		wCard[i]=wCard[j];
		wCard[j]=temp;
	}
}
void Deal(struct CARD *wCard)
{
	int i;
	for(i=0;i<52;i++)
	{
		printf("%10s%10s\n", wCard[i].suit, wCard[i].face);
	}
}
int main()
{
	char *suit[]={"Spades", "Hearts", "Clubs", "Diamonds"};
	char *face[]={"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	struct CARD card[52];
	srand(time(NULL));
	FillCard(card, face, suit);
	Shuffle(card);
	Deal(card);
	return 0;
}
