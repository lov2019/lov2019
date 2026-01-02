function parseUrlParams(url) {
    // 1. 分割 URL，提取查询参数部分（?后的内容）
    const queryStr = url.split('?')[1] || '';
    // 2. 处理空参数场景
    if (!queryStr) return {};

    const params = {};
    // 3. 分割多个参数
    const paramPairs = queryStr.split('&');

    paramPairs.forEach(pair => {
        // 4. 分割键值对（=分隔），并解码特殊字符（如 %20 转空格）
        const [key, value] = pair.split('=').map(item => decodeURIComponent(item));
    
        // 5. 处理数组格式参数（如 c[]）
        if (key.endsWith('[]')) {
            const arrKey = key.slice(0, -2);
            params[arrKey] = params[arrKey] || [];
            params[arrKey].push(value);
        } else {
          // 6. 普通参数直接赋值（重复参数会覆盖前值）
            params[key] = value;
        }
    });
    return params;
}
module.exports.parseUrlParams = parseUrlParams
http = require("http");
class LFWebServer {
    constructor() {
        this.server = http.createServer((req, res) => {
            const url = req.url;
            const method = request.method;
        }
    }
}













    
