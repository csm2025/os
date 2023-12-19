read -p "Enter Number" n

num=$n
rev=0
sum=0
while [ $num -gt 0 ]
do
	rev=$((num%10))
	cube=$((rev*rev*rev))
	sum=$((sum+cube))
	num=$((num/10))
done
if [ $sum -eq $n ]
then
	echo "Arm"
else
	echo "No"
fi
