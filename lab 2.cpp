/* Program Description: This program will offer the user a menu choice to perform C-string operations.
 The user will choose the desired string operation, input the requested arguments and view the result
 of the desired operations.
 
 Pseudocode:
 Display menu choices to user.
 In a do-while loop, prompt user for a menu choice.
 If choice is not valid:
 Displays to user that choice was not valid.
 Prompt if user wants to return to menu or exit.
 If choice is valid:
 Prompt user to imput arguments to perform operations.
 Display results of operation to user.
 Prompt if user wants to return to menu for new operation or exit.
 If user requests new operation, return him back to menu.
 Else, exists the program.
 */

#include <iostream>
using namespace std;

//Function prototypes:
void inputSingleString(char *string1, const int size);
void inputDoubleString(char *string1, char *string2, const int size);
int stringLength(char *charArrayFromMain);
char *stringNCopy(char *stringArrayFromMain);
char* stringAdd(char *dest, const char *src);
int stringCompare (const char *firstWord, const char *secondWord);



//int stringLength(char *);
//char *stringNCopy(char *);
//void stringAdd();
//void stringCompare();


int main()
{
	
    // C-string arrays for user input
    const int LENGTH = 20;
    char str1[40],         //double length, so str1 can hold str1 + str2
         str2[LENGTH];
	
	int choice = 0;     //to hold the menu choice from 1-4

    // To display the menu and get a choice from user
    cout << "Enter the number that corresponds to the string manipulation to be performed:\n\n"
    << "    1. String lenght.\n"
    << "    2. String copy\n"
    << "    3. String concatenation\n"
    << "    4. String comparison.\n\n";
    
    //To give user the possibility to repeat the menu
    char again = 'y';
    do
    {
    cout << "Enter your choice and press [ENTER]: " << endl;
    cin >> choice;
    cin.clear();
    cin.ignore();
    switch (choice)
    
    {
        case 1:
        {
            inputSingleString(str1, LENGTH);                    // single word input
            int len = stringLength(str1);                       // return word lenght to len variable
            cout << "Word has " << len << " characters \n";
            break;
        }
            
        case 2:
        {
            /*FF: This function takes 3 parameters (2 string pointers + 1 int) for the amount of
            characters to be copied from source to destination. I used single input string
            because your function only took a single input and I wanted to test the menu. */
            inputSingleString(str1, LENGTH);
            stringNCopy(str1);
            break;
        }
            
        case 3:
        {
            inputDoubleString(str1, str2, LENGTH);   // double word input
            stringAdd(str1, str2);                   // returns concatenated words
            cout << "Here are your concatenated words: " << str1 << endl;
            break;
        }
            
        case 4:
        {
            inputDoubleString(str1, str2, LENGTH);  // double word input
            int comp = stringCompare (str1, str2);  // returns value of compared words
            
            if (comp == 0)
                cout << "You inputed identical words.";
            
            else if (comp > 0)
                cout << "The words are different: '" <<str2 << "' comes before '" << str1 << "' alphabetically\n";
            
            else
            cout << "The words are different: '" <<str1 << "' comes before '" << str2 << "' alphabetically\n";
            break;
        }
            
        default: cout <<  choice << " is not a choice in this menu.\n" << "You must enter 1, 2, 3 or 4! \n";
            
    
    }
        
    cout << "\nManipulate another string? [Y/N]";
    cin >> again;
    cin.clear();
        
    } while (again == 'y' || again == 'Y');
    
    return 0;
	
}
	
	//cout << "Enter A, B, or C: ";
	//cin >> choice;
	/*switch (choice)
	{
		case 'a': cout << "You entered A.\n";
		{
			break;
		}
		case 'A': cout << "You entered A.\n";
		{
			break;
		}
		case 'b': cout << "You entered B.\n";
		{
			break;
		}
		case 'c': cout << "You entered C.\n";
		{
			break;
		}
		default: cout << "You did not enter A, B, or C!\n";
	}*/
	
	/*
	cout << "sending character array to stringLength function... \n";
	char test[99] = "12345678";
	int stringLengthReturnValue = stringLength(test);
	cout << "this is what stringLength returns: " << stringLengthReturnValue << endl;
	cout << "sending array to stringNCopy function... \n";
	char *charPointer = nullptr;
	charPointer = stringNCopy(test);
	cout << "this is what the stringNCopy returns: ";
	for (int count = 0; count < (stringLengthReturnValue + 2); count++)  // the +2 is for the the 'X' I added and the \0 
	{
		cout << *(charPointer + count);
	}

	delete []charPointer;  // free up the memory again
	charPointer = nullptr;
	cin.get();
	return 0;
}*/
	

