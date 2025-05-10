// 港南二中2322班懂哥编写

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
    for _, ln := range strings.Split(src, "\n") {
        if ln == "" {
            continue
        }
        ei = strings.Index(ln, "=")
        if ei == -1 {
            return nil
        }
        ln += " "
        rc[ln[0 : ei]] = ln [ei + 1 : len(ln) - 1]
    }
    return rc
}
