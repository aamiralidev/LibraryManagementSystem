#ifndef CONTENT_H
#define CONTENT_H

#include <string>

class Content
{
private:
    std::string author, title, publisher;
    bool status;
    unsigned int productionYear, copies, itemId, libraryId, category;
public:
    Content();
    Content(unsigned int libraryId, unsigned int itemId, std::string title, std::string author, std::string publisher, unsigned int productionYear, unsigned int copies, bool status);
    void updateContent(unsigned int libraryId, unsigned int itemId, std::string title, std::string author, std::string publisher, unsigned int productionYear, unsigned int copies, bool status);

    // ========== Setters ==========

    Content& setTitle(std::string title);
    Content& setAuthor(std::string author);
    Content& setStatus(bool status);
    Content& setPublisher(std::string publisher);
    Content& setItemId(unsigned int itemId);
    Content& setLibraryId(unsigned int id);
    Content& setProductionYear(unsigned int productionYear);
    Content& setCopies(unsigned int copies);
    Content& setCategory(unsigned int category);
    // ========== GETTER ==========

    std::string getTitle() const;
    std::string getAuthor() const;
    bool getStatus() const;
    std::string getPublisher()const;
    unsigned int getItemId() const;
    unsigned int getLibraryId() const;
    unsigned int getProductionYear() const;
    unsigned int getCopies() const;
    unsigned int getCategory() const;
};

#endif // CONTENT_H
