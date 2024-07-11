#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>

class FileProcessor {
public:
    std::string readFile(const std::string &filename);
};

#endif // FILE_PROCESSOR_H
