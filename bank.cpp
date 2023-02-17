#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int amount;
    struct Node *next;
    string phone;
    int id;
    string name;
};

int id = 0;

void insert(struct Node *&head, struct Node *&tail, string name, string phone)
{
    Node *n = new Node();
    cout << "Enter the amount to be added" << endl;
    int am;
    cin >> am;
    id++;
    n->id = id;
    n->next = NULL;
    n->amount = am;
    n->phone = phone;
    n->name = name;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = tail->next;
    }
}

void balance(struct Node *&head, int acc)
{
    Node *temp = head;
    while (temp->id != acc && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Enter Valid Account ID" << endl;
    }
    else
    {
        cout << temp->amount << endl;
    }
}

void add_money(struct Node *&head, int acc, int amoun)
{
    Node *temp = head;
    while (temp->id != acc)
    {
        temp = temp->next;
    }
    temp->amount = temp->amount + amoun;
}

void delete_money(struct Node *&head, int acc, int amount)
{
    Node *temp = head;
    while (temp->id != acc)
    {
        temp = temp->next;
    }

    if (amount > temp->amount)
    {
        cout << "Insufficient Balance" << endl;
    }
    else
    {
        temp->amount = temp->amount - amount;
    }
}

void delete_account(struct Node *&head, int acc)
{
    Node *temp = head;
    while (temp->id != acc)
    {
        temp = temp->next;
    }

    Node *g = head;
    if (temp == head)
    {
        head = head->next;
        g->next = NULL;
    }
    else
    {
        while (g->next != temp)
        {
            g = g->next;
        }
        g->next = temp->next;
        temp->next = NULL;
    }
}

void display(struct Node *head, struct Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << " has " << temp->amount << " rupee with ID number " << temp->id << " " << endl;
        ;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Welcome to betanode bank" << endl;
    int t;
    t = -1;
    struct Node *head = NULL;
    struct Node *tail = NULL;
    while (t != 100)
    {
        cout << "For Opening new account press 1 and then press enter" << endl;
        cout << "If you have account press 2 and then press enter" << endl;
        cout << "to exit press 100 and then press enter" << endl;
        int n;
        cin >> n;

        while (n != 1 && n != 2 && n != 100)
        {
            cout << "Enter valid key" << endl;
            cin >> n;
        }
        if (n == 1)
        {
            string name;
            string phone;

            cout << "Enter Your Name and press enter" << endl;
            cin >> name;
            // cout << "Enter phone number and press enter" << endl;
            // cin >> phone;
            // while(phone.length()<10){
            // cout<<"Enter Valid Phone Number"<<endl;
            // cin>>phone;
            //}
            insert(head, tail, name, "phone");
            cout << "Your ID number is " << id << endl;
            cout << endl;
            cout << "Thank You , Returning to Main Menu" << endl;
            cout << endl;
        }
        else if (n == 2)
        {
            int acc_id;
            cout << "Enter account ID and then press enter" << endl;
            cin >> acc_id;
            int b;
            cout << "For checking bank balance press 1 and then press enter" << endl;
            cout << "For adding money press 2 and then press enter" << endl;
            cout << "To withdraw money press 3 and then press enter" << endl;
            cout << "To delete account press 4 and then press enter" << endl;
            cin >> b;
            while (b != 1 && b != 2 && b != 3 && b != 4)
            {
                cout << "Enter valid key" << endl;
                cin >> b;
            }
            if (b == 1)
            {
                balance(head, acc_id);
            }
            else if (b == 2)
            {
                cout << "Enter amount to be added" << endl;
                int amount;
                cin >> amount;
                add_money(head, acc_id, amount);
            }
            else if (b == 3)
            {
                cout << "Enter amount to be withdraw" << endl;
                int amount;
                cin >> amount;
                delete_money(head, acc_id, amount);
            }
            else if (b == 4)
            {
                delete_account(head,acc_id);
            }
        }
        display(head, tail);
        t = n;
    }

    return 0;
}