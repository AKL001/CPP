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


    