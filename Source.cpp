#include <ctime>
#include <iostream>
#include <string>
#include <exception>

using namespace std;
void CodeWords()
{
	cout << "GetData - get info about cars int carshowroom"<< endl;
	cout << "Erase - delete car by car model + price" << endl;
	cout << "SortName- sort cars data by car models"<< endl;
	cout << "SortPrice- sort cars data by car prices"<< endl;
	cout << "SearchName - get data about all cars with same model"<< endl;
	cout << "Clear - clear console"<< endl;
	cout << "DataToFile - copy all data to file"<< endl;
	cout << "DataFromFile - take all data from file"<< endl;
	cout << "EXIT"<< endl;
}


int DataInput()
{
	cout<< "\nDo u want to Set all Data or Program will do it itself"<< endl;
	cout << "0-NO/1-YES/2-READ FROM FILE"<< endl;
	int a;
	try
	{
		cin >> a;
		if (a!=0&&a!=1&&a!=2)
		throw exception("Incorrect Input");
	}
	catch (exception& er)
	{
		cout << er.what()<< endl;
	}
	return a;
}

int To_easyInt(string a)
{
	if(a=="GetData")
	return 1;
	if(a=="Erase")
	return 2;
	if(a=="SortName")
	return 3;
	if(a=="SortPrice")
	return 4;
	if(a=="SearchName")
	return 5;
	if(a== "Clear")
	return 6;
	if(a=="DataToFile")
	return 7;
	if(a=="DataFromFile")
	return 8;
	if(a=="EXIT")
	return 9;
	return 0;
}



std::string GenName()
{
	int a = rand() % 11 + 1;
	switch (a)
	{
	case 1:
		return "Merc";
	case 2:
		return "BMW";
	case 3:
		return "Tesla";
	case 4:
		return "Hundai";
	case 5:
		return "Kia";
	case 6:
		return "Audi";
	case 7:
		return "Citroen";
	case 8:
		return "Jaguar";
	case 9:
		return "Lexus";
	case 10:
		return "Skoda";
	case 11:
		return "Subaru";
	}
}

std::string GenReleaseDate()
{
   int d=rand()%28+1;
   int m=rand()%12+1;
   int y=rand()%41+1986;
   return std::to_string(d)+"."+std::to_string(m)+"."+std::to_string(y);
}

int GenEngineVolume()
{
	return rand()%101+100;
}

int GenPrice()
{
	return (rand()%10+1)*(rand()%5000+5000)+((rand()%9+1)*(rand()%100+1));
}
