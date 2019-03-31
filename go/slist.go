// singly linked list

package main

import "fmt"

type slist struct {
    data  int
    next *slist
}

func main () {
    head := &slist{1, nil}

    fmt.Println(head.data)
}
