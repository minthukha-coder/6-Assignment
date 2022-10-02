// Book shop management

#include<iostream>
using namespace std;

class Book{

public:
    int i = 0;
    int locate = 0;
    int id[100];
    string name[100];
    string author[100];
    string publisher[100];
    int year[100];
    int price[100];
    int quantity[100];
    int add();
    int display();
    int buy();
    int mainMenu();
    int update();
    int cost();
    Book(){
    cout << "********Welcome to our book shop*********" << endl;
    }

};


    int Book::add(){

        int nId;
        string nName;
        string nAuthor;
        string nPublisher;
        int nYear;
        int nPrice;
        int nQuantity;

        cout << "Enter book id: ";
        cin >> nId;
        cout << "Enter book name: ";
        cin >> nName;
        cout << "Enter book author: ";
        cin >> nAuthor;
        cout << "Enter book publisher: ";
        cin >> nPublisher;
        cout << "Enter book year: ";
        cin >> nYear;
        cout << "Enter book price: ";
        cin >> nPrice;
        cout << "Enter available book: ";
        cin >> nQuantity;
        id[locate] = nId;
        name[locate] = nName;
        author[locate] = nAuthor;
        publisher[locate] = nPublisher;
        year[locate] = nYear;
        price[locate] = nPrice;
        quantity[locate] = nQuantity;
        cout << "Book id: " << id[locate] << endl;
        cout << "Book name: " << name[locate] << endl;
        cout << "Author name: " << author[locate] << endl;
        cout << "Publisher name: " << publisher[locate] << endl;
        cout << "Year: " << year[locate] << endl;
        cout << "Price: " << price[locate] << endl;
        cout << "Quantity: " << quantity[locate] << endl;
        locate++;

    }


int Book::display(){
    for (i = 0;i < locate; i++){
    cout << "Book id: " << id[i] << endl;
    cout << "Book Name: " << name[i] << endl;
    cout << "Author Name: " << author[i] << endl;
    cout << "Publisher Name: " << publisher[i] << endl;
    cout << "Year: " << year[i] << endl;
    cout << "Price: " << price[i] << endl;
    cout << "The stock available: " << quantity[i] << endl << endl;
    }
}

int Book::buy(){
    string bName;
    string bAuthor;
    string ch;

    cout << "Please enter book's name you want to buy: ";
    cin >> bName;
    cout << "Please enter author name: ";
    cin >> bAuthor;
     for (i = 0; i < locate;i++){
    if (bName == name[i] && bAuthor == author[i] ){
    cout << "Book id: " << id[i] << endl;
    cout << "Book Name: " << name[i] << endl;
    cout << "Author Name: " << author[i] << endl;
    cout << "Publisher Name: " << publisher[i] << endl;
    cout << "Year: " << year[i] << endl;
    cout << "Price: " << price[i] << endl;
    cout << "The stock available: " << quantity[i] << endl << endl;


    cout << "If you are sure to buy / write yes: ";
    cin >> ch;
    if (ch == "yes"){
        cost();

    }else{
        cout << "We don't have this book" << endl;
    }
}
}
}


int Book::cost(){
    int buying = 0;
    cout << "How many book will you buy? ";
    cin >> buying;
    if (buying > quantity[i] ){
        cout << "We don't have enough books" << endl;
        cost();
    }else{
    price[i] = price[i] * buying;
    cout << "The book's cost: " << price[i] << "$" << endl << endl;
    }
}

int Book::update(){

    string uName;
    int cPrice[100];
    int cQuantity[100];
    int option = 0;

    cout << "Please enter book's name to update: " << endl;
    cin >> uName;
    for (int i = 0;i < locate;i++){
    if (uName == name[i]){
        cout << "Press 1 to update price: " << endl;
        cout << "Press 2 to update stock available: " << endl;
        cin >> option;

        if (option == 1){
    cout << "Please enter new price: " << endl;
    cin >> cPrice[i];

    cout << "Book id: " << id[i] << endl;
    cout << "Book Name: " << name[i] << endl;
    cout << "Author Name: " << author[i] << endl;
    cout << "Publisher Name: " << publisher[i] << endl;
    cout << "Year: " << year[i] << endl;
    cout << "Price: " << cPrice[i] << endl;
    cout << "The stock available: " << quantity[i] << endl << endl;


    }else if (option == 2){
        cout << "Please enter new stock available: ";
        cin >> cQuantity[i];
        for (int i = 0;i < locate;i++){
    cout << "Book id: " << id[i] << endl;
    cout << "Book Name: " << name[i] << endl;
    cout << "Author Name: " << author[i] << endl;
    cout << "Publisher Name: " << publisher[i] << endl;
    cout << "Year: " << year[i] << endl;
    cout << "Price: " << price[i] << endl;
    cout << "The stock available: " << cQuantity[i] << endl << endl;

        }

    }else{
    cout << "Invalid option!";
    update();
    }



}
}
}


int Book::mainMenu(){
    int option = 0;
    int check = 0;
    cout << "For Book shop owner: Press 1" << endl;
    cout << "For Customer: Press 2 " << endl;
    cin >> option;
    while(true){
    if (option == 1){
    cout << "Press 1 to add book: " << endl;
    cout << "Press 2 to update book: "<< endl;
    cout << "Press 3 to choose owner or customer: " << endl;
    cout << "Press 4 to quit: " << endl;
    cin >> check;

    if (check == 1){
        add();
    }else if (check == 2){
        update();
    }else if (check == 3){
        mainMenu();
    }else if (check == 4){
        exit(0);

    }else{
        cout << "Choose again" << endl;
        mainMenu();
    }

    }else if(option == 2){
        cout << "Press 1 to show book " << endl;
        cout << "Press 2 to buy book " << endl;
        cout << "Press 3 to choose owner or customer " << endl;
        cout << "Press 4 to quit " << endl;
        cin >> check;

   if (check == 1){
       display();

    }else if (check == 2){
        display();

        buy();
    }else if ( check == 3){
        mainMenu();
    }else if (check == 4){
        exit(0);
    }
    }else{
    cout << "Invalid check" << endl;
    mainMenu();
    }
    }


}




int main(){
    Book obj;
    obj.mainMenu();

return 0;
}



