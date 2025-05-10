package femlparser

import (
    "fmt"
    "strings"
)

func MapToFEML(src map[string]string) string {
    rc := ""
    for k, v := range src {
        rc += fmt.Sprintf("%s=%s\n", k, v)
        }
    return rc
}

func ParseFEML(src string) map[string]string {
    rc := make(map[string]string)
    ei := 0
    
