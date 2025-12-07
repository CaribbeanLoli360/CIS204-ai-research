# CIS204-ai-research

# Program Purpose  
-What will a user use your program to do? users will be able to keep track of how many books have been added, removed, the list of books and its information.
- What problem does your program solve for users?  this will help the user keep tabs on the books they own and without having to firgure out the books they have loaned to friends and family, the books that are to be read that did not finifh reading etc.
- What does your program do? Again, use your creativity here. the program will give the user information based on as book, just by looking up the genre,ISBN, title or the authors name.

# Input, Output, and Memory Management 
- What input will a user need to provide? String, interger and whatever the users menu choices are. 
- What output is the program expected to generate? the program will output will firstl list all the books available, if it has been added or removed recently, menu option, or if the book isnt found.
- What variables will your program need to define? 
struct Book inventory[100];
int count = 0;
int choice;
char title[50];


- How much memory will your program require to operate? the program will require memory  that can store up to 100-150 books

# Functions Needed 
- List 3–6 functions your program will require. 
void addBook(struct Book inteventory[i], int *count);
void  displayBooks(struct Book inventory[i], int count);
void removeBook(struct Book inventory[], int *count, char title[]);
void updateBook(struct Book inventory[], int count, char title[]);
int searchBook(struct Book inventory[i], int count, char title[i]);
- Example: int addNumbers(int a, int b); 

# Data Structures 
 Define a simple struct to use in your program. 
- This struct should represent the “object” of your program 
- Example: a Student struct might have members such as name, age, grade. 
struct Book {
    char title[i];
    char author[i];
    char genre[i];
    int year [i];
};
# File Responsibilities 
 The following files are required in your project submission. 
Describe the purpose and contents of each file. 
- main.c 
- helpers.h 
- Helpers.c 

# Research Plan 
 Write a 250 words describing your strategy for using AI to help you 
to write the code for this project. 
I decide to use AI for this project to try to gain a better understanding of it. Though AI has assisted me with work, giving me help, it tends to give me the more advanced version of the assignment, which can be difficult. Organizing this program was a little challenging because I'm still getting used to putting in the code for separating files, even though it's easier to find each code and compile the program. Ai helped me with mainly functions and compiling. It’s been interesting learning the different ways AI can create programs in both C and C++. I was able to ask AI to explain each part of the code, which helped me understand how the program works and how to implement it in my own project.AI was very crucial in dealing with mistakes, primarily because I didn't understand what it meant when my program not only didn't comply, but also when the errors were really incomprehensible to me, which made me very frustrated. But then I'd run it through AI, and they'd show me every mistake and explain in detail how and why I got it in the first place.Using AI in this project helped me understand how to organize C programs with multiple files and functions. It also helped me troubleshoot errors that I wouldn’t have been able to fix on my own. Overall, AI made my coding process more efficient and gave me confidence in completing the project successfully.
- Include  3–5 prompts you will give the AI to generate code.
Help me organize my program files into main.c, helpers.c, and helpers.h.
Explain the errors when my program wouldn’t compile and why they occurred.
Suggest what variables I can use for storing book information and how to input them.