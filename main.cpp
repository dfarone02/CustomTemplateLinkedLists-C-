//Daniel Farone
//CSCI 3110-001
//Project #3
//Due: 02/24/22
//This driver file creates an custom instance of the TSLList class template then reads input from "rectangles.txt"
//Each line of the read file contains a length value, a width value, and an operation instruction. 
//Depending on the letter read,the integer value is either added or deleted from the list. 
//For every line of the input file the printAll() function is called which displays every rectangle currently in the list.
#include "tsllist.h"
#include "rectangle.h"
#include <fstream> 

int main()
{
 	TSLList<Rectangle> list;
	int rectLength;
	int rectWidth;
	char letter;
	std::ifstream infile;
	infile.open("rectangles.txt");
	
	while(infile >> rectLength >> rectWidth >> letter)
	{
    std::cout << letter << "(" << rectLength << "," << rectWidth << "): ";
    Rectangle box{rectLength, rectWidth};
		if(letter == 'a')
			list.insertInOrder(box);
		else if(letter == 'd')
			std::cout << "Returned " << list.deleteVal(box);
		else
			list.deleteAllVal(box);
		list.printAll();
	}
	infile.close();
	return 0;
}
