#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

bool state;
bool input;

struct variables {
    std::string name;
    std::string type;
    void* value;
};

std::vector<variables>variable;
std::vector<std::string>cond;
std::vector<std::vector<std::string>>body;
std::string lexer;


void translate(std::vector<std::string>&);

bool boolOperators(std::string operation, std::string str1, std::string str2) {
    if (operation == "&&") {
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
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "amboghj")) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[j].value));
                    return first < second;
                }
                else if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "racional")) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[i].value));
                    return first < second;
                }
            }
        }
    }
    else if (operation == ">") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "amboghj")) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[j].value));
                    return first > second;
                }
                else if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "racional")) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first > second;
                }
            }
        }
    }
    else if (operation == "==") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "amboghj")) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[j].value));
                    return first == second;
                }
                else if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "racional")) {
                    double first = *(static_cast<double*> (variable[i].value));
                    double second = *(static_cast<double*> (variable[j].value));
                    return first == second;
                }
                else if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "togh")) {
                    std::string first = *(static_cast<std::string*> (variable[i].value));
                    std::string second = *(static_cast<std::string*> (variable[j].value));
                    return first == second;
                }
                else if ((variable[i].name == str1 && variable[j].name == str2) && (variable[i].type == "tramabanakan")) {
                    bool first = *(static_cast<bool*> (variable[i].value));
                    bool second = *(static_cast<bool*> (variable[j].value));
                    return first == second;
                }
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


bool binaryboolOperators(std::string operation, bool operand1, bool operand2) {
    if (operation == "&&") {
        if (operand1 == true && operand2 == true) {
            return true;
        }
        else return false;
    }
    else if (operation == "||") {
        if (operand1 == true || operand2 == true) {
            return true;
        }
        else return false;
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
                else if (variable[j].name == str2) {
                    double x = *(static_cast<double*>(variable[j].value));
                    double y = stod(str1);
                    return x + y;
                }
            }
            if (variable[i].name == str1) {
                double x = *(static_cast<double*>(variable[i].value));
                double y = stod(str2);
                return x + y;
            }
        }
    }
    if (operation == "-") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first - second;
                }
                else if (variable[j].name == str2) {
                    double x = *(static_cast<double*> (variable[j].value));
                    double y = std::stod(str1);
                    return x - y;
                }
            }
            if (variable[i].name == str1) {
                double x = *(static_cast<double*> (variable[i].value));
                double y = std::stod(str2);
                return x - y;
            }
        }
    }
    if (operation == "*") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first * second;
                }
                else if (variable[j].name == str2) {
                    double x = *(static_cast<double*> (variable[j].value));
                    double y = std::stod(str1);
                    return x * y;
                }
            }
            if (variable[i].name == str1) {
                double x = *(static_cast<double*>(variable[i].value));
                double y = stod(str2);
                return x * y;
            }
        }
    }
    if (operation == "/") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    double first = *(static_cast<double*>(variable[i].value));
                    double second = *(static_cast<double*>(variable[j].value));
                    return first / second;
                }
                else if (variable[j].name == str2) {
                    double x = *(static_cast<double*>(variable[i].value));
                    double y = stod(str2);
                    return x / y;
                }
            }
            if (variable[i].name == str1) {
                double x = *(static_cast<double*>(variable[i].value));
                double y = stod(str2);
                return x / y;
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
                    int second = *(static_cast<int*>(variable[j].value));
                    return first + second;
                }
            }
            if (variable[i].name == str1) {
                int x = *(static_cast<int*>(variable[i].value));
                int y = stoi(str2);
                return x + y;
            }
        }
    }
    if (operation == "-") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int x = *(static_cast<int*>(variable[i].value));
                    int y = *(static_cast<int*>(variable[j].value));
                    return x - y;
                }
                else if (variable[j].name == str2) {
                    int x = *(static_cast<int*>(variable[j].value));
                    int y = stoi(str1);
                    return x - y;
                }
            }
            if (variable[i].name == str1) {
                int x = *(static_cast<int*>(variable[i].value));
                int y = stoi(str2);
                return x - y;
            }
        }
    }
    if (operation == "*") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first * second;
                }
                else if (variable[j].name == str2) {
                    int x = *(static_cast<int*>(variable[j].value));
                    int y = stoi(str1);
                    return x * y;
                }
            }
            if (variable[i].name == str1) {
                int x = *(static_cast<int*>(variable[i].value));
                int y = stoi(str2);
                return x * y;
            }
        }
    }
    if (operation == "/") {
        for (int i = 0; i < variable.size(); ++i) {
            for (int j = 0; j < variable.size(); ++j) {
                if (variable[i].name == str1 && variable[j].name == str2) {
                    int first = *(static_cast<int*>(variable[i].value));
                    int second = *(static_cast<int*>(variable[i].value));
                    return first / second;
                }
                else if (variable[j].name == str2) {
                    int x = *(static_cast<int*>(variable[j].value));
                    int y = stoi(str1);
                    return x / y;
                }
            }
            if (variable[i].name == str1) {
                int x = *(static_cast<int*>(variable[i].value));
                int y = stoi(str2);
                return x / y;
            }
        }
    }
}


