#include <iostream>

#include "../include/Client.h"

Client::Client() : fd(0) { }

Client::Client(int fd) : fd(fd) { }

const std::string& Client::getMessage() const {
    return this->msg;
}

void Client::addMessage(const std::string& msg) {
    this->msg += msg;
}

void Client::clearMessage() {
    this->msg.clear();
}

