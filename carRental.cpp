#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;

class Cars
{
protected:
    static const int max_cars = 20;
    string car_color[20];
    string car_make_year[20];
    string car_fuel_type[20];
    int car_mileage[20];
    int car_seating_capacity[20];
    static int car_total;

public:
    Cars() // constructor
    {
        load_Cars("car.txt");
    }
    int getCarTotal() { return car_total; }
    string car_name[20];
    string car_model[20];
    int car_price[20];
    void initializeDefaultCars()
    {
        if (car_total == 0)
        {
            car_name[car_total] = "Alto";
            car_model[car_total] = "VX";
            car_color[car_total] = "White";
            car_make_year[car_total] = "2021";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 10000;
            car_price[car_total] = 1000;
            car_total++;

            car_name[car_total] = "Cultus";
            car_model[car_total] = "VXR";
            car_color[car_total] = "Silver";
            car_make_year[car_total] = "2022";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 15000;
            car_price[car_total] = 1500;
            car_total++;

            car_name[car_total] = "Mira";
            car_model[car_total] = "X";
            car_color[car_total] = "Blue";
            car_make_year[car_total] = "2020";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 17000;
            car_price[car_total] = 1700;
            car_total++;

            car_name[car_total] = "Corolla";
            car_model[car_total] = "Altis Grande";
            car_color[car_total] = "White";
            car_make_year[car_total] = "2021";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 15000;
            car_price[car_total] = 3000;
            car_total++;

            car_name[car_total] = "Civic";
            car_model[car_total] = "RS Turbo";
            car_color[car_total] = "Black";
            car_make_year[car_total] = "2021";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 20000;
            car_price[car_total] = 3000;
            car_total++;

            car_name[car_total] = "City";
            car_model[car_total] = "Aspire";
            car_color[car_total] = "Silver";
            car_make_year[car_total] = "2021";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 18000;
            car_price[car_total] = 2500;
            car_total++;

            car_name[car_total] = "Lexus";
            car_model[car_total] = "ZX";
            car_color[car_total] = "Black";
            car_make_year[car_total] = "2023";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 7;
            car_mileage[car_total] = 8000;
            car_price[car_total] = 5000;
            car_total++;

            car_name[car_total] = "BMW";
            car_model[car_total] = "i7";
            car_color[car_total] = "White";
            car_make_year[car_total] = "2022";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 5;
            car_mileage[car_total] = 7000;
            car_price[car_total] = 10000;
            car_total++;

            car_name[car_total] = "Haval";
            car_model[car_total] = "2.0T";
            car_color[car_total] = "White";
            car_make_year[car_total] = "2022";
            car_fuel_type[car_total] = "Petrol";
            car_seating_capacity[car_total] = 7;
            car_mileage[car_total] = 6000;
            car_price[car_total] = 4500;
            car_total++;
        }
    }
    friend class Rent; // friend Class
    void save_Cars(const string &filename)
    {
        ofstream car_file(filename);
        if (!car_file)
        {
            cout << "Unable to open file." << endl;
            return;
        }
        car_file << car_total << endl;
        for (int i = 0; i < car_total; i++)
        {
            car_file << car_name[i] << endl;
            car_file << car_model[i] << endl;
            car_file << car_color[i] << endl;
            car_file << car_make_year[i] << endl;
            car_file << car_fuel_type[i] << endl;
            car_file << car_mileage[i] << endl;
            car_file << car_seating_capacity[i] << endl;
            car_file << car_price[i] << endl;
        }
        car_file.close();
    }
    void load_Cars(const string &filename)
    {
        ifstream car_file(filename);
        if (!car_file)
        {
            cout << "Unable to open file." << endl;
            return;
        }
        car_file >> car_total;
        car_file.ignore();
        for (int i = 0; i < car_total; i++)
        {
            getline(car_file, car_name[i]);
            getline(car_file, car_model[i]);
            getline(car_file, car_color[i]);
            getline(car_file, car_make_year[i]);
            getline(car_file, car_fuel_type[i]);
            car_file >> car_mileage[i];
            car_file >> car_seating_capacity[i];
            car_file >> car_price[i];
            car_file.ignore();
        }
        car_file.close();
    }

