#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    char data;
    int col;
    struct node* link;
    struct node* link2;
};
struct node* create(char dat)
{
    struct node* temp = (struct node*)malloc(1*sizeof(struct node));
    temp->data = dat;
    temp->link = NULL;
    temp->link2 = NULL;
    temp->col = 0;

    return temp;
}
void display(struct node* root)
{
    if(root->col!=0)
    {
        cout<<"Cycle Detected\n"    ;
        exit(0);
    }
    else
    {
        cout<<root->data<<endl;
        root->col = 1;
        if(root->link!=NULL)
                display(root->link);
        if(root->link2!=NULL)
                display(root->link2);
    }
}

int main()
{
    struct node* a[6];
    a[0] = create('A');
    a[1] = create('B');
    a[2] = create('C');
    a[3] = create('D');
    a[4] = create('E');
    a[5] = create('F');


    //Creating link between nodes

    a[0]->link = a[2];
    a[1]->link = a[2];
    a[1]->link2 = a[3];
    a[2]->link = a[3];
    a[2]->link = a[4];
    a[3]->link = a[5];
    a[4]->link = a[5];
    a[5]->link = a[2];

    display(a[0]);

return 0;
}
