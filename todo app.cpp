#include<bits/stdc++.h>
using namespace std;

class TodoItem {
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {} // contructor
    ~TodoItem() = default;// destructor

    bool create(string new_description) { // function to create the new todoitem object
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }

};

int main()
{
    char input_option;
    int input_id;
    string input_description;
    list<TodoItem> todoItems;
    list<TodoItem>::iterator it;


    todoItems.clear();// in case the list is not empty this clears it

    while (1) {
        system("cls");// it clears the screen between two 2 diffrent loops 
        cout << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << endl;
        }

        if (todoItems.empty()) {
        	cout << "*****WELCOME*****" << endl;
        	cout<<endl;
        	cout<<endl;
            cout << "Add your first todo :)" << endl;
        }

        cout << endl << endl;

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "Give your choice(a/c/q): ";

        cin >> input_option;

        if (input_option == 'q') {
        	int count=0;
        	for (it = todoItems.begin(); it != todoItems.end(); it++) {
               if(it->isCompleted()==false) count++;
            }
            if(count!=0) cout<<"hey you still have "<<count<<" thing(s) to do"<<endl;
            else 
			{ cout<< "Excellent you are done with every thing :)"<<endl;
			cout << "Have a great day !" << endl;}
            break;
        }
        else if (input_option == 'a') {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);// newitem is pushed into the main list

        }
        else if (input_option == 'c') {
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }

        }

    }

    return 0;
}
