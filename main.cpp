#include <iostream>
#include "todo_list.h"

using namespace std;

int main(int argc, char const *argv[])
{
	TodoList tasks("list.txt");

	while(true)
	{
		tasks.read();

		if (tasks.get_count() > 0)
		{
			tasks.display();
			cout << endl;

			cout << "1) Add" << endl;
			cout << "2) Clear" << endl;
			cout << "3) Check" << endl;
			cout << "Choice: ";
			
			string choice;
			getline(cin, choice);
			
			if (choice == "1")
			{
				tasks.add();
			} else if (choice == "2") {
				tasks.clear();
			} else if (choice == "3") {
				tasks.check();
			} else {
				break;
			}

		} else {
			cout << "Created a new list .." << endl;
			tasks.create();
			
			cout << endl; 
			tasks.display();

			tasks.save();
		}
	}

	return 0;
}