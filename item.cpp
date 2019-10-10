#include "item.h"

Item::Item()
{
	_text = "";
	_done = false;
}

Item::Item(string item)
{
	int startf = item.find("false");
	int startt = item.find("true");
	string str;

	if (startf > -1 && startt == -1) // item has false
	{
		str = item.substr(0, startf - 1);
		_done = false;
	} else if (startt > -1 && startf == -1) { // item has true
		str = item.substr(0, startt - 1);
		_done = true;
	} else if (startf == -1 && startt == -1) { // item is user input (no true or false)
		str = item;
		_done = false;
	}
	
	_text = str;
}

Item::~Item()
{
	// do nothing
}


string Item::text()
{
	return _text;
}

void Item::done()
{
	_done = true;
}

bool Item::is_done()
{
	return _done;
}

string Item::str_tolower(string str)
{
	string temp = str;
	for (int i = 0; i < temp.size(); ++i)
		temp[i] = tolower(temp[i]);
	return temp;
}

bool Item::operator==(Item& other)
{
	bool text_equal = str_tolower(_text) == str_tolower(other.text());
	bool done_equal = _done == other.is_done();
	return text_equal && done_equal;
}
