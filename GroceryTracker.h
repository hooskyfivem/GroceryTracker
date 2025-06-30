#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

class GroceryTracker {
    private:
        std::map<std::string, int> itemFrequency;

        void loadItemsFromFile(const std::string& filename);
        void saveFrequenciesToFile(const std::string& filename);

    public:
        GroceryTracker(const std::string& inputFilename, const std::string& backupFilename);

        int getItemFrequency(const std::string& inputFilename, const std::string& backupFilename);

        int getItemFrequency(const std::string& item) const;
        void printAllFrequencies() const;
        void printHistogram() const;
};

#endif