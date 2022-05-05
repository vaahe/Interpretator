#include <string>
#include <fstream>
#include <vector>

bool state = false;
bool input = false;

struct variables {
    std::string name;
    std::string type;
    void* value;
};

std::vector<variables>variable;

std::vector<std::string>cond;
std::vector<std::vector<std::string> >body;
std::string lexer;

void lexing(std::ifstream&);
void translate(std::vector<std::string>&);
void declare(std::vector<std::string>&);
void operate(std::vector<std::string>&);
void conditionScope(std::vector<std::string>&);
void detCond(std::vector<std::string>&);
bool doCondition(std::vector<std::string>&);
void print(std::vector<std::string>&);
int intOperators(std::string, std::string, std::string);
double doubleOperators(std::string, std::string, std::string);
std::string stringOperators(std::string, std::string);
bool binaryboolOperators(std::string, bool, bool);
bool unaryboolOperators(std::string, std::string);
bool boolOperators(std::string, std::string, std::string);