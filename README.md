Guys,

You will find in this repesitory my push_swap project.

The principle is to oreder a list of integer passed through thh terminal command, but some restricitons are imposed to complete this project.

Firstly, you only can use two stack to order the integers.

Seccondly, you have a limited move possibles to order the integers:

To complete this projet, you will have to implement two different algorithms: one for small datasets and one for big ones.

The algo for small dataset is quite simple to implement but must be highly efficient.

My strategy to complete the algo for big statset has been to make a copy of the inputs into an array of integers, then order it using quick sort algorithm. Then I know exactly the exact position of each element. I have then create chunks to pass from stack a to stack b to make a first sort. Then I pass elements from stack b to stack a at the exact position.


Results
Dataset size = 500 => less than 7000 moves
Dataset size = 100 => less than 730 moves
Dataset size = 5 => less than 10 moves
Datset size = 3 => less than 4 moves
