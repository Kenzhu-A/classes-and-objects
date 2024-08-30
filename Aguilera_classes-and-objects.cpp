#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{

	private:
		string title;
		string author;
		int year;
		
	public:
		void setTitle(string t){
			title = t;
		}
		
		void setAuthor(string a){
			author = a;
		}
		
		void setYear(int y){
			year = y;
		}


		string getTitle(){
			return title;
		}
		
		string getAuthor(){
			return author;
		}
		
		int getYear(){
			return year;
		}
		
};

class Library
{

	private:
		vector<Book> books;
		

	public:
		void addBook()
	{
		string title;
		string author;
		int year;
	
		Book b1;
	
		cin.ignore();
		cout<<"Enter title: ";
		getline(cin, title);
		cout<<"Enter author: ";
		getline(cin, author);
		while (true)
		{
			cout<<"Enter year: ";
			cin >> year;
		if (year > 0)
			{	
				break;
			}
		else 
			{ 
				cout <<"Invalid input!! There must be no negative input!\n";
			}
				
		};
		
		b1.setTitle(title);
		b1.setAuthor(author);
		b1.setYear(year);
	
		books.push_back(b1);
		cout<<"Book added successfully!\n\n";
	}

	void displayBook()
	{
		cout<<"Book list: \n\n";
		cout << left << setw(30) << "Title" << left << setw(30) << "Author" << left << setw(30)<< "Year" << endl;
	
		for (auto& b1 : books)
   		{
		cout << left << setw(30) << b1.getTitle() << left << setw(30) << b1.getAuthor() << left << setw(30) << b1.getYear() << endl;
		}
	
		cout << endl;
	
	}

	void searchBook()
	{
		string title;
	
		cin.ignore();
		cout<<"Enter a book to search: ";
		getline(cin,title);
		bool bookFound = false;
	
		for (auto& b1 : books)
   		{
    	
			if(b1.getTitle()==title)
			{ 
			cout<<"\nBook found!\n\n";
			cout<<"Title: "<<b1.getTitle()<<endl;
			cout<<"Author: "<<b1.getAuthor()<<endl;
			cout<<"Year: "<<b1.getYear()<<endl;
			cout<<endl;
			bookFound = true;
			break;
			}
		
		}
	
			if(bookFound == false)
			{
			cout<<"\nBook not found!\n\n";	
			}
		
	
	}	

	void exitBook()
	{
		exit(0);
	}

};

int main()
{
	Library l1;
	int choice;
	
	while(choice != 4)
	{
		cout<<"Menu\n\n";
		cout<<"1 - Add Book\n";
		cout<<"2 - Display Book\n";
		cout<<"3 - Search Book\n";
		cout<<"4 - Exit\n\n";
	
		cout<<"Enter your choice: ";
		cin>>choice;
		
		cout<<endl;

	switch (choice) { 
	
		case 1: 
		{
			l1.addBook(); 
			break;
		}
		
		case 2: 
		{
			l1.displayBook(); 
			break;
		}

		case 3: 
		{
			l1.searchBook(); 
			break;
		}

		case 4: 
		{
			l1.exitBook(); 
			break;
		}

		default: 
			cout<<"Invalid input!! Please try again!\n\n"; 
			
		} 
		
	};

	return 0;
	
}