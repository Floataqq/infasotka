package main

import (
	"regexp"
	"strings"
	"fmt"
	"bufio"
	"os"
)

func cleanString(text string) string {
	clean_text := strings.ToLower(text)
	clean_text = strings.Join(strings.Fields(clean_text), "")
	regex, _ := regexp.Compile(`[^\p{L}\p{N} ]+`)
	return regex.ReplaceAllString(clean_text, "")
}

func foo(text string) bool {
	clean_text := cleanString(text)
	var i, j int
	rune := []rune(clean_text)
	for i = 0; i < len(rune)/2; i++ {
		j = len(rune) - 1 - i
		if string(rune[i]) != string(rune[j]) {
			return false
		}
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	string, _ := reader.ReadString('\n')
	fmt.Printf("%t", foo(string))
}