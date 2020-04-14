#include <iostream>

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Student
{
	char marka[56];
	char proizvod[32];
	Date registration;
	char type[56];
	short yearissue;
};

using namespace std;
int main()
{
	const int N = 2;
	Student group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput Car make : ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].marka, 56);

		cout << "\nIinput Manufacturer : ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].proizvod, 32);


		do
		{
			cout << "\nInput Date of registration: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].registration.day >> group[i].registration.month >> group[i].registration.year;
		} while (!group[i].registration.isCorrect());

		cout << "\nInput Type :";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].type;

		cout << "\nInput Year of issue:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].yearissue;

	}


	cin.clear();



	int best = 0;
	for (int i = 0; i < N; i++)
	{
		if (group[i].registration.year < 2000 || group[i].marka == "Ford")
			best = i;
	}

	cout << "\nName: " << group[best].marka << endl;
	cout << "\nManufacturer: " << group[best].proizvod << endl;
	cout << "\nDate of receipt at the werehouse: " << group[best].registration.day << "." << group[best].registration.month << "." << group[best].registration.year;
	cout << "\nPrice: " << group[best].type << endl;
	cout << "\nAmount: " << group[best].yearissue << endl;
	return 0;
}
