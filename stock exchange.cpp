#include <iostream>
#include<string.h>
#include<cstring>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include <sstream>
#include <mysql.h>
#include<iomanip>
#include<windows.h>
#include<math.h>
#include<random>
#include<cstdlib>

using namespace std;
class User{
    string stock;
    string symbol;
    string exchange;
    int price;
    int quantity;

    public:

    User(const string& stock_, const string& symbol_, const string& exchange_, int price_, int quantity_):
        stock(stock_), symbol(symbol_), exchange(exchange_), price(price_), quantity(quantity_) {}
    virtual ~User() {}
    virtual string to_string() const {
        stringstream ss;
        ss << "Stock Name: "<< stock << ", Symbol: "<< symbol<<", Exchange: "<< exchange <<", Price: " << price << ", Quantity: " << quantity;
        return ss.str();
    }
    virtual string to_sql() const {
        stringstream ss;
          ss << "\"" << stock << "\", \"" << symbol << "\", \"" << exchange << "\", " << price << ", " << quantity;
        return ss.str();
    }
     friend void insert_user(MYSQL *conn, const User& user);
     };



// Stock class
class Stock {
private:
     string name;
    string symbol;
    string exchange;
    double price;
    double volume;
public:
    Stock(const string& name_, const string& symbol_, const string& exchange_, int price_, double volume_):
        name(name_), symbol(symbol_), exchange(exchange_), price(price_), volume(volume_) {}
    virtual ~Stock() {}
    virtual string to_string() const {
        stringstream ss;
        ss << "Name: "<< name << ", Symbol: "<< symbol<<", Exchange: "<< exchange <<", Price: " << price << ", Volume: " << volume;
        return ss.str();
    }
    virtual string to_sql() const {
        stringstream ss;
          ss << "\"" << name << "\", \"" << symbol << "\", \"" << exchange << "\", " << price << ", " << volume;
        return ss.str();
    }
     friend void insert_stock(MYSQL *conn, const Stock& stock);

};

// Currency class
class Currency  {
private:
     string name;
    string symbol;
    string exchange;
    double exchange_rate;
public:
    Currency(const string& name_, const string& symbol_, const string& exchange_, int exchange_rate_) :
         name(name_), symbol(symbol_), exchange(exchange_), exchange_rate(exchange_rate_) {}
    virtual ~Currency() {}
    virtual string to_string() const {
        stringstream ss;
        ss << "Name: "<<name<< ", Symbol: "<<symbol<<", Exchange: "<<exchange<<", Exchange_rate: " << exchange_rate;
        return ss.str();
    }
    virtual string to_sql() const {
        stringstream ss;
  ss << "\"" << name << "\", \"" << symbol << "\", \"" << exchange << "\", " << exchange_rate;
        return ss.str();
    }
     friend void insert_currency(MYSQL *conn, const Currency& currency);
};

// Crypto class
class Crypto {
private:
     string name;
    string symbol;
    string exchange;
    double price;
public:
    Crypto(const string& name_, const string& symbol_, const string& exchange_, int price_) :
         name(name_), symbol(symbol_), exchange(exchange_), price(price_) {}
    virtual ~Crypto() {}
    virtual string to_string() const {
        stringstream ss;
        ss << "Name: "<<name<< ", Symbol: "<<symbol<<", Exchange: "<<exchange<<", Price: " << price;
        return ss.str();
    }
    virtual string to_sql() const {
        stringstream ss;
      ss << "\"" << name << "\", \"" << symbol << "\", \"" << exchange << "\", " << price;
        return ss.str();
    }
     friend void insert_crypto(MYSQL *conn, const Crypto& crypto);
};

// Energy class
class Energy  {
private:
     string name;
    string symbol;
    string exchange;
    double price;
public:
    Energy(const string& name_, const string& symbol_, const string& exchange_, double price_) :
         name(name_), symbol(symbol_), exchange(exchange_), price(price_) {}
    virtual ~Energy() {}
    virtual string to_string() const {
        stringstream ss;
        ss << "Name: "<<name<< ", Symbol: "<<symbol<<", Exchange: "<<exchange<<", Price: " << price;
        return ss.str();
    }
    virtual string to_sql() const {
        stringstream ss;
      ss << "\"" << name << "\", \"" << symbol << "\", \"" << exchange << "\", " << price;
        return ss.str();
    }
     friend void insert_energy(MYSQL *conn, const Energy& energy);
};

