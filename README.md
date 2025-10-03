# Dictionary Spell Checker (C - Binary Search Tree)

This project implements a dictionary-based spell checker using a Binary Search Tree (BST) in C.
It loads words from a dictionary file (EN-US-Dictionary.txt) into a BST and allows users to input sentences for spell-checking. The program checks each word for correctness and suggests possible corrections (predecessor and successor words in the BST).

## 📌 Features

Loads dictionary words into a case-insensitive BST.

Supports:

Search for words in the dictionary.

Spell-checking for sentences.

Suggestions for incorrect words (closest predecessor and successor).

Calculates:

Dictionary size (total words loaded).

Tree height.

Provides feedback whether a word is CORRECT or INCORRECT.

## ⚙️ How It Works

The program reads all words from EN-US-Dictionary.txt and inserts them into a Binary Search Tree.

Each word is stored in lexicographical order (case-insensitive).

When the user inputs a sentence:

Each word is searched in the BST.

If found → marked as CORRECT.

If not found → marked as INCORRECT with two suggestions:

Successor (next closest word in dictionary).

Predecessor (previous closest word in dictionary).

## ▶️ Compilation & Execution
Compile:
gcc main.c -o spellchecker

Run:
./spellchecker

Example Input:
Enter a sentence:
helllo worlld

Example Output:
..................................
Dictionary Loaded Successfully...!
..................................
Size = 100000
..................................
Height = 25
..................................
Enter a sentence:
helllo worlld
helllo - Incorrect, Suggestions: hello  help  
worlld - Incorrect, Suggestions: world  worm  

## 📖 Dictionary File Format

The program expects a file named EN-US-Dictionary.txt in the same directory.
Format:

word1
word2
word3
...


Example:

apple
banana
cat
dog
elephant

## 🚀 Possible Improvements

Replace BST with AVL Tree or Red-Black Tree for balanced search.

Add Levenshtein Distance for better word suggestions.

Allow loading different language dictionaries.

Improve memory management (freeing nodes on exit).

## 🛠️ Requirements

GCC or any C compiler.

A dictionary text file (EN-US-Dictionary.txt).

