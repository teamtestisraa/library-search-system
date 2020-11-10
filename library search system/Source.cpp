#include <iostream>
#include<string>
#include <fstream>
#include<conio.h>


using namespace std;

struct bookInfo
{
	string bookName, authorName, category;
	string  bookId, publishedYear;
};
struct userInfo
{
	string Name, password;
};

bookInfo book[15], array_to_coppy[15];
userInfo reader[10];

fstream fs;
int bookNum = 0, readerNum = 0;

void convert(string& str);
void convert(char* arr, int size);
void getBooksFromFile();
void getReadersFromFile();

void signupReader();
void loginReader();
void searchByName();
void searchByAuthor();
void searchById();
void searchByCategory();
void searchByYear();
void searchForWord();
void searchForCompositeWord();
void displayAllBooks();

void addBook();
void deleteBook();
void modifyBook();

void readerMenu();
void readerSection();

void putBooksInFile();
void putReadersInFile();


int main()
{
	getBooksFromFile();
	getReadersFromFile();

	readerMenu();

	putBooksInFile();
	putReadersInFile();

	system("pause");
	return 0;
}

void convert(string& str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}
void convert(char* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = tolower(arr[i]);
}

void getBooksFromFile()
{
	fstream fs;
	fs.open("books.txt", ios::in);
	if (!fs)
		cout << "file not found !" << endl;
	else
	{
		while (!fs.eof())
		{
			getline(fs, book[bookNum].bookName, '|');
			getline(fs, book[bookNum].authorName, '|');
			getline(fs, book[bookNum].bookId, '|');
			getline(fs, book[bookNum].category, '|');
			getline(fs, book[bookNum].publishedYear);
			bookNum++;
		}
		bookNum--;
		fs.close();
	}
}
void getReadersFromFile()
{
	fs.open("readers.txt", ios::in);
	if (!fs)
		cout << "file not found !" << endl;
	else
	{
		while (!fs.eof())
		{
			getline(fs, reader[readerNum].Name, '|');
			getline(fs, reader[readerNum].password);
			readerNum++;
		}
		readerNum--;
	}
	fs.close();
}

void signupReader()
{
	system("CLS");
	string rName, rPassword, rPasswordCheck;
	int count = 0;

	cout << "Enter your username : ";
	cin.ignore();
	getline(cin, rName);
	while (true)
	{
		cout << "Enter your password(6 characters) : " << endl;
		getline(cin, rPassword);
		cout << "Re-enter your password:" << endl;
		getline(cin, rPasswordCheck);
		if (rPassword == rPasswordCheck)
		{
			cout << "Successfuly sign up!" << endl;
			readerNum++;
			reader[readerNum].Name = rName;
			reader[readerNum].password = rPassword;
			readerSection();
			break;
		}
		else
			cout << "Password doesn`t match" << endl << endl;
	}
}
void loginReader()
{
	int counter = 0;
	while (counter != 1)
	{
		system("CLS");
		string uName, uPassword;

		cin.ignore();
		cout << "Enter reader name : ";
		getline(cin, uName);
		cout << "Enter password : ";
		getline(cin, uPassword);


		for (int i = 0; i < readerNum; i++)
		{
			if (reader[i].Name == uName)
			{
				if (reader[i].password == uPassword)
					counter++;
				break;
			}
		}
		if (counter == 1)
		{
			cout << "Successfully loged in" << endl;
			readerSection();
		}
		else
		{
			int x = 0;
			while (x == 0)
			{
				cout << "Invalid user name or password" << endl << endl;
				int choise = 0;
				cout << "If you want to to try again .. press 1 " << endl;
				cout << "If you don't have an acount .. press 2 " << endl;
				cin >> choise;
				switch (choise)
				{
				case 1:
				{   x = 1;
				counter = 0;
				break;
				}
				case 2:
				{   x = 1;
				signupReader();
				break;
				}
				default:
					cout << "Invalid choise " << endl;
				}
			}
		}
	}
}