// Metal class
class Metal {
private:
     string name;
    string symbol;
    string exchange;
    double price;
public:
    Metal(const string& name_, const string& symbol_, const string& exchange_, int price_) :
         name(name_), symbol(symbol_), exchange(exchange_), price(price_) {}
virtual ~Metal() {}
virtual string to_string() const {
    stringstream ss;
     ss << "Name: "<<name<< ", Symbol: "<<symbol<<", Exchange: "<<exchange<<"Price: " << price;
    return ss.str();
}
virtual string to_sql() const {
    stringstream ss;
   ss << "\"" << name << "\", \"" << symbol << "\", \"" << exchange << "\", " << price;
    return ss.str();
}
 friend void insert_metal(MYSQL *conn, const Metal& metal);
};

//function definition
void insert_user(MYSQL *conn, const User& user)
 {
       string table_name = "user_details";
          const string values = user.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, price, quantity) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }
}
 void insert_stock(MYSQL *conn, const Stock& stock)
 {
       string table_name = "stock";
          const string values = stock.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, price, volume) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

 }
  void insert_currency(MYSQL *conn, const Currency& currency)
 {
       string table_name = "currency";
          const string values = currency.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, exchange_rate) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

 }
 void insert_crypto(MYSQL *conn, const Crypto& crypto)
 {
       string table_name = "crypto";
          const string values = crypto.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, price) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }


 }
   void insert_metal(MYSQL *conn, const Metal& metal)
 {
       string table_name = "metal";
          const string values = metal.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, price) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }


 }
   void insert_energy(MYSQL *conn, const Energy& energy)
 {
       string table_name = "energy";
          const string values = energy.to_sql();
    string query = "INSERT INTO " + table_name + " (name, symbol, exchange, price) VALUES (" + values + ")";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

 }

class signup{
    private:
    string username;
    string password;
    int aadharno;
    int panno;
    int phoneno;
    int bankaccountno;
    int bankbalance;

    public:
    //string uname, string uid, int ano, int pno, int phno, int bano
    string uname, pass;
    int ano, pno, phno, bano, bal;


    void setdata(){
        username = uname;
        aadharno = ano;
        panno = pno;
        phoneno = phno;
        bankaccountno = bano;
        bankbalance = bal;
    }



    void getdata(){
        ofstream file1("user.txt");
        cout << "Enter the desired username\n";
        cin>>uname;
        file1 << uname << "\n";
        cout << "Enter your password\n";
        cin>>pass;
        file1 << pass << "\n";
        cout << "Enter your Aadhar number\n";
        cin >> ano;
        file1 << ano << "\n";
        cout << "Enter your Pan number\n";
        cin >> pno;
        file1 << pno << "\n";
        cout << "Enter your Phone number\n";
        cin >> phno;
        file1 << phno << "\n";
        cout << "Enter your Bank Account number\n";
        cin >> bano;
        file1 << bano << "\n";
        cout << "How much money would you like to deposit in your Hindustan Trade Account ?\n";
        cin >> bal;
        file1 << bal << "\n";
        cout<<"Money deposited successfully"<<endl;
        cout<<endl;
        cout<<"You are successfully signed in ";
        Sleep(1000);

    }

};

class login : public signup{
    public:
    void getdata_login(){
    ifstream file1("user.txt");
    string username2, password2,line;
    //file1 >> username2 >> password2;
      getline(file1, line);
      username2 = line;

        // Move the pointer to the next line
        getline(file1, line);
        password2 = line;

        file1.close();
    string username_login, password_login;
    cout << "Enter your username\n";
    cin >> username_login;
    cout << "\nEnter your password\n";
    cin >> password_login;
    if(username_login == username2 && password_login == password2)
    {
            Sleep(1000);
    cout << endl<<"You are succesfully logged in Hindustan Trade";
    }
    else{
    cout << "Wrong information \n";
    cout << "Please signup before login";
    exit(0);
    }
    }
};

string space(int l)
{
 string st = "";
 for(int m = 0; m < l ; m ++)
 {
     st = st + "--";
 }
 return st;
}
void  grapher_crypto(int crypto_price)

