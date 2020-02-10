diff $1 $2 &> /dev/null

if [[ $? == 2 ]]; then
	echo "\033[1;31merror: something\033[0m"
elif [[ $? == 1]]; then
	echo "\033[1;31mnot same: something\033[0m"
else
	echo "\033[1;32msame: something\033[0m"
fi
