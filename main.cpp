#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream tmp("template.txt");
    std::ifstream sub("substitution.txt");

    std::map<std::string, std::string> sublist;

    std::string key, value;
    while (sub >> key >> value) {
        sublist[key] = value;
    }

    std::cout<<"\n>> substitutions:"<<std::endl;

    for (auto &it : sublist) {
        std::cout <<"key: "<<it.first << " "
                  <<"replacement: "<<it.second << std::endl;;
    }

    std::string t_key;
    std::string output;

    bool trigger;

    std::cout<<"\n>> original text:"<<std::endl;

    for (std::string line; std::getline(tmp, line);) {
        std::cout<<line<<std::endl;


        for (std::string::size_type i = 0; i < line.size(); i++) {
            if ('}'==line.at(i))
            {
                output += sublist[t_key];
                t_key="";
                trigger = false;
                continue;
            } else if ('{' ==line.at(i))
            {
                trigger = true;
                continue;
            } else if (trigger)
            {
                t_key += line[i];
            } else
            {
                output += line[i];
            }
        };
        output+="\n";

    };
    std::cout<<"\n>> replaced text:"<<std::endl;

    std::cout<<output<<std::endl;
    return 0;
}
