## Conventions
In general, the conventions should make bugs as clear as possible

- Use capitalized camel case for functions, and not capitalized for attributes. `LikeThis()` and `this->likeThis`. Prefix globals with `g`, `gLikeThis`.
- In class declarations, use declare public, then private. Within that, declare in the following order: default constructor, copy constructors, destructor, alphabetized methods, newline, alphabetized attributes, newline, private, repeat. See the example below.
- For pointers and references, use `Type* thing` or `Type& thing`, not `Type *thing`.
- Despite being technically unnecessary, preface methods and attributes with `this->` so it's explicit that it's a method or attribute.
- In function declarations, put the return type, name, and args on one line followed by space and open brace:

## Example header and source files
---
```
// SomeClass.cpp


```
---
```
// SomeClass.h
#pragma once

class SomeClass
{
public:
    SomeClass();                                 // Put default constructor first
    SomeClass(const SomeClass* const object);    // Put copy constructors second
    SomeClass(const int x);                      // Then any other constructors
    ~SomeClass();                                // Last is the destructor
    AMutator();                                  // Then any other methods, alphabetized
    BMutator()                                   // If a method isn't marked const, assume it is a mutator
    NotMutator2(const int x) const;              // Const correct EVERYTHING otherwise

    float* anything;                            // Newline, then attributes
    int data1;
    int data2;
    int* gData;

private:                                        // Newline, private, wash, rinse, and repeat
    FooBarBaz();            
    GooBarBaz();

    float aDerp;
    int* bDerp;
}
```
