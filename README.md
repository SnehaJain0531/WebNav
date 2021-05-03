# WebNav 
DS Project - Semester 3
Implementation of Simple Web Browser Navigation in C 

Data Structure incorporated - Circular Doubly Linked List

A structure called 'Node' is created which has the website link as the data part, the left link stores the address of the previous webpage and the right link stores the address of the next webpage.There is also a header node.
The operations included are:
1.create
2.insert
3.delete
4.search
5.display

1. create function:
*getNode(char *name)
the website is taken as a string.

2. insert function:
*insert(Node* start)
we have the webpage name as a string and we are calling the getNode() function which helps to create the node the for given website.If the website is not available then a relevant message is printed else node will get linked with the header node,this keeps on going.

3. delete function:
*delete(Node* start)
this takes the website address from the user and then checks whether the website is there or not , if yes then it deletes the node containing that address else it prints "not found".

4. search function:
search(Node *start)
checks whether the asked website is found or not, if it's found it opens the respective website else prints a message saying "PAGE NOT FOUND".

5. display function:
display(Node *start)
it asks the user to select which page to be displayed ,by giving the options 'Next page' and 'previous page' and according to the users selection it displays the web page.
