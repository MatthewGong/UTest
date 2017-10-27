#ifndef CIRCULARARRAY_H_
#define CIRCULARARRAY_H_

#include <sstream>
#include <iostream>

template<typename T>

class CircularArray
{

public:

	// Constructors and destructors
	CircularArray(int size){

		// check for valid size
		if(size >= 1){

			MaxSize = size;
			TopNode = new Node();

			// if there's a single node in the array we have to 
			// link it to itself
			if(size == 1){

				TopNode->right = TopNode;
				TopNode->left  = TopNode;

			}else{
			// populate the array
				for(int i = 1; i < size; i++){
					std::cout << "I added a node!" << std::endl;
					// check and see if there is at least one node
					if(!TopNode->left){
						// if there hasn't been at least one node added then
						// we create and fully link the new node

						// link the new node to the TopNode
						Node* tempNode = new Node(TopNode,TopNode);

						// link the TopNode to the new node
						TopNode->left  = tempNode;
						TopNode->right = tempNode;


					} else {
						// if we have added at least one node then
						// we add in and link the node

						// Create and link the new node to the TopNode and its
						// left node
						Node* tempNode = new Node(TopNode->left,TopNode);

						// link the new node to the left node
						TopNode->left->right = tempNode;

						// link the TopNode to the new node
						TopNode->left = tempNode;

					}
				}	 
			}

		} else {
			// tell the user the size is invalid
			std::cout << "Invalid size parameter" << std::endl;

		}
		
	};	
	~CircularArray() {};

	/*
	ChangeTop(T datum)
	
	changes the value of the top node 
	*/
	void ChangeTop(T datum){
		TopNode.data = &datum;
	}

	/*
	RotateRight()

	rotates the array to the right by 1
	*/

	void RotateRight(){
	// By construction there will always be a right node. 
		TopNode = TopNode->left;
	}

	/*
	RotateLeft()

	rotates the array to the left by 1
	*/

	void RotateLeft(){
	// By construction there will always be a left node.
		TopNode = TopNode->right;
	}

	/*
	toString()

	generates a string of the array starting at the top and moving 
	clockwise(to the right) around the array
	*/

	std::string toString(){

		Node* first = TopNode;
		Node* current = TopNode;

		std::stringstream ss;

		do {
			
			// if the node has no data print EMPTY NODE
			if(!current->data){
				ss << "EMPTY NODE ";
			} else {
			// otherwise print the data in the node
				ss << current->data << ", ";
			}

			// move to the next node
			current = current->right;

		} while (current != first);

		return ss.str();
	}

	/*
	fill()

	fills in the nodes with increasing values starting at 1
	*/
	void fill(int start = 1, int increment = 1){
		Node *first = TopNode;
		Node *current = TopNode;
		
		do {
			
			// fill in the node with the value
			current->data = start;

			/* 
			THIS WAS A TESTING ARTIFACT
			std::cout << "I set the value to " + std::to_string(counter) << std::endl;
			if (current->data){
				std::cout << std::to_string(current->data) << std::endl;
			}
			*/

			// move to the next node
			current = current->right;
			start += increment;

		} while (current != first);

	}

	/*
	turn()

	rotate the array a certain number of times in the chosen direction	
	
	checks to see if we're rotating more than the size of the array and
	find the least number of turns to get into the desired position
	
	*/
	void turn(int rotations, std::string direction){

		// 
		int efficient = 0;

		if(direction == "left"){
			// Check to see if we can be more efficient on the rotation
			if(rotations%MaxSize > MaxSize/2){
				efficient = MaxSize - rotations%MaxSize;
				std::cout <<"It was more efficient to go right." << std::endl;
				for(int i=0; i < efficient; i++){
					RotateRight();
				}

			} else {
				if(rotations%MaxSize == 0){
					std::cout << "no reason to move." << std::endl;
				} else{
					for(int i=0; i<rotations; i++){
						RotateLeft();
					}
				}

			}

		} else {
			// Check to see if we can be more efficient on the rotation
			if(rotations%MaxSize > MaxSize/2){
				efficient = MaxSize - rotations%MaxSize;
				std::cout <<"It was more efficient to go left." << std::endl;
				for(int i=0; i < efficient; i++){
					RotateLeft();
				}
			} else {

				for(int i=0; i<rotations; i++){
					RotateRight();
				}
			}
		}

	}

private:

	struct Node
	{
		T data; // generic holder for whatever kind of data we want to use
		Node *left; //allows nodes to be linked 
		Node *right; //allows nodes to be linked

		Node(Node *left, Node *right) // constructor with no data
			: data(), left(left), right(right){}
		
		Node(Node *right) //constructor with no data and right node
			: data(), left(), right(){}

		Node() //constructor with no data or neighbors
			: data(), left(), right(){}

		~Node(){};
	};

	Node* TopNode;
	int MaxSize;
};

#endif