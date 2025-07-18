#!/bin/bash

# 检查参数数量
if [ $# -ne 1 ]; then
  echo "用法: $0 文件路径"
  exit 1
fi

file="$1"

# 检查文件是否存在
if [ ! -f "$file" ]; then
  echo "错误: 文件不存在: $file"
  exit 1
fi

# 使用 sed 清除只包含空格或 Tab 的“空行”
# 将其替换为真正的空行（不含任何字符）
sed -E 's/^[[:space:]]+$//' "$file" > "${file}.tmp" && mv "${file}.tmp" "$file"

echo "处理完成，已清除空行中的 tab/空格：$file"
