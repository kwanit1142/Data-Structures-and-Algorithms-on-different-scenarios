# Data-Structures-and-Algorithms-on-different-scenarios

## Lab-1

Using linked list, write a program to add, subtract and evaluate polynomials: P1(x), P2(x), P3(x) and P4(x) where P1(x) and P2(x) are input polynomials and P3(x) = P1(x)+P2(x) and P4(x)=P1(x)-P2(x). Each node in the linked list correspond to a term in the polynomial. So, in your node structure - you may keep two data components – integers pow and coeff; and one pointer to the next node.

### Input Format:

First line mentions K i.e. the number of test cases. Then there are three lines for each test case, In the first two lines of a test case, First number indicate the highest degree of polynomials N and then there are N+1 integers which are the coefficients of polynomial terms in descending order. In the third (and last line) of a test case, there is one integer i.e. value of x for which you need to evaluate the polynomials. (Constraints: 0≤K≤50, 0≤N≤9, -2≤x≤2, and Input coefficient terms would be between -100 to +100; Assume you can safely do calculations for each polynomial term without worrying about underflow/overflow issues).

### Note: 

There is a single space before and after =, +, -, and : in the output. There should be NO nodes in the linked list for the polynomial terms having 0 coefficient value. In the above example, the polynomials f1 and f2 were to be represented using 4 and 2 nodes in the linked list, respectively

### Remarks: 
There are three test cases in 2nd Sample Input. Remember to appropriate free the memory space after each test case. Input would be read from terminal (i.e. stdin) and not from any file

## Lab-2

Question 1:-

You have a stack with push, pop and stackTop functionality. Assume that you have a sequence of n integers 1,2,3,….,n in this order. Using the given stack and the built-in functionality as mentioned already, state whether it is possible to construct a given output sequence or not. If yes, then show the sequence. (You can read the input only sequentially. Similarly, you can write on the output only sequentially, and once the output is written, you can’t read or modify it later.)

Example 1: 

Given input n = 3. (i.e. sequence available to you is 1,2,3). And given sequence: 2,1,3.

Answer: Yes. It is possible by the following sequence of operations: push(1), push(2), pop(), pop(), push(3), pop(). (i.e., we can create the sequence 2,1,3 using a stack.)

Example 2: 

Given input n=3. Given sequence: 3,1,2.

Answer: Not possible.

Your program should first read a given n from the user. And then read a sequence of length n. User will provide the sequence with space between the elements. That is, for the sequence 1,2,3, you will get 1 2 3. The program should output Yes/No, followed by the sequence of push/pop steps as already shown in example 1 above (of course, this push/pop list should be output only when the answer is yes).

Question 2:-

Convert a given Infix expression to Postfix expression. And then evaluate this postfix expression. The following operators are allowed in the input:

(i) +, –, *, / (with + and – having same level of precedence, which is lower than that of * and /)

(ii) ( and ) having higher precedence than all other operators

(iii) ^ (unary squaring operator, having higher precedence than +,-,*,/ but lower than brackets). Example: 3^ evaluates to 9.

(iv) << and >> : bitwise binary operators for left shift and right shift. Have same level of precedence as ^. Example: 1<<3 evaluates to 8. And 8>>2 evaluates to 2. That is, the left operand is binary shifted left or right, and the number of bits shifted is given by the right operand. (These are two < or > symbols, without any space between them).

Example Input: 2+(3^ + 4)<<2

Example output line 1: 2, 3^, 4, +, <<, +

Example output line 2: 54

(that is, 2 + (9+4)<<2 = 2 + 13<<2 = 2+ 52 = 54)

