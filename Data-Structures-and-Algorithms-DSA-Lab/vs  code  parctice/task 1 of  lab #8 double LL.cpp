#include <iostream>
#include <string> // Fixed: Changed from <cstring> to <string>
using namespace std;

class node { 
public:
    int songid;
    string songname;
    int duration;

    node *next;
    node *prev;
};

class playlist { // Fixed: Removed the extra '{'
private:
    node *head; 
    node*curr; 

public:
    // Fixed: Removed the 'class' keyword from the constructor
    playlist() {
        head = NULL;
        curr = NULL;
    }

    void addsong(int id, string name, int dur) {
        node* newnode = new node;
        newnode->songid = id;
        newnode->songname = name;
        newnode->duration = dur;

        if (head == NULL) {
            head = newnode;  
            newnode->next = NULL;
            newnode->prev = NULL;
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp; 
            newnode->next = NULL;           
        }
    }

 void deletesong( string name) {
        
    if( head == NULL){
        cout<<"Playlist is empty!"<<endl;
        return;
    }else{
          node  *temp = head; 
          while (temp != NULL){
              if ( temp->songname == name){
                 if (temp == head){
                     head = temp ->next;
                     
                    if (head != NULL) { 
                        head->prev = NULL;
                    }
                delete temp;
                 } else{ 
                 temp-> prev->next = temp ->next;
                 if (temp ->next!=NULL){
                    temp->next->prev = temp->prev;
                 }
                     delete temp;
                     cout<<"Song deleted successfully!"<<endl;
                     return; 
                }

               }
            }
          }
    }


    void playnext(){
      if(curr == NULL ){
     cout<<"Playlist is empty!"<<endl;
        return;
       }  
       if(curr->next !=NULL){
         curr = curr->next;
         cout<<"Playing next song: "<< curr->songname<<endl; 
       }else{
           cout<<"last song in the playlist!"<<endl;
           
        }  
    }

    void playprevious(){
      if ( curr == NULL){
        cout<<"Playlist is empty!"<<endl;
        return;
      }
      else{
            if(curr->prev !=NULL){
             curr =curr->prev;
             cout<<"Playing previous song: "<< curr->songname<<endl;
             
             }else{

             cout<<"First song in the playlist!";
             
            }
        }

    }

void reverseDisplay()
{
    node* curr = head;

   
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    
    while (curr != NULL)
    {
        cout << curr->songname << endl;
        curr = curr->prev;
    }
}





    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << "Song ID: " << temp->songid << ", Name: " << temp->songname << ", Duration: " << temp->duration << " minutes" << endl;
            temp = temp->next;
        }
    }

}; 
int main()
{
    playlist p1;

    // Adding 10 songs
    p1.addsong(1, "song1", 3);
    p1.addsong(2, "song2", 4);
    p1.addsong(3, "song3", 5);
    p1.addsong(4, "song4", 6);
    p1.addsong(5, "song5", 4);
    p1.addsong(6, "song6", 5);
    p1.addsong(7, "song7", 3);
    p1.addsong(8, "song8", 6);
    p1.addsong(9, "song9", 4);
    p1.addsong(10, "song10", 5);

    cout << "Original Playlist:\n";
    p1.display();

    // Play next songs
    cout << "\nPlay Next:\n";
    p1.playnext();

    cout << "\nPlay Next:\n";
    p1.playnext();

    cout << "\nPlay Next:\n";
    p1.playnext();

    // Play previous song
    cout << "\nPlay Previous:\n";
    p1.playprevious();

    // Delete a song
    cout << "\nDeleting song5...\n";
    p1.deletesong("song5");

    // Display after deletion
    cout << "\nPlaylist After Deletion:\n";
    p1.display();

    // Reverse display
    cout << "\nPlaylist In Reverse Order:\n";
    p1.reverseDisplay();

    return 0;
}