#include "Book.hpp"

// Default Constructor
Book::Book()
    : m_bookId(0), m_title(""), m_author(""), m_isbn(""), m_publisher(""),
    m_publicationYear(0), m_genre(Genre::eUnknown), m_quantity(0), m_available(0)
{
    std::cout << "Book: Default constructor called." << std::endl;
}

// Parameterized constructor
Book::Book(int bookId, std::string title, std::string author, std::string isbn, std::string publisher,
    int publicationYear, Genre genre, int quantity, int available)
    : m_bookId(bookId), m_title(std::move(title)), m_author(std::move(author)), m_isbn(std::move(isbn)),
    m_publisher(std::move(publisher)), m_publicationYear(publicationYear), m_genre(genre),
    m_quantity(quantity), m_available(available)
{
    std::cout << "Book: Parameterized constructor called for \"" << m_title << "\"." << std::endl;
}

// Destructor
Book::~Book()
{
    std::cout << "Book: Destructor called for \"" << m_title << "\"." << std::endl;
}

// Public methods

void Book::displayBookInfo() const
{
    std::cout << "--- Book Info ---" << std::endl;
    std::cout << "ID: " << m_bookId << std::endl;
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Author: " << m_author << std::endl;
    std::cout << "ISBN: " << m_isbn << std::endl;
    std::cout << "Publisher: " << m_publisher << std::endl;
    std::cout << "Year: " << m_publicationYear << std::endl;
    std::cout << "Total Quantity: " << m_quantity << std::endl;
    std::cout << "Available: " << m_available << std::endl;
    std::cout << "-----------------" << std::endl;
}

void Book::decreaseAvailable()
{
    if (m_available > 0)
    {
        m_available--;
    }
    else
    {
        std::cerr << "Error: Cannot decrease available for \"" << m_title << "\". No copies available." << std::endl;
    }
}

void Book::increaseAvailable()
{
    if (m_available < m_quantity)
    {
        m_available++;
    }
    else
    {
        std::cerr << "Warning: Available count for \"" << m_title << "\" is already at maximum." << std::endl;
    }
}

// getters
std::string Book::getTitle() const { return m_title; }
std::string Book::getAuthor() const { return m_author; }
int Book::getBookId() const { return m_bookId; }
int Book::getQuantity() const { return m_quantity; }
int Book::getAvailable() const { return m_available; }