#include <string>
#include <iostream>

class Book;

class User
{
public:
    // default constructor
    User();

    // constructor with parameters
    User(int userId, std::string name, std::string address, std::string phone, std::string email);

    // destructor
    ~User();

    // Публичные методы

    // display user information
    void displayUserInfo() const;

    // borrow book
    void borrowBook(Book* book);

    // add fine
    void addFine(double amount);

    // pay fine
    void payFine(double amount);

    // getters
    int getUserId() const;
    double getFineAmount() const;

private:
    // private fields
    int m_userId;
    std::string m_name;
    std::string m_address;
    std::string m_phone;
    std::string m_email;

    double m_fineAmount;
};