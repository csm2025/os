read -p "Enter Number" n
i=0
echo "First n Digits are:"
while [ $i -lt $n ];
do
	echo $i
	i=$((i+1))
done
