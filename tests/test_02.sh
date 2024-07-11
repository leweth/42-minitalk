#In this test we run the client with a bunch of invalid process ids

echo "Testing with values from -5 to 10"

pid=-5
while [[ $pid -le 10 ]]; do
	../client "$pid" "..."

	pid=$((pid + 1))

	sleep 0.2
done

echo "--------------------------------------------"
echo "Testing with values from 200 to 210"

pid=200
while [[ $pid -le 210 ]]; do
	../client "$pid" "..."

	pid=$((pid + 1))

	sleep 0.2
done

echo "--------------------------------------------"
echo "Testing with values from 10000 to 10010"

pid=10000
while [[ $pid -le 10010 ]]; do
	../client "$pid" "..."

	pid=$((pid + 1))

	sleep 0.2
done