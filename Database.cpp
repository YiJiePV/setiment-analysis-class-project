// Title: Lab 2 - Database.cpp
//
// Purpose: Implements the functions InitDatabase, AddWordToDatabase,
// FindWordInDatabase, and GetInfoAboutDatabase, each function manipulating
// and/or analyzing a database of Record objects as specified.
//
// Class: CSC 2430 Winter 2022
// Author: Karena Qian

#include "Database.h"
#include <iostream>

using std::cerr;
using std::endl;

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;

// InitDatabase only initializes the size of the database to zero. It must be called once before
// adding to the database.
// Parameters:
//      capacity -- maximum size of the database array
//      records -- an array of Record objects representing the database array
//      size -- current number of filled slots in the database array
// Returns:
//      nothing
// Possible Errors:
//      none
void InitDatabase(int capacity, Record records[], int& size){
    size = 0;
}

// AddWordToDatabase adds a new Record object to the database array, with its data members word,
// count, and total score set to the given word, 1, and the given score respectively, if a Record
// object with the given word does not already exist or if the database array is not at full capacity
// yet. If the given word is found in the database, then its corresponding Record object's count data
// member increases by 1 and the given score will be added to the object's total score data member.
// Finally, if the maximum size of the database is reached, the method will generate an error
// and return false. Otherwise, it will return true to indicate success.
// Parameters:
//      capacity -- maximum size of the database array
//      records -- an array of Record objects representing the database array
//      size -- current number of filled slots in the database array
//      word -- given word to be added to the database
//      score -- given score corresponding to the word
// Returns:
//      true if given word is added successfully
//      otherwise false
// Possible Errors:
//      The function will print an error message and return false if size has reached capacity
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score){
    if(size == capacity){
        cerr << "Maximum capacity reached, unable to add data" << endl;
        return false;
    }
    else{
        for(int i = 0; i < size; i++){
            if(records[i].GetWord() == word){
                records[i].SetCount(1 + records[i].GetCount());
                records[i].SetScoreTotal(score + records[i].GetScoreTotal());
                return true;
            }
        }
        records[size].SetWord(word);
        records[size].SetCount(1);
        records[size].SetScoreTotal(score);
        size++;
        return true;
    }
}

// FindWordInDatabase determines if the given word is in the database array. If it is, it sets
// occurrences and averageScore to the word's count and total score data members respectively,
// both stored in its corresponding Record object. Otherwise, it sets occurrences and averageScore
// to 0 and NEUTRAL respectively.
// Parameters:
//      records -- an array of Record objects representing the database array
//      size -- current number of filled slots in the database array
//      word -- given word to be added to the database
//      occurrences -- total number of occurrences of the word
//      averageScore -- total score of the word
// Returns:
//      nothing
// Possible Errors:
//      none
void FindWordInDatabase(const Record records[], int size,
                        const string& word, int& occurrences, double& averageScore){
    for(int i = 0; i < size; i++){
        averageScore = 0;
        if(records[i].GetWord() == word){
            occurrences = records[i].GetCount();
            averageScore = records[i].GetScoreTotal();
            return;
        }
        else{
            occurrences = 0;
            averageScore = NEUTRAL;
        }
    }
}

// GetInfoAboutDatabase finds and stores the total number of words in the database,
// the minimum and maximum value of the total occurrences of a word, and the minimum
// and maximum value of the average score of a word.
// Parameters:
//      records -- an array of Record objects representing the database array
//      size -- current number of filled slots in the database array
//      numberWords -- total number of words in the database array
//      maxOccurrences -- maximum value of data member count in the database
//      minOccurrences -- minimum value of data member count in the database
//      maxScore -- maximum value of a word's average score in the database
//      minScore -- minimum value of a word's average score in the database
// Returns:
//      nothing
// Possible Errors:
//      none
void GetInfoAboutDatabase(const Record records[], int size,
                          int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore){
    numberWords = size;
    minOccurrences = numberWords;
    minScore = numberWords;
    for(int i = 0; i < numberWords; i++){
        if(records[i].GetCount() > maxOccurrences){
            maxOccurrences = records[i].GetCount();
        }
        else if(records[i].GetCount() < minOccurrences){
            minOccurrences = records[i].GetCount();
        }
        if(records[i].GetScoreTotal() > maxScore){
            maxScore = (static_cast<double>(records[i].GetScoreTotal()) / records[i].GetCount());
        }
        else if(records[i].GetScoreTotal() < minScore){
            minScore = (static_cast<double>(records[i].GetScoreTotal()) / records[i].GetCount());
        }
    }
}