{
int count = 5;
int arr[count];
int price = crypto_price;
srand(time(NULL));
  for(int f = 0; f < count; f ++ )
  {
     if(f == 0)
     {
         arr[0] = crypto_price;
     }
     else if(true)
     {
    arr[f] = price + (rand()%5)*500*pow((-1),rand());
    price = arr[f];
     }
  }




    bool visited[count] = { false };
    int new_value =5000;

    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            for (int j = i + 1; j < count; j++) {
                if (arr[i] == arr[j]) {
                    arr[j] = new_value;
                    visited[j] = true;
                    new_value = (new_value + 500) % 10001;
                    if (new_value < 5000) new_value += 5000;
                }
            }
        }
    }






    for (int p = 0; p < count; p++) {
      cout<<"The Price of the cryptocurrency "<<p<<" months before was"<<arr[p]<<endl;
    }


cout<<"The following is the graph for the crypto"<<endl<<endl;

for(int c  = 10000; c >= 5000; c -= 500)
{
    cout<<c;
    for(int k = 0; k < count; k++)
    {
        if(c == arr[k])
        {
          cout<<space(count - k -1)<<"*";
        }
        else
          continue;
    }
    cout<<endl;
}
cout<<"    ";
for(int g = (count-1); g>=0; g--)
{
   cout<<g;
   cout<<" ";


}

}
void  grapher_stock(int stock_price)
{

int count = 10;
int arr[count];
int price = stock_price;
srand(time(NULL));
  for(int f = 0; f < count; f ++ )
  {
     if(f == (count-1))
     {
         arr[(count-1)] = stock_price;
     }
     else if(true)
     {
    arr[f] = price + (rand()%5)*10*pow((-1),rand());
    price = arr[f];
     }
  }




    bool visited[count] = { false };
    int new_value = 500;

    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            for (int j = i + 1; j < count; j++) {
                if (arr[i] == arr[j]) {
                    arr[j] = new_value;
                    visited[j] = true;
                    new_value = (new_value + 10) % 801;
                    if (new_value < 500) new_value += 500;
                }
            }
        }
    }






    for (int p = 0; p < count; p++) {
      cout<<"The Price of the stock "<<p<<" months before was "<<arr[p]<<endl;
    }


cout<<"The following is the graph for the stock"<<endl<<endl;

for(int c  = 800; c >= 500; c -= 10 )
{
    cout<<c;
    for(int k = 0; k < count; k++)
    {
        if(c == arr[k])
        {
          cout<<space(k)<<"*";
        }
        else
          continue;
    }
    cout<<endl;
}
cout<<"   ";
for(int g = (count-1); g>=0; g--)
{
   cout<<g;
   cout<<" ";


}

}
void  grapher_forex(int forex_price)
{
int count = 5;
int arr[count];
int price = forex_price;
srand(time(NULL));
  for(int f = 0; f < count; f ++ )
  {
     if(f == 0)
     {
         arr[0] = forex_price;
     }
     else if(true)
     {
    arr[f] = price + (rand()%5)*10*pow((-1),rand());
    price = arr[f];
     }
  }




    bool visited[count] = { false };
    int new_value = 10;

    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            for (int j = i + 1; j < count; j++) {
                if (arr[i] == arr[j]) {
                    arr[j] = new_value;
                    visited[j] = true;
                    new_value = (new_value + 10) % 101;
                    if (new_value < 10) new_value += 10;
                }
            }
        }
    }






    for (int p = 0; p < count; p++) {
      cout<<"The Price of the currency "<<p<<" months before was"<<arr[p]<<endl;
    }


cout<<"The following is the graph for that currency"<<endl<<endl;

for(int c  =100; c >= 0; c -= 10 )
{
    cout<<c;
    for(int k = 0; k < count; k++)
    {
        if(c == arr[k])
        {
          cout<<space(count - k - 1)<<"*";
        }
        else
          continue;
    }
    cout<<endl;
}
cout<<"  ";
for(int g = (count-1); g>=0; g--)
{
   cout<<g;
   cout<<" ";


}

}