You can assume that the input length is not more than 100 characters. In case the input is wrong, you should print an error message. For example, these are some wrong inputs: 1 + (3 (i.e. no closing bracket), / 4 ( no left operand).

We assume that unary – is not present in the input. The only way – is used is in binary format.

Question 3:-

You created a singly linked lists in the first assignment. Use the previous codes (create nodes, insert node and display the list) to construct a linked list from the given inputs. Say, with given input 12, 45 and 7, you should create a singly linked list with 3 nodes in this order, i.e. head pointing to the node having data 12. Use the display list function to show the current state of the list.

Then write a non-recursive program to reverse this linked list. That is, the new list should have the same nodes but in the reversed order. You should not allocate new memory andcreate another linked list. Just modify the pointers of the current linked list suitably. Then display the list. (For the given example, we expect 7, 45, 12 now, and the head of the list should point to the node containing the data 7).

Input: n integers, with space between the values (you can assume that the data values are within -1000 to 1000), and that n will be a small integer.

Output: first display the list (this should be matching with the input), then display the list again after the reverse function is called (this time the list should be reversed). 

## Lab-3

A binary search tree (BST) is a special kind of binary tree, in which the following is true:

For each node, data at the left node is smaller than the data at the right node. (Recall that a node contains a data field, and two pointers).

Assume that we construct a BST with values 5,8,9,4,6 in this order. Then the resultant tree will look like

On the other hand, if the input data sequence was 8,9,5 (or 8,5,9) then a balanced binary tree with height 1 will be obtained. (We always start with the root and go left or right, recursively, depending on the input value being smaller or larger). To delete a node from the binary tree, one needs to readjust the other nodes so that the BST property still holds. For example, to delete 9 from the above tree, simply delete the node containing value 9. However, to delete 8, we will need to move 9 up. The resultant tree will look like:


1. Write a C program to do the following: (Maintain a global pointer to the root of the BST. Display a menu after each operation. And depending on user input, call appropriate function with inputs provided by the user. Assume that all the values in the BST are distinct and positive).

(i) On menu input 1, call a function to insert data into a BST (which is initially empty). The input will be given as a sequence of positive integers. The length of the sequence is not pre-specified, and hence you should allocate the necessary memory dynamically. Ex. We can say, 2,4,3,7,5,1 and the appropriate BST with 6 nodes should be constructed.

(ii) On menu input 2, call a function to delete a node from the BST. The node value will be input by the user. (If there is no node with such a value then print ‘error’). Ex. In the BST constructed by you in step (i), we may ask you to delete 4 (i.e. the node containing the value 4). At one time, we will ask you to delete only one node, but we can call the same function multiple times in succession. You should take care of the BST being empty when node deletion function is called. (Take care to handle deletion of an internal node with one child or with two children; a leaf; or the root itself).

(iii) On menu input 3, display the number of leaves, the number of internal nodes, and the height of the tree. (Assume that the root is at height 0. That is, the maximum level number and the height are equal.)

(iv) On menu input 4, display the in- order traversal of the tree. (Non-recursive code. No marks for the recursive version. However, you should verify your code by checking that the output matches with the recursive version in every case.)

(v) On menu input 5, display the pre-order traversal of the tree. (Non-recursive code. Same comment as in (iv) above.)

(vi) On menu input 5, display the post-order traversal of the tree. (Non-recursive code. Same comment as in (iv) above.)

## Lab-4

1. [HEAP] Write a C program which works as follows: (You may create two global arrays of max_size=100 for the purpose of this problem. However, it is not mandatory.)

We will test your code for both min- and max- heaps. We will always start with input 1 below. You need to create 2 arrays: one for min-heap and the other for max-heap. All inputs in the question will be positive integers. You should print the current array after finishing each operation so that we can test
your code. If the current operation is of type X then print only the max-heap, and if the operation is of type N then print only min-heap (not both together).

(i) On input 1 X n m1 m2 m3 …..

Creates a maX-heap with n positive integers m1, m2, m3, …. You should first fill the array with the integers m1, m2, m3 …. And then convert this array into a max-heap. (Note that X is used for max heap)

(ii) On input 1 N n m1 m2 m3 …..

Creates a miN-heap with n positive integers m1, m2, m3, …. Similar to (i) above. (Note that N is used for min heap) 

(iii and iv) On input 2 X m and on input 2 N m

(iii) Insert integer m into the already existing max heap. 

(iv) same for min heap.

(v and vi) On input 3 X m and on input 3 N m

(v) Delete element m from the existing max heap. 

(vi) same for min heap.

(The way this operation should be implemented is to replace the deleted integer with the last element of the array and then moving elements so that the heap property is satisfied. Note that you may need to move the newly moved element upwards or downwards, depending on the current elements in the heap. If m is not present in the heap, then do nothing.).

(vii and viii) On input 4 X and on input 4 N

(vii) Delete max element from the existing max heap. 

(viii) Delete min element for min heap

(ix and x) On input 5 X and on input 5 N

(ix) Sort the array containing max heap. 

(x) Same for min heap.

2. [AVL Tree] Write a C program which works as follows: (You may assume that the tree will not contain more than 100 elements).
 
For the purposes of this exercise, you can take a global variable pointing to the root of the AVL tree. You should write separate functions for left-rotate and right-rotate. Call them appropriately to balance the tree when needed.

(i) On input 1 n m1 m2 m3 …..

Create an AVL tree with n positive integers m1, m2, m3, …. You should construct the AVL tree with insertion of elements in the given order.

(ii) On input 2 m

Insert the element m in the existing AVL tree.

(iii) On input 3 m

Delete the element m from the existing AVL tree. Do nothing if m is not present in the tree.

(iv) On input 4

Print the in-order traversal of the tree. For each node, print the contents as (data, height, balance factor). For example, if you have an AVL tree with 2 nodes, with the root and its left child containing data 5 and 3 respectively, then you should print (3,1,0), (5,0,-1).

Try not to use any specific property of AVL trees while implementing these.

(v) On input 5

Print the width, and the perimeter of the tree.

Width: The width (or diameter) of a tree is the number of nodes on the longest path between two leaf nodes. (It may or may not pass through the root).

Perimeter: Boundary nodes of the tree (sometimes also called boundary traversal – Search it).

(vi) On input 6 (a,b)

Print the lowest common ancestor of node containing ‘a’ and ‘b’

(vii) On input 7 (a,b)

Print the route (i.e. values of intermediate nodes) when you move from an ancestor node containing value ‘a’ to a descendant node containing value ‘b’ in the tree. Write -1 if no such path exists.

## Lab-5

1. Read two arrays A and B from the command line. You can assume that the input is given in two separate lines and the format of each line is as follows:
 
 N, x1, x2, …, xN

Here, N is the number of elements and this is followed by the actual numbers. Further, all the numbers are positive integers. Using hashing techniques we studied in the class, create two new arrays C and D such that:

(i) C contains numbers only in A or in B (symmetric difference) 

(ii) D contains numbers in both A and in B (intersection). 

Print C and D on separate lines. Your algorithm should run in linear time.

2. Read an array A from the command line just like the previous question. Then read a number k from the command line. Write a program to find two numbers x and y in A such that x+y = k. If no such pair can be found then print “Not found”.  Your algorithm should run in linear time.

## Lab-6

1. There is a single classroom but there are N professors interested in using it. The professors have id numbers 1,2,3…,N and we denote any data for their class by using their id number as a subscript (such as xi). Their classes run for time ti. There is no fixed start time for their classes, but the professors have other meetings(in fact, I bet, they have plenty of them), and they would like to finish their classes by a preferred deadline of di. Given a specific input of (ti, di) pairs, it may not be feasible to provide a schedule which is permissible under the given conditions. For example, (t1=2, d1=9), (t2=5, d2=6), (t3=3, d3=3). The third professor would like to finish her class of 3 time-units by time=3. But if that is permitted then the second professor can’t finish his class of 5 time-units by time=6. (Time starts from 0. We assume that the next class can start immediately after the previous one is finished. No two classes can overlap.)

Hence, we relax the conditions a little, and allow delays beyond their preferred finish time. But we don’t want to annoy professors (who would?). Hence, we permit delays beyond their preferred times but with a method to minimize the displeasure of the professors. Let us denote the finish time of the class by professor i as fi. We measure the annoyance of professor i by the following function:

annoyancei = max(fi - di , 0) (i.e. no annoyance if the class finishes by the preferred time).

Your goals is to come up with an algorithm which minimizes the sum maximum of annoyance of among all the professors. You are required to schedule all the classes (i.e. none of them can be skipped).

Input: You will read the input in the following way: (spaces between t’s and d’s, and new line for each class).

N
t1 d1
t2 d2
…
tN dN

Output: Print the order of classes taken by the professors in one line, and the total annoyance you computed in the next line. (e.g. in the given example, the output will be: first line: 3, 2, 1 and the second line: 3. This is because the 2nd class will start at 3 and finish at 8 thus having an annoyance of 2. And the
1st class will start at 8 and finish at 10 having an annoyance of 1. This scheduling produces a total annoyance of 3.)

You also need to provide a pdf file explaining the algorithm used, the cost of the algorithm and why is this algorithm optimal. Name the file as roll_number.pdf (Write the analysis and the proof of optimality of your algorithm formally).

2. Two players Akshara and Bharat play a game in which they take turns to make their moves. The game starts with Akshara deciding to collect some numbers from a given sequence. The rules of the game state that the player making the move can collect only one number from the given sequence, and that the selected number must be either at the beginning or at the end of the sequence. Once the player collects the number, the opponent gets to make a move. Every time a player collects the number, this specific number is removed from the sequence. The game stops when the sequence is empty. The winner of the game is the player who has collected a larger sum.

For example, if the given sequence is 3,5,2,1 and Akshara makes the first move. Then she can pick either 3 or 1. Let us suppose she picks 1. Then Bharat gets to move. The remaining sequence for him is 3,5,2. He may decide to pick 3. Then Akshara picks 5 from the sequence 5,2. And finally, Bharat picks the only remaining number 2. The game ends here. Akshara is the winner with her numbers summing to 6, while Bharat could only reach to 5.

Note that if Akshara had picked 3 in her first move then Bharat would have picked 5. And this would have allowed Bharat to win the game. Therefore, Akshara made a good decision by not going for the first number in the sequence on her first move. Hence, by using an “optimal strategy”, Akshara collected 6 points.

Your aim is to develop an efficient algorithm for maximizing the sum of numbers collected by Akshara on a given sequence of numbers, assuming that she makes the first move. You can assume that both the players are playing “optimally”, i.e. trying their best to get the larger sum for themselves.

Input: A sequence of numbers given in one line. (Some of you were having difficulties with reading inputs in the previous homework. In order to not bother with reading commas, we assume that the input in the following format:

 N x1 x2 … xN

Here, N is the number of elements and this is followed by the actual numbers. Further, all the numbers are positive integers. However, they need not be distinct.

Output: Total sum collected by Akshara. And the sequence of her moves. For instance, the given example will result in an output of:

Sum = 6
Steps = 1, 5

## Lab-7

Helper code: (being written here since some of you may not know file handling in C)

Create a file input.txt with the following data: (It shows the adjacency matrix of an undirected graph G). The graph can be represented as

4
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0

Create a C file with the following helper code:

'#include <stdio.h>'

int main(){

  int i,j, n, **M;
  FILE *fp;
  fp = fopen(“r”, “input.txt”);
  fscanf(fp, “%d”, &n); /* assuming that n is a positive integer. */
  M= (int **) malloc(sizeof(int *)*n);
  for(i=0; i<n; i++)
  M[i] = (int*) malloc(sizeof(int)*n);
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      fscanf(fp, “%d”, &M[i][j]);
      /* the above code reads the data from the file into the square matrix M */
      ….. /* Your code will come here */
      // free the memory allocated by malloc yourself
      fclose(fp);
  return 0;
  }

The above code will read the adjacency matrix given in the input file. Size and input may change

Note: If the matrix represents weights then the entries can be any integer values. The (i,j)th entry in the matrix represents if ith vertex is connected to the jth vertex (or its weight). If the matrix has (i,j)th entry as 2 but (j,i)th entry as 0 then it is denoting a directed graph where there is an edge (i,j) with weight 2 but the edge (j,i) is absent. An undirected graph’s matrix M will always be symmetric.

1. For a given directed unweighted graph (which is described by an adjacency matrix given in input.txt), perform DFS. Whenever there is a choice of vertices, pick the smaller numbered vertex. If the input matrix is of size n x n then assume that the vertices are numbered 1, 2, … n.

Input: Input matrix as defined earlier.

Output: First print the vertex numbers followed by their discovery time and finish time. Assume that the time when the first vertex is discovered is 1, and the time is incremented by 1 at every step as discussed in the class. Then print an n x n matrix, which should mimic the adjacency matrix. Wherever there was no edge between vertex i and vertex j (i.e. when (i,j)th entry of M is zero), print 0. For the rest of the edges, print their type. Print T for tree edge, F for forward edge, B for back edge and C for cross edge. The output should look like what is given below. (Note: the matrix shown below may not be meaningful. In fact, it is invalid for the given example (there can only be 3 tree edges for 4 vertices). It is being shown only to present the format of the output).

1 discovery1 finish1
2 discovery2 finish2
…
N discoveryn finishn

0 T 0 F
0 0 T C
0 T 0 B
0 T C 0 

2. Given the weight matrix of an undirected graph, implement Kruskal’s algorithm to find a Minimum Spanning Tree.

Note that this will require you to implement a function to test if a specific edge is “safe” or not. That is, you will need to check if the specific edge is creating a cycle if added to the set A (as discussed in the class).

Input: A weight matrix of size n x n as explained on page 1.

Output: The weight of the MST you found. 

3. For a given weighted undirected graph specified by it weight matrix, and a given source vertex i find the shortest distance of all the vertices from the source vertex using Dijkstra’s algorithm.

Input: The first line of the input file will have two entries n and S with space between them, where n will denote the number of vertices (labelled 1 to n) and S will denote the source vertex. S will be an integer from among these n numbers. Rest of the input file will contain the weight matrix in the same way as
explained for input.txt in question 1.

Output: You should print n distances corresponding to the shortest path length from the source S, in a sequence, separated by a space character.

That is, you should use a loop to print the output as follows:

for(i=1; i<=n; i++)
  printf(“%d ”, distance[i]);

where the array distance[] is storing distances of vertices from the source vertex.

One of these entries will certainly be 0. And some entries may be UNDEFINED, if the vertex is unreachable from the source vertex. To handle such UNDEFINED entries, we assume that the distances will all be positive integers only, and hence you can take UNDEFINED to be an invalid value -1.
