#include <iostream>
#include <string>
using namespace std;

// FavoriteMovies Item Class
class FavoriteMovies
{
private:
	int ID;
	static int IDGenerator;

	string movieTitle;
	string movieGenre;
	string movieCountry;
	int movieYearRealsed;
	int movieRating;

public:
	FavoriteMovies();
	void getFavoriteMovies();
	friend ostream& operator<<(ostream &o, FavoriteMovies& i);
	string getMoviewTitle();
};

// intialize the static variable to be used when generating the ID
int FavoriteMovies::IDGenerator = 1;

// FavoriteMovies List Class
class FavoriteMoviesList
{
private:
	int numItems;
	FavoriteMovies iList[101];
public:
	FavoriteMoviesList();
	void addItem();
	void showList();
	bool isInList(string title);
	int getThisID();
};
// FavoriteMovies List constructor
FavoriteMoviesList::FavoriteMoviesList()
{
	numItems = 0;


}
// Constructor
FavoriteMovies::FavoriteMovies()
{
	ID = IDGenerator++;
	movieTitle = "";
	movieGenre = "";
	movieCountry = "";
	movieYearRealsed = 0;
	movieRating = 0;

}
string FavoriteMovies::getMoviewTitle()
{
	string moviet;
	moviet = movieTitle;
	return moviet;
}
int FavoriteMoviesList::getThisID()
{
	int i;
	i = numItems;
	return i;
}
bool FavoriteMoviesList::isInList(string mTitle) // if an item(movieTitle)already exist, return true
{
	bool answer = false;
	string altTitle="";
	int i;
	int x = numItems;
	for (i = 0; i < x; i++)
	{
		altTitle = iList[i].getMoviewTitle();

		if (mTitle== altTitle)
		{
			answer= true;
			
			break;
		}
		else;
	}
	return answer;
}
// overloaded insertion operation << for printing object to the console
ostream& operator<<(ostream &o, FavoriteMovies& i)
{


	o << "ID: " << i.ID << endl;
	o << "name " << i.movieTitle << endl;
	o << "Genre " << i.movieGenre << endl;
	o << "Country " << i.movieCountry << endl;
	o << "Year of Realsed:" << i.movieYearRealsed << endl;
	o << "rating: " << i.movieRating << endl;


	return o;
}

// gets input from the user for the FavoriteMovies object
void FavoriteMovies::getFavoriteMovies()
{
	cout << "enter name" << endl;
	getline(cin, movieTitle); // Is this going where? possible to do this way? or do i need to find another? MovieList(string, string, string, int,int)? MovieList *iList=NULL?

	// How can I access the array index of movie title from here? 
	//Check see if the movie name is already in the array
	//Use For statement (linear search) to see if the value is still existing.
	//If the value is not in the list, add, if not, Say "the movie is already in the array. try diffrent."
	//call addFaovritemovies function (if the value is in the list)
	FavoriteMoviesList list;
	bool answer= list.isInList(movieTitle);
	if (answer == true)
	{
			getFavoriteMovies();
	}
	else
	{
		cout << "enter Genre:" << endl;
		getline(cin, movieGenre);
		cout << "enter Country:" << endl;
		getline(cin, movieCountry);
		cout << "enter Year of Realsed:" << endl;
		cin >> movieYearRealsed;
		cout << "enter rating:" << endl;
		cin >> movieRating;
		cin.ignore();
		cin.clear();
	}
}


// adds an FavoriteMovies item to the list
void FavoriteMoviesList::addItem()
{
	iList[numItems].getFavoriteMovies();
	numItems++; // keeps track of the number of items
	cout << numItems << endl;

}

// shows the contents of the list
void FavoriteMoviesList::showList()
{
	int i;
	for (i = 0; i < numItems; i++)
		cout << iList[i] << endl;
}

int main()
{
	int j;
	bool quit;
	FavoriteMoviesList myList; // create list object 
	string quitOrder;
	cout << "Welcome to my favorite movie tracker." << endl;
	cout << "Favorite things to be track" << endl;
	cout << endl;
	quit = false;
	for (int i = 0; i < 101; i++) // loop to add FavoriteMovies Items to the list
	{

		myList.addItem();
		cout << "-------Type Quit if you want to stop-----" << endl;
		getline(cin, quitOrder);
		if (quitOrder == "quit" || quitOrder == "Quit")
		{
			cout << endl;
			break;
		}
	}

	myList.showList();

	system("pause");
	return 0;
}