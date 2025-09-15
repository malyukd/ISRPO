#include "StringHandler.h"
#include <cstring> 
#include <iostream>

StringHandler::StringHandler(char* str) {
    strcpy_s(this->str, str);
    divide(this->str, sizeof(this->str),0);
}

//void StringHandler::divide(char *str, size_t size) {
//    int i = 0;
//    char* ind = str;
//    //protocol
//    char* p = strstr(str, "://");
//    if (p == nullptr)
//        throw("Request is invalid. Invalid format");
//    while (ind != p && i+1 < strlen(this->protocol)
//        this->protocol[i++] = *(ind++);
//    this->protocol[i] = '\0';
//    ind += 3;
//    std::memmove(str, ind, std::strlen(ind) + 1);
//    ind = str;
//    //ip
//    p = strstr(str, ":");
//    if (p == nullptr || strlen(ind) <= 3)
//        throw("Request is invalid. Invalid format");
//    i = 0;
//    while (ind != p)
//        this->ip_a[i++] = *(ind++);
//    this->ip_a[i] = '\0';
//    ind += 1;
//    std::memmove(str, ind, std::strlen(ind) + 1);
//    ind = str;
//    //port
//    p = strstr(str, "/");
//    if (p == nullptr || strlen(ind) <= 1)
//        throw("Request is invalid. Invalid format");
//    i = 0;
//    while (ind != p)
//        this->port[i++] = *(ind++);
//    this->port[i] = '\0';
//    std::memmove(str, ind, std::strlen(ind) + 1);
//    ind = str;
//    //volume_name
//    if (strlen(ind) <= 1)
//        throw("Request is invalid. Invalid format");
//    ind += 1;
//    strcpy_s(this->volume_name, sizeof(this->volume_name), ind);
//    
//}

void StringHandler::divide(char* str, size_t size, int format) {
    char* ind = str;
    if (format == 3) {
        strcpy_s(this->volume_name, ind);
        return;
    }
    char* p = strstr(ind, this->symbol[format]);
    if (p == nullptr || strlen(ind) <= strlen(this->symbol[format]))
        throw std::invalid_argument("Request is invalid. Invalid format");
    int i = 0;
    while (ind != p && this->format[format]+1)
        *(this->format[format]++) = *(ind++);
    *(this->format[format]) = '\0';
    ind += strlen(this->symbol[format]);
    divide(ind, size, format+1);
}

bool StringHandler::isProtocolValid() {
    if (!strcmp(this->protocol, "tcp") || !strcmp(this->protocol, "iscsi") || !strcmp(this->protocol, "nbd"))
        return true;
    return false;
}

bool StringHandler::isIPValid() {
    char ip[4][4];
    int ind=0;
    char buffer[4];
    for (int i = 0; i < 4; i++) {
        int count = 0;
        while (this->ip_a[ind] && this->ip_a[ind] != '.') {
            if(count>2)
                throw std::invalid_argument("Request is invalid. Invalid IP address");
            buffer[count++] = this->ip_a[ind++];
        }
        buffer[count] = '\0';
        strcpy_s(ip[i], buffer);
        ind++;
    }
    for (int i = 0; i < 4; i++) {
            if (atoi(ip[i]) < 0 && atoi(ip[i]) > 256)
                return false;
            if (ip[i][i] != '0' && atoi(ip[i]) == 0)
                return false;
    }
    return true;
}

bool StringHandler::isPortValid() {
    int i = atoi(this->port);
    if(port)
}

bool StringHandler::isValid() {
    return true;
}

