cp ../uls .

err=('-l' '-l' '-al' '-la' '-Al' '-Aa' '-aA'
	'-f' '-fA' '-l1' '-1l' '-uT' '-Tu' '-AR' '-Ra' '-rAR' '-raR' '-aATu' '-dr')

for i in "${err[@]}"; do
	zsh compare.sh <(ls $i 2>&1) <(./uls $i 2>&1) $i
	zsh compare.sh <(ls $i . 2>&1) <(./uls $i . 2>&1) "$i ."
	zsh compare.sh <(ls $i .. 2>&1) <(./uls $i .. 2>&1) "$i .."
done
