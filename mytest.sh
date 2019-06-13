quiet=0
check=0
sred=0

if [ "$#" -lt 3 ] || [ "$#" -gt 4 ]
then
	printf "\nusage: test.sh [-full] arg1 arg2 arg3\n"
	printf "       arg1  - start number (random value from .. ).\n"
	printf "       arg2  - finish number ( .. random value to).\n"
	printf "       arg3  - how many times run a test.\n"

    exit


fi

count=$1
from=$2
to=$3
echo "----------------------------------------"
for ((i = 0; i < $count; i++))
do
    ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; res=$(./push_swap $ARG | wc -l) ; lala=$(./push_swap $ARG) ; answer=$(./push_swap $ARG | ./checker $ARG)
    echo $ARG
    echo $res
    echo $answer
    echo "----------------------------------------"
done