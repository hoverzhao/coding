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

# 使用 Perl 替换每组"4个空格"为一个Tab
perl -pe 's/ {4}/\t/g' "$file" > "${file}.tmp" && mv "${file}.tmp" "$file"

echo "处理完成：$file 已替换 4 个空格为 Tab。"