void print(std::vector<std::string>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == ";") break;
        if (i == 0) ++i;
        if (vec[i] == "<<") ++i;

        for (int j = 0; j < variable.size(); ++j) {
            if (vec[i] == variable[j].name) {
                if (variable[j].type == "amboghj") {
                    std::cout << *(static_cast<int*>(variable[j].value)) << " ";
                }
                else if (variable[j].type == "racional") {
                    std::cout << *(static_cast<double*>(variable[j].value)) << " ";
                }
                else if (variable[j].type == "togh") {
                    std::cout << *(static_cast<std::string*>(variable[j].value)) << " ";
                }
                else if (variable[j].type == "tramabanakan") {
                    std::cout << *(static_cast<bool*>(variable[j].value)) << " ";
                }
                break;
            }
            else if (vec[i] == "(") {
                ++i;
                while (vec[i] != ")") {
                    if (vec[i] == "verj") {
                        std::cout << std::endl;
                        ++i;
                    }
                    else {
                        std::cout << vec[i] << " ";
                        ++i;
                    }
                }
                continue;
            }
        }
    }
}


bool doCondition(std::vector<std::string>& vec) {
    bool flag = false;
    if (vec.size() == 1) {
        for (int i = 0; i < vec.size(); ++i) {
            if (variable[i].name == vec[0] && variable[i].type == "tramabanakan") {
                if (*(static_cast<bool*>(variable[i].value)) == true) {
                    flag = true;
                    return true;
                }
                else {
                    flag = false;
                    return false;
                }
            }
        }
    }
    else if (vec.size() == 2) {
        flag = unaryboolOperators(vec[0], vec[1]);
        if (flag == true) {
            state = true;
            return true;
        }
        else {
            state = false;
            return false;
        }
    }
    else if (vec.size() == 3) {
        flag = boolOperators(vec[1], vec[0], vec[2]);
        if (flag == true) {
            state = true;
            return true;
        }
        else {
            state = false;
            return false;
        }
    }
    else if (vec.size() == 7) {
        bool str1 = boolOperators(vec[1], vec[0], vec[2]);
        bool str2 = boolOperators(vec[5], vec[4], vec[6]);
        flag = binaryboolOperators(vec[3], str1, str2);
        if (flag == true) {
            state = true;
            return true;
        }
        else {
            state = false;
            return false;
        }
    }
}


void detCond(std::vector<std::string>& tokens) {
    int i = 1;
    while (tokens[i] != ")") {
        if (tokens[i] == "(") {
            ++i;
        }
        cond.push_back(tokens[i]);
        ++i;
    }
    doCondition(cond);
}