void  grapher_metal(int metal_price)
{
int count = 5;
int arr[count];
int price = metal_price;
srand(time(NULL));
  for(int f = 0; f < count; f ++ )
  {
     if(f == 0)
     {
         arr[0] = metal_price;
     }
     else if(true)
     {
    arr[f] = price + (rand()%5)*1000*pow((-1),rand());
    price = arr[f];
     }
  }




    bool visited[count] = { false };
    int new_value = 10000;

    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            for (int j = i + 1; j < count; j++) {
                if (arr[i] == arr[j]) {
                    arr[j] = new_value;
                    visited[j] = true;
                    new_value = (new_value + 1000) % 20001;
                    if (new_value < 10000) new_value += 10000;
                }
            }
        }
    }






    for (int p = 0; p < count; p++) {
      cout<<"The Price of the metal "<<p<<" months before was"<<arr[p]<<endl;
    }


cout<<"The following is the graph for the metal"<<endl<<endl;

for(int c  = 20000; c >= 10000; c -= 1000 )
{
    cout<<c;
    for(int k = 0; k < count; k++)
    {
        if(c == arr[k])
        {
          cout<<space(count - k- 1)<<"*";
        }
        else
          continue;
    }
    cout<<endl;
}
cout<<"     ";
for(int g = (count-1); g>=0; g--)
{
   cout<<g;
   cout<<" ";


}

}


void updateFile(int assetValue) {
    fstream file("user.txt");


    // Move the file pointer
    string line;
    for (int i = 1; i <= 6; i++) {
        getline(file, line);
    }
    int currentValue = stoi(line);
   int newValue = currentValue - assetValue;

    // Update the value
    file.seekp(file.tellg());
    file << newValue;
    file.close();
}




int main()
{  // Create a connection to MySQL database
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!conn) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }
    conn = mysql_real_connect(conn, "localhost", "aayush", "metro26", "trading", 0, NULL, 0);
    if (!conn) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }
    cout << "Connected successfully!" << endl;


    // Create table for User Details
    mysql_query(conn, "CREATE TABLE user_details ("
                      "userid INT(11) NOT NULL AUTO_INCREMENT,"
                      "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "price INT NOT NULL,"
                      "quantity INT NOT NULL,"
                      "PRIMARY KEY (userid)"
                      ");");
    // Create table for Stock
    mysql_query(conn, "CREATE TABLE stock ("
                      "id INT(11) NOT NULL AUTO_INCREMENT,"
                       "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "price INT NOT NULL,"
                      "volume DOUBLE NOT NULL,"
                      "PRIMARY KEY (id)"
                      ");");

    // Create table for Currency
    mysql_query(conn, "CREATE TABLE currency ("
                      "id INT(11) NOT NULL AUTO_INCREMENT,"
                       "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "exchange_rate INT NOT NULL,"
                      "PRIMARY KEY (id)"
                      ");");

    // Create table for Crypto
    mysql_query(conn, "CREATE TABLE crypto ("
                      "id INT(11) NOT NULL AUTO_INCREMENT,"
                       "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "price INT NOT NULL,"
                      "PRIMARY KEY (id)"
                      ");");

    // Create table for Energy
    mysql_query(conn, "CREATE TABLE energy ("
                      "id INT(11) NOT NULL AUTO_INCREMENT,"
                       "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "price DOUBLE NOT NULL,"
                      "PRIMARY KEY (id)"
                      ");");

    // Create table for Metal
    mysql_query(conn, "CREATE TABLE metal ("
                      "id INT(11) NOT NULL AUTO_INCREMENT,"
                       "name VARCHAR(255) NOT NULL,"
                      "symbol VARCHAR(10) NOT NULL,"
                      "exchange VARCHAR(50) NOT NULL,"
                      "price INT NOT NULL,"
                      "PRIMARY KEY (id)"
                      ");");

    //insert values
   Stock stock1("Apple Inc.", "AAPL", "NASDAQ", 630, 100000);
insert_stock(conn, stock1);

Stock stock2("Microsoft Corporation", "MSFT", "NASDAQ", 620, 75000);
insert_stock(conn, stock2);

Stock stock3("Amazon.com, Inc.", "AMZN", "NASDAQ", 690, 5000);
insert_stock(conn, stock3);

Stock stock4("Facebook, Inc.", "FB", "NASDAQ", 610, 120000);
insert_stock(conn, stock4);

Stock stock5("Tesla, Inc.", "TSLA", "NASDAQ", 630, 25000);
insert_stock(conn, stock5);

