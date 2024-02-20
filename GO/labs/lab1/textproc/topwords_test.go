// textproc_test.go
package textproc

import (
	"testing"
)

func TestTopWords(t *testing.T) {
	topK := topWords("passage", 3) // Replace with the correct path to your text file
	want := "butter: 4 better: 2 betty: 2 "
	got := ""
	for _, word := range topK {
		got += word.String() + " "
	}
	if got != want {
		t.Errorf("TopWords test failed, Want-{%s} Got-{%s}", want, got)
	}
}