void searchByName()
{
	system("CLS");
	string bName;
	int found = 0;
	cout << "--- searching a book name ---" << endl;
	cout << "Enter book name : " << endl;
	cin.ignore();
	getline(cin, bName);

	for (int i = 0; i < bookNum; i++)
	{
		if (bName == book[i].bookName)
		{
			found++;
			cout << endl;
			cout << "Book name : " << book[i].bookName << endl;
			cout << "Author name : " << book[i].authorName << endl;
			cout << "ID : " << book[i].bookId << endl;
			cout << "Category : " << book[i].category << endl;
			cout << "Published year : " << book[i].publishedYear << endl << endl;
		}
	}

	if (found == 0)

		cout << "Book is not found !" << endl;



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchByName();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}
void searchByAuthor()
{
	system("CLS");
	string aName;
	int found = 0;
	cout << "--- searching a book author----" << endl;
	cout << "Enter author name : " << endl;
	cin.ignore();
	getline(cin, aName);

	for (int i = 0; i < bookNum; i++)
	{
		if (aName == book[i].authorName)
		{
			found++;
			cout << endl;
			cout << "Book name : " << book[i].bookName << endl;
			cout << "Author name : " << book[i].authorName << endl;
			cout << "ID : " << book[i].bookId << endl;
			cout << "Category : " << book[i].category << endl;
			cout << "Published year : " << book[i].publishedYear << endl << endl;
		}
	}

	if (found == 0)
		cout << "Book is not found !" << endl;

	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchByAuthor();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}
void searchById()
{
	system("CLS");
	int found = 0;
	string bID;
	cout << "----- searching a book ID -----" << endl;
	cout << "Enter ID : " << endl;
	cin.ignore();
	getline(cin, bID);

	for (int i = 0; i < bookNum; i++)
	{
		if (bID == book[i].bookId)
		{
			found++;
			cout << endl;
			cout << "Book name : " << book[i].bookName << endl;
			cout << "Author name : " << book[i].authorName << endl;
			cout << "ID : " << book[i].bookId << endl;
			cout << "Category : " << book[i].category << endl;
			cout << "Published year : " << book[i].publishedYear << endl << endl;
		}
	}

	if (found == 0)
		cout << "Book is not found !" << endl;



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchById();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}
void searchByCategory()
{
	system("CLS");
	string bCategory;
	int found = 0;
	cout << "--- searching a book category ---" << endl;
	cout << "Enter category : " << endl;
	cin.ignore();
	getline(cin, bCategory);
	for (int i = 0; i < bookNum; i++)
	{
		if (bCategory == book[i].category)
		{
			found++;
			cout << endl;
			cout << "Book name : " << book[i].bookName << endl;
			cout << "Author name : " << book[i].authorName << endl;
			cout << "ID : " << book[i].bookId << endl;
			cout << "Category : " << book[i].category << endl;
			cout << "Published year : " << book[i].publishedYear << endl << endl;

		}
	}
	if (found == 0)
		cout << "Book is not found !" << endl;



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchByCategory();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}


}
void searchByYear()
{
	system("CLS");
	int found = 0;
	string bPublishedYear;
	cout << "--- searching a book published year ---" << endl;
	cout << "Enter year : " << endl;
	cin.ignore();
	getline(cin, bPublishedYear);
	for (int i = 0; i < bookNum; i++)
	{
		if (bPublishedYear == book[i].publishedYear)
		{
			found++;
			cout << endl;
			cout << "Book name : " << book[i].bookName << endl;
			cout << "Author name : " << book[i].authorName << endl;
			cout << "ID : " << book[i].bookId << endl;
			cout << "Category : " << book[i].category << endl;
			cout << "Published year : " << book[i].publishedYear << endl << endl;
		}
	}

	if (found == 0)
		cout << "Book is not found !" << endl;



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchByYear();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}
void searchForWord()
{
	system("CLS");

	char word[25];
	char a[25];
	cout << " \n enter word : ";
	cin.ignore();
	cin.getline(a, 25);
	for (int y = 0; y < bookNum; y++)
	{
		int x = 0, apperanceOfWord = 0;
		string bookFile;
		bookFile = book[y].bookName;
		bookFile.append(".txt");
		fs.open(bookFile, ios::in);
		if (!fs)
			cout << "file is not found !"
			<< endl;
		else
		{
			while (!fs.eof())
			{
				fs >> word;
				if (strcmp(word, a) == 0)
				{
					apperanceOfWord++;
					x = 1;
				}
			}
		}
		fs.close();
		if (x == 0)
			cout << " word is not found !" << endl;
		else
			cout << "Number of apperance of this word in " << book[y].bookName << " is : " << apperanceOfWord << endl;
	}



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		searchForWord();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}
void searchForCompositeWord()
{
	system("CLS");
	string cWord;
	cout << "enter string : ";
	cin.ignore();
	getline(cin, cWord);
	char* cWordF = new char[cWord.size()];

	for (int y = 0; y < bookNum; y++)
	{
		int x = 0, apperanceOfWord = 0;
		string bookFile;
		bookFile = book[y].bookName;
		bookFile.append(".txt");
		fs.open(bookFile, ios::in);
		if (!fs)
			cout << "file is not found !"
			<< endl;
		else
		{
			while (!fs.eof())
			{
				fs >> cWordF;
				convert(cWordF, cWord.size());
				if (cWordF == cWord)
				{
					apperanceOfWord++;
					x = 1;
				}
			}
		}
		fs.close();
		if (x == 0)
			cout << " word is not found !" << endl;
		else
			cout << "Number of apperance of this word in " << book[y].bookName << " is : " << apperanceOfWord << endl;

	}


}
void displayAllBooks()
{
	system("CLS");
	for (int i = 0; i < bookNum; i++)
	{
		if (book[i].bookName == " ")
			continue;

		cout << endl;
		cout << "Book name : " << book[i].bookName << endl;
		cout << "Author name : " << book[i].authorName << endl;
		cout << "ID : " << book[i].bookId << endl;
		cout << "Category : " << book[i].category << endl;
		cout << "Published year : " << book[i].publishedYear << endl << endl;
	}



	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		displayAllBooks();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}

