// Copyright 2023 Selivankin Sergey

#include <stdexcept>
#include <vector>
#include "include/cipher_application.h"
#include "include/cipher.h"

void CipherApplication::help(const char *appname) {
    std::string builder;

    builder
    .append("This is a caesar cipher application.\n\n")
    .append("Please provide arguments in the following format:\n\n")
    .append("\t$ ")
    .append(appname)
    .append(" <op type> <number of words> <words>\n\n")
    .append("Where <op_type> may be \"d\" or \"e\"\n\n")
    .append("(decoding and encoding respectively)")
    .append("<number of words> is an integer\n\n")
    .append("<words> is a string");

    m_message = std::move(builder);
}

size_t parseUInt(const char *value) {
    try {
        int integer = std::stoi(value);
        if (integer < 0) {
            throw std::exception();
        }

        return static_cast<size_t>(integer);
    } catch (const std::exception &e) {
        throw std::invalid_argument("Expected positive integer");
    }
}

bool CipherApplication::validateArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }

    if (argc < 4) {
        m_message =
                std::string("[ERROR] Should be at least 4 elements. Type `$ ")
                + argv[0]
                + "` to see help";
        return false;
    } else {
        std::string op = argv[1];
        if (op.size() > 1 || (op[0] != 'd' && op[0] != 'e')) {
            m_message =
                    std::string(R"([ERROR] <op_type> must be only "d" or "e")")
                    + ("Type `$ ")
                    + argv[0]
                    + "` to see help";
            return false;
        }
    }

    size_t size;
    try {
        size = parseUInt(argv[2]);
    } catch (const std::exception &e) {
        m_message =
                std::string("[ERROR] Can't parse <number of words>: ")
                + e.what()
                + ". Type `$ "
                + argv[0]
                + "` to see help";
        return false;
    }

    if (size != static_cast<size_t>(argc - 3)) {
        m_message =
                std::string("[ERROR] Elements count doesn't ")
                + "match <number of words>."
                + " Type `$ "
                + argv[0]
                + "` to see help";
        return false;
    }

    return true;
}

std::string CipherApplication::operator()(int argc, const char **argv) {
    if (!validateArguments(argc, argv)) {
        return m_message;
    }

    std::string text;
    for (int i = 3; i < argc; ++i) {
        text.append(argv[i]);
        if (i != argc - 1)
            text.append(" ");
    }

    CaesarCipher c;
    std::string result;
    std::string op = argv[1];
    switch (op[0]) {
        case 'd':
            result = c.decode(text);
            break;
        case 'e':
            result = c.encode(text);
            break;
    }

    return result;
}
