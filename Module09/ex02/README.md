engineering the logic to work with :

    class FordJohnson algo
        private members:
            -comparisons
            -time_taken
            -Pair struct 
            - isLess() function that calculate the comparisons
            -getJacobsthal() function to get the jacobsthal number
            -make a binary search or we could just use the lower_bound of the container
            

            -mergeinsertion() recursive function that sort the container
                STEP A :
                -> base case = .size() <= 1
                -> look if we have a stragller ,meaning a odd number without his pair
                -> using a loop we pair the numbers
                STEP B :
                -> recursion we send the winners mergeinsertion(winners)

                STEP C: SETUP PENDING LIST
                -> mainchain = sorted winners;
                    pendingLosers;
                //  we map the losers back to the sorted winners 

                STEP D : Insertion 
                1)
                -> at first we insert b1 befor a1 , we know that b1 is less thatn a1
                2)
                -> after that we make another Toinsert list removing the b1
                -> if we have a strangled (odd number ) we add it to the pending list
                3)
                -> now the Jacobsthal insertion loop , find the groupEnd , and start , we could use like a list where we define those numbers without calculating them
                
    public:
        -Constructor 
        -sort(); function that call the mergeinsertion and calculate the time and comparison
        -getters for the time and comparison


use this commands to check if sorted 
``` bash :

    ./PmergeMe `shuf -i 1-1000000 -n 3000 | tr "\n" " "` | grep "After" | python3 -c "import sys; line = sys.stdin.read().split()[1:]; nums = [int(n) for n in line]; print('Sorted:', nums == sorted(nums))"

    ./PmergeMe 3 5 9 7 4 | grep "After" | python3 -c "import sys; line = sys.stdin.read().split()[1:]; nums = [int(n) for n in line]; print('Sorted:', nums == sorted(nums))"

    or 

    # 1. Run your program and save only the numbers from "After:" to a file
    ./PmergeMe 5 2 3 1 4 | grep "After" | cut -d ':' -f 2 | tr ' ' '\n' | grep -v "^$" > output.txt

    ./PmergeMe `shuf -i 1-1000000 -n 30000 | tr "\n" " "` | grep "After" | cut -d ':' -f 2 | tr ' ' '\n' | grep -v "^$" > output.txt
    # 2. Check if that file is sorted numerically (-n)
    sort -n -c output.txt
``` 