read -p "Enter The Number" n
if [ $((n%2)) -eq 0 ];
then
echo "Its even"
else
echo "Odd"
fi
