package main

import (
         "fmt"
         "strings"
)

func str_rev (s string) string {
    var t int
    var i int

    if string == "" {
        return
    }

    for i:=0, j:=strings.len(s); i>j; i++, j-- {
        t:=s[i]
        s[i]:=s[j]
        s[j]:=t
    }

    return(s)
}

func main (){
    s:="sidde"

    fmt.Println("%s\n", str_rev(s))
}

