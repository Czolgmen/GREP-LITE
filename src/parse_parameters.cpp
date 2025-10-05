#include "parse_parameters.hpp"

bool Config::getLiteralMatch() const{
    return this->literalMatch;
}

bool Config::getIgnoreCase() const {
    return this->ignoreCase;
}

bool Config::getRecursive() const {
    return this->recursive;
}

bool Config::getOnlyCount() const {
    return this->onlyCount;
}

bool Config::getOnlyWritePaths() const {
    return this->onlyWritePaths;
}

bool Config::getLogErrors() const {
    return this->logErrors;
}

int Config::getLineNumber() const {
    return this->lineNumber;
}

int Config::getLinesAfter() const {
    return this->linesAfter;
}

int Config::getLinesBefore() const {
    return this->linesBefore;
}

int Config::getConcurentThreads() const {
    return this->concurentThreads;
}

void Config::setLiteralMatch(bool val) {
    this->literalMatch=val;
}

void Config::setIgnoreCase(bool val) {
    this->ignoreCase=val;
}

void Config::setRecursive(bool val) {
    this->recursive=val;
}

void Config::setOnlyCount(bool val) {
    this->onlyCount=val;
}

void Config::setOnlyWritePaths(bool val) {
    this->onlyWritePaths=val;
}

void Config::setLogErrors(bool val) {
    this->logErrors=val;
}

void Config::setLineNumber(int val){
    this->lineNumber=val;
}

void Config::setLinesBefore(int val){
    this->linesBefore=val;
}

void Config::setLinesAfter(int val){
    this->linesAfter=val;
}

void Config::setConcurentThreads(int val){
    this->setConcurentThreads(val);
}

Config parse_parameters(int argc, char *argv[], std::string &pattern, std::vector<std::string> &paths){
    Config config;
    if (argc < 2){
        throw std::invalid_argument("Not enough arguments");
    }
    std::string arg;
    for(int i = 1; i < argc; i++){
        if (argv[i] == nullptr) continue;
        arg = argv[i];
        if (arg == "-F") {
            config.setLiteralMatch(true);
        } else if (arg == "-i")
        {
            config.setIgnoreCase(true);
        } else if (arg == "-n") {
            if (i+1 >= argc) {
                throw std::invalid_argument("Line number not specified");
            }
            try {
            config.setLineNumber(std::atoi(argv[++i]));
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid number for -n");
            }
        } else if (arg == "-A") {
            if (i+1 >= argc) {
                throw std::invalid_argument("Line number not specified");
            }
            try {
                config.setLinesAfter(std::atoi(argv[++i]));
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid number for -A");
            }
        } else if (arg == "-B") {
            if (i+1 >= argc) {
                throw std::invalid_argument("Line number not specified");
            }
            try {
                config.setLinesBefore(std::atoi(argv[++i]));
            } catch (const std::exception&){
                throw std::invalid_argument("Invalid number for -B");
            }
        } else if (arg == "-C") {
            if (i+1 >= argc) {
                throw std::invalid_argument("Line number not specified");
            }
            try {
                int c = std::atoi(argv[++i]);
                config.setLinesAfter(c);
                config.setLinesBefore(c);
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid number for -C");
            }
        } else if (arg == "-c") {
            config.setOnlyCount(true);
        } else if (arg == "-l") {
            config.setOnlyWritePaths(true);
        } else if (arg == "-j") {
            if (i+1 >= argc) {
                throw std::invalid_argument("Number of jobs not specified");
            }
            try{
                int j = std::atoi(argv[++i]);
                if (j <= 0) throw std::invalid_argument("Invalid number of jobs");
                config.setConcurentThreads(j);
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid number of jobs");
            }
        } else if (arg == "-s") {
            config.setLogErrors(false);
        } else {
            if (pattern.empty()) {
                pattern = arg;
            } else {
                paths.push_back(arg);
            }
        }
    }
    return config;
}