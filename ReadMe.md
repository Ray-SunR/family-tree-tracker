#Family Tree Tracker
Contributor: Renchen Sun (Ray)

#Compilation
The program can be compiled by using following command     

make     

For cleaning the generated files:     

make clean    

An executable called "family-tree" will be produced.    
make clean    

##Instroction:
A family tree begins with a topmost acestor and indicates the ancestor's children, and then their children, and so on. In this type of family tree, which is oriented towards the decentants rather than acestors, each non-root leaf is decentant of one parent (the other parent is not considered)      


##Commands:

1. ! name    
Adds name as the topmost ancestor of the tree; if the tree already has a topmost ancestor, this new topmost ancestor is added as the parent of the current topmost. If the tree is empty, this command creates a new tree that contains only name.    
2. + name1 name2     
Adds name2 to the tree as a child of name1. If name1 is not found in the tree, print out Failed (and a newline) to stdout.     
3. ? name     
Answers whether name occurs in the tree. If name is found, output the sequence of names (separated by commas) from the topmost ancestor to name, inclusive (and a newline); otherwise, output Not found (and a newline).    
4. * name      
Oops! It turns out that name was not part of this family after all. Remove name and all of its descendants from the tree. If name is not in the tree, this command has no e↵ect.    
5. p     
Prints the tree. Your print routine should perform a preorder traversal of the tree, following the format of the model presented below. Children should be presented and traversed in the order in which they were added to the tree.    
6. include filename      
Reads the file filename and executes the commands contained therein. The program terminates when it encounters an EOF signal on stdin.    

**NoteTest folder is there for testing purpose. Use the runSuite which is provided. For how to use runSuite, please refer to my repository: Ray-SunR/Runsuite for details**    

##Example:
**Input:**    
! A     
\+ A B     
\+ B C     
\+ C D     
\+ D E     
\+ E F     
\+ F G     
\+ G H    
\+ H I      
\+ I J     
? C     
? I     
? H    
? G    
p      
   
**Output:**
A,B,C     
A,B,C,D,E,F,G,H,I     
A,B,C,D,E,F,G,H     
A,B,C,D,E,F,G     
A is parent of B     
B is parent of C     
C is parent of D    
D is parent of E     
E is parent of F    
F is parent of G     
G is parent of H     
H is parent of I     
I is parent of J       