Stock stock6("Alphabet Inc.", "GOOGL", "NASDAQ", 650, 45000);
insert_stock(conn, stock6);

Stock stock7("Johnson & Johnson", "JNJ", "NYSE", 660, 30000);
insert_stock(conn, stock7);

Stock stock8("Procter & Gamble Company", "PG", "NYSE", 680, 40000);
insert_stock(conn, stock8);

Stock stock9("Coca-Cola Company", "KO", "NYSE", 640, 60000);
insert_stock(conn, stock9);

Stock stock10("Walmart Inc.", "WMT", "NYSE", 660, 80000);
insert_stock(conn, stock10);


Currency currency1("Euro", "EUR", "FOREX", 60);
insert_currency(conn, currency1);

Currency currency2("US Dollar", "USD", "FOREX", 50);
insert_currency(conn, currency2);

Currency currency3("British Pound", "GBP", "FOREX", 70);
insert_currency(conn, currency3);

Currency currency4("Japanese Yen", "JPY", "FOREX", 20);
insert_currency(conn, currency4);

Currency currency5("Swiss Franc", "CHF", "FOREX", 80);
insert_currency(conn, currency5);

Currency currency6("Australian Dollar", "AUD", "FOREX", 30);
insert_currency(conn, currency6);

Currency currency7("Canadian Dollar", "CAD", "FOREX", 60);
insert_currency(conn, currency7);

Currency currency8("Chinese Yuan", "CNY", "FOREX", 90);
insert_currency(conn, currency8);

Currency currency9("Indian Rupee", "INR", "FOREX", 80);
insert_currency(conn, currency9);

Currency currency10("Brazilian Real", "BRL", "FOREX", 50);
insert_currency(conn, currency10);


Crypto crypto1("Bitcoin", "BTC", "BITFINEX", 5500);
insert_crypto(conn, crypto1);

Crypto crypto2("Ethereum", "ETH", "BINANCE", 6500);
insert_crypto(conn, crypto2);

Crypto crypto3("Binance Coin", "BNB", "KUCOIN", 7000);
insert_crypto(conn, crypto3);

Crypto crypto4("Cardano", "ADA", "HUOBI", 8500);
insert_crypto(conn, crypto4);

Crypto crypto5("XRP", "XRP", "OKEX", 6000);
insert_crypto(conn, crypto5);

Crypto crypto6("Dogecoin", "DOGE", "BITTREX", 8000);
insert_crypto(conn, crypto6);

Crypto crypto7("Litecoin", "LTC", "BITMAX", 9500);
insert_crypto(conn, crypto7);

Crypto crypto8("Bitcoin Cash", "BCH", "COINBASE", 6000);
insert_crypto(conn, crypto8);

Crypto crypto9("Chainlink", "LINK", "HITBTC", 7500);
insert_crypto(conn, crypto9);

Crypto crypto10("Polkadot", "DOT", "FTX", 8500);
insert_crypto(conn, crypto10);

Energy energy1("Crude Oil", "CL", "NYMEX", 65.77);
insert_energy(conn, energy1);

Energy energy2("Natural Gas", "NG", "NYMEX", 3.98);
insert_energy(conn, energy2);

Energy energy3("Brent Crude Oil", "BZ", "ICE", 68.53);
insert_energy(conn, energy3);

Energy energy4("Gasoline", "RB", "NYMEX", 2.17);
insert_energy(conn, energy4);

Energy energy5("Heating Oil", "HO", "NYMEX", 2.04);
insert_energy(conn, energy5);

Energy energy6("Propane", "PB", "NYMEX", 0.92);
insert_energy(conn, energy6);

Energy energy7("Coal", "C", "CME", 119.10);
insert_energy(conn, energy7);

Energy energy8("Ethanol", "EH", "CBOT", 1.68);
insert_energy(conn, energy8);

Energy energy9("Uranium", "UX", "CME", 45.00);
insert_energy(conn, energy9);

Energy energy10("RBOB Gasoline", "XB", "NYMEX", 2.15);
insert_energy(conn, energy10);

Metal metal1("Gold", "GC", "COMEX", 13000);
insert_metal(conn, metal1);

Metal metal2("Silver", "SI", "COMEX", 12000);
insert_metal(conn, metal2);

