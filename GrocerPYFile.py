'''
    This file provides function for the Project3GrocerRecords C++ program. Function explanations
    are included in comments above each function.

    William Kendall
    04.18.2021
'''

import re
import string

inFile = open('CS210_Project_Three_Input_File.txt') # Opening input file.
outFile = open('frequency.dat', 'w+')               # Opening output file.
py_dict = {}         # Declaring dictionary.
items = []           # Declaring list for items.

# Reads all items from input file, fills dictionary with unique items and
# tracks number of occurrences, and outputs the dictionary's contents if
# no argument is passed.
def AllItemCounter(shouldPrint = 1):
    items = inFile.readlines() # Put each item into a list.
    for item in items:         # Iterates across all items.
        if item[-1] == '\n':   # Removes trailing newline character.
            item = item[0:-1]  
        if item in py_dict:    # Increments item's value in dict if item exists.
            py_dict[item] += 1
        else:                  # Creates item in dict since item does not exist yet.
            py_dict[item] = 1
    if (shouldPrint == 1):     # Outputs items and quantities if no argument is passed.
        for product, quantity in py_dict.items():
            print('{}: {}'.format(product, quantity))

# Returns the number of occurrences of an argument item in the item list.
def SingleItemCounter(userItem):
    AllItemCounter(0)            # Calls AllItemCounter() without print option in case user has not called this function.
    if (userItem in py_dict):    
        return py_dict[userItem] # Returns number of occurrences of an item if it exists in the item dictionary.
    else:
        return 0                 # Returns 0 as number of occurrences if userItem does not exist in the item dictionary.


# Writes each item and quantity from dictionary to the frequency.dat file.
def FrequencyFileCreator():
    iterationCounter = 0           # Tracks the number of times loop has iterated.
    AllItemCounter(0)              # Calls AllItemCounter() without print option in case user has not called this function.
    numItems = len(py_dict.keys()) # Stores the number of unique items in the dictionary.

    # Iterates across all key-value pairs in the dictionary.
    for product, quantity in py_dict.items():
        iterationCounter += 1 # Increments iteration counter.

        # Writes product and quantity with trailing newline as long as it is not the last key-value pair.
        if (iterationCounter < numItems):
            outFile.write('{} {}\n'.format(product, quantity))

        # Writes product and quantity without newline if it is the last key-value pair.
        elif (iterationCounter == numItems) :
            outFile.write('{} {}'.format(product, quantity))

