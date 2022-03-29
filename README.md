# CustomTemplateLinkedLists-C-

Project description:

This assignment modifies the ordered singly linked list developed for Integer Linked Lists to store custom objects. The
list will hold objects representing rectangles and store them in ascending area order. The driver program instantiates a
list and applies operations read from the input file.


## Requirements:

### split into four files, the requirements for which are specified below:
  
  a) The Rectangle class – This class represents an individual rectangle
    
     Files named rectangle.h (provided) and rectangle.cpp
      
      i. Rectangle details:
        
         Each rectangle has length, width, and area data members.
        
         The Null Rectangle (one with all data members set to zero) is a special rectangle indicating a
        null value. This object is created by the default constructor.
      
      ii. Functions for the relational operators not defined in the header file must be implemented in .cpp file.
  
  b) The class template is fully implemented in a filed named tsllist.h. (no .cpp file). It follows the header
  file for Project 2, except for name changes and its implementation as a class template (so that the list is able to store
  any custom object, not just ints). You may not depart from those specifications (ask if in doubt). Note the following:
    
    all functions and data members specified in the Project 2 header file (but these must be modified
    to handle custom objects)
    
     use the following struct (replacing the one in Project 2):
     struct TSLLNode {
     TSLLNode(T el = T()) {
     info = el;
     next = nullptr;
     }
     T info;
     TSLLNode *next;
     };

### Implementation for functions required by the Project 2 header file. Observe the following:

  i. insertInOrder – Adds each custom object to the list in ascending area order. If there are objects in
  the list with the same value, the newly object must come after the one already in the list. Rectangle
  example: If custom object (Rectangle in this case) has length 3 and width 4 (area 12) is in the list,
  and a Rectangle with length 2 and width 6 (also having area 12) is added, the Rectangle with length
  2 and with 6 must come after the one of length 3 and width 4. See sample output.

  ii. deleteVal – This function removes the custom object that has the same value as the argument to
  the function. In the event there are multiple objects with that value in the list, this function should
  remove only the first object having that value. The object removed must be returned. Rectangle
  example: If the parameter has length 4 and width 5, the first rectangle with area = 20 (the one being
  deleted) should be returned. If a rectangle with area = 20 is not in the list, the function should return
  the Null Rectangle object.

  iii. deleteAllVal – This function must remove from the list all custom objects having the same value as
  the function argument. Rectangle example: If a call is made with a rectangle with length 2 and width
  4, all rectangles with area = 8 are removed from the list.

  iv. clearList – This function must remove all nodes from the list. It should print the word Clearing
  followed by the custom object being deleted. This function is called by the class destructor.

## A driver, or client, file

   named proj3.cpp

   Reads data from input file named rectangles.txt, with two integers and a character on each line:

    1. The first element of each line is an integer representing the length of the rectangle .

    2. The second element of the line (also an integer) is the width of the rectangle.

    3. The third element is one of characters a, d, or D, and should be interpreted as follows:

       a = add the rectangle to the list (rectangles with same area must follow rules above)

       d = removes the first rectangle in the list having the same area as the specified rectangle

       D = remove all rectangles having the same area as the specified rectangle

    4. A Rectangle with dimensions read must be declared and passed to one of the functions above.
    Note: The input file has an unspecified number of randomly shaped rectangles. The Null Rectangle or
    other invalid rectangles (such as those with negative dimensions) will not appear in the input file.
    Required output (see sample output for clarification):

   Each operation and its rectangle dimensions should be printed prior to calling any function.

   In the case where a single rectangle is removed (operation d), the rectangle returned by
  deleteVal must be output after the word “Returned” and before calling the printAll function.

   The printAll function must be called after each operation to show the contents of the list. 