Metal metal3("Platinum", "PL", "NYMEX", 16000);
insert_metal(conn, metal3);

Metal metal4("Palladium", "PA", "NYMEX", 17000);
insert_metal(conn, metal4);

Metal metal5("Copper", "HG", "COMEX", 14000);
insert_metal(conn, metal5);

Metal metal6("Aluminum", "AL", "LME", 20000);
insert_metal(conn, metal6);

Metal metal7("Zinc", "ZC", "LME", 12000);
insert_metal(conn, metal7);

Metal metal8("Lead", "PB", "LME", 13000);
insert_metal(conn, metal8);

Metal metal9("Nickel", "NI", "LME", 12000);
insert_metal(conn, metal9);

Metal metal10("Tin", "SN", "LME", 15000);
insert_metal(conn, metal10);



cout<<endl<<endl;

cout<<"                       ******************************************************************************";
cout<<endl<<endl<<endl;
cout<< setw(70);
cout<<"Welcome to Hindustan Trade"<<endl<<endl<<endl;

cout<<"                       ******************************************************************************"<<endl<<endl;
Sleep(1000);
cout<<setw(70);
cout<<endl<<"This is a model trading platform which simulates a trading environment wherein the user can buy and sell assets such as: "<<endl;
cout<<setw(90);
cout<<"STOCKS  ENERGY METALS  CRYPTOCURRENCY  FOREX "<<endl;
Sleep(1000);
cout<<endl<<endl;
cout<<setw(70);
cout<<"Login (1) "<<endl<<endl;
cout<<setw(65);
cout<<"OR"<<endl<<endl;
cout<<setw(70);
cout<<"Sign up (2)"<<endl<<endl;