    virtual void display_Cars(const string &filename)        //Polymorphism 
    {
        ifstream car_file(filename);
        if (!car_file)
        {
            cout << "Unable to open file." << endl;
            return;
        }
        car_file >> car_total;
        car_file.ignore();
        for (int i = 0; i < car_total; i++)
        {
            getline(car_file, car_name[i]);
            getline(car_file, car_model[i]);
            getline(car_file, car_color[i]);
            getline(car_file, car_make_year[i]);
            getline(car_file, car_fuel_type[i]);
            car_file >> car_mileage[i];
            car_file >> car_seating_capacity[i];
            car_file >> car_price[i];
            car_file.ignore();
        }
        car_file.close();
        system("cls");
        for (int i = 0; i < car_total; i++)
        {
            cout << "Name: " << car_name[i] << endl;
            cout << "Model: " << car_model[i] << endl;
            cout << "Color: " << car_color[i] << endl;
            cout << "Make year: " << car_make_year[i] << endl;
            cout << "Fuel Type: " << car_fuel_type[i] << endl;
            cout << "Mileage: " << car_mileage[i] << endl;
            cout << "Seating Capacity: " << car_seating_capacity[i] << endl;
            cout << "Price Per Hour: " << car_price[i] << endl;
            cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    void search_car()
    {
        int count = 0;
        string n;
        cout << "Enter name of the car to be searched..." << endl;
        cin >> n;
        system("cls");
        bool found = false;
        for (int i = 0; i < car_total; i++)
        {
            if (n == car_name[i])
            {
                found = true;
                cout << "                     Car is Available" << endl;
                cout << "------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Name: " << car_name[i] << endl;
                cout << "Model: " << car_model[i] << endl;
                cout << "Color: " << car_color[i] << endl;
                cout << "Make year: " << car_make_year[i] << endl;
                cout << "Fuel Type: " << car_fuel_type[i] << endl;
                cout << "Mileage: " << car_mileage[i] << endl;
                cout << "Seating Capacity: " << car_seating_capacity[i] << endl;
                cout << "Price Per Hour: " << car_price[i] << endl;
                cout << "------------------------------------------------------------------------------------------------------------------" << endl;
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "                            Not Available ......!" << endl
                 << endl
                 << endl
                 << endl;
        }
    }
    void addCarToArray(const string &name, const string &model, const string &color, const string &make_year, const string &fuel_type, int mileage, int seating_capacity, int price)
    {
        if (car_total < max_cars)
        {
            car_name[car_total] = name;
            car_model[car_total] = model;
            car_color[car_total] = color;
            car_make_year[car_total] = make_year;
            car_fuel_type[car_total] = fuel_type;
            car_mileage[car_total] = mileage;
            car_seating_capacity[car_total] = seating_capacity;
            car_price[car_total] = price;
            car_total++;
        }
        else
        {
            cout << "Max cars limit reached." << endl;
        }
    }
    int options()
    {
        int c;
        while (true)
        {
            cout << endl
                 << endl;
            cout << "                             **************************************************\n";
            cout << "                             *                 Select Action                  *\n";
            cout << "                             **************************************************\n";
            cout << "                             * 1. Login as Owner                              *\n";
            cout << "                             * 2. Login as Customer                           *\n";
            cout << "                             * 3. Exit                                        *\n";
            cout << "                             **************************************************\n";
            cin >> c;
            system("cls");
            if (!cin)
            {
                cin.clear();                                         // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input, please enter a number." << endl;
            }
            else
            {
                break;
            }
        }
        return c;
    }
    ~Cars() {}               // destructor
    friend class Car_Dealer; // Friend class
};
int Cars ::car_total = 0;

class Car_Dealer
{
protected:
    string name;
    string password;

public:
    Car_Dealer() {}
    Car_Dealer(string n, string p)
    {
        name = n;
        password = p;
    }
    void welcome(){
        cout << "\n\n\n";
    cout << "\t\t\t\t\tWelcome to Car Rental System" << endl;
    cout << "\t\t\t\t\t\t Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
    }
    int login(string user, string passwor)
    {
        int y = 1, n = 2;

        if (user == name && passwor == password)
        {
            return y;
        }
        else
        {
            return n;
        }
    }
    int options2()
    {
        int c;
        while (true)
        {
            cout << "                              **************************************************\n";
            cout << "                              *                  Select Action                 *\n";
            cout << "                              **************************************************\n";
            cout << "                              * 1. Add Car                                     *\n";
            cout << "                              * 2. Remove Car                                  *\n";
            cout << "                              * 3. Update Car                                  *\n";
            cout << "                              * 4. Search Car                                  *\n";
            cout << "                              * 5. Display All Cars                            *\n";
            cout << "                              * 6. Rental History                              *\n";
            cout << "                              * 7. Back to login Page                          *\n";
            cout << "                              * 8. Exit                                        *\n";
            cout << "                              **************************************************\n";
            cin >> c;
            if (!cin)
            {
                cin.clear();                                         // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input, please enter a number." << endl;
            }
            else if (c < 1 || c > 7)
            {
                cout << "Invalid option, please choose a number between 1 and 7." << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                return c;
            }
            system("cls");
        }
    }

    void add_car(Cars &carManager)
    {
        carManager.display_Cars("car.txt");
        system("cls");
        string car_name, car_model, car_color, car_make_year, car_fuel_type;
        int car_mileage, car_seating_capacity, car_price;

        cout << "Enter car name: ";
        getline(cin, car_name);
        cout << "Enter car model: ";
        getline(cin, car_model);
        cout << "Enter car color: ";
        getline(cin, car_color);
        cout << "Enter car make year: ";
        cin >> car_make_year;
        cout << "Enter car fuel type: ";
        cin.ignore();
        getline(cin, car_fuel_type);
        cout << "Enter car mileage: ";
        cin >> car_mileage;
        cout << "Enter car seating capacity: ";
        cin >> car_seating_capacity;
        cout << "Enter car price: ";
        cin >> car_price;

        carManager.addCarToArray(car_name, car_model, car_color, car_make_year, car_fuel_type, car_mileage, car_seating_capacity, car_price);
        carManager.save_Cars("car.txt");

        cout << "Car added successfully." << endl;
    }
    int againMenu()
    {
        int c;
        cout << "Back to previous Menu ?" << endl;
        cout << "                       1.Yes" << endl;
        cout << "                       2.No" << endl;
        cin >> c;
        if (c == 2)
        {
            cout << "Going to Login Page..." << endl;
        }
        return c;
    }
    void remove_car(Cars &carManager)
    {
        string name;
        cout << "Enter car name to remove: ";
        cin >> name;
        for (int i = 0; i < carManager.car_total; i++)
        {
            if (carManager.car_name[i] == name)
            {
                for (int j = i; j < carManager.car_total - 1; j++)
                {
                    carManager.car_name[j] = carManager.car_name[j + 1];
                    carManager.car_model[j] = carManager.car_model[j + 1];
                    carManager.car_color[j] = carManager.car_color[j + 1];
                    carManager.car_make_year[j] = carManager.car_make_year[j + 1];
                    carManager.car_fuel_type[j] = carManager.car_fuel_type[j + 1];
                    carManager.car_mileage[j] = carManager.car_mileage[j + 1];
                    carManager.car_seating_capacity[j] = carManager.car_seating_capacity[j + 1];
                    carManager.car_price[j] = carManager.car_price[j + 1];
                }
                carManager.car_total--;
                carManager.save_Cars("car.txt");
                cout << "Car removed successfully." << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }
    void display_rental_history(const string &filename) {
        ifstream receipt_file(filename);
        if (!receipt_file) {
            cout << "Unable to open file." << endl;
            return;
        }
        
        string line;
        system("cls"); // Clear the console screen
        cout << "Rental History:" << endl;
        cout << "------------------------------------------------------------" << endl;
        while (getline(receipt_file, line)) {
            cout << line << endl;
        }
        cout << "------------------------------------------------------------" << endl;
        
        receipt_file.close();
    }
    void update_car(Cars &carManager)
    {
        string name;
        cout << "Enter car name to update: ";
        cin >> name;
        for (int i = 0; i < carManager.car_total; i++)
        {
            if (carManager.car_name[i] == name)
            {
                string car_name, car_model, car_color, car_make_year, car_fuel_type;
                int car_mileage, car_seating_capacity, car_price;
                cout << "Enter new car model: ";
                cin >> car_model;
                cout << "Enter new car color: ";
                cin >> car_color;
                cout << "Enter new car make year: ";
                cin >> car_make_year;
                cout << "Enter new car fuel type: ";
                cin >> car_fuel_type;
                cout << "Enter new car mileage: ";
                cin >> car_mileage;
                cout << "Enter new car seating capacity: ";
                cin >> car_seating_capacity;
                cout << "Enter new car price: ";
                cin >> car_price;

                carManager.car_model[i] = car_model;
                carManager.car_color[i] = car_color;
                carManager.car_make_year[i] = car_make_year;
                carManager.car_fuel_type[i] = car_fuel_type;
                carManager.car_mileage[i] = car_mileage;
                carManager.car_seating_capacity[i] = car_seating_capacity;
                carManager.car_price[i] = car_price;

                carManager.save_Cars("car.txt");
                cout << "Car updated successfully." << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }
    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    // Data is binded in the class which is Encapsulation
};

class Customer
{
protected:
    Cars *cars;
    static const int max_users = 1000;
    string user_name[max_users];
    string user_password[max_users];
    string user_contact[max_users];
    string user_city[max_users];
    static int user_count;
    string name, city, password, contact;

public:
    string user_pin[max_users];

    Customer() // Constructor
    {
        load_user_data("user.txt");
    }
    void display_Cars()
    {
        cars->display_Cars("car.txt");
    }
    void save_user_data(const string &filename)
    {
        ofstream file(filename, ios::out | ios::trunc);
        if (!file)
        {
            cout << "Unable to open file for writing." << endl;
            return;
        }
        file << user_count << endl;
        for (int i = 0; i < user_count; i++)
        {
            file << user_name[i] << endl;
            file << user_password[i] << endl;
            file << user_contact[i] << endl;
            file << user_city[i] << endl;
        }
        file.close();
    }

    void load_user_data(const string &filename)
    {
        ifstream file(filename, ios::in); // Open file for reading
        if (!file)
        {
            cout << "Unable to open file." << endl;
            return;
        }
        file >> user_count;
        file.ignore(); // Ignore the newline after user_count
        for (int i = 0; i < user_count; i++)
        {
            getline(file, user_name[i]);
            getline(file, user_password[i]);
            getline(file, user_contact[i]);
            getline(file, user_city[i]);
        }
        file.close();
    }
    int rrDisplay()
    {
        int rrr;
        cout << "                              **************************************************\n";
        cout << "                              *                  Select Action                 *\n";
        cout << "                              **************************************************\n";
        cout << "                              * 1. Rent Car                                    *\n";
        cout << "                              * 2. Return Car                                  *\n";
        cout << "                              * 3. Back to Previous Menu                       *\n";
        cout << "                              * 4. Exit                                        *\n";
        cout << "                              **************************************************\n";
        cin >> rrr;
        return rrr;
    }
    void signUp()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your contact: ";
        cin >> contact;
        cout << "Enter your city: ";
        cin >> city;

        user_name[user_count] = name;
        user_password[user_count] = password;
        user_contact[user_count] = contact;
        user_city[user_count] = city;
        user_count++; // Increment user_count after adding a new user

        save_user_data("user.txt");
        cout << "Sign Up Successful." << endl;
    }

    int signIn()
    {
        string user_nam, user_passwor;
        cout << "Enter your name: ";
        cin >> user_nam;
        cout << "Enter password: ";
        cin >> user_passwor;

        for (int i = 0; i < user_count; i++)
        {
            if (user_nam == user_name[i] && user_passwor == user_password[i])
            {
                return 0; // Successful sign-in
            }
        }
        return 1; // Sign-in failed
    }

    void changePassword()
    {
        string current_password, new_password, name;
        int user_index = -1;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter current password: ";
        cin >> current_password;

        for (int i = 0; i < user_count; ++i)
        {
            if (user_name[i] == name && user_password[i] == current_password)
            {
                user_index = i;
                break;
            }
        }

        if (user_index == -1)
        {
            cout << "Incorrect current password. Password change failed." << endl;
            return;
        }

        cout << "Enter new password: ";
        cin >> new_password;

        user_password[user_index] = new_password;
        save_user_data("user.txt");

        cout << "Password changed successfully." << endl;
    }

    int cDisplay()
    {
        int cho;
        cout << "                              **************************************************\n";
        cout << "                              *                  Select Action                 *\n";
        cout << "                              **************************************************\n";
        cout << "                              * 1. Sign In                                     *\n";
        cout << "                              * 2. Create Account                              *\n";
        cout << "                              * 3. Exit                                        *\n";
        cout << "                              **************************************************\n";
        cin >> cho;
        system("cls"); 
        return cho;
    }
     virtual void display() const // Virtual function for polymorphism
    {
        cout << "Customer: " << name << ", City: " << city << ", Contact: " << contact << endl;
    }
    int cuDisplay()
    {
        int cuc;
        cout << "                              **************************************************\n";
        cout << "                              *                  Select Action                 *\n";
        cout << "                              **************************************************\n";
        cout << "                              * 1. View Cars                                   *\n";
        cout << "                              * 2. Search Car                                  *\n";
        cout << "                              * 3. Car Booking                                 *\n";
        cout << "                              * 4. Change Password                             *\n";
        cout << "                              * 5. Back to Previous Menu                       *\n";
        cout << "                              * 6. Exit                                        *\n";
        cout << "                              **************************************************\n";
        cin >> cuc;
        system("cls"); 
        return cuc;
    }

    int getUserTotal()
    {
        return user_count;
    }
     virtual void rentCar() const // Virtual function for polymorphism
    {
        cout << "This function is for renting a car." << endl;
    }

    virtual void returnCar() const // Virtual function for polymorphism
    {
        cout << "This function is for returning a car." << endl;
    }
    void defaultCustomers()
    {
        user_name[0] = "Ahmad";
        user_password[0] = "123";
        user_contact[0] = "0304-6808885";
        user_city[0] = "Lahore";
        user_count++;
        user_name[1] = "Abubakar";
        user_password[1] = "123";
        user_contact[1] = "0321-1306560";
        user_city[1] = "Lahore";
        user_count++;
        user_name[2] = "Talha";
        user_password[2] = "123";
        user_contact[2] = "0318-4950591";
        user_city[2] = "Lahore";
        user_count++;
        user_name[3] = "Zain";
        user_password[3] = "123";
        user_contact[3] = "0323-5100739";
        user_city[3] = "Lahore";
        user_count++;
        user_name[4] = "Anus";
        user_password[4] = "123";
        user_contact[4] = "0344-4686810";
        user_city[4] = "Lahore";
        user_count++;
        user_name[5] = "Nasar";
        user_password[5] = "123";
        user_contact[5] = "0324-5142040";
        user_city[5] = "Lahore";
        user_count++;
        user_name[6] = "Rashid";
        user_password[6] = "123";
        user_contact[6] = "0321-1086586";
        user_city[6] = "Lahore";
        user_count++;
    }
    int againMenu()
    {
        int c;
        cout << "Back to previous Menu ?" << endl;
        cout << "                       1.Yes" << endl;
        cout << "                       2.No" << endl;
        cin >> c;
        if (c == 2)
        {
            cout << "Going to Login Page..." << endl;
        }
        return c;
    }
    // signIn(), signUp(), cuDisplay(), etc., are abstracted methods within the Customer class.
};
int Customer::user_count = 0;
class Rent : public Customer // Inheritence
{
protected:
    string cName;
    int totalRent;
    int timeInHours;
    static const int MAX_RECEIPTS = 100;
    string dateTime[MAX_RECEIPTS];
    string carRented[MAX_RECEIPTS];
    int rentalDuration[MAX_RECEIPTS];
    double totalPrice[MAX_RECEIPTS];
    string savePin;
    static int numReceipts;

public:
    void setName(string CN)
    {
        cName = CN;
    }
    void setTime(int time)
    {
        timeInHours = time;
    }
    void setTotalRent(int total)
    {
        totalRent = total;
    }
    void selectCar()
    {
        string carName;
        int HoursTime;
        cout << "Enter Name of the Car u want to rent: ";
        cin.ignore();
        getline(cin, carName);
        cout << "Enter Hours for which u want to rent: ";
        cin >> HoursTime;
        setName(carName);
        setTime(HoursTime);
    }
    void display(Cars &carManager, Customer &cust) 
    {
        bool found = false;
        for (int i = 0; i < carManager.car_total; i++)
        {
            if (cName == carManager.car_name[i])
            {
                found = true;
                system("cls");
                cout << "Car Details:" << endl;
                cout << "Name: " << carManager.car_name[i] << endl;
                cout << "Model: " << carManager.car_model[i] << endl;
                cout << "Color: " << carManager.car_color[i] << endl;
                cout << "Make year: " << carManager.car_make_year[i] << endl;
                cout << "Fuel Type: " << carManager.car_fuel_type[i] << endl;
                cout << "Mileage: " << carManager.car_mileage[i] << endl;
                cout << "Seating Capacity: " << carManager.car_seating_capacity[i] << endl;
                cout << "Price Per Hour: " << carManager.car_price[i] << endl;
                cout << "------------------------------------------------------------------------------------------------------------------" << endl;

                totalRent = timeInHours * carManager.car_price[i];
                setTotalRent(totalRent);
                cout << "Total Rent for " << timeInHours << " hours: Rs." << totalRent << endl;
                int md;
                cout << endl
                     << endl
                     << "Avail Membership Discount : " << endl;
                cout << "1.Yes" << endl;
                cout << "2.No" << endl;
                cin >> md;
                if (md == 1)
                {
                    string pin;
                    int memds = 0;
                    cout << "Enter your user Pin : ";
                    cin >> pin;
                    savePin = pin;
                        if (pin == "000")
                        {
                            totalRent = totalRent * 0.9;
                            cout << "Discounted Rent for " << timeInHours << " hours: Rs." << totalRent << endl;
                            memds++;
                        }
                    
                    if (memds == 0)
                    {
                        cout << "You cannot avail Membership Discount...!" << endl;
                    }
                }
                else if (md == 2)
                {
                    break;
                }
                break;
            }
        }
        if (!found)
        {
            cout << "Car not found." << endl;
        }
    }
    int confirmBooking()
    {
        int y = 1;
        int n = 2;
        int cb;
        cout << "Do you want to confirm the booking? " << endl;
        cout << "1.Yes" << endl;
        cout << "2.No" << endl;
        cin >> cb;
        if (cb == 1)
        {
            return y;
        }
        else if (cb == 2)
        {
            return n;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }
    int getNumReceipts() const
    {
        return numReceipts;
    }
    void display() const override
    {
        cout << "Rented Car: " << cName << ", Total Rent: Rs." << totalRent << endl;
    }
    void generateReceipt()
    {
        // Get current time
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char *dt = ctime(&now);

        // Store receipt in array
        if (numReceipts < MAX_RECEIPTS)
        {
            dateTime[numReceipts] = dt;
            carRented[numReceipts] = cName;
            rentalDuration[numReceipts] = timeInHours;
            totalPrice[numReceipts] = totalRent;
            numReceipts++;
        }
        else
        {
            cout << "Maximum number of receipts reached. Cannot store more receipts." << endl;
            return;
        }

        ofstream receipt("receipt.txt", ios::app); // Open file in append mode
        if (!receipt)
        {
            cout << "Unable to open file." << endl;
            return;
        }

        receipt << fixed << setprecision(2);
        receipt << "-----------------------------------------" << endl;
        receipt << "               RENTAL RECEIPT            " << endl;
        receipt << "-----------------------------------------" << endl;
        receipt << "User Pin: " << savePin << endl;
        receipt << "Date & Time: " << dt;
        receipt << "Car Rented: " << cName << endl;
        receipt << "Rental Duration: " << timeInHours << " hours" << endl;
        receipt << "Total Price: Rs." << totalRent << endl;
        receipt << "-----------------------------------------" << endl;
        receipt << "         Thank you for renting with us!        " << endl;
        receipt << "For any queries, contact us at OurCar@gmail.com" << endl;
        receipt << "-----------------------------------------" << endl;

        receipt.close();

        cout << "\nReceipt generated and stored successfully." << endl;
    }

    void displayReceipt(int index)
    {
        system("cls");
        if (index < 0 || index >= numReceipts)
        {
            cout << "Invalid receipt index." << endl;
            return;
        }

        cout << "                              -----------------------------------------" << endl;
        cout << "                                             RENTAL RECEIPT            " << endl;
        cout << "                              -----------------------------------------" << endl;
        cout << "                              User Pin: " << savePin << endl;
        cout << "                              Date & Time: " << dateTime[index];
        cout << "                              Car Rented: " << carRented[index] << endl;
        cout << "                              Rental Duration: " << rentalDuration[index] << " hours" << endl;
        cout << "                              Total Price: Rs." << totalPrice[index] << endl;
        cout << "                              -----------------------------------------" << endl;
        cout << "                                      Thank you for renting with us!        " << endl;
        cout << "                              For any queries, contact us at OurCarRetal@gmail.com" << endl;
        cout << "                              -----------------------------------------" << endl;
    }
    void rentCar() const override
    {
        cout << "Renting a car in Rent class." << endl;
    }
};
int Rent ::numReceipts = 0;
class Return : public Customer {
private:
    string car_model; // Number of days for car return
    string car_name; // Price of the car
    float body_damage_cost;
    float engine_damage_cost;
    float interior_damage_cost;
    float tire_damage_cost;

public:
    Return(string d, string cp) : car_name(d), car_model(cp), body_damage_cost(0), engine_damage_cost(0), interior_damage_cost(0), tire_damage_cost(0) {}

    // Method to set specific part damage costs
    void setDamageCosts(float body, float engine, float interior, float tire) {
        body_damage_cost = body;
        engine_damage_cost = engine;
        interior_damage_cost = interior;
        tire_damage_cost = tire;
    }

    // Method to calculate damage cost based on specific parts
    float calculateDamageByParts() {
        return body_damage_cost + engine_damage_cost + interior_damage_cost + tire_damage_cost;
    }

    // Method to print total damage cost
    void printTotalDamageCost(float damage_margin = 0) {
        float total_damage = 0;
       
            total_damage = calculateDamageByParts();
        cout << "Total Damage Cost: " << total_damage << endl;
    }

    // Method to interactively ask the owner about the damage
    void askOwnerForDamage() {
        float body_damage, engine_damage, interior_damage, tire_damage;
        char response;

        cout << "Is there any body damage? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            cout << "Enter body damage cost: ";
            cin >> body_damage;
            body_damage_cost = body_damage;
        }

        cout << "Is there any engine damage? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            cout << "Enter engine damage cost: ";
            cin >> engine_damage;
            engine_damage_cost = engine_damage;
        }

        cout << "Is there any interior damage? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            cout << "Enter interior damage cost: ";
            cin >> interior_damage;
            interior_damage_cost = interior_damage;
        }

        cout << "Is there any tire damage? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            cout << "Enter tire damage cost: ";
            cin >> tire_damage;
            tire_damage_cost = tire_damage;
        }

        printTotalDamageCost();
    }

    // Method to display return information
    void displayReturnInfo() {
        cout << "Car: " << car_name <<"with model " << car_model << "is returned successfully" << endl;
        cout<<"You will have to pay Extra ";
        printTotalDamageCost();
    }
};
                         
int main()
{
    Car_Dealer d1;
    d1.setColor(10);
    d1.welcome();
    d1.setColor(15);
    cout << endl;
    Cars carManager;
    if (carManager.getCarTotal() == 0)
    {
        carManager.initializeDefaultCars();
    }
    carManager.save_Cars("car.txt");
    Customer customerManager;
    if (customerManager.getUserTotal() == 0)
    {
        customerManager.defaultCustomers();
        customerManager.save_user_data("user.txt");
    }
    Car_Dealer dealer("Ahmad", "123");
    int choice;
    do
    {
        int bok;
        choice = carManager.options();
        switch (choice)
        {
        case 1:
        {
            string user, password;
            cout << "Enter username: ";
            cin >> user;
            cout << "Enter password: ";
            cin >> password;
            if (dealer.login(user, password) == 1)
            {
                int aM;
                int dealerChoice;
                do
                {
                    dealerChoice = dealer.options2();
                    switch (dealerChoice)
                    {
                    case 1:
                        dealer.add_car(carManager);
                        break; // Association
                    case 2:
                        dealer.remove_car(carManager);
                        break; // Association
                    case 3:
                        dealer.update_car(carManager);
                        break; // Association
                    case 4:
                        carManager.search_car();
                        break;
                    case 5:
                        carManager.display_Cars("car.txt");
                        break;
                    case 6:
                        dealer.display_rental_history("receipt.txt");
                        break;
                    case 7:
                        cout << "Exiting Owner Menu...\n";
                        break;
                    case 8:
                        cout << "Exiting!!!" << endl;
                        return 0;
                    }
                    if (dealerChoice != 7)
                        aM = dealer.againMenu();
                } while (aM == 1 && dealerChoice != 7);
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
            break;
        }
        case 2:
        {
            int customerChoice = customerManager.cDisplay();
            switch (customerChoice)
            {
            case 1:
            {
                if (customerManager.signIn() == 0)
                {
                    int cuD;
                    int customerAction;
                    do
                    {
                        customerAction = customerManager.cuDisplay();
                        switch (customerAction)
                        {
                        case 1:
                            carManager.display_Cars("car.txt");
                            break;
                        case 2:
                            carManager.search_car();
                            break;
                        case 3:
                        {
                            int cB = customerManager.rrDisplay();
                            if (cB == 1)
                            {
                                Rent rentManager;
                                rentManager.selectCar();
                                rentManager.display(carManager, customerManager);
                                int numReceipts = 0;
                                bok = rentManager.confirmBooking();
                                if (bok == 1)
                                {
                                    rentManager.generateReceipt();
                                    rentManager.displayReceipt(numReceipts);
                                    numReceipts++;
                                }
                                else if (bok == 2)
                                {
                                    cout << "Booking Cancelled" << endl;
                                }
                                break;
                            }
                            else if (cB == 2)
                            {
                                system("cls");
                                string carName, carModel;
                                cout << "Enter the name of car: ";
                                cin >> carName;
                                cout << "Enter Car Model: ";
                                cin >> carModel;
                                Return returnCarManager(carName, carModel);  
                                cout<<"Confirming Car condition by Owner... "<<endl<<endl;  
                                returnCarManager.askOwnerForDamage();
                                returnCarManager.displayReturnInfo();
                                break;
                            }
                        }
                        case 4:
                            customerManager.changePassword();
                            break;
                        case 5:
                            cout << "Exiting Customer Menu..." << endl;
                            break;
                        }
                        cuD = customerManager.againMenu();
                    } while (customerAction != 5 && cuD == 1);
                }
                else
                {
                    cout << "Invalid username or password." << endl;
                }
                break;
            }
            case 2:
                customerManager.signUp();
                break;
            case 3:
                cout << "Exiting Customer Menu..." << endl;
                break;
            }
            break;
        }
        case 3:
            cout << "Exiting program..." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}