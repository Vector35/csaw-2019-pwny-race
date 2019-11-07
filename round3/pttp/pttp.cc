#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define BUFSIZE 2048

class PString {
public:
    PString();
    PString(char *);
    ~PString();
    virtual char *get();
    virtual void set(char *);
    virtual unsigned int len();
private:
    unsigned int length;
    char *value;
};

PString::PString()
{
    length = 0;
    value = nullptr;
}

PString::PString(char *string)
{
    length = strlen(string);
    value = new char[length]();
    strncpy(value, string, length);
}

PString::~PString()
{
    length = 0;
    if (value) {
        delete[] value;
    }
}

char *PString::get()
{
    return value;
}

void PString::set(char *string)
{
    if (value) {
        delete[] value;
    }
    length = strlen(string);
    value = new char[length]();
    strncpy(value, string, length);
}

unsigned int PString::len()
{
    return length;
}


enum StringType { CSTRING = 0, PSTRING = 1 };
struct Item {
    unsigned long id;
    StringType type;
    void *string;
};


void pttp_get(std::vector<Item> *storage, unsigned long id)
{
    for (auto it = storage->begin(); it != storage->end(); it++) {
        if (it->id == id) {
            if (it->type == PSTRING) {
                PString *string = reinterpret_cast<PString *> (it->string);
                unsigned int string_size = string->len() + 1;
                char *output = new char[string_size]();

                strncpy(output, string->get(), string_size);
                output[string_size] = '\0';
                puts(output);
                delete[] output;
            } else if (it->type == CSTRING) {
                char *string = reinterpret_cast<char *> (it->string);
                puts(string);
            } else {
                puts("ERROR");
            }
            return;
        }
    }
    puts("ERROR");
    return;
}

void pttp_post(std::vector<Item> *storage, unsigned long type, char *string)
{
    Item item;

    // create new string storage item
    if (type == PSTRING) {
        PString *newstr = new PString(string);

        item.string = reinterpret_cast<void *> (newstr);
        item.id = reinterpret_cast<unsigned long> (newstr);
        item.type = static_cast<StringType> (type);
    } else if (type == CSTRING) {
        char *newstr = new char[strlen(string)+1]();
        strncpy(newstr, string, strlen(string)+1);

        item.string = reinterpret_cast<void *> (newstr);
        item.id = reinterpret_cast<unsigned long> (newstr);
        item.type = static_cast<StringType> (type);
    } else {
        puts("ERROR");
        return;
    }

    storage->push_back(item);
    puts("OK");
    printf("%lu\n", item.id);
    return;
}

void pttp_put(std::vector<Item> *storage, unsigned long id, char *string)
{
    for (auto it = storage->begin(); it != storage->end(); it++) {
        if (it->id == id) {
            char *newstr = new char[strlen(string)+1]();
            strncpy(newstr, string, strlen(string)+1);

            it->string = newstr;
            it->id = reinterpret_cast<unsigned long> (newstr);
            puts("OK");
            printf("%lu\n", it->id);
            return;
        }
    }
    puts("ERR");
    return;
}

void pttp_delete(std::vector<Item> *storage, unsigned long id)
{
    for (auto it = storage->begin(); it != storage->end(); it++) {
        if (it->id == id) {
            storage->erase(it);
            puts("OK");
            return;
        }
    }
    puts("ERR");
    return;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    std::vector<Item> *storage = new std::vector<Item>();
    char input[BUFSIZE] = { 0 };
    unsigned long id;

    // place stdout into non-buffered mode
    setvbuf(stdout, NULL, _IONBF, 0);

    while (true) {
        // get command
        if (!fgets(input, 8, stdin)) {
            return 1;
        }

        if (!strncmp(input, "GET", 3)) {
            // get ID of data blob to return
            if (!fgets(input, 32, stdin)) {
                return 1;
            }
            id = atoi(input);

            pttp_get(storage, id);
        } else if (!strncmp(input, "POST", 3)) {
            // get type of data to store
            if (!fgets(input, 8, stdin)) {
                return 1;
            }
            if (!strncmp(input, "ZSTR", 4)) {
                id = 0;
            } else if (!strncmp(input, "PSTR", 4)) {
                id = 1;
            } else {
                puts("ERROR");
                continue;
            }

            // get data to store
            if (!fgets(input, BUFSIZE-1, stdin)) {
                return 1;
            }

            pttp_post(storage, id, input);
        } else if (!strncmp(input, "PUT", 3)) {
            // get ID of data blob to replace
            if (!fgets(input, 32, stdin)) {
                return 1;
            }
            id = atoi(input);

            // get data to store
            if (!fgets(input, BUFSIZE-1, stdin)) {
                return 1;
            }

            pttp_put(storage, id, input);
        } else if (!strncmp(input, "DELETE", 3)) {
            // get ID of data blob to delete
            if (!fgets(input, 32, stdin)) {
                return 1;
            }
            id = atoi(input);

            pttp_delete(storage, id);
        } else if (!strncmp(input, "END", 3)) {
            puts("OK");
            break;
        } else {
            puts("ERROR");
        }
    }

    delete storage;
    return 0;
}

void win()
{
    system("/bin/bash");
}