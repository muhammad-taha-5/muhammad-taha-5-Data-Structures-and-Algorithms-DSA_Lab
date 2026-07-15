#include<iostream>
using namespace std;

struct node
{
    int PlayerID;
    int Score;
    node* next;
};

class Game
{
private:
    node* head;
    node* current;

public:

    Game()
    {
        head = NULL;
        current = NULL;
    }

    void addPlayer(int id, int score)
    {
        node* temp = new node;
        temp->PlayerID = id;
        temp->Score = score;

        if(head == NULL)
        {
            head = temp;
            temp->next = head;
            current = head;
        }
        else
        {
            node* curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = temp;
            temp->next = head;
        }
    }

    void removePlayer(int id)
    {
        if(head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        node* curr = head;
        node* prev = NULL;

        if(head->PlayerID == id)
        {
            if(head->next == head)
            {
                delete head;
                head = NULL;
                current = NULL;
                return;
            }

            node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = head->next;
            head = head->next;
            current = head;
            delete curr;
            cout << "Player removed" << endl;
            return;
        }

        do
        {
            prev = curr;
            curr = curr->next;

            if(curr->PlayerID == id)
            {
                prev->next = curr->next;

                if(curr == current)
                    current = curr->next;

                delete curr;
                cout << "Player removed" << endl;
                return;
            }

        } while(curr != head);

        cout << "Player not found" << endl;
    }

    void nextTurn()
    {
        if(head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        current = current->next;

        cout << "Player " << current->PlayerID << " turn" << endl;
    }

    void skipPlayer()
    {
        if(head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        current = current->next->next;

        cout << "Turn skipped" << endl;
        cout << "Player " << current->PlayerID << " turn" << endl;
    }

    void checkWinner()
    {
        if(head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        if(head->next == head)
        {
            cout << "Winner is Player " << head->PlayerID << endl;
        }
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        node* temp = head;

        do
        {
            cout << "ID: " << temp->PlayerID
                 << " Score: " << temp->Score << endl;

            temp = temp->next;

        } while(temp != head);
    }
};

int main()
{
    Game g;

    g.addPlayer(1, 10);
    g.addPlayer(2, 20);
    g.addPlayer(3, 15);
    g.addPlayer(4, 25);

    cout << "Players" << endl;
    g.display();

    cout << "Next turn" << endl;
    g.nextTurn();

    cout << "Skip player" << endl;
    g.skipPlayer();

    cout << "Remove player 2" << endl;
    g.removePlayer(2);
    g.display();

    g.checkWinner();

    return 0;
}