package main

import (
	"fmt"
)

func foo(n uint) uint {
	if n == 0 {
		return 0
	}

	var n1, n2 uint = 0, 1

	for i := uint(1); i < n; i++ {
		n3 := n1 + n2
		n1 = n2
		n2 = n3
	}

	return n2
}

func main() {
	var num uint

	fmt.Scanf("%d", &num)

	fmt.Printf("%d", foo(num))
}