void addBook()
{
	while (true)
	{
		system("CLS");
		char ch = 'y';
		string bName, text;

		cout << "Enter bookname : ";
		cin.ignore();
		getline(cin, book[bookNum].bookName);
		cout << "Enter book ID : ";
		getline(cin, book[bookNum].bookId);
		cout << "Enter author name : ";
		getline(cin, book[bookNum].authorName);
		cout << "Enter published year : ";
		getline(cin, book[bookNum].publishedYear);
		cout << "Enter category : ";
		getline(cin, book[bookNum].category);
		bName = book[bookNum].bookName;
		bookNum++;
		bName.append(".txt");
		fs.open(bName, ios::out);
		cout << "Enter text : ";
		getline(cin, text);
		fs << text;
		fs.close();


		cout << "to complete press .. c \n";
		cout << "to go to the main page press .. g \n";
		int flage = 0;
		while (flage == 0)
		{
			char ch = 'a';
			cin >> ch;
			switch (ch)
			{
			case 'c':
			case 'C':
			{   flage++;
			addBook();
			break;
			}
			case 'g':
			case 'G':
			{
				flage++;
				readerSection();
				break;
			}
			default:
				cout << "Invalid choise ! \n";
			}
		}
	}
}
void deleteBook()
{
	system("CLS");
	string bName;
	cout << "Enter name of book: ";
	cin.ignore();
	getline(cin, bName);
	for (int i = 0; i < bookNum; i++)
	{
		if (bName == book[i].bookName)
		{
			continue;
		}


		array_to_coppy[i].bookName = book[i].bookName;
		array_to_coppy[i].authorName = book[i].authorName;
		array_to_coppy[i].bookId = book[i].bookId;
		array_to_coppy[i].category = book[i].category;
		array_to_coppy[i].publishedYear = book[i].publishedYear;


	}



	bName.append(".txt");
	if (remove(bName.c_str()) != 0)
		cout << "Error deleting book" << endl;
	else
		cout << "Book successfully deleted" << endl;


	for (int i = 0; i < bookNum; i++)
	{
		book[i].bookName = array_to_coppy[i].bookName;
		book[i].authorName = array_to_coppy[i].authorName;
		book[i].bookId = array_to_coppy[i].bookId;
		book[i].category = array_to_coppy[i].category;
		book[i].publishedYear = array_to_coppy[i].publishedYear;

	}
	cout << "to complete press .. c \n";
	cout << "to go to the main page press .. g \n";
	int flage = 0;
	while (flage == 0)
	{
		char ch = 'a';
		cin >> ch;
		switch (ch)
		{
		case 'c':
		case 'C':
		{   flage++;
		deleteBook();
		break;
		}
		case 'g':
		case 'G':
		{
			flage++;
			readerSection();
			break;
		}
		default:
			cout << "Invalid choise ! \n";
		}
	}
}

