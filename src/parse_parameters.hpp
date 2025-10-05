#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <variant>
#include <stdexcept>

class Config{
    private:
        bool literalMatch = false;
        bool ignoreCase = false;
        bool recursive = false;
        bool onlyCount = false;
        bool onlyWritePaths = false;
        bool logErrors = true;
        bool showLineNumbers = false;
        int linesAfter = 0;
        int linesBefore = 0;
        int concurentThreads = 1;
    public:
        Config() = default;
        ~Config() = default;
        bool getLiteralMatch() const;
        bool getIgnoreCase() const;
        bool getRecursive() const;
        bool getOnlyCount() const;
        bool getOnlyWritePaths() const;
        bool getLogErrors() const;
        bool getShowLineNumbers() const;
        int getLinesAfter() const;
        int getLinesBefore() const;
        int getConcurentThreads() const;
        void setLiteralMatch(bool);
        void setIgnoreCase(bool);
        void setRecursive(bool);
        void setOnlyCount(bool);
        void setOnlyWritePaths(bool);
        void setLogErrors(bool);
        void setShowLineNumbers(bool);
        void setLinesAfter(int);
        void setLinesBefore(int);
        void setConcurentThreads(int);
};

Config parse_parameters(int argc, char* argv[], std::string &pattern, std::vector<std::string> &paths);