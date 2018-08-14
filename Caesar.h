//
// Created by yuriy on 14.08.18.
//

#ifndef CAESARCIPHER_CAESAR_H
#define CAESARCIPHER_CAESAR_H

#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

std::string encrypt(std::string, int);                          // method for encrypt text string
std::string decrypt(std::string, int);                          // method for decrypt encrypted string

#endif //CAESARCIPHER_CAESAR_H
