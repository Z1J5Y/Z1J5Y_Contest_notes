#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

char first = 0, second = 0, third = 0;

struct Card
{
    int data;
    Card* next;

    Card()
    {
        data = 0;
        next = NULL;
    }
};
Card* Sort(Card* head)
{
    Card* pCure = NULL, * temp, * current;
    for (; head->next != pCure; pCure = current->next)
    {
        current = head;
        for (; current->next->next != pCure; current = current->next)
        {
            if (current->next->data > current->next->next->data)
            {
                temp = current->next->next->next;
                current->next->next->next = current->next;
                current->next = current->next->next;
                current->next->next->next = temp;
            }
        }
    }
    return head;
}
void CreatList(Card*& head)
{
    head = new Card();
    Card* tail = head, * temp;
    for (int i = 0; i < 54; ++i)
    {
    tag:    int t = rand() % 54 + 1;
        for (Card* temp = head->next; temp; temp = temp->next)
            if (temp->data == t) goto tag;
        temp = new Card();
        temp->data = t;
        tail->next = temp;
        tail = tail->next;
    }
}
void DeliverCard(Card* head, Card*& p1, Card*& p2, Card*& p3)
{
    Card* temp = head->next;
    p1 = temp;
    Card* t1 = temp;
    for (int i = 0; i < 17; ++i)
        t1 = t1->next;
    p2 = t1->next;
    t1->next = NULL;

    t1 = p2;
    for (int i = 0; i < 17; ++i)
        t1 = t1->next;
    p3 = t1->next;
    t1->next = NULL;
}
void Insert(int data, Card*& list)
{
    Card* t = list->next, * in = new Card();
    in->data = data;
    in->next = t;
    list->next = in;
}
int toInt(std::string& a)
{
    int n, p;
    if (a[0] == '0') return 0;

    if (a.substr(0, 4) == "方块")
        n = 1;
    else if (a.substr(0, 4) == "梅花")
        n = 2;
    else if (a.substr(0, 4) == "红桃")
        n = 3;
    else if (a.substr(0, 4) == "黑桃")
        n = 4;
    else if (a == "小王") return 53;
    else if (a == "大王") return 54;

    if (a[4] <= '9' && a[4] >= '3'||a[4]=='1')
        p = 4 * (std::stoi(a.substr(4)) - 3);
    else if (a[4] == 'J') p = 4 * 8;
    else if (a[4] == 'Q') p = 4 * 9;
    else if (a[4] == 'K') p = 4 * 10;
    else if (a[4] == 'A') p = 4 * 11;
    else if (a[4] == '2') p = 4 * 12;

    return p + n;
}

