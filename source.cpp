#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

struct variables {
    std::string name;
    std::string type;
    void* value;
};

std::vector<variables>variable;

bool boolOperators(std::string operation, std::string str1, std::string str2) {

    if(operation == "&&"){
    for (int i = 0; i < variable.size(); ++i) {
        for (int j = 0; j < variable.size(); ++j) {
            if (variable[i].name == str1 && variable[j].name == str2) {
                bool first = *(static_cast<bool*>(variable[i].value));
                bool second = *(static_cast<bool*>(variable[j].value));
                return first && second;
                }
            }
        }
    } 
    else if (operation == "||") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    bool first = *(static_cast<bool*>(variable[i].value));
                    bool second = *(static_cast<bool*>(variable[i].value));
                    return first || second;
                }
            }
        }
    }
    else if (operation == "<") {
        for (int i = 0 ; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                bool first = *(static_cast<bool*>(variable[i].value));
                bool second = *(static_cast<bool*>(variable[j].value));
                return first < second;
            }
        }
    }
    else if (operation == ">") {
        for (int i = 0 ; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                bool first = *(static_cast<bool*>(variable[i].value));
                bool second = *(static_cast<bool*>(variable[j].value));
                return first > second;
            }
        }
    }
    else if (operation == "==") {
        for (int i = 0 ; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                bool first = *(static_cast<bool*>(variable[i].value));
                bool second = *(static_cast<bool*>(variable[j].value));
                return first == second;
            }
        }
    }
}


bool unaryboolOperators(std::string operation, std::string str1) {
    if (operation == "!") {
        for (int i = 0; i < variable.size(); ++i) {
            if (variable[i].name == str1 && variable[i].type == "tramabanakan") {
                bool deny = !*(static_cast<bool*>(variable[i].value));
                return deny;
            }
        }
    }
}


std::string concat(std::string str1, std::string str2) {
    for (int i = 0; i < variable.size(); ++i) {
       for (int j = 0; j < variable.size(); ++j) {
           if (variable[i].name == str1 && variable[j].name == str2) {
                std::string first = *(static_cast<std::string*>(variable[i].value));
                std::string second = *(static_cast<std::string*>(variable[j].value));
                return first + second;
           }
       }
    }
}


double doubleOperators(std::string operation, std::string str1, std::string str2) {
    if (operation == "+") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                double first = *(static_cast<double*>(variable[i].value));
                double second = *(static_cast<double*>(variable[j].value));
                return first + second;
                }
            }
        }
    }
    else if (operation == "-") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                    if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first - second;
                }
            }
        }
    }
    else if (operation == "*") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                    if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first * second;
                }
            }
        }
    }
    else if (operation == "/") {
        for (int i = 0; i < variable.size(); ++i) {
                for (int j = 0; j < variable.size(); ++j) {
                    if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first / second;
                }
            }
        }
    }
}


int intOperators(std::string operation, std::string str1, std::string str2) {
    if (operation == "+") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first + second;
                }
            }
        }
    }
    else if (operation == "-") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first - second;
                }
            }
        }
    }
    else if (operation == "*") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first * second;
                }
            }
        }
    }
    else if (operation == "/") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first / second;
                }
            }
        }
    }
}

int main()
{
    std::ifstream fin;
    fin.open("text.txt");
    if (fin.is_open()) {
        std::cout<<"File successfully has been opened!"<<std::endl;
    }
    else {
        std::cout<<"ERROR: Can't open file"<<std::endl;
    }

    return 0;
}