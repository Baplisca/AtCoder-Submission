package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	for i := 0; i < len(s); i++ {
		c := s[i : i+1]
		if c != "a" && c != "i" && c != "u" && c != "e" && c != "o" {
			fmt.Printf("%s", s[i:i+1])
		}
	}
	fmt.Println()
}
