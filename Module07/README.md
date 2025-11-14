typename keyword used to define  the template type parameters 
or use class keyword same thing

function Templates 
Class templates 
variable Templates 

example:

template<typename T>
void print(T value)
{
    std::cout << value << std::endl;
}
/*
template function are not created untill is called 
*/


int main()
{
    // we can call it like this  the compiler at compiling time define the type implicitly
    // The below example demonstrates how the STL  method deduces the data type without being explicitly specified.
    print(4);
    // or we define the type explicitly
    print<int>(5);
}

used by devs 
(.tpp)=> template implementation files.


why cant I seperate the definition of my templates class in .cpp file
"https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl"


well why not just put the implemetation in  a .cpp file is because the linker phase , linked wond know the implemetation of a template if its not in the same .cpp file. (separate compilation model.)