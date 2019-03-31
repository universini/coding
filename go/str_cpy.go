// string copy function

package main

import ( "fmt"
       )

func str_cpy(t string, s string) string {

    for range s {
       t=s 
    }

    return(t)
}

func main() {
    s:="sidde"
    t:=" "

    r:=str_cpy(t,s)
    fmt.Println(r)
}

