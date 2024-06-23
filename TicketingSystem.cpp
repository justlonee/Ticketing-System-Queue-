#include<iostream>
#include<string>
#include<windows.h>
#include<stdio.h>
// for font color
#define RESET "\033[0m" // font color reset (this is needed so that the color wont affect other text)
#define TXT_YELLOW "\033[33m" // font color value (Yellow)
#define SIZE 10
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        string d_name;

        Node(int value, string name) {
            data = value;
            next = nullptr;
            d_name = name;
        }
};

// class user-defined data type that serves as a blueprint for creating objects
class Queue{
    private:
        Node* front;
        Node* rear;
        int ticket;

    public:
        // queue constructor
        Queue(){
            front = nullptr;
            rear = nullptr;
            ticket = 1; // ticket number starts with 1
        } 
    
        bool isEmpty(){
            return front == nullptr;
        }

        void dequeue(){ // this function deletes/dequeue the first/top data from the queue.
            if(isEmpty()){
                cout<<"Queue is Empty\n";
            } else {
                Node* temp = front;
                cout<<"Removed from Queue: "<< TXT_YELLOW << "Ticket # " << temp -> data << RESET <<endl<<"Driver Name: "<< TXT_YELLOW <<front -> d_name << RESET << endl;
                front = front -> next;
                delete temp;
                if(front == nullptr){
                    rear = nullptr;
                }
            }
        }

        int peek(){ // this function outputs the ticket # that is currently the peek of the queue
                if(!isEmpty()){
                    return front -> data;
                } else {
                    cout<<"Queue is Empty!\n";
                    return -1;
                }
        }

        void display(){ // this function displays all the data that is currently in queue.
            if(isEmpty()){
                cout<<"Queue is Empty!\n";
                return;
            }
            Node* temp = front;
            while(temp != nullptr){
                cout<<"Drivers Currently in Queue: " << TXT_YELLOW << "Ticket # "<<temp -> data <<RESET <<endl<<"Driver Name: "<< TXT_YELLOW <<temp -> d_name << RESET <<endl;
                temp = temp -> next;
            }
        }

        string name_peek(){ // this function outputs the driver name that is currently the peek of the queue
            if(!isEmpty()){
                return front -> d_name;
            } else {
                return "Queue is Empty!\n";
            }
        }

        void enqueue(string d_name){ // this function is to add data to the queue
            Node* newNode = new Node(ticket++, d_name);
            
            if(isEmpty()){
                front = rear = newNode;
            } else{
                rear -> next = newNode;
                rear = newNode;
            }
            cout<<endl;
            TicketLA();
            cout<< TXT_YELLOW <<"Ticket # "<<newNode -> data<< RESET <<endl;
        }


        // LOADING ANIMATIONS (Ticket Loading Animation and Loading Animation in general)
        void TicketLA(){
            cout<< TXT_YELLOW; // #define TXT_YELLOW it changes the text color

            SetConsoleCP(437);
            SetConsoleOutputCP(437);
            int bar1 = 177, bar2 = 219; //ASCII Symbols
            cout<<"Processing Ticket...";
            cout<<"\n";

            for(int i = 0; i < 25; i++){ // the background bar of the loading animation
                cout<< (char)bar1; // (char) makes the integer itno a char
            }
            cout<<"\r"; // this allows the animated loading (2nd for loop) to write on the same line as the background bar (1st for loop)

            for(int i = 0; i < 25; i++){ // the moving/animated loading itself
                cout<< (char)bar2;
                Sleep(80); // for loading animation delay
            }
            cout<<RESET; // #define RESET it resets the color and it prevents the next text from changing color
            cout<<endl<<endl;
        }

        void LoadingAnimation(){
            cout<< TXT_YELLOW; // #define TXT_YELLOW it changes the text color

            SetConsoleCP(437);
            SetConsoleOutputCP(437);
            int bar1 = 177, bar2 = 219; //ASCII Symbols
            cout<<"Loading...";
            cout<<"\n";

            for(int i = 0; i < 25; i++){ // the background bar of the loading animation
                cout<< (char)bar1; // (char) makes the integer itno a char
            }
            cout<<"\r"; // this allows the animated loading (2nd for loop) to write on the same line as the background bar (1st for loop)

            for(int i = 0; i < 25; i++){ // the moving/animated loading itself
                cout<< (char)bar2; 
                Sleep(80); // for loading animation delay
            }
            cout<<RESET; // #define RESET it resets the color and it prevents the next text from changing color
            cout<<endl<<endl;
        }
};

int main(){
    Queue q;
    char ans;
    string d_name;

    while(ans != 5){ // while loop allows the program to keep looping as long as the users input is NOT EQUAL to 5.
        cout<<"---------------------------------\n";
        cout<<" LAND TRANSPORTATION OFFICE\n\n";

        cout<<" [1] - Issue DL Ticket (Enqueue)\n";
        cout<<" [2] - Peek of Current Queue\n";
        cout<<" [3] - Dequeue\n";
        cout<<" [4] - Display Current Queue\n";
        cout<<" [5] - Exit LTO\n"; 
        cout<<"---------------------------------\n";
        cout<<"Your Choice: ";
        cin>>ans;
        cin.ignore();
        cout<<endl;
        switch(ans){ // switch case allows the users to choose the desired outputs from the given choices above
            case '1':
            	cout<<"Enter Name: ";
            	getline(cin, d_name);
                q.enqueue(d_name);
                break;

            case '2':
                q.LoadingAnimation();
                cout<<"Current Peek is "<< TXT_YELLOW<< "Ticket # " <<q.peek()<< RESET <<endl<<"Driver Name: "<< TXT_YELLOW <<q.name_peek()<< RESET <<endl;
                break;

            case '3':
                q.LoadingAnimation();
                q.dequeue();
                break;

            case '4':
                q.LoadingAnimation();
                q.display();
                break;    
            
            case '5':
                q.LoadingAnimation();
                cout<< TXT_YELLOW <<"Come back whenever you feel like taking the exams!!" << RESET;
                exit(0);     
                break;   
        }
    }
}