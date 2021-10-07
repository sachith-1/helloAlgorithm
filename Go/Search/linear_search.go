package main

import "fmt"

func linearSort(arr []int, s int) int {
    for i, v := range arr {
        if s == v {
            return i
        }
    }

    return -1
}

func main() {
    var n = []int{4, 2, 5, 8, 0, 7, 3, 9}

    fmt.Println(linearSort(n, 23)) // -1 => 23 is not in the array n
    fmt.Println(linearSort(n, 4)) // 0 => index of the 4 is 0
}
