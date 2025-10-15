- inhiritance :
    - single inheritance
    - multiple inheritance 
    - hybrid
    - multilevel 
    - hierarchical

- base class (parrent)
- derived class (child)

- access specifier
    - public : protected and public of bass class remain as they are
    - private: protected and public of bass class become private
    - protecter: protected and public of bass class become protected


- virtual destructor -> in the base class so the drived class can call the destructor (only use virtual destructor only if we overriden  in the drived class)

- C++ uses dynamic dispatch (runtime polymorphism) to find the actual destructor of the object type — even if the pointer is of base type.


```
The diamond problem The diamond problem occurs when two superclasses of a class have a common base class. For example, in the following diagram, the TA class gets two copies of all attributes of Person class, this causes ambiguities.
``` 


- Dynamic dispatch

- in virtual if we dont use override the compiler doesnt create, a virtual method for tha class 

meaning bass class "Base" and derived class "child" 
    -if no override -> the vptr(virtual pointer table) would have the same pointer to the parrent class virtual table
    -else if we have override the compiler create a new child vitual table that contain -> Child::method();
    