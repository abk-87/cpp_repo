This project is an implementation of the std::queue container of the c++ standard library. It is designed to to operate in a FIFO context (first-in first-out), where elements are inserted into the end of the container and extracted from the front side. Container std::forward_list acts as the base container for queue in this project. It means that queue container is a singly-linked list, linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next.

The container queue supports the following operations:
-get_size - returns the number of elements;
-is_empty - indicates whether the queue is empty or not;
-front - returns a reference to the first element;
-back - returns a reference to the last element;
-push - inserts a new element at the end of the queue;
-pop - removes the first element in the queue.

To compile and run the program, you need to enter the command "make" in the terminal. Use the command "make clean" to remove the intermediate files and the executable file "queue" created as a result of program compilation.
