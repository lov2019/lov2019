/*
港南二中2322班懂哥编写
此文件已经测试并通过，目前为稳定版本，请放心使用
新版本将增加字符串转义
*/

package femlparser

import (
    "fmt"
    "strings"
)

/*
MapToFEML
接受map 将一个map转为FEML字符串
返回string
*/

func MapToFEML(src map[string]string) string {
    rc := ""
    for k, v := range src {
        rc += fmt.Sprintf("%s=%s\n", k, v)
        }
    return rc
}

/*
ParseFEML
将FEML转为map
如果成功返回map,发生语法错误则返回nil
*/

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
