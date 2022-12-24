#include "library.h"

using namespace std;

Library::Library()
{
    this->libraryId = 0;
    this->libraryName = "N/A";
}
Library::Library(unsigned int id,string name)
{
    this->libraryId = id;
    this->libraryName = name;
}
void Library::updateLibrary(unsigned int id, string name)
{
    this->libraryId = id;
    this->libraryName = name;
}

//========setters========
Library& Library::setLibraryId(unsigned int id)
{
    this->libraryId = id;
    return *this;
}
Library& Library::setLibraryName(string name)
{
    this->libraryName = name;
    return *this;
}

//=======getters=======
unsigned int Library::getLibraryId() const
{
    return this->libraryId;
}
string Library::getLibraryName() const
{
    return this->libraryName;
}

