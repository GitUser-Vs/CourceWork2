#include "User.hpp"
#include "Book.hpp" // ¬ключаем Book, так как User может работать с Book

// Default Constructor
User::User()
    : m_userId(0), m_name(""), m_address(""), m_phone(""), m_email(""),
    m_fineAmount(0.0)
{
    std::cout << "User: Default constructor called." << std::endl;
}

// Parameterized constructor
User::User(int userId, std::string name, std::string address, std::string phone, std::string email)
    : m_userId(userId), m_name(std::move(name)), m_address(std::move(address)),
    m_phone(std::move(phone)), m_email(std::move(email)), m_fineAmount(0.0)
{
    std::cout << "User: Parameterized constructor called for \"" << m_name << "\"." << std::endl;
}

// Destructor
User::~User()
{
    std::cout << "User: Destructor called for \"" << m_name << "\"." << std::endl;
}

// Public methods

void User::displayUserInfo() const
{
    std::cout << "--- User Info ---" << std::endl;
    std::cout << "ID: " << m_userId << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Address: " << m_address << std::endl;
    std::cout << "Phone: " << m_phone << std::endl;
    std::cout << "Email: " << m_email << std::endl;
    std::cout << "Fine Amount: " << m_fineAmount << std::endl;
    std::cout << "-----------------" << std::endl;
}

void User::borrowBook(Book* book)
{
    if (book) {
        std::cout << "User \"" << m_name << "\" is borrowing book \"" << book->getTitle() << "\"." << std::endl;
    }
}

void User::addFine(double amount)
{
    m_fineAmount += amount;
    std::cout << "User \"" << m_name << "\" incurred a fine of " << amount << ". Total fine: " << m_fineAmount << std::endl;
}

void User::payFine(double amount)
{
    if (amount > 0) {
        if (m_fineAmount >= amount) {
            m_fineAmount -= amount;
            std::cout << "User \"" << m_name << "\" paid " << amount << ". Remaining fine: " << m_fineAmount << std::endl;
        }
        else {
            std::cout << "User \"" << m_name << "\" paid " << amount << ". Fine fully paid. Remaining: " << m_fineAmount - amount << std::endl;
            m_fineAmount = 0.0;
        }
    }
    else {
        std::cerr << "Error: Invalid amount for paying fine." << std::endl;
    }
}

// Getters
int User::getUserId() const { return m_userId; }
std::string User::getName() const {return m_name;}
double User::getFineAmount() const { return m_fineAmount; }