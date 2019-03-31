// string length function

package main

import ( "fmt"
       )

func str_len(s string) int {
    l:=0

    for range s {
       l++ 
    }

    return(l)
}

func main() {
    s:="sidde"

    l:=str_len(s)
    fmt.Println(l)
}

