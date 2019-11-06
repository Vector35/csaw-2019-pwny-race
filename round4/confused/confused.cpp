#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

class Object
{
public:
    virtual void Print() = 0;
};

class NumberObject: public Object
{
    long long num;
public:
    NumberObject(long long n): num(n) {}
    virtual void Print()
    {
        printf("Number: %lld", num);
    }
    long long GetNumber() __attribute__((noinline)) { return num; }
    void SetNumber(long long n) __attribute__((noinline)) { num = n; }
};

class WordObject: public Object
{
    char* word;
public:
    WordObject(const char* w)
    {
        word = strdup(w);
    }
    virtual void Print()
    {
        printf("Word: %s", word);
    }
    const char* GetWord() __attribute__((noinline)) { return word; }
    void SetWord(const char* w) __attribute__((noinline)) { word = strdup(w); }
};

class Shape
{
public:
    virtual const char* Name() = 0;
};

class Square: public Shape
{
public:
    virtual const char* Name() { return "square"; }
};

class Circle: public Shape
{
public:
    virtual const char* Name() { return "circle"; }
};

class Triangle: public Shape
{
public:
    virtual const char* Name() { return "triangle"; }
};

class ShapeObject: public Object
{
    Shape* shape;
public:
    ShapeObject(Shape* s): shape(s) {}
    virtual void Print()
    {
        printf("Shape: %s", shape->Name());
    }
    Shape* GetShape() __attribute__((noinline)) { return shape; }
    void SetShape(Shape* s) __attribute__((noinline)) { shape = s; }
};

std::vector<Object*> objects;

void new_number()
{
    printf("Number:\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    objects.push_back(new NumberObject(strtoll(line, NULL, 0)));
}

void new_word()
{
    printf("Word:\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    if (line[0] == 0)
        return;
    line[strlen(line) - 1] = 0;
    objects.push_back(new WordObject(line));
}

void new_shape()
{
    printf("1) Square\n");
    printf("2) Circle\n");
    printf("3) Triangle\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    int choice = atoi(line);
    switch (choice)
    {
    case 1:
        objects.push_back(new ShapeObject(new Square()));
        break;
    case 2:
        objects.push_back(new ShapeObject(new Circle()));
        break;
    case 3:
        objects.push_back(new ShapeObject(new Triangle()));
        break;
    default:
        break;
    }
}

void new_object()
{
    printf("1) Number\n");
    printf("2) Word\n");
    printf("3) Shape\n");
    fflush(stdout);

    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    int choice = atoi(line);

    switch (choice)
    {
    case 1:
        new_number();
        break;
    case 2:
        new_word();
        break;
    case 3:
        new_shape();
        break;
    default:
        break;
    }
}

void list_objects()
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        printf("%d) ", (int)i);
        objects[i]->Print();
        printf("\n");
    }
    fflush(stdout);
}

void edit_number()
{
    printf("Index:\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    int i = atoi(line);
    if ((i < 0) || (i >= (int)objects.size()))
        return;

    NumberObject* n = (NumberObject*)objects[i];
    printf("Existing number: %lld\n", n->GetNumber());
    printf("New number:\n");
    fflush(stdout);
    if (!fgets(line, 127, stdin))
        return;
    n->SetNumber(strtoll(line, NULL, 0));
}

void edit_word()
{
    printf("Index:\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    int i = atoi(line);
    if ((i < 0) || (i >= (int)objects.size()))
        return;

    WordObject* w = (WordObject*)objects[i];
    printf("Existing word: %s\n", w->GetWord());
    printf("New word:\n");
    fflush(stdout);
    if (!fgets(line, 127, stdin))
        return;
    if (line[0] == 0)
        return;
    line[strlen(line) - 1] = 0;
    if (strlen(line) == 0)
        return;
    w->SetWord(line);
}

void edit_shape()
{
    printf("Index:\n");
    fflush(stdout);
    char line[128];
    if (!fgets(line, 127, stdin))
        return;
    int i = atoi(line);
    if ((i < 0) || (i >= (int)objects.size()))
        return;

    ShapeObject* s = (ShapeObject*)objects[i];
    printf("Existing shape: %s\n", s->GetShape()->Name());
    printf("New shape:\n");
    printf("1) Square\n");
    printf("2) Circle\n");
    printf("3) Triangle\n");
    fflush(stdout);
    if (!fgets(line, 127, stdin))
        return;
    int choice = atoi(line);
    switch (choice)
    {
    case 1:
        s->SetShape(new Square());
        break;
    case 2:
        s->SetShape(new Circle());
        break;
    case 3:
        s->SetShape(new Triangle());
        break;
    default:
        break;
    }
}

int main()
{
    while (true)
    {
        printf("1) New object\n");
        printf("2) List objects\n");
        printf("3) Edit number\n");
        printf("4) Edit word\n");
        printf("5) Edit shape\n");
        fflush(stdout);

        char line[128];
        if (!fgets(line, 127, stdin))
            break;
        int choice = atoi(line);
        switch (choice)
        {
        case 1:
            new_object();
            break;
        case 2:
            list_objects();
            break;
        case 3:
            edit_number();
            break;
        case 4:
            edit_word();
            break;
        case 5:
            edit_shape();
            break;
        default:
            break;
        }
    }
    return 0;
}
