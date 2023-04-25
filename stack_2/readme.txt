This project is an implementation of the std::stack container of the c++ standard library. It is designed to work in a LIFO (last in, first out) context, where elements are inserted and removed from only one end of the container. Container std::vector acts as the base container for stack in this project. It means that stack container is a one-dimensional array.

The container stack supports the following operations:
-get_size - returns the number of elements;
-is_empty - indicates whether the stack is empty or not;
-top ֊ returns a reference to the top (last added) element;
-push - inserts a new element at the top of the stack;
-pop - removes the element on top of the stack.

To compile and run the program, you need to enter the command "make" in the terminal. Use the command "make clean" to remove the intermediate files and the executable file "stack" created as a result of program compilation.