/* Single String Input Function:
 Accepts one input string and size limit for that string, including the null terminator.
 cin appends a maximum of size-1 characters to string1 + automatic null terminator. */
void inputSingleString(char *string1, const int size)
{
    cout << "Enter the word: " << endl;
    cin.getline(string1, size);
    cin.clear();
}


/* Double String Input Function:
 Accepts two input strings from user and size limit for that string, including the null terminator.
 cin appends a maximum of size-1 characters to each string variable + automatic null terminator. */
void inputDoubleString(char *string1, char *string2, const int size)
{
    cout << "Enter the first word: " << endl;
    cin.getline(string1, size);
    cin.clear();
    cout << "Enter the second word: " << endl;
    cin.getline(string2, size);
    cin.clear();
}


int stringLength(char *charArrayFromMain)
{
	// get an array adress pointer, then use a loop to count the characters in the array until a null terminator is found
	// return the length of the array not counting the \0
	int count = 0;
	while (*charArrayFromMain != '\0')
	{
		//if (*strPtr == ch) // If the current character equals ch...
		//	count++; // ... increment the counter
		charArrayFromMain++;
		count++; // Go to the next char in the string.
	}
	//cout << "string has " << count << " length \n";
	return count;
}

char *stringNCopy(char *stringArrayFromMain)
{
	// get the array from main, then call stringLength function to the get size.
	// create a pointer, then make it point to a char array the size of stringLength + 2
	// the plus two becuase I add and 'X' and then the null char \0
	// return the pointer's memory location

	cout << "this is stringNCopy function... \n";  
	int count = 0;  // loop counter

	
	const int ARRAYSIZE = stringLength(stringArrayFromMain) + 2;  // the plus is the the extra X and the \0
	//arrayPointer = new char[stringLength(stringArrayFromMain) + 1];
	char *arrayPointer = nullptr;  // create memory pointer for the start of the array
	arrayPointer = new char[ARRAYSIZE];  // create a character array


	for (count = 0; *(stringArrayFromMain + count) != '\0'; count++)
	{
		*(arrayPointer + count) = *(stringArrayFromMain + count);
		cout << *(arrayPointer + count);
	}
	*(arrayPointer + count) = 'X'; // prove the function worked 
	//arrayPointer++;  // move the pointer one memory slot over
	count++; // add one to the counter
	*(arrayPointer + count) = '\0'; // Place a null character in 
	//count++;
	cout << endl;

	//cout << *arrayPointer << endl;
	//for (int x = 0; x < count; x++)
	//{
	//	cout << *arrayPointer;
	//	arrayPointer++;
	//}
	//cout << endl;
	//arrayPointer--;
	return arrayPointer;
	//delete []arrayPointer;  // free up the memory again
}

	
/*stringAdd String Concatenation Function:
 Duplicates C-string concatenation strcat function.
 Acceppts two pointers to C-strings as arguments and copies the contents
 of secondWord to firstWord.*/
char* stringAdd(char *firstWord, const char *secondWord)
{
    while (*firstWord!= '\0')
        firstWord++;			//moves the destination word pointer to the position before its null terminator
    
    while (*secondWord != '\0')
        *firstWord++ = *secondWord++;	// appends the source characters to location pointed in destination word, untill
                                        // a null terminator is found in the source word.
    return firstWord;			// returns pointer to destination word

}

	
/* stringCompare String Comparison Function:
 Mimics C-string camparison strcmp function.
 Accepts two pointers to C-strings as arguments and returns an
 int value that shows how the strings compare to each other. */
int stringCompare (const char *firstWord, const char *secondWord)
{
    while( (*firstWord!='\0') && (*firstWord==*secondWord) )	// loops through firstWord until null terminator and compares
    {                                                           // each character of firstWord to secondWor
        firstWord++;
        secondWord++;
    }
    
    if ((*firstWord - *secondWord) > 0)		// firstWord is larger
        return 1;
    
    else if ((*firstWord - *secondWord) == 0)	// both words are identical
        return 0;
    
    else					// secondWord is larger
        return -1;
    
}
