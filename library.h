#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

using namespace std;

class Library
{
private:
    unsigned int libraryId;
    std::string libraryName;
public:
    Library();
    Library(unsigned int id,std::string name);
    void updateLibrary(unsigned int id,std::string name);

    //=======setters======
    Library& setLibraryId(unsigned int id);
    Library& setLibraryName(std::string name);

    //=======getters======
    unsigned int getLibraryId() const;
    std::string getLibraryName() const;
};

#endif // LIBRARY_H