void conditionScope(std::vector<std::string>& tokens) {
    if (state == true) {
        int i = 0;
        if (tokens[i] == "}") input = false;
        if (input = true) {
            translate(tokens);
            return;
        }
    }
    else {
        int i = 0;
        if (tokens[i] == "}") input = false;
        return;
    }
}


void operate(std::vector<std::string>& vec) {
    if (vec[1] == "=") {
        for (int i = 0; i < variable.size(); ++i) {
            if (variable[i].name == vec[0]) {
                if (variable[i].type == "amboghj") {
                    if (vec.size() > 3 && (vec[3] == "+" || vec[3] == "-" || vec[3] == "*" || vec[3] == "/")) {
                        *(static_cast<int*>(variable[i].value)) = intOperators(vec[3], vec[2], vec[4]);
                    }
                    else {
                        bool flag = false;
                        for (int j = 0; j < variable.size(); ++j) {
                            if (variable[j].name == vec[2] && vec.size() == 3) {
                                *(static_cast<int*>(variable[i].value)) = *(static_cast<int*>(variable[j].value));
                                flag = true;
                            }
                            else return;
                        }
                        if (flag == false) {
                            *(static_cast<int*>(variable[i].value)) = stoi(vec[2]);
                        }
                    }
                }
                else if (variable[i].type == "racional") {
                    if (vec.size() > 3 && (vec[3] == "+" || vec[3] == "-" || vec[3] == "*" || vec[3] == "/")) {
                        *(static_cast<double*>(variable[i].value)) = doubleOperators(vec[3], vec[2], vec[4]);
                    }
                    else {
                        bool flag = false;
                        for (int j = 0; j < variable.size(); ++j) {
                            if (variable[j].name == vec[2] && vec.size() == 3) {
                                *(static_cast<double*>(variable[i].value)) = *(static_cast<double*>(variable[j].value));
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            *(static_cast<double*>(variable[i].value)) = stod(vec[2]);
                        }
                    }
                }
                else if (variable[i].type == "togh") {
                    if (vec.size() > 3 && vec[3] == "+") {
                        *(static_cast<std::string*>(variable[i].value)) = concat(vec[2], vec[4]);
                    }
                    else {
                        bool flag = false;
                        for (int j = 0; j < variable.size(); ++j) {
                            if (variable[j].name == vec[2] && vec.size() == 3) {
                                *(static_cast<std::string*>(variable[i].value)) = *(static_cast<std::string*>(variable[j].value));
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            *(static_cast<std::string*>(variable[i].value)) = vec[2].substr(1, (vec[2].length() - 2));
                        }
                    }
                }
                else if (variable[i].type == "tramabanakan") {
                    if (vec.size() > 3 && vec[2] == "!") {
                        for (int j = 0; j < variable.size(); ++j) {
                            if (variable[j].name == vec[3]) {
                                *(static_cast<bool*>(variable[i].value)) = !(*(static_cast<bool*>(variable[j].value)));
                                std::cout << *(static_cast<bool*>(variable[i].value));
                            }
                        }
                    }
                    else if (vec.size() > 3 && (vec[3] == "&&" || vec[3] == "||" || vec[3] == ">" || vec[3] == "==" || vec[3] == "<")) {
                        *(static_cast<bool*>(variable[i].value)) = boolOperators(vec[3], vec[2], vec[4]);
                    }
                    else {
                        bool flag = false;
                        for (int j = 0; j < variable.size(); ++j) {
                            if (variable[j].name == vec[2] && vec.size() == 3) {
                                *(static_cast<bool*>(variable[j].value)) = *(static_cast<bool*>(variable[j].value));
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            if (vec[2] == "false" || vec[2] == "0") {
                                *(static_cast<bool*>(variable[i].value)) = false;
                            }
                            else {
                                *(static_cast<bool*>(variable[i].value)) = true;
                            }
                        }
                    }
                }
            }
        }
    }
}


void declare(std::vector<std::string>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == ";") break;

        variables var;
        var.type = vec[i];
        ++i;
        var.name = vec[i];
        ++i;
        if (vec[i] == ",") continue;
        else if (vec[i] == "=") ++i;

        if (var.type == "amboghj") {
            var.value = static_cast<void*>(new int);
            *(static_cast<int*>(var.value)) = stoi(vec[i]);
        }
        else if (var.type == "racional") {
            var.value = static_cast<void*>(new double);
            *(static_cast<double*>(var.value)) = stod(vec[i]);
        }
        else if (var.type == "togh") {
            var.value = static_cast<std::string*>(new std::string);
            *(static_cast<std::string*>(var.value)) = vec[i].substr(1, (vec[i].length() - 2));
        }
        else if (var.type == "tramabanakan") {
            var.value = static_cast<void*>(new bool);
            if (vec[i] == "false" || vec[i] == "0") {
                *(static_cast<bool*>(var.value)) = false;
            }
            else if (vec[i] == "true" || vec[i] == "1") {
                *(static_cast<bool*>(var.value)) = true;
            }
        }
        else std::cout << "Error: invalid type.";
        variable.push_back(var);
    }
}


void translate(std::vector<std::string>& tokens) {
    if (tokens[0] == "amboghj" || tokens[0] == "racional" || tokens[0] == "togh" || tokens[0] == "tramabanakan") {
        declare(tokens);
    }
    else if (tokens[0] == "minchder") {
        cond.clear();
        lexer = "minchder";
        return;
    }
    else if (tokens[0] == "ete") {
        cond.clear();
        lexer = "ete";
        return;
    }
    else if (tokens[0] == "tpel") {
        print(tokens);
    }
    else {
        bool flag = false;
        for (int j = 0; j < variable.size(); ++j) {
            if (tokens[0] == variable[j].name) {
                operate(tokens);
                return;
            }
        }
        std::cout << "Error: invalid type of variable " << tokens[0] << std::endl;
    }
}


void lexing(std::ifstream& file) {
    while (!file.eof()) {
        std::string str;
        getline(file, str);
        std::vector<std::string>tokens;
        std::string temp;

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] != ' ' && str[i] != '\0') {
                temp += str[i];
            }
            else {
                tokens.push_back(temp);
                temp = "";
            }
        }

        if (tokens.size() == 0) continue;
        if (input != true) translate(tokens);
        if (lexer == "ete") {
            if (input != true) {
                detCond(tokens);
                tokens.push_back("{");
                for (int i = 0; i < tokens.size(); ++i) {
                    if (tokens[i] == "{") {
                        input = true;
                        break;
                    }
                    else continue;
                }
                continue;
            }
        }
        if (input == true && lexer == "ete") {
            conditionScope(tokens);
        }
        if (lexer == "minchder") {
            if (input != true) {
                detCond(tokens);
                tokens.push_back("{");
                for (int i = 0; i < tokens.size(); ++i) {
                    if (tokens[i] == "{") {
                        input = true;
                        break;
                    }
                }
                continue;
            }
        }
        if (input == true && lexer == "minchder") {
            int i = 0;
            if (tokens[i] == "}") input = false;
            if (input == true) {
                if (tokens[0] != "}")
                {
                    body.push_back(tokens);
                }
            }
            continue;
        }

        bool flag = doCondition(cond);
        while (flag == true) {
            if (tokens[0] != "}") {
                body.push_back(tokens);
            }
            continue;
        }
        while (flag == true) {
            for (int i = 0; i < body.size(); ++i) {
                translate(body[i]);
            }
            flag = doCondition(cond);
        }
    }
}

int main()
{
    std::ifstream file;
    file.open("text.txt");
    if (file.is_open()) {
        lexing(file);
    }
    else {
        std::cout << "ERROR: Can't open file" << std::endl;
    }

    return 0;
}
