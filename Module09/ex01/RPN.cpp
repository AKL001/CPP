/*
    -container used : stack , vector
    -parsing: number should be less than 10, double or int ? 
    -operators: - + * / 
    -error handling: throwing exceptions
    "8 9 * 9 - 9 - 9 - 4 - 1 +"
    after hadling the parsing  part 
    1) push 8 then 9 
    2) if operator 
    3) pop right , then pop left , push (left operator right)
    4) if number push
    5) operator ... repeat

    -edge cases : deviding 0 , / 0 
    -number bigger than 10

    */