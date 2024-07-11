#In this test, "Yo buddy should be printed"

./client $(ps | grep ./server | awk 'NR==1{print $1}') "Yo buddy"