#include "FileProcessor.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string FileProcessor::readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "不能打开这个文件!" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
