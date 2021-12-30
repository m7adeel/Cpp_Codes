#include <iostream>
#include <ctime>

using namespace std;

struct Date
{
private:
    string month;
    int year;
    int day;

public:
    int format; // Format 1 is dd/mm/yyyy   // Format 2 is Day Month, year

    Date()
    {
        // in the constructor we get the date and then divide it into month, year and days
        month = "";
        year = 0;
        day = 0;
        int store_in = 0;
        string d = __DATE__;

        for(int i = 0 ; i < d.size() ; i++)
        {
            if(d[i] == ' ')
            {
                store_in++;
                continue;
            }
            if(store_in == 0)
            {
                month += d[i];
                continue;
            }
            if(store_in == 1)
            {
                day *= 10;
                day += ((int)d[i] - (int)'0');
                continue;
            }
            if(store_in == 2)
            {
                year *= 10;
                year += ((int)d[i] - (int)'0');
            }
        }

        format = 1;
    }

    void printDate()
    {
        if(format == 1)
        {
            cout << day << "/";

            if(month == "Jan")
                cout << "01";
            if(month == "Feb")
                cout << "02";
            if(month == "Mar")
                cout << "03";
            if(month == "Apr")
                cout << "04";
            if(month == "May")
                cout << "05";
            if(month == "Jun")
                cout << "06";
            if(month == "Jul")
                cout << "07";
            if(month == "Aug")
                cout << "08";
            if(month == "Sep")
                cout << "09";
            if(month == "Oct")
                cout << "10";
            if(month == "Nov")
                cout << "11";
            if(month == "Dec")
                cout << "12";

            cout << "/" << year << endl;
        }
        else if(format == 2)
        {
            cout << day << " " << month << "," << year << endl;
        }
    }
};

struct Time
{
private:
    int hours;          //
    int minutes;        //  assigning the value of minutes sec and hours in printTime() so they get updated every time
    int sec;            //

public:
    int format; // format 1 is for military time and format 2 is for 12 hrs time

    Time()
    {
        format = 1;
    }

    
    void printTime()
    {
                    // mode 24*60*60 give us the seconds passed in the current day
        int t = (time(0) % (24*60*60)) + (5 * 60 * 60);    // we add 5 * 60 * 60 since Pakistani clock is 5 hours ahead of GMT

        hours = t / 3600;
        t %= 3600;
        minutes = t / 60;
        t %= 60;
        sec = t;

        if(format == 1)
        {
            if(hours < 10)
                cout << "0";
            cout << hours << ":";
            if(minutes < 10)
                cout << "0";
            cout << minutes << ":";
            if(sec < 10)
                cout << "0";
            cout << sec << endl;
        }
        if(format == 2)
        {
            if(hours % 12 == 0)
            cout << 12;
            else
            {
                if(hours % 12 < 10)
                    cout << "0";
                cout << hours % 12;
            }
            cout << ":";
            if(minutes < 10)
            cout << "0";
            cout << minutes << ":";
            if(sec < 10)
                cout << "0";
            cout << sec;

            if(hours / 12 == 1)
            {
                cout << " PM";
            }
            else
            {
                cout << " AM";
            }
        }
    }
};

struct Mirror
{
    int d_order[4]; // this is the display order
    Date date;
    Time time;
    string weekly_quote;
    string *tasks;
	int n_tasks;

    Mirror()
    {
        // considering 1 for Date
        // considering 2 for Time
        // considering 3 for Weekly Quote
        // considering 4 for Task

		n_tasks = 0;
        for(int i = 0 ; i < 4 ; i++)
            d_order[i] = i+1;

        weekly_quote = "";

    }

    void display()
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if(d_order[i] == 1)
			{
				cout << "\t\t\t";
                date.printDate();
			}
            if(d_order[i] == 2)
			{
				cout << "\n\t\t\t ";
                time.printTime();
			}
            if(d_order[i] == 3)
                cout << "    " << weekly_quote << endl;

