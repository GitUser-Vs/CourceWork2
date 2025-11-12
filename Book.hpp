#include <string>
#include <iostream>

enum class Genre
{
    eUnknown = 0, //default value
    eFiction,
    eScience,
    eTextbook,
    eReference,
    ePeriodical,
    eEbook,
    eRareAndValuable
};

class Book
{
public:
    // default constructor
    Book();

    // constructor with parameters
    Book(int bookId, std::string title, std::string author, std::string isbn, std::string publisher,
        int publicationYear, Genre genre, int quantity, int available);

    // destructor
    ~Book();

    // get information about a book
    void displayBookInfo() const;

    // decreasing the number of available instances
    void decreaseAvailable();

    // increasing the number of available instances
    void increaseAvailable();

    // getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getBookId() const;
    int getQuantity() const;
    int getAvailable() const;

private:
    // private fields
    Genre m_genre;
    std::string m_title;
    std::string m_author;
    std::string m_isbn;
    std::string m_publisher;
    int m_publicationYear;
    int m_bookId;
    int m_quantity;
    int m_available;
};