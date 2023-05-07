This project is an implementation of the std::map container of the c++ standard library. Map is associative container that store elements formed by a combination of a key value and a mapped value, following a specific order. The map is implemented as binary search tree, which is a rooted data structure with the key of each internal node being greater than all the keys in the respective node's left subtree and less than the ones in its right subtree.

The container list supports the following operations:
-get_size - returns the number of elements;
-emplace - inserts a new element in the map;
-clear - removes all elements from the map.
-print - outputs the keys and values of the elements.

To compile and run the program, you need to enter the command "make" in the terminal. Use the command "make clean" to remove the intermediate files and the executable file "stack" created as a result of program compilation.
