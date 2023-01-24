package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%v", &n)
	s := make([]int, n+1)
	s[0] = 1
	for i := 1; i < n+1; i++ {
		s[i] = i * s[i-1]
	}
	fmt.Println(s[n])
}
