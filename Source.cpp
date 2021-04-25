/*
 *  This program reads in a text file of chronologically-ordered grocery items purchased, then offers the user the options
 *  to output the purchase quantity of all items, output the purchase quantity of a single user-specified item, print a 
 *  histogram that graphically represents the purchase quantities of all items, or to quit the program.
 * 
 *  The program uses the GrocerPYFile.py file, and may create the frequency.dat file depending on which functions are called.
 * 
 *  William Kendall
 *  04.18.2021
 */

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("GrocerPYFile");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"GrocerPYFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"GrocerPYFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// This function prints out the menu options.
void PrintMenu() {
	cout << setfill('=') << setw(57) << "" << endl;
	cout << "1: Print all items purchased and purchase quantities." << endl;
	cout << "2: Print the purchase quantity of a specific item." << endl;
	cout << "3: Print a histogram of purchase quantities of each item." << endl;
	cout << "4: Quit the program." << endl;
	cout << setfill('=') << setw(57) << "" << endl;
	cout << "Please select an action by entering a number." << endl;
	cout << "Multi-character inputs will only use the first character." << endl;
}

int main() {
	string userString;     // Stores total user input for the menu.
	char userChar = 'a';   // Stores the first character of the user's menu input string.
	string continueString; // Stores user input to move on after a function has been called.
	string userItem;       // Stores the user's input item for the single item counter function.
	ifstream inFS;         // Input filestream for the frequency.dat file.
	string tempString;     // Stores the item name from the frequency.dat file.
	int tempInt;           // Stores the item quantity from the frequency.dat file.

	// Iterates unless user has entered the character '4'.
	while (userChar != '4') {
		PrintMenu(); // Calls the function to print the menu.

		 // Reads user input, then takes only the first character of that input to ensure valid input.
		cin >> userString; 
		userChar = userString.at(0);

		system("CLS"); // Clears screen for formatting.

		if (userChar == '1') { // Calls AllItemCounter Python function if input is '1'.
			CallProcedure("AllItemCounter");
		}
		else if (userChar == '2') {
			// Asks user to input the item they want the quantity of.
			cout << "Please enter the item you want to know the quantity of." << endl;
			cin >> userItem; // Stores user input.

			// Capitalizes first letter of user input to match text file format.
			userItem.at(0) = toupper(userItem.at(0)); 

			// Calls SingleItemCounter Python function with user-item argument and outputs the result.
			cout << endl << userItem << ": " << callIntFunc("SingleItemCounter", userItem) << endl;
		}
		else if (userChar == '3') {
			CallProcedure("FrequencyFileCreator"); // Calls FrequencyFileCreator Python function.
			inFS.open("frequency.dat"); // Opens the file created by FrequencyFileCreator function.

			// Handles file opening errors.
			if (!(inFS.is_open())) {
				cout << "Could not open file \"frequency.dat\"." << endl;
				return 1;
			}
			while (!inFS.eof()) { // Iterates until end-of-file.
				inFS >> tempString; // Stores current line's item name.
				inFS >> tempInt;    // Stores current line's item quantity.
				cout << setfill(' ') << setw(11) << tempString << ": "; // Outputs formatted item name.
				
				// Outputs histogram using item quantity.
				for (int i = 0; i < tempInt; i++) {
					cout << "X";
				}
				cout << endl; // Formatting.
			}
			inFS.close(); // Closing frequency.dat file.
		}
		else if (userChar == '4') { // Quits program by breaking out of loop.
			cout << "Quitting program." << endl;
			Sleep(1500);
			break;
		}
		else { // Handles any invalid input.
			cout << "Invalid input." << endl;
		}
		// Allows function output to stay on screen until user enters a character.
		cout << endl << "Enter any character to continue." << endl;
		cin >> continueString;

		system("CLS"); // Clears screen for formatting before next iteration.
	}
}