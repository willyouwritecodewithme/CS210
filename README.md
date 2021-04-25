# CS210 Grocer Records C++ Program


# Summarize the project and what problem it was solving.
This program reads in a text file of chronologically-ordered grocery items purchased, then offers the user the options to output the purchase quantity of all items, output the purchase quantity of a single user-specified item, print a histogram that graphically represents the purchase quantities of all items, or to quit the program. The program uses the GrocerPYFile.py file, and may create the frequency.dat file depending on which functions are called by the user. It is intended to make clear to the grocer the best selling products so that they can place those items in more convenient locations.

# What did you do particularly well?
I think that this program succeeds in terms of clarity of function as well as displaying all information in a nicely-formatted way.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I would like to add a GUI to make the program more user-friendly for grocer employees. I would also like to add a function that suggests the nearest grocery item if the user-input grocery item does not exist in the list. This would allow minor typos to be resolved.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
A significant portion of the time spent on this project was dedicated to determining how I wanted to break the program functions into Python functions. I use a dictionary to store each unique item as a key and the frequency of that item as the value, and this dictionary is then used by all of the program functions. Initially, I had two separate functions, one that parsed the input file and created the dictionary but did not print out the items, and one that parsed the input and created the dictionary but did print the items. Eventually, I decided to condense these two functions into a singular function that creates the dictionary but only prints the dictionary if no argument is passed to the function. I did not really utilize any tools or resources for this particular improvement, but it was a good learning experience that improved my ability to break up a program into efficient functions with minimal repetition.

# What skills from this project will be particularly transferable to other projects or course work?
The utilization of dual languages in this program will certainly be transferrable to many other projects, especially those that make use of Python's libraries but use a separate compiled language for quicker execution. All of the other skills used in this project also continued to hone my abilities, which will allow me to tackle more complicated programs in the future.

# How did you make this program maintainable, readable, and adaptable?
I included significant amounts of comments, including comments explaining the overall program's purpose, each function's purpose, what certain code is for, and many other things. I used the standard style that we have been using during this course, which includes guidelines for making code more readable. I broke up the program's functions into individual functions, which will allow the program to be easily adapted to include more functions or to modify the current functions.