            if(d_order[i] == 4)
            {
                cout << "Tasks : \n";

				if(n_tasks == 0)
				{
					cout << "\n\t!!! Woohoo No Task Pending !!!\n";
				}

                for(int i = 0 ; i < n_tasks ; i++)
                {
                    cout << i+1 << ". " <<tasks[i] << endl;
                }
            }
        }
    }

	void setquote(string quo)
	{
		weekly_quote = quo;
	}

	void addTask()	// here a copy of tasks is made and then we increase the size of the tasks array and copy all of the tasks back
	{
		string cpy_tasks[n_tasks];

		for(int i = 0 ; i < n_tasks ; i++)
			cpy_tasks[i] = tasks[i]; 

		de_alloc();
		n_tasks++;
		alloc();

		for(int i = 0 ; i < n_tasks - 1 ; i++)
		{
			tasks[i] = cpy_tasks[i];
		}
		cin.ignore();
		string new_task;
		cout << "Enter the Task : ";
		getline(cin,new_task);

		tasks[n_tasks-1] = new_task; 
	}

	void removeTask()
	{
		if( n_tasks > 0)
		{
			int task_no = 0;
			cout << "\n\n\n";
			cout << "Tasks : \n";
			for(int i = 0 ; i < n_tasks ; i++)
				cout << i+1 << ". " << tasks[i] << endl;

			cout << "Enter the Number of Task you Want to remove : ";
			cin >> task_no;

			// now we will create a copy of the task but we will leave the entered task

			string cpy_tasks[n_tasks - 1];
			int cpy_index = 0;	

			for(int i = 0 ; i < n_tasks ; i++)
			{
				if(i == task_no - 1)
				{
					continue;
				}
				else
				{
					cpy_tasks[cpy_index++] = tasks[i];
				}
			}

			de_alloc();
			n_tasks--;
			alloc();

			// copying back elements to the decreased array
			for(int i = 0 ; i < n_tasks ; i++)
				tasks[i] = cpy_tasks[i];
		}

	}

	void edit()
	{
		char choice = '0';

		system("cls");

		cout << "\n\n\t\t\tEdit Screen\n"
			 << "\t1. Change the Date Format\n "
		     << "\t2. Change the Time Format\n"
			 << "\t3. Add a Task\n"
			 << "\t4. Remove a Task\n"
			 << "\t5. Change the Weekly Quote\n"
			 << "\t6. Change the order of the Display\n\n"
			 << "Choice : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			{
				int d_format = 0;
				date.format = 1;
				cout << "\n\n";
				cout << "\nFormat 1 : \t"; date.printDate();
				date.format = 2;
				cout << "\nFormat 2 : \t"; date.printDate();
				cout << "\nEnter your Choice : ";
				cin >> d_format;

				if(d_format == 1 || d_format == 2)
				{
					date.format = d_format;
				}
			}
			break;
		
		case '2':
			{
				int t_format = 0;
				time.format = 1;
				cout << "\n\n";
				cout << "\nFormat 1 : \t"; time.printTime();
				time.format = 2;
				cout << "\nFormat 2 : \t"; time.printTime();
				cout << "\nEnter your Choice : ";
				cin >> t_format;

				if(t_format == 1 || t_format == 2)
				{
					time.format = t_format;
				}
			}
			break;

		case '3':
			addTask();
			break;

		case '4':
			removeTask();
			break;

		case '5':
			{
				string quote;
				cin.ignore();
				cout << "\n\nEnter the quote to Display : ";
				getline(cin,quote);

				setquote(quote);
			}
		break;

		case '6':
			{

				cout << "\nBelow is the Choice Numbers assigned to the Displays\n\nEnter in the order you want to Display\n\nNOTE: Any other number will be consided as if no display is need\n\n"
					 << "1 For Date\n"
					 << "2 For Time\n"
					 << "3 For Weekly Quote\n"
					 << "4 For Tasks\n\n";

				for(int i = 0 ; i < 4 ; i++)
				{
					cout << i + 1 << " to appear on Display : ";
					cin >> d_order[i];
				}

			}
			break;

		default:
			break;
		}
	}

private:
	void alloc()
	{
		tasks = new string[n_tasks];
	}

	void de_alloc()
	{
		delete[] tasks;
	}

public:
	~Mirror()
	{
		delete[] tasks;
	}
};

int main()
{
	Mirror m1;
	char choice = 0;
	while(choice != '3')
	{
		if(choice == '1')
		{
			m1.edit();
		}

		if(choice  == '2')
		{
			string quote ="";

			cin.ignore();

			cout << "Enter the quote to Display : ";
			getline(cin,quote);
			m1.setquote(quote);
		}
		system("cls");
		cout << "\n\n\n\n";
		m1.display();

		cout << "\n\nPress 1 to edit the menu, 2 to edit the quote, 3 to exit or any other key to refresh : ";
		//choice  = cin.get();
		cin >> choice;
	}
    return 0;
}
