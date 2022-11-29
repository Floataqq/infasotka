package main

import (
    "bufio"
    "fmt"
	"os"
)

func Encrypt(input string, key int) string {
	key8 := byte(key%26+26) % 26

	var outputBuffer []byte

	for _, b := range []byte(input) {
		newByte := b
		if 'A' <= b && b <= 'Z' {
			outputBuffer = append(outputBuffer, 'A'+(newByte-'A'+key8)%26)
		} else if 'a' <= b && b <= 'z' {
			outputBuffer = append(outputBuffer, 'a'+(newByte-'a'+key8)%26)
		} else {
			outputBuffer = append(outputBuffer, newByte)
		}
	}
	return string(outputBuffer)
}

func Decrypt(input string, key int) string {
	return Encrypt(input, 26-key)
}

func main() {
	var key int
	reader := bufio.NewReader(os.Stdin)

	text, _ := reader.ReadString('\n')
	fmt.Scanf("%d", &key)

	enc_text := Encrypt(text, key)
	dec_text := Decrypt(enc_text, key)

    fmt.Printf("Original text: %sEnc text: %sDec text: %s", text, enc_text, dec_text)
}