int login_signup;
cout << "Press 1 for login and 2 for signup\n";
cin >> login_signup;
signup s1;
login l1;
if(login_signup == 2){
s1.getdata();
s1.setdata();
}
else if(login_signup==1)
{
cout << "\nPlease enter your details for login in Hindustan Trade \n";
l1.getdata_login();
}
while(true)
    {
int switch1;
cout<<endl<<"Press 1. for Mainmenu "<<endl;
cout<<"Press 2. to Exit program "<<endl;
cin>>switch1;
switch(switch1){
case 1:
cout<<endl<<endl;
cout<<"Press the corresponding digit to view following details "<<endl;
cout<<"1. Profile "<<endl;
cout<<"2. Portfolio "<<endl;
cout<<"3. Market "<<endl;
Sleep(1000);
int view;
cout<<endl;
cin >> view;
cout<<endl;
if(view == 1){
cout<<setw(60)<<"Profile"<<endl;
ifstream myfile("user.txt");
    string line1;
      getline(myfile, line1);
        cout <<setw(60) <<"Username : "<<line1 << endl;
         getline(myfile, line1);
        cout <<setw(60) <<"Password : "<<line1 << endl;
         getline(myfile, line1);
        cout <<setw(60) <<"Adhaar Number : "<<line1 << endl;
         getline(myfile, line1);
        cout <<setw(60) <<"PAN Number : "<<line1 << endl;
         getline(myfile, line1);
        cout <<setw(60) <<"Phone Number : "<<line1 << endl;
         getline(myfile, line1);
        cout <<setw(60) <<"Account Number : "<<line1 << endl;
        getline(myfile, line1);
        cout <<setw(60) <<"Balance : "<<line1 << endl;

       myfile.close();

}
else if (view == 2)
    {
        MYSQL_RES *result;
MYSQL_ROW row;

string query = "SELECT * FROM user_details";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    int price = atof(row[4]);
    int quantity = atof(row[5]);

    User user(name, symbol, exchange, price,quantity);
    cout << user.to_string() << endl;
}

mysql_free_result(result);
    }

else if(view == 3){
        int flag=0;
        while(flag==0){
                int switch2;
        cout<<endl<<"Press 1. for Market";
        cout<<endl<<"Press 2. for Menu"<<endl<<endl;
        cin>>switch2;
        switch(switch2){
            case 1:
    int asset;
    cout<<endl<<"Which asset would you like to trade in ?"<<endl;
    cout<<"1. Stocks"<<endl;
    cout<<"2. Forex"<<endl;
    cout<<"3. Cryptocurrencies"<<endl;
    cout<<"4. Energy"<<endl;
    cout<<"5. Metals"<<endl<<endl;

    cin >> asset;

    if (asset == 1)
    {
        MYSQL_RES *result, *result1;
MYSQL_ROW row;

string query = "SELECT * FROM stock";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    double price = atof(row[4]);
    double volume = atof(row[5]);

    Stock stock(name, symbol, exchange, price, volume);
    cout << stock.to_string() << endl;

}

mysql_free_result(result);
int a_price,qty;
int yn_trade;
string obj;
cout << endl << "Would you like to Trade " << endl;
cout << "Press 1 for yes or 2 for no" << endl;
cin >> yn_trade;

if (yn_trade == 1) {
    cout << "Enter symbol of object " << endl;
    cin >> obj;
    stringstream ss;
    ss << "SELECT price FROM stock WHERE symbol = \"" << obj << "\"";
    const string query = ss.str();

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if (row) {
        a_price = atof(row[0]);
        cout << "The price of  " << obj << " is " << a_price << endl;
        cout<<"Enter quantity of stock to purchase"<<endl;
        cin>>qty;
        cout<<"Total amount will be  "<<qty*a_price<<endl;
        Sleep(1000);
        cout<<endl<<"Transaction successful"<<endl;
        int value=qty*a_price;
        updateFile(value);

    }

    mysql_free_result(result);
   /* // update portfolio
    stringstream ss1;
    ss1 << "SELECT * FROM stock WHERE symbol = \"" << obj << "\"";
    const string query1 = ss1.str();

    result1 = mysql_store_result(conn);
    row = mysql_fetch_row(result1);
    if (row) {
    string name1 = row[1];
    string symbol1 = row[2];
    string exchange1 = row[3];
    double price1 = atof(row[4]);
    int volume1 = qty;

    User user1(name1, symbol1, exchange1, price1, volume1);
    insert_user(conn, user1);

    }
     mysql_free_result(result1);*/


    int graph;
    cout<<"Would you like to view past 9 month trend of this stock"<<endl;
    cout<<"Press 1. for yes 2. for no"<<endl;
    cin>>graph;
    if(graph==1)
    {
        grapher_stock(a_price);
    }
    else {
        cout << "Object not found" << endl;
    }
}
}



else if (asset == 2)
    {
        MYSQL_RES *result;
MYSQL_ROW row;

string query = "SELECT * FROM currency";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    double exchange_rate = atof(row[4]);

    Currency currency(name, symbol, exchange, exchange_rate);
    cout << currency.to_string() << endl;
}

mysql_free_result(result);
int a_price,qty;
int yn_trade;
string obj;
cout << endl << "Would you like to Trade " << endl;
cout << "Press 1 for yes or 2 for no" << endl;
cin >> yn_trade;

if (yn_trade == 1) {
    cout << "Enter symbol of object " << endl;
    cin >> obj;
    stringstream ss;
    ss << "SELECT exchange_rate FROM currency WHERE symbol = \"" << obj << "\"";
    const string query = ss.str();

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if (row) {
        a_price = atof(row[0]);
        cout << "The price of  " << obj << " is " << a_price << endl;
        cout<<"Enter quantity of currency to purchase"<<endl;
        cin>>qty;
        cout<<"Total amount will be  "<<qty*a_price<<endl;
        Sleep(1000);
        cout<<endl<<"Transaction successful"<<endl;
         int value=qty*a_price;
        updateFile(value);
    } else {
        cout << "Object not found" << endl;
    }

    mysql_free_result(result);
    int graph;
    cout<<endl<<"Would you like to view past 9 month trend of this currency"<<endl;
    cout<<"Press 1. for yes 2. for no"<<endl;
    cin>>graph;
    if(graph==1)
    {
        grapher_forex(a_price);
    }

}}
else if (asset == 3)
    {
        MYSQL_RES *result;
MYSQL_ROW row;

string query = "SELECT * FROM crypto";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    double price = atof(row[4]);

    Crypto crypto(name, symbol, exchange, price);
    cout << crypto.to_string() << endl;
}

mysql_free_result(result);
int a_price,qty;
int yn_trade;
string obj;
cout << endl << "Would you like to Trade " << endl;
cout << "Press 1 for yes or 2 for no" << endl;
cin >> yn_trade;

if (yn_trade == 1) {
    cout << "Enter symbol of object " << endl;
    cin >> obj;
    stringstream ss;
    ss << "SELECT price FROM crypto WHERE symbol = \"" << obj << "\"";
    const string query = ss.str();

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if (row) {
        a_price = atof(row[0]);
        cout << "The price of  " << obj << " is " << a_price << endl;
        cout<<"Enter quantity of crypto to purchase"<<endl;
        cin>>qty;
        cout<<"Total amount will be  "<<qty*a_price<<endl;
        Sleep(1000);
        cout<<endl<<"Transaction successful"<<endl;
         int value=qty*a_price;
        updateFile(value);
    } else {
        cout << "Object not found" << endl;
    }

    mysql_free_result(result);
    int graph;
    cout<<"Would you like to view past 9 month trend of this crypto"<<endl;
    cout<<"Press 1. for yes 2. for no"<<endl;
    cin>>graph;
    if(graph==1)
    {
        grapher_crypto(a_price);
    }

}
    }
else if (asset == 4)
    {
        MYSQL_RES *result;
MYSQL_ROW row;

string query = "SELECT * FROM energy";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    double price = atof(row[4]);

    Energy energy(name, symbol, exchange, price);
    cout << energy.to_string() << endl;
}

mysql_free_result(result);
int a_price,qty;
int yn_trade;
string obj;
cout << endl << "Would you like to Trade " << endl;
cout << "Press 1 for yes or 2 for no" << endl;
cin >> yn_trade;

if (yn_trade == 1) {
    cout << "Enter symbol of object " << endl;
    cin >> obj;
    stringstream ss;
    ss << "SELECT price FROM energy WHERE symbol = \"" << obj << "\"";
    const string query = ss.str();

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if (row) {
        a_price = atof(row[0]);
        cout << "The price of  " << obj << " is " << a_price << endl;
        cout<<"Enter quantity of energy to purchase"<<endl;
        cin>>qty;
        cout<<"Total amount will be  "<<qty*a_price<<endl;
        Sleep(1000);
        cout<<endl<<"Transaction successful"<<endl;
         int value=qty*a_price;
        updateFile(value);
    } else {
        cout << "Object not found" << endl;
    }

    mysql_free_result(result);


}
    }
