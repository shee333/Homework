#include "FileProcessor.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string FileProcessor::readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "���ܴ�����ļ�!" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
