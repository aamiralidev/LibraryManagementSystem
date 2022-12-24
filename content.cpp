#include "content.h"

using namespace std;

Content::Content()
{
    this->title = "N/A";
    this->author = "N/A";
    this->publisher = "N/A";
    this->status = "N/A";
    this->itemId = 0;
    this->productionYear = 0;
    this->copies = 0;
}
Content::Content(unsigned int libraryId,unsigned int itemId, string title, string author, string publisher,unsigned int productionYear,unsigned int copies, bool status)
{
    this->libraryId = libraryId;
    this->itemId = itemId;
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->productionYear = productionYear;
    this->copies = copies;
    this->status = status;
}
void Content::updateContent(unsigned int libraryId,unsigned int itemId, string title, string author, string publisher,unsigned int productionYear,unsigned int copies, bool status)
{
    this->libraryId = libraryId;
    this->itemId = itemId;
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->productionYear = productionYear;
    this->copies = copies;
    this->status = status;
}

//======setters=======
Content& Content::setTitle(string title)
{
    this->title = title;
    return *this;
}
Content& Content::setAuthor(string author)
{
    this->author = author;
    return *this;
}
Content& Content::setPublisher(string publisher)
{
    this->publisher = publisher;
    return *this;
}
Content& Content::setStatus(bool status)
{
    this->status = status;
    return *this;
}
Content& Content::setItemId(unsigned int itemId)
{
    this->itemId = itemId;
    return *this;
}
Content& Content::setLibraryId(unsigned int id)
{
    this->libraryId = id;
    return *this;
}
Content& Content::setProductionYear(unsigned int productionYear)
{
    this->productionYear = productionYear;
    return *this;
}
Content& Content::setCopies(unsigned int copies)
{
    this->copies = copies;
    return *this;
}
Content& Content::setCategory(unsigned int category)
{
    this->category = category;
    return *this;
}

//======getters=======
string Content::getTitle() const
{
    return this->title;
}
string Content::getAuthor() const
{
    return this->author;
}
bool Content::getStatus() const
{
    return this->status;
}
string Content::getPublisher()const
{
    return this->publisher;
}
 unsigned int Content::getItemId() const
{
    return this->itemId;
}
unsigned int Content::getProductionYear()const
{
    return this->productionYear;
}
unsigned int Content::getCopies()const
{
    return this->copies;
}
unsigned int Content::getLibraryId() const
{
    return this->libraryId;
}
unsigned int Content::getCategory() const
{
    return this->category;
}