else if (asset == 5)
    {
        MYSQL_RES *result;
MYSQL_ROW row;

string query = "SELECT * FROM metal";

if (mysql_query(conn, query.c_str())) {
    cout << "Error: " << mysql_error(conn) << endl;
    exit(1);
}

result = mysql_store_result(conn);

while ((row = mysql_fetch_row(result))) {
    string name = row[1];
    string symbol = row[2];
    string exchange = row[3];
    double price = atof(row[4]);

    Metal metal(name, symbol, exchange, price);
    cout << metal.to_string() << endl;
}

mysql_free_result(result);
int a_price,qty;
int yn_trade;
string obj;
cout << endl << "Would you like to Trade " << endl;
cout << "Press 1 for yes or 2 for no" << endl;
cin >> yn_trade;

if (yn_trade == 1) {
    cout << "Enter symbol of object " << endl;
    cin >> obj;
    stringstream ss;
    ss << "SELECT price FROM metal WHERE symbol = \"" << obj << "\"";
    const string query = ss.str();

    if (mysql_query(conn, query.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
        exit(1);
    }

    result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if (row) {
        a_price = atof(row[0]);
        cout << "The price of  " << obj << " is " << a_price << endl;
        cout<<"Enter quantity of metal to purchase"<<endl;
        cin>>qty;
        cout<<"Total amount will be  "<<qty*a_price<<endl;
        Sleep(1000);
        cout<<endl<<"Transaction successful"<<endl;
         int value=qty*a_price;
        updateFile(value);
    } else {
        cout << "Object not found" << endl;
    }

    mysql_free_result(result);
     int graph;
    cout<<"Would you like to view past 9 month trend of this energy"<<endl;
    cout<<"Press 1. for yes 2. for no"<<endl;
    cin>>graph;
    if(graph==1)
    {
        grapher_metal(a_price);
    }

}
    }

     break;
     case 2:
    flag=1;
             }
     }
}
     break;
 case 2:
     exit(0);
     default:
        // invalid choice
        cout << "Invalid choice\n";
        break;
}



}
}





