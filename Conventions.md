## Conventions (how should code look?)
In general, the conventions should make bugs as clear as possible. 

- Use capitalized camel case for functions, and not capitalized for attributes. `LikeThis()` and `this->likeThis`; Prefix globals with `g`, `gLikeThis`.
- In class declarations, use declare public, then private. Within that, declare in the following order: default constructor, copy constructors, destructor, alphabetized methods, newline, alphabetized attributes, newline, private, repeat. See the example below.
- For pointers and references, use `Type* thing` or `Type& thing`, not `Type *thing`.
- Despite being technically unnecessary, preface methods and attributes with `this->` so it's explicit that it's a method or attribute.
- In function declarations, put the return type, name, and args on one line followed by space and open brace.
- Every source file should have three sections - ctors/dtors/Startup/Shutdown, public, and private; separate them and keep them alphabetized.

## Practices (how should code work?)
- Every single thing that can be `const` should be
- Assume all non-const functions are mutators and all non-const parameters are mutated
- Use const variables instead of #define'd things where possible

## Example header and source files
---
```
// SomeClass.h
#pragma once													// Prevent multiple includes

class SomeClass
{
public:
    SomeClass();												// Put default constructor first
    SomeClass(const SomeClass* const object);					// Put copy constructors second
    SomeClass(const int x);										// Then any other constructors
    ~SomeClass();												// Last is the destructor
	StartUp();													// If the class is a subsystem, put StartUp and ShutDown after the constructors/destructors
	ShutDown();			
    int AMutator();												// Then any other methods, alphabetized. If a method isn't marked const, assume it is a mutator
    void NotMutator2(const int x, const SomeType* thing) const;	// Const correct EVERYTHING otherwise

    float* anything;											// Newline, then attributes
    int data1;
    int* gData;

private:														// Newline, private, wash, rinse, and repeat
    FooBarBaz();            
    GooBarBaz();

    float aDerp;
    int* bDerp;
}
```
---
```
// SomeClass.cpp
 
#include <vector>												// include std headers first, then third party, then Gibson's
#include <3rdparty.h>
#include <myOtherClass.h>  
                      
// ctors/dtors/Startup/Shutdown
// Omitting for concision, use ordering in the header file

// public
int SomeClass::AMutator() {
	int x, y, z;												// Do all unconditional declarations/initializations first, then execute
	Finger* ptr1, ptr2, ptr3;

	MutateThings();
	return x;
}              
                    
void SomeClass::NotMutator2(const int x, const SomeType* thing) const {
	int x, y, z;
	Finger* ptr1, ptr2, ptr3;

	MutateThings();
}   

// private
// Also omitted - you get the idea
```