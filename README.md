# Spell-Checker-binary-search-tree
Binary search tree spelchecker

For this assignment, you are tasked to build a console-based spell checker that will
be used to show the spelling mistakes in a standard text document.

The application will start by reading all the words in a dictionary file that has been
provided for you. The file is not a complete dictionary. It simply contains all the
correct spelling for specific words in alphabetic order. The dictionary words will be
the basis for a custom binary search tree in your application.

You will then use a programmatic means to balance the binary search tree. It will be
up to you to choose and implement how the tree will be balanced. Feel free to
choose any method that works!

Once the binary search tree has been filled and balanced, you will read in a second
file that is a sample document needing spell checking. All the words in the document
needing checking are located in the dictionary (and now in the binary search tree).

You will then compare each word in the document against the binary search tree. If
the search fails, you will display the misspelled word to the console.

Along with displaying a list of all the misspelled words to the console, the program
should also write the balanced tree output to a file for later examination.

Note: You cannot modify either the provided dictionary file or document file.
However, you may find it easier to test your application with a smaller dictionary
and/or document before testing against the given files.
