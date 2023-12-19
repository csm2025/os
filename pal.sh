read -p "Enter Number" n
num=$n
rev=0
while [ $num -gt 0 ]
do
	rev=$((rev*10 + num%10))
	num=$((num/10))
done
if [ $rev -eq $n ]
then 
	echo "Palindrome!!"
else
	echo "Not a Palindrome"
fi
