#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <exception>
#include "Header.h"

using namespace std;

template<class T>
class Base
{
public:
	vector<T> cars;
	virtual void GetData()=0;
	virtual void NameSearch(string)=0;
	virtual void GetDataToFile()=0;
	virtual void SetDataFromFile()=0;
};


class Car
{
public:
	string name;
	string releaseDate;
	int engineVolume;
	int price;

	Car()
	{
	this->name=GenName();
	this->releaseDate=GenReleaseDate();
	this->engineVolume=GenEngineVolume();
	this->price=GenPrice();
	}
	Car(string name,string releaseDate,int engineVolume,int price)
	{
		this->name = name;	
		this->releaseDate = releaseDate;
		this->engineVolume = engineVolume;
		this->price = price;
	}
	Car(int i)
	{
		try
		{
		cin >> this->name >> this->releaseDate >> this->engineVolume >> this->price;
		if(cin.fail())
			throw exception("Incorrect Input");
		}
		catch (exception& err)
		{
			while (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << err.what() << endl;
				cin >> this->name >> this->releaseDate >> this->engineVolume >> this->price;
			}
		}
	}
	void GetData()
	{
		cout << name << setw(18) <<releaseDate << setw(18) << engineVolume << setw(18) << price<< endl<< endl;
	}
};


class CarShowroom:public Base<class Car>
{
public:
	vector <Car> cars;

	CarShowroom()
	{
        int a= DataInput();
        if(a==0)
		{
		for(int i=0;i<10;i++)
		cars.push_back(Car());
		}
		else
		if(a==1)
		{
	        cout << "Input Data in this order: "<< endl;
			cout << "Car model->release date-> engine Volume->price"<< endl;
			int a;
			cout << "How many cars in ur CarShowRoom?" << endl;
			cin >> a;	
			for (int i = 0; i < a; i++)
				cars.push_back(Car(1));
		}
		else
			if (a == 2)
			{
				SetDataFromFile();
				if (cars.size()==0)
				{
					for (int i = 0; i < 10; i++)
						cars.push_back(Car());
				}
			}

	}


	void GetData() override
	{
	cout << "Name:"<< setw(18) << "release date:"<< setw(18)<<"engine Volume:"<< setw(18)<<"price:"<< endl;
	int i=1;
	   for(auto x:cars) 
	   {
	   cout << i<<".";x.GetData();
	   i++;
	   }
	}


	void Erase(string c,int price)
	{
	vector <Car>::iterator it;
	it=cars.begin();
		while(it!=cars.end())
		{
			if(it->name==c&&it->price==price)
			{
			cars.erase(it);
			break;
			}
			it++;
			
		}
	}

	void SortByName()
	{
		sort(cars.begin(),cars.end(),[](Car& a, Car& b){return a.name.compare(b.name) < 0;});
	}

	void SortByPrice()
	{
		sort(cars.begin(), cars.end(), [](Car& a, Car& b) {return a.price<b.price; });
	}

    
	void NameSearch(string line) override
	{    
		for_each(cars.begin(),cars.end(),[line](Car c){if(line==c.name)c.GetData();});
	}


	void GetDataToFile() override
	{
		ofstream file("SetDataTo.txt");
		if (file.is_open())
		{   
		    file<<  "Name:" << setw(18) << "release date:" << setw(18) << "engine Volume:" << setw(18) << "price:" << endl;
			for_each(cars.begin(),cars.end(),[&file](Car cars){file << cars.name << setw(18) << cars.releaseDate << setw(18) << cars.engineVolume << setw(18) << cars.price<< endl;});
		}
	}

	void SetDataFromFile() override
	{
		string temp;
		ifstream file("GetDataFrom.txt");
		string name;
		string releaseDate;
		int engineVolume;
		int price;
		if (file.is_open())
		{
			if (cars.size() != 0)
			{	
					cars.clear();
			}
				getline(file, temp);
				int i = 0;
				while (file >> name >> releaseDate >> engineVolume >> price)
				{
					i++;
					if (i != 0)
					{
						cars.push_back(Car(name, releaseDate, engineVolume, price));
					}
				
			    }
		}
		else
		{
			cout << "FILE WASNT FOUND"<< endl;
			cout << "RANDOMIZE DATA"<< endl;
			return;
		}
		

	}

};



int main()
{
    srand(time(0));
	CodeWords();
	CarShowroom c;
	string a;
	while (cin >> a)
	{
		int easyint=To_easyInt(a);
		switch (easyint)
		{
			case 1:
				c.GetData(); 
				break;
			case 2:
			{
				string temp;
				int p;
				cin >> temp >> p;
				c.Erase(temp,p);
				break;
			}
			case 3:
				c.SortByName();
				break;
			case 4:
				c.SortByPrice();
				break;
			case 5:
			{
				string temp;
				cin >> temp;
				c.NameSearch(temp);
				break;
			}
			case 6:
			{
				system("cls");
				CodeWords();
				break;
			}
			case 7:
				c.GetDataToFile();
				break;
			case 8:
				c.SetDataFromFile();
				break;
			default:
				cout << "Incorrect Input" << endl;
				break;
		}
	}
	return 0;
}

