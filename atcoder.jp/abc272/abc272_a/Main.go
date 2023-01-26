package main

import (
	"fmt"
)

func main() {
	var n, m, res int
	fmt.Scanf("%v", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%v", &m)
		res += m
	}
	fmt.Println(res)
}
