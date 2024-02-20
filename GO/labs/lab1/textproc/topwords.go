package textproc

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strings"
)

// WordCount represents how many times a word is observed in a document
type WordCount struct {
	Word  string
	Count int
}

// checkError is a helper function to log fatal errors
func checkError(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// sortWordCounts is a helper function to sort a list of word counts in place.
// This sorts by the count in decreasing order, breaking ties using the word.
func sortWordCounts(wordCounts []WordCount) {
	sort.Slice(wordCounts, func(i, j int) bool {
		wc1 := wordCounts[i]
		wc2 := wordCounts[j]
		if wc1.Count == wc2.Count {
			return wc1.Word < wc2.Word
		}
		return wc1.Count > wc2.Count
	})
}

// topWords finds the top K most common words in a text document.
func topWords(path string, K int) []WordCount {
	// Open the file
	file, err := os.Open(path)
	checkError(err)
	defer file.Close()

	// Create a map to count word occurrences
	wordCountMap := make(map[string]int)

	// Use bufio scanner to read the file line by line
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)

		// Count occurrences of each word
		for _, word := range words {
			wordCountMap[word]++
		}
	}

	// Check for errors during scanning
	checkError(scanner.Err())

	// Convert map to a slice for sorting
	var wordCounts []WordCount
	for word, count := range wordCountMap {
		wordCounts = append(wordCounts, WordCount{Word: word, Count: count})
	}

	// Sort the slice by word count
	sortWordCounts(wordCounts)

	// Return the top K occurrences
	if K > len(wordCounts) {
		K = len(wordCounts)
	}
	return wordCounts[:K]
}

// String method to convert WordCount struct to string format
func (wc WordCount) String() string {
	return fmt.Sprintf("%v: %v", wc.Word, wc.Count)
}