void printCard(int a)
{
    if (a > 52)
    {
        if (a == 53) printf("小王 ");
        else if (a == 54) printf("大王 ");
    }
    else
    {
        switch (a % 4)
        {
        case 1:
            if ((a / 4 + 1) <= 8)
                printf("方块%d ", (a / 4 + 3));
            else if ((a / 4 + 1) == 9)  printf("方块J ");
            else if ((a / 4 + 1) == 10) printf("方块Q ");
            else if ((a / 4 + 1) == 11) printf("方块K ");
            else if ((a / 4 + 1) == 12) printf("方块A ");
            else if ((a / 4 + 1) == 13) printf("方块2 ");
            break;
        case 2:
            if ((a / 4 + 1) <= 8)
                printf("梅花%d ", (a / 4 + 3));
            else if ((a / 4 + 1) == 9)  printf("梅花J ");
            else if ((a / 4 + 1) == 10) printf("梅花Q ");
            else if ((a / 4 + 1) == 11) printf("梅花K ");
            else if ((a / 4 + 1) == 12) printf("梅花A ");
            else if ((a / 4 + 1) == 13) printf("梅花2 ");
            break;
        case 3:
            if ((a / 4 + 1) <= 8)
                printf("红桃%d ", (a / 4 + 3));
            else if ((a / 4 + 1) == 9)  printf("红桃J ");
            else if ((a / 4 + 1) == 10) printf("红桃Q ");
            else if ((a / 4 + 1) == 11) printf("红桃K ");
            else if ((a / 4 + 1) == 12) printf("红桃A ");
            else if ((a / 4 + 1) == 13) printf("红桃2 ");
            break;
        case 0:
            if ((a / 4 ) <= 8)
                printf("黑桃%d ", (a / 4 + 2));
            else if ((a / 4 ) == 9)  printf("黑桃J ");
            else if ((a / 4 ) == 10) printf("黑桃Q ");
            else if ((a / 4 ) == 11) printf("黑桃K ");
            else if ((a / 4 ) == 12) printf("黑桃A ");
            else if ((a / 4 ) == 13) printf("黑桃2 ");
            break;
        default:
            break;
        }
    }
}
void PlayCard(Card*& p1, Card*& p2, Card*& p3, Card*& CardHeap)
{
    Card* give = NULL, * prenode;
    std::string input;
    int givedata, predata = 0;
    bool flag, flagB, flagC;
    int pass = 0;
give:if (!p1->next && !p2->next || !p3->next && !p2->next || !p1->next && !p3->next) return;
    putchar('\n');
    for (Card* temp = p1->next; temp; temp = temp->next)
        printCard(temp->data);
    putchar('\n');

choose:printf("choose card to give(input 0 if you have no card to give):");
    std::cin >> input;
    givedata = toInt(input);
    if (!givedata) { pass++; goto t; }
    flag = false;
    for (Card* temp = p1->next, *pre = p1; temp; pre = temp, temp = temp->next)
    {
        if (temp->data == givedata)
        {
            flag = true;
            pre->next = temp->next;
            predata = givedata;
            Insert(temp->data, CardHeap);
            delete temp;
            pass = 0;
            break;
        }
    }
    if (!(p1->next))
    {
        if (!first)
            first = 'A';
        else if (!second)
        {
            if (first != 'A')
                second = 'A';
        }
    }
    if (!flag) { std::cout << "you don't have this card,please choose again\n"; goto choose; }
t:  if (pass == 2) { predata = 0; pass = 0; }

    //predata=givedata;
    flagB = false, flagC = false;

    prenode = p2;
    for (Card* temp = p2->next; temp; prenode = temp, temp = temp->next)
        if (temp->data > predata) { flagB = true; give = temp; break; }
    if (flagB)
    {
        std::cout << "B:";
        printCard(give->data);
        putchar('\n');
        Insert(give->data, CardHeap);
        predata = give->data;
        prenode->next = give->next;
        delete give;
        pass = 0;
    }
    else
    {
        printf("pass!\n");
        pass++;
    }
    if (!(p2->next))
    {
        if (!first)
            first = 'B';
        else if (!second)
        {
            if (first != 'B')
                second = 'B';
        }

    }
    if (pass == 2) { predata = 0; pass = 0; }
    prenode = p3;
    for (Card* temp = p3->next; temp; prenode = temp, temp = temp->next)
        if (temp->data > predata) { flagC = true; give = temp; break; }
    if (flagC)
    {
        std::cout << "C:";
        printCard(give->data);
        putchar('\n');
        Insert(give->data, CardHeap);
        predata = give->data;
        prenode->next = give->next;
        delete give;
        pass = 0;
    }
    else
    {
        printf("pass!\n");
        pass++;
    }
    if (!(p3->next))
    {
        if (!first)
            first = 'C';
        else if (!second)
        {
            if (first != 'C')
                second = 'C';
        }
    }
    if (pass == 2) { predata = 0; pass = 0; }
    goto give;

}


int main()
{
    srand(time(NULL));
    Card* head = NULL;
    CreatList(head);
    Card* A = new Card(), * B = new Card(), * C = new Card();
    A->data = B->data = C->data = 18;
    DeliverCard(head, A->next, B->next, C->next);

    for (Card* temp = A->next; temp; temp = temp->next)
        printCard(temp->data);
    putchar('\n');
    for (Card* temp = B->next; temp; temp = temp->next)
        printCard(temp->data);
    putchar('\n');
    for (Card* temp = C->next; temp; temp = temp->next)
        printCard(temp->data);

    A = Sort(A), B = Sort(B), C = Sort(C);
    putchar('\n');
    for (Card* temp = A->next; temp; temp = temp->next)
        printCard(temp->data);
    putchar('\n');
    for (Card* temp = B->next; temp; temp = temp->next)
        printCard(temp->data);
    putchar('\n');
    for (Card* temp = C->next; temp; temp = temp->next)
        printCard(temp->data);

    Card* CardHeap = new Card();

    PlayCard(A, B, C, CardHeap);
    third = 'A' + 'B' + 'C' - first - second;
    std::cout << std::endl << first << ' ' << second << ' ' << third << std::endl;

    std::cout << "turn of give cards:\n";
    for (Card* temp = CardHeap->next; temp; temp = temp->next)
        std::cout << temp->data << ' ';

    return 0;
}