void modifyBook()
{
	while (true)
	{
		char ch = 'y';
		system("CLS");
		string bName;
		int index;
		cout << "Enter book Name : ";
		cin.ignore();
		getline(cin, bName);
		for (int i = 0; i < bookNum; i++)
		{
			if (bName == book[i].bookName)
				index = i;
		}
		cout << "Old book name : " << book[index].bookName << endl;
		cout << "Enter new book name : ";
		getline(cin, book[index].bookName);
		cout << "Old author name : " << book[index].authorName << endl;
		cout << "Enter new author name : ";
		getline(cin, book[index].authorName);
		cout << "Old ID : " << book[index].bookId << endl;
		cout << "Enter new ID : ";
		getline(cin, book[index].bookId);
		cout << "Old category : " << book[index].category << endl;
		cout << "Enter new category : ";
		getline(cin, book[index].category);
		cout << "Old published year : " << book[index].publishedYear << endl;
		cout << "Enter new published year : ";
		getline(cin, book[index].publishedYear);
		cout << "Book successfully modified " << endl;


		cout << "to complete press .. c \n";
		cout << "to go to the main page press .. g \n";
		int flage = 0;
		while (flage == 0)
		{
			char ch = 'a';
			cin >> ch;
			switch (ch)
			{
			case 'c':
			case 'C':
			{   flage++;
			modifyBook();
			break;
			}
			case 'g':
			case 'G':
			{
				flage++;
				readerSection();
				break;
			}
			default:
				cout << "Invalid choise ! \n";
			}
		}
	}
}

void readerMenu()
{
	system("CLS");
	int choice;
	cout << "1.log in" << endl;
	cout << "2.sign up" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		loginReader();
		break;
	case 2:
		signupReader();
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}
}
void readerSection()
{
	system("CLS");
	int choice;
	cout << "1.search for word " << endl;
	cout << "2.search by book name " << endl;
	cout << "3.search by author name " << endl;
	cout << "4.search by book ID " << endl;
	cout << "5.search by category " << endl;
	cout << "6.search by published year " << endl;
	cout << "7.display all books " << endl;
	cout << "8.add book " << endl;
	cout << "9.delete book " << endl;
	cout << "10.modify book " << endl;
	cout << "11.exit" << endl;
	while (true)
	{
		int repeat = 0;
		cout << "enter your choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			searchForWord();
			break;
		case 2:
			searchByName();
			break;
		case 3:
			searchByAuthor();
			break;
		case 4:
			searchById();
			break;
		case 5:
			searchByCategory();
			break;
		case 6:
			searchByYear();
			break;
		case 7:
			displayAllBooks();
			break;
		case 8:
			addBook();
			break;
		case 9:
			deleteBook();
			break;
		case 10:
			modifyBook();
			break;
		case 11:
		{
			putBooksInFile();
			putReadersInFile();
			exit(0);
			break;
		}
		default:
		{
			repeat++;
			cout << "Invalid choice" << endl;
			break;
		}
		}
		if (repeat = 0)
			break;
	}
}

void putBooksInFile()
{
	fs.open("books.txt", ios::out | ios::trunc);
	ofstream file;
	if (!fs)
		cout << "File not found !" << endl;
	else
	{
		system("CLS");
		for (int i = 0; i < bookNum; i++)
		{
			if (book[i].bookName == " ")
				continue;

			fs << book[i].bookName << "|" << book[i].authorName << "|" << book[i].bookId << "|" << book[i].category << "|" << book[i].publishedYear << '\n';
		}
	}
	fs.close();
}
void putReadersInFile()
{
	fs.open("readers.txt", ios::out | ios::trunc);
	if (!fs)
		cout << "file not found !" << endl;
	else
	{
		for (int i = 0; i < readerNum; i++)
			fs << reader[i].Name << "|" << reader[i].password << '\n';
	}
	fs.close();
}
