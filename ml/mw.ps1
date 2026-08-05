<#
Original shell script convert to Powershell for Windows
Original tool: mlt
#>
#mlt raw "i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0; i = 0;"

#mlt raw "for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko for (int i = 0; i < 100; ++i) {\r}\x1Bko"

mlt raw "for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko for (int j = 0; j < 100; --j) {\r}\x1Bko"


#------ insert态 上一行输入 <esc>ko   \x
# mlt raw ";jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko ;jkko "
#------ insert态 下一行输入 <esc>o
# mlt raw ";jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko ;jko "
#------ insert态 下下行输入 <esc>jo
# mlt raw ";jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo ;jkjo "

#------ insert态 上跳空行
# mlt raw ";jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko ;jk{ko "
#------ insert态 下跳空行
# mlt raw ";jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o ;jk}o "

#------ insert态 下2级括号 插入
# mlt raw ";jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko ;jk2[{ko "
#------ insert态 上2级括号 插入
# mlt raw ";jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o ;jk2]}o "

#------选中block    <esc>va{a{V
# mlt raw ";jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy ;jkva{Vy "
# mlt raw ";jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky ;jkva{Voky "
# mlt raw ";jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy ;jkva{a{Vy "

#------选中2层block  花括号单行模式
# mlt raw ";jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd ;jkva{a{okd "
# mlt raw ";jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky ;jkva{a{oky "

#------选中函数
#------ r4] r3[ <leftshift>v l3% l2y r3d -------选中函数yd
# mlt raw ";jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky ;jk][V%ky "
# mlt raw "p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] p=\`] "


