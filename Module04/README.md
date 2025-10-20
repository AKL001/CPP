1 **SubType Polymorphism**
Subtype poly is achived through inheritance and virtual function , when we have a base class have a virtual function , the derived class can override(change) the function , the correct function is called in runtime
via a virtual table pointer .

why we use it:
    - runtime flexibility 
    - add new type without modifying existing code
    
Notes:
    - Always make the base class destructor virtual when using polymorphism
    - Polymorphism works with pointers and references, not value types
    - dynamic binding ,  static binding
    - The base class only needs a virtual destructor to enable dynamic dispatch for destruction.
    -The vptr inside the object ensures the right destructor chain is called at runtime.


2 **Abstract base class**
-you cannot create an instance of an abstract base class , but you can create other classes that are derived from it 
-A pure virtual function is a virtual memeber function that belongs to a base class and need to be redefined in derived class 

- redefined vs override

- when a class has a pure virtual function as a memeber , it becomes an abstract base class 

- virtual vs Pure virtual (=0) => virtual : can be overriden in subclass , but Pure must be overriden in subclass , also the abstract base class can be created as an instance 

- Interface vs Abstract class :
    => Abstract class : need to have at  least one pure virtual function, can have member functions, 
        have non-virtual functions.
    => Interface class : No data members no implemeted methods , only pure virtual functions.
    