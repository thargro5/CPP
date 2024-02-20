// main.go
package main

import (
	"example.com/textproc"
	"fmt"
)

func main() {
	path := "passage" // Replace with the actual path to your text file
	K := 3

	topWordsResult := textproc.topWords(path, K)

	// Print the top K words
	for _, wc := range topWordsResult {
		fmt.Println(wc)
	}
}
