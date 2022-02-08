#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct card
{
    char number[6];
    char type[10];
}Card;

struct node
{
    int hand[52];
    struct node* next;
};
typedef struct node* list;

struct node1
{   
    int card;
    struct node1* next;
};
typedef struct node1* stack;

void Make_NULL_List(list* List)
{
    *List=NULL;
}

void Make_NULL_Stack(stack* Stack)
{
    *Stack = NULL;
}

stack Push(stack Stack, int data)
{
    stack temp = (stack)malloc( sizeof( struct node ) );
    if(temp==NULL)
    {
        printf("Out of Memory.");
        exit(0);
    }
    temp->card = data;
    temp->next = NULL;

    if(Stack==NULL) Stack = temp;
    else
    {
        temp->next = Stack;
        Stack = temp;  
    }

    return Stack;
}

stack Pop(stack Stack, int* data)
{
    stack temp = Stack;
    Stack = Stack->next;
    *data = temp->card;
    free(temp);

    return Stack;
}

list Round_Table(list List, int number)
{
    list cur = (list)malloc( sizeof( struct node ) );
    for(int i=0; i<number; i++)
    {
        list temp = (list)malloc( sizeof( struct node ) );
        if(temp==NULL)
        {
            printf("Out of Memory.\n");
            exit(0);
        }
        for(int i=0; i<52; i++) temp->hand[i] = -1;
        temp->next = NULL;

        if(List==NULL) List = temp;
        else
        {
            cur = List;
            while(cur->next!=NULL) cur = cur->next;
            cur->next = temp;
        }
    }
    cur = cur->next;
    cur->next = List;
    return List;
}

list Deal_Card(list List, stack Stack)
{
    if(Stack==NULL) return List;
    else
    {
        int temp;
        Stack = Pop(Stack, &temp);
        for(int i=0; i<52; i++)
        {
            if(List->hand[i]!=-1) continue;
            else
            {
                List->hand[i] = temp;
                break;
            }
        }
        List->next = Deal_Card(List->next, Stack);
    }

    return List;
}



int main()
{   
    int number;
    int deck[52];
    list Player; Make_NULL_List(&Player);
    stack Deck; Make_NULL_Stack(&Deck);
    Card Deck_of_Cards[52];

    do
    {
        printf("Number of player: "); scanf("%d", &number);
        if(number<=0) printf("This game need more than 0 player.\n");
        if(number>=53) printf("The deck only has 52 cards.\n");
    } while (number<=0 || number>=53);

    Player = Round_Table(Player, number);
    
    srand( (int)time(NULL) );
    int r;
    for(int i=0; i<52; i++)
    {
        goal: r =1+rand()%52;
        for(int j=0; j<i; j++)
        {
            if(r==deck[j]) goto goal;
        }
        deck[i] = r;
    }

    for(int i=51; i>=0; i--) Deck = Push(Deck, deck[i]);

    Player = Deal_Card(Player, Deck);

    for(int i=0; i<52; i++)
    {
        if(i+1==1 || i+1==14 || i+1==27 || i+1==40) strcpy(Deck_of_Cards[i].number, "Ace");
        if( (1+i%13)==11 ) strcpy(Deck_of_Cards[i].number, "Jack");
        if( (1+i%13)==12 ) strcpy(Deck_of_Cards[i].number, "Queen");
        if( (1+i%13)==13 ) strcpy(Deck_of_Cards[i].number, "King");
        char type[4];
        if( 2<=(1+i%13) && (1+i%13)<=10 )
        {
            itoa(1+i%13, type, 10);
            strcpy(Deck_of_Cards[i].number, type);
        }
        if(1<=i+1 && i+1<=13) strcpy(Deck_of_Cards[i].type, "Diamond");
        if(14<=i+1 && i+1<=26) strcpy(Deck_of_Cards[i].type, "Heart");
        if(27<=i+1 && i+1<=39) strcpy(Deck_of_Cards[i].type, "Club");
        if(40<=i+1 && i+1<=52) strcpy(Deck_of_Cards[i].type, "Spade");
    }

    list cur = Player;
    for(int i=0; i<number; i++)
    {
        printf("Player %2d's hand: ", i+1);
        for(int j=0; j<52; j++)
        {
            if(cur->hand[j]==-1) break;
            else printf("|%5s-%-7s| ", Deck_of_Cards[ cur->hand[j]-1 ].number, Deck_of_Cards[ cur->hand[j]-1 ].type);
        }
        printf("\n");
        cur = cur->next;
    }

    return 0;
}
