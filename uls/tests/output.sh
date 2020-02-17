cp ../uls .

err=('-l' '-l' '-al' '-la' '-Al' '-Aa' '-aA' '-R' '-1' '-Sr' '-rR' '-arR' ''
	'-f' '-fA' '-l1' '-1l' '-S' '-AR' '-Ra' '-rAR' '-raR' '-aAS' '-dr')

for i in "${err[@]}"; do
	zsh compare.sh <(ls $i 2>&1) <(./uls $i 2>&1) $i
	zsh compare.sh <(ls $i . 2>&1) <(./uls $i . 2>&1) "$i ."
	zsh compare.sh <(ls $i .. 2>&1) <(./uls $i .. 2>&1) "$i .."
	zsh compare.sh <(ls $i .. 2>&1) <(./uls $i .. 2>&1) "$i /dev"
	zsh compare.sh <(ls $i .. 2>&1) <(./uls $i .. 2>&1) "$i /Users"
done
