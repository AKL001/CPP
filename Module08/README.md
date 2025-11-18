+++Containers:
+std::vector -> dynamic array , start at a memory point and when it all filled up , it reallocat all to another block , and keeps going , memory of an index could changes , if we changed in the array meaning if added some thing in the back or front

+std::list -> double linked list 

+std::deque -> (double ended q) its like a vector and list at the same time , so the pointer is not changed , like having multiple blocks of memory adjustable, we only allocat a new block if needed , pointer are the same , memory of an index doesnt change

+std::set -> sorts the insertions , also doesnt duplicate the data 
+std::unordred_set -> doesnt sort the insertion 

+++Iterators:

// aranged based for loops C++11
    for (int <name> : <array u want to interat>)
        // 
// just like the above look but with iterators
for (std::vector<int>::iterator it = value.begin(); it != value.end() ; it++)
{
    // it is a pointer 
    *it;
}

Iterator  is a smart pointer:
    1- points to a specific element in the container 

when would interator help us , example :
    vector when it switch block we can just use 

NOTES:
    Iterators are categories:
        - output_iterator
        - forward_iterator
        -bidirectional_iterator
        -random_access_iterator
        -iterator
<iterator>::distance -> calculate the istance between first and last

