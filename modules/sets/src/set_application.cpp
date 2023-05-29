// Copyright 2023 Mironov Nikita

#include "include/set_application.h"

void set_application::help() {
    message += "This application is needed to work with the Set class.\n\n";
    message += "To get started, write one of the commands below: \n";
    message += "; - to separate operations \n";
    message += "get - to get elements of set \n";
    message += "insert - to inset element or elements separated by space \n";
    message += "erase - to erase element \n";
    message += "exist - to check if the element exists \n";
    message += R"(/ - to separate  two sets in following commands 
     /like & 1 2 3 / 2 3 5 / \n)";
    message += "& - to intersect two sets /like & 1 2 3 / 2 3 5 / \n";
    message += "| - to union two sets /like | 1 2 3 / 2 3 5 / \n";
    message += "- - to difference two sets /like - 1 2 3 / 2 3 5 / \n";
}

bool set_application::is_number(const std::string& string) {
    std::string::const_iterator iterator = string.begin();
    while (iterator != string.end() && std::isdigit(*iterator))
        ++iterator;
    return !string.empty() && iterator == string.end();
}

std::string set_application::operator()(int argc, const char** argv) {
    int operation_started = 0;

    if (argc == 1) {
        help();
    }

    for(int arg_num = 1; arg_num < argc; ++arg_num){
        if (arg_num != 1)
            message += " ";
        std::string arg(argv[arg_num]);
        if (arg == ";") {
            continue;
        }
        if (arg == "get") {
            std::vector<int> elems = set.getElems();
            if(!set.getElems().empty()){
                for (int elem = 0; elem < elems.size(); elem++) {
                    message += " " + elems[elem];
                }
                message += '\n';
            } else {
                message += "Notification: set is empty.\n";
            }
            continue;
        }
        if (arg == "insert") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for insert!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for insert!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't insert non digit!";
                break;
            }
            int insert_arg_num = arg_num + 1;
            std::string insert_arg(argv[insert_arg_num]);
            while (is_number(insert_arg)) {
                set.insert(stoi(insert_arg));
                if (insert_arg_num + 1 < argc) {
                    insert_arg_num += 1;
                    std::string insert_arg(argv[insert_arg_num]);
                } else {
                    break;
                }
            }
            arg_num += (insert_arg_num - arg_num) - 1;
            continue;
        }
        if (arg == "erase") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for erase!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for erase!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't erase non digit!";
                break;
            }else if (!set.isExit(stoi(std::string(argv[arg_num + 1])))) {
                message += "Notification: element doesn't exist.\n";
                arg_num += 1;
                continue;
            } else {
                set.erase(stoi(std::string(argv[arg_num + 1])));
                arg_num += 1;
                continue;
            }
        }
        if (arg == "exist") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for check!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for check!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't erase non digit!";
                break;
            } else if (!set.isExit(stoi(std::string(argv[arg_num + 1])))) {
                message += "Notification: element doesn't exist.\n";
                arg_num += 1;
                continue;
            } else {
                message += "Notification: element exists.\n";
                arg_num += 1;
                continue;
            }
        }
        if (arg == "&") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for intersect!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for intersect!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for intersect!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            while (true) {
                if (!is_number(inter_arg) && inter_arg != "/") {
                    message += "Error: can't intersect non digit!";
                    break;
                }
                if (inter_arg == "/") {
                    first_set_filling = false;
                    if (inter_iterator + 1 != argc) {
                        inter_iterator += 1;
                        std::string inter_arg(argv[inter_iterator]);
                        continue;
                    } else {
                        break;
                    }
                }
                if (first_set_filling) {
                    first_set.insert(stoi(inter_arg));
                } else {
                    second_set.insert(stoi(inter_arg));
                }
                if (inter_iterator + 1 == argc) {
                    break;
                } else if (std::string(argv[arg_num + 1]) == ";") {
                    break;
                }
                inter_iterator += 1;
                std::string inter_arg(argv[inter_iterator]);
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set & second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (int i = 0; i < res.size(); i++) {
             message += " " + res[i];
            }
            message += '\n';
            continue;
        }
        if (arg == "|") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for union!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for union!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for union!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            while (true) {
                if (!is_number(inter_arg) && inter_arg != "/") {
                    message += "Error: can't union non digit!";
                    break;
                }
                if (inter_arg == "/") {
                    first_set_filling = false;
                    if (inter_iterator + 1 != argc) {
                        inter_iterator += 1;
                        std::string inter_arg(argv[inter_iterator]);
                        continue;
                    } else {
                        break;
                    }
                }
                if (first_set_filling) {
                    first_set.insert(stoi(inter_arg));
                } else {
                    second_set.insert(stoi(inter_arg));
                }
                if (inter_iterator + 1 == argc) {
                    break;
                } else if (std::string(argv[arg_num + 1]) == ";") {
                    break;
                }
                inter_iterator += 1;
                std::string inter_arg(argv[inter_iterator]);
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set & second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (int i = 0; i < res.size(); i++) {
             message += " " + res[i];
            }
            message += '\n';
            continue;
        }
        if (arg == "-") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for difference!";
                break;
            } else if (std::string(argv[arg_num + 1]) == ";") {
                message += "Error: need arguments for difference!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for difference!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            while (true) {
                if (!is_number(inter_arg) && inter_arg != "/") {
                    message += "Error: can't difference non digit!";
                    break;
                }
                if (inter_arg == "/") {
                    first_set_filling = false;
                    if (inter_iterator + 1 != argc) {
                        inter_iterator += 1;
                        std::string inter_arg(argv[inter_iterator]);
                        continue;
                    } else {
                        break;
                    }
                }
                if (first_set_filling) {
                    first_set.insert(stoi(inter_arg));
                } else {
                    second_set.insert(stoi(inter_arg));
                }
                if (inter_iterator + 1 == argc) {
                    break;
                } else if (std::string(argv[arg_num + 1]) == ";") {
                    break;
                }
                inter_iterator += 1;
                std::string inter_arg(argv[inter_iterator]);
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set & second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (int i = 0; i < res.size(); i++) {
             message += " " + res[i];
            }
            message += '\n';
            continue;
        }
    }
    message += '\n';
    return message;
}
