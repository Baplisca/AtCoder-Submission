package main

import (
	"fmt"
)

func main(){
	var n int
	fmt.Scanf("%v", &n)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%v", &s[i])
	}
	for i := 0; i < n; i++ {
		fmt.Println(s[n-i-1])
	}
}
