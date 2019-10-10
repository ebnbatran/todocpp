#include "todo_list.h"

TodoList::TodoList()
{
	filename = nullptr;
}

TodoList::TodoList(const char* filename)
{
	this->filename = filename;
}

TodoList::~TodoList()
{
	// do nothing
}

void TodoList::read()
{
	fstream fs(filename, fstream::in);
	string line;

	list.clear();

	while(getline(fs, line))
	{
		if (line == "") continue;
		Item item(line);
		list.push_back(item);
	}

	fs.close();
}

void TodoList::display()
{
	cout << "Your todo list: " << endl << endl;

	const int W = 40;	
	cout << "   " << setw(W) << left << "TASK" << "DONE" << endl;
	cout << "   " << setw(W) << left << "----" << "----" << endl;
	for (int i = 0; i < list.size(); ++i)
		cout << i + 1 << ") " << setw(W) << left << list[i].text() << (list[i].is_done() ? "Done" : "" ) << endl;	
}

void TodoList::create()
{
	bool is_finished = false;
	int count = 1;
	string task;

	list.clear();

	while(!is_finished)
	{	
		cout << count << ": ";
		
		getline(cin, task);
		if (task == "") is_finished = true;

		Item item(task);
		list.push_back(item);
		count++;
	}
}

void TodoList::save()
{
	fstream fs(filename, fstream::out);
	
	for (Item item : list) 
	{
		if (item.text().empty()) continue;
		fs << item.text() << " " << (item.is_done() ? "true" : "false") << endl;
	}

	fs.close();
}

int TodoList::get_count()
{
	return list.size();
}

void TodoList::add()
{
	int index = list.size();
	while (true)
	{
		cout << ++index << ": ";
		
		string task;
		getline(cin, task);
		if (task == "") break;

		Item item(task);
		list.push_back(item);
	}

	save();
}

void TodoList::clear()
{
	list.clear();
	remove(filename);
}	

void TodoList::check()
{
	cout << "Enter number of task: ";
	
	string choice;
	getline(cin, choice);
	
	if (choice.empty()) return;
	for (char c : choice) if (isalpha(c)) return;
	
	int index = stoi(choice) - 1;
	if (index > list.size()) return;
	list[index].done();

	save();